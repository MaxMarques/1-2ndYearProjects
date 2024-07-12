/*
** EPITECH PROJECT, 2020
** ModelError.hpp
** File description:
** ModelError header file
*/

#ifndef ModelError_H_
#define ModelError_H_

#include "IndieError.hpp"

namespace Indie::Errors {
    class ModelError : public IndieError {
        public:
            ModelError(const std::string &message, const std::string &function);
    };
}

#endif
