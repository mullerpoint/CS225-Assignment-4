//
//Music Class declaration
//

#ifndef MUSIC_CLASS_DEF_H_
#define MUSIC_CLASS_DEF_H_

#include "MediaItems.hpp"



class Music :
	public MediaItems
{
public:
	enum class Genre {
		ROC, COU, HIP, TEC, REG, OTHER, DEF
	};
private:
	std::string Producer;
	double minutes;

	Genre musicGenre;

public:
	Music();
	~Music();

	//mutators
	int setProducer(std::string);
	int setRunTime(double);
	int setGenre(Genre);

	//Accessors
	const std::string getProducer();
	const virtual double getRunTime();
	const Music::Genre getGenre();
	const virtual int toCout();

	//predicate
	const int in_mem();
	int clear();

};

#endif