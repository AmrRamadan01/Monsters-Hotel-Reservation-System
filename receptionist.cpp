#include "receptionist.h"
#include <string>
#include <iostream>
#include <fstream>



using namespace std; 

fstream database; // file handle of the client database (human or monster database) to read and write IDs

string id;

char type;



/************  functions  **************/

// prints out a greeting message 
void receptionist::greet()
{
	cout << "Welcome to the Dracula Hotel!\nMy name is Frankenstein and I'm glad to serve you today " << endl;

}

/********************************************************************************************************/

int receptionist::AskForType()
{
	cout << "For a monster account press 'm' and for a human account press 'h'\nYour answer:	";
	cin >> type;
	
	if (type == 'm')
	{
		return(1);
	}

	else if (type == 'h')
	{
		return(2);
	}
	
	else
	{
		cout << "\nSorry, your input in invalid";
		exit(0);
	}
}

/********************************************************************************************************/

// prompts the customer for ID if available
// determines if the customer is old or new
int receptionist::AskForId()
{
	cout << "\n\nMay I have your 3 - number ID please ? (press '000' if you are new to the hotel)\nYour answer is :	 ";
	cin >> id;
	
	
	/*checking the id format*/
	if (id.size() != 3)
	{
		cout << "\nSorry, your ID is not correct\n\n-police siren sound-" << endl;
		
		exit(0); //closes the program with a funny message (sadly I had no time to code a time parameter for the message to last longer:( )
	}
	
	
	/*checks if the customer is new*/
	else if(id == "000")
	{
		cout << "\nThanks for choosign our hotel, we are creating an account for you" << endl;
		return(0);
	}
	
	
	/*checks if the customer has a monster ID*/
	/*a monster ID starts with 1*/
	else if(id.substr(0,1) == "1")
	{
		cout << "\nWelcome come back Mr.Monster" << endl;
		return(1);
	}


	/*checks if the customer has a human ID*/
	/*a monster ID starts with 2*/
	else if (id.substr(0, 1) == "2")
	{
		cout << "\nWelcome come back Mr.Human" << endl;
		return(2);
	}
}

/********************************************************************************************************/

int receptionist::CreateAccount()
{
	char type;
	cout << "\n For a monster account press 'm' and for a human account press 'h'\nYour answer:		";
	cin >> type;

	if (type == 'm')
	{
		return(1);
	}

	else if (type == 'h')
	{
		return(2);
	}

	else
	{
		cout << "\nSorry, your input is invalid";
		exit(0);
	}
}


/********************************************************************************************************/

string receptionist::CreateId(int type)
{
	string new_id, last_id;
	int int_id;

	
	if (type == 1)
	{
		
		database.open("monster_database.txt", ios::in | ios::out |ios::app);
		getline(database, last_id);
		
		int_id = stoi(last_id) + 1;
		new_id = to_string(int_id);

		database >> new_id;

		database.close();

		cout << "\n Your monster Id is " << new_id << endl;
		return(new_id);
	}

	else if (type == 2)
	{
		
		database.open("humans_database.txt", ios::in | ios::out | ios::app);
		getline(database, last_id);

		int_id = stoi(last_id) + 1;
		new_id = to_string(int_id);

		database >> new_id;

		database.close();

		cout << "\n Your human Id is " << new_id << endl;
		return(new_id);
	}
}

/********************************************************************************************************/

void receptionist::SearchForId(int type, string id)
{
	string line;                                          //line object to scan the file for a matching ID
	int found_flag;                                       //a flag equal to 1 when found and 1 if not 

	if (type == 1)
	{

		database.open("monster_database.txt", ios::out); //opens monster database to read IDs
		
		while (getline(database, line))                  //loops through the file scaning for an ID match
		{
			if (id == line)
			{
				found_flag = 1;
			}
		}

		if (!found_flag)                                 //exits the program with a funny message (intruder detection)
		{
			cout << "Sorry, Your ID is not on the list\n-police siren sound-" << endl;
			exit(0);
		}
		database.close();
	}

	
	else if (type == 2)
	{

		database.open("humans_database.txt", ios::out);  //opens monster database to read IDs
		
		while (getline(database, line))                  //loops through the file scaning for an ID match
		{
			if (id == line)
			{
				found_flag = 1;
			}
		}

		if (!found_flag)                                //exits the program with a funny message (intruder detection)
		{
			cout << "Sorry, Your ID is not on the list\n-police siren sound-" << endl;
			exit(0);
		}
		
		database.close();
		
	}
}

/********************************************************************************************************/

int receptionist::AskForService()
{

	return(0);
}



void receptionist::NewReserve()
{

}


void receptionist::ExtendReserve()
{

}


void receptionist::AdditionalServe()
{

}


void receptionist::CancleReserve()
{

}


