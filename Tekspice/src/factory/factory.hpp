/*
** EPITECH PROJECT, 2021
** factory
** File description:
** factory.hpp
*/

#ifndef _FACTORY_
#define _FACTORY_

#include "error.hpp"
#include <memory>
#include <map>
#include "IComponent.hpp"

namespace nts {
    typedef std::unique_ptr<IComponent> (*create_t)();
    class Factory {
        public:
            static std::unique_ptr<IComponent> Create_Component(const std::string &name);
            static std::unique_ptr<IComponent> Create_True();
            static std::unique_ptr<IComponent> Create_Output();
            static std::unique_ptr<IComponent> Create_False();
            static std::unique_ptr<IComponent> Create_Input();
    };
}

#endif
