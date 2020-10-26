#include <iostream>
using namespace std;
#include <string>

#include "Fighter.h"
#include "random.h"

Fighter::Fighter(string n, int x, int z) : name(n), hp(x), atk(z) {}

int Fighter::takeDmg(int dmg)
{
    hp = hp - dmg;
    if(hp < 0)
        hp = 0;
    
    return hp;
}

int Fighter::getHp() { return hp; }

int Fighter::getAtk() { return atk; }

void Fighter::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Fighter::getPositionY() { return cords[0]; }

int Fighter::getPositionX() { return cords[1]; }

void Fighter::print()
{
    cout<<"Figher: ["<<name<<"] (hp:"<<hp<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}

//-----

Dorc::Dorc() : Fighter("Dorc", 5, 0)
{
    atk = random(3) + 6;
    cout<<"Fighter Created-- '"<<name<<"' (hp:"<<hp<<", atk:"<<atk<<")"<<endl;
}

int Dorc::takeDmg(int dmg)
{
    hp = hp - dmg;
    if(hp < 0)
        hp = 0;
    
    return hp;
}

int Dorc::getHp() { return hp; }

int Dorc::getAtk() { return atk; }

void Dorc::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Dorc::getPositionY() { return cords[0]; }

int Dorc::getPositionX() { return cords[1]; }

void Dorc::print()
{
    cout<<"["<<name<<"] (hp:"<<hp<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}

//-----

Borc::Borc() : Fighter("Borc", 5, 0)
{
    atk = random(4) + 8;
    cout<<"Fighter Created-- '"<<name<<"' (hp:"<<hp<<", atk:"<<atk<<")"<<endl;
}

int Borc::takeDmg(int dmg)
{
    hp = hp - dmg;
    if(hp < 0)
        hp = 0;
    
    return hp;
}

int Borc::getHp() { return hp; }

int Borc::getAtk() { return atk; }

void Borc::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Borc::getPositionY() { return cords[0]; }

int Borc::getPositionX() { return cords[1]; }

void Borc::print()
{
    cout<<"["<<name<<"] (hp:"<<hp<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}

//-----

Porc::Porc() : Fighter("Porc", 5, 0)
{
    atk = random(2) + 4;
    cout<<"Fighter Created-- '"<<name<<"' (hp:"<<hp<<", atk:"<<atk<<")"<<endl;
}

int Porc::takeDmg(int dmg)
{
    hp = hp - dmg;
    if(hp < 0)
        hp = 0;
    
    return hp;
}

int Porc::getHp() { return hp; }

int Porc::getAtk() { return atk; }

void Porc::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Porc::getPositionY() { return cords[0]; }

int Porc::getPositionX() { return cords[1]; }

void Porc::print()
{
    cout<<"["<<name<<"] (hp:"<<hp<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}

//-----

Dragon::Dragon() : Fighter("Dragon", 1000, 1000) {}

int Dragon::takeDmg()
{
    return 0;
}

int Dragon::getHp() { return hp; }

int Dragon::getAtk() { return atk; }

void Dragon::setPosition(int y, int x)
{
    cords[0] = y;
    cords[1] = x;
}

int Dragon::getPositionY() { return cords[0]; }

int Dragon::getPositionX() { return cords[1]; }

void Dragon::print()
{
    cout<<"["<<name<<"] (hp:"<<hp<<", atk:"<<atk<<") - Position:("<<cords[0]<<","<<cords[1]<<")"<<endl;
}