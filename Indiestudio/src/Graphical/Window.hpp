/*
** EPITECH PROJECT, 2020
** Window.hpp
** File description:
** Window header file
*/

#ifndef Window_H_
#define Window_H_

#include "Indie.hpp"
#include "IScene.hpp"

#include <memory>
#include <map>
#include <vector>
#include <string>

namespace Indie::Scenes {
    class IScene;
}

namespace Indie::Graphical {
    struct Vector2D {
        float x;
        float y;
    };

    class Window {
        public:
            Window(
                unsigned int width = 800,
                unsigned int height = 600,
                const std::string &title = "Bomberman"
            );
            ~Window();

            void display(double deltaTime);
            void changeSize(const Vector2D &size);
            void setScene(const std::shared_ptr<Scenes::IScene> &scene);

            bool isOpened() const;

            Vector2D getPos(float x, float y) const;

            Indie::Event getEvent() const;
        private:
            bool _opened = false;

            Vector2D _size;

            std::shared_ptr<Scenes::IScene> _scene;

            std::map<int, KeyEvent> _keymap;
    };
}

#endif
