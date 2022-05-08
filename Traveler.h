#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include "Destination.h"

class Traveler 
{
private:
	std::string user_name;
	std::string password;
	std::string email;
	std::vector<Destination*> list_dest;

public:
	Traveler() = default;
	Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest);
	~Traveler();

	Destination* SearchDestinationByName(std::string name_destination) const;
};