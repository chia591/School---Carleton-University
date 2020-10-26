#ifndef PRINCE_H
#define PRINCE_H

#include <string>
using namespace std;

class Prince
{
    public:
        Prince(string, int, int, int);
        ~Prince();
        int getHp();
        int getDef();
        int getAtk();
        string getName();
        int takeDmg(int);
        void setPosition(int, int);
        int getPositionY();
        int getPositionX();
        void print();

    private:
        string Name;
        int hp;
        int def;
        int atk;
        int cords[2];

};
#endif