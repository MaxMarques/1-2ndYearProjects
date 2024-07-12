/*
** EPITECH PROJECT, 2021
** system
** File description:
** system.hpp
*/

#ifndef _SYSTEM_
#define _SYSTEM_

#include "error.hpp"
#include "parsing.hpp"
#include "true.hpp"
#include "input.hpp"
#include "output.hpp"

namespace nts
{
    class System
    {
        public:
            System(const std::string &file);
            ~System();
            int system_analysis();
            void exit(const std::vector<std::string> &);
            void display(const std::vector<std::string> &);
            void input(const std::vector<std::string> &);
            void simulate(const std::vector<std::string> &);
            void loop(const std::vector<std::string> &);
            void dump(const std::vector<std::string> &);
        private:
            void nano_execution();
            std::vector<std::string> comp_name;
            bool exit_loop = false;
            std::string _buffer;
            std::vector<std::string> str_string(const std::string &str, const char delim);
            std::vector<std::string> _input;
            int _tick = 0;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
    };
}

#endif