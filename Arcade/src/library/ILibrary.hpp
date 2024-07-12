/*
** EPITECH PROJECT, 2021
** ILibrary
** File description:
** ILibrary.hpp
*/

#ifndef _ILIBRARY_
#define _ILIBRARY_

#include "../core/enum.hpp"
#include <iostream>
#include "../core/struct.hpp"

class ILibrary
{
    public:
        virtual ~ILibrary() = default;
        virtual void init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs) = 0;
        virtual void close() = 0;
        virtual void update() = 0;
        virtual void display() = 0;
        virtual void setGameMap(const std::vector<std::vector<int>> &) = 0;
        virtual bool isOpened() = 0;
        virtual KeyEvent getKeyEvent() = 0;
        virtual std::string getName() const = 0;
        virtual void set_pos_caractere(std::vector<caractere_pos_t> pos) = 0;
        virtual void set_pos_obj(obj_pos_t pos) = 0;
        virtual void setScore(unsigned int score) = 0;
};

#endif