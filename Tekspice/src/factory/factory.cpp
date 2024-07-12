/*
** EPITECH PROJECT, 2021
** factory
** File description:
** factory.cpp
*/

#include "true.hpp"
#include "false.hpp"
#include "input.hpp"
#include "output.hpp"
#include "factory.hpp"

std::map<std::string, nts::create_t> factory {
    { "true", &nts::Factory::Create_True },
    { "output", &nts::Factory::Create_Output },
    { "false", &nts::Factory::Create_False },
    { "input", &nts::Factory::Create_Input }
};

std::unique_ptr<nts::IComponent> nts::Factory::Create_Component(const std::string &name)
{
    auto search = factory.find(name);

    if (search == factory.end())
        throw(Error("Unknow component in factory"));
    return (*search->second)();
}

std::unique_ptr<nts::IComponent> nts::Factory::Create_True()
{
    return (std::unique_ptr<nts::IComponent>(new nts::True()));
}

std::unique_ptr<nts::IComponent> nts::Factory::Create_Output()
{
    return (std::unique_ptr<nts::IComponent>(new nts::Output()));
}

std::unique_ptr<nts::IComponent> nts::Factory::Create_False()
{
    return (std::unique_ptr<nts::IComponent>(new nts::False()));
}

std::unique_ptr<nts::IComponent> nts::Factory::Create_Input()
{
    return (std::unique_ptr<nts::IComponent>(new nts::Input()));
}