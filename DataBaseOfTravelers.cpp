#include "DataBaseOfTravelers.h"

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
        //std::cout << currLine << std::endl;
        travelers.push_back(MakeTraveler(currLine));
    }
    file.close();
}

bool DataBaseOfTravelers::FreeUserName(const std::string& user_name)
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (travelers[i]->GetUserName() == user_name)
            return false;
    }
    return true;
}

bool DataBaseOfTravelers::FreeEmail(const std::string& email)
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (travelers[i]->GetEmail() == email)
            return false;
    }
    return true;
}

bool DataBaseOfTravelers::SearchingForTheUser(const std::string& user_name, const std::string& password)
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (travelers[i]->GetUserName() == user_name)
        {
            if (travelers[i]->GetPassword() == password)
                return true;
        }
    }
    return false;
}

size_t DataBaseOfTravelers::IndexOfUserInTheVector(const std::string& user_name, const std::string& password)
{
    size_t size = travelers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (travelers[i]->GetUserName() == user_name)
        {
            if (travelers[i]->GetPassword() == password)
                return i;
        }
    }
    return 0;

}

void DataBaseOfTravelers::SearchingDestination(const std::string& name_destination)
{
    size_t size = travelers.size();
    int counter = 0;
    int sum = 0;

    std::vector<Destination*> all_dest_name;
    for (size_t i = 0; i < size; i++)
    {
        all_dest_name = travelers[i]->SearchDestinationByName(name_destination);
        if (all_dest_name.empty()== false)
        {
            std::cout << travelers[i]->GetUserName() << " : " << std::endl;
            for (size_t j = 0; j < all_dest_name.size(); j++)
            {
                all_dest_name[j]->SpecPrint();

                sum = sum + all_dest_name[j]->GetRate();
                counter++;
       
            }
        }
    }
    std::cout << "Avarage rate: " << sum / counter << std::endl;
}

void DataBaseOfTravelers::LogIn()
{
    std::string user_name, password;
    std::cout << "Username: ";
    std::cin >> user_name;
    std::cout << "Password: ";
    std::cin >> password;
    while(!SearchingForTheUser(user_name, password))
    {
        std::cout << "Wrong username or password!" << std::endl;
        std::cout << "Username: ";
        std::cin >> user_name;
        std::cout << "Password: ";
        std::cin >> password;
    }

    system("CLS");        //see it on Google

    size_t index = IndexOfUserInTheVector(user_name, password);

    std::cout << "Hello, " << user_name << " :)" << std::endl;
    

    char input='y';
    while (input!='n')
    {
        
        std::cout << std::endl << "1. See your destinations " << std::endl;
        std::cout << "2. Search information aboout destination " << std::endl;
        std::cout << "3. Exit " << std::endl;
        int number;
        std::cout << "Write down the number:";
        std::cin >> number;
        while (number != 1 && number != 2 && number!=3)
        {
            std::cout << "How stupid you have to be? Please enter 1, 2, 3 :)" << std::endl;
            std::cin >> number;
        }

        if (number == 1) travelers[index]->PrintAllDestination();
        else if (number==2)
        {
            std::cout << "Input the destination: ";
            std::string name_dest;
            std::cin >> name_dest;
            SearchingDestination(name_dest);
        }
        else
        {
            std::cout << "Bye, Bye!" << std::endl;
            break;
        }
        std::cout << "Do you want to go back to the menu" << std::endl;
        std::cout << "Write 'y' for yes/ 'n' for no :";
        
        std::cin >> input;
        system("CLS");

    }
    
}

void DataBaseOfTravelers::Registration()
{
    std::string user_name;
    std::cout << "Create username: ";
    std::cin >> user_name;
    bool flag = false;
    while (!flag)
    {
        if (!Traveler::ValidUserName(user_name))
        {
            std::cout << "Username is invalid" << std::endl;
            std::cout << "The username can only contain Latin letters and numbers!" << std::endl;
            std::cout << "Please enter new username: ";
        }
        else if (!FreeUserName(user_name))
        {
            std::cout << "Username is busy, please enter a new one: ";
        }
        else break;

        std::cin >> user_name;
    }

    std::cout << "Create password: ";
    std::string password;
    std::cin >> password;

    std::cout << "Please enter your email: ";
    std::string email;
    std::cin >> email;
    while (!FreeEmail(email))
    {
        std::cout << "Email is busy, please enter a new one: ";
        std::cin >> email;
    }

    Traveler* trav = new Traveler(user_name, password, email);
    travelers.push_back(trav);
    std::fstream data;
    data.open("DataBase.txt", std::ios::app);
    if (!data)
    {
        throw std::exception("Something went wrong :( \n");
    }
    data << "\n"<<user_name << ".txt \n";
    data.close();

    std::string name_file = user_name + ".txt";
    std::fstream user_data;
    user_data.open(name_file,std::ios::out);
    if (!user_data)
    {
        throw std::exception("Something went wrong :( \n");
    }
    user_data << user_name << "\n" << password << "\n" << email << "\n";
    user_data.close();

    std::cout << "You have completed your registration. Please go to the email to confirm your account ....... I'm kidding :)" << std::endl;

    LogIn();
}

void DataBaseOfTravelers::User()
{
    std::cout << "1. Sign up                   2.Sign in" << std::endl;
    std::cout << "Please select an option by entering its number: ";
    int number;
    std::cin >> number;

    while (number != 1 && number != 2)
    {
        std::cout << "How stupid you have to be? Please enter 1 or 2 :)" << std::endl;
        std::cin >> number;
    }

    if (number == 1)
    {
        system("CLS");
        Registration();
    }
    else
    {
        system("CLS");
        LogIn();
    }
  
}

