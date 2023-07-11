/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/student.h"

using namespace std;

Student::Student(const string name, const double gpa, const double gre, const double toefl){
    set_GPA(gpa);
    set_GRE(gre);
    set_TOEFL(toefl);
    set_name(name);
    cout<<name<<" logged in to the system."<<endl;
}

Student::Student(const Student &student_in){
    set_name(student_in.name);
    set_GPA(student_in.GPA);
    set_GRE(student_in.GRE);
    set_TOEFL(student_in.TOEFL);
    set_num_of_apps(0);
    cout<<name<<" logged in to the system."<<endl;
}

Student::~Student(){
    cout<<this->name<<" logged out of the system with "<<this->num_of_apps<<" application(s)."<<endl;
}

string Student::get_name() const{
    return name;
}

void Student::set_name(const string inp_name){
    name=inp_name;
}

double Student::get_GPA() const{
    return GPA;
}

void Student::set_GPA(const double inp_gpa){
    GPA=inp_gpa;
}

double Student::get_GRE() const{
    return GRE;
}

void Student::set_GRE(const double inp_gre){
    GRE=inp_gre;
}

double Student::get_TOEFL() const{
    return TOEFL;
}

void Student::set_TOEFL(const double inp_toefl){
    TOEFL=inp_toefl;
}

int Student::get_num_of_apps() const{
    return num_of_apps;
}

void Student::set_num_of_apps (const int app_num) const{
    num_of_apps=app_num;
}