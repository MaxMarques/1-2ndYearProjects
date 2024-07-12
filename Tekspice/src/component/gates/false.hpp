/*
** EPITECH PROJECT, 2021
** false
** File description:
** false.hpp
*/

#ifndef _FALSE_
#define _FALSE_

#include "AComponent.hpp"

namespace nts {
    class False : public Acomponent {
        public:
            False();
            ~False();
            void simulate();
            nts::Tristate compute(std::size_t pin) final;
    };
}

#endif