/*
** EPITECH PROJECT, 2021
** system
** File description:
** system.cpp
*/


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <functional>
#include "system.hpp"

nts::System::System(const std::string &file)
{
    this->_buffer = file;
}

nts::System::~System()
{

}

std::vector<std::string> nts::System::str_string(const std::string &str, const char delim)
{
    std::vector<std::string> tokens;
    std::istringstream isstring(str);
    std::string string;

    while (std::getline(isstring, string, delim))
        tokens.insert(tokens.end(), string);
    return (tokens);
}

void nts::System::nano_execution()
{
    std::map<std::string, std::function<void(const std::vector<std::string> &)>> commande {
        { "exit", std::bind(&nts::System::exit, this, std::placeholders::_1) },
        { "display", std::bind(&nts::System::display, this, std::placeholders::_1) },
        { "input", std::bind(&nts::System::input, this, std::placeholders::_1) },
        { "simulate", std::bind(&nts::System::simulate, this, std::placeholders::_1) },
        { "loop", std::bind(&nts::System::loop, this, std::placeholders::_1) },
        { "dump", std::bind(&nts::System::dump, this, std::placeholders::_1) }
    };
    std::string buffer;
    std::vector<std::string> cmd;
    bool search = false;

    std::cout << "> ";
    while (std::getline(std::cin, buffer)) {
        if (buffer.empty()) {
            std::cout << "> ";
            continue;
        }
        if (buffer.find("=") != std::string::npos) {
            this->_input = str_string(buffer, '=');
            for (const auto &i : this->comp_name) {
                if (this->_input.at(0) == i) {
                    auto test = commande.find("input");
                    test->second(this->_input);
                    search = true;
                }
            }
            if (search == false)
                std::cerr << "Unknow component name" << std::endl;
            else
                search = false;
        } else {
            cmd = str_string(buffer, ' ');
            auto search = commande.find(cmd.at(0));
            if (search == commande.end())
                std::cerr << "Unknow command" << std::endl;
            else
                search->second(cmd);
            if (this->exit_loop == true) break;
        }
        std::cout << "> ";
    }
}

void nts::System::exit(const std::vector<std::string> &)
{
    this->exit_loop = true;
}

void nts::System::display(const std::vector<std::string> &)
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" <<std::endl;
    for (auto &i : this->_components) {
        if (dynamic_cast<nts::Input*>(i.second.get())) {
            if (i.second->get_value() == -1)
                std::cout << "  " << i.first << ": " << "U" << std::endl;
            else
                std::cout << "  " << i.first << ": " << i.second->get_value() << std::endl;
        }
    }
    std::cout << "output(s):" <<std::endl;
    for (auto &i : this->_components) {
        i.second->compute(0);
        if (dynamic_cast<nts::Output*>(i.second.get())) {
            if (i.second->get_value() == -1)
                std::cout << "  " << i.first << ": " << "U" << std::endl;
            else
                std::cout << "  " << i.first << ": " << i.second->get_value() << std::endl;
        }
    }
}

void nts::System::input(const std::vector<std::string> &)
{
    if (this->_input.at(1) == "0") {
        for (auto &i : this->_components) {
            if (dynamic_cast<nts::Input*>(i.second.get())) {
                i.second->set_value(nts::Tristate::FALSE);
            }
        }
    }
    else if (this->_input.at(1) == "1") {
        for (auto &i : this->_components) {
            if (dynamic_cast<nts::Input*>(i.second.get())) {
                i.second->set_value(nts::Tristate::TRUE);
            }
        }
    }
    else if (this->_input.at(1) == "U") {
        for (auto &i : this->_components) {
            if (dynamic_cast<nts::Input*>(i.second.get())) {
                i.second->set_value(nts::Tristate::UNDEFINED);
            }
        }
    }
    else
        std::cerr << "Value input incorrect" << std::endl;
}

void nts::System::simulate(const std::vector<std::string> &)
{
    this->_tick++;
    for (auto &i : this->_components)
        i.second->simulate();
}

void nts::System::loop(const std::vector<std::string> &)
{
}

void nts::System::dump(const std::vector<std::string> &)
{
}

int nts::System::system_analysis()
{
    Parsing parser;

    try
    {
        this->_components = parser.pars_file(this->_buffer);
        this->comp_name = parser.get_comp_name();
        this->nano_execution();
    }
    catch (Error &message)
    {
        std::cerr << message.what() << std::endl;
        return (84);
    }
    return(0);
}