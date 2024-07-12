/*
** EPITECH PROJECT, 2021
** true
** File description:
** true.cpp
*/

#include "true.hpp"

nts::True::True() : Acomponent(nts::C_TRUE, 1)
{
    this->_states = nts::Tristate::TRUE;
}

nts::True::~True()
{
}

void nts::True::simulate() 
{
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    (void)pin;
    return (this->_states);
}