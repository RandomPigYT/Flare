#include "emit.hpp"
#include "typeinfo.hpp"

#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <filesystem>

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
    fileContents += currentAlias + " = malloc(" +
                    std::to_string(aliases[i].length() + 1) + ");\n\t";
    fileContents += "strcpy(" + currentAlias + ", \"" + aliases[i] + "\");\n\t";
  }
}

static void writeTypeInfo(std::string &fileContents,
                          const std::string &programInfoStruct,
                          const struct Reflection::context &ctx) {
  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    std::string currentType =
      programInfoStruct + ".types[" + std::to_string(i) + "]";

    fileContents +=
      currentType + ".ID = " + std::to_string(ctx.typeinfo[i].ID) + ";\n\t";
    fileContents +=
      currentType + ".filename = \"" + ctx.typeinfo[i].fileName + "\";\n\t";
    fileContents +=
      currentType + ".name = \"" + ctx.typeinfo[i].name + "\";\n\t";
    fileContents += currentType + ".aliases = malloc(" +
                    std::to_string(ctx.typeinfo[i].aliases.size()) +
                    " * sizeof(char *));\n\t";
    std::string aliasArray = currentType + ".aliases";
    writeAliases(fileContents, aliasArray, ctx.typeinfo[i].aliases);
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
  fileContents += "if (!allocator) \n\t\tallocator = malloc;\n\n\t";
  fileContents += programInfoStruct + ".types = malloc(" +
                  std::to_string(ctx.typeinfo.size()) +
                  " * sizeof(struct flr_typeInfo));\n\t";
  fileContents += programInfoStruct +
                  ".numTypes = " + std::to_string(ctx.typeinfo.size()) +
                  ";\n\t";

  fileContents += "\n\t";

  fileContents += programInfoStruct + ".enums = malloc(" +
                  std::to_string(ctx.enumInfo.size()) +
                  " * sizeof(struct flr_enumInfo));\n\t";
  fileContents += programInfoStruct +
                  ".numEnums = " + std::to_string(ctx.enumInfo.size()) +
                  ";\n\n\t";
  writeTypeInfo(fileContents, programInfoStruct, ctx);

  fileContents += "return " + programInfoStruct + ";\n";
  fileContents += "}\n";

  FILE *f = fopen(ctx.outFile.c_str(), "w");
  fwrite(fileContents.c_str(), 1, fileContents.length(), f);
  fclose(f);
}
