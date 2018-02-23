#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s){
    if (is){
        is >> s.name >> s.midterm >> s.final;
        read_hw(is, s.homework);

        /* This try/catch is for grading as we read
        try {
            s.finalGrade = grade(s.midterm, s.final, homework);
        } catch (std::domain_error e){
            s.finalGrade = -1;
        } */

    }
    return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw){
    if (in){
        hw.clear();
        double x;
        while(in >> x)
            hw.push_back(x);
    in.clear();
    }
    return in;
}


