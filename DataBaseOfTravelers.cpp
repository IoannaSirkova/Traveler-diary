#include "DataBaseOfTravelers.h"
#include <sstream>

Traveler* DataBaseOfTravelers::MakeTraveler(const std::string& filepath)
{
    std::vector<Destination*> destinations;
    std::ifstream user_file(filepath);
    if (!user_file)
    {
        throw std::exception("Such file doesn't exist!\n");

    }
    std::string currLine_user;
    std::getline(user_file, currLine_user);
    std::string user_name = currLine_user;


    std::getline(user_file, currLine_user);
    std::string password = currLine_user;


    getline(user_file, currLine_user);
    std::string email = currLine_user;


    while (user_file)
    {

        if (user_file.eof())
        {

            break;
        }

        getline(user_file, currLine_user);
        std::string dest = currLine_user;


        getline(user_file, currLine_user);
        std::string start_date = currLine_user;


        getline(user_file, currLine_user);
       std:: string end_date = currLine_user;


        getline(user_file, currLine_user);
        std::string rate_str = currLine_user;
        int rate = stoi(rate_str);


        getline(user_file, currLine_user);
        std::string comments = currLine_user;


        getline(user_file, currLine_user);
        std::stringstream temp(currLine_user);

        std::string photo;
        std::vector<std::string> photos;
        while (temp >> photo)
        {
            photos.push_back(photo);
        }
        Destination* destination = new Destination(dest, start_date, end_date, rate, comments, photos);
        destinations.push_back(destination);


    }
    user_file.close();
    Traveler* traveler = new Traveler(user_name, password, email, destinations);
    return traveler;

}

DataBaseOfTravelers::~DataBaseOfTravelers()
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        travelers[i]->~Traveler();
    }
    travelers.clear();
}

void  DataBaseOfTravelers::RunDataBase()
{
    std::string filepath = "DataBase.txt";
    std::ifstream file(filepath);
    if (!file)
    {
        throw std::exception("Such file doesn't exist!\n");
    }
    while (file)
    {

        if (file.eof()) break;
        std::string currLine;
        std::getline(file, currLine);
        travelers.push_back(MakeTraveler(currLine));
    }
    file.close();
}

void DataBaseOfTravelers::Print()
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        travelers[i]->Print();
    }
}