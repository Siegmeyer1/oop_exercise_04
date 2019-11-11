//
// Created by anri on 08.11.2019.
//

#ifndef OOP_EXERCISE_04_PROCESS_H
#define OOP_EXERCISE_04_PROCESS_H

template<class T>
void process(std::istream& is, std::ostream& os) {
    if constexpr (has_dots<T>::value) {
        T object(is);
        printout(object, os);
        os << std::endl;
        os << area(object) << std::endl;
        os << center(object) << std::endl;
    } else if constexpr (is_figurelike_tuple<T>::value) {
        size_t s;
        os << "enter number of angles: ";
        is >> s;
        switch(s) {
            case 3: {
                vertex<double> fig[3];
                for (auto & i : fig) {
                    is >> i;
                }
                auto[a, b, c] = fig;
                auto object = std::make_tuple(a, b, c);
                printout(object, os);
                os << std::endl;
                os << area(object) << std::endl;
                os << center(object) << std::endl;
                break;
            }
            case 4: {
                vertex<double> fig[4];
                for (auto & i : fig) {
                    is >> i;
                }
                if (!is_proper_square(fig)) {
                    throw std::logic_error ("square is not squarish enouth");
                }
                auto[a, b, c, d] = fig;
                auto object = std::make_tuple(a, b, c, d);
                printout(object, os);
                os << std::endl;
                os << area(object) << std::endl;
                os << center(object) << std::endl;
                break;
            }
            case 8: {
                vertex<double> fig[8];
                for (auto & i : fig) {
                    is >> i;
                }
                auto[a, b, c, d, e, f, g, h] = fig;
                auto object = std::make_tuple(a, b, c, d, e, f, g, h);
                printout(object, os);
                os << std::endl;
                os << area(object) << std::endl;
                os << center(object) << std::endl;
                break;
            }
            default:
                throw std::logic_error("incorrect number of angles, try 3, 4 or 8");

        }


    } else {
        throw std::logic_error ("trying to process something stupid. Tuple must be like a figure");
    }
}

#endif //OOP_EXERCISE_04_PROCESS_H
