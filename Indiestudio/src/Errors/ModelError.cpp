/*
** EPITECH PROJECT, 2020
** ModelError.cpp
** File description:
** ModelError function
*/

#include "ModelError.hpp"

Indie::Errors::ModelError::ModelError(
    const std::string &message,
    const std::string &function
) : Indie::Errors::IndieError(message, function, "Model")
{

}
