/*
Accelerated C++ Exercise 6-5
Write an analysis function to call optimistic_median
*/

#include <algorithm> // stable_partition
#include <iomanip> // precision, setw
#include <ios> // width
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "grade.h"
#include "passingGrade.h"
#include "Student_info.h"


typedef std::list<Student_info> container;
typedef std::list<Student_info>::iterator iter;

int main(){
    container students; // Uses List to contain student records for optimized insertion/deletion
    Student_info record; // Student info struct contains data string "name" and grade double "finalGrade"

    std::cout << "Enter student name, midterm, final, and all homework grades below." << std::endl;

    // Passes the console input and the temporary struct "record" to hold read values until it is appended to our vector
    std::string::size_type maxLen = 0;
    while(read(std::cin, record)){
        maxLen = std::max(maxLen, record.name.size());
        students.push_back(record);
    }

    // Compare predicate uses "name" of student data, as defined in Student_info.cpp
    students.sort(compare);

    // Extract students who failed and store in new container
    iter seperator = stable_partition(students.begin(), students.end(), passingGrade);
    container failStudents(seperator, students.end());
    students.erase(seperator, students.end());

    // Print passing students in original container
    std::cout << "PASSING STUDENTS:" << std::endl;
    for (iter i = students.begin(); i!= students.end(); ++i){
        // Print name then appropriate spaces (COULD USE WIDTH AND SETW??)
        std::cout << i->name
                  << std::string(maxLen + 1 - (i->name).size(), ' ');
        std::streamsize prec = std::cout.precision();
        std::cout << std::setprecision(3)
                  << i->finalGrade
                  << std::setprecision(prec)
                  << std::endl;
    }

    std::cout << std::endl << "FAILING STUDENTS (under 60):" << std::endl;
    for (iter i = failStudents.begin(); i!= failStudents.end(); ++i){
        // Print name then appropriate spaces (COULD USE WIDTH AND SETW??)
        std::cout << i->name
                  << std::string(maxLen + 1 - (i->name).size(), ' ');
        std::streamsize prec = std::cout.precision();
        std::cout << std::setprecision(3)
                  << i->finalGrade
                  << std::setprecision(prec)
                  << std::endl;
    }
    return 0;
}
