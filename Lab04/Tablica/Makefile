CXX=g++
CXXFLAGS=-g

Program : Main.cpp Main.h
	$(CXX) $(CXXFLAGS) Main.cpp -o $@

.PHONY : clean

clean:
	rm -f *.o Program
