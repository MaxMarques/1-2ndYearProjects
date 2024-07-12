/*
** EPITECH PROJECT, 2020
** IndieError.hpp
** File description:
** IndieError header file
*/

#ifndef IndieError_H_
#define IndieError_H_

#include <exception>
#include <ostream>
#include <string>

namespace Indie::Errors {
    class IndieError : public std::exception {
        public:
            IndieError(
                const std::string &message,
                const std::string &function,
                const std::string &context
            );

            const char *what() const noexcept;

            std::string getContext() const;
            std::string getFunction() const;
        protected:
            std::string _function;
            std::string _message;
            std::string _context;
    };
}

std::ostream &operator<<(std::ostream &os, const Indie::Errors::IndieError &err);

#endif
