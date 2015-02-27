//
//Media Item Class declaration
//

#define DEF_ELEMENTS 15

class MediaItems
{
protected:
	int num_alive;
	std::string name;
	int pub_year;
	bool pub_year_def;

	double price;

	Elements element[DEF_ELEMENTS];
	int element_num;

	static int active;
	bool hasData;

public:
	MediaItems();
	~MediaItems();

	//mutators
	int setName(std::string);
	int setPubYear(int);
	int setPrice(double);
	int setElement(int, int, std::string, int);

	//Accessors
	std::string getName();
	int toCout();

	//Predicate Functions
	bool isEmpty();
	int modified(bool);
	int in_mem();
};

