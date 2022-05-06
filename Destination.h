#pragma once
#include <iostream>
#include <string>
#include <vector>

class Destination
{
private:
	std::string name;
	std::string start_date;
	std::string end_date;
	int rate;
	std::string coments;
	std::vector<std::string> photos;

	void ValidDate(std::string& date);
	bool ValidDates(std::string start_date, std::string end_date);
	bool ValidPhotos(std::vector<std::string>& photos);

public:
	Destination() = default;
	Destination(std::string name, std::string start_date, std::string end_date,
		int rate, std::string coments, std::vector<std::string> photos);
	std::string GetPeriod();
	std::string GetRate();
	std::string GetComents();
	std::vector<std::string>* GetPhotos();
	bool operator== (const Destination& helper);
	Destination operator= (const Destination& helper);

	friend std::ostream& operator<<(std::ostream& os, const Destination& dt);
	//friend std::istream& operator>>(std::istream& is, Destination& dt);

	
};