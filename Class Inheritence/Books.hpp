//
//Book Class declaration
//

#ifndef BOOKS_CLASS_DEF_H_
#define BOOKS_CLASS_DEF_H_

#include "MediaItems.hpp"
class Books :
	public MediaItems
{
private:
	std::string isbn;
	int pages;
	bool in_print;
	bool in_print_def;
	Books* sequel_ptr;

	
public:
	Books();
	virtual ~Books();

	//mutators
	int setPages(int);
	int setInPrint(bool);
	int setSequel(Books*);
	int setISBN(std::string);

	//Accessors
	int getPages();
	bool getInPrint();
	bool getInPrintDef();
	virtual Books* getSequel();
	std::string getISBN();
	virtual int toCout();

	//predicate
	int in_mem();
	virtual int clear();
};

#endif