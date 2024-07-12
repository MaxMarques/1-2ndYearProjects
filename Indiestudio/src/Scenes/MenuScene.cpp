/*
** EPITECH PROJECT, 2020
** MenuScene.cpp
** File description:
** MenuScene function
*/

#include "MenuScene.hpp"
#include "SceneManager.hpp"

#include <raylib.h>

Indie::Scenes::MenuScene::MenuScene(SceneManager &sceneManager) : AScene("MenuScene", sceneManager)
{
    this->_animationSpeed = 0.7;
    this->_background = ::LoadTexture("assets/menu/back.png");
    this->_play_menu = ::LoadTexture("assets/menu/play_menu.png");
    this->_exit_menu = ::LoadTexture("assets/menu/exit_menu.png");
    this->_setting_menu = ::LoadTexture("assets/menu/setting_menu.png");
}

void Indie::Scenes::MenuScene::update(Indie::Event event, double deltaTime, const Indie::Graphical::Window &win)
{
    int test = 0;
    AScene::update(event, deltaTime, win);

    if (GetMouseX() >= 910 && GetMouseX() <= 1160 && GetMouseY() >= 400 && GetMouseY() <= 467 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        this->_sceneManager.changeScene("GameScene");
    }
    if (GetMouseX() >= 904 && GetMouseY() <= 1149 && GetMouseY() >= 606 && GetMouseY() <= 668 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        ::CloseWindow();
    }
    this->menu_title = win.getPos(55, 20);
    if (this->_elapstedTime >= (60 / (this->_animationSpeed * 60)))
    {
        this->_elapstedTime = 0;
        this->_menu_titlePosX += this->_menu_titlePosOffset;
        if (this->_time_menu > 250)
        {
            if (this->_menu_playPosX < 900)
                this->_menu_playPosX += 15;
            if (this->_menu_exitPosX > 900)
                this->_menu_exitPosX -= 15;
            if (this->_menu_settingPosy > 45)
                this->_menu_settingPosy -= 15;
        }
        this->_time_menu++;
    }
}

void Indie::Scenes::MenuScene::display(const Indie::Graphical::Window &win)
{
    (void)win;
    ::ClearBackground(::GRAY);
    ::DrawTexture(this->_background, 0, 0, ::GRAY);
    if (this->_time_menu < 250)
    {
        if (this->_menu_titlePosX < 100)
            ::DrawText("INDIE STUDIO", this->menu_title.x, this->menu_title.y, this->_menu_titlePosX, ::MAGENTA);
        else
            ::DrawText("INDIE STUDIO", this->menu_title.x, this->menu_title.y, 100, ::MAGENTA);
    }
    else
    {
        ::DrawTexture(this->_play_menu, this->_menu_playPosX, 400, ::GRAY);
        ::DrawTexture(this->_exit_menu, this->_menu_exitPosX, 600, ::GRAY);
        ::DrawTexture(this->_setting_menu, 1830, this->_menu_settingPosy, ::GRAY);
    }
}
