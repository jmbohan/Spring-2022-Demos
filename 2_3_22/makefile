all: book
	g++ -pedantic-errors -g main.cpp book
book: book.h book.cpp
	g++ -pedantic-errors -g -c book.cpp -o book
intLinkedList: intLinkedList.cpp intLinkedList.h
	g++ -pedantic-errors -g -c intLinkedList.cpp -o intLinkedList
clean:
	rm intLinkedList
	rm a.out