#include <iostream>

#include "Vector.hpp"
#include "List.hpp"

int main(int args, char *argv[])
{
    DS::Vector<int> vect(0);

    for (int i = 0; i < 20; ++i)
    {
        vect.AddBack(i);
    }

    vect.ShrinkToFit();

    for (int i = 0; i < vect.Length(); ++i)
    {
        std::cout << vect.At(i) << " ";
    }

    std::cout << std::endl;
    return 0;
}
