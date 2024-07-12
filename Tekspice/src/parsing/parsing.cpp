/*
** EPITECH PROJECT, 2021
** parsing
** File description:
** parsing.cpp
*/

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <string>
#include "factory.hpp"
#include "parsing.hpp"
#include "system.hpp"

std::map<std::string, std::unique_ptr<nts::IComponent>> nts::Parsing::pars_file(const std::string &file)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>> components;
    std::ifstream open_file;
    std::ostringstream cpy_file;
    std::string buffer;

    if (file.substr(file.find_last_of('.') + 1) != "nts")
        throw(Error("File is not correct"));
    open_file.open(file);
    if (!open_file.is_open())
        throw(Error("Impossible to open the file"));
    cpy_file << open_file.rdbuf();
    buffer = cpy_file.str();
    if (buffer.empty())
        throw(Error("File is empty"));
    recup_input_chipset(buffer, components);
    open_file.close();
    return (components);
}

std::vector<std::string> nts::Parsing::strtok_string(const std::string &str, const char delim)
{
    std::vector<std::string> tokens;
    std::istringstream isstring(str);
    std::string string;

    while (std::getline(isstring, string, delim))
        tokens.insert(tokens.end(), string);
    return (tokens);
}

void nts::Parsing::recup_input_chipset(const std::string &buffer, std::map<std::string, std::unique_ptr<nts::IComponent>> &components)
{
    bool contenent_chipset = false;
    bool contenent_links = false;
    std::string line;
    std::istringstream buff = std::istringstream(buffer);

    while (std::getline(buff, line, '\n')) {
        if (line.empty() || line[0] == '#')
            continue;
        if (line.find(".chipsets:") != std::string::npos) {
            contenent_chipset = true;
            continue;
        }
        if (line.find(".links:") != std::string::npos) {
            contenent_chipset = false;
            contenent_links = true;
            continue;
        }
        if (contenent_chipset) {
            std::vector<std::string> buff_chipset;
            std::istringstream buf(line);
            std::string recup;
            while (std::getline(buf, recup, ' '))
                buff_chipset.insert(buff_chipset.end(), recup);
            this->_comp_name.push_back(buff_chipset.at(1));
            components.insert({ buff_chipset.at(1), nts::Factory::Create_Component(buff_chipset.at(0)) });
        }
        if (contenent_links) {
            auto s_link = strtok_string(line, ' ');
            auto first_link = strtok_string(s_link.at(0), ':');
            auto second_link = strtok_string(s_link.at(1), ':');
            auto first_c = components.find(first_link.at(0));
            auto second_c = components.find(second_link.at(0));
            if (first_c == components.end()) {
                std::string mess1 = "Unknow compoment name '";
                std::string comp = first_link.at(0);
                std::string mess2 = "'";
                std::string message = mess1 + comp + mess2;
                throw(Error(message));
            }
            if (second_c == components.end()) {
                std::string mess1 = "Unknow compoment name '";
                std::string comp = second_link.at(0);
                std::string mess2 = "'";
                std::string message = mess1 + comp + mess2;
                throw(Error(message));
            }
            first_c->second->setLink(std::stoi(first_link.at(1)), *(second_c->second.get()), std::stoi(second_link.at(1)));
            second_c->second->setLink(std::stoi(second_link.at(1)), *(first_c->second.get()), std::stoi(first_link.at(1)));
        }
    }
}

std::vector<std::string> nts::Parsing::get_comp_name() const
{
    return (this->_comp_name);
}