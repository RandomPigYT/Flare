#include "emit.hpp"
#include "typeinfo.hpp"

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

void Reflection::emit(const struct Reflection::context &ctx) {
  std::string relativePath = getRelativePath(ctx.outFile, ctx.reflectionHeader);

  std::string fileContents;

  fileContents += "#include \"" + relativePath + "\"\n";
  fileContents += "#include <stdlib.h>\n";
  fileContents += "#include <stdint.h>\n";

  // Add more headers if needed

  fileContents += "\n";

  fileContents += "struct ref_programInfo *ref_load(ref_Alloc allocator) {\n";

  // Write type info to file

  fileContents += "}\n";

  FILE *f = fopen(ctx.outFile.c_str(), "w");
  fwrite(fileContents.c_str(), 1, fileContents.length(), f);
  fclose(f);
}
