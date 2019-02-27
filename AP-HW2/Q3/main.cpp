#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //find
#include <iomanip>

int main() {

	std::ifstream inp{"db.txt"};
	size_t count{};
	inp >> count;

	char tempChar{};
	std::string day{};
	std::string time{};
	int customerId{}, productId{};

	bool repeatFlag{false};
	std::vector <std::string> days {}; 
	std::vector <int> productCounts {};
	std::vector <int> customerCounts {};
	std::vector <int> productItems {};
	std::vector <int> customerItems {};
	
	int index{-1};
	
	for(size_t i{}; i < count; i++)
	{
		inp >> tempChar
			>> day
			>> time	
			>> productId
			>> customerId;

	
		
		time.pop_back(); // To omit ']' at the end of time string!

		std::cout << productId  << ", " << customerId << std::endl;

		if(std::find(days.begin(), days.end(), day) != days.end())
		{
			repeatFlag = true;
		}
		else
		{
			repeatFlag = false;
			productItems = {};
			customerItems = {};
		}
		

		if(repeatFlag)
		{
			std::cout << "in if 1" << std::endl;
			
			if ( std::find(productItems.begin(), productItems.end(), productId)
				!= productItems.end())
			{
				std::cout << "repeated product" << std::endl;
			}
			else
			{
				productCounts[index]++;
				std::cout << "P: "<<  productCounts[index] << std::endl;
			}

			
			if (std::find(customerItems.begin(), customerItems.end(), customerId)
				!= customerItems.end())
			{
				std::cout << "repeated customer" << std::endl;
			}
			else
			{
				customerCounts[index]++;
				std::cout << "C: " << customerCounts[index] << std::endl;
			}
		}
		else
		{
			std::cout << "in else 1" << std::endl;
			index++;
			days.push_back(day);
			std::cout << day << std::endl;
			productCounts.push_back(1);
			customerCounts.push_back(1);
		}
		std::cout << "index: " <<  index << std::endl;
		productItems.push_back(productId);
		customerItems.push_back(customerId);
	}


	std::ofstream of{"dbnew.txt"};

	for (size_t i{}; i < days.size(); i++)
	{
		of << days[i]
		   << std::setw(3) << " "
		   << productCounts[i]
		   << std::setw(3) << " "
		   << customerCounts[i]
		   << std::endl;
	}
	return 0;
}
