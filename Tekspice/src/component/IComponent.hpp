/*
** EPITECH PROJECT, 221
** IComponent
** File description:
** IComponent.hpp
*/

#ifndef _ICOMPONENT_
#define _ICOMPONENT_

#include <iostream>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum Type {
        C_TRUE,
        C_OUTPUT,
        C_FALSE,
        C_INPUT
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual Type get_type() const = 0;
            virtual void set_value(nts::Tristate) = 0;
            virtual nts::Tristate get_value() = 0;
            virtual void simulate() = 0;
    };
    struct Pin {
        IComponent *comp;
        std::size_t _pin;
    };
}

#endif