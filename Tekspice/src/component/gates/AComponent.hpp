/*
** EPITECH PROJECT, 2021
** AComponent
** File description:
** AComponent.hpp
*/

#ifndef _ACOMPONENT_
#define _ACOMPONENT_

#include "IComponent.hpp"

namespace nts
{
    class Acomponent : public IComponent
    {
        public:
            Acomponent(Type type, size_t pin);
            ~Acomponent();
            Type get_type() const final;
            nts::Tristate compute(std::size_t pin) = 0;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
            nts::Tristate get_value() override;
            void set_value(nts::Tristate) override;

        protected:
            nts::Tristate _states;
            Type _type;
            nts::Pin _pin[20];
    };
}
#endif