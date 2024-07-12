/*
** EPITECH PROJECT, 2020
** IModel.hpp
** File description:
** IModel header file
*/

#ifndef IModel_H_
#define IModel_H_

#include <raylib.h>
#include <vector>
#include <string>

namespace Indie::Models {
    class IModel {
        public:
            virtual ~IModel() = default;

            virtual void setScale(const ::Vector3 &scale) = 0;
            virtual void setRotationAngle(float rotationAngle) = 0;
            virtual void setPosition(const ::Vector3 &position) = 0;
            virtual void setRotationAxis(const ::Vector3 &rotationAxis) = 0;

            virtual void display() = 0;
            virtual void update(double deltaTime) = 0;
            virtual void setPlaySpeed(float speed) = 0;
            virtual void setCurrentAnimation(const std::string &name) = 0;
            virtual void setAnimationsNames(const std::vector<std::string> &) = 0;
            virtual Vector3 getPosition() = 0;
            virtual BoundingBox getBoundingBox() = 0;
            virtual BoundingBox setBoundingBox(const ::Vector3 &nextPositions) = 0;
    };
}

#endif
