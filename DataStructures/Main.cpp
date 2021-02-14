#include <iostream>

#include "Vector.hpp"
#include "List.hpp"
#include "Stack.hpp"

int main(int args, char *argv[])
{
    DS::Stack<std::string> stackk;

    for (int i = 0; i < 10; ++i)
    {
        stackk.Push(std::to_string(i) + " FAAK ");
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << stackk.Top() << std::endl;
        stackk.Pop();
    }

    return 0;
}
