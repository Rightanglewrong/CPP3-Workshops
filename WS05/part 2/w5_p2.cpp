// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1,	  // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book> &theCollection,
					   const Book &theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie> &theCollection,
						const Movie &theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
			  << "\" added to collection \"" << theCollection.name()
			  << "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char **argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Collection<sdds::Book> library("Bestsellers");
	size_t cnt = 0;
	if (argc == 5)
	{
		std::ifstream file(argv[1]);
		std::string book;

		if (!file) // if the file cannot be open, print a message to standard error console and  exit from application with error code "AppErrors::CannotOpenFile"
		{
			std::cerr << "ERROR: Incorrect number of arguments.\n";
			exit(AppErrors::CannotOpenFile);
		}
		// TODO: load the first 4 books from the file "argv[1]".
		// while (file) // read one line at a time, and pass it to the Book constructor
		// {
		// 	std::getline(file, book);
		// 	if (cnt < 5)
		// 	{
		// 		if (!book.empty() && book[0] != '#') // lines that start with "#" are considered comments and should be ignored
		// 		{
		// 			library += sdds::Book(book); // store each book read into the collection "library" (use the += operator)
		// 			cnt++;
		// 		}
		// 	}
		// }
		// This one up top should do the same but didnt seem to?
		for (size_t i = 0; i < 6; i++)
		{
			std::getline(file, book);
			if (file)
			{
				if (!book.empty() && book[0] != '#')
				{
					library += sdds::Book(book);
					cnt++;
				}
			}
		}
		library.setObserver(bookAddedObserver);
		// TODO: add the rest of the books from the file.
		while (file)
		{
			std::getline(file, book);
			if (!book.empty() && book[0] != '#') // lines that start with "#" are considered comments and should be ignored
			{
				library += sdds::Book(book); // store each book read into the array "library"
				cnt++;
			}
		}
		file.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from part #1) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	auto updatePrice = [&](Book &book)
	{
		if (book.country() == "US") // if the book was published in US, multiply the price with "usdToCadRate"
		{
			book.price() *= usdToCadRate; // and save the new price in the book object
		}
		else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) // if the book was published in UK between 1990 and 1999 (inclussive),
		{
			book.price() *= gbpToCadRate; // multiply the price with "gbpToCadRate" and save the new price in the book object
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from part #1): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0; i < cnt; ++i)
	{
		updatePrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	size_t cnt2 = 0;
	if (argc > 2)
	{
		// TODO: load 5 movies from the file "argv[2]".
		std::ifstream movieFile(argv[2]);
		std::string movie;

		if (!movieFile)
		{
			std::cerr << "Cant Open movie file\n";
			exit(AppErrors::CannotOpenFile);
		}
		if (movieFile)
		{
			for (size_t i = 0; i < 7; i++) // read one line at a time, and pass it to the Movie constructor
			{
				std::getline(movieFile, movie);
				if (movie[0] != '#') // lines that start with "#" are considered comments and should be ignored
				{
					movies[cnt2] = sdds::Movie(movie); // store each movie read into the array "movies"
					cnt2++;
				}
			}
		}
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2)
	{
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else
	{
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

	// TODO: The following loop can generate generate an exception
	//         write code to handle the exception
	//       If an exception occurs print a message in the following format
	//** EXCEPTION: ERROR_MESSAGE<endl>
	//         where ERROR_MESSAGE is extracted from the exception object.
	try
	{
		for (auto i = 0u; i < 10; ++i)
		{
			try
			{
				std::cout << theCollection[i];
			}
			catch (const std::exception &err)
			{
				std::cout << "** EXCEPTION: Bad index [" << i << "]. Collection has [" << i << "] items." << std::endl;
				break;
			}
		}
	}
	catch (const std::exception &err)
	{
		std::cout << "** EXCEPTION: " << err.what() << std::endl;
	}

	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3; i < argc; ++i)
	{
		// TODO: The following statement can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//** EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		try
		{
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			sp.showStatistics(std::cout);
		}
		catch (const char *err)
		{
			std::cout << "** EXCEPTION: " << err << std::endl;
		}
	}
	if (argc < 3)
	{
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie *aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n"
				  << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
