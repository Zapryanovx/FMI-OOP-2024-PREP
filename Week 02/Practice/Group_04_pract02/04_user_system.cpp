//#include <iostream>
//#include <fstream>
//
//namespace MAX_SIZE_CONSTANTS
//{
//	const int MAX_SIZE_STR = 128;
//	const int MAX_SIZE_USERS = 100;
//
//}
//
//
//struct User
//{
//	char name[MAX_SIZE_CONSTANTS::MAX_SIZE_STR];
//	char email[MAX_SIZE_CONSTANTS::MAX_SIZE_STR];
//	char password[MAX_SIZE_CONSTANTS::MAX_SIZE_STR];
//};
//
//struct System
//{
//	User users[MAX_SIZE_CONSTANTS::MAX_SIZE_USERS];
//	int currUsersSize = 0;
//};
//
//void readUserFromFile(std::ifstream& fileInUser, User& user)
//{
//	fileInUser >> user.name;
//	fileInUser >> user.email;
//	fileInUser >> user.password;
//}
//
//void saveUserInFile(std::ofstream& fileOutUser, User& user)
//{
//	fileOutUser << user.name << " ";
//	fileOutUser << user.email << " ";
//	fileOutUser << user.password << std::endl;
//}
//
//void readSystemFromFile(std::ifstream& fileInSystem, System& system)
//{
//	while (!fileInSystem.eof())
//	{
//		readUserFromFile(fileInSystem, system.users[system.currUsersSize++]);
//	}
//}
//
//void saveSystemInFile(std::ofstream& fileOutSystem, System& system)
//{
//	for(int i = 0; i < system.currUsersSize; i++)
//	{
//		saveUserInFile(fileOutSystem, system.users[i]);
//	}
//}
//
//int main()
//{
//	User user;
//	std::ifstream fileInUser("04_user.txt");
//	readUserFromFile(fileInUser, user);
//	fileInUser.close();
//
//	std::ofstream fileOutUser("04_user.txt");
//	saveUserInFile(fileOutUser, user);
//	fileOutUser.close();
//
//	System system;
//	std::ifstream fileInSystem("04_system.txt");
//	readSystemFromFile(fileInSystem, system);
//	fileInSystem.close();
//
//	std::ofstream fileOutSystem("04_system.txt");
//	saveSystemInFile(fileOutSystem, system);
//	fileOutSystem.close();
//
//	return 0;
//}