/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/pokemon.h"

Pokemon::Pokemon(const std::string name_in, int hp_in, const int damage_in, const int power_chance_in, const int recharge_in):
name(name_in), hp(hp_in), damage(damage_in), power_up_chance(power_chance_in), recharge(recharge_in){
    is_fainted=false;
    is_power_up=false;
    its_own_terrain=false;
    power_up_enable=0;
}

std::string Pokemon::get_name(){
    return name;
}

int Pokemon::get_hp(){
    return hp;
}

void Pokemon::set_hp(const int hp_in){
    hp=hp_in;
}

int Pokemon::get_power_up_enable(){
    return power_up_enable;
}

void Pokemon::set_power_up_enable(const int enable_in){
    power_up_enable=enable_in;
}

int Pokemon::get_damage(){
    return damage;
}

int Pokemon::get_power_up_chance(){
    return power_up_chance;
}

int Pokemon::get_recharge(){
    return recharge;
}

bool Pokemon::get_is_fainted(){
    return is_fainted;
}

void Pokemon::set_is_fainted(bool in){
    is_fainted=in;
}

bool Pokemon::get_is_power_up(){
    return is_power_up;
}

void Pokemon::set_is_power_up(bool in){
    is_power_up=in;
}

bool Pokemon::get_its_own_terrain(){
    return its_own_terrain;
}

void Pokemon::set_its_own_terrain(bool in){
    its_own_terrain=in;
}

void Pokemon::power_up(int* enable_in){
    if(*enable_in>0){
        *enable_in-=1;
        return;
        //it attempts to power up if enable is zero
    }
    int random=(int)(rand()%100);
    if(random<get_power_up_chance()){
        set_is_power_up(true);
    }

}