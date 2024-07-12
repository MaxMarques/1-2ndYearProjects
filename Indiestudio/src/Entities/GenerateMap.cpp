//
// Created by ravens on 09/06/2021.
//

#include "GenerateMap.hpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Indie::Entities::GenerateMap::GenerateMap()
{

}

void Indie::Entities::GenerateMap::CreateMap(unsigned int width, unsigned int height)  {
    this->_width = width;
    srand (time(NULL));
    int value = 0;
    if (height == 3)
        this->_height = width;
    else
        this->_height = height;
    for (unsigned int i = 0; i < this->_width; ++i) {
        std::vector<int> v;
        for (unsigned int j = 0; j < this->_height; ++j) {
            if (j == 0 || i == 0 ||i == this->_width -1 || j == this->_height -1) {
                value = 2;
            } else if ((i == 1 && j ==1) || (i == 1 && j == 2) || (i== 2 && j == 1)
                       || (i == this->_width -2 && j == this->_height -2 )|| (i == this->_width -2 && j == this->_height -3)||(i== this->_width -3 && j == this->_height - 2)
                       ||  (i == 1 && j == this->_height -2 ) || (i == 1 && j == this->_height -3)||(i == 2  && j == this->_height - 2)
                       || (i == this->_width -2 && j == 1)||(i== this->_width -2 && j == 2) || (i== this->_width -3 && j == 1)) {
                value = 0;
            } else {
                j % 2 == true || j == this->_height-2 ? value = 1 : value = 2;
            }
            if ((i == 1 || i == this->_width - 2) && (j != 0 && j != this->_height - 1 ) && value == 2)
                value = 1;
            v.push_back(value);
        }
        this->_mapvect.push_back(v);
        std::cout << std::endl;
    }
}

Indie::Entities::GenerateMap::~GenerateMap() {

}

std::vector<std::vector<int>> Indie::Entities::GenerateMap::getCreatedMap() {
    return this->_mapvect;
}

void Indie::Entities::GenerateMap::AddMapToVector() {
    for (unsigned int i = 0; i < this->_mapvect.size(); i++)
    {
        for (unsigned int j = 0; j < this->_mapvect[i].size(); j++)
        {
            if (this->_mapvect[i][j] == 2) {
                std::unique_ptr<Models::IModel> _block = std::make_unique<Models::AModel>("assets/models/tree.obj",
                                                                                          "assets/models/tree.png", "");
                _block->setPosition({(float) i - 4, 0.0f, (float) j - 4 });
                this->_modelVect.push_back(std::move(_block));
            }
            else if (this->_mapvect[i][j] == 1) {
                std::unique_ptr<Models::IModel> _box = std::make_unique<Models::AModel>("assets/models/rock.obj",
                                                                                        "assets/models/rock.png", "");
                _box->setPosition({(float) i - 4, 0.0f, (float) j - 4});
                this->_modelVect.push_back(std::move(_box));
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::unique_ptr<Indie::Models::IModel>> &Indie::Entities::GenerateMap::getMapVector()
{
    return this->_modelVect;
}