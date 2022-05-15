#pragma once
#include <iostream>
#include <string>
#include <vector>

class Destination
{
private:
	std::string name;
	std::string start_date;
	std::string end_date;                         //data members
	int rate;
	std::string coments;
	std::vector<std::string> photos;

protected:
	void ValidDate(std::string& date);
	bool ValidDates(std::string start_date, std::string end_date);           //help-functions for validation
	bool ValidPhotos(std::vector<std::string>& photos);

public:
	Destination() = default;                                                           
	Destination(std::string name,std::string start_date, std::string end_date,         //Constructor
		int rate, std::string coments, std::vector<std::string> photos);
	~Destination();                                                                   //Destructor
	std::string GetName() const;
	int GetRate();
	bool operator== (const Destination& helper);                                      //overload operator==
	Destination& operator= (const Destination& helper);                                //overload operator= , I think didn't use it
	void SpecPrint();                                                                 //Diferent type of printing
	void Print();                                                                     //Just printing
};