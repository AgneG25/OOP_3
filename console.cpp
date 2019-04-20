#include "console.h"

int Console::GetInteger (int a, int b) 
        {
            const int imax = std::numeric_limits<int>::max();
            int choice;
            std::cin >> choice;
            while (true)
            {
                if (choice >= a && choice <= b && choice < imax) break;
                do
                {
                    try
                    {
                        if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                    }
                    catch (...)
                    {
                            std::cin.clear();
                            std::cin.ignore(256, '\n');
                    }
                    std::cout << "Iveskite dar karta: ";
                    std::cin >> choice;
                }while(std::cin.fail());
            }
            return choice;
        }
