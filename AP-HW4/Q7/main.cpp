#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <iterator>
#include <set>
#include <functional>

void printVector (const std::vector<int>& vec);
void printSet (const std::set<int>& s);
void vectorRand (std::vector<int>& vec);
void setRand (std::set<int>& s);

int main() {
    // A //
    std::vector<int> a (50, 0);
    printVector(a);

    // B //
    //srand(time(nullptr));  // Initialize random number generator.
    std::vector<int> b (50, 0);
    vectorRand(b);
    printVector(b);

    // C //
    std::set<int> b2 {b.begin(), b.end()};
    printSet(b2);

    // D //
    std::set<int> c;
    setRand(c);
    printSet(c);

    // E //
    std::vector<int> c2 {c.begin(), c.end()};
    std::transform(b.begin(), b.end(), b.begin(), b.begin(), std::multiplies<>()); //b^2
    std::transform(c2.begin(), c2.end(), c2.begin(), c2.begin(), std::multiplies<>()); //(c2)^2
    std::transform(b.begin(), b.end(), c2.begin(), b.begin(), std::plus<>()); //b^2 + (c2)^2
    printVector(b);
    return 0;
}

void printVector (const std::vector<int>& vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void printSet (const std::set<int>& s) {
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void vectorRand (std::vector<int>& vec) {
    static auto arg{std::begin(vec)};
    if (arg != (std::end(vec)))
    {
        *arg = (rand()%50 + 1); // If static arg != vector.end(s), vec.push_back(rand num)
        arg++;
        vectorRand(vec);                // ... and call print function more!
    }
    else
    {
        arg = vec.begin();
    }
}

void setRand (std::set<int>& s) {
    if (s.size() < 50)
    {
        s.insert(rand()%50 + 1);
        setRand(s);                // ... and call print function more!
    }
    else
    {
    }
}
