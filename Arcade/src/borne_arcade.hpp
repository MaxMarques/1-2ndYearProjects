/*
** EPITECH PROJECT, 2021
** borne_arcade
** File description:
** borne_arcade.hpp
*/

#ifndef _ARCADE_
#define _ARCADE_

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include<map>
#include <string.h>
#include <vector>
#include <dirent.h>
#include "library/ILibrary.hpp"
#include "game/IGame.hpp"
#include "openlibrary.hpp"
#include "core/core.hpp"

class Arcade : public Openlibrary
{
    public:
        Arcade(const int argc, const char *argv[]);
        ~Arcade();
        void Usage(const std::string library);
        void getLib(const std::string library);
        void getGame();
    protected:
        std::unique_ptr<Openlibrary> _Openlibrary;
        std::unique_ptr<Core> _Core;
        std::map<std::string, std::shared_ptr<ILibrary>> _ILibrary;
        std::string _index_lib;
        std::map<std::string, std::shared_ptr<IGame>> _IGame;
        std::vector<std::string> _lib;
        std::vector<std::string> _game;

};

#endif