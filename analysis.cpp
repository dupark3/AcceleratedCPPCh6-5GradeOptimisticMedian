#include "Student_info.h"

void write_analysis(std::ostream& out,
                    const std::list<Student_info>& didHw,
                    const std::list<Student_info>& didNotHw)
{
    out <<
    "Students who did all HW (Median of HW):                                    " << std::endl <<
    "Students who did not do all HW (Median of HW):                             " << std::endl <<
    "Students who did all HW (Optimistic Median of HW, ignoring zeroes:         " << analysis(didHw, optimisticMedian) << std::endl <<
    "Students who did not do all HW (Optimistic Median of HW, ignoring zeroes): " << analysis(didNotHw, optimisticMedian) << std::endl <<
    "Students who did all HW (Average of HW):                                   " << std::endl <<
    "Students who did not do all HW (Average of HW):                            " << std::endl <<
}

double analysis (const std::list<Student_info>& students, double calculateHW(const std::vector<double>&)){
    // output : median of final grades
    // input: vector of Students, function for grade calculation
    // grade() has to take what kind of homework calculation it will do
    std::vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), calculateHW);
    return median(grades);
}
