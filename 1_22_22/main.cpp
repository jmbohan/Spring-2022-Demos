#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "book.h"

using namespace std;

const map<genreType,string> genreToString {{NONFICTION, "Non-Fiction"},{FICTION, "Fiction"}, {SCIFI, "Science Fiction"}, {CHILD, "Childrens"}, {HORROR, "Horror"}, {FANTASY, "Fantasy"}, {AUTOBIO, "Autobiography"}, {BIO, "Biography"}};
const map<string, genreType> stringToGenre{{"Non-Fiction", NONFICTION},{"Fiction", FICTION}, {"Science Fiction", SCIFI}, {"Childrens", CHILD}, {"Horror", HORROR}, {"Fantasy", FANTASY}, {"Autobiography", AUTOBIO}, {"Biography", BIO}};



int main()
{
	vector<book> library;	
	genreType genres[] = {FICTION, CHILD, FANTASY};
	book myBook("author", "title", "subject", genres, 3, "publisher", "callNum", "isbn");
	library.push_back(myBook);
	for(int i = 0; i < library.size(); i++)
	{
		
	}
	
	return 0;
}

