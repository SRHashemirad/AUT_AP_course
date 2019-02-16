#include <iostream>
#include <fstream>
#include <algorithm>    // std::max, std::min


int main(){

  size_t N{20}; //Input list size
  int input_list[N]{};

  //Input_list from file
  std::ifstream in{"input.txt"};

  for(size_t i{}; i<N; i++)
    in >> input_list[i]; 
  
  //Initialisition of gussed_list
  int gussed_list[2*N]{0};

  //Computing gussed_list
      //This list must be increasing!
      //Loop starts from second element!
  for(size_t i{0}; i<N; i++) 
  {
    if(i)
    {
      gussed_list[i] = std::max(gussed_list[i-1] + 1,
				input_list[i] - gussed_list[2*N-i-1 + 1]);
    }
    gussed_list[2*N-i-1] = input_list[i] - gussed_list[i];
  }

  std::ofstream ogussed{"gussedList.txt"};
  std::ofstream odesired{"desiredList.txt"};
  
  //Printing gussed_list
  std::cout << "gussed list:" << std::endl;
  for(auto num: gussed_list)
  {
    std::cout << num << std::endl;
    ogussed << num << std::endl;
  }

  //Initialisition of  desired_list
  int desired_list[N]{};
  
  //Computing desired_list
  for(size_t i{}; i<2*N; i+=2)
    desired_list[i/2] = gussed_list[i] + gussed_list[i+1];

  //Printing desired_list
  std::cout << "Desired list:" << std::endl;
  for(auto num: desired_list)
  {
    std::cout << num << std::endl;
    odesired << num << std::endl;
  }
  
  return 0;
}

