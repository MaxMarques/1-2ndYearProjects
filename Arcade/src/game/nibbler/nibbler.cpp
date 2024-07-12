/*
** EPITECH PROJECT, 2021
** Nibbler
** File description:
** Nibbler.cpp
*/

#include "nibbler.hpp"

Nibbler::Nibbler()
{
    this->score = 0;
    this->lose = 0;
    this->direction = "right";
    this->mapSize.x = 16;
    this->mapSize.y = 16;
    std::vector<int> start = {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < this->mapSize.x; i++) {
        std::vector<int> v1;
        for (int j = 0; j < this->mapSize.y; j++) {
            if (j == 8 && i == 8) {
                v1 = start;
                snake_p.push_back({3, 8});
                snake_p.push_back({4, 8});
                snake_p.push_back({5, 8});
                snake_p.push_back({6, 8});
                break;            v1.push_back(0);
            } else {
                v1.push_back(0);
            }
        }
        this->map.push_back(v1);
    }
    this->generate_food();
}

Nibbler::~Nibbler()
{

}

void Nibbler::reset()
{

}

void Nibbler::update(double elapsedTime)
{
    (void)elapsedTime;
}

void Nibbler::handleEvent(KeyEvent event)
{
    switch (event)
    {
    case KeyEvent::MOVEUP:
        move_snake_up();
        break;
    case KeyEvent::MOVEDOWN:
        move_snake_down();
        break;
    case KeyEvent::MOVELEFT:
        move_snake_left();
        break;
    case KeyEvent::MOVERIGHT:
        move_snake_rigth();
        break;
    default:
        break;
    }
    if (Nibbler::direction == "right") {
        move_snake_rigth();
    } else if (Nibbler::direction == "left") {
        move_snake_left();
    } else if (Nibbler::direction == "up") {
        move_snake_up();
    } else if (Nibbler::direction == "down") {
        move_snake_down();
    }
}

unsigned int Nibbler::getScore() const
{
    return (this->score);
}

int Nibbler::getLose() const
{
    return (this->lose);
}

std::vector<std::vector<int>> Nibbler::getMap() const
{
    return (this->map);
}

std::vector<caractere_pos_t> Nibbler::get_pos_caractere()
{
    return (this->snake_p);
}

obj_pos_t Nibbler::get_pos_obj()
{
    return (this->applePos);
}

std::string Nibbler::getName() const
{
    return ("Nibbler");
}

void Nibbler::generate_food() {
    srand (time(NULL));
    int v1;
    int v2;

    while (1) {
        v1 = rand() % 16;
        v2 = rand() % 16;
        if (this->map.at(v1).at(v2) == 0) {
            this->map.at(v1).at(v2) = -1;
            this->applePos.x = v2;
            this->applePos.y = v1;
            break;
        }
    }
}

void Nibbler::move_snake_rigth() {

    if (direction == "left") {
        return;
    }
    if (snake_p.back().x + 1 > 15) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y).at(snake_p.back().x + 1) == 1) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y).at(snake_p.back().x + 1) == -1) {
        this->map.at(snake_p.back().y).at(snake_p.back().x + 1) = 1;
        snake_p.push_back({snake_p.back().x + 1, snake_p.back().y});
        this->score += 1;
        this->generate_food();
    } else {
        this->map.at(snake_p.back().y).at(snake_p.back().x + 1) = 1;
        snake_p.push_back({snake_p.back().x + 1, snake_p.back().y});
        this->map.at(snake_p.begin()->y).at(snake_p.begin()->x) = 0;
        snake_p.erase(snake_p.begin());
    }
    this->direction = "right";
}

void Nibbler::move_snake_left() {
    if (direction == "right")
        return;
    if (snake_p.back().x - 1 < 0) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y).at(snake_p.back().x - 1) == 1) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y).at(snake_p.back().x - 1) == -1) {
        this->map.at(snake_p.back().y).at(snake_p.back().x - 1) = 1;
        snake_p.push_back({snake_p.back().x - 1, snake_p.back().y});
        this->score += 1;
        this->generate_food();
    } else {
        this->map.at(snake_p.back().y).at(snake_p.back().x - 1) = 1;
        snake_p.push_back({snake_p.back().x - 1, snake_p.back().y});
        this->map.at(snake_p.begin()->y).at(snake_p.begin()->x) = 0;
        snake_p.erase(snake_p.begin());
    }
    this->direction = "left";
}

void Nibbler::move_snake_down() {

    if (direction == "up")
        return;
    if (snake_p.back().y + 1 > 15) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y + 1).at(snake_p.back().x) == 1) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y + 1).at(snake_p.back().x) == -1) {
        this->map.at(snake_p.back().y + 1).at(snake_p.back().x) = 1;
        snake_p.push_back({snake_p.back().x, snake_p.back().y +  1});
        this->score += 1;
        this->generate_food();
    } else {
        this->map.at(snake_p.back().y + 1).at(snake_p.back().x) = 1;
        snake_p.push_back({snake_p.back().x, snake_p.back().y +  1});
        this->map.at(snake_p.begin()->y).at(snake_p.begin()->x) = 0;
        snake_p.erase(snake_p.begin());
    }
    this->direction = "down";
}

void Nibbler::move_snake_up() {

    if (direction == "down")
        return;
    if (snake_p.back().y - 1 < 0) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y - 1).at(snake_p.back().x) == 1) {
        this->lose = 1;
        return;
    }
    if (this->map.at(snake_p.back().y - 1).at(snake_p.back().x) == -1) {
        this->map.at(snake_p.back().y - 1).at(snake_p.back().x) = 1;
        snake_p.push_back({snake_p.back().x, snake_p.back().y - 1});
        this->score += 1;
        this->generate_food();
    } else {
        this->map.at(snake_p.back().y - 1).at(snake_p.back().x) = 1;
        snake_p.push_back({snake_p.back().x, snake_p.back().y - 1});
        this->map.at(snake_p.begin()->y).at(snake_p.begin()->x) = 0;
        snake_p.erase(snake_p.begin());
    }
    this->direction = "up";
}

extern "C" IGame *create_game()
{
	return (new Nibbler());
}

extern "C" void destroy_game(IGame *library)
{
	delete (library);
}