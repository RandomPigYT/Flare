#ifndef REFLECTION_CONTEXT_H
#define REFLECTION_CONTEXT_H

#include "typeinfo.hpp"
#include <clang/AST/ASTConsumer.h>
#include <string>

namespace Reflection {

struct context {
  using typeInfoVec = std::vector<struct Reflection::typeInfo>;
  using enumInfoVec = std::vector<struct Reflection::enumInfo>;

  typeInfoVec typeinfo;
  enumInfoVec enumInfo;
  std::vector<const char *> args;
  char *filename;

  clang::ASTContext *context;
  std::string outFile;
  std::string reflectionHeader;
};

}

#endif
