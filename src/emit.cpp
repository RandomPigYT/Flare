#include "emit.hpp"
#include "typeinfo.hpp"

#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <filesystem>

struct emittterStatus {
  std::string fileContents;
  uint32_t indentLevel;

  emittterStatus() {
    fileContents = "";
    indentLevel = 0;
  }
};

static void addIndent(struct emittterStatus &s) {
  for (uint32_t i = 0; i < s.indentLevel; i++) {
    s.fileContents += "\t";
  }
}

static void addLine(struct emittterStatus &s) {
  s.fileContents += "\n";
}
static void beginBlock(struct emittterStatus &s,
                       const std::string &blockHeader = "",
                       bool prependSpace = false, bool shouldAddIndent = true) {
  if (shouldAddIndent)
    addIndent(s);

  s.fileContents += prependSpace ? " " : "";
  s.fileContents +=
    blockHeader + std::string(!blockHeader.length() ? "" : " ") + "{\n";
  s.indentLevel++;
}

static void endBlock(struct emittterStatus &s, const std::string &end = ",") {
  s.indentLevel--;
  addIndent(s);
  s.fileContents += "}" + end + "\n";
}

static void assignVal(struct emittterStatus &s, const std::string &dst,
                      const std::string &src, const std::string &end = ",") {
  addIndent(s);
  s.fileContents += dst + " = " + src + end + "\n";
}

static void assignBlock(struct emittterStatus &s, const std::string &dst,
                        const std::string &blockHeader = "") {
  addIndent(s);
  s.fileContents += dst + " =";
  beginBlock(s, blockHeader, true, false);
}

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

static void writeAliases(struct emittterStatus &s,
                         const std::vector<std::string> &aliases) {
  if (!aliases.size()) {
    addLine(s);
    addIndent(s);
    s.fileContents += "// No aliases\n";
    addLine(s);

    return;
  }

  for (auto &i : aliases) {
    addIndent(s);
    s.fileContents += "\"" + i + "\",\n";
  }
}

