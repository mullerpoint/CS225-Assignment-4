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
#endif

#include "Videos.hpp"

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

//std::ostream& operator<<(std::ostream &out, Videos &Video)
//{
//	out << Videos::element[1];
//
//
//	if (Video.getDirector() == DEF_DIRECTOR);
//	else
//	{
//		out << std::left << std::setw(TEXT_WIDTH) << "  Director" << " : " << Video.getDirector;
//	}
//	if (Video.getRunTime == DEF_RUNTIME);
//	else
//	{
//		out << std::left << std::setw(TEXT_WIDTH) << "  RunTime" << " : " << Video.getRunTime;
//	}
//	if (Video.getSequel == NULL);
//	else
//	{
//		out << std::left << std::setw(TEXT_WIDTH) << "  Sequel" << " : " << (*(Video.getSequel)).getName;
//	}
//
//
//	return out;
//}

#endif