#include "Destination.h"

void Destination::ValidDate(std::string& date)
{
	if (date[1] == '-')
	{
		date.insert(0, "0");
	}
	if (date[4] == '-')
	{
		date.insert(3, "0");
	}

}

bool Destination::ValidDates(std::string start_date, std::string end_date)
{
	ValidDate(start_date);
	ValidDate(end_date);

	int st_d = int(start_date[0] - '0') * 10 + int(start_date[1] - '0');
	int st_m = int(start_date[3] - '0') * 10 + int(start_date[4] - '0');
	int st_y = int(start_date[6] - '0') * 1000 + int(start_date[7] - '0') * 100 + int(start_date[8] - '0') * 10
		+ int(start_date[9] - '0');
	
	int end_d = int(end_date[0] - '0') * 10 + int(end_date[1] - '0');
	int end_m = int(end_date[3] - '0') * 10 + int(end_date[4] - '0');
	int end_y = int(end_date[6] - '0') * 1000 + int(end_date[7] - '0') * 100 + int(end_date[8] - '0') * 10
		+ int(end_date[9] - '0');

	if (st_m > 12 && st_m < 1) return false;
	if (end_m > 12 && end_m < 1) return false;
	if (st_m == 2)
	{
		if (st_d > 29) return false;
		if (st_d == 29)
		{
			if (!(st_y % 4 == 0 && st_y % 400 == 0))
				return false;
		}
	}
	else
	{
		if (st_d > 31) return false;
		if (st_d == 31 && (st_m == 4 || st_m == 6 || st_m == 9 || st_m == 11)) return false;
	}

	if (end_m == 2)
	{
		if (end_d > 29) return false;
		if (end_d == 29)
		{
			if (!(end_y % 4 == 0 && end_y % 400 == 0))
				return false;
		}
	}
	else
	{
		if (end_d > 31) return false;
		if (end_d == 31 && (end_m == 4 || end_m == 6 || end_m == 9 || end_m == 11)) return false;
	}

	if (st_y > end_y) return false;

	if (st_y == end_y)
	{
		if (st_m == end_m)
		{
			if (st_d > end_d)
				return false;
		}
		else if (st_m > end_m) return false;
	}	
	
	return true;

}

bool Destination::ValidPhotos(std::vector<std::string>& photos)
{
	size_t size = photos.size();
	for (size_t i = 0; i < size; i++)
	{
		if (photos[i].find(".jpeg") == -1 && photos[i].find(".png") == -1)
			return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		size_t size_str = photos[i].size();
		for (size_t j = 0; j < size_str; j++)
		{
			if (!((photos[i][j] >= 'a' && photos[i][j] <= 'z')
				|| (photos[i][j] >= 'A' && photos[i][j] <= 'Z')
				|| photos[i][j] == '.' || photos[i][j] == '_'))
				return false;
		}
	}
	return true;
}

Destination::Destination(std::string name,std::string start_date, std::string end_date,
	int rate, std::string coments, std::vector<std::string> photos)
{
	this->name = name;
	
	if (!ValidDates(start_date, end_date))
		throw std::exception("Invalid dates");
	this->start_date = start_date;
	this->end_date = end_date;
	
	if (rate < 1 && rate>5)
		throw std::exception("Please input rate between 1 and 5");
	this->rate = rate;
	this->coments = coments;

	if (!ValidPhotos(photos))
		throw std::exception("There is some problem with the photos!");
	this->photos = photos;
}

Destination::~Destination()
{
	name.clear();
	start_date.clear();
	end_date.clear();
	rate = 0;
	coments.clear();
	photos.clear();
}

std::string Destination::GetName() const
{
	return this->name;
}

int Destination::GetRate()
{
	return rate;
}

bool Destination::operator==(const Destination& helper)
{
	if (name == helper.name && start_date == helper.start_date &&
		end_date == helper.end_date && rate == helper.rate &&
		coments == helper.coments && photos == helper.photos)
		return 1;
	return 0;
}

Destination Destination::operator=(const Destination& helper)
{
	if (this == &helper)
		return *this;

	name = helper.name;
	start_date = helper.start_date;
	end_date = helper.end_date;
	rate = helper.rate;
	coments = helper.coments;
	photos = helper.photos;
	return *this;

}

void Destination::SpecPrint()
{
	std::cout <<"Period: "<< start_date << ' ' << end_date << std::endl<<"Rate: " <<rate << std::endl <<"Comments: "<<coments << std::endl;
	std::cout <<"Photos: "<< photos[0];
	for (size_t i = 1; i < photos.size(); i++)
	{
		std::cout << ',' << photos[i];
	}
	std::cout << std::endl;

}



void Destination::Print()
{
	std::cout<< name << std::endl << start_date << std::endl << end_date << std::endl << rate << std::endl << coments << std::endl << photos[0];
	for (size_t i = 1; i < photos.size(); i++)
	{
		std::cout << ' ' << photos[i];
	}
	std::cout << std::endl;
}
