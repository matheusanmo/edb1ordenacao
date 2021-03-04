#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

unsigned int* new_random_array(int n) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<unsigned int> dist{};
    unsigned int* new_array = new unsigned int[n];
    if (new_array == nullptr) {
        cout << "new_random_array nao conseguiu alocar espaco para array" << endl;
        return nullptr;
    }
    for (int i = 0; i < n; i++) {
        new_array[i] = dist(mt);
    }
    return new_array;
}

int main() {
    int array_size{};
    cin >> array_size;
    unsigned int* new_array = new_random_array(array_size);
    for (int i = 0; i < array_size; i++)
        cout << new_array[i] << endl;
    delete[] new_array;
    new_array = nullptr;
}

