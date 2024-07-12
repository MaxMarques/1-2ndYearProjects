/*
** EPITECH PROJECT, 2021
** pacman
** File description:
** pacman.hpp
*/

#include <iostream>
#include "../IGame.hpp"
#include "../../core/struct.hpp"

#ifndef _PACMAN_
#define _PACMAN_

class Pacman : public IGame
{
    public:
        Pacman();
        ~Pacman();
        void reset() override final;
        void update(double elapsedTime) override final;
        void handleEvent(KeyEvent) override final;
        unsigned int getScore() const override final;
        int getLose() const override final;
        std::vector<std::vector<int>> getMap() const override final;
        std::string getName() const override final;
        std::vector<caractere_pos_t> get_pos_caractere() override final;
        obj_pos_t get_pos_obj() override final;
};

extern "C" IGame *create_game();
extern "C" void destroy_game(IGame *library);

#endif