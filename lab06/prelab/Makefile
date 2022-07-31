CXX=clang++
CXXFLAGS=-Wall -O2
OFILES = hashTable.o timer.o wordPuzzle.o
.SUFFIXES: .o .cpp
words: $(OFILES)
	 $(CXX) $(CXXFLAGS) $(OFILES)
clean:
	-rm -f *.o *~ outputfile