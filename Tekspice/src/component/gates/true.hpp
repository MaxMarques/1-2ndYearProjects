/*
** EPITECH PROJECT, 2021
** true
** File description:
** true.hpp
*/

#ifndef _TRUE_
#define _TRUE_

#include "AComponent.hpp"

namespace nts {
    class True : public Acomponent {
        public:
            True();
            ~True();
            void simulate();
            nts::Tristate compute(std::size_t pin) final;
    };
}

#endif