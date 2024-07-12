/*
** EPITECH PROJECT, 2020
** PlaygroundScene.hpp
** File description:
** PlaygroundScene header file
*/

#ifndef PlaygroundScene_H_
#define PlaygroundScene_H_

#include "AScene.hpp"
#include "AModel.hpp"

#include <raylib.h>

namespace Indie::Scenes {
    class PlaygroundScene : public AScene {
        public:
            PlaygroundScene(SceneManager &manager);
            ~PlaygroundScene();

            void update(Event event, double deltaTime, const Indie::Graphical::Window &win) final;
            void display(const Graphical::Window &window) final;
        private:
            std::unique_ptr<Models::IModel> _model;

            ::Camera _camera;
    };
}

#endif
