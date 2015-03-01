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
	int num_alive;
	std::string Producer;
	double minutes;


	/*enum class Genre {
		ROCK = 'roc', COUNTRY = 'cou', HIPHOP = 'hip', TECNO = 'tec', REGGAE = 'reg', OTHER, DEF
	};*/

	enum class Genre {
		ROC, COU, HIP, TEC, REG, OTHER, DEF
	};

	Genre musicGenre;

	static int active;

public:
	Music();
	~Music();

	//mutators
	int setProducer(std::string);
	int setMinutes(double);
	int setGenre(Genre);

	//predicate
	int in_mem();
};

#endif