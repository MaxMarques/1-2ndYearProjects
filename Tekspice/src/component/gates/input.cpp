/*
** EPITECH PROJECT, 2021
** input
** File description:
** input.cpp
*/

#include "input.hpp"

nts::Input::Input() : Acomponent(nts::C_INPUT, 1)
{
    this->_states = nts::Tristate::UNDEFINED;
}

nts::Input::~Input()
{
}

void nts::Input::simulate() 
{
    this->_states = this->_temp;
}

void nts::Input::set_value(nts::Tristate value)
{
    this->_temp = value;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    (void)pin;
    return (this->_states);
}