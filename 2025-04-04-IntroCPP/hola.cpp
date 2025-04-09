// This prints a comment
#include <iostream>
#include <string>

int main(void)
{
    std::string name; 
    std::cout << "Hello, whats your name?\n";
    //std::cin >> name; // lee hbasta el primer espacio
    std::getline(std::cin, name);
    std::cout << "Hello, " + name + "\n" ;

    std::cout << 3 << "\n";
    
    return 0;
}
