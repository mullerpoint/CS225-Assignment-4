//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Video Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VIDEOS_CLASS_IMPL_H_
#define VIDEOS_CLASS_IMPL_H_

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


#include "Videos.hpp"

#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
#define DEF_DIRECTOR ""
#define DEF_RUNTIME 0.0
#define TEXT_WIDTH 20

Videos::Videos()
{
	MediaItems::MediaItems();

	Videos::setDirector(DEF_DIRECTOR);
	Videos::setRunTime(DEF_RUNTIME);
	Videos::setSequel(NULL);

	MediaItems::modified(false);
	active++;
}


Videos::~Videos()
{
	active--;
}

//Set video Director
int Videos::setDirector(std::string new_Director)
{
	Videos::director = new_Director;
	MediaItems::modified(true);
	return 0;
}

//Set Video Run time
int Videos::setRunTime(double new_RunTime)
{
	if (new_RunTime >= 0)
	{
		Videos::runTime = new_RunTime;
		MediaItems::modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a positive run time";
		return -1;
	}
}

//Set Sequel
int Videos::setSequel(Videos* new_sequel)
{
	Videos::sequel_ptr = new_sequel;
	MediaItems::modified(true);
	return 0;
}

//get director
std::string Videos::getDirector()
{
	return director;
}

//get run time
double Videos::getRunTime()
{
	return runTime;
}

//get sequel pointer
Videos* Videos::getSequel()
{
	return sequel_ptr;
}

//return the number of constructed items
int Videos::in_mem()
{
	return active;
}

std::ostream& operator<<(std::ostream &out, Videos &Video)
{

	//check if the item is empty
	if (Video.isEmpty() == true); //if empty print nothing
	else if (Video.isEmpty() == false) //if not empty print data thats available
	{
		// display item name if present
		if (Video.getName() == DEF_NAME);
		else if (Video.getName() != DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << Video.getName() << std::endl;
		}

		//display publication year if set; check if the value is default
		if (Video.getPubYearDef() == true);
		else if (Video.getPubYearDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << Video.getPubYear() << std::endl;
		}

		//display price if set
		if (Video.getPrice() == DEF_PRICE);
		else if (Video.getPrice() != DEF_PRICE)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << Video.getPrice() << std::endl;
		}

				//display director if set
		if (Video.getDirector() == DEF_DIRECTOR);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Director" << " : " << Video.getDirector() << std::endl;
		}

		//display runtime if set
		if (Video.getRunTime() == DEF_RUNTIME);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  RunTime" << " : " << Video.getRunTime();
		}

		//display sequel if set
		if (Video.getSequel() == NULL);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Sequel" << " : " << (*(Video.getSequel())).getName();
		}

		//display elements if they exist; 
		if ((*Video.getElements(0)).isEmpty() == true);
		else if ((*Video.getElements(0)).isEmpty() == false)
		{
			int count = 0;
			while ((*Video.getElements(count)).isEmpty() == false)
			{
				out << (*Video.getElements(count));
				count++;
			}
		}
	}
	return out;
}

#endif