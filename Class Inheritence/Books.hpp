//
//Book Class declaration
//


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

	int setPages(int);
	int setInPrint(bool);
	int setSequel(Books*);
	int setISBN(std::string);

	int in_mem();
};

