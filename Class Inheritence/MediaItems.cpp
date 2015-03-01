//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Media Item Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MEDIAITEMS_CLASS_IMPL_H
#define MEDIAITEMS_CLASS_IMPL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Author.hpp"
#include "Elements.hpp"

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

	active++;
}

//destructor
MediaItems::~MediaItems()
{
	active--;
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
	return active;
}

//get book title
std::string MediaItems::getName()
{
	return MediaItems::name;
}

#endif