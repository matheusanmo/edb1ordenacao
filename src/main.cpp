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
    double dt = time_sorts_mean(&merge_sort, &gen_random_uniform, 10000);
    cout << dt << "ms" << endl;
    return 0;
}

