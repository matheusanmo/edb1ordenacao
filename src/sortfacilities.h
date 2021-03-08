#ifndef SORTFACILITIES_H
#define SORTFACILITIES_H

#include "uint.h"

#include <vector>
using std::vector;

vector<uint> vec_empty (0);

double time_sorts_mean (
        void         (*sort_fun)(vector<uint>&),
        vector<uint> (*vec_gen)(int),
        int          vec_size,
        int          run_count);
void   selection_sort  (vector<uint> &vec);
void   insertion_sort  (vector<uint> &vec);
void   bubble_sort     (vector<uint> &vec);
void   shell_sort      (vector<uint> &vec, vector<uint> gaps_sequence = vec_empty);

#endif

