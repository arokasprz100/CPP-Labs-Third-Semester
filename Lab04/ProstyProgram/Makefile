CXX=g++
CXXFLAGS=-Wall -g

Program : Main.cpp Functions.h
	$(CXX) $(CXXFLAGS) Main.cpp -o $@

.PHONY: clean

clean:
	rm -f *.o Program
