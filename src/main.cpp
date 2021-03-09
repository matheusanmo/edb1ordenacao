#include "uint.h"
#include "vecfacilities.h"
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
    vector<uint> vec = gen_random_uniform(n, 1000);
    print_vector(vec);
    cout << is_increasing(vec) << endl << endl;
    shell_sort(vec);
    print_vector(vec);
    cout << is_increasing(vec) << endl << endl;
    return 0;
}

