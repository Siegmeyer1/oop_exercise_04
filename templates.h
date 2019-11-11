#ifndef OOP_LAB4_V2_FIGURES_H
#define OOP_LAB4_V2_FIGURES_H

#include <tuple>
#include <type_traits>
#include <cassert>

#include "vertex.h"
#include "classes.h"

//==============================ASSISTANCE TEMPLATES===============================================//

template<class T, class = void>
struct has_dots : std::false_type {};

template<class T>
struct has_dots<T, std::void_t<decltype(std::declval<const T&>().dots)>> : std::true_type {};

template<class T>
struct is_figurelike_tuple : std::false_type {};

template<class Head, class... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> :
        std::conjunction<is_vertex<Head>, std::is_same<Head, Tail>...> {};


//=======================================PRINT===================================================//

template<size_t Id, class T>
void tuple_print(const T& object, std::ostream& os) {
   if constexpr (Id >= std::tuple_size<T>::value) {
   } else {
       os << std::get<Id>(object) << " ";
       tuple_print<Id + 1>(object, os);
   }
}

template <class T>
void printout(const T& object, std::ostream& os) {
    if constexpr (has_dots<T>::value) {
        for (auto dot : object.dots) {
            os << dot << " ";
        }
    } else if constexpr (is_figurelike_tuple<T>::value) {
        tuple_print<0>(object, os);
    } else {
        throw std::logic_error("ERROR! Perhaps tuple is incorrect");
    }
}

//====================================CENTER===============================================//

template<size_t Id, class T>
vertex<double> tuple_center(const T& object) {
    if constexpr (Id >= std::tuple_size<T>::value) {
        return vertex<double> {0, 0};
    } else {
        vertex<double> res = std::get<Id>(object);
        return res + tuple_center<Id+1>(object);
    }
}

template <class T>
vertex<double> center(const T& object) {
    vertex<double> res{0.0, 0.0};
    int i = 0;
    if constexpr (has_dots<T>::value) {
        for (auto dot : object.dots) {
            res += dot;
            ++i;
        }
        res /= i;
        return res;
    } else if constexpr (is_figurelike_tuple<T>::value) {
        res = tuple_center<0>(object);
        res /= std::tuple_size_v<T>;
        return res;
    } else {
        throw std::logic_error ("ERROR! Perhaps tuple is incorrect");
    }
}

//====================================AREA==============================================//

template<size_t Id, class T>
double tuple_area(const T& object) {
    if constexpr (Id >= std::tuple_size<T>::value - 1) {
        return 0.0;
    } else {
        double res = (std::get<Id>(object).x * std::get<Id+1>(object).y) -
                (std::get<Id+1>(object).x * std::get<Id>(object).y);
        return res + tuple_area<Id+1>(object);
    }
}

template <class T>
double area(const T& object) {
    double res = 0.0;
    if constexpr (has_dots<T>::value) {
        for (int i = 0; i < object.size-1; ++i) {
            res += (object.dots[i].x * object.dots[i+1].y) - (object.dots[i+1].x * object.dots[i].y);
        }
        res += (object.dots[object.size-1].x * object.dots[0].y) - (object.dots[0].x * object.dots[object.size-1].y);
        return std::abs(res) / 2;
    } else if constexpr (is_figurelike_tuple<T>::value) {
        res = tuple_area<0>(object);
        res += (std::get<std::tuple_size<T>::value - 1>(object).x * std::get<0>(object).y) - (std::get<0>(object).x * std::get<std::tuple_size<T>::value - 1>(object).y);
        return std::abs(res) / 2;
    } else {
        throw std::logic_error ("ERROR! Perhaps tuple is incorrect");
    }
}

//==================================================================//

#endif //OOP_LAB4_V2_FIGURES_H
