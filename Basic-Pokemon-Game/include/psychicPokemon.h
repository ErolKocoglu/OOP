/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#ifndef _psychicpokemon
#define _psychicpokemon

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"


class ElectricPokemon;

class PsychicPokemon : public Pokemon{
    public:
        PsychicPokemon(const std::string, int, const int, const int, const int);
        void attack();
        void set_rival(ElectricPokemon*);
        

    private:
        ElectricPokemon* rival;
        
};

#endif