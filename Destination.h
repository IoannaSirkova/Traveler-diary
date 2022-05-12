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

protected:
	void ValidDate(std::string& date);
	bool ValidDates(std::string start_date, std::string end_date);
	bool ValidPhotos(std::vector<std::string>& photos);

public:
	Destination() = default;
	Destination(std::string name,std::string start_date, std::string end_date,
		int rate, std::string coments, std::vector<std::string> photos);
	~Destination();
	std::string GetName() const;
	int GetRate();
	bool operator== (const Destination& helper);
	Destination operator= (const Destination& helper);
	void SpecPrint();
	void Print();
};