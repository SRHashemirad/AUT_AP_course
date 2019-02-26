#include <iostream>

void swap(int *xp, int *yp);
void bubbleSort(int arr[], size_t n);

int main(int argc, char* argv[]){
  
  size_t N{static_cast<size_t>(argc-1)};

  // Creating input array //
  int arr[N]{};
  for(size_t i{}; i<N; i++)
    arr[i] = atoi(argv[i+1]);

  // Sorting //
  bubbleSort(arr, N);

  // Computing the result //
  int result{};
  for(size_t i{}; i<N; i+=2)
    result += arr[i] - arr[i+1];

  std::cout <<  result << std::endl;
  
  return 0;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


// A function to implement bubble sort
void bubbleSort(int arr[], size_t n) 
{ 
  bool swapped;
  for (size_t i{}; i < n-1; i++)         
  {  
    // Last i elements are already in place    
    for (size_t j{}; j < n-i-1; j++)  
      if (arr[j] < arr[j+1])
      {
	swap(&arr[j], &arr[j+1]);
	swapped = true;
      }

    //If no two elements were swapped by inner loop, then break
    if (swapped == false) 
      break; 
  }
}

