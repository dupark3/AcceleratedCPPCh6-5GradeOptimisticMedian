/*
Accelerated C++ Exercise 6-5
Write an analysis function to call optimistic_median
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#include "extract_fail.h"
#include "grade.h"
#include "Student_info.h"

typedef std::list<Student_info> container;
typedef std::list<Student_info>::iterator container_size;

int main(){
    // Uses List to contain student records for optimized insertion/deletion
    container students;
    // Student info struct contains data string "name" and grade double "finalGrade"
    Student_info record;

    std::cout << "Enter student name, midterm, final, and all homework grades below." << std::endl;

    // Passes the console input and the temporary struct "record" to hold read values until it is appended to our vector
    while(read(std::cin, record)){
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Compare predicate uses "name" of student data, as defined in Student_info.cpp
    students.sort(compare);

    // Extract students who failed and store in container
    container fails;
    container_size i = students.begin();
    container_size countPassing = 0;
    while (i != students.end()){
        if (extract_fail(i->finalGrade)){
            fails.push_back(*i);
            ++i;
        } else {
            students.push_front(*i);
            ++i;
            ++countPassing;
        }
    }

    // Resize the original vector by how many passing students have been copied to the front of the vector
    students.resize(countPassing);
    students.sort(compare);

    // Print passing students in original container (fails have been extracted)
    std::cout << "PASSING STUDENTS:" << std::endl;
    for (container_size i = students.begin(); i!= students.end(); ++i){
        // Print name then appropriate spaces (COULD USE WIDTH AND SETW??)
        std::cout << i->name
                  << std::string(maxlen + 1 - (i->name).size(), ' ');

        std::streamsize prec = std::cout.precision();
        std::cout << std::setprecision(3)
                  << i->finalGrade
                  << std::setprecision(prec)
                  << std::endl;
    }

    std::cout << std::endl << "FAILING STUDENTS (under 60):" << std::endl;
    for (container_size i = fails.begin(); i!= fails.end(); ++i){
        // Print name then appropriate spaces (COULD USE WIDTH AND SETW??)
        std::cout << i->name
                  << std::string(maxlen + 1 - (i->name).size(), ' ');

        std::streamsize prec = std::cout.precision();
        std::cout << std::setprecision(3)
                  << i->finalGrade
                  << std::setprecision(prec)
                  << std::endl;
    }
    return 0;
}
