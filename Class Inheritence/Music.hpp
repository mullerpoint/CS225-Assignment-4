//
//Music Class declaration
//

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

	int setProducer(std::string);
	int setMinutes(double);
	int setGenre(Genre);

	int in_mem();
};

