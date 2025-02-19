#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    try {
        int value = 300;
        auto it = easyfind(numbers, value);
        std::cout << "Found " << value << " at position " << std::distance(numbers.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}