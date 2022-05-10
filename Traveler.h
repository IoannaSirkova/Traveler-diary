#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include "Destination.h"

class Traveler :public Destination
{
private:
	std::string user_name;
	std::string password;
	std::string email;
	std::vector<Destination*> list_dest;

	bool ValidUserName(std::string user_name);

public:
	Traveler() = default;
	Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest);
	~Traveler();

	std::vector<Destination*> SearchDestinationByName(std::string name_destination) const;

	void PrintAllDestination();
	void AddNewDestination(Destination* new_dest);
	void AddNewDestination(std::string name, std::string start_date, std::string end_date, int rate,
		std::string comments, std::vector<std::string> photos);
	void AddNewPhotoToDestination(std::string name_dest, std::string photo);

	
};