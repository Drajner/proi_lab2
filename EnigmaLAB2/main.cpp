#include <iostream>
#include "Enigma.h"
#include <string>
#include <array>
#include <cstddef>

int main()
{
    Enigma enigma;
    enigma = generateMachine();
    EnigmaState state = {0,0,0,0};
    bool not_end = true;
    int input;
    std::string text;
    while (not_end)
    {
        std::cout << "In order to decrypt previously encrypted text you need to change machine state to " << std::endl;
        std::cout << "state in which encryption ended. In order to get that information you need to press 3 " << std::endl;
        std::cout << "after encryption." << std::endl;
        std::cout << "Please choose action:" << std::endl;
        std::cout << "1. Encrypt text." << std::endl;
        std::cout << "2. Decrypt text." << std::endl;
        std::cout << "3. Show machine state." << std::endl;
        std::cout << "4. Change machine state." << std::endl;
        std::cout << "5. Show numbers on cylinders." << std::endl;
        std::cout << "6. Change numbers on cylinders." << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cin >> input;
        switch (input)
        {
            case 1:
                std::cout << "Please enter text:" << std::endl;
                std::cin >> text;
                std::cout << encrypt(text,state,enigma) << std::endl;
                break;
            case 2:
                std::cout << "Please enter text:" << std::endl;
                std::cin >> text;
                std::cout << decrypt(text, state, enigma) << std::endl;
                break;
            case 3:
                std::cout << state;
                break;
            case 4:
                std::cin >> state;
                break;
            case 5:
                std::cout << enigma;
                break;
            case 6:
                std::cin >> enigma;
                break;
            case 7:
                not_end = false;
                break;
            default:
                std::cout << "Wrong input!" << std::endl;
                break;
        }


    };
    return 0;
}
