/* @Author
* Student Name: Erol Koçoğlu
* Student ID : 150200107
*/

#ifndef _pokemon
#define _pokemon

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


class Pokemon{
    public:
        Pokemon(const std::string, int, const int, const int, const int);
        std::string get_name();
        int get_hp();
        void set_hp(const int);
        int get_power_up_enable();
        void set_power_up_enable(const int);
        int get_damage();
        int get_power_up_chance();
        int get_recharge();
        bool get_is_fainted();
        void set_is_fainted(bool);
        bool get_is_power_up();
        void set_is_power_up(bool);
        bool get_its_own_terrain();
        void set_its_own_terrain(bool);
        void power_up(int*);

    private:
        const std::string name;
        int hp;
        int power_up_enable;//this controls if it can attempts to power up
        const int damage;
        const int power_up_chance;
        const int recharge;
        bool is_fainted;
        bool is_power_up;
        bool its_own_terrain;


};

#endif