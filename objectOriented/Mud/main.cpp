//  Program:  This is going to be a simple, small dungeon MUD to stretch and use my programming skills.
//  Author:  Joshua Jolley
//  Date:  Sept 13 2012
//  
//
//
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;


   
struct backpack
{
   item items[50];
};

struct player
{
   string name;
   string race;
   int str;
   int dex;
   int con;
   int wis;
   int intel;
   int cha;
   int hp;
   int mp;
   int stamina;
   backpack smallpack;
   item head;
   item body;
   item feet;
   item ring1;
   item ring2;
   int locationX;
   int locationY;
   int locationZ;
   int numMoves;
};

struct item
{
   int eqslot;
   string shortDesc;
   string longDesc;
   int ac;
   int atk;
   bool invis;
};

struct room
{
   int x;
   int y;
   int z;
   string shortDesc;
   string longDesc;
   item item1;
   item item2;
   item item3;
   char map;
};

void interact();
void displayHelp();
void displayRoom(player, room);
void displayItem(const item);
void displayStats(const player);
void getItem(player, item);
int main ()
{
   interact();
}

void interact()
{
   string move = " ";
   cout << player.name << ": ";
   while (move != "quit")
   {
      if (move.compare("e") == 0 || move.comapre("east") == 0)
      {
         player.locationX++;
         displayRoom(player, room);
