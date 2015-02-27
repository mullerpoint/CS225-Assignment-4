//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Video Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include "Videos.hpp"

#define DEF_DIRECTOR ""
#define DEF_RUNTIME 0.0

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
}

//return the number of constructed items
int Videos::in_mem()
{
	return active;
}