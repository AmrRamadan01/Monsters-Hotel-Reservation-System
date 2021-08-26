#pragma once
#include <string>
using namespace std;

class guest
{
public:
	string username;
	string id;
	int no_nights;
	int no_rooms;
	int dryclean_flag;
	int spa_flag;
	int total_cost;

	int GetCost();

};
