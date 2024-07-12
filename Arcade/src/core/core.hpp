/*
** EPITECH PROJECT, 2021
** core
** File description:
** core.hpp
*/

#ifndef _CORE_
#define _CORE_

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include "../library/ILibrary.hpp"
#include "../game/IGame.hpp"

class Core
{
    public:
        Core(std::map<std::string, std::shared_ptr<ILibrary>> Library, const std::string index, const std::vector<std::string> choice_lib, const std::vector<std::string> choice_game, std::map<std::string, std::shared_ptr<IGame>> Game);
        ~Core();
        int loop();
    private:
        void handle_event();
        std::map<std::string, std::shared_ptr<ILibrary>> _Library;
        std::map<std::string, std::shared_ptr<IGame>> _Game;
        std::string _index_lib;
        std::vector<std::string> _index_game_vector;
        std::vector<std::string> _index_lib_vector;
        std::string _index_game;
        KeyEvent _event;
};

#endif