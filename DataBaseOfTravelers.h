#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Traveler.h"
#include "Destination.h"
#include <fstream>
#include <sstream>

class DataBaseOfTravelers
{
	std::vector<Traveler*> travelers;
	

public:
	DataBaseOfTravelers() = default;
	Traveler* MakeTraveler(const std::string filepath);
	void RunDataBase();

	void Print();
};