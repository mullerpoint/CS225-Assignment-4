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


#include "Music.hpp"

#define DEF_PRODUCER ""
#define DEF_MIN 0.0
#define DEF_GENRE Genre::DEF
#define TEXT_WIDTH 20

Music::Music()
{
	MediaItems::MediaItems();

	Music::setProducer(DEF_PRODUCER);
	Music::setMinutes(DEF_MIN);
	Music::setGenre(DEF_GENRE);

	MediaItems::active++;
}


Music::~Music()
{
	MediaItems::active--;
}

//Set video Director
int Music::setProducer(std::string new_producer)
{
	Music::Producer = new_producer;
	MediaItems::modified(true);
	return 0;
}

//set time of music
int Music::setMinutes(double new_Minutes)
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

//return the number of constructed items
int Music::in_mem()
{
	return MediaItems::active;
}

#endif