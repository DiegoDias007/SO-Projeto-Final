#
# Project Makefile
#

# =============================================================================
# Project Configuration
# =============================================================================

# Compiler and Flags
CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Directories
SRC_DIR   = src
BUILD_DIR = build

# Target executable
TARGET = $(BUILD_DIR)/my_program

# =============================================================================
# Sources
# =============================================================================

# Automatically find all C++ source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# =============================================================================
# Build Targets
# =============================================================================

# Default target executed when 'make' is run
all: $(TARGET)

# Link the executable
$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# =============================================================================
# Utility Targets
# =============================================================================

# Execute the program
run: all
	@./$(TARGET)

# Remove all build artifacts
clean:
	@rm -rf $(BUILD_DIR)

# Force a complete rebuild of the project
rebuild: clean all

# Declare targets that are not files
.PHONY: all run clean rebuild