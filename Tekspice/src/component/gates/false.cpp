/*
** EPITECH PROJECT, 2021
** false
** File description:
** false.cpp
*/

#include "false.hpp"

nts::False::False() : Acomponent(nts::C_FALSE, 1)
{
    this->_states = nts::Tristate::FALSE;
}

nts::False::~False()
{
}

void nts::False::simulate() 
{
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    (void)pin;
    return (this->_states);
}