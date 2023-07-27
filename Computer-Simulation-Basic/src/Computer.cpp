// fill
/*
Erol Koçoğlu - 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/Computer.h"

Computer::Computer(){
    std::cout<<"Computer is ready"<<std::endl;
}

void Computer::execute(const std::string operation){
    if(operation=="add" || operation=="subtract" || operation=="multiply"){
        std::cout<<cpu->execute(operation)<<std::endl;
    }else{
        std::cout<<gpu->execute(operation)<<std::endl;
    }
}

Computer Computer::operator+(const CPU& in_cpu){
    if(cpu!=NULL){
        std::cout<<"There is already a CPU"<<std::endl;
    }else{
        cpu=&in_cpu;
        std::cout<<"CPU is attached"<<std::endl;
    }
    return *this;
    
}

Computer Computer::operator+(const GPU& in_gpu){
    if(gpu!=NULL){
        std::cout<<"There is already a GPU"<<std::endl;
    }else{
        gpu=&in_gpu;
        std::cout<<"GPU is attached"<<std::endl;
    }
    return *this;
}

CUDA::CUDA(const int core_num):numCores(core_num){
    std::cout<<"CUDA is ready"<<std::endl;
}


std::string CUDA::render()const{
    return "Video is rendered";
}

std::string CUDA::trainModel()const{
    return "AI model is trained";
}


ALU::ALU(const int num_per_cores):numPerCores(num_per_cores){
    std::cout<<"ALU is ready"<<std::endl;
}

int ALU::add(const int num1, const int num2)const{
    return num1 + num2;
}

int ALU::subtract(const int num1, const int num2)const{
    return num1 - num2;
}

int ALU::multiply(const int num1, const int num2)const{
    return num1 * num2;
}


CPU::CPU(const int num_per_cores):alu{num_per_cores}{
    std::cout<<"CPU is ready"<<std::endl;
}

int CPU::execute(const std::string operation)const{
    int input1, input2;
    std::cout<<"Enter two integers"<<std::endl;
    std::cin>>input1;
    std::cin>>input2;
    if(operation=="add"){
        return alu.add(input1,input2);
    }

    if(operation=="subtract"){
        return alu.subtract(input1, input2);
    }

    return alu.multiply(input1,input2);
    
}

GPU::GPU(const int core_num):cuda{core_num}{
    std::cout<<"GPU is ready"<<std::endl;
}

std::string GPU::execute(const std::string operation)const{
    if(operation=="render"){
        return cuda.render();
    }
    return cuda.trainModel();
}