/*
** EPITECH PROJECT, 2021
** core_sfml.cpp
** File description:
** core_sfml
*/

#include "core_sfml.hpp"

SFML::SFML()
{
    this->_selection_menu = 0;
    this->_selection_off = 0;
    this->_selection_option = 0;
    this->_selection_play = 0;
    this->_selection_rules = 0;
    this->_game = 0;
    this->_energy = true;
    this->_option = 0;
    this->_volume = 50;
    this->_switch_sound = true;
    this->_switch_play = false;
    this->_switch_rules = false;
    this->_play = false;
    this->_switch_s = true;
    this->_load_game = false;
    this->_library = 0;
    this->_off = false;
    this->_switch_option = false;
    this->_e_game = 0;
    this->_choice_game = 0;
}

SFML::~SFML()
{

}

void SFML::setGameMap(const std::vector<std::vector<int>> &)
{
}

void SFML::set_pos_caractere(std::vector<caractere_pos_t> pos)
{
    this->_caractere = pos;
}

void SFML::set_pos_obj(obj_pos_t pos)
{
    this->_obj = pos;
}

void SFML::setScore(unsigned int score)
{
    this->_score = score;
}

std::string SFML::getName() const
{
    return ("SFML");
}

void SFML::init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs)
{
    this->_Renderwindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Resize | sf::Style::Close);
    this->_Event = new sf::Event();
    this->_clock = sf::Clock();
    this->_Renderwindow->setMouseCursorVisible(0);
    this->_font.loadFromFile("assets/borne/ARCADE.TTF");
    this->_buffer.loadFromFile("assets/borne/bruitage.ogg");
    this->_sound.setBuffer(this->_buffer);
    this->_music_principal.openFromFile("assets/borne/principal_song.ogg");
    this->_music1.openFromFile("assets/borne/44bulldog.ogg");
    this->_music2.openFromFile("assets/borne/oboy.ogg");
    this->_music3.openFromFile("assets/borne/au_dd.ogg");
    this->_music4.openFromFile("assets/borne/glk.ogg");
    this->_music5.openFromFile("assets/borne/bande_organise.ogg");
    this->_music6.openFromFile("assets/borne/KidCudi.ogg");
    this->_music7.openFromFile("assets/borne/Pirate.ogg");
    this->_music_principal.play();
    this->_music_principal.setVolume(50);
}

void SFML::update()
{
    init_menu();
    this->_Renderwindow->display();
}

KeyEvent SFML::getKeyEvent()
{
    static KeyEvent keep_direction = KeyEvent::MOVERIGHT;
    while (this->_Renderwindow->pollEvent(*(this->_Event))) {
        if (this->_Event->type == this->_Event->Closed) {
            this->_music1.stop();
            this->_music2.stop();
            this->_music3.stop();
            this->_music4.stop();
            this->_music5.stop();
            this->_music6.stop();
            this->_music7.stop();
            this->_music_principal.stop();
            return(KeyEvent::EXIT);
        }
        if (this->_Event->type == this->_Event->KeyPressed) {
            event_option();
            event_menu();
            event_rules();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                return(KeyEvent::EXIT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                this->_switch_option = false;
                this->_off = false;
                this->_switch_play = false;
                this->_switch_rules = false;
                this->_game = 0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
                return (KeyEvent::LIBNCURSES);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
                return (KeyEvent::LIBSDL);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && this->_switch_option == false && this->_off == false && this->_switch_play == false && this->_switch_rules == false && this->_game != 0)
                return (KeyEvent::PACMAN);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4) && this->_switch_option == false && this->_off == false && this->_switch_play == false && this->_switch_rules == false && this->_game != 0)
                return (KeyEvent::NIBBLER);
            if (event_play() == KeyEvent::NIBBLER)
                return (KeyEvent::NIBBLER);
            else
                return (KeyEvent::PACMAN);
            if (event_off() == KeyEvent::EXIT)
                return (KeyEvent::EXIT);
        }
        if (event_game() == KeyEvent::MOVEUP) {
            keep_direction = KeyEvent::MOVEUP;
            return (KeyEvent::MOVEUP);
        }
        else if (event_game() == KeyEvent::MOVEDOWN) {
            keep_direction = KeyEvent::MOVEDOWN;
            return (KeyEvent::MOVEDOWN);
        }
        else if (event_game() == KeyEvent::MOVELEFT) {
            keep_direction = KeyEvent::MOVELEFT;
            return (KeyEvent::MOVELEFT);
        }
        else if (event_game() == KeyEvent::MOVERIGHT) {
            keep_direction = KeyEvent::MOVERIGHT;
            return (KeyEvent::MOVERIGHT);
        }
    }
    return keep_direction;
}

