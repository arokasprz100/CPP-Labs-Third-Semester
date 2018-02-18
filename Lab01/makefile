CCX=g++
CXXFLAGS= -g -Wall
SRC=$(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
TARG=Main4.exe


all: $(TARG) 

$(TARG): $(OBJ) 
	$(CCX) $^ $(CXXFLAGS) -o $@
Main.o: Czas.h
	$(CCX) -c Main.cpp 
.PHONY: clean run

clean:
	rm $(OBJ) $(TARG)
run:
	./$(TARG)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARG)
gdb:
	gdb ./$(TARG)
