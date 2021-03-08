#ifndef VECFACILITIES_H
#define VECFACILITIES_H

#include "uint.h"

#include <vector>
using std::vector;

vector<uint> gen_random_uniform        (const int n, uint max_bound = 0);
vector<uint> gen_random_non_increasing (const int n);
vector<uint> gen_random_non_decreasing (const int n);
vector<uint> gen_random_preordered     (const int n, double p);
bool         is_increasing             (vector<uint> const &vec);
void         print_vector              (vector<uint> const &vec);

#endif
