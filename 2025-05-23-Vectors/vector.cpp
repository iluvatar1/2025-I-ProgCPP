#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data = {2, 3, 4, 5, 6};
    std::cout << data[0] << "\n";
    std::cout << &data[0] << "\n";

    data.push_back(10);
    std::cout << data[0] << "\n";
    std::cout << &data[0] << "\n";
    
    return 0;
}