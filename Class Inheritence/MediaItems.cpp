//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Media Item Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MEDIAITEMS_CLASS_IMPL_H_
#define MEDIAITEMS_CLASS_IMPL_H_

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


#ifndef MEDIA_DEPENDENCIES_H_
#define MEDIA_DEPENDENCIES_H_
#include "Author.hpp"
#include "Elements.hpp"
#endif

#include "MediaItems.hpp"

#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
#define TEXT_WIDTH 20


//constructor
MediaItems::MediaItems()
{
	MediaItems::setName(DEF_NAME);

	MediaItems::setPrice(DEF_PRICE);

	MediaItems::setPubYear(DEF_PUB);
	pub_year_def = true;

	element_num = ELEMENT_ZERO;

	setAuthor(NULL);

	hasData = false;

	MediaItems::active++;
}

//destructor
MediaItems::~MediaItems()
{
	MediaItems::active--;
}

//set title of book
int MediaItems::setName(std::string new_name)
{
	MediaItems::name = new_name;
	modified(true);
	return 0;
}

int MediaItems::setPubYear(int new_year)
{
	if (new_year >= 0)
	{
		MediaItems::pub_year = new_year;
		MediaItems::pub_year_def = false;
		modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a valid Year.";
		return -1;
	}
}

//set the Media Item price - validate that the price is not negative
int MediaItems::setPrice(double new_price)
{
	if (new_price >= 0)
	{
		MediaItems::price = new_price;
		modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a valid positive price.";
		return -1;
	}
}

//set item elements
int MediaItems::setElement(int start, int end, std::string name, int elementNum)
//elementNum is not used but I included it to make it easier to change the program over later
{
	element[element_num].setStart(start);
	element[element_num].setEnd(end);
	element[element_num].setName(name);
	MediaItems::element_num++;
	modified(true);
	return 0;
}

//set author
int MediaItems::setAuthor(Author* new_author)
{
	MediaItems::auth_ptr = new_author;
	MediaItems::modified(true);
	return 0;
}

//print out item
int MediaItems::toCout()
{
	//check if the item is empty
	if (isEmpty() == true); //if empty print nothing
	else if (isEmpty() == false) //if not empty print data thats available
	{
		// display item name if present
		if (name == DEF_NAME);
		else if (name != DEF_NAME)
		{
			std::cout << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << name << std::endl;
		}

		//display publication year if set; check if the value is default
		if (pub_year_def == true);
		else if (pub_year_def == false)
		{
			std::cout << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << pub_year << std::endl;
		}

		//display price if set
		if (price == DEF_PRICE);
		else if (price != DEF_PRICE)
		{
			std::cout << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << price << std::endl;
		}

		//display elements if they exist; 
		if (element_num == ELEMENT_ZERO);
		else if (element_num > ELEMENT_ZERO)
		{
			int count = 0;
			while (count < element_num)
			{
				std::cout << MediaItems::element[count];
				count++;
			}
		}
	}
	return 0;
}

//get book title
std::string MediaItems::getName()
{
	return MediaItems::name;
}

//get pulication year
int MediaItems::getPubYear()
{
	return pub_year;
}

// get if the publication year is default
bool MediaItems::getPubYearDef()
{
	return pub_year_def;
}

//get author pointer
Author* MediaItems::getAuthor()
{
	return auth_ptr;
}

//get price of item
double MediaItems::getPrice()
{
	return price;
}

//get the address of an elemtent in the array
Elements* MediaItems::getElements(int elementNum)
{
	Elements* elem_addr = &element[elementNum];
	
	return elem_addr;
}

//returns if the item is empty
bool MediaItems::isEmpty()
{
	return !(hasData);
}

// set a modified flag
int MediaItems::modified(bool data)
{
	MediaItems::hasData = data;
	return 0;
}

//return the number of constructed items
int MediaItems::in_mem()
{
	return MediaItems::active;
}


std::ostream& operator<<(std::ostream &out, MediaItems &MI)
{
	//check if the item is empty
	if (MI.isEmpty() == true); //if empty print nothing
	else if (MI.isEmpty() == false) //if not empty print data thats available
	{
		// display item name if present
		if (MI.getName == DEF_NAME);
		else if (MI.getName != DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << MI.getName() << std::endl;
		}

		//display publication year if set; check if the value is default
		if (MI.getPubYearDef() == true);
		else if (MI.getPubYearDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << MI.getPubYear() << std::endl;
		}

		//display price if set
		if (MI.getPrice == DEF_PRICE);
		else if (MI.getPrice != DEF_PRICE)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << MI.getPrice() << std::endl;
		}

		//display elements if they exist; 
		if ((*MI.getElements(0)).isEmpty == true);
		else if ((*MI.getElements(0)).isEmpty == false)
		{
			int count = 0;
			while ((*MI.getElements(count)).isEmpty == false)
			{
				out << (*MI.getElements(count));
				count++;
			}
		}
	}
	return out;
}

#endif