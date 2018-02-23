#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade_optimistic_median(const Student_info&);
double grade_median(const Student_info&);
double grade_average(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);

#endif // GUARD_grade_h