void SFML::init_element(const std::string &string, int x, int y, int onef, int twof, float xo, float yo)
{
    sf::Texture Texture;
    sf::Sprite Sprite;
    
    Texture.loadFromFile(string);
    Sprite.setTexture(Texture);
    Sprite.setPosition(x, y);
    Sprite.setScale(onef, twof);
    Sprite.setOrigin(xo, yo);
    this->_Renderwindow->draw(Sprite);
}

void SFML::element_sound(const std::string &string, int x, int y, int onef, int twof)
{
    sf::Texture Texture;
    sf::Sprite Sprite;
    
    Texture.loadFromFile(string);
    Sprite.setTexture(Texture);
    Sprite.setPosition(x, y);
    Sprite.setScale(onef, twof);
    Sprite.setColor(sf::Color::Green);
    this->_Renderwindow->draw(Sprite);
}

sf::Text SFML::init_text(const std::string &string, int x, int y, unsigned int size, sf::Color color)
{
    sf::Text text(string, this->_font);
    text.setPosition(y, x);
    text.setCharacterSize(size);
    text.setFillColor(color);

    return (text);
}

void SFML::display()
{
    if (this->_off == true)
        this->_energy = false;
    else
        this->_energy = true;
    if (this->_switch_option == false)
        this->_option = false;
    else
        this->_option = true;
    if (this->_switch_play == false)
        this->_play = false;
    else
        this->_play = true;
    if (this->_switch_rules == false)
        this->_rules = false;
    else
        this->_rules = true;
    if (this->_game == 1)
        this->_load_game = true;
    else
        this->_load_game = false;
    this->_Renderwindow->clear();
    init_element("assets/borne/arcade.jpg", 0, 0, 1.f, 1.f, 0, 0);
    sf::Time Time = this->_clock.getElapsedTime();
    float m = Time.asSeconds();
    if (this->_energy == true && this->_option == false && this->_play == false && this->_rules == false && this->_game == 0) {
        if (m < 5) {
            this->_on = true;
            init_element("assets/borne/Titre.png", 550, 200, 2.0f, 2.0f, 0, 0);
        } else {
            this->_on = false;
            init_element("assets/borne/Titre.png", 750, 50, 1.0f, 1.0f, 0, 0);
            for (const auto &i : this->_Texte) {
                this->_Renderwindow->draw(i);
            }
        }
    }
    else if (this->_option == true) {
        if (this->_switch_s == false)
            this->_switch_sound = false;
        else
            this->_switch_sound = true;
        init_option();
    }
    else if (this->_play == true)
        init_play();
    else if (this->_rules == true)
        init_rules();
    else if (this->_energy == false)
        init_off();
    else if (this->_load_game == true)
        display_game();
    this->_Renderwindow->display();
}

