//
//Media Item Class declaration
//
#ifndef MEDIAITEMS_CLASS_DEF_H
#define MEDIAITEMS_CLASS_DEF_H

#define DEF_ELEMENTS 15

class MediaItems
{
protected:
	int num_alive;
	std::string name;
	int pub_year;
	bool pub_year_def;
	Author* auth_ptr;

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
	int setAuthor(Author*);

	//Accessors
	std::string getName();
	int toCout();

	//Predicate Functions
	bool isEmpty();
	int modified(bool);
	int in_mem();
};

#endif