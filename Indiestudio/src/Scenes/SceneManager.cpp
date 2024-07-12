/*
** EPITECH PROJECT, 2020
** SceneManager.cpp
** File description:
** SceneManager function
*/

#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "OptionScene.hpp"
#include "SceneManager.hpp"
#include "PlaygroundScene.hpp"
#include "SceneManagerError.hpp"

#include <iostream>

void Indie::Scenes::SceneManager::changeScene(const std::string &name)
{
    for (const auto &scene : this->_scenes) {
        if (scene->getName() == name) {
            this->_currScene = scene;
            return;
        }
    }
    throw Errors::SceneManagerError("Scene doesn't exist", __func__);
}

std::shared_ptr<Indie::Scenes::IScene> Indie::Scenes::SceneManager::getCurrentScene() const
{
    return this->_currScene;
}

void Indie::Scenes::SceneManager::removeScene(const std::string &name)
{
    auto it = this->_scenes.begin();

    for (const auto &scene : this->_scenes) {
        if (scene->getName() == name) {
            it++;
        }
    }

    if (it != this->_scenes.end())
        this->_scenes.erase(it);
}
