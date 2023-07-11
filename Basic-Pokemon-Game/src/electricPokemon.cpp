/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/pokemon.h"
#include "../include/psychicPokemon.h"
#include "../include/electricPokemon.h"

ElectricPokemon::ElectricPokemon(const std::string name_in, int hp_in, const int damage_in, const int power_chance_in, const int recharge_in):
Pokemon(name_in, hp_in, damage_in, power_chance_in, recharge_in){
    is_confused=false;
}


void ElectricPokemon::attack(){
    //First, attempts power up
    int en=get_power_up_enable();
    power_up(&en);
    set_power_up_enable(en);
    if(!is_confused){
        //It can attack if it is not confused
        if(get_is_power_up()){
            rival->set_hp(rival->get_hp()-3*get_damage());
        }else{
            rival->set_hp(rival->get_hp()-get_damage());
        }
        //Checks if its rival is fainted
        if(rival->get_hp()<=0){
            rival->set_hp(0);
            rival->set_is_fainted(true);
        }
    }else{
        //Waits for recovering confusion to attack
        recover_confusing-=1;
        if(recover_confusing==0){
            is_confused=false;
        }
    }
    
}


void ElectricPokemon::set_rival(PsychicPokemon* rival_in){
    rival=rival_in;
}

void ElectricPokemon::set_is_confused(bool in){
    is_confused=in;
}

void ElectricPokemon::set_recover_confusing(const int num){
    recover_confusing=num;
}