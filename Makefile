# Compiler
CC = gcc

# Compiler flags (add include directory!)
CFLAGS = -Wall -Wextra -g -I$(INC_DIR)

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
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# SAFE Clean up compiled files (DOES NOT delete .c files)
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)
