all: book
	g++ -pedantic-errors -g main.cpp book
book: book.h book.cpp
	g++ -pedantic-errors -g -c book.cpp -o book
clean:
	rm book
	rm a.out