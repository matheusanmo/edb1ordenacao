#include "uint.h"
#include "vecfacilities.h"
#include "sortfacilities.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

int main(int argc, char* argv[]) {
    // double dt = time_sorts_mean(&quick_sort, &gen_random_uniform, 10000);
    // cout << dt << "ms" << endl;
    for (int i = 2; i < 100000; i*=k) {
        vector<uint> vec = gen_random_uniform(i);
        quick_sort(vec);
        cout << std::boolalpha << is_increasing(vec) << " " << i << endl;
    }
    return 0;
}