void SFML::event_menu()
{
    if (this->_Event->type == this->_Event->KeyPressed) {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && this->_energy == true && this->_on == false && this->_game == 0) {
		    this->_selection_menu--;
            this->_sound.play();
        }
        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && this->_energy == true && this->_on == false && this->_game == 0) {
            this->_selection_menu++;
            this->_sound.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_menu == 1  && this->_energy == true && this->_play == 0 && this->_rules == 0 && this->_option == 0 && this->_off == 0 && this->_game == 0)
            this->_switch_play = true;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_menu == 2  && this->_energy == true && this->_play == 0 && this->_rules == 0 && this->_option == 0 && this->_off == 0 && this->_game == 0)
            this->_switch_rules = true;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_menu == 3  && this->_energy == true && this->_play == 0 && this->_rules == 0 && this->_option == 0 && this->_off == 0 && this->_game == 0)
            this->_switch_option = true;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_menu == 4  && this->_energy == true && this->_on == false && this->_play == 0 && this->_rules == 0 && this->_option == 0 && this->_off == 0 && this->_game == 0) {
            this->_off = true;
            this->_music_principal.stop();
            this->_music1.stop();
            this->_music2.stop();
            this->_music3.stop();
            this->_music4.stop();
            this->_music5.stop();
            this->_music6.stop();
            this->_music7.stop();
            this->_clock.restart();
        }
    }
}

void SFML::init_menu()
{
    this->_Texte.push_back(init_text("PLAY", 350, 880, 80, sf::Color::Magenta));
    this->_Texte.push_back(init_text("RULES", 500, 860, 80, sf::Color::Cyan));
    this->_Texte.push_back(init_text("OPTIONS", 650, 830, 80, sf::Color::Magenta));
    this->_Texte.push_back(init_text("OFF", 770, 910, 80, sf::Color::Cyan));
    if (this->_selection_menu == 1 && this->_energy == true && this->_on == false && this->_option == 0 && this->_play == false && this->_rules == false && this->_game == 0)
        this->_Renderwindow->draw(init_text("PLAY", 360, 880, 80, sf::Color::Cyan));
    else if (this->_selection_menu == 2 && this->_energy == true && this->_on == false && this->_option == 0 && this->_play == false && this->_rules == false && this->_game == 0)
        this->_Renderwindow->draw(init_text("RULES", 510, 860, 80, sf::Color::Magenta));
    else if (this->_selection_menu == 3 && this->_energy == true && this->_on == false && this->_option == 0 && this->_play == false && this->_rules == false && this->_game == 0)
        this->_Renderwindow->draw(init_text("OPTIONS", 660, 830, 80, sf::Color::Cyan));
    else if (this->_selection_menu == 4 && this->_energy == true && this->_on == false && this->_option == 0 && this->_play == false && this->_rules == false && this->_game == 0)
        this->_Renderwindow->draw(init_text("OFF", 780, 915, 80, sf::Color::Magenta));
    if (this->_selection_menu > 5)
            this->_selection_menu = 1;
    if (this->_selection_menu < 0)
        this->_selection_menu = 4;
}

KeyEvent SFML::event_play()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && this->_play == 1) {
        this->_selection_play--;
        this->_sound.play();
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && this->_play == 1) {
        this->_selection_play++;
        this->_sound.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_play == 1 && this->_play == 1)
        this->_switch_play = false;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_play == 2 && this->_play == 1) {
        this->_switch_play = false;
        this->_game = 1;
        this->_choice_game = 1;
        return (KeyEvent::PACMAN);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_play == 3 && this->_play == 1) {
        this->_switch_play = false;
        this->_game = 1;
        this->_choice_game = 2;
        return (KeyEvent::NIBBLER);
    }
}

