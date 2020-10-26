#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
using namespace std;

class Fighter
{
    public:
        Fighter(string, int, int);
        int getHp();
        int getAtk();
        int takeDmg(int);
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();
    
    protected:
        string name;
        int hp;
        int atk;
        int cords[2];

};

class Dorc : public Fighter
{
    public:
        Dorc();
        int getHp();
        int getAtk();
        int takeDmg(int);
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();
};

class Borc : public Fighter
{
    public:
        Borc();
        int getHp();
        int getAtk();
        int takeDmg(int);
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();
};

class Porc : public Fighter
{
    public:
        Porc();
        int getHp();
        int getAtk();
        int takeDmg(int);
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();
};

class Dragon : public Fighter
{
    public:
        Dragon();
        int getHp();
        int getAtk();
        int takeDmg(); //return remaining hp
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();
};

#endif