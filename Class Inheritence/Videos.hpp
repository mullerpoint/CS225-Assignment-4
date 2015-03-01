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
	int num_alive;
	std::string director;
	double runTime;

	Videos* sequel_ptr;

	static int active;
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

	//predicate
	int in_mem();
};

#endif