/*
** EPITECH PROJECT, 2020
** AModel.hpp
** File description:
** AModel header file
*/

#ifndef AModel_H_
#define AModel_H_

#include "IModel.hpp"

#include <string>

namespace Indie::Models {
    class AModel : public IModel {
        public:
            AModel(
                const std::string &modelPath,
                const std::string &texturePath = "",
                const std::string &animationPath = ""
            );
            ~AModel();

            void display() override;
            void update(double deltaTime) override;
            void setPlaySpeed(float speed) override;
            void setCurrentAnimation(const std::string &name) final;
            void setAnimationsNames(const std::vector<std::string> &names) final;

            void setScale(const ::Vector3 &scale) final;
            void setRotationAngle(float rotationAngle) final;
            void setPosition(const ::Vector3 &position) final;
            void setRotationAxis(const ::Vector3 &rotationAxis) final;
            Vector3 getPosition() final;
            BoundingBox getBoundingBox() final;
            BoundingBox setBoundingBox(const ::Vector3 &nextPositions) final;
    private:
            std::string _modelPath;
            std::string _texturePath;
            std::string _animationPath;

            std::vector<std::string> _names;
        protected:
            ::Model _model;
            ::Texture2D _texture;
            ::ModelAnimation *_animations = nullptr;

            int _frameCounter = 0;
            int _currentFrame = 0;
            int _animationCount = 0;
            int _currentAnimation = 0;

            float _animationSpeed = 1;
            double _elapsedTime = 0;

            ::Vector3 _position;
            ::Vector3 _rotationAxis;
            ::Vector3 _scale;
            float _rotationAngle;
            ::BoundingBox _bBox;
            ::BoundingBox _bBoxNext;
    };
}

#endif
