/*
** EPITECH PROJECT, 2021
** input
** File description:
** input.hpp
*/

#ifndef _INPUT_
#define _INPUT_

#include "AComponent.hpp"

namespace nts {
    class Input : public Acomponent {
        public:
            Input();
            ~Input();
            void simulate();
            void set_value(nts::Tristate) final;
            nts::Tristate compute(std::size_t pin) final;
        private:
            nts::Tristate _temp;
    };
}

#endif