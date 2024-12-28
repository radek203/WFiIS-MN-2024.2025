# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20  # Compiler flags, including C++ standard
OBJ = lab03.o           # Object file

# Target: all (default target)
all: lab03

# Target: executable 'lab03'
lab03: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab03 $(OBJ)

# Target: compiling lab03.o
lab03.o: lab03.cpp
	$(CXX) $(CXXFLAGS) -c lab03.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab03

