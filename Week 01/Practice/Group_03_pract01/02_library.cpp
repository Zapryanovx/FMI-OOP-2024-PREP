//#include <iostream>
//
//const int MAX_NUM_OF_BOOKS = 5;
//
//enum Genre
//{
//	Novel,
//	Historical,
//	Poetry,
//	Other
//};
//
//struct Book
//{
//	char title[50];
//	char author[50];
//	Genre genre;
//	bool isInStock;
//};
//
//struct Library
//{
//	Book books[MAX_NUM_OF_BOOKS];
//	int currentCountOfBooks = 0;
//};
//
//void readBook(Book& book)
//{
//	std::cin.getline(book.title, 50);
//	std::cin.getline(book.author, 50);
//	
//	int genreIdx = 0;
//	std::cin >> genreIdx;
//
//	switch (genreIdx)
//	{
//		case 0:
//			book.genre = Genre::Novel;
//			break;
//		case 1:
//			book.genre = Genre::Historical;
//			break;
//		case 2:
//			book.genre = Genre::Poetry;
//			break;
//		case 3:
//			book.genre = Genre::Other;
//			break;
//
//		default:
//			std::cout << "[ERROR] Invalid book genre." << std::endl;
//			break;
//	}
//
//	std::cin >> book.isInStock;
//
//}
//
//void addBookToLibrary(Library& library, const Book& book)
//{
//	//check if library is full
//	if (library.currentCountOfBooks == MAX_NUM_OF_BOOKS)
//	{
//		std::cout << "[ERROR] Library is full.";
//		return;
//	}
//
//	//if not add book
//	library.books[library.currentCountOfBooks++] = book;
//}
//
//bool compare(const char strFirst[], const char strSecond[])
//{
//	int i = 0;
//	while (strFirst[i], strSecond[i])
//	{
//		if (strFirst[i] != strSecond[i])
//		{
//			return false;
//		}
//		
//		i++;
//	}
//
//	if (strFirst[i] || strSecond[i])
//	{
//		return false;
//	}
//	return true;
//
//}
//
//void getBookByTitle(Library& library, const char *givenTitle)
//{
//	for (int i = 0; i < library.currentCountOfBooks; i++)
//	{
//		//if book is found check if in stock
//		if (compare(library.books[i].title, givenTitle))
//		{
//			if (library.books[i].isInStock)
//			{
//				library.books[i].isInStock = false;
//				return;
//			}
//
//			std::cout << "[ERROR] Book not available.";
//			return;
//		}
//	}
//
//	//if book does not exist
//	std::cout << "[ERROR] Book doesn't exist";
//}
//
//void returnBookByTitle(Library& library, const char* givenTitle)
//{
//	for (int i = 0; i < library.currentCountOfBooks; i++)
//	{
//		//if book exist return it back
//		if (compare(library.books[i].title, givenTitle))
//		{
//			library.books[i].isInStock = true;
//			return;
//		}
//	}
//
//	//if book does not exist
//	std::cout << "[ERROR] Book doesn't exist";
//}
//
//void printAllBooksInLibrary(const Library& library)
//{
//	for (int i = 0; i < library.currentCountOfBooks; i++)
//	{
//		std::cout << "Title: " << library.books[i].title << " ";
//		std::cout << "Author: " << library.books[i].author << " ";
//		
//		std::cout << "Genre: ";
//		switch (library.books[i].genre)
//		{
//			case 0:
//				std::cout << "Novel ";
//				break;
//			case 1:
//				std::cout << "Historical ";
//				break;
//			case 2:
//				std::cout << "Poetry ";
//				break;
//			case 3:
//				std::cout << "Other ";
//				break;
//		
//			default:
//				break;
//		}
//
//		std::cout << "In Stock: " << library.books[i].isInStock;
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	Book book;
//	Library library;
//	readBook(book);
//
//	addBookToLibrary(library, book);
//	printAllBooksInLibrary(library);
//
//	getBookByTitle(library, "yonkata");
//	printAllBooksInLibrary(library);
//
//	returnBookByTitle(library, "yonkata3");
//	printAllBooksInLibrary(library);
//
//	return 0;
//}