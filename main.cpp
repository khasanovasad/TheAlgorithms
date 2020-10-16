#include <iostream>
#include <string>

#include "SLinkedList.h"
#include "DLinkedList.h"
#include "Stack.h"

using namespace DSCpp;

int main(int args, char *argv[]) {
    do {
        Stack<std::string> myStack; 

        std::cout << "Pushing...\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << i << "\n";
            myStack.Push(std::to_string(i)); 
        }

        std::cout << "\nTop: " << myStack.Top() << "\n\n";

        std::cout << "Popping...\n";
        int size = myStack.Count();
        for (int i = 0; i < size; ++i) {
            std::cout << myStack.Pop() << "\n";
        }
    } while (false);
    return 0;
}