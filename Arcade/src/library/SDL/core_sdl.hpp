/*
** EPITECH PROJECT, 2021
** core_sdl
** File description:
** core_sdl.hpp
*/

#ifndef _SDL_
#define _SDL_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "../ILibrary.hpp"

class Sdl : public ILibrary
{
    public:
        Sdl();
        ~Sdl();
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
    private:
        SDL_Renderer *_Renderwindow;
        SDL_Window *_window;
        SDL_Texture *_background;
        SDL_Event _event;
        bool _open;
};

extern "C" ILibrary *create_library();
extern "C" void destroy_library(ILibrary *library);

#endif