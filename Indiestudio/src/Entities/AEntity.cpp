/*
** EPITECH PROJECT, 2020
** AEntity.cpp
** File description:
** AEntity function
*/

#include "AEntity.hpp"

Indie::Entities::AEntity::AEntity()
{

}

bool Indie::Entities::AEntity::collidesWith(const Indie::Entities::IEntity &other) const
{
    (void)other;
    return false;
}

Indie::Graphical::Vector2D Indie::Entities::AEntity::getPosition() const
{
    return this->_position;
}

void Indie::Entities::AEntity::setPosition(const Graphical::Vector2D &pos)
{
    this->_position = pos;
}

void Indie::Entities::AEntity::display()
{
    #ifdef INDIE_DEBUG
    this->_debug();
    #endif
}

void Indie::Entities::AEntity::_debug()
{

}

void Indie::Entities::AEntity::setParent(std::shared_ptr<IEntity> &parent)
{
    this->_parent = parent;
}
