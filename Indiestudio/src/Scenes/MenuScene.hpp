/*
** EPITECH PROJECT, 2020
** MenuScene.cpp
** File description:
** MenuScene function
*/

#ifndef INDIE_MENUSCENE_HPP
#define INDIE_MENUSCENE_HPP

#include "AScene.hpp"

#include "AScene.hpp"
#include "raylib.h"

namespace Indie::Scenes {
    class MenuScene : public Scenes::AScene {
        public:
            MenuScene(SceneManager &sceneManager);

            void display(const Graphical::Window &window) final;
            void update(Indie::Event event, double deltaTime, const Indie::Graphical::Window &win) final;
        private:
            Graphical::Vector2D menu_title;
            ::Texture2D _background;
            ::Texture2D _play_menu;
            ::Texture2D _exit_menu;
            ::Texture2D _setting_menu;
            int _menu_titlePosX = 0;
            int _menu_playPosX = 0;
            int _menu_settingPosy = 1080;
            int _menu_exitPosX = 1900;
            int _menu_titlePosOffset = 1;
            float _animationSpeed = 8.0f;
            int _time_menu = 0;
            int here = 0;
    };
}
#endif
