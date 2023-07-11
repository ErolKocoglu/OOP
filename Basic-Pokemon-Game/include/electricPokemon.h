/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#ifndef _electricpokemon
#define _electricpokemon

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"
#include "psychicPokemon.h"

class ElectricPokemon : public Pokemon{
    public:
        ElectricPokemon(const std::string, int, const int, const int, const int);
        void attack();
        void set_rival(PsychicPokemon*);
        void set_is_confused(bool);
        void set_recover_confusing(int);

    private:
        PsychicPokemon* rival;
        bool is_confused;
        int recover_confusing;//It recovers confusing when this variable is zero
        
};

#endif