/*
** EPITECH PROJECT, 2021
** core_sfml
** File description:
** core_sfml.hpp
*/

#ifndef _SFML_
#define _SFML_

#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include <SFML/Graphics/View.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../ILibrary.hpp"
#include "../../core/struct.hpp"

class SFML : public ILibrary
{
    public:
        SFML();
        ~SFML();
        void init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs) override final;
        void update() override final;
        KeyEvent getKeyEvent() override final;
        void display() override final;
        bool isOpened() override final;
        void close() override final;
        void setGameMap(const std::vector<std::vector<int>> &) override final;
        std::string getName() const override final;
        void set_pos_caractere(std::vector<caractere_pos_t> pos) override final;
        void set_pos_obj(obj_pos_t pos) override final;
        void setScore(unsigned int score) override final;
        void init_element(const std::string &string, int x, int y, int onef, int twof, float xo, float yo);
        sf::Text init_text(const std::string &string, int x, int y, unsigned int size, sf::Color color);
        void element_sound(const std::string &string, int x, int y, int onef, int twof);
        void event_menu();
        void init_menu();
        KeyEvent event_off();
        void init_off();
        void event_option();
        void init_option();
        KeyEvent event_play();
        void init_play();
        void event_rules();
        void init_rules();
        void display_game();
        KeyEvent event_game();
    private:
        sf::RenderWindow *_Renderwindow;
        sf::Event *_Event;
        sf::Clock _clock;
        std::vector<sf::Text> _Texte;
        sf::Font _font;
        sf::Music _music_principal;
        sf::Music _music1;
        sf::Music _music2;
        sf::Music _music3;
        sf::Music _music4;
        sf::Music _music5;
        sf::Music _music6;
        sf::Music _music7;
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
        int _volume;
        int _selection_menu;
        int _selection_off;
        int _selection_option;
        int _selection_play;
        int _selection_rules;
        int _game;
        int _library;
        int _e_game;
        int _choice_game;
        bool _energy;
        bool _on;
        bool _off;
        bool _option;
        bool _switch_option;
        bool _switch_sound;
        bool _switch_s;
        bool _switch_play;
        bool _play;
        bool _switch_rules;
        bool _rules;
        bool _load_game;
        unsigned int _score;
        std::vector<caractere_pos_t> _caractere;
        obj_pos_t _obj;
};

extern "C" ILibrary *create_library();
extern "C" void destroy_library(ILibrary *library);

#endif