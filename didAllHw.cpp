#include <algorithm> // find
#include <vector>

#include "didAllHw.h"
#include "Student_info.h"

bool didAllHw(const Student_info& student){
    std::vector<double>::const_iterator i = find(student.homework.begin(), student.homework.end(), 0);
    return i == student.homework.end();
}
