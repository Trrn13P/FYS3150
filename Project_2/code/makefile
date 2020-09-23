CPPflags= c++ -o
LIB = -larmadillo -llapack -lblas

all: compile execute

compile:
	${CPPflags} ./main.out test_functions.cpp eigenvalues.cpp ${LIB}

execute:
	./main.out

#
#CPPflags= c++ -O3



#PROG= testcode
#${PROG} :	   	tests_main.o  test_functions.o jacobi.o
#			${CPPflags} tests_main.o test_functions.o jacobi.o ${LIB} -o ${PROG}

#tests-main.o :			tests_main.cpp
#		        	${CPPflags} -c tests_main.cpp

#test-functitons.o :			test_functions.cpp
#		        	${CPPflags} -c test_functions.cpp
