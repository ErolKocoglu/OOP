// fill
/*
Erol Koçoğlu - 150200107
*/

#ifndef _computer
#define _computer

#include <iostream>
#include <stdio.h>
#include <string.h>

class ALU{
    public:
        ALU(const int);
        int add(const int, const int)const;
        int subtract(const int, const int)const;
        int multiply(const int , const int)const;

    private:
        const int numPerCores;
};

class CPU{
    
    public:
        CPU(const int);
        int execute(const std::string)const;

    private:
        const ALU alu;
};

class CUDA{
    public:
        CUDA(const int);
        std::string render()const;
        std::string trainModel()const;

    private:
        const int numCores;
    
};

class GPU{  
    public:
        GPU(const int);
        std::string execute(const std::string)const;
        
    private:
        const CUDA cuda;
};



class Computer{
    public:
        Computer();
        void execute(const std::string);
        Computer operator+(const CPU&);
        Computer operator+(const GPU&);
    private:
        const CPU* cpu=NULL;;
        const GPU* gpu=NULL;;
};














#endif