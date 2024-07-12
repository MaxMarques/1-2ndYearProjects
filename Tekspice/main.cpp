/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include <iostream>
#include <memory>
#include <system.hpp>

int main(int ac, char *av[])
{
    if (ac != 2) {
        std::cout << "USAGE:" << std::endl;
        std::cout << "      ./nanotekspice [COMPONENT]" << std::endl;
        return (84);
    } else {
        auto nanotekspice = std::make_unique<nts::System>(av[1]);
        return (nanotekspice->system_analysis());
    }
    return (0);
}