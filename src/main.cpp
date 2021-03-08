#include "uint.h"
#include "vecfacilities.h"
#include "timefacilities.h"
#include "sortfacilities.h"

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

    auto dt = time_sort<uint>(&selection_sort<uint>, vec);

    cout << dt;

    return 0;
}

