SRC = Source
OBJ = Obj
OUTPUT = main
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: compile link

compile: SquareSolver.o $(OBJ)/sqrio.o sqrdbg.o eqslv.o dblequal.o

link:
	g++ $(OBJ)/*.o -o $(OUTPUT)

SquareSolver.o: $(SRC)/SquareSolver.cpp
	g++ -c $(SRC)/SquareSolver.cpp -o $(OBJ)/SquareSolver.o $(CFLAGS)

# $@

$(OBJ)/sqrio.o: $(SRC)/sqrio.cpp
	g++ -c $(SRC)/sqrio.cpp -o $(OBJ)/sqrio.o $(CFLAGS)

sqrdbg.o: $(SRC)/sqrdbg.cpp
	g++ -c $(SRC)/sqrdbg.cpp -o $(OBJ)/sqrdbg.o $(CFLAGS)

eqslv.o: $(SRC)/eqslv.cpp
	g++ -c $(SRC)/eqslv.cpp -o $(OBJ)/eqslv.o $(CFLAGS)

dblequal.o: $(SRC)/dblequal.cpp
	g++ -c $(SRC)/dblequal.cpp -o $(OBJ)/dblequal.o $(CFLAGS)