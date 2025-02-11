# Compiler
CC = gcc

# Compiler flags (add include directory!)
CFLAGS = -Wall -Wextra -g -I$(INC_DIR)

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests

# Source files for all .c files in src and tests directories
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# Test source files
TEST_SRC = $(TEST_DIR)/test_career.c

# Object files (convert .c to .o safely)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRC))

# Executable names
TARGET = audit-escape
TEST_EXEC = test-suite

# Default rule: Compile the game
all: $(TARGET)

# Compile game executable from .o files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each .c file into a .o object file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test suite
tests: $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_SRC) $(filter-out $(SRC_DIR)/main.c, $(SRC)) 


# SAFE Clean up compiled files (DOES NOT delete .c files)
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET) $(TEST_EXEC)


# Run the game
run: $(TARGET)
	./$(TARGET)

# Run tests
test: tests
	./$(TEST_EXEC)