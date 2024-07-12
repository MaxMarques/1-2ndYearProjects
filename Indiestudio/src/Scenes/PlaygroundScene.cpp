/*
** EPITECH PROJECT, 2020
** PlaygroundScene.cpp
** File description:
** PlaygroundScene function
*/

#include "PlaygroundScene.hpp"

#include <iostream>

Indie::Scenes::PlaygroundScene::PlaygroundScene(Scenes::SceneManager &manager) : AScene("PlaygroundScene", manager)
{
    this->_camera.fovy = 90.0f;
    this->_camera.position = { 10.0f, 10.0f, 10.0f };
    this->_camera.projection = ::CAMERA_PERSPECTIVE;
    this->_camera.target = { 0.0f, 0.0f, 0.0f };
    this->_camera.up = { 0.0f, 1.0f, 0.0f };
    ::SetCameraMode(this->_camera, ::CAMERA_ORBITAL);

    this->_model = std::make_unique<Models::AModel>(
        "assets/models/lumberjack/lumberjack.iqm",
        "assets/models/lumberjack/texture.png",
        "assets/models/lumberjack/lumberjack_anim.iqm"
    );

    std::vector<std::string> names = {
        "TPOSE",
        "IDLE"
    };
    this->_model->setAnimationsNames(names);
    this->_model->setCurrentAnimation("IDLE");
    this->_model->setPlaySpeed(1);
    this->_model->setRotationAxis({ 1.0f, 0.0f, 0.0f });
    this->_model->setRotationAngle(-90.0f); // Blender export fix.
}

Indie::Scenes::PlaygroundScene::~PlaygroundScene()
{

}

void Indie::Scenes::PlaygroundScene::update(Event event, double deltaTime, const Indie::Graphical::Window &win)
{
    AScene::update(event, deltaTime, win);
}

void Indie::Scenes::PlaygroundScene::display(const Graphical::Window &window)
{
    (void)window;
    ::UpdateCamera(&this->_camera);
    ::ClearBackground(BLUE);
    ::BeginMode3D(this->_camera);
    this->_model->display();
    ::EndMode3D();
}
