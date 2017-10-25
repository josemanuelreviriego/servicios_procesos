DEPS = suma.h

suma: main.o suma.o
	g++ main.o suma.o -o suma

main.o: main.cpp $(DEPS)
	g++ -c main.cpp

suma.o: suma.cpp $(DEPS)
	g++ -c suma.cpp

.PHONY: clean

clean:
	$(RM) *.o
