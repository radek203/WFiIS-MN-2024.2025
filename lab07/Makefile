# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
OBJ = lab07.o           # Object file

# Target: all (default target)
all: lab07

# Target: executable 'lab07'
lab07: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab07 $(OBJ)

# Target: compiling lab07.o
lab07.o: lab07.cpp
	$(CXX) $(CXXFLAGS) -c lab07.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab07

