/*
** EPITECH PROJECT, 2021
** output
** File description:
** output.cpp
*/

#include "output.hpp"
#include "error.hpp"

nts::Output::Output() : Acomponent(nts::C_OUTPUT, 1)
{
}

nts::Output::~Output()
{
}

void nts::Output::simulate() 
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    (void)pin;
    if (_pin[1-1].comp == NULL)
        throw(Error("Component don't exist"));
    this->_states = _pin[1-1].comp->compute(_pin[1-1]._pin);
    return (this->_states);
}