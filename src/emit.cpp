#include "emit.hpp"
#include "typeinfo.hpp"

#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <filesystem>

#define ASSIGN_VAL(fileContents, dst, src) \
  fileContents += dst + " = " + src + ";\n\t";

#define ALLOC_MEM(fileContents, dst, n, pointeeType)                         \
  {                                                                          \
    ASSIGN_VAL(fileContents, dst,                                            \
               "malloc(" + std::to_string(n) + " * sizeof(" + #pointeeType + \
                 "))");                                                      \
  }

#define ASSIGN_STR(fileContents, dst, src)                       \
  {                                                              \
    ALLOC_MEM(fileContents, dst, src.length() + 1, char);        \
    fileContents += "strcpy(" + dst + ", \"" + src + "\");\n\t"; \
  }

#define GET_FIELD(container, field) container + "." + #field

static std::string getRelativePath(std::string from, std::string to) {
  char currentDir[PATH_MAX];

  if (!getcwd(currentDir, PATH_MAX)) {
    perror("Failed to get current directoy");
    exit(EXIT_FAILURE);
  }

  std::string fromDir = std::filesystem::path(from).parent_path().string();

  std::string absTo = std::filesystem::absolute(to).string();

  std::filesystem::current_path(fromDir);
  std::string relativePath = std::filesystem::relative(absTo).string();
  std::filesystem::current_path(currentDir);

  return relativePath;
}

static void writeAliases(std::string &fileContents,
                         const std::string &aliasArray,
                         const std::vector<std::string> &aliases) {
  for (uint64_t i = 0; i < aliases.size(); i++) {
    std::string currentAlias = aliasArray + "[" + std::to_string(i) + "]";
    ASSIGN_STR(fileContents, currentAlias, aliases[i]);
  }
}

static void writeTypeSpecifier(std::string &fileContents,
                               const std::string &typeSpecifierName,
                               const struct Reflection::typeSpecifier &spec) {
  ASSIGN_VAL(fileContents, typeSpecifierName + ".type",
             std::to_string(spec.type));
}

static void writeInfo(std::string &fileContents,
                      const std::string &programInfoStruct,
                      const struct Reflection::context &ctx) {
  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    std::string currentType =
      programInfoStruct + ".types[" + std::to_string(i) + "]";

    ASSIGN_VAL(fileContents, currentType + ".ID",
               std::to_string(ctx.typeinfo[i].ID));

    ASSIGN_STR(fileContents, currentType + ".filename",
               ctx.typeinfo[i].fileName);

    ASSIGN_STR(fileContents, currentType + ".name", ctx.typeinfo[i].name);

    ALLOC_MEM(fileContents, currentType + ".aliases",
              ctx.typeinfo[i].aliases.size(), char *);

    std::string aliasArray = currentType + ".aliases";
    writeAliases(fileContents, aliasArray, ctx.typeinfo[i].aliases);

    ASSIGN_VAL(fileContents, currentType + ".recordType",
               std::to_string(ctx.typeinfo[i].recordType));

    ALLOC_MEM(fileContents, currentType + ".fields",
              ctx.typeinfo[i].fields.size(), struct flr_field);
    for (uint64_t j = 0; j < ctx.typeinfo[i].fields.size(); j++) {
      std::string currentField =
        currentType + ".fields[" + std::to_string(j) + "]";

      ASSIGN_STR(fileContents, currentField + ".name",
                 ctx.typeinfo[i].fields[j].name);
      ASSIGN_VAL(fileContents, currentField + ".offset",
                 std::to_string(ctx.typeinfo[i].fields[j].offset));
      writeTypeSpecifier(fileContents, currentField + ".type",
                         ctx.typeinfo[i].fields[j].type);
    }

    fileContents += "\n\t";
  }
}

void Reflection::emit(const struct Reflection::context &ctx) {
  std::string relativePath = getRelativePath(ctx.outFile, ctx.reflectionHeader);

  std::string fileContents;

  fileContents += "#include \"" + relativePath + "\"\n";
  fileContents += "#include <stdlib.h>\n";
  fileContents += "#include <stdint.h>\n";
  fileContents += "#include <string.h>\n";

  // Add more headers if needed

  fileContents += "\n";

  fileContents += "struct flr_programInfo flr_load(flr_Alloc allocator) {\n\t";

  std::string programInfoStruct = "info";

  fileContents += "struct flr_programInfo " + programInfoStruct + ";\n\t";

  fileContents += "\n\t";

  ALLOC_MEM(fileContents, programInfoStruct + ".types", ctx.typeinfo.size(),
            struct flr_typeInfo);
  ASSIGN_VAL(fileContents, programInfoStruct + ".numTypes",
             std::to_string(ctx.typeinfo.size()));

  fileContents += "\n\t";

  ALLOC_MEM(fileContents, programInfoStruct + ".enums", ctx.enumInfo.size(),
            struct flr_enumInfo);
  ASSIGN_VAL(fileContents, programInfoStruct + ".numEnums",
             std::to_string(ctx.enumInfo.size()));

  fileContents += "\n\t";

  writeInfo(fileContents, programInfoStruct, ctx);

  fileContents += "return " + programInfoStruct + ";\n";
  fileContents += "}\n";

  FILE *f = fopen(ctx.outFile.c_str(), "w");
  fwrite(fileContents.c_str(), 1, fileContents.length(), f);
  fclose(f);
}
