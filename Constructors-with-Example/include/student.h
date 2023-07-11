/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#ifndef _student
#define _student

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Student{
    private:
        mutable string name="";
        double GPA=0;
        double GRE=0;
        double TOEFL=0;
        mutable int num_of_apps=0;
    
    public:
        Student(const string,const double,const double,const double);
        Student(const Student &);
        ~Student();
        string get_name() const;
        void set_name(const string);
        double get_GPA() const;
        void set_GPA(const double);
        double get_GRE() const;
        void set_GRE(const double);
        double get_TOEFL() const;
        void set_TOEFL(const double);
        int get_num_of_apps() const;
        void set_num_of_apps(const int) const;
        
};

#endif