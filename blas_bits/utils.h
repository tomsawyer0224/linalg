#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <cstdbool>
#include <vector>
#include <list>
#include <initializer_list>

//check whether input can be a matrix or not
template <class T>
bool isRectangle(std::vector<std::vector<T>>&);

template <class T>
bool isRectangle(std::list<std::list<T>>&);

template <class T>
bool isRectangle(std::initializer_list<std::initializer_list<T>>&);


#include "utils.hpp"
#endif
