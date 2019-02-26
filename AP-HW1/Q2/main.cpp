#include <iostream>
#include <fstream>
#include <string>


int main(){

  std::ofstream of{"dict.txt"};
 
  std::string name{"john"};
  std::string year{"1995"};

  size_t N = name.length();

  //Number of name permutations is 2^N
  size_t statesNum{static_cast<size_t>(1 << N)};
  
  std::string name_buff[statesNum]{};

  for(size_t i{}; i<statesNum; ++i)
  {
    //If j-th bit is set, we convert it to upper case 
    std::string combination {name};
    for (size_t j{}; j < N; j++)  
      if (((i >> j) & 1) == 1) 
	combination[j] = toupper(name[j]);      
  
    //Adding current combination 
    name_buff[i] = combination;  
  }

  //Adding year to name_buff
  std::string totalPermutation[2*statesNum]{};

  for(size_t i{}; i<2*statesNum; ++i)
    if(i<statesNum)
      totalPermutation[i] = name_buff[i] + year;
    else
      totalPermutation[i] = year + name_buff[i-statesNum];
  

  //Adding to Total permutation to the dic.txt file
  for(auto str: totalPermutation)
    of << str << std::endl;

  
  return 0;
}
