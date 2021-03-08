#include "uint.h"
#include "vecfacilities.h"
#include "timefacilities.h"
#include "sorts.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

int main() {
    int n{};
    cin >> n;
    vector<uint> vec = gen_random_uniform(n);
    for (auto const &x : vec) {
        cout << x << endl;
    }
    cout << endl;
    vector<uint> vec2 = gen_random_preordered(n, 0.75);
    for (auto const &x : vec2) {
        cout << x << endl;
    }
    return 0;
}