static void writeTypeSpecifier(struct emittterStatus &s,
                               const struct Reflection::typeSpecifier &type) {
  switch (type.type) {
    case Reflection::FIELD_TYPE_PTR: {
      assignVal(s, ".type", "FIELD_TYPE_PTR");
      assignBlock(s, ".ptrInfo", "&(struct flr_ptrRef)");

      auto temp = (struct Reflection::ptrRef *)type.info;

      assignVal(s, ".level", std::to_string(temp->level));

      assignBlock(s, ".type");
      writeTypeSpecifier(s, temp->type);
      endBlock(s);

      endBlock(s);
    } break;

    case Reflection::FIELD_TYPE_ARRAY: {
      assignVal(s, ".type", "FIELD_TYPE_ARRAY");
      assignBlock(s, ".arrayInfo", "&(struct flr_arrayRef)");

      auto temp = (struct Reflection::arrayRef *)type.info;

      assignVal(s, ".size", std::to_string(temp->size));

      assignBlock(s, ".type");
      writeTypeSpecifier(s, temp->type);
      endBlock(s);

      endBlock(s);
    } break;

    case Reflection::FIELD_TYPE_STRUCT:
    case Reflection::FIELD_TYPE_UNION: {
      if (type.type == Reflection::FIELD_TYPE_STRUCT) {
        assignVal(s, ".type", "FIELD_TYPE_STRUCT");
      } else {
        assignVal(s, ".type", "FIELD_TYPE_UNION");
      }

      assignBlock(s, ".recordInfo", "&(struct flr_recordRef)");

      auto temp = (struct Reflection::recordRef *)type.info;

      assignVal(s, ".ID", std::to_string(temp->ID));
      assignVal(s, ".fileName", "\"" + std::string(temp->fileName) + "\"");

      endBlock(s);

    } break;
    case Reflection::FIELD_TYPE_FUNCTION: {
      assignVal(s, ".type", "FIELD_TYPE_FUNCTION");
    } break;
    case Reflection::FIELD_TYPE_ENUM: {
      assignVal(s, ".type", "FIELD_TYPE_ENUM");
      assignBlock(s, ".recordInfo", "&(struct flr_recordRef)");

      auto temp = (struct Reflection::enumRef *)type.info;

      assignVal(s, ".ID", std::to_string(temp->ID));
      assignVal(s, ".fileName", "\"" + std::string(temp->fileName) + "\"");

      endBlock(s);
    } break;

    case Reflection::FIELD_TYPE_I8: {
      assignVal(s, ".type", "FIELD_TYPE_I8");
    } break;
    case Reflection::FIELD_TYPE_I16: {
      assignVal(s, ".type", "FIELD_TYPE_I16");
    } break;
    case Reflection::FIELD_TYPE_I32: {
      assignVal(s, ".type", "FIELD_TYPE_I32");
    } break;
    case Reflection::FIELD_TYPE_I64: {
      assignVal(s, ".type", "FIELD_TYPE_I64");
    } break;
    case Reflection::FIELD_TYPE_LONGLONG: {
      assignVal(s, ".type", "FIELD_TYPE_LONGLONG");
    } break;
    case Reflection::FIELD_TYPE_UI8: {
      assignVal(s, ".type", "FIELD_TYPE_UI8");
    } break;
    case Reflection::FIELD_TYPE_UI16: {
      assignVal(s, ".type", "FIELD_TYPE_UI16");
    } break;
    case Reflection::FIELD_TYPE_UI32: {
      assignVal(s, ".type", "FIELD_TYPE_UI32");
    } break;
    case Reflection::FIELD_TYPE_UI64: {
      assignVal(s, ".type", "FIELD_TYPE_UI64");
    } break;
    case Reflection::FIELD_TYPE_ULONGLONG: {
      assignVal(s, ".type", "FIELD_TYPE_ULONGLONG");
    } break;
    case Reflection::FIELD_TYPE_FLOAT: {
      assignVal(s, ".type", "FIELD_TYPE_FLOAT");
    } break;
    case Reflection::FIELD_TYPE_DOUBLE: {
      assignVal(s, ".type", "FIELD_TYPE_DOUBLE");
    } break;
    case Reflection::FIELD_TYPE_LONG_DOUBLE: {
      assignVal(s, ".type", "FIELD_TYPE_LONG_DOUBLE");
    } break;
    case Reflection::FIELD_TYPE_VOID: {
      assignVal(s, ".type", "FIELD_TYPE_VOID");
    } break;

    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_I8: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_I8");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_I16: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_I16");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_I32: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_I32");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_I64: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_I64");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_UI8: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_UI8");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_UI16: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_UI16");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_UI32: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_UI32");
    } break;
    case Reflection::FIELD_TYPE_GNU_EXT_COMPLEX_UI64: {
      assignVal(s, ".type", "FIELD_TYPE_GNU_EXT_COMPLEX_UI64");
    } break;
    case Reflection::FIELD_TYPE_COMPLEX_FLOAT: {
      assignVal(s, ".type", "FIELD_TYPE_COMPLEX_FLOAT");
    } break;
    case Reflection::FIELD_TYPE_COMPLEX_DOUBLE: {
      assignVal(s, ".type", "FIELD_TYPE_COMPLEX_DOUBLE");
    } break;
    case Reflection::FIELD_TYPE_COMPLEX_LONG_DOUBLE: {
      assignVal(s, ".type", "FIELD_TYPE_COMPLEX_LONG_DOUBLE");
    } break;

    default: {
      assignVal(s, ".type", "FIELD_TYPE_NONE");
    } break;
  }
}

static void writeFields(struct emittterStatus &s,
                        const std::vector<struct Reflection::field> &fields) {
  if (!fields.size()) {
    addLine(s);
    addIndent(s);
    s.fileContents += "// No fields\n";
    addLine(s);

    return;
  }
  uint64_t fieldNum = 0;
  for (auto &i : fields) {
    beginBlock(s);

    assignVal(s, ".name", "\"" + i.name + "\"");
    assignVal(s, ".offset", std::to_string(i.offset));

    assignBlock(s, ".type");
    writeTypeSpecifier(s, i.type);
    endBlock(s);

    endBlock(s);

    if (fieldNum++ != fields.size() - 1)
      addLine(s);
  }
}

