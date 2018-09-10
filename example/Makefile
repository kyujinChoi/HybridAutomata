GG = g++

all::Main.exe

Main.exe:Main.o HybridAutomata.o
	$(GG) -o $@ $^

%.o: %.cpp $(DEPS)
	$(GG) -c -o $@ $< 

clean: 
	rm -f *.exe *.o *~ *.stackdump .*.swo .*.swp