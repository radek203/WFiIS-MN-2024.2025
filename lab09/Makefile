# Define variables
CXX = g++               # The C++ compiler
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
LDFLAGS = -lgsl -lgslcblas -lm
OBJ = lab09.o           # Object file

# Target: all (default target)
all: lab09

# Target: executable 'lab09'
lab09: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab09 $(OBJ) $(LDFLAGS)

# Target: compiling lab09.o
lab09.o: lab09.cpp
	$(CXX) $(CXXFLAGS) -c lab09.cpp

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab09

