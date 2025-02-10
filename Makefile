# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
INC_DIR = include

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/player.c $(SRC_DIR)/career.c

# Object files (convert .c to .o safely)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRC))

# Executable name
TARGET = audit-escape

# Default rule: Compile the game
all: $(TARGET)

# Link all object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each .c file into a .o object file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/player.h $(INC_DIR)/career.h
	$(CC) $(CFLAGS) -c $< -o $@

# SAFE Clean up compiled files (DOES NOT delete .c files)
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)
