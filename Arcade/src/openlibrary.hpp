/*
** EPITECH PROJECT, 2021
** openlibrary
** File description:
** openlibrary.hpp
*/

#ifndef _OPENLIBRARY_
#define _OPENLIBRARY_

#include <iostream>
#include <dlfcn.h>

class Openlibrary  {
    public:
        Openlibrary();
        ~Openlibrary();

        void *LoadLib(std::string library);
        void CloseLib(void *library);
        void *getLib(void *library, const std::string name);
};

#endif