#ifndef CONTROLER_H
#define CONTROLER_H

#include <list>
using namespace std;

#include "Prince.h"
#include "Fighter.h"
#include "Map.h"

class Controler
{
    public:
        Controler();
        ~Controler();
        void Colisions(int, int, int, int);
        void update();
        void turn();
    
    private:
        Map map;
        list<Prince*> Princes;
        list<Dorc*> Dorcs;
        list<Borc*> Borcs;
        list<Porc*> Porcs;
        Dragon* drag;
        bool dragDir;

};

#endif