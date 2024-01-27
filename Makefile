CC:=g++
LD:=g++

CFLAGS:= -Wall -Wextra -g -std=c++20 -fPIC $(shell llvm-config --cxxflags) -I.
LDFLAGS := -fPIC -shared
LDFLAGS += $(shell llvm-config --ldflags) -lncurses -lclang-cpp
LDFLAGS += $(shell llvm-config --libs)

BIN:=bin
OBJ:=obj
SRC:=src
INCLUDE:=include


TARGET:=$(BIN)/reflection.so
VALGRIND_OUT:=./val_out.txt

SRCS:=$(shell find $(SRC) -type  f -name "*.cpp")
OBJS:=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
INCLUDES:=$(shell find $(INCLUDE) -type f -name "*.h")

DIRS:=$(patsubst $(SRC)/%, $(OBJ)/%, $(shell find $(SRC)/ -mindepth 1 -type d))

CREATE_DIR_COMMAND:=./dirs.sh

.PHONY: all clean dirs valgrind format run

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	@echo
	@echo building $(TARGET)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@echo built $(TARGET)

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo building $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo built $@
	@echo

dirs:
	@mkdir -p $(BIN)
	@mkdir -p $(OBJ)
	@$(CREATE_DIR_COMMAND) $(DIRS)

clean:
	-@rm -rf $(OBJ)
	-@rm -rf $(BIN)

run: $(TARGET)
	@clang -Xclang -load -Xclang $(TARGET) -Xclang -add-plugin -Xclang reflection -fsyntax-only testFiles/as.c testFiles/lol.c

valgrind:
	@valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(VALGRIND_OUT) \
         ./$(TARGET)	"test"

format:
	@clang-format $(SRCS) $(INCLUDES) --style=Google -i

