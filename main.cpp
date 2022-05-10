#include <iostream>
#include <vector>

#include "Destination.h"
#include "Traveler.h"
using namespace std;
int main()
{
	
	vector<string> photos;
	vector<string> photos2;
	photos.push_back( "Neshto.jpeg");
	photos.push_back("Neshtonz.png");
	photos2 = photos;
	Destination nz("Varna", "22-03-2020", "22-04-2021", 5, "Mnogo hubavo", photos);
	Destination nz1("Varna","25-04-2021","22-04-2022",5,"Mnogo hubavo",photos);
	vector<Destination*> qko;
	qko.push_back(&nz);
	qko.push_back(&nz1);

	Traveler one("ani", "123456", "nz@gmail.com", qko);
	//one.PrintAllDestination();
	one.AddNewPhotoToDestination("Varna", "novasnimka.jpeg");
	one.PrintAllDestination();


	
	
	
}