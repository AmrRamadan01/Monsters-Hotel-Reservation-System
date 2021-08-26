#pragma once
class rooms
{
private:
	int total_Rooms;
	int availble_rooms;
	
public:
	int night_price;
	int dryclean_price;
	int spa_price;

	int AvailableRooms();
	int ReservedRooms();
	int ReserveRoom(int n);
	int FreeRoom(int n);
};

