#include <algorithm> // remove_copy
#include <vector>

#include "optimisticMedian.h"

typedef std::vector<double>::size_type vec_sz;

// Takes the median of HW from submitted homework grades
double optimisticMedian (std::vector<double> vec){
    std::vector<double> nonzero;

    // Any value in passed vector that is not equal to value "0" is copied into new vector "nonzero"
    remove_copy(vec.begin(), vec.end(), back_inserter(nonzero), 0);

    vec_sz homeworkDone = nonzero.size();
    vec_sz middle = homeworkDone / 2;
    if (homeworkDone == 0)
        return 0;
    else
        return homeworkDone % 2 == 0 ? (vec[(middle) - 1] + vec[middle]) / 2 : vec[middle];
}
