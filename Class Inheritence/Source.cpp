//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gary Muller
// Spring 2015
// CS 225 Assignment 4
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files standard libraries and classes
#include <iostream> //default include
#include <string> // included to get strings to work
#include <locale> // included to get locale info for output
#include <io.h> // isatty for windows
//#include <unistd.h> // isatty  for linux
#include <iomanip> // included to make pretty output

//User Defined Class Includes
#include "Author.hpp"
#include "Elements.hpp"
#include "MediaItems.hpp"
#include "Books.hpp"
#include "Music.hpp"
#include "Videos.hpp"



//Gloabal Variables and Defines
#define OBJS_MI 30 //number of Media Items
#define OBJS_AUTH 8 //number of Authors
#define TEXT_WIDTH 20
bool done = false;

//determine if interactive or scripted
int interactive = _isatty(_fileno(stdin)); //windowns statement
//int interactive = isatty(STDIN_FILENO); //unix statement

//define global pointers for media item objects
MediaItems* Items_ptr;
int* ItemNum_ptr;
//

//define global pointers for author objects
Author* Auth_ptr;
int* AuthNum_ptr;
//

//define global locale pointer for the locale imbue functionality
std::locale* locale;
//

//Function Prototypes
void process_menu_in(char);
void print_menu();
//


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Main Declaration
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	//Create an array, of size OBJS_MI, of media items for filling with data
	//useing the global pointer we can use the item specified with 
	MediaItems Items[OBJS_MI];
	Items_ptr = &Items[0];
	int itemNum = 0;
	ItemNum_ptr = &itemNum;

	int AuthNum = 0;
	AuthNum_ptr = &AuthNum;
	Author Authors[OBJS_AUTH];
	Auth_ptr = &Authors[*AuthNum_ptr];



	//determine if interactive or scripted


	//use the imbue functionality to make the output look pretty
	std::locale mylocal("");
	locale = &mylocal;
	std::cout.imbue(*locale);

	//core program 
	std::string menu_in;
	print_menu();


	if (interactive)
	{
		while (!done)
		{
			std::cout << std::endl << "Menu [" << *ItemNum_ptr << "]: ";
			std::getline(std::cin, menu_in);
			process_menu_in(menu_in[0]);
		}
	}
	else if (!interactive)
	{
		while (!done)
		{
			std::cout << std::endl << "Menu [" << *ItemNum_ptr << "]: ";
			std::cin >> menu_in;
			process_menu_in(menu_in[0]);
		}
	}
	std::cout << std::endl << "Goodbye" << std::endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Function Declarations
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Process Menu Function
void process_menu_in(char inchar)
{
	std::cout.imbue(*locale);
	std::cout.precision(2);

	switch (toupper(inchar))
	{

	case '/':
	{
		std::string junk_line;
		std::getline(std::cin, junk_line);
	}
	break;

	// Print all objects
	case '*':
	{
		//Print out all author objects
		std::cout << std::endl << std::endl << "==== All Authors Start ====" << std::endl;
		int count = 0;
		while (count <= (OBJS_AUTH - 1))
		{
			if (!Auth_ptr[count].isEmpty());
			//isempty() returns the hasData value which is false for an object with no data and true for an object with data, hence the ! to invert the return value
			else
			{
				std::cout << std::endl << "Author [" << count << "] :" << std::endl;
				Auth_ptr[count].toCout();
			}
			count++;
		}

		std::cout << std::endl << std::endl << std::left << std::setw(TEXT_WIDTH) << "  Authors in Memory" << " : " << Auth_ptr[0].in_mem() << std::endl
			<< std::left << std::setw(TEXT_WIDTH) << "    Memory Used" << " : " << sizeof(Author)*Auth_ptr[0].in_mem() << " Bytes";

		std::cout << std::endl << "===== All Authors End =====" << std::endl;

		//Print out all Media Item Objects
		std::cout << std::endl << std::endl << "===== All Items Start =====" << std::endl;
		count = 0;
		while (count <= (OBJS_MI - 1))
		{
			if (!Items_ptr[count].isEmpty());
			//isempty() returns the hasData value which is false for an object with no data and true for an object with data, hence the ! to invert the return value
			else //if (Items_ptr[count].isEmpty() == true)
			{
				std::cout << std::endl << "Item [" << count << "]" << std::endl;
				Items_ptr[count].toCout();
			}
			count++;
		}

		std::cout << std::endl << std::endl << std::left << std::setw(TEXT_WIDTH) << "  Items in Memory" << " : " << Items_ptr[0].in_mem() << std::endl
			<< std::left << std::setw(TEXT_WIDTH) << "    Memory Used" << " : " << sizeof(MediaItems)*Items_ptr[0].in_mem() << " Bytes";

		std::cout << std::endl << "====== All Items End ======" << std::endl;

		std::cout << std::endl << std::left << std::setw(TEXT_WIDTH) << "  Total Memory Used" << " : " << (sizeof(MediaItems)*Items_ptr[0].in_mem()) + (sizeof(Author)*Auth_ptr[0].in_mem()) << " Bytes";
	}
	break;

	//increase item number by 1
	case '+':
	{
		if (*ItemNum_ptr < (OBJS_MI - 1))
		{
			*ItemNum_ptr = *ItemNum_ptr + 1;
		}
		else if (*ItemNum_ptr >= (OBJS_MI - 1))
		{
			*ItemNum_ptr = (OBJS_MI - 1);
		}
		std::cout << std::endl;
	}
	break;

	//decrease item number by 1
	case '-':
	{
		if (*ItemNum_ptr > 0)
		{
			*ItemNum_ptr = *ItemNum_ptr - 1;
		}
		else if (*ItemNum_ptr <= 0)
		{
			*ItemNum_ptr = 0;
		}
		std::cout << std::endl;
	}
	break;

	// set a custom item number between 0-OBJS_MI
	case '#':
	{
		//declare temp vaiable and read in user value
		int new_itemNum;
		std::cout << "Enter new item number : ";
		std::cin >> new_itemNum;

		//validate input
		if ((new_itemNum >= 0) && (new_itemNum <= (OBJS_MI - 1)))
		{
			*ItemNum_ptr = new_itemNum;
		}
		else{
			std::cout << "Please enter a valid number beteen 0-" << OBJS_MI;
		}

		//clear buffer for next input
		std::cin.ignore(10000, '\n');
		std::cout << std::endl;
	}
	break;

	// clear item menu option
	case '0':
	{
		Items_ptr[*ItemNum_ptr] = MediaItems();
	}
	break;

	// display item menu option
	case 'D':
	{
		std::cout << std::endl << "Item [" << *ItemNum_ptr << "] :" << std::endl;
		Items_ptr[*ItemNum_ptr].toCout();
	}
	break;

	// enter item name menu option
	case 'N':
	{
		std::string new_name;
		std::cout << "Enter Media Item Title : ";
		std::getline(std::cin, new_name);
		Items_ptr[*ItemNum_ptr].setName(new_name);
	}
	break;

	//Create an author object
	case 'C':
	{
		int born, died;
		std::string name;

		if (interactive)
		{
			std::cout << "Please enter the Authors name :";
			std::getline(std::cin, name);
			Auth_ptr[*AuthNum_ptr].setName(name);


			std::cout << "Please enter the Authors birth year (yyyy), Zero(0) for none :";
			std::cin >> born;
			Auth_ptr[*AuthNum_ptr].setBirth(born);
			std::cin.ignore(10000, '\n');

			std::cout << "Please enter the Authors death year (yyyy), Zero(0) for none :";
			std::cin >> died;
			Auth_ptr[*AuthNum_ptr].setDeath(died);
			std::cin.ignore(10000, '\n');

			*AuthNum_ptr = *AuthNum_ptr + 1;
		}
		else //scripted
		{
			std::cin >> Auth_ptr[*AuthNum_ptr];
			//std::cin.ignore(256, '\n');

			*AuthNum_ptr = *AuthNum_ptr + 1;
		}
	}
	break;

	// enter item page count menu option
	case 'P':
	{
		int new_pages;
		std::cout << "Enter Media Item Pages : ";
		std::cin >> new_pages;
		Items_ptr[*ItemNum_ptr].setPages(new_pages);
		std::cin.ignore(10000, '\n');
	}
	break;

	// set the item in print status
	case 'I':
	{
		bool printStatus;
		std::cout << "Is the book still in print (0/1) : ";
		std::cin >> printStatus;
		std::cin.ignore(10000, '\n');
		Items_ptr[*ItemNum_ptr].setInPrint(printStatus);
	}
	break;

	// set the item value ($)
	case 'V':
	{
		double new_price;
		std::cout << "Enter Media Item value : ";
		std::cin >> new_price;
		std::cin.ignore(10000, '\n');
		Items_ptr[*ItemNum_ptr].setPrice(new_price);
	}
	break;

	// set the item publication year
	case 'Y':
	{
		int new_year;
		std::cout << "Enter Media Item publication year : ";
		std::cin >> new_year;
		std::cin.ignore(10000, '\n');
		Items_ptr[*ItemNum_ptr].setPubYear(new_year);
	}
	break;

	//Create an element object in the media item object
	case 'E':
	{
		int num, start, end;
		std::string name;

		if (interactive)
		{
			std::cout << "Please enter the Element name : ";
			std::getline(std::cin, name);

			std::cout << "Please enter the Element start, Zero(0) for none : ";
			std::cin >> start;
			std::cin.ignore(1, '\n');

			std::cout << "Please enter the Element end, Zero(0) for none : ";
			std::cin >> end;
			std::cin.ignore(1, '\n');

		}
		else //scripted
		{
			std::cin >> start;
			std::cin.ignore(1, '\n');

			std::cin >> end;
			std::cin.ignore(1, '\n');

			std::getline(std::cin, name);
			Auth_ptr[*AuthNum_ptr].setName(name);
		}


		Items_ptr[*ItemNum_ptr].setElement(start, end, name, num = 0);

	}
	break;

	//Set author pointer
	case 'T':
	{
		int temp_num;
		std::cout << "Enter Author index number : ";
		std::cin >> temp_num;
		std::cin.ignore(1, '\n');
		Items_ptr[*ItemNum_ptr].setAuthor(&Auth_ptr[temp_num]);
	}
	break;

	//Set Sequel index
	case 'S':
	{
		int temp_num;
		std::cout << "Enter Sequel index number : ";
		std::cin >> temp_num;
		std::cin.ignore(1, '\n');
		Items_ptr[*ItemNum_ptr].setSequel(&Items_ptr[temp_num]);
	}
	break;

	// display menu again menu option
	case 'M':
		print_menu();
		break;

		// quit program menu option
	case 'Q':
		done = true;
		break;

		// show memory useage
	case 'R':
	{
		std::cout
			<< std::left << std::setw(28) << "Memory Used for Authors" << " : " << sizeof(Author)*Auth_ptr[0].in_mem() << " Bytes"
			<< std::endl << std::left << std::setw(28) << "Memory Used for Media Items" << " : " << sizeof(MediaItems)*Items_ptr[0].in_mem() << " Bytes"
			<< std::endl << std::left << std::setw(28) << "Memory Used for Book Items" << " : " << sizeof(Books)*Items_ptr[0].in_mem() << " Bytes"
			<< std::endl << std::left << std::setw(28) << "Memory Used for Music Items" << " : " << sizeof(Music)*Items_ptr[0].in_mem() << " Bytes"
			<< std::endl << std::left << std::setw(28) << "Memory Used for Video Items" << " : " << sizeof(Videos)*Items_ptr[0].in_mem() << " Bytes"
			<< std::endl << std::left << std::setw(28) << "  Total Memory Used" << " : " << 
			(sizeof(MediaItems)*Items_ptr[0].in_mem()) + (sizeof(Author)*Auth_ptr[0].in_mem() + 
			sizeof(Books)*Items_ptr[0].in_mem() + sizeof(Music)*Items_ptr[0].in_mem() + sizeof(Videos)*Items_ptr[0].in_mem()) << " Bytes";

	}
	break;

	// default option if wrong key entered
	default:
		std::cout << "Please select an option from the menu" << std::endl << "to see the menu again type 'm'";
		break;
	}
}

//Print Menu Function
void print_menu()
{
	std::cout << std::endl
		<< "* - Display all media items data" << std::endl
		<< "+/- increment / decrement the select item w/in the Array" << std::endl
		<< "# - set the selected media item" << std::endl
		<< "0 - Clear Media Item Data" << std::endl
		<< "C - Create New Author Item" << std::endl
		<< "D - Display Media Item Data" << std::endl
		<< "N - Set Media Item Name" << std::endl
		<< "T - Set Author Index Number" << std::endl
		<< "E - Add Media Item Element" << std::endl
		<< "P - Set Media Item Pages" << std::endl
		<< "I - set in print status" << std::endl
		<< "V - set item Value/Price" << std::endl
		<< "Y - set Year Produced" << std::endl
		<< "M - Print this Menu" << std::endl
		<< "Q - Quit this program" << std::endl << std::endl;
}