all: simulation
	g++ -pedantic-errors -g main.cpp simulation
simulation: simulation.h simulationImp.cpp
	g++ -pedantic-errors -g -c simulationImp.cpp -o simulation
clean:
	rm a.out