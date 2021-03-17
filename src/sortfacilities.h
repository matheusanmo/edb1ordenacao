#ifndef SORTFACILITIES_H
#define SORTFACILITIES_H

#include "uint.h"

#include <vector>
using std::vector;

double time_sorts_mean (
        void         (*sort_fun)(vector<uint>&),
        vector<uint> (*vec_gen)(int),
        int          vec_size,
        int          run_count = 20);
void   selection_sort  (vector<uint> &vec);
void   insertion_sort  (vector<uint> &vec);
void   bubble_sort     (vector<uint> &vec);
void   merge_sort      (vector<uint> &vec);
void   shell_sort      (vector<uint> &vec);
void   quick_sort      (vector<uint> &vec);

#endif

