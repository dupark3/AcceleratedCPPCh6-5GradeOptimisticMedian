#include <list>

#include "didAllHw.h"
#include "Student_info.h"

bool didAllHw(const Student_info& student){
    return (std::list::iterator i = find(student.begin(), student.end(),0)) == student.end();
}
