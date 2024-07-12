/*
** EPITECH PROJECT, 2020
** SceneManagerError.cpp
** File description:
** SceneManagerError function
*/

#include "SceneManagerError.hpp"

Indie::Errors::SceneManagerError::SceneManagerError(const std::string &m, const std::string &function)
    : Indie::Errors::IndieError(m, function, "SceneManager")
{

}
