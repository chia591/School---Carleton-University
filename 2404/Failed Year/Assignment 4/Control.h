#ifndef CONTROL_H
#define CONTROL_H

#include "List.h"
#include "Student.h"
#include "Date.h"
#include "View.h"

class Control
{
    public:
        void launch();

    private:
        List<Student> stu;
        List<Date> dat;
        View view;
        void initStudents();
        void initDates();
};

#endif