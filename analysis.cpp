#include <algorithm> // transform
#include <iostream>
#include <iterator>
#include <list>

#include "Student_info.h"

void write_analysis(std::ostream& out,
                    const std::list<Student_info>& didHw,
                    const std::list<Student_info>& didNotHw)
{
    // Take the did/didnot list of students and pass it to analysis
    // Also pass to analysis what kind of calculation we will do with the homework
    // Grade will take the type of hw calculation and output a double grade using that hw calculation
    // We will transform the list of Student_info to list of doubles
    out <<
    "Students who did all HW (Median of HW):                                    " << analysis(didHw, grade_median) << std::endl <<
    "Students who did not do all HW (Median of HW):                             " << analysis(didNotHw, grade_median) << std::endl <<
    "Students who did all HW (Optimistic Median of HW, ignoring zeroes:         " << analysis(didHw, grade_optimistic_median) << std::endl <<
    "Students who did not do all HW (Optimistic Median of HW, ignoring zeroes): " << analysis(didNotHw, grade_optimistic_median) << std::endl <<
    "Students who did all HW (Average of HW):                                   " << analysis(didHw, grade_average) << std::endl <<
    "Students who did not do all HW (Average of HW):                            " << analysis(didNotHw, grade_average) << std::endl <<
}

double analysis (const std::list<Student_info>& students, double calculateGrade(const std::vector<double>&)){
    std::list<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), calculateGrade);
    return median(grades);
}
