/*
** EPITECH PROJECT, 2021
** core
** File description:
** core.cpp
*/

#include "core.hpp"

Core::Core(std::map<std::string, std::shared_ptr<ILibrary>> Library, const std::string index, const std::vector<std::string> choice_lib, const std::vector<std::string> choice_game, std::map<std::string, std::shared_ptr<IGame>> Game)
{
    this->_Library = Library;
    this->_Game = Game;
    this->_index_lib = index;
    this->_index_game_vector = choice_game;
    this->_index_lib_vector = choice_lib;
}

Core::~Core()
{
}

int Core::loop()
{
    this->_Library[this->_index_lib]->init(this->_index_lib_vector, this->_index_game_vector);

    while (this->_Library[this->_index_lib]->isOpened())
    {
        this->_Library[this->_index_lib]->update();
        this->_Library[this->_index_lib]->display();
        this->_event = this->_Library[this->_index_lib]->getKeyEvent();
        if (this->_event == KeyEvent::EXIT)
            break;
        handle_event();
        if (this->_index_game == this->_index_game_vector.at(0)) {
            if (this->_Game[this->_index_game]->getLose() == 1) {
                this->_Game[this->_index_game]->reset();
            }
            this->_Game[this->_index_game]->handleEvent(this->_event);
            this->_Library[this->_index_lib]->set_pos_caractere(this->_Game[this->_index_game]->get_pos_caractere());
            this->_Library[this->_index_lib]->set_pos_obj(this->_Game[this->_index_game]->get_pos_obj());
            this->_Library[this->_index_lib]->setScore(this->_Game[this->_index_game]->getScore());
        }
    }
    this->_Library[this->_index_lib]->close();

    return(0);
}

void Core::handle_event()
{
    switch(this->_event) {
        case KeyEvent::LIBNCURSES:
            this->_Library[this->_index_lib]->close();
            this->_index_lib = this->_index_lib_vector.at(1);
            this->_Library[this->_index_lib]->init(this->_index_lib_vector, this->_index_game_vector);
            break;
        case KeyEvent::LIBSDL:
            this->_Library[this->_index_lib]->close();
            this->_index_lib = this->_index_lib_vector.at(2);
            this->_Library[this->_index_lib]->init(this->_index_lib_vector, this->_index_game_vector);
            break;
        case KeyEvent::LIBSFML:
            this->_Library[this->_index_lib]->close();
            this->_index_lib = this->_index_lib_vector.at(0);
            this->_Library[this->_index_lib]->init(this->_index_lib_vector, this->_index_game_vector);
            break;
        case KeyEvent::NIBBLER:
            this->_index_game = this->_index_game_vector.at(0);
            break;
        default: return;
    }
}