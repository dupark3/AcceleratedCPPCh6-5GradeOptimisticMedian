#include <stdexcept>
#include <vector>

#include "Student_info.h"

#include "grade.h"
#include "optimisticMedian.h"
#include "median.h"
#include "average.h"

double grade_optimistic_median(const Student_info& s){
    try {
        return grade(s.midterm, s.final, s.homework, optimisticMedian);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double grade_median(const Student_info& s){
    try {
        return grade(s.midterm, s.final, s.homework, median);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double grade_average(const Student_info& s){
    try {
        return grade(s.midterm, s.final, s.homework, average);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double grade(double midterm, double final, const std::vector<double>& homework, double calculateHW(const std::vector<double>&)){
    if (homework.size() == 0)
        throw std::domain_error("No homework grades");
    return grade(midterm, final, calculateHW(homework));
}

double grade(double midterm, double final, double homework){
    return (midterm * 0.2 + final * 0.4 + homework * 0.4);
}