void SFML::init_play()
{
    init_element("assets/borne/pacman_icon.jpg", 550, 200, 1.f, 1.f, 0, 0);
    init_element("assets/borne/nibbler_icon.png", 550, 600, 1.f, 1.f, 0, 0);
    this->_Renderwindow->draw(init_text("PACMAN", 230, 900, 130, sf::Color::Cyan));
    this->_Renderwindow->draw(init_text("NIBBLER", 630, 900, 130, sf::Color::Magenta));
    this->_Renderwindow->draw(init_text("X", 100, 1400, 80, sf::Color::Red));
    if (this->_selection_play == 1 && this->_play == 1)
        this->_Renderwindow->draw(init_text("X", 120, 1400, 80, sf::Color::Green));
    else if (this->_selection_play == 2 && this->_play == 1)
        this->_Renderwindow->draw(init_text("PACMAN", 250, 900, 130, sf::Color::Magenta));
    else if (this->_selection_play == 3 && this->_play == 1)
        this->_Renderwindow->draw(init_text("NIBBLER", 650, 900, 130, sf::Color::Cyan));
    if (this->_selection_play > 4)
        this->_selection_play = 1;
    if (this->_selection_play < 0)
        this->_selection_play = 3;
}

void SFML::event_rules()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && this->_rules == 1) {
        this->_selection_rules--;
        this->_sound.play();
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && this->_rules == 1) {
        this->_selection_rules++;
        this->_sound.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_rules == 1 && this->_rules == 1)
        this->_switch_rules = false;
}

void SFML::init_rules()
{
    this->_Renderwindow->draw(init_text("~ Borne ~", 100, 850, 40, sf::Color::Magenta));
    this->_Renderwindow->draw(init_text("Press 'cursor keys' => movement in the borne", 150, 600, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'echap' => exit program", 200, 720, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'm' => back menu", 250, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'r' => reload game", 300, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'F1' => start Ncurses", 350, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'F2' => start SDL2", 400, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'F3' => start Pacman", 450, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'F4' => start Nibbler", 500, 770, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("~ Pacman & Nibbler ~", 550, 760, 40, sf::Color::Magenta));
    this->_Renderwindow->draw(init_text("Press 'z' => up", 620, 820, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 's' => down", 670, 820, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'q' => left", 720, 820, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("Press 'd' => right", 770, 820, 30, sf::Color::White));
    this->_Renderwindow->draw(init_text("X", 100, 1400, 80, sf::Color::Red));
    if (this->_selection_rules == 1 && this->_rules == 1)
        this->_Renderwindow->draw(init_text("X", 120, 1400, 80, sf::Color::Green));
    if (this->_selection_rules > 2)
        this->_selection_rules = 1;
    if (this->_selection_rules < 0)
        this->_selection_rules = 1;
}

KeyEvent SFML::event_off()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && this->_energy == false) {
        this->_selection_off--;
        this->_sound.play();
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && this->_energy == false) {
        this->_selection_off++;
        this->_sound.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_off == 1  && this->_energy == false) {
        this->_off = false;
        this->_clock.restart();
        this->_music_principal.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_off == 2  && this->_energy == false)
        return(KeyEvent::EXIT);
}

void SFML::init_off()
{
    this->_music_principal.stop();
    this->_music1.stop();
    this->_music2.stop();
    this->_music3.stop();
    this->_music4.stop();
    this->_music5.stop();
    this->_music6.stop();
    this->_music7.stop();
    sf::Time Time = this->_clock.getElapsedTime();
    float m = Time.asSeconds();
    if (m < 3)
        init_element("assets/borne/end.jpg", 630, 120, 2.f, 2.f, 0, 0);
    else {
        this->_Renderwindow->draw(init_text("ON", 300, 910, 80, sf::Color::Green));
        this->_Renderwindow->draw(init_text("X", 500, 935, 80, sf::Color::Red));
        if (this->_selection_off == 1 && this->_energy == false)
            this->_Renderwindow->draw(init_text("ON", 310, 910, 80, sf::Color::Red));
        else if (this->_selection_off == 2 && this->_energy == false)
            this->_Renderwindow->draw(init_text("X", 510, 935, 80, sf::Color::Green));
        if (this->_selection_off > 3)
            this->_selection_off = 1;
        if (this->_selection_off < 0)
            this->_selection_off = 2;
    }
}

void SFML::event_option()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
        this->_music1.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music_principal.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
        this->_music_principal.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music1.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music2.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music2.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music3.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music4.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music6.stop();
        this->_music7.stop();
        this->_music5.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music7.stop();
        this->_music6.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
        this->_music_principal.stop();
        this->_music1.stop();
        this->_music2.stop();
        this->_music3.stop();
        this->_music4.stop();
        this->_music5.stop();
        this->_music6.stop();
        this->_music7.play();
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && this->_option == 1) {
        this->_selection_option--;
        this->_sound.play();
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && this->_option == 1) {
        this->_selection_option++;
        this->_sound.play();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_option == 1 && this->_option == 1) {
        this->_music_principal.setVolume(this->_volume);
        this->_music1.setVolume(this->_volume);
        this->_music2.setVolume(this->_volume);
        this->_music3.setVolume(this->_volume);
        this->_music4.setVolume(this->_volume);
        this->_music5.setVolume(this->_volume);
        this->_music6.setVolume(this->_volume);
        this->_music7.setVolume(this->_volume);
        this->_volume = this->_volume - 5;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_option == 2 && this->_switch_sound == true) {
        this->_music_principal.setVolume(0);
        this->_music1.setVolume(0);
        this->_music2.setVolume(0);
        this->_music3.setVolume(0);
        this->_music4.setVolume(0);
        this->_music5.setVolume(0);
        this->_music6.setVolume(0);
        this->_music7.setVolume(0);
        this->_switch_s = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_option == 2 && this->_switch_sound == false) {
        this->_music_principal.setVolume(this->_volume);
        this->_music1.setVolume(this->_volume);
        this->_music2.setVolume(this->_volume);
        this->_music3.setVolume(this->_volume);
        this->_music4.setVolume(this->_volume);
        this->_music5.setVolume(this->_volume);
        this->_music6.setVolume(this->_volume);
        this->_music7.setVolume(this->_volume);
        this->_switch_s = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_option == 3 && this->_option == 1) {
        this->_music_principal.setVolume(this->_volume);
        this->_music1.setVolume(this->_volume);
        this->_music2.setVolume(this->_volume);
        this->_music3.setVolume(this->_volume);
        this->_music4.setVolume(this->_volume);
        this->_music5.setVolume(this->_volume);
        this->_music6.setVolume(this->_volume);
        this->_music7.setVolume(this->_volume);
        this->_volume = this->_volume + 5;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && this->_selection_option == 4 && this->_option == 1)
        this->_switch_option = false;
}

