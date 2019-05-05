#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void printVector (const std::vector<int>& vec);
void doubleVector (std::vector<int>& vec);
double averageCalculate (const std::vector<int>& vec);
void averageSort (std::vector<int>& vec, double avg);
void printSet (const std::set<int>& s);

int main() {
    // Part A //
    std::vector<int> vec{1, 2, 3, 4, 5, 4, 3, 2, 1};


    //// [FALSE] Only std::remove used
    //std::remove(std::begin(vec), std::end(vec), 2); // It is clear that std::remove did not erase anything!
    printVector(vec);                               // ... It just sends "2"s to the end of vector!!

    //// [TRUE] remove-erase idiom
    //auto first_to_erase{ std::remove(std::begin(vec), std::end(vec), 2) };
    //vec.erase(first_to_erase, vec.end());
    //printVector(vec); // It works correctly!

    // Part B //
    //doubleVector(vec);
    //printVector(vec);

    // Part C //
    //double avg{averageCalculate(vec)};
    //std::cout << avg << std::endl;
    //averageSort(vec, avg);
    //printVector(vec);

    // Part D //
    //std::vector<int>::iterator it;
    //std::sort(vec.begin(), vec.end());
    //it = std::unique_copy(std::begin(vec), std::end(vec), std::begin(vec), [](int a, int b){return a==b;});
    //vec.resize(std::distance(vec.begin(),it));
    //printVector(vec);

    // Part E //
    std::set<int> mySet(vec.begin(), vec.end());
    printSet(mySet);

    mySet.erase(mySet.find(4), mySet.end());
    printSet(mySet);

    return 0;
}


void doubleVector (std::vector<int>& vec) {
    static int arg{};
    if (arg < vec.size() - 1)
    {
        vec[arg++] *= 2;    // If static int arg < vec.size, double it
        doubleVector(vec);  // ... and call double function more!
    }
    else
    {
        vec[arg] *= 2;
        arg = 0;
    }
}

void printVector (const std::vector<int>& vec) {
    static int arg{};
    if (arg < vec.size() - 1)
    {
        std::cout << vec[arg++] << ", "; // If static int arg < vec.size, std::cout
        printVector(vec);                // ... and call print function more!
    }
    else
    {
        std::cout << vec[arg] << std::endl;
        arg = 0;
    }
}

double averageCalculate (const std::vector<int>& vec) {
    static int arg{};
    static double sum{};
    if (arg < vec.size() - 1)
    {
        sum += vec[arg++];          // If static int arg < vec.size, add it to sum
        averageCalculate(vec);      // ... and call averageCalculate function more!
    }
    else
    {
        sum += vec[arg];
        return sum/vec.size();
        arg = 0;
    }
}

void averageSort (std::vector<int>& vec, double avg) {
    static int i{};
    static int j{1};
    if (i < vec.size() - 1) //From first element to one before last
    {
        if (j < vec.size()) //From one after ith element to last
        {
            if (std::abs(vec[i] - avg) < std::abs(vec[j] - avg))
            {
                std::swap(vec[i], vec[j]); //Swap when it is necessary!
            }
            //std::cout << "i: " << i << ", j: " << j << std::endl;
            j++;
            averageSort(vec,avg); //Call function for j
        }
        else
        {
            j = ++i + 1;
            averageSort(vec,avg); //Call function for i
        }
    }
    else
    {
        std::cout << "The vector is sorted!" << std::endl;
        i = 0;
        j = 0;
    }
}

void printSet (const std::set<int>& s) {
    static auto arg{std::begin(s)};
    if (arg != (--std::end(s)))
    {
        std::cout << *(arg++) << ", "; // If static int arg < vec.size, std::cout
        printSet(s);                // ... and call print function more!
    }
    else
    {
        std::cout << *arg << std::endl;
        arg = s.begin();
    }
}