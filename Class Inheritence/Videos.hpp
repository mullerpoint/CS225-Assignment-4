//
//Video Class declaration
//

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

	int setDirector(std::string);
	int setRunTime(double);
	int setSequel(Videos*);
	
	int in_mem();
};

