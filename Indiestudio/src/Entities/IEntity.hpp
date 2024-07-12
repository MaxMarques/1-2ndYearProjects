/*
** EPITECH PROJECT, 2020
** IEntity.hpp
** File description:
** IEntity header file
*/

#ifndef IEntity_H_
#define IEntity_H_

#include "Window.hpp"

#include <memory>

namespace Indie::Entities {
    class IEntity {
        public:
            ~IEntity() = default;

            virtual void display() = 0;
            virtual void setParent(std::shared_ptr<IEntity> &parent) = 0;
            virtual void setPosition(const Graphical::Vector2D &pos) = 0;

            virtual Graphical::Vector2D getPosition() const = 0;

            virtual bool collidesWith(const IEntity &other) const = 0;
    };
}

#endif
