#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <set>
#include <map>

using std::string;
using std::ostream;
using std::endl;
using std::set;
using std::map;


enum genreType {NONFICTION, FICTION, SCIFI, CHILD, HORROR, FANTASY, AUTOBIO, BIO, HIST};

enum genreGroupType {HISTFICT, PICTURE, HISTBIO, SCIFIFANT};

const map<genreType,string> genreToStr = {{NONFICTION, "Non-Fiction"},{FICTION, "Fiction"}, {SCIFI, "Science Fiction"}, {CHILD, "Childrens"}, {HORROR, "Horror"}, {FANTASY, "Fantasy"}, {AUTOBIO, "Autobiography"}, {BIO, "Biography"}, {HIST, "Historical"}};

const map<string, genreType> strToGenre = {{"NON-FICTION", NONFICTION}, {"FICTION", FICTION}, {"SCIENCE FICTION", SCIFI}, {"CHILDRENS", CHILD}, {"HORROR", HORROR}, {"FANTASY", FANTASY}, {"AUTOBIOGRAPHY", AUTOBIO}, {"BIOGRAPY", BIO}, {"HISTORICAL", HIST}};

const map<genreGroupType, string> genreGroupToStr {{HISTFICT, "Historical Fiction"}, {PICTURE ,"Childrens Picture Book"}, {HISTBIO, "Historical Biography"}, {SCIFIFANT, "Sci-fi Fantasy"}};

const map<string, genreGroupType> strToGenreGroup {{"HISTORICAL FICTION",HISTFICT}, {"CHILDRENS PICTURE BOOK", PICTURE}, {"HISTORICAL BIOGRAPHY", HISTBIO}, {"SCI-FI FANTASY", SCIFIFANT}};

const map<genreGroupType, set<genreType>> genreGroupGenres {{HISTFICT, {FICTION, HIST}}, {PICTURE, {CHILD, FICTION}}, {HISTBIO, {NONFICTION, HIST, BIO}}, {SCIFIFANT, {SCIFI, FANTASY}}};

class book
{
public:
	book(string, string, string, string, string, string);
	book(const book&);
	~book();
	void addGenre(string genre);
	void addGenreGroup(string);
	bool operator==(const book&);
	bool operator!=(const book&);
	string getTitle() const;
	string getAuthor() const;
	friend ostream& operator<<(ostream&, const book&);
private:
	string author;
	string title;
	string subject;
	set<genreType> genres;
	string publisher;
	string callNum;
	string isbn;
	
};

#endif