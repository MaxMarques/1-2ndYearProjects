/*
** EPITECH PROJECT, 2020
** AModel.cpp
** File description:
** AModel function
*/

#include "AModel.hpp"
#include "ModelError.hpp"

#include <iostream>

Indie::Models::AModel::AModel(
    const std::string &modelPath,
    const std::string &texturePath,
    const std::string &animationPath
)
{
    this->_modelPath = modelPath;
    this->_texturePath = texturePath;
    this->_animationPath = animationPath;

    this->_model = ::LoadModel(modelPath.c_str());
    if (!animationPath.empty())
        this->_animations = ::LoadModelAnimations(animationPath.c_str(), &this->_animationCount);
    if (!texturePath.empty()) {
        this->_texture = ::LoadTexture(texturePath.c_str());
        ::SetMaterialTexture(
            &this->_model.materials[0],
            ::MAP_DIFFUSE,
            this->_texture
        );
    }

    this->_rotationAngle = 0.0f;
    this->_scale = { 1.0f, 1.0f, 1.0f };
    this->_position = { 0.f, 0.0f, 0.0f };
    this->_rotationAxis = { 0.0f, 0.0f, 0.0f };
}

Indie::Models::AModel::~AModel()
{
    ::UnloadModel(this->_model);
    if (this->_animations)
        ::UnloadModelAnimations(this->_animations, this->_animationCount);
    if (!this->_texturePath.empty())
        ::UnloadTexture(this->_texture);
}

void Indie::Models::AModel::update(double deltaTime)
{
    this->_elapsedTime += deltaTime;

    if (!this->_animations) return;

    if (this->_elapsedTime >= (60 / (this->_animationSpeed * 60))) {
        this->_elapsedTime = 0;
        this->_currentFrame++;
        if (this->_currentFrame >=
                this->_animations[this->_currentAnimation].frameCount) {}
            this->_currentFrame = 0;
        ::UpdateModelAnimation(
            this->_model,
            this->_animations[this->_currentAnimation],
            this->_currentFrame
        );
    }
}

void Indie::Models::AModel::display()
{
    ::DrawModelEx(
        this->_model,
        this->_position,
        this->_rotationAxis,
        this->_rotationAngle,
        this->_scale,
        ::WHITE
    );
}

void Indie::Models::AModel::setPlaySpeed(float speed)
{
    this->_animationSpeed = speed;
}

void Indie::Models::AModel::setCurrentAnimation(const std::string &name)
{
    std::size_t i = 0;

    for (const auto &n : this->_names) {
        if (n == name) {
            this->_currentAnimation = i;

            return;
        }
        i++;
    }

    throw Errors::ModelError("Animation not found.", __func__);
}

void Indie::Models::AModel::setAnimationsNames(const std::vector<std::string> &names)
{
    this->_names = names;
}

void Indie::Models::AModel::setScale(const ::Vector3 &scale)
{
    this->_scale = scale;
}

void Indie::Models::AModel::setPosition(const ::Vector3 &position)
{
    this->_position = position;
}

void Indie::Models::AModel::setRotationAngle(float rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

void Indie::Models::AModel::AModel::setRotationAxis(const ::Vector3 &rotationAxis)
{
    this->_rotationAxis = rotationAxis;
}

Vector3 Indie::Models::AModel::AModel::getPosition() {
    return this->_position;
}

BoundingBox Indie::Models::AModel::getBoundingBox() {
    this->_bBox = {{this->_position.x - this->_scale.x / 2, this->_position.y - this->_scale.y / 2,
                                                                                                    this->_position.z -
                                                                                                    this->_scale.z / 2},
                   {this->_position.x + this->_scale.x / 2, this->_position.y + this->_scale.y / 2, this->_position.z +
                                                                                                    this->_scale.z /2}};
    return this->_bBox;
}

BoundingBox Indie::Models::AModel::setBoundingBox(const ::Vector3 &nextPositions) {
    this->_bBoxNext =  {{nextPositions.x - this->_scale.x / 2, nextPositions.y - this->_scale.y / 2,
                                                                                                         nextPositions.z -
                                                                                                         this->_scale.z / 2},
                        {nextPositions.x + this->_scale.x / 2, nextPositions.y + this->_scale.y / 2, nextPositions.z +
                                                                                                         this->_scale.z /2}};
    return this->_bBoxNext;
}
