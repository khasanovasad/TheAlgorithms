#include <iostream>

#include "List.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Vector.hpp"

int main(int args, char* argv[])
{
    DS::Queue<std::string> que;

    for (int i = 0; i < 10; ++i)
    {
        que.Push(std::to_string(i) + " FAKK ");
    }

    for (int i = 0; i < 15; ++i)
    {
        std::cout << que.Front() << std::endl;
        que.Pop();
    }
    return 0;
}
