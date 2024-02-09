#include "ast.hpp"

#include <clang/AST/Decl.h>

#include "handleDecl.hpp"

std::unique_ptr<clang::tooling::FrontendActionFactory>
Reflection::customFrontendActionFactory(struct context &ctx) {
  class SimpleFrontendActionFactory
      : public clang::tooling::FrontendActionFactory {
   public:
    SimpleFrontendActionFactory(struct context &ctx) : m_ctx(ctx) {}

    std::unique_ptr<clang::FrontendAction> create() override {
      return std::make_unique<Reflection::ReflectionASTAction>(m_ctx);
    }

   private:
    struct context &m_ctx;
  };

  return std::unique_ptr<clang::tooling::FrontendActionFactory>(
      new SimpleFrontendActionFactory(ctx));
}

bool Reflection::ASTDeclVisitor::TraverseDecl(clang::Decl *D) {
  if (clang::RecordDecl *rd = clang::dyn_cast<clang::RecordDecl>(D)) {
    // printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());

    Reflection::handleRecordDecl(rd, m_ctx);
  }

  if (clang::TypedefDecl *td = clang::dyn_cast<clang::TypedefDecl>(D)) {
    Reflection::handleTypedefDecl(td, m_ctx);

    clang::QualType q = td->getUnderlyingType();
    clang::RecordDecl *rd = q->getAsRecordDecl();

    if (rd) printf("typedef: %s\t", td->getNameAsString().c_str());
    if (rd) printf("%ld\n", rd->getID());
  }

  if (clang::FieldDecl *fd = clang::dyn_cast<clang::FieldDecl>(D)) {
    Reflection::handleFieldDecl(fd, m_ctx);
  }

  if (clang::IndirectFieldDecl *ifd =
          clang::dyn_cast<clang::IndirectFieldDecl>(D)) {
			clang::RecordDecl *p = clang::dyn_cast<clang::RecordDecl>(D->getDeclContext());
			if (!p->isAnonymousStructOrUnion()){
				printf("Indirect field name: %s\t", ifd->getNameAsString().c_str());
				printf("offset: %ld\n", m_ctx.context->getFieldOffset(ifd));

				printf("Anon parent name: %s\n", p->getNameAsString().c_str());
		}

  }

  return RecursiveASTVisitor<ASTDeclVisitor>::TraverseDecl(D);
}
