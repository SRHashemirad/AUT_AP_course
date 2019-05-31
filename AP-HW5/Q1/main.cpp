#include <iostream>
#include <vector>
#include <iterator> //std::begin, std::end
#include <numeric> //std::iota
#include <algorithm> //std::count_if, std::sort
//#include <execution> //std::execution::par

template<typename T>
void printVec(const std::vector<T>& vec);

int main() {

    // Part 1
    std::cout << "PART 1" << std::endl;
    std::vector<int> vec1(100);
    std::vector<int> vec2(10);

    /*std::iota was used for increamenting the vector's elements
     * template <class ForwardIterator, class T>
             void iota (ForwardIterator first, ForwardIterator last, T val)
            {
                while (first!=last) {
                    *first = val;
                    ++first;
                    ++val;
                }
            }
    */
    std::iota(std::begin(vec1), std::end(vec1), 1);
    std::iota(std::begin(vec2), std::end(vec2), 1);

    printVec(vec1);
    printVec(vec2);

    // Part 2
    std::cout << "PART 2" << std::endl;
    // Appending vec1 to end of vec2
    vec2.insert(std::end(vec2), std::begin(vec1), std::end(vec1));
    printVec(vec2);

    // Part 3
    std::cout << "PART 3" << std::endl;
    // Calculate vec_odd size
    int odd_vec_size{ static_cast<int>(std::count_if(std::begin(vec1),
                                        std::end(vec1),
                                        [](const int& a) {return a % 2 == 1;})) };
    std::vector<int> odd_vec(odd_vec_size);

    // copy odd elements
    std::copy_if(std::begin(vec1), std::end(vec1), odd_vec.begin(), [](int& a) {return a%2 == 1;});
    printVec(odd_vec);

    // Part 4
    std::cout << "PART 4" << std::endl;
    std::vector<int>  reverse_vec(std::rbegin(vec1), std::rend(vec1));
    printVec(reverse_vec);

    // Part 5
    std::cout << "PART 5" << std::endl;
    // Normal sort
    std::vector<int> copy_vec {vec2};
    std::sort(std::begin(vec2), std::end(vec2));
    printVec(vec2);

    // Parallel sort
    //std::sort(std::execution::par, std::begin(copy_vec), std::end(copy_vec));
    printVec(copy_vec);
    return 0;
}


template<typename T>
void printVec(const std::vector<T>& vec)
{
    std::cout << "The vector is: " << std::endl;

    // Print vector without loop
    std::copy(std::begin(vec), std::end(vec),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}