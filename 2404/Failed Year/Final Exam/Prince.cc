#include <iostream>
#include <string>
using namespace std;

#include "Prince.h"

Prince::Prince(string n, int x, int y, int z)
{
    Name = n;
    hp = x;
    def = y;
    atk = z;
    cout<<"Prince made: ["<<Name<<"] (hp:"<<hp<<", def:"<<def<<", atk:"<<atk<<")"<<endl;
}

Prince::~Prince()
{
    
}

int Prince::getHp() { return hp; }

int Prince::getDef() { return def; }

int Prince::getAtk() { return atk; }

string Prince::getName() { return Name; }

int Prince::takeDmg(int dmg)
{
    dmg = dmg - def;
    if(dmg < 0)
        dmg = 0;
    
    hp = hp - dmg;
    if(hp < 0)
        hp = 0;
    
    return hp;
}

void Prince::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Prince::getPositionY() { return cords[0]; }

int Prince::getPositionX() { return cords[1]; }

void Prince::print()
{
    cout<<"["<<Name<<"] (hp:"<<hp<<", def:"<<def<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}