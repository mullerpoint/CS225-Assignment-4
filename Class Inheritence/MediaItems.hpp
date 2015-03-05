//
//Media Item Class declaration
//
#ifndef MEDIAITEMS_CLASS_DEF_H_
#define MEDIAITEMS_CLASS_DEF_H_

#define DEF_ELEMENTS 15

#ifndef MEDIA_DEPENDENCIES_H_
#define MEDIA_DEPENDENCIES_H_
#include "Author.hpp"
#include "Elements.hpp"
#endif

class MediaItems
{
private:

	bool hasData;

protected:
	std::string name;
	int pub_year;
	bool pub_year_def;
	Author* auth_ptr;

	double price;

	Elements element[DEF_ELEMENTS];
	int element_num;

	static int active;

public:
	MediaItems();
	virtual ~MediaItems();

	//mutators
	int setName(std::string);
	int setPubYear(int);
	int setPrice(double);
	int setElement(int, int, std::string, int);
	int setAuthor(Author*);

	//Accessors
	std::string getName();
	int getPubYear();
	bool getPubYearDef();
	Author* getAuthor();
	double getPrice();
	Elements* getElements(int=0);
	int toCout();

	//Predicate Functions
	bool isEmpty();
	int modified(bool);
	int in_mem();
	virtual int clear();
};

#endif