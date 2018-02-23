#include <numeric> // accumulate
#include <vector>

#include "average.h"

double average(const std::vector<double>& vec){
    return (accumulate(vec.begin(), vec.end(), 0) / vec.size());
}
