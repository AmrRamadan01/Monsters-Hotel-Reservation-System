#include <iostream>
#include <string>
#include "receptionist.h"
#include "monster.h"
#include "human.h"

using namespace std;

int main()
{
	receptionist receptionist; // creating a receptionist object
	int custumer_flag = 1;     // a flag indicating a new customer in the reception hall


	string id;
	int type;

/*******************   main loop   ********************/
	while (custumer_flag)
	{
		
		receptionist.greet(); // just welcoming the customer
		
	

		/*checks if the customer already has an ID or not*/
		/*if yes, looks for the id in the database (.txt file)*/
		/*if not, creats a new ID for the customer*/
			
		if (receptionist.AskForId() == 1)        //for monster customers
		{
			type = 1;
			monster monster;                     //creats a monster object
			monster.id = id;                     //inserts the ID into the object 

			receptionist.SearchForId(type,id);   //verifies if the monster cutomer has a valid ID
		}

		
		else if (receptionist.AskForId() == 2)   //for human customers
		{
			human human;                         //creats a human object
			human.id = id;                       //inserts the ID into the object 

			receptionist.SearchForId(type,id);   //verifies if the human cutomer has a valid ID
		}

		
		else                                     //for new customers
		{
			
			type = receptionist.CreateAccount(); //type is 1 for monsters and 2 for humans

			id = receptionist.CreateId(type);    //gets the freshly created string ID and prints it out to the customer
		}
		
		
		if (type == 1)                           //creats a monster object
		{
			monster Monster;
			Monster.id = id;                    //inserts the ID into the object
		}
		
		else if (type == 2)                     //creats a human object
		{
			human Human; 
			Human.id = id;                      //inserts the ID into the object 
		}

			






		/********************************* loop termination condition ***********************************/
		cout << "\n\nIs there any customers in the reception? [answer '1' if yes or '0' if not]\nYour answer	";
		cin >> custumer_flag;
	}
}


