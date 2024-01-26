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
class MyASTVisitor : public RecursiveASTVisitor<MyASTVisitor> {
public:
  // Override method for visiting all AST nodes
  bool TraverseDecl(Decl *D) {
		
		//D->dump(llvm::outs());
		RecordDecl *rd = clang::dyn_cast<RecordDecl>(D);
		
		if (rd){

			printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());
		}


		if (TypedefDecl *TD = dyn_cast<TypedefDecl>(D)){
			
			printf("typedef: %s\t", TD->getNameAsString().c_str());

			QualType q = TD->getUnderlyingType();
			rd = q->getAsRecordDecl();

			if (rd)
				printf("%ld\n", rd->getID());

			else 
				printf("\n");


		}


		
    return RecursiveASTVisitor::TraverseDecl(D);
  }

};

// Define an ASTConsumer for processing the AST
class MyASTConsumer : public ASTConsumer {
public:
  // Override method for setting up the AST visitor
  void HandleTranslationUnit(ASTContext &Context) override {
    MyASTVisitor Visitor;
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());

  }
};

// Define a FrontendAction for the plugin
class MyPluginAction : public PluginASTAction {
protected:
  // Override method for creating the AST consumer
  std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI,
                                                 StringRef file) override {
    return std::make_unique<MyASTConsumer>();
  }

  // Override method for determining whether to process the AST for a given file
  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string> &args) override {
    return true;
  }
};

// Register the plugin with the Clang frontend
static FrontendPluginRegistry::Add<MyPluginAction>
X("dump-ast", "Dump the entire AST of the source code");
