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
	int num_alive;
	std::string isbn;
	int pages;
	bool in_print;
	bool in_print_def;
	Books* sequel_ptr;
	
	static int active;
public:
	Books();
	~Books();

	//mutators
	int setPages(int);
	int setInPrint(bool);
	int setSequel(Books*);
	int setISBN(std::string);

	//predicate
	int in_mem();
};

#endif