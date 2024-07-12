/*
** EPITECH PROJECT, 2020
** AScene.cpp
** File description:
** AScene function
*/

#include "AScene.hpp"
#include <iostream>
#include <raylib.h>

Indie::Scenes::AScene::AScene(
    const std::string &name,
    Scenes::SceneManager &sceneManager
) : _sceneManager(sceneManager)
{
    this->_name = name;
}

std::string Indie::Scenes::AScene::getName() const
{
    return this->_name;
}

void Indie::Scenes::AScene::display(const Indie::Graphical::Window &win)
{
    (void)win;
}

void Indie::Scenes::AScene::update(Indie::Event e, double deltaTime, const Indie::Graphical::Window &win)
{
    (void)e;
    (void)win;
    this->_elapstedTimeTotal += deltaTime;
    this->_elapstedTime += deltaTime;
}
