//
//Video Class declaration
//

#ifndef VIDEOS_CLASS_DEF_H_
#define VIDEOS_CLASS_DEF_H_

#include "MediaItems.hpp"
class Videos :
	public MediaItems
{
private:
	std::string director;
	double runTime;

	Videos* sequel_ptr;

public:
	Videos();
	~Videos();

	//mutators
	int setDirector(std::string);
	int setRunTime(double);
	int setSequel(Videos*);
	
	//accessors
	std::string getDirector();
	double getRunTime();
	Videos* getSequel();
	int toCout();

	//predicate
	int in_mem();
	int clear();
};

#endif