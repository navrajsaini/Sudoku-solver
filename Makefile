
CCC = g++
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11


all : Sudoku

Sudoku : Sudoku.o
	$(CCC) $(CCCFLAGS) -o $@ $^


%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<


clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f Sudoku
