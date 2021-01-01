#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "vector.h"
#include "list.h"

int main(int args, char *argv[]) {
    dsa::vector<int> vect(0);
    for (int i = 0; i < 20; ++i) {
        vect.add_back(i);
    }
    vect.shrink_to_fit();
    for (int i = 0; i < vect.length(); ++i) {
        std::cout << vect.get_at(i) << " ";
    }
    std::cout << std::endl;
}
