#include <stdexcept>
#include <vector>

#include "grade.h"
#include "optimisticMedian.h"
#include "Student_info.h"

double grade(double midterm, double final, const std::vector<double>& homework){
    if (homework.size() == 0)
        throw std::domain_error("No homework grades");
    return grade(midterm, final, optimisticMedian(homework));
}

double grade(double midterm, double final, double homework){
    return (midterm * 0.2 + final * 0.4 + homework * 0.4);
}
