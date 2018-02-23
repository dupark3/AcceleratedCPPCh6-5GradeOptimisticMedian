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
        double midterm, final;
        std::vector<double> homework;

        is >> s.name >> midterm >> final;
        read_hw(is, homework);

        try {
            s.final_grade = grade(midterm, final, homework);
        } catch (std::domain_error e){
            s.final_grade = -1;
        }

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


