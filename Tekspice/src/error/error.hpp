/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.hpp
*/

#ifndef _ERROR_
#define _ERROR_

#include <iostream>

class Error
{
    public:
        Error(const std::string & = "Error not specify.");
        ~Error();
        const char *what();
    private:
        std::string _message;
};

#endif