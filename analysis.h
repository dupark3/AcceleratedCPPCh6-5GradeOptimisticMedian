#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <iostream>
#include <list>
#include <vector>
#include "Student_info.h"

void write_analysis(std::ostream&, const std::list<Student_info>&, const std::list<Student_info>&);
double analysis(const std::list<Student_info>&, double calculateGrade(const Student_info&));

#endif // GUARD_analysis_h
