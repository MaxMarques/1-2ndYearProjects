/*
** EPITECH PROJECT, 2021
** output
** File description:
** output.hpp
*/

#ifndef _OUTPUT_
#define _OUTPUT_

#include "AComponent.hpp"

namespace nts {
    class Output : public Acomponent {
        public:
            Output();
            ~Output();
            void simulate();
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif