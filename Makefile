#
# Project Makefile
#

# =============================================================================
# Project Configuration
# =============================================================================

# Compiler and Flags
CXX      = g++
CXXFLAGS = -std=c++11

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
# Targets de Execucao
# =============================================================================

# Executar o programa (padrao com priority_rr)
run: all
	@./$(TARGET) priority_rr

# =============================================================================
# Targets Especificos de Algoritmos
# =============================================================================

# Executar algoritmo FCFS (First Come First Served)
fcfs: all
	@./$(TARGET) fcfs

# Executar algoritmo SJF (Shortest Job First)
sjf: all
	@./$(TARGET) sjf

# Executar algoritmo RR (Round Robin)
rr: all
	@./$(TARGET) rr

# Executar algoritmo Priority Scheduling
priority: all
	@./$(TARGET) priority

# Executar algoritmo Priority Round Robin
priority_rr: all
	@./$(TARGET) priority_rr

# =============================================================================
# Targets Utilitarios
# =============================================================================

# Remover todos os arquivos de build
clean:
	@rm -rf $(BUILD_DIR)


# Mostrar targets de algoritmos disponiveis
help:
	@echo "Targets disponiveis:"
	@echo "  make fcfs        - Executar algoritmo First Come First Served"
	@echo "  make sjf         - Executar algoritmo Shortest Job First"
	@echo "  make rr          - Executar algoritmo Round Robin"
	@echo "  make priority    - Executar algoritmo Priority Scheduling"
	@echo "  make priority_rr - Executar algoritmo Priority Round Robin"
	@echo "  make all         - Compilar o programa"
	@echo "  make run         - Executar algoritmo padrao (priority_rr)"
	@echo "  make clean       - Remover arquivos de build"
	@echo "  make help        - Mostrar esta mensagem de ajuda"
	@echo ""
	@echo "Todos os algoritmos usam automaticamente o arquivo schedule.txt."

# Declarar targets que nao sao arquivos
.PHONY: all run clean fcfs sjf rr priority priority_rr help