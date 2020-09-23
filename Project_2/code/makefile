CPPflags= c++ -o
LIB = -larmadillo -llapack -lblas

all: compile execute

compile:
	${CPPflags} ./main.out test_functions.cpp eigenvalues.cpp ${LIB}

execute:
	./main.out
