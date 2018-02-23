/*
Accelerated C++

Exercise 6-5
Write an analysis function to call optimistic_median

Exercise 6-6
Merge analysis of median, average, and optimistic median into one function

Exercise 6-7
Stable partition students who did and did not do all homework, just like extract_fails
*/

#include <algorithm> // stable_partition
#include <iomanip> // precision
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
    container students;
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

    // Separate students who did and didn't do all homework
    iter didOrDidnt = stable_partition(students.begin(), students.end(), didAllHw);
    container studentsDidHw(students.begin(), didOrDidnt);
    container studentsDidNotHw(didOrDidnt, students.end());

    // Extract fails from DID group of students
    iter seperatorDid = stable_partition(studentsDidHw.begin(), studentsDidHw.end(), passingGrade);
    container failStudentsDidHw(seperator, studentsDidHw.end());
    studentsDidHw.erase(seperatorDid, studentsDidHw.end());

    // Extract fails from the DID NOT group of students
    iter separatorDidnt = stable_partition(studentsDidNotHw.begin(), studentsDidNotHw.end(), passingGrade);
    container failStudentsDidNotHw(separatorDidnt, studentsDidNotHw.end());
    studentsDidNotHw.erase(separatorDidnt,studentsDidNotHw.end());

    // At this point, we have FOUR containers:
    // 1. studentsDidHw = those who did all HW and passed
    // 2. studentsDidNotHw = those who did not do all HW but passed
    // 3. failStudentsDidHw = those who did all HW but failed
    // 4. failStudentsDidNotHw = those who did not do all HW and failed

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

    std::cout << std::endl << "FAILING STUDENTS (under 65):" << std::endl;
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
