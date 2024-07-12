/*
** EPITECH PROJECT, 2021
** core_ncurses
** File description:
** core_ncurses.hpp
*/

#ifndef _NCURSES_
#define _NCURSES_

#include <iostream>
#include <ncurses.h>
#include <vector>
#include "../ILibrary.hpp"

struct Window {
    float x;
    float y;
    WINDOW *w;
    float width;
    float height;
};

class Ncurses : public ILibrary
{
    public:
        Ncurses();
        ~Ncurses();
        void init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs) override final;
        void update() override final;
        KeyEvent getKeyEvent() override final;
        void display() override final;
        bool isOpened() override final;
        void close() override final;
        void setGameMap(const std::vector<std::vector<int>> &) override final;
        std::string getName() const override final;
        void set_pos_caractere(std::vector<caractere_pos_t> pos) override final;
        void set_pos_obj(obj_pos_t pos) override final;
        void setScore(unsigned int score) override final;
        std::pair<int, int> get_position(float with, float height, WINDOW* w);
        void draw_text(int x, int y, WINDOW* w, std::string txt);
    private:
        bool _open;
        WINDOW* _window;
        std::vector<Window> _background;
        int _switch_game;
        unsigned int _score;
};

extern "C" ILibrary *create_library();
extern "C" void destroy_library(ILibrary *library);

#endif