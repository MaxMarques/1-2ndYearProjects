/*
** EPITECH PROJECT, 2021
** core_sdl
** File description:
** core_sdl.cpp
*/

#include "core_sdl.hpp"

Sdl::Sdl()
{

}

Sdl::~Sdl()
{

}

void Sdl::setGameMap(const std::vector<std::vector<int>> &)
{

}

void Sdl::set_pos_caractere(std::vector<caractere_pos_t> pos)
{
	
}

void Sdl::setScore(unsigned int score)
{
}

void Sdl::set_pos_obj(obj_pos_t pos)
{

}

std::string Sdl::getName() const
{

}

void Sdl::init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs)
{
	this->_open = true;
	IMG_Init(IMG_INIT_PNG);
	this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
	this->_Renderwindow = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);

}

void Sdl::update()
{
	SDL_RenderPresent(this->_Renderwindow);
}

KeyEvent Sdl::getKeyEvent()
{
	while(SDL_PollEvent(&this->_event)) {
		if (this->_event.type == SDL_QUIT)
			close();
	}
}

void Sdl::display()
{
	SDL_Texture *texture = IMG_LoadTexture(this->_Renderwindow, "assets/borne/arcade.jpg");
	SDL_QueryTexture(texture, NULL, NULL, 0, 0);
	SDL_RenderCopy(this->_Renderwindow, texture, NULL, 0);
	SDL_DestroyTexture(texture);
}

bool Sdl::isOpened()
{
    return(this->_open);
}

void Sdl::close()
{
	this->_open = false;
	SDL_DestroyRenderer(this->_Renderwindow);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

extern "C" ILibrary *create_library()
{
	return (new Sdl());
}

extern "C" void destroy_library(ILibrary *library)
{
	delete (library);
}