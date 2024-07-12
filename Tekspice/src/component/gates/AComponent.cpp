/*
** EPITECH PROJECT, 2021
** AComponent
** File description:
** AComponent.cpp
*/

#include "error.hpp"
#include "AComponent.hpp"

nts::Acomponent::Acomponent(nts::Type type, size_t pin)
{
    (void)pin;
    this->_type = type;
}

nts::Acomponent::~Acomponent()
{

}

nts::Type nts::Acomponent::get_type() const
{
    return (this->_type);
}

void nts::Acomponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin >= 20 || pin == 0)
        throw(Error("Pin not correct"));
    _pin[pin-1].comp = &other;
    _pin[pin-1]._pin = otherPin;
}

void nts::Acomponent::dump() const
{
}

nts::Tristate nts::Acomponent::get_value()
{
    return (this->_states);
}

void nts::Acomponent::set_value(nts::Tristate value)
{
    (void)value;
}