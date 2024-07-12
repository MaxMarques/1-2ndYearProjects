/*
** EPITECH PROJECT, 2021
** core_ncurses
** File description:
** core_ncurses.cpp
*/

#include "core_ncurses.hpp"

Ncurses::Ncurses()
{
	this->_switch_game = 0;
}

Ncurses::~Ncurses()
{

}

static const std::vector<std::string> title = {
	" ________  ________  ________  ________  ________  _______      ",
	"|\\   __  \\|\\   __  \\|\\   ____\\|\\   __  \\|\\   ___ \\|\\  ___ \\     ",
	"\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\_|\\ \\ \\   __/|    ",
	" \\ \\   __  \\ \\   _  _\\ \\  \\    \\ \\   __  \\ \\  \\ \\\\ \\ \\  \\_|/__  ",
	"  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\____\\ \\  \\ \\  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\ ",
	"   \\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\_______\\ \\__\\ \\__\\ \\_______\\ \\_______\\",
	"    \\|__|\\|__|\\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|\\|_______|"
};

void Ncurses::setGameMap(const std::vector<std::vector<int>> &)
{
	
}

void Ncurses::set_pos_caractere(std::vector<caractere_pos_t> pos)
{
	
}

void Ncurses::set_pos_obj(obj_pos_t pos)
{

}

void Ncurses::setScore(unsigned int score)
{
    this->_score = score;
}

std::string Ncurses::getName() const
{
	return ("SFML");
}

void Ncurses::init(const std::vector<std::string> &graphLib, const std::vector<std::string> &gameLibs)
{
	this->_open = true;
	this->_window = initscr();
	this->_background = {
		{ 0, 0, nullptr, 100, 17 },
		{ 0, 17, nullptr, 20, 50 },
		{ 20, 17, nullptr, 60, 50 },
		{ 80, 17, nullptr, 20, 50 },
		{ 0, 67, nullptr, 100, 35 }
	};
	for (auto &i : this->_background) {
		auto surface = this->get_position(i.width, i.height, this->_window);
		auto position = this->get_position(i.x, i.y, this->_window);
		i.w = subwin(this->_window, surface.second, surface.first, position.second, position.first);
	}
	cbreak();
    noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
}

void Ncurses::update()
{
}

KeyEvent Ncurses::getKeyEvent()
{
	int touch = wgetch(this->_window);
	switch (touch) {
		case 27:
		return (KeyEvent::EXIT);
		case KEY_UP:
		return (KeyEvent::LIBSFML);
		case KEY_DOWN:
		return (KeyEvent::LIBSDL);
		case KEY_LEFT:
		return (KeyEvent::NIBBLER);
		case KEY_RIGHT:
		return (KeyEvent::PACMAN);
	}
}

void Ncurses::display()
{
	clear();
	for (const auto &i : this->_background) {
        wclear(i.w);
        wborder(i.w, '|', '|', '-', '-', '/', '\\', '\\', '/');
        wrefresh(i.w);
    }
	auto titre = this->get_position(50, 12, this->_background.at(0).w);
	for (const auto &i : title)
		mvwprintw(this->_background.at(0).w, titre.second++, titre.first - (30), "%s", i.c_str());
	this->draw_text(36, 5, this->_background.at(1).w, "Library:");
	this->draw_text(15, 40, this->_background.at(1).w, "arcade_sfml.so");
	this->draw_text(15, 45, this->_background.at(1).w, "arcade_sdl2.so");
	this->draw_text(40, 5, this->_background.at(3).w, "Game:");
	this->draw_text(10, 40, this->_background.at(3).w, "arcade_nibbler.so");
	this->draw_text(15, 45, this->_background.at(3).w, "arcade_pacman.so");
	this->draw_text(50, 7, this->_background.at(4).w, "Rules:");
	this->draw_text(20, 20, this->_background.at(4).w, "~Borne~");
	this->draw_text(10, 30, this->_background.at(4).w, "Press 'echap' => exit program");
	this->draw_text(10, 40, this->_background.at(4).w, "Press 'r' => reload game");
	this->draw_text(10, 50, this->_background.at(4).w, "Press 'UP' => start SFML");
	this->draw_text(10, 60, this->_background.at(4).w, "Press 'DOWN' => start SDL2");
	this->draw_text(10, 70, this->_background.at(4).w, "Press 'LEFT' => start Nibbler");
	this->draw_text(10, 80, this->_background.at(4).w, "Press 'RIGHT' => start Pacman");
	this->draw_text(70, 20, this->_background.at(4).w, "~Pacman & Nibbler~");
	this->draw_text(71, 40, this->_background.at(4).w, "Press 'z' => up");
	this->draw_text(71, 50, this->_background.at(4).w, "Press 's' => down");
	this->draw_text(71, 60, this->_background.at(4).w, "Press 'd' => right");
	this->draw_text(71, 70, this->_background.at(4).w, "Press 'q' => left");
	refresh();
}

bool Ncurses::isOpened()
{
    return(this->_open);
}

void Ncurses::close()
{
	this->_open = false;
    for (const auto &i : this->_background) {
        delwin(i.w);
    }
	endwin();
}

std::pair<int, int> Ncurses::get_position(float with, float height, WINDOW* w)
{
	int x = 0;
	int y = 0;

	getmaxyx(w, y, x);
	
	return (std::make_pair((with / 100) * (float)x, (height / 100) * (float)y));
}

void Ncurses::draw_text(int x, int y, WINDOW* w, std::string txt)
{
	auto position = this->get_position(x, y, w);
	mvwprintw(w, position.second, position.first, "%s", txt.c_str());
}

extern "C" ILibrary *create_library()
{
	return (new Ncurses());
}

extern "C" void destroy_library(ILibrary *library)
{
	delete (library);
}