/*
BLG 252E - Assignment 3
Spring 2023
*/

#include "include/arena.h"//I had to change the path since arena.h is in include folder


int main()
{
	srand(1773);
	Arena myArena; 

	myArena.addPokemon('e', "Pikachu", 150, 20); 
	myArena.addPokemon('p', "Abra", 120, 10);
	myArena.simulateBattle();

	myArena.addPokemon('e', "Jolteon", 150, 10); 
	myArena.addPokemon('p', "Kadabra", 100, 20); 
	myArena.simulateBattle();

	return 0;
}