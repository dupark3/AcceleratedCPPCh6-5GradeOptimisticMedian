#include <stdexcept>
#include <vector>

#include "grade.h"
#include "optimisticMedian.h"
#include "Student_info.h"
double grade(const Student_info& s, double calculateHW(const std::vector<double>&)){
    return grade(s.midterm, s.final, s.homework, calculateHW);
}

double grade(double midterm, double final, const std::vector<double>& homework, double calculateHW(const std::vector<double>&)){
    if (homework.size() == 0)
        throw std::domain_error("No homework grades");
    return grade(midterm, final, calculateHW(homework));
}

double grade(double midterm, double final, double homework){
    return (midterm * 0.2 + final * 0.4 + homework * 0.4);
}
