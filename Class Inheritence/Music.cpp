//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Music Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MUSIC_CLASS_IMPL_H_
#define MUSIC_CLASS_IMPL_H_

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

// include header file
#include "Music.hpp"

//defines for default vaules and text output options
#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
#define DEF_PRODUCER ""
#define DEF_MIN 0.0
#define DEF_GENRE Genre::DEF
#define TEXT_WIDTH 20

//Function prototype for insertion operator
std::ostream& operator<<(std::ostream &out, Music &music);

Music::Music() : MediaItems()
{
	/*MediaItems::MediaItems();*/

	Music::setProducer(DEF_PRODUCER);
	Music::setRunTime(DEF_MIN);
	Music::setGenre(DEF_GENRE);

	MediaItems::modified(false);
	active++;
}


Music::~Music()
{
	active--;
}

//Set video Director
int Music::setProducer(std::string new_producer)
{
	Music::Producer = new_producer;
	MediaItems::modified(true);
	return 0;
}

//set time of music
int Music::setRunTime(double new_Minutes)
{
	if (new_Minutes >=0)
	{
		Music::minutes = new_Minutes;
		MediaItems::modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a positive value for minutes";
		return -1;
	}
}

//set genre
int Music::setGenre(Genre new_genre)
{
	Music::musicGenre = new_genre;
	return 0;
}

//get the producer name
std::string Music::getProducer()
{
	return Producer;
}

//get the music time
double Music::getRunTime()
{
	return minutes;
}

//get music genre
Music::Genre Music::getGenre()
{
	return musicGenre;
}

int Music::toCout()
{
	std::cout << (*this);
	return 0;
}

//return the number of constructed items
int Music::in_mem()
{
	return active;
}

//clear music object
int Music::clear()
{
	(*this) = Music::Music();
	MediaItems::active = MediaItems::active - 2; //active is increased by two when calling the constructor
	return 0;
}

std::ostream& operator<<(std::ostream &out, Music &music)
{

	//check if the item is empty
	if (music.isEmpty() == true); //if empty print nothing
	else if (music.isEmpty() == false) //if not empty print data thats available
	{
		// display item name if present
		if (music.getName() == DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item Name" << " : " << "No Name Set" << std::endl;
		}
		else if (music.getName() != DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << music.getName() << std::endl;
		}

		//display publication year if set; check if the value is default
		if (music.getPubYearDef() == true);
		else if (music.getPubYearDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << music.getPubYear() << std::endl;
		}

		//display price if set
		if (music.getPrice() == DEF_PRICE);
		else if (music.getPrice() != DEF_PRICE)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << music.getPrice() << std::endl;
		}

		//display producer if set
		if (music.getProducer() == DEF_PRODUCER);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Director" << " : " << music.getProducer() << std::endl;
		}

		//display minutes
		if (music.getRunTime() == DEF_MIN);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Minutes" << " : " << music.getRunTime() << std::endl;
		}

		//Display genre
		/*if (music.getGenre == 'Def');
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Genre" << " : " << music.getGenre() << std::endl;
		}*/

		//display elements if they exist; 
		if ((*music.getElements(0)).isEmpty() == true);
		else if ((*music.getElements(0)).isEmpty() == false)
		{
			int count = 0;
			while ((*music.getElements(count)).isEmpty() == false)
			{
				out << (*music.getElements(count));
				count++;
			}
		}
	}
	return out;
}

#endif