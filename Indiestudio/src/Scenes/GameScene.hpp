/*
** EPITECH PROJECT, 2021
** indie
** File description:
** GameScene
*/

#ifndef INDIE_GAMESCENE_HPP_
#define INDIE_GAMESCENE_HPP_

#include "AScene.hpp"
#include "SceneManager.hpp"
#include "GenerateMap.hpp"
#include "AModel.hpp"

#include <raylib.h>

namespace Indie::Scenes
{
    class GameScene : public Scenes::AScene
    {
        struct playerRotation
        {
            float x;
            float y;
        };
        struct playerPos
        {
            float x;
            float z;
        };

    public:
        GameScene(SceneManager &sceneManager);
        ~GameScene();
        void update(Event event, double deltaTime, const Indie::Graphical::Window &win) final;
        void display(const Graphical::Window &window) final;

    protected:
    private:
        ::Model _model;
        ::Texture2D _cubicmap;
        ::Texture2D _texture;
        ::Camera _camera;

        ::Vector3 _PositionBilly;
        ::Model _billy;
        ::Texture2D _textureBilly;
        playerPos _playerPose;
        std::unique_ptr<Models::IModel> _billiModel;

        ::Model _bomb;
        ::Texture2D _textureBomb;
        bool _dropBomb = false;
        bool _clear = false;

        ::Model _explosion;
        ::Texture2D _textureExplosion;

        int _timeBomb = 0;
        int _timeExplosion = 0;

        ::Sound sound;

        ::Texture2D _textureFloor;
        ::Texture2D _textureHerb;

        Entities::GenerateMap _GenMap;
        std::vector<std::vector<int> > _mapvect;

        //next positions management
        ::Vector3 _GoUp;
        ::Vector3 _GoDown;
        ::Vector3 _GoLeft;
        ::Vector3 _GoRight;
        bool _canGoUp;
        bool _canGoDown;
        bool _canGoLeft;
        bool _canGoRight;
    };
};

#endif // INDIE_GAMESCENE_HPP_
