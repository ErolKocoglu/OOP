/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#ifndef _university
#define _university

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "student.h"

using namespace std;

class University{
    private:
        string name="";
        double weight_for_gpa=0.01;
        double weight_for_gre=0.02;
        double weight_for_toefl=0.03;
        double bias=0.1;
        string country="";
     public:
        University(string, double, double, double, double, string);
        University(string, double, double, double, double);
        void evaluate_student(const Student &);
};

#endif