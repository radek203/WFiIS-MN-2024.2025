# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
OBJ = lab08.o           # Object file

# Target: all (default target)
all: lab08

# Target: executable 'lab08'
lab08: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab08 $(OBJ)

# Target: compiling lab08.o
lab08.o: lab08.cpp
	$(CXX) $(CXXFLAGS) -c lab08.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab08