void SFML::init_option()
{
    this->_Renderwindow->draw(init_text("Press '0' => Borne Music", 150, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '1' => 44bulldog (Pop Smoke)", 200, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '2' => Ghost Killer Track (OBOY)", 250, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '3' => Au DD (PNL)", 300, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '4' => 93% [Tijuana] (GLK)", 350, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '5' => Bande Organisee (Bande Organisee)", 400, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '6' => Day 'N' Nite (Kid Cudi)", 450, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("Press '7' => Pirate (Ninho)", 500, 470, 30, sf::Color::Yellow));
    this->_Renderwindow->draw(init_text("X", 720, 1350, 80, sf::Color::Red));
    this->_Renderwindow->draw(init_text("-", 600, 570, 100, sf::Color::White));
    this->_Renderwindow->draw(init_text("+", 600, 850, 100, sf::Color::White));
    if (this->_switch_sound == true)
        init_element("assets/borne/sound_on.png", 650, 600, 1.f, 1.f, 0, 0);
    if (this->_switch_sound == false)
        init_element("assets/borne/sound_off.png", 650, 600, 1.f, 1.f, 0, 0);
    if (this->_selection_option == 1 && this->_option == 1)
        this->_Renderwindow->draw(init_text("-", 600, 570, 100, sf::Color::Green));
    if (this->_selection_option == 2 && this->_option == 1 && this->_switch_sound == true)
        element_sound("assets/borne/sound_on.png", 650, 600, 1.f, 1.f);
    if (this->_selection_option == 2 && this->_option == 1 && this->_switch_sound == false)
        element_sound("assets/borne/sound_off.png", 650, 600, 1.f, 1.f);
    if (this->_selection_option == 3 && this->_option == 1)
        this->_Renderwindow->draw(init_text("+", 600, 850, 100, sf::Color::Green));
    if (this->_selection_option == 4 && this->_option == 1)
        this->_Renderwindow->draw(init_text("X", 730, 1350, 80, sf::Color::Green));
    if (this->_selection_option > 4)
        this->_selection_option = 1;
    if (this->_selection_option < 0)
        this->_selection_option = 4;
}

bool SFML::isOpened()
{
    return (this->_Renderwindow->isOpen());
}

void SFML::close()
{
    this->_music1.stop();
    this->_music2.stop();
    this->_music3.stop();
    this->_music4.stop();
    this->_music5.stop();
    this->_music6.stop();
    this->_music7.stop();
    this->_music_principal.stop();
	this->_Renderwindow->close();
    this->_Renderwindow->close();
}

KeyEvent SFML::event_game()
{
    static KeyEvent save = KeyEvent::MOVERIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && save != sf::Keyboard::Q) {
        this->_e_game = 1;
        save = KeyEvent::MOVERIGHT;
        return (KeyEvent::MOVERIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && save != sf::Keyboard::D) {
        this->_e_game = 2;
        save = KeyEvent::MOVELEFT;
        return (KeyEvent::MOVELEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && save != sf::Keyboard::S) {
        this->_e_game = 3;
        save = KeyEvent::MOVEUP;
        return (KeyEvent::MOVEUP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && save != sf::Keyboard::Z) {
        this->_e_game = 4;
        save = KeyEvent::MOVEDOWN;
        return (KeyEvent::MOVEDOWN);
    }
    return save;
}

void SFML::display_game()
{
    if (this->_choice_game == 2) {
        init_element("assets/nibbler/background.png", 630, 130, 1.f, 1.f, 0, 0);
        this->_Renderwindow->draw(init_text(std::to_string(this->_score), 120, 1380, 90, sf::Color::White));
        init_element("assets/nibbler/fruit.png", this->_obj.x * 43.4 + 630, this->_obj.y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        if (this->_e_game == 0)
            init_element("assets/nibbler/head_right.png", this->_caractere.back().x * 43.4 + 630, this->_caractere.back().y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        if (this->_e_game == 1 && this->_e_game != 2)
            init_element("assets/nibbler/head_right.png", this->_caractere.back().x * 43.4 + 630, this->_caractere.back().y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        else if (this->_e_game == 2 && this->_e_game != 1)
            init_element("assets/nibbler/head_left.png", this->_caractere.back().x * 43.4 + 630, this->_caractere.back().y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        else if (this->_e_game == 3 && this->_e_game != 4)
            init_element("assets/nibbler/head_up.png", this->_caractere.back().x * 43.4 + 630, this->_caractere.back().y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        else if (this->_e_game == 4 && this->_e_game != 3)
            init_element("assets/nibbler/head_down.png", this->_caractere.back().x * 43.4 + 630, this->_caractere.back().y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
        for (int i = 0; i < this->_caractere.size() - 1; i++)
            init_element("assets/nibbler/skin.png", this->_caractere.at(i).x * 43.4 + 630, this->_caractere.at(i).y * 43.4 + 130, 2.6f, 2.6f, 0, 0);
    }
    else if (this->_choice_game == 1) {
        std::cout << "pacman" << std::endl;
    }
}

extern "C" ILibrary *create_library()
{
	return (new SFML());
}

extern "C" void destroy_library(ILibrary *library)
{
	delete (library);
}