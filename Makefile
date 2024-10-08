# Makefile for the Sudoku

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I.

# Source files
SRCS = testProgSudoku.cpp sudoku.cpp

# Object files
OBJS = testProgSudoku.o sudoku.o

# Executable name
TARGET = testSudoku

# Default rule
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile testProgSudoku.cpp
testProgSudoku.o: testProgSudoku.cpp sudoku.h 
	$(CXX) $(CXXFLAGS) -c testProgSudoku.cpp

# Rule to compile sudoku.cpp
sudoku.o: sudoku.cpp sudoku.h 
	$(CXX) $(CXXFLAGS) -c sudoku.cpp

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
