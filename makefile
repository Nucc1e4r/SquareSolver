SRC = Source
OBJ = Obj
OUTPUT = main

all: compile link

compile: $(SRC)/SquareSolver.cpp $(SRC)/sqrio.cpp $(SRC)/sqrdbg.cpp $(SRC)/eqslv.cpp $(SRC)/isZero.cpp
	g++ -c $(SRC)/SquareSolver.cpp -o $(OBJ)/SquareSolver.o
	g++ -c $(SRC)/sqrio.cpp -o $(OBJ)/sqrio.o
	g++ -c $(SRC)/sqrdbg.cpp -o $(OBJ)/sqrdbg.o
	g++ -c $(SRC)/eqslv.cpp -o $(OBJ)/eqslv.o	
	g++ -c $(SRC)/isZero.cpp -o $(OBJ)/isZero.o

link:
	g++ $(OBJ)/*.o -o $(OUTPUT)

SquareSolver:
	g++ -c $(SRC)/SquareSolver.cpp -o $(OBJ)/SquareSolver.o

sqrio:
	g++ -c $(SRC)/sqrio.cpp -o $(OBJ)/sqrio.o

sqrdbg:
	g++ -c $(SRC)/sqrdbg.cpp -o $(OBJ)/sqrdbg.o

eqslv:
	g++ -c $(SRC)/eqslv.cpp -o $(OBJ)/eqslv.o

isZero:
	g++ -c $(SRC)/isZero.cpp -o $(OBJ)/isZero.o