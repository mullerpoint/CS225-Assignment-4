//
//Music Class declaration
//

#ifndef MUSIC_CLASS_DEF_H_
#define MUSIC_CLASS_DEF_H_

#include "MediaItems.hpp"
class Music :
	public MediaItems
{
private:
	std::string Producer;
	double minutes;


	/*enum class Genre {
		ROCK = 'roc', COUNTRY = 'cou', HIPHOP = 'hip', TECNO = 'tec', REGGAE = 'reg', OTHER, DEF
	};*/

	enum class Genre {
		ROC, COU, HIP, TEC, REG, OTHER, DEF
	};

	Genre musicGenre;


public:
	Music();
	~Music();

	//mutators
	int setProducer(std::string);
	int setMinutes(double);
	int setGenre(Genre);

	//Accessors
	std::string getProducer();
	double getMinutes();
	Music::Genre getGenre();
	int toCout();

	//predicate
	int in_mem();
};

#endif