#include <algorithm> // remove_copy, sort
#include <vector>

#include "optimisticMedian.h"

typedef std::vector<double>::size_type vec_sz;

// Takes the median of HW from submitted homework grades
double optimisticMedian (const std::vector<double>& vec){
    // Any value in passed vector that is not equal to value "0" is copied into new vector "nonzero"
    std::vector<double> nonzero;
    remove_copy(vec.begin(), vec.end(), back_inserter(nonzero), 0);

    sort(nonzero.begin(), nonzero.end());
    vec_sz homeworkDone = nonzero.size();
    vec_sz middle = homeworkDone / 2;

    // if no homework done, return 0 for homework grade
    if (homeworkDone == 0)
        return 0;
    // some homework done: if even, take average of middle two values, if odd, take middle value
    else
        return homeworkDone % 2 == 0 ? (nonzero[(middle) - 1] + nonzero[middle]) / 2 : nonzero[middle];
}
