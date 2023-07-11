/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/student.h"
#include "../include/university.h"

using namespace std;

University::University(string name, double gpa_weight, double gre_weight, double toefl_weight, double bias, string country){
    this->name=name;
    weight_for_gpa=gpa_weight;
    weight_for_gre=gre_weight;
    weight_for_toefl=toefl_weight;
    this->bias=bias;
    this->country=country;
}

University::University(string name, double gpa_weight, double gre_weight, double toefl_weight, double bias){
    this->name=name;
    weight_for_gpa=gpa_weight;
    weight_for_gre=gre_weight;
    weight_for_toefl=toefl_weight;
    this->bias=bias;
}

void University::evaluate_student(const Student &student){
    double res= student.get_GPA() * weight_for_gpa + student.get_GRE() * weight_for_gre + student.get_TOEFL() * weight_for_toefl + bias;
    student.set_num_of_apps(student.get_num_of_apps()+1);
    
    if(res>=0){
        cout<<student.get_name()<<" is admitted to "<<name<<endl;
    }else{
        cout<<student.get_name()<<" is rejected from "<<name<<endl;
    }
}