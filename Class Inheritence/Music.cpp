//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Music Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include "Music.hpp"

#define DEF_PRODUCER ""
#define DEF_MIN 0.0
#define DEF_GENRE Genre::DEF

Music::Music()
{
	MediaItems::MediaItems();

	Music::setProducer(DEF_PRODUCER);
	Music::setMinutes(DEF_MIN);
	Music::setGenre(DEF_GENRE);

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
}

//return the number of constructed items
int Music::in_mem()
{
	return active;
}