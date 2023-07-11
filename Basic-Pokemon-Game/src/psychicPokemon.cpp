/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/pokemon.h"
#include "../include/electricPokemon.h"
#include "../include/psychicPokemon.h"

PsychicPokemon::PsychicPokemon(const std::string name_in, int hp_in, const int damage_in, const int power_chance_in, const int recharge_in):
Pokemon(name_in, hp_in, damage_in, power_chance_in, recharge_in){

}

void PsychicPokemon::attack(){
    int en=get_power_up_enable();
    power_up(&en);
    set_power_up_enable(en);
    //First attempts to power up
    if(get_is_power_up()){
        if(!rival->get_its_own_terrain()){
            rival->set_is_confused(true);
            rival->set_recover_confusing(3);
        }
        //If it is in power up state, then makes its rival confused
        
    }
    if(get_its_own_terrain()){
        rival->set_hp(rival->get_hp()-2*get_damage());
    }else{
        rival->set_hp(rival->get_hp()-get_damage());
    }
    if(rival->get_hp()<=0){
            rival->set_hp(0);
            rival->set_is_fainted(true);
    }
}

void PsychicPokemon::set_rival(ElectricPokemon* rival_in){
    rival=rival_in;
}