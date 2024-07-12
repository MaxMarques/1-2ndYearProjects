/*
** EPITECH PROJECT, 2020
** IndieError.cpp
** File description:
** IndieError function
*/

#include "IndieError.hpp"

Indie::Errors::IndieError::IndieError(
    const std::string &message,
    const std::string &function,
    const std::string &context
)
{
    this->_context = context;
    this->_message = message;
    this->_function = function;
}

const char *Indie::Errors::IndieError::what() const noexcept
{
    return this->_message.c_str();
}

std::ostream &operator<<(std::ostream &os, const Indie::Errors::IndieError &err)
{
    os << "Error<" << err.getContext() << "> in " << err.getFunction();
    os << ": '" << err.what() << "'.";

    return os;
}

std::string Indie::Errors::IndieError::getFunction() const
{
    return this->_function;
}

std::string Indie::Errors::IndieError::getContext() const
{
    return this->_context;
}
