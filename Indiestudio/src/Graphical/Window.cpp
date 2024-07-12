/*
** EPITECH PROJECT, 2020
** Window.cpp
** File description:
** Window function
*/

#include "Window.hpp"

#include <raylib.h>
#include <iostream>
#include <sstream>

Indie::Graphical::Window::Window(
        unsigned int width,
        unsigned int height,
        const std::string &title
)
{
    ::InitWindow(width, height, title.c_str());
    ::SetTargetFPS(60);
    this->_opened = true;
    this->_size = Vector2D { (float)width, (float)height };
    this->_keymap.insert({ ::KEY_RIGHT, MOVE_RIGHT });
    this->_keymap.insert({ ::KEY_LEFT, MOVE_LEFT });
    this->_keymap.insert({ ::KEY_UP, MOVE_UP });
    this->_keymap.insert({ ::KEY_DOWN, MOVE_DOWN });
    this->_keymap.insert({ ::KEY_SPACE, ACTION });
    this->_keymap.insert({ ::KEY_P, PAUSE });
    this->_keymap.insert({ ::KEY_ENTER, ENTER });
}

Indie::Graphical::Window::~Window()
{
    ::CloseWindow();
}

void Indie::Graphical::Window::changeSize(const Vector2D &size)
{
    this->_size = size;
    ::SetWindowSize(this->_size.x, this->_size.y);
}

void Indie::Graphical::Window::display(double deltaTime)
{
    (void)deltaTime;
    ::BeginDrawing();
    ::ClearBackground(RAYWHITE);
    #ifdef INDIE_DEBUG
    auto recPos = this->getPos(75, 0);
    auto recSize = this->getPos(25, 15);
    ::DrawRectangle(recPos.x, recPos.y, recSize.x, recSize.y, ::LIGHTGRAY);
    ::DrawFPS(recPos.x, recPos.y + 28);
    ::DrawText("Debug", recPos.x, recPos.y + 1, 25, ::BLACK);
    if (this->_scene) {
        std::string SceneName = "Current scene: ";
        SceneName += this->_scene->getName();
        ::DrawText(SceneName.c_str(), recPos.x, recPos.y + 50, 25, ::BLACK);
        std::ostringstream ss;
        ss << "Frame time: " << deltaTime << "ms";
        ::DrawText(ss.str().c_str(), recPos.x, recPos.y + 75, 25, ::BLACK);
    }
    #endif
    if (this->_scene)
        this->_scene->display(*this);
    ::EndDrawing();
}

bool Indie::Graphical::Window::isOpened() const
{
    return !::WindowShouldClose();
}

Indie::Graphical::Vector2D Indie::Graphical::Window::getPos(float x, float y) const
{
    return Vector2D {
        (x / 100) * this->_size.x,
        (y / 100) * this->_size.y
    };
}

void Indie::Graphical::Window::setScene(const std::shared_ptr<Scenes::IScene> &scene)
{
    this->_scene = scene;
}

Indie::Event Indie::Graphical::Window::getEvent() const
{
    int key = ::GetKeyPressed();
    auto it = this->_keymap.find(key);

    if (it == this->_keymap.end()) return { EVENT_NONE, NONE};

    if (IsKeyPressed(key))
        return { EVENT_KEY, it->second};
    if (IsKeyUp(key))
        return { EVENT_KEY, it->second };
    return {EVENT_NONE, NONE};
}
