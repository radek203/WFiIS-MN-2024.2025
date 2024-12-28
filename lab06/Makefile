# Define variables
CXX = g++               # The C++ compiler
CFLAGS = -Wall -std=c11 -O3 # Compiler flags for C files
CXXFLAGS = -Wall -std=c++20 -O3 # Compiler flags, including C++ standard
OBJ = lab06.o mgmres.o  # Object files

# Target: all (default target)
all: lab06

# Target: executable 'lab06'
lab06: $(OBJ)
	$(CXX) $(CXXFLAGS) -o lab06 $(OBJ)

# Target: compiling lab06.o
lab06.o: lab06.cpp
	$(CXX) $(CXXFLAGS) -c lab06.cpp

# Target: compiling mgmres.o
mgmres.o: mgmres.c mgmres.h
	$(CXX) $(CFLAGS) -c mgmres.c

# Target: clean (removes compiled files)
clean:
	rm -f *.o lab06
