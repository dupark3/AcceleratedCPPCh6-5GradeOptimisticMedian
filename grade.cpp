#include <stdexcept>
#include <vector>

#include "grade.h"

#include "optimisticMedian.h"
#include "median.h"
#include "average.h"
#include "Student_info.h"

double grade_optimistic_median(const Student_info& s){
    return grade(s.midterm, s.final, optimisticMedian(s.homework));
}

double grade_median(const Student_info& s){
    return grade(s.midterm, s.final, median(s.homework));
}

double grade_average(const Student_info& s){
    return grade(s.midterm, s.final, average(s.homework));
}

/*
double grade(double midterm, double final, const std::vector<double>& homework){
    if (homework.size() == 0)
        throw std::domain_error("No homework grades");
    return grade(midterm, final, (homework));
}
*/

double grade(double midterm, double final, double homework){
    return (midterm * 0.2 + final * 0.4 + homework * 0.4);
}
