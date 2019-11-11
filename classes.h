#ifndef OOP_EXERCISE_04_CLASSES_H
#define OOP_EXERCISE_04_CLASSES_H

#include "vertex.h"
#include <type_traits>
#include <iostream>

template <class T>
class Triangle {
public:
    vertex<T> dots[3];
    int size = 3;
    explicit Triangle<T>(std::istream& is) {
        for (auto & dot : dots) {
            is >> dot;
        }
    }
};

template <class T>
class Square {
public:
    vertex<T> dots[4];
    int size = 4;
    explicit Square<T>(std::istream& is) {
        for (auto & dot : dots) {
            is >> dot;
        }
        if (!is_proper_square(dots)) {
            throw std::logic_error("square is not squarish enouth");
        }
    }
};

template<class T>
bool is_proper_square (vertex<T> dots[4]) {
    bool equasion1 = ((vert_length(dots[0], dots[1]) == vert_length(dots[1], dots[2])) && (vert_length(dots[2], dots[3]) == vert_length(dots[3], dots[0])) &&
                      (vert_length(dots[0], dots[1]) == vert_length(dots[3], dots[0])) );
    bool equasion2 =  (((dots[0].x - dots[1].x) * (dots[2].x - dots[1].x) + (dots[0].y - dots[1].y) * (dots[2].y - dots[1].y)) == 0);
    return equasion1 && equasion2;
}

template <class T>
class Octagon {
public:
    vertex<T> dots[8];
    int size = 8;
    explicit Octagon<T>(std::istream& is) {
        for (auto & dot : dots) {
            is >> dot;
        }
    }
};

#endif //OOP_EXERCISE_04_CLASSES_H
