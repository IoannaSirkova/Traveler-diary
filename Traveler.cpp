#include "Destination.h"
#include "Traveler.h"

Traveler::Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest)
{
	this->user_name = user_name;
	this->email = email;
	this->password = password;
	this->list_dest = list_dest;
}

Traveler::~Traveler()
{
	user_name.clear();
	password.clear();
	email.clear();
	list_dest.clear();
}

