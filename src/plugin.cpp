#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/Frontend/CompilerInstance.h"
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/LangOptions.h>
#include <llvm/ADT/StringRef.h>
#include "llvm/Support/raw_ostream.h"
#include <llvm/IR/Value.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace clang;

// Define a visitor for traversing the AST
class ASTDeclVisitor : public RecursiveASTVisitor<ASTDeclVisitor> {

	char *filename;

public:

	ASTDeclVisitor(char *file){


		filename = (char *)malloc(strlen(file));
		strcpy(filename, file);
	}

  // Override method for visiting all AST nodes
  bool TraverseDecl(Decl *D) {

		if (TranslationUnitDecl *tr = dyn_cast<TranslationUnitDecl>(D)){
			printf("file: %s\n", filename);
		}
		
		//D->dump(llvm::outs());
		RecordDecl *rd = clang::dyn_cast<RecordDecl>(D);
		
		if (rd){

			printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());
		}


		if (TypedefDecl *TD = dyn_cast<TypedefDecl>(D)){
			

			QualType q = TD->getUnderlyingType();
			rd = q->getAsRecordDecl();

			if (rd)
				printf("typedef: %s\t", TD->getNameAsString().c_str());

			if (rd)
				printf("%ld\n", rd->getID());


		}


		
    return RecursiveASTVisitor::TraverseDecl(D);
  }

};

// Define an ASTConsumer for processing the AST
class MyASTConsumer : public ASTConsumer {
	

	char *filename;
	ASTDeclVisitor Visitor;

public:

	MyASTConsumer(char *file) : filename(file), Visitor(filename){
	}

  // Override method for setting up the AST visitor
  void HandleTranslationUnit(ASTContext &Context) override {
    if (Visitor.TraverseDecl(Context.getTranslationUnitDecl())){

			printf("Done!\n");
		}

  }
};

// Define a FrontendAction for the plugin
class Reflection : public PluginASTAction {
protected:
  // Override method for creating the AST consumer
  std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI,
                                                 StringRef file) override {

    return std::make_unique<MyASTConsumer>((char*)file.str().c_str());
  }

  // Override method for determining whether to process the AST for a given file
  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string> &args) override {
    return true;
  }
};

// Register the plugin with the Clang frontend
static FrontendPluginRegistry::Add<Reflection>
X("reflection", "Reflect about the source code");
