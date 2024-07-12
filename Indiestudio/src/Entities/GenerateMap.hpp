/*
** EPITECH PROJECT, 2020
** AModel.hpp
** File description: Function to generation map
** GenerationMap cpp file
*/

#ifndef INDIE_GENERATEMAP_HPP
#define INDIE_GENERATEMAP_HPP
#include "AModel.hpp"
#include <vector>
#include <iostream>
#include <memory>

namespace Indie::Entities {
    class GenerateMap {
    public :
        GenerateMap();
        void CreateMap(unsigned int, unsigned int = 3);
        ~GenerateMap();
        void AddMapToVector();
        std::vector<std::vector<int>> getCreatedMap();
        std::vector<std::unique_ptr<Models::IModel>> &getMapVector();
    private :
        std::vector<std::vector<int>> _mapvect;
        std::vector<std::unique_ptr<Models::IModel>> _modelVect;
        std::vector<std::unique_ptr<Models::IModel>> _modelFloor;

        unsigned int _width;
        unsigned int _height;
    };

}
#endif //INDIE_GENERATEMAP_HPP
