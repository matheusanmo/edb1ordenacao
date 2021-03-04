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


/**
 * ordenacao nao precisa ser estrita
 */
bool is_ascending(unsigned int* first, unsigned int* last) {
    unsigned int last_num = *first++;
    while (first != last) {
        unsigned int new_num = *first++;
        if (new_num < last_num) {
            return false;
        }
        last_num = new_num;
    }
    return true;
}

void print_array(unsigned int* first, unsigned int* last) {
    while (first != last)
        cout << *first++ << endl;
    return;
}

int main() {
    int array_size{};
    cin >> array_size;
    unsigned int* new_array = new_random_array(array_size);
    print_array(new_array, &new_array[array_size]);
    cout << is_ascending(&new_array[0], &new_array[array_size]);

    delete[] new_array;
    new_array = nullptr;
}

