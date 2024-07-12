#include "raylib.h"

#include "Indie.hpp"
#include "AScene.hpp"
#include "Window.hpp"
#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "MenuScene.hpp"
#include "OptionScene.hpp"
#include "SceneManager.hpp"
#include "PlaygroundScene.hpp"

#include <cstring>
#include <chrono>

static void parseArguments(int ac, char *av[])
{
    /*for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "--debug") == 0) {
            #undef INDIE_DEBUG
            #define INDIE_DEBUG true
        }
    }*/
    (void)ac;
    (void)av;
}

int main(int ac, char *av[])
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    auto sceneManager = std::make_shared<Indie::Scenes::SceneManager>();
    Indie::Graphical::Window window = Indie::Graphical::Window(1920, 1080);

    parseArguments(ac, av);
    sceneManager->addScene<Indie::Scenes::MenuScene>();
    sceneManager->addScene<Indie::Scenes::OptionScene>();
    sceneManager->addScene<Indie::Scenes::PlaygroundScene>();
    sceneManager->addScene<Indie::Scenes::GameScene>();
    sceneManager->changeScene("MenuScene");

    while (window.isOpened()) {
        start = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::ratio<1, 1000>> deltaTime = start - end;
        auto scene = sceneManager->getCurrentScene();
        window.setScene(scene);
        scene->update(window.getEvent(), deltaTime.count() * 1000, window);
        window.display(deltaTime.count() * 1000);
        end = std::chrono::steady_clock::now();
    }
}