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
    //double dt = time_sorts_mean(&selection_sort, &gen_random_uniform, 1000, 25);
    int n{};
    cin >> n;
    auto vec =gen_random_uniform(n);
    cout << is_increasing(vec) << endl;
    selection_sort(vec);
    cout << is_increasing(vec) << endl;
    return 0;
}

