#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


#include "Destination.h"
#include "Traveler.h"
using namespace std;
int main()
{

    vector<string> photos;
    vector<Destination*> destinations;
    vector<Traveler*> travelers;


    ifstream file("DataBase.txt");
    if (!file)
    {
        throw exception("Such file doesn't exist!\n");

    }

    while (file)
    {

        if (file.eof()) break;
        string currLine;
        getline(file, currLine);
        ifstream user_file(currLine);
        if (!user_file)
        {
            throw exception("Such file doesn't exist!\n");

        }
        string currLine_user;
        getline(user_file, currLine_user);
        string user_name = currLine_user;
        

        getline(user_file, currLine_user);
        string password = currLine_user;
       

        getline(user_file, currLine_user);
        string email = currLine_user;
        

        while (user_file)
        {
            
            if (user_file.eof())
            {
                
                break;
            }
          
            getline(user_file, currLine_user);
            string dest = currLine_user;
            

            getline(user_file, currLine_user);
            string start_date = currLine_user;
            

            getline(user_file, currLine_user);
            string end_date = currLine_user;
            

            getline(user_file, currLine_user);
            string rate_str = currLine_user;
            int rate = stoi(rate_str);
            

            getline(user_file, currLine_user);
            string comments= currLine_user;
            

            getline(user_file, currLine_user);
            stringstream temp(currLine_user);
            
            string photo;
            while (temp>>photo)
            {
                photos.push_back(photo);
            }
          /* static*/ Destination destination(dest, start_date, end_date, rate, comments, photos);
            destinations.push_back(&destination);

          /* static*/ Traveler trav(user_name, password, email, destinations);
            travelers.push_back(&trav);
        }
        user_file.close();
    }
    file.close();
	
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << "Neshto    " << endl;
        travelers[i]->Print();
    }

    return 0;
	
}