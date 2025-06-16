#ifndef POLISHSTRING_HPP
#define POLISHSTRING_HPP

#include <string>

bool precedence(char operator1, char operator2);

std::string infixToPostfix(std::string infix);

std::string infixToPrefix(std::string infix);

#endif
