# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20  # Compiler flags, including C++ standard
OBJ = lab01.o           # Object file

# Target: all (default target)
all: lab01

# Target: executable 'lab01'
lab01: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab01 $(OBJ)

# Target: compiling lab01.o
lab01.o: lab01.cpp
	$(CXX) $(CXXFLAGS) -c lab01.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab01

