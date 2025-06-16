#include "stack.hpp"
#include "../string.hpp"
#include <stdexcept>
#include <string>

// Here '^' is treated as the exponentiation operator

bool precedence(char operator1, char operator2)
{
    if (operator1 == '+' or operator1 == '-')
    {
        if (operator2 == '+' or operator2 == '-')
            return true;
        else
            return false;
    }
    else if (operator1 == '*' or operator1 == '/')
    {
        if (operator2 == '^')
            return false;
        else
            return true;
    }
    else if (operator1 == '^')
        return true;
    else
        throw std::invalid_argument("This is not an arithmetic operator.");
}

std::string infixToPostfix(std::string infix)
{
    std::string postfix = "";
    auto *stack = new Stack<char>();

    // Traversing the infix string
    for (char i : infix)
    {
        if (i == '(' or i == '{' or i == '[')
            stack->push(i);

        else if (i == ')')
        {
            while (stack->peek() != '(')
            {
                if (stack->peek() == '{' or stack->peek() == '[')
                    throw std::invalid_argument("The infix expression has incorrect bracket order");
                postfix += stack->pop();
            }
            stack->pop();
        }
        else if (i == '}')
        {
            while (stack->peek() != '{')
            {
                if (stack->peek() == '(' or stack->peek() == '[')
                    throw std::invalid_argument("The infix expression has incorrect bracket order");
                postfix += stack->pop();
            }
            stack->pop();
        }
        else if (i == ']')
        {
            while (stack->peek() != '[')
            {
                if (stack->peek() == '(' or stack->peek() == '{')
                    throw std::invalid_argument("The infix expression has incorrect bracket order");
                postfix += stack->pop();
            }
            stack->pop();
        }

        else if (i == '+' or i == '-' or i == '*' or i == '/' or i == '^')
        {
            if (stack->isEmpty())
                stack->push(i);
            else if (stack->peek() == '(' or stack->peek() == '{' or stack->peek() == '[')
                stack->push(i);
            else
            {
                if (precedence(stack->peek(), i))
                {
                    postfix += stack->pop();
                    stack->push(i);
                }
                else
                    stack->push(i);
            }
        }

        else if (i == ' ')
            continue;

        else
            postfix += i;
    }

    while (not stack->isEmpty())
        postfix += stack->pop();

    return postfix;
}

std::string infixToPrefix(std::string infix)
{
    infix = reverse(infix);

    // Alternating brackets
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == '{')
            infix[i] = '}';
        else if (infix[i] == '[')
            infix[i] = ']';
        else if (infix[i] == ')')
            infix[i] = '(';
        else if (infix[i] == '}')
            infix[i] = '{';
        else if (infix[i] == ']')
            infix[i] = '[';
    }

    std::string prefix = infixToPostfix(infix);
    prefix = reverse(prefix);
    return prefix;
}
