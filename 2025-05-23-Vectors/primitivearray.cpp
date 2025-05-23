#include <iostream>

int main()
{
    int * data = new int [5] {2, 3, 4, 5, 6};
    std::cout << data[0] << "\n";
    std::cout << &data[0] << "\n";
    delete [] data;

    data = new int [6]{2, 3, 4, 5, 6, 10};
    data[5] = 10;
    std::cout << data[0] << "\n";
    std::cout << &data[0] << "\n";

    delete [] data;

    return 0;
}