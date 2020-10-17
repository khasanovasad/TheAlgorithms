#include <iostream>
#include <string>

#include "SLinkedList.h"
#include "DLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

using namespace DSCpp;

int main(int args, char *argv[]) {
    /*
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
    */
    /*
    do {
        Queue<int> myQueue;

        std::cout << "Pushing...\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << i << "\n";
            myQueue.Push(i);
        }

        std::cout << "\nFront: " << myQueue.Front() << "\n";
        std::cout << "Back: " << myQueue.Back() << "\n\n";

        std::cout << "Popping...\n";
        int size = myQueue.Count();
        for (int i = 0; i < size; ++i) {
            std::cout << myQueue.Pop() << "\n";
        }
    } while (true);
    */
    do {
        Deque<int> myDeque;

        std::cout << "PushFront...\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << i << "\n";
            myDeque.PushFront(i);
        }

        std::cout << "\nFront: " << myDeque.Front() << "\n";
        std::cout << "Back: " << myDeque.Back() << "\n\n";

        std::cout << "PopBack...\n";
        int size = myDeque.Count();
        for (int i = 0; i < size; ++i) {
            std::cout << myDeque.PopBack() << "\n";
        }
    } while (false);
    return 0;
}