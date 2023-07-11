/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/electricPokemon.h"
#include "../include/psychicPokemon.h"
#include "../include/arena.h"

Arena::Arena(){
    ePokemon=NULL;
    pPokemon=NULL;
    retain=0;
}

Arena::~Arena(){
    delete ePokemon;
    delete pPokemon;
    //Since this variables are created with "new keyword", we need to delete them in destructor
}

void Arena::addPokemon(const char type, const std::string name_in, int hp_in, const int damage_in){
    if(type=='e'){
        if(ePokemon!=NULL){
            //We delete the pokemon from previous battle
            delete ePokemon;
        }
        
        ePokemon=new ElectricPokemon(name_in,hp_in,damage_in,20,3);
        std::cout<<"Electric Pokemon "<<name_in<<" has entered the arena."<<std::endl;
        std::cout<<"Class: Electric"<<std::endl;
        std::cout<<"\tName: "<<name_in<<"\n"<<"\tHP: "<<hp_in<<"\n"<<"\tDamage: "<<damage_in<<"\n"<<std::endl;
    }else{
        if(pPokemon!=NULL){
            delete pPokemon;
            //We delete the pokemon from previous battle
        }
        pPokemon=new PsychicPokemon(name_in,hp_in,damage_in,30,5);
        std::cout<<"Psychic Pokemon "<<name_in<<" has entered the arena."<<std::endl;
        std::cout<<"Class: Psychic"<<std::endl;
        std::cout<<"\tName: "<<name_in<<"\n"<<"\tHP: "<<hp_in<<"\n"<<"\tDamage: "<<damage_in<<"\n"<<std::endl;
    }
}

void Arena::restartTerrain(){
    int random=(int)(rand()%100);
    //this function restart terrain without considering the previous round's terrain
    if(random<20){
        terrain="Electric";
        retain=5;
    }else if(random>=20 && random<40){
        terrain="Psychic";
        retain=5;
    }else{
        terrain="None";
        retain=1;
    }

    if(terrain=="Electric"){
            ePokemon->set_its_own_terrain(true);
            pPokemon->set_its_own_terrain(false);
    }else if(terrain=="Psychic"){
            pPokemon->set_its_own_terrain(true);
            ePokemon->set_its_own_terrain(false);
    }else{
            ePokemon->set_its_own_terrain(false);
            pPokemon->set_its_own_terrain(false);
    }
}

void Arena::spawnTerrain(){
    if(retain>0){
        retain-=1;
        return;
    }
    
    //this function spawns the terrain depending on the variable "retain", it tells how many
    //rounds the terrain will not change
    int random=(int)(rand()%100);
    if(random<20){
        terrain="Electric";
        retain=4;
    }else if(random>=20 && random<40){
        terrain="Psychic";
        retain=4;
    }else{
        terrain="None";
        retain=0;
    }

    if(terrain=="Electric"){
            ePokemon->set_its_own_terrain(true);
            ePokemon->set_recover_confusing(0);
            ePokemon->set_is_confused(false);//It recovers confusing
            pPokemon->set_its_own_terrain(false);
    }else if(terrain=="Psychic"){
            pPokemon->set_its_own_terrain(true);
            ePokemon->set_its_own_terrain(false);
    }else{
            ePokemon->set_its_own_terrain(false);
            pPokemon->set_its_own_terrain(false);
    }
}

void Arena::printMatchResults(){
    //Checks who has won and prints to the screen
    std::cout<<"Match Results:"<<std::endl;
    if(ePokemon->get_is_fainted()){
        std::cout<<pPokemon->get_name()<<" has won the match!\n"<<std::endl;
    }else{
        std::cout<<ePokemon->get_name()<<" has won the match!\n"<<std::endl;
    }
}

void Arena::printRoundStats(const int round,const int heads){
    std::cout<<"Round: "<<round<<std::endl;
    std::cout<<"Current terrain: "<<terrain<<std::endl;
    //Prints round information
    if(heads==0){
        std::cout<<ePokemon->get_name()<<" goes first"<<std::endl;
    }else{
        std::cout<<pPokemon->get_name()<<" goes first"<<std::endl;
    }
    //Prints when any pokemon initiates power up
    if(ePokemon->get_is_power_up()){
        std::cout<<ePokemon->get_name()<<" has initiated a power up."<<std::endl;
    }
    if(pPokemon->get_is_power_up()){
        std::cout<<pPokemon->get_name()<<" has initiated a power up."<<std::endl;
    }

    std::cout<<ePokemon->get_name()<<" HP: "<<ePokemon->get_hp()<<std::endl;
    std::cout<<pPokemon->get_name()<<" HP: "<<pPokemon->get_hp()<<std::endl;
    if(ePokemon->get_hp()>pPokemon->get_hp()){
        std::cout<<ePokemon->get_name()<<" is in the lead!\n"<<std::endl;
    }else{
        std::cout<<pPokemon->get_name()<<" is in the lead!\n"<<std::endl;
    }
}

void Arena::simulateBattle(){
    if(ePokemon==NULL || pPokemon==NULL){
        std::cout<<"There must be 1 psychic pokemon and 1 electric pokemon in the arena!"<<std::endl;
        return;
    }
    ePokemon->set_rival(pPokemon);
    pPokemon->set_rival(ePokemon);
    
    int round=1;
    restartTerrain();

    while(true){
        spawnTerrain();
        int random=(int)(rand()%2);
        //Selects who attacks first
        
        if(random==0){
            ePokemon->attack();
            if(!pPokemon->get_is_fainted()){
                pPokemon->attack();//Attacks if it is not fainted
            }
        }else{
            pPokemon->attack();
            if(!ePokemon->get_is_fainted()){
                ePokemon->attack();//Attacks if it is not fainted
            }
        }

        printRoundStats(round,random);
        //Turns power up states off
        if(ePokemon->get_is_power_up()){
            ePokemon->set_power_up_enable(ePokemon->get_recharge());
            ePokemon->set_is_power_up(false);
        }
        if(pPokemon->get_is_power_up()){
            pPokemon->set_power_up_enable(pPokemon->get_recharge());
            pPokemon->set_is_power_up(false);
        }
        if(ePokemon->get_is_fainted() || pPokemon->get_is_fainted()){
            break;
        }
        round+=1;

    }
    printMatchResults();
    
    
}