static void
writeConstants(struct emittterStatus &s,
               const std::vector<struct Reflection::enumConstant> &constants) {
  if (!constants.size()) {
    addLine(s);
    addIndent(s);
    s.fileContents += "// No constants\n";
    addLine(s);

    return;
  }
  uint64_t constantNum = 0;
  for (auto &i : constants) {
    beginBlock(s);

    assignVal(s, ".name", "\"" + i.name + "\"");
    assignVal(s, ".value", std::to_string(i.value));

    endBlock(s);

    if (constantNum++ != constants.size() - 1)
      addLine(s);
  }
}

static void writeInfo(struct emittterStatus &s,
                      const struct Reflection::context &ctx) {
  assignBlock(s, ".types", "(struct flr_typeInfo[])");

  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    beginBlock(s);

    assignVal(s, ".ID", std::to_string(ctx.typeinfo[i].ID));
    assignVal(s, ".filename", "\"" + ctx.typeinfo[i].fileName + "\"");
    assignVal(s, ".name", "\"" + ctx.typeinfo[i].name + "\"");

    assignVal(s, ".numAliases", std::to_string(ctx.typeinfo[i].aliases.size()));
    assignBlock(s, ".aliases", "(char (*[]))");
    writeAliases(s, ctx.typeinfo[i].aliases);
    endBlock(s);

    assignVal(s, ".recordType", std::to_string(ctx.typeinfo[i].recordType));

    assignVal(s, ".numFields", std::to_string(ctx.typeinfo[i].fields.size()));
    assignBlock(s, ".fields", "(struct flr_field[])");
    writeFields(s, ctx.typeinfo[i].fields);
    endBlock(s);

    endBlock(s);

    if (i != ctx.typeinfo.size() - 1)
      addLine(s);
  }

  endBlock(s);

  addLine(s);

  assignBlock(s, ".enums", "(struct flr_enumInfo[])");

  for (uint64_t i = 0; i < ctx.enumInfo.size(); i++) {
    beginBlock(s);

    assignVal(s, ".ID", std::to_string(ctx.enumInfo[i].ID));
    assignVal(s, ".filename", "\"" + ctx.enumInfo[i].fileName + "\"");
    assignVal(s, ".name", "\"" + ctx.enumInfo[i].name + "\"");

    assignVal(s, ".numAliases", std::to_string(ctx.enumInfo[i].aliases.size()));
    assignBlock(s, ".aliases", "(char (*[]))");
    writeAliases(s, ctx.enumInfo[i].aliases);
    endBlock(s);

    assignVal(s, ".numConstants",
              std::to_string(ctx.enumInfo[i].constants.size()));
    assignBlock(s, ".constants", "(struct flr_enumConstant[])");
    writeConstants(s, ctx.enumInfo[i].constants);
    endBlock(s);

    endBlock(s);
    if (i != ctx.enumInfo.size() - 1)
      addLine(s);
  }

  endBlock(s);
}

void Reflection::emit(const struct Reflection::context &ctx) {
  std::string relativePath = getRelativePath(ctx.outFile, ctx.reflectionHeader);

  std::string fileContents;

  struct emittterStatus s;

  s.fileContents += "#include \"" + relativePath + "\"\n";
  s.fileContents += "#include <stdlib.h>\n";
  s.fileContents += "#include <stdint.h>\n";
  s.fileContents += "#include <string.h>\n";

  // Add more headers if needed

  s.fileContents += "\n";

  std::string programInfoStruct = "info";
  //s.fileContents += "struct flr_programInfo " + programInfoStruct + " = ";

  assignBlock(s, "struct flr_programInfo " + programInfoStruct);

  assignVal(s, ".numTypes", std::to_string(ctx.typeinfo.size()));
  assignVal(s, ".numEnums", std::to_string(ctx.enumInfo.size()));

  addLine(s);

  writeInfo(s, ctx);

  endBlock(s, ";");

  addLine(s);

  s.fileContents +=
    "struct flr_programInfo flr_load(flr_Alloc allocator) {\n\t";

  s.fileContents += "return " + programInfoStruct + ";\n";
  s.fileContents += "}\n";

  FILE *f = fopen(ctx.outFile.c_str(), "w");
  fwrite(s.fileContents.c_str(), 1, s.fileContents.length(), f);
  fclose(f);
}
