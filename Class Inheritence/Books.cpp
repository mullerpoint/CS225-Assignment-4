//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Books Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include "Author.hpp"
#include "Books.hpp"

#define DEF_PAGES 0
#define DEF_PUB 1970
#define DEF_ISBN ""

Books::Books()
{
	MediaItems::MediaItems();
	
	setPages(DEF_PAGES);
	
	setInPrint(false);
	in_print_def = true;

	setSequel(NULL);

	setAuthor(NULL);

	setISBN(DEF_ISBN);

	MediaItems::modified(false);
	active++;
}


Books::~Books()
{
	active--;
}


//set book page count - validate that the book doesnt have a negative page count
int Books::setPages(int new_pages)
{
	if (new_pages >= 0)
	{
		Books::pages = new_pages;
		MediaItems::modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a valid positive page number.";
		return -1;
	}

}

//set book in print status
int Books::setInPrint(bool printStatus)
{
	in_print = printStatus;
	in_print_def = false;
	MediaItems::modified(true);
	return 0;
}

//Set Sequel
int Books::setSequel(Books* new_sequel)
{
	Books::sequel_ptr = new_sequel;
	MediaItems::modified(true);
	return 0;
}

//set book author
int Books::setAuthor(Author* new_author)
{
	Books::auth_ptr = new_author;
	MediaItems::modified(true);
	return 0;
}

int Books::setISBN(std::string new_isbn)
{
	Books::isbn = new_isbn;
	MediaItems::modified(true);
	return 0;
}

//return the number of constructed items
int Books::in_mem()
{
	return active;
}