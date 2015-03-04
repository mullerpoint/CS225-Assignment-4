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
#include <typeinfo>
#endif


#include "Books.hpp"

#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
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

//get page count
int Books::getPages()
{
	return pages;
}

//get in print status
bool Books::getInPrint()
{
	return in_print;
}

//get if in print is default
bool Books::getInPrintDef()
{
	return in_print_def;
}

//get the sequel pointer
Books* Books::getSequel()
{
	return sequel_ptr;
}

//get the isbn number
std::string Books::getISBN()
{
	return isbn;
}

std::ostream& operator<<(std::ostream &out, Books &Book)
{

	//check if the item is empty
	if (Book.isEmpty() == true); //if empty print nothing
	else if (Book.isEmpty() == false) //if not empty print data thats available
	{
		// display item name if present
		if (Book.getName() == DEF_NAME);
		else if (Book.getName() != DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << Book.getName() << std::endl;
		}

		//display publication year if set; check if the value is default
		if (Book.getPubYearDef() == true);
		else if (Book.getPubYearDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << Book.getPubYear() << std::endl;
		}

		//display price if set
		if (Book.getPrice() == DEF_PRICE);
		else if (Book.getPrice() != DEF_PRICE)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << Book.getPrice() << std::endl;
		}

		//display director if set
		if (Book.getPages() == DEF_PAGES);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Page Count" << " : " << Book.getPages() << std::endl;
		}

		//display runtime if set
		if (Book.getInPrintDef() == true)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Print Status" << " : " << "In Print";
		}
		else if (Book.getInPrintDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Print Status" << " : " << "Out of Print";
		}

		//display sequel if set
		if (Book.getSequel() == NULL);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Sequel" << " : " << (*(Book.getSequel())).getName();
		}

		//display elements if they exist; 
		if ((*Book.getElements(0)).isEmpty() == true);
		else if ((*Book.getElements(0)).isEmpty() == false)
		{
			int count = 0;
			while ((*Book.getElements(count)).isEmpty() == false)
			{
				out << (*Book.getElements(count));
				count++;
			}
		}
	}
	return out;
}

#endif