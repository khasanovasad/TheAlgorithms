#include <iostream>
#include <string>
#include <vector>

#include "SLinkedList.h"
#include "DLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "Vector.h"

using namespace DSCpp;

int main(int args, char *argv[]) {
    do {
        Vector<std::string> vect(20, "sex");
        // vect.Clear();
        vect.Erase(0, vect.Size());
        std::cout << vect.Front() << std::endl;
    } while (false);
    return 0;
}