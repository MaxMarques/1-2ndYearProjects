/*
** EPITECH PROJECT, 2021
** openlibrary
** File description:
** openlibrary.cpp
*/

#include "openlibrary.hpp"

Openlibrary::Openlibrary()
{
}

Openlibrary::~Openlibrary()
{
}

void *Openlibrary::LoadLib(std::string library)
{
    void *lib = dlopen(library.c_str(), RTLD_LAZY);

    if (lib == nullptr) {
        std::cerr << "Wrong Library : " << dlerror() << std::endl;
        return(NULL);
    }
    dlerror();
    return lib;
}

void Openlibrary::CloseLib(void *library)
{
    dlclose(library);
}

void *Openlibrary::getLib(void *library, const std::string name)
{
    void *lib = dlsym(library, name.c_str());
    
    if (lib == nullptr)
        std::cerr << "Error while loading function : " << dlerror() << std::endl;
    
    return lib;
}