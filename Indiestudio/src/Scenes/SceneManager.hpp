/*
** EPITECH PROJECT, 2020
** SceneManager.hpp
** File description:
** SceneManager header file
*/

#ifndef SceneManager_H_
#define SceneManager_H_

#include "IScene.hpp"

#include <vector>
#include <memory>

namespace Indie::Scenes {
    class SceneManager {
        public:
            SceneManager() = default;

            template<typename T, typename ... Args>
            void addScene(Args && ... args);
            void removeScene(const std::string &name);

            void changeScene(const std::string &name);

            std::shared_ptr<IScene> getCurrentScene() const;
        private:
            std::vector<std::shared_ptr<IScene>> _scenes;

            std::shared_ptr<IScene> _currScene;
    };
}

template<typename T, typename ... Args>
void Indie::Scenes::SceneManager::addScene(Args && ... args)
{
    this->_scenes.push_back(
        std::make_shared<T>(*this, std::forward<Args>(args) ...)
    );
}

#endif
