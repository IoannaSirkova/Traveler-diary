#include "Traveler.h"

bool Traveler::ValidUserName(std::string user_name)
{
	size_t size = user_name.size();
	for (size_t i = 0; i < size; i++)
	{
		if (!((user_name[i] >= 'a' && user_name[i] <= 'z') ||
			  (user_name[i] >= 'A' && user_name[i] <= 'B') ||
			  (user_name[i] >= '0' && user_name[i] <= '9')))
			return false;
	}
	return true;

}

void Traveler::PrintSpecificDestination(std::string name_dest)
{
	size_t counter = 0;
	for (size_t i = 0; i < list_dest.size(); i++)
	{
		if (list_dest[i]->GetName()==name_dest)
		{
			std::cout << counter << ". ";
			list_dest[i]->Print();
			std::cout<< std::endl;
			counter++;
		}
	}
}

std::string Traveler::GetUserName() const
{
	return user_name;
}

std::string Traveler::GetPassword() const
{
	return password;
}

std::string Traveler::GetEmail() const
{
	return email;
}

Traveler::Traveler(std::string user_name, std::string password, std::string email, std::vector<Destination*> list_dest)
{
	if (!ValidUserName(user_name))
		throw std::exception("Please input valid username");
	this->user_name = user_name;
	this->email = email;
	this->password = password;
	this->list_dest = list_dest;
}

Traveler::Traveler(std::string user_name, std::string password, std::string email)
{
	this->user_name = user_name;
	this->email = email;
	this->password = password;
}

Traveler::~Traveler()
{
	user_name.clear();
	password.clear();
	email.clear();
	list_dest.clear();
}

std::vector<Destination*> Traveler::SearchDestinationByName(std::string name_destination) const
{
	std::vector<Destination*> all_destination_with_this_name;
	for (size_t i = 0; i < list_dest.size(); i++)
	{
		if (list_dest[i]->GetName()==name_destination)
		{
			all_destination_with_this_name.push_back(list_dest[i]);
		}
	}
	 return all_destination_with_this_name;
}

void Traveler::PrintAllDestination()
{
	size_t size = list_dest.size();
	for (size_t i = 0; i < size; i++)
	{
		list_dest[i]->Print();
		std::cout << std::endl;
	}
}

