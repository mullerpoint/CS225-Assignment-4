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
	enum Genre {
		UDEF, ROC, COU, HIP, TEC, REG, OTHER
	};
	void getGenre(Genre test);

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
	std::string dispGenre(Music::Genre = Music::Genre::OTHER); // returns a string for outputting the genre 
	std::string dispGenreSht(Music::Genre = Music::Genre::OTHER); // returns a short string for searching the tokens
	const virtual int toCout();

	//predicate
	const int in_mem();
	int clear();

};

#endif