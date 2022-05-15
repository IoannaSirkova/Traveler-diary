#pragma once 
#include "Destination.h"

class Traveler
{
private:
	std::string user_name;
	std::string password;                         //data members
	std::string email;
	std::vector<Destination*> list_dest;

protected:
	bool ValidUserName(std::string user_name);                //help-function
	void PrintSpecificDestination(std::string name_dest);    //help-function

public:
	Traveler() = default;
	Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest); 
	Traveler(std::string user_name, std::string password, std::string email);            //Need this type of constructor for when crate new traveler
	~Traveler();
	std::string GetUserName() const;                    
	std::string GetPassword() const;
	std::string GetEmail() const;

	std::vector<Destination*> SearchDestinationByName(std::string name_destination) const;

	void PrintAllDestination();            
	
};