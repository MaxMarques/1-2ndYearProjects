/*
** EPITECH PROJECT, 2020
** IScene.hpp
** File description:
** IScene header file
*/

#ifndef IScene_H_
#define IScene_H_

#include "Indie.hpp"
#include "Window.hpp"

#include <iostream>
#include <vector>
#include <string>

namespace Indie::Graphical {
    class Window;
}

namespace Indie::Scenes {
    class IScene {
        public:
            virtual ~IScene() = default;

            virtual void display(const Graphical::Window &window) = 0;
            virtual void update(Indie::Event event, double deltaTime, const Indie::Graphical::Window &win) = 0;

            virtual std::string getName() const = 0;
    };
}

#endif
