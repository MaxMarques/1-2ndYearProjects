/*
** EPITECH PROJECT, 2021
** nibbler
** File description:
** nibbler.hpp
*/

#ifndef _NIBBLER_
#define _NIBBLER_

#include <iostream>
#include <vector>
#include "../IGame.hpp"
#include "../../core/struct.hpp"

class Nibbler : public IGame
{
    public:
        Nibbler();
        ~Nibbler();
        void reset() override final;
        void update(double elapsedTime) override final;
        void handleEvent(KeyEvent) override final;
        unsigned int getScore() const override final;
        int getLose() const override final;
        std::vector<std::vector<int>> getMap() const override final;
        std::string getName() const override final;
        std::vector<caractere_pos_t> get_pos_caractere() override final;
        obj_pos_t get_pos_obj() override final;
        void move_snake_rigth();
        void move_snake_left();
        void move_snake_up();
        void move_snake_down();
        void generate_food();

    private:
        unsigned int score;
        std::vector<std::vector<int>> map;
        std::string direction;
        int lose;

        typedef struct map_size {
            int x;
            int y;
        } map_size_t;
        map_size_t mapSize;
        std::vector<caractere_pos_t> snake_p;
        obj_pos_t applePos;
};

extern "C" IGame *create_game();
extern "C" void destroy_game(IGame *library);

#endif