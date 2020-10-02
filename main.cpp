#include <iostream>
#include <string>

#include "SLinkedList.h"
#include "DLinkedList.h"

void Foo(int size) {
    // creating the array
    int **arr = new int*[size];
    for (int i = 0; i < size; ++i)
        arr[i] = new int[size];

    // setting up the array
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j)
            arr[i][j] = -1;
        arr[i][i] = 0;
        for (int j = i + 1; j < size; ++j)
            arr[i][j] = 1;
    }
    
    // printing the array
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == -1)
                std::cout << arr[i][j];
            else 
                std::cout << " " << arr[i][j];
        }
        std::cout << std::endl;
    }

    // free memory
    for (int i = 0; i < size; ++i)
        delete[] arr[i];
    delete[] arr;

int main(int args, char *argv[]) {
    do {
        int size = std::stoi(argv[1]);
        Foo(size);
    } while (true);
    /*
    DLinkedList<std::string> d_list1 = { "zero", "one", "two", "three", "four" };
    DLinkedList<std::string> d_list2 = d_list1;
    for (int i = 0; i < d_list2.Count(); ++i) {
        std::cout << d_list2.ElementAt(i) << " ";
    }
    std::cout << std::endl;
    */
    return 0;
}
