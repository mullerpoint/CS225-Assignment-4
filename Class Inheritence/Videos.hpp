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
	virtual ~Videos();

	//mutators
	int setDirector(std::string);
	virtual int setRunTime(double);
	int setSequel(Videos*);
	
	//accessors
	std::string getDirector();
	double getRunTime();
	virtual Videos* getSequel();
	virtual int toCout();

	//predicate
	int in_mem();
	virtual int clear();
};

#endif