/*
** EPITECH PROJECT, 2021
** pacman
** File description:
** pacman.cpp
*/

#include "pacman.hpp"

Pacman::Pacman()
{

}

Pacman::~Pacman()
{

}

void Pacman::reset()
{

}

void Pacman::update(double elapsedTime)
{
    (void)elapsedTime;
}

void Pacman::handleEvent(KeyEvent)
{

}

unsigned int Pacman::getScore() const
{
	return (0);
}

int Pacman::getLose() const
{
    return (0);
}

std::vector<std::vector<int>> Pacman::getMap() const
{
}

std::vector<caractere_pos_t> Pacman::get_pos_caractere()
{
}

obj_pos_t Pacman::get_pos_obj()
{
}

std::string Pacman::getName() const
{
	return ("Pacman");
}

extern "C" IGame *create_game()
{
	return (new Pacman());
}

extern "C" void destroy_game(IGame *library)
{
	delete (library);
}