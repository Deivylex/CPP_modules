#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 100;
        }

        std::cout << "array of char\n";
        Array<int> este(arr);
       /* for (unsigned int i = 0; i < este.size(); i++) {
            este[i] = 'a' + i;
        }*/
        std::cout << "\n array char size is " << este.size() << "\n";
        for (unsigned int i = 0; i < este.size(); i++) {
            std::cout << este[i] << " ";
        }
        std::cout << "\nArray elements: ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copyArr = arr;
        copyArr[0] = 100;
        std::cout << "Modified copyArr[0]: " << copyArr[0] << std::endl;
        std::cout << "Original arr[0]: " << arr[0] << std::endl;

        std::cout << "Attempting out-of-bounds access..." << std::endl;
        std::cout << arr[10] << std::endl; // Should throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
