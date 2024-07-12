/*
** EPITECH PROJECT, 2021
** error
** File description:
** error.cpp
*/

#include "error.hpp"

Error::Error(const std::string &message)
{
    this->_message = message;
}

Error::~Error()
{

}

const char *Error::what()
{
    return (this->_message.c_str());
}