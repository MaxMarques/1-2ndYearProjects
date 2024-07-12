/*
** EPITECH PROJECT, 2021
** borne_arcade
** File description:
** borne_arcade.cpp
*/

#include "borne_arcade.hpp"

Arcade::Arcade(const int argc, const char *argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
        return;
    }
    auto lib = std::string(strdup(argv[1]));

    getLib(lib);
    getGame();
    this->_Core = std::make_unique<Core>(this->_ILibrary, this->_index_lib, this->_lib, this->_game, this->_IGame);
    this->_Core->loop();
}

Arcade::~Arcade()
{
}

void Arcade::Usage(const std::string library)
{
    std::cout << "USAGE:" << std::endl << "      " << library << " [lib/.so]" << std::endl << "You must enter at least one library .so in folder lib/" << std::endl;
}

void Arcade::getLib(const std::string library)
{
    this->_lib = { "arcade_sfml.so", "arcade_ncurses.so", "arcade_sdl2.so" };
    
    for (const auto &i : this->_lib) {
        if (library.compare("lib/" + i) == 0)
            this->_index_lib = i;
        auto uni_lib = this->_Openlibrary->LoadLib("./lib/" + i);
        auto create_lib = this->_Openlibrary->getLib(uni_lib, "create_library");
        std::shared_ptr<ILibrary> final_lib(((ILibrary *(*)())create_lib)());
        this->_ILibrary.insert({i, final_lib});
    }
}

void Arcade::getGame()
{
    this->_game = { "arcade_nibbler.so", "arcade_pacman.so" };
    
    for (const auto &i : this->_game) {
        auto uni_game = this->_Openlibrary->LoadLib("./lib/" + i);
        auto create_g = this->_Openlibrary->getLib(uni_game, "create_game");
        std::shared_ptr<IGame> final_game(((IGame *(*)())create_g)());
        this->_IGame.insert({ i, final_game});
    }
}