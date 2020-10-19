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
        Vector<int> vect;
        for (int i = 0; i < 15; ++i) {
            vect.PushBack(i);
        }
        vect.Insert(3, 89);
        for (int i = 0; i < 16; ++i) {
            std::cout << vect.At(i) << std::endl;
        }
    } while (false);
    return 0;
}