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

protected:
	bool ValidUserName(std::string user_name);
	void PrintSpecificDestination(std::string name_dest);

public:
	Traveler() = default;
	Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest);
	Traveler(std::string user_name, std::string password, std::string email);
	~Traveler();
	std::string GetUserName() const;
	std::string GetPassword() const;
	std::string GetEmail() const;

	std::vector<Destination*> SearchDestinationByName(std::string name_destination) const;

	void PrintAllDestination();
	
};