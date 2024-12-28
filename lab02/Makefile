# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20  # Compiler flags, including C++ standard
OBJ = lab02.o           # Object file

# Target: all (default target)
all: lab02

# Target: executable 'lab02'
lab02: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab02 $(OBJ)

# Target: compiling lab02.o
lab02.o: lab02.cpp
	$(CXX) $(CXXFLAGS) -c lab02.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab02

