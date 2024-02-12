#include "ast.hpp"

#include <clang/AST/Decl.h>

#include "handleDecl.hpp"

std::unique_ptr<clang::tooling::FrontendActionFactory>
Reflection::customFrontendActionFactory(struct context &ctx) {
	class SimpleFrontendActionFactory
		: public clang::tooling::FrontendActionFactory {
public:
		SimpleFrontendActionFactory(struct context &ctx)
			: m_ctx(ctx) {
		}

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
		Reflection::handleRecordDecl(rd, m_ctx);
	}

	if (clang::EnumDecl *ed = clang::dyn_cast<clang::EnumDecl>(D)) {
		Reflection::handleEnumDecl(ed, m_ctx);
	}

	if (clang::EnumConstantDecl *ecd =
				clang::dyn_cast<clang::EnumConstantDecl>(D)) {
		Reflection::handleEnumConstantDecl(ecd, m_ctx);
	}

	if (clang::TypedefDecl *td = clang::dyn_cast<clang::TypedefDecl>(D)) {
		Reflection::handleTypedefDecl(td, m_ctx);
	}

	if (clang::FieldDecl *fd = clang::dyn_cast<clang::FieldDecl>(D)) {
		Reflection::handleFieldDecl(fd, m_ctx);
	}

	if (clang::IndirectFieldDecl *ifd =
				clang::dyn_cast<clang::IndirectFieldDecl>(D)) {
		clang::RecordDecl *p =
			clang::dyn_cast<clang::RecordDecl>(D->getDeclContext());

		if (!p->isAnonymousStructOrUnion()) {
			handleFieldDecl(ifd->getAnonField(), m_ctx, p,
											m_ctx.context->getFieldOffset(ifd));
		}
	}

	return RecursiveASTVisitor<ASTDeclVisitor>::TraverseDecl(D);
}
