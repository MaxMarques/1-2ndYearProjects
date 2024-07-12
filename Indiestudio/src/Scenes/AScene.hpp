/*
** EPITECH PROJECT, 2020
** AScene.hpp
** File description:
** AScene header file
*/

#ifndef AScene_H_
#define AScene_H_

#include "IScene.hpp"
#include "SceneManager.hpp"

#include <memory>
#include <vector>

namespace Indie::Scenes {
    class AScene : public IScene {
        public:
            AScene(const std::string &name, Scenes::SceneManager &sceneManager);

            void update(Event event, double deltaTime, const Indie::Graphical::Window &win) override;
            void display(const Graphical::Window &window) override;

            std::string getName() const final;
        protected:
            std::string _name;

            Scenes::SceneManager &_sceneManager;

            double _elapstedTimeTotal = 0;
            double _elapstedTime = 0;
    };
}

#endif
