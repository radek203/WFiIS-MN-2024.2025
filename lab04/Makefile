# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20  # Compiler flags, including C++ standard
OBJ = lab04.o           # Object file

# Target: all (default target)
all: lab04

# Target: executable 'lab04'
lab04: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab04 $(OBJ)

# Target: compiling lab04.o
lab04.o: lab04.cpp
	$(CXX) $(CXXFLAGS) -c lab04.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab04

