/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.cpp
*/

#include <iostream>
#include <memory>
#include "borne_arcade.hpp"

int main(const int argc, const char *argv[])
{
    auto arcade = std::make_unique<Arcade>(argc, argv);

    return (0);
}