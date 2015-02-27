//
//Book Class declaration
//


#include "MediaItems.hpp"
class Books :
	private MediaItems
{
private:
	int num_alive;
	std::string isbn;
	int pages;
	bool in_print;
	bool in_print_def;
	Books* sequel_ptr;
	Author* auth_ptr;

	static int active;
public:
	Books();
	~Books();

	int setPages(int);
	int setInPrint(bool);
	int setSequel(Books*);
	int setAuthor(Author*);
	int setISBN(std::string);

	int in_mem();
};

