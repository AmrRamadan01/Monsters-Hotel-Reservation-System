#pragma once
#include <string>
using namespace std;

class receptionist
{
public:
	string id;
	void greet();                           // prints out a greeting
	int  AskForType();                      // returns 1 for a monster and 2 for a human
	int  AskForId();                        // returns 0 for new customers, 1 for old monster customers, and 2 for old humans
	void SearchForId(int type, string id);  // asks for username if the ID is found and exits the program if not (inturder detection)
	int  CreateAccount();                   // exits the program if the input is invalid (inturder detection), 1 for a monster account and 2 for a human
	string AskForName();                    // asks the user for his name
	string CreateId(int type);              // creats a new unique ID and returns its value as a string
	int  AskForService();
	void NewReserve();
	void ExtendReserve();
	void CancleReserve();
	void AdditionalServe();
};

