#include <iostream>
#include <vector>

#include "Destination.h"
using namespace std;
int main()
{
	
	vector<string> photos;
	vector<string> photos2;
	photos.push_back( "Neshto.jpeg");
	photos.push_back("Neshtonz.png");
	photos2 = photos;
	Destination nz;
	
	//Destination nz2("Varna", "15-02-2022", "05-03-2022", 5, "Mnogo hubavo beshe", photos);

	//for (size_t i = 0; i < 6; i++)
	//{
	//	if (photos[i].find(".jpeg") == -1 && photos[i].find(".png") == -1)
	//	{
	//		cout << "nqma razshirenie" << " " << photos[i] << endl;
	//	}
	//}
	//for (size_t i = 0; i < 6; i++)
	//{
	//	size_t size_str = photos[i].size();
	//	for (size_t j = 0; j < size_str; j++)
	//	{
	//		if (!((photos[i][j] >= 'a' && photos[i][j] <= 'z')
	//			|| (photos[i][j] >= 'A' && photos[i][j] <= 'Z')
	//			|| photos[i][j] == '.' || photos[i][j] == '_'))
	//		{
	//			//cout << "Greshka" << " " <<photos[i][j]<<" " <<photos[i] << endl;
	//			throw exception("Greshka");
	//		}
	//	}
	//}

}