#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student_info{
    std::string name;
    std::vector<double> homework;
    double finalGrade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif // GUARD_Student_info_h

