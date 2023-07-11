/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/
#ifndef _arena
#define _arena

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena{
    public:
        Arena();
        ~Arena();
        void addPokemon(const char, const std::string, int , const int);
        void simulateBattle();
        void spawnTerrain();
        void restartTerrain();
        void printRoundStats(const int, const int);
        void printMatchResults();

    private:
        ElectricPokemon* ePokemon;
        PsychicPokemon* pPokemon;
        std::string terrain;
        int retain;
};

#endif