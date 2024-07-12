/*
** EPITECH PROJECT, 2020
** AEntity.hpp
** File description:
** AEntity header file
*/

#ifndef AEntity_H_
#define AEntity_H_

#include "Window.hpp"
#include "IEntity.hpp"

namespace Indie::Entities {
    class AEntity : public IEntity {
        public:
            AEntity();
            ~AEntity() = default;

            void display() override;
            void setParent(std::shared_ptr<IEntity> &parent) override;
            void setPosition(const Graphical::Vector2D &pos) override;

            Graphical::Vector2D getPosition() const override;

            bool collidesWith(const IEntity &other) const override;
        private:

            Graphical::Vector2D _position;

            virtual void _debug();
        protected:
            std::shared_ptr<IEntity> _parent;
    };
}

#endif
