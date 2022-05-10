#include "DataBaseOfTravelers.h"
#include <sstream>

Traveler* DataBaseOfTravelers::MakeTraveler(const std::string filepath)
{
    std::ifstream file(filepath);
    if (!file)
    {
        throw std::exception("Such file doesn't exist!\n");
    }
    std::string currLine;
    std::getline(file, currLine);
    std::string user_name = currLine;

    std::getline(file, currLine);
    std::string password = currLine;
    
    std::getline(file, currLine);
    std::string email = currLine;

    std::vector<Destination*> destinations;
    Destination destination;

    while (file)
    {
        if (file.eof()) break;

        std::getline(file, currLine);
        std::string dest = currLine;

        std::getline(file, currLine);
        std::string start_date = currLine;

        std::getline(file, currLine);
        std::string end_date= currLine;

        std::getline(file, currLine);
        std::string rate_str= currLine;
        int rate = stoi(rate_str);   //checked this on Google

        std::getline(file, currLine);
        std::string comments = currLine;

        std::getline(file, currLine);
        std::stringstream temp(currLine);

        std::vector<std::string> photos;
        std::string photo;
        while (temp>>photo)
        {
            
            photos.push_back(photo);
        }
        
        Destination help(dest, start_date, end_date, rate, comments, photos);
        destination = help;
        destinations.push_back(&destination);

       
    }

    destinations[0]->Print();
    Traveler traveler(user_name, password, email, destinations);
  
    return &traveler;

}

void  DataBaseOfTravelers::RunDataBase()
{
    std::string filepath = "DataBase.txt";
    std::ifstream file(filepath);
    if (!file)
    {
        throw std::exception("Such file doesn't exist!\n");
    }
    int counter = 0;
    while (file)
    {

        if (file.eof()) break;
        std::string currLine;
        std::getline(file, currLine);
        //std::cout << currLine << std::endl;
        travelers.push_back(MakeTraveler(currLine));
        travelers[counter]->Print();
    }
}

void DataBaseOfTravelers::Print()
{
    size_t size = travelers.size();
    std::cout << size << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        travelers[i]->Print();
    }
}