/*
** EPITECH PROJECT, 2020
** Indie.hpp
** File description:
** Indie header file
*/

#ifndef Indie_H_
#define Indie_H_

#ifndef PERC
#define PERC(width, height, x, y) (std::make_pair(x / 100 * width, y / 100 * height))
#endif

namespace Indie {
    enum KeyEvent {
        MOVE_UP,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        ACTION,
        PAUSE,
        ENTER,
        NONE,
    };

    enum EventType {
        EVENT_KEY,
        EVENT_WINDOW,
        EVENT_NONE,
    };

    struct Event {
        EventType type;
        KeyEvent keyEvent;
    };
}

#endif
