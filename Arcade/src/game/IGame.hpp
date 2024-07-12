/*
** EPITECH PROJECT, 2021
** IGame
** File description:
** IGame.hpp
*/

#include <string>
#include <vector>
#include "../core/enum.hpp"
#include "../core/struct.hpp"

#ifndef _IGAME_
#define _IGAME_

#include <vector>

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void reset() = 0;
        virtual void update(double elapsedTime) = 0;
        virtual void handleEvent(KeyEvent) = 0;
        virtual unsigned int getScore() const = 0;
        virtual int getLose() const = 0;
        virtual std::vector<std::vector<int>> getMap() const = 0;
        virtual std::string getName() const = 0;
        virtual std::vector<caractere_pos_t> get_pos_caractere() = 0;
        virtual obj_pos_t get_pos_obj() = 0;

};

#endif
