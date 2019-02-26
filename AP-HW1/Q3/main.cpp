#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double func(double x, std::vector <double> coeff);


int main(int argc, char* argv[]){

  // Getting coefficients //
  std::vector <double> coeff;

  for(int i{}; i < argc - 1; i++)
  {
    coeff.push_back(atof(argv[i+1]));
  }


  // Printing equation //
  std::cout << "f(x) = ";
  for(size_t i{}; i < coeff.size() - 1; i++)
  {
    std::cout << coeff[i]
	      <<"x^"
	      << (coeff.size() - i - 1)
	      << " + ";
  }
  std::cout << coeff[coeff.size() - 1] << std::endl;

  // Initialization //
  double firstInGu{}, secondInGu{};
  double epsilon{};
  std::cout << "Enter 1st initial guess: ";
  std::cin >> firstInGu;
  std::cout << "Enter 2nd initial guess: ";
  std::cin >> secondInGu;
  std::cout << "Enter epsilon: ";
  std::cin >> epsilon;
  
  
  // secant method //
  double x_old{}, x_new{};
  double error{};
  int level_cnt{1};
  
  x_old = firstInGu;
  x_new = secondInGu;
  
  do
  {
    std::cout << std::setw(22) << std::setfill('=')
	      << "Level " << level_cnt
	      << std::setw(16) << std::setfill('=') << '='
	      << std::endl;

    double x_newnew{};
    
    x_newnew = (x_old * func(x_new, coeff) - x_new * func(x_old,coeff)) / (func(x_new, coeff) - func(x_old, coeff));

    x_old = x_new;
    x_new = x_newnew;

    std::cout << "x_new = " << x_new << std::endl;
    std::cout << "x_old = " << x_old << std::endl;

    std::cout << "f(x) = " << func(x_new, coeff) << std::endl;

    error = fabs((x_new - x_old) / x_old); 

    std::cout << "Error = " << error << std::endl << std::endl;

    level_cnt++;
  }while(error > epsilon);

  std::cout << std::setw(39) << std::setfill('=') << '=' << std::endl;
  std::cout << "Final answer = " << x_new << std::endl;

  return 0;
}


double func(double x, std::vector <double> coeff)
{
  double result{};
  for(size_t i{}; i < coeff.size(); i++)
  {
    result += (coeff[i]) * pow(x,(coeff.size() - i - 1));
  }
  return result;
}
