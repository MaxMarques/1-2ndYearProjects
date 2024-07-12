/*
** EPITECH PROJECT, 2020
** OptionScene.cpp
** File description:
** OptionScene file
*/

#include "OptionScene.hpp"
#include <raylib.h>

Indie::Scenes::OptionScene::OptionScene(SceneManager &sceneManager) : AScene("OptionScene", sceneManager)
{

}

void Indie::Scenes::OptionScene::display(const Indie::Graphical::Window &win)
{
    ::ClearBackground(::GRAY);
    auto textPos = win.getPos(50, 50);
    ::DrawText("OptionScene", textPos.x, textPos.y, 30, ::BLACK);
}

void Indie::Scenes::OptionScene::update(Event event, double deltaTime, const Indie::Graphical::Window &win)
{
    AScene::update(event, deltaTime, win);
}
