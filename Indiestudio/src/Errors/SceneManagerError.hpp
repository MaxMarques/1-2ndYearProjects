/*
** EPITECH PROJECT, 2020
** SceneManagerError.hpp
** File description:
** SceneManagerError header file
*/

#ifndef SceneManagerError_H_
#define SceneManagerError_H_

#include "IndieError.hpp"

namespace Indie::Errors {
    class SceneManagerError : public IndieError {
        public:
            SceneManagerError(const std::string &message, const std::string &function);
    };
}

#endif
