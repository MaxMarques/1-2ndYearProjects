/*
** EPITECH PROJECT, 2021
** parsing
** File description:
** parsing.hpp
*/

#ifndef _PARSING_
#define _PARSING_


#include <vector>
#include "IComponent.hpp"
#include "error.hpp"
#include <memory>
#include <map>

namespace nts
{
    class System;
    class Parsing
    {
        public:
            std::map<std::string, std::unique_ptr<nts::IComponent>> pars_file(const std::string &file);
            std::vector<std::string> get_comp_name() const;
        private:
            void recup_input_chipset(const std::string &buffer, std::map<std::string, std::unique_ptr<nts::IComponent>> &);
            std::vector<std::string> strtok_string(const std::string &str, const char delim);
            std::vector<std::string> _comp_name;
    };
}

#endif