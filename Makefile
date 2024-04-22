CC:=g++
LD:=g++

CFLAGS := -Wall -Wextra -O3 -std=gnu++17 -pedantic $(shell llvm-config --cppflags) -Wno-unused-label -I.
LDFLAGS := $(shell llvm-config --ldflags) -lncurses -lclang-cpp
LDFLAGS += $(shell llvm-config --libs)

BIN:=bin
OBJ:=obj
SRC:=src
INCLUDE:=include


TARGET:=$(BIN)/flare
VALGRIND_OUT:=./val_out.txt

SRCS:=$(shell find $(SRC) -type  f -name "*.cpp")
OBJS:=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
INCLUDES:=$(shell find $(INCLUDE) -type f -name "*.h")
INCLUDES +=$(shell find $(INCLUDE) -type f -name "*.hpp")
INCLUDES +=$(shell find $(SRC) -type f -name "*.hpp")

DIRS:=$(patsubst $(SRC)/%, $(OBJ)/%, $(shell find $(SRC)/ -mindepth 1 -type d))

CREATE_DIR_COMMAND:=./dirs.sh

.PHONY: all clean dirs valgrind format run

all: dirs $(TARGET)

$(TARGET): $(OBJS)
	@echo building $(TARGET)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@echo built $(TARGET)


$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDES)
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
	@./$(TARGET) testFiles/as.c testFiles/lol.c
	


valgrind: dirs $(TARGET)
	@valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(VALGRIND_OUT) \
         ./$(TARGET)	testFiles/as.c testFiles/lol.c

format: $(SRCS) $(INCLUDES)
	@clang-format $(SRCS) $(INCLUDES) --style=file:/home/randompigyt/.clang_frmt/.clang-format -i
	@echo Formatted: $(SRCS) $(INCLUDES)

test: $(TARGET)
	./$(TARGET) testFiles/enum.c testFiles/void.c testFiles/as.c testFiles/kind.c testFiles/array.c --opts --out "./emitted/out.c" --header "include/flare.h"
