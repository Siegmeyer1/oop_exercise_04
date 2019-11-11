#include <iostream>
#include "templates.h"
#include "vertex.h"
#include "process.h"


int main() {
    char option = '0';
    while (option != 'q') {
        std::cout << "choose option (m for man, q to quit): ";
        std::cin >> option;
        switch (option) {
            default:
                std::cout << "no such option, try m for man" << std::endl;
                break;
            case 'q':
                break;
            case 'm': {
                std::cout << "1) process triangle" << '\n'
                << "2) process square" << '\n'
                << "3) process octagon" << '\n'
                << "4) process tuple" <<  '\n'
                << "5) place for your tests" << std::endl;
                break;
            }
            case '1': {
                process<Triangle<double>>(std::cin, std::cout);
                break;
            }
            case '2': {
                process<Square<double>>(std::cin, std::cout);
                break;
            }
            case '3': {
                process<Octagon<double>>(std::cin, std::cout);
                break;
            }
            case '4': {
                process<std::tuple<vertex<double>>>(std::cin, std::cout);
                break;
            }
            case '5' : {
//====================PLACE-FOR-CUSTOM-TESTS=============================//
                auto tup = std::make_tuple(vertex<double>{0.0, 0.0},
                        vertex<int>{0, 2}, vertex<float>{2.0, 0.0});
                printout(tup, std::cout);

//=======================================================================//
                break;
            }
        }
    }

    return 0;
}