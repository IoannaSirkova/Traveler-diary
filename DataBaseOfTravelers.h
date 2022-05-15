#pragma once
#include "Traveler.h"
#include <fstream>
#include <sstream>

class DataBaseOfTravelers: public Traveler, public Destination           //Maybe without inheritance, but because we studied it I decided to use it
{
	std::vector<Traveler*> travelers;                                   //member data


	bool FreeUserName(const std::string& user_name);
	bool FreeEmail(const std::string& email);
	bool SearchingForTheUser(const std::string& user_name, const std::string& password);          //All of these are help-functions
	size_t IndexOfUserInTheVector(const std::string& user_name, const std::string& password);
	void SearchingDestination(const std::string& name_destination); 



	Traveler* MakeTraveler(const std::string& filepath);      //Helps create the database by creating a traveler
	void LogIn();                                            //User account login feature
	void Registration();                                    //Function to make new user
	
public:
	DataBaseOfTravelers() = default;                      //I'm not sure if I need a default constructor, but it doesn't hurt to have one
	~DataBaseOfTravelers();                              //Destructor because we use dynamic memory

	
	void RunDataBase();                                //Creates our database of files
	void User();                                      //Through this function the user works with the program

};