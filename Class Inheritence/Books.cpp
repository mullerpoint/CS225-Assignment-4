//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Books Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOKS_CLASS_IMPL_H_
#define BOOKS_CLASS_IMPL_H_

#ifndef MEDIA_DEPENDENCIES_CORE_H_
#define MEDIA_DEPENDENCIES_CORE_H_
#include <iostream> //default include
#include <string> // included to get strings to work
#include <locale> // included to get locale info for output
#include <io.h> // isatty for windows
//#include <unistd.h> // isatty  for linux
#include <iomanip> // included to make pretty output
#endif

#include "Books.hpp"

#define DEF_PAGES 0
#define DEF_PUB 1970
#define DEF_ISBN ""
#define TEXT_WIDTH 20

Books::Books()
{
	MediaItems::MediaItems();
	
	setPages(DEF_PAGES);
	
	setInPrint(false);
	in_print_def = true;

	setSequel(NULL);

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

#endif