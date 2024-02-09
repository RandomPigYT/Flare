CC:=g++
LD:=g++

CFLAGS := -Wall -Wextra -O3 -g -std=c++20 -pedantic $(shell llvm-config --cxxflags) -I. -fdata-sections -ffunction-sections -Wl,--gc-sections 
LDFLAGS := $(shell llvm-config --ldflags) -lncurses -lclang-cpp
LDFLAGS += $(shell llvm-config --libs)

BIN:=bin
OBJ:=obj
SRC:=src
INCLUDE:=include


TARGET:=$(BIN)/reflection
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
	@./$(TARGET) testFiles/as.c testFiles/lol.c
	


valgrind: dirs $(TARGET)
	@valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(VALGRIND_OUT) \
         ./$(TARGET)	testFiles/as.c testFiles/lol.c

format: $(SRCS) $(INCLUDES)
	@clang-format $(SRCS) $(INCLUDES) --style=Google -i
	@echo Formatted: $(SRCS) $(INCLUDES)
