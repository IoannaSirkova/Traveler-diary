#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Traveler.h"
#include "Destination.h"
#include <fstream>
#include <sstream>

class DataBaseOfTravelers: public Traveler, public Destination
{
	std::vector<Traveler*> travelers;


	bool FreeUserName(const std::string& user_name);
	bool FreeEmail(const std::string& email);
	bool SearchingForTheUser(const std::string& user_name, const std::string& password);
	size_t IndexOfUserInTheVector(const std::string& user_name, const std::string& password);
	void SearchingDestination(const std::string& name_destination);



	Traveler* MakeTraveler(const std::string& filepath);
	void LogIn();
	void Registration();
	
public:
	DataBaseOfTravelers() = default;
	~DataBaseOfTravelers();

	
	void RunDataBase();
	void User();

};