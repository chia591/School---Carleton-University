#include <iostream>
using namespace std;
#include <string>
#include <list>

#include "random.h"
#include "Controler.h"

Controler::Controler()
{
    Prince* timmy = new Prince("Timmy", 15, 3, 3);
    Prince* harold = new Prince("Harold", 15, 1, 5);

    int temp = random(5);
    timmy->setPosition(temp,0);

    temp = temp + random(4) + 1;
    if(temp > 4)
        temp -= 5;
    harold->setPosition(temp, 0);

    Princes.push_back(timmy);
    Princes.push_back(harold);

    drag = new Dragon();
    drag->setPosition(random(3) + 1, 24);
}

Controler::~Controler()
{

}

void Controler::update()
{
    map.clear();
    int tmpY, tmpX;
    tmpY = drag->getPositionY();
    tmpX = drag->getPositionX();

    map.change(tmpY, tmpX, 'D');

    for(Prince* i : Princes)
    {
        tmpY = i->getPositionY();
        tmpX = i->getPositionX();

        map.change(tmpY, tmpX, i->getName().at(0));
    }

    for(Dorc* i : Dorcs)
    {
        tmpY = i->getPositionY();
        tmpX = i->getPositionX();

        map.change(tmpY, tmpX, 'd');
    }

    for(Borc* i : Borcs)
    {
        tmpY = i->getPositionY();
        tmpX = i->getPositionX();

        map.change(tmpY, tmpX, 'b');
    }

    for(Porc* i : Porcs)
    {
        tmpY = i->getPositionY();
        tmpX = i->getPositionX();

        map.change(tmpY, tmpX, 'p');
    }

    map.print();



    cout<<"Token List:"<<endl;
    cout<<endl<<"Princes list size: "<<Princes.size()<<endl;
    for(Prince* i : Princes)
    {
        i->print();
    }
    cout<<endl<<"Dragon:"<<endl;
    drag->print();
    cout<<endl<<"Dorcs list size: "<<Dorcs.size()<<endl;
    for(Dorc* i : Dorcs)
    {
        i->print();
    }
    cout<<endl<<"Borcs list size: "<<Borcs.size()<<endl;
    for(Borc* i : Borcs)
    {
        i->print();
    }
    cout<<endl<<"Porcs list size: "<<Porcs.size()<<endl;
    for(Porc* i : Porcs)
    {
        i->print();
    }
}

void Controler::turn()
{
    dragDir = false; //false:up true:down
    char exit = 'l';
    while(true)
    {
        update();
        cout<<endl<<"Enter anything to go in deeper [e to exit]:  ";
        cin >> exit;
        if(exit == 'e')
            break;
        cout<<endl<<"--------------------------------------------------"<<endl;

        //Step 1: Move Characters
        for(Prince* i : Princes)
        {
            int tmpY, tmpX;
            tmpY = i->getPositionY() + random(3) - 1;
            if(tmpY > 4)
                tmpY = 4;
            if(tmpY < 0)
                tmpY = 0;
            tmpX = i->getPositionX() + 1;
            i->setPosition(tmpY, tmpX);
        }

        for(Dorc* i : Dorcs)
        {
            int tmpY, tmpX;
            tmpY = i->getPositionY() + random(3) - 1;
            if(tmpY > 4)
                tmpY = 4;
            if(tmpY < 0)
                tmpY = 0;
            tmpX = i->getPositionX() - 1;
            i->setPosition(tmpY, tmpX);
        }

        for(Borc* i : Borcs)
        {
            int tmpY, tmpX;
            tmpY = i->getPositionY() + random(3) - 1;
            if(tmpY > 4)
                tmpY = 4;
            if(tmpY < 0)
                tmpY = 0;
            tmpX = i->getPositionX() - 1;
            i->setPosition(tmpY, tmpX);
        }

        for(Porc* i : Porcs)
        {
            int tmpY, tmpX;
            tmpY = i->getPositionY() + random(3) - 1;
            if(tmpY > 4)
                tmpY = 4;
            if(tmpY < 0)
                tmpY = 0;
            tmpX = i->getPositionX() - 1;
            i->setPosition(tmpY, tmpX);
        }

        //Step 2: Dragon be strong
        if(drag->getPositionY() == 1)
            dragDir = false;
        else if(drag->getPositionY() == 3)
            dragDir = true;

        if(dragDir == true)
            drag->setPosition(drag->getPositionY() - 1, drag->getPositionX());
        if(dragDir == false)
            drag->setPosition(drag->getPositionY() + 1, drag->getPositionX());

        //Step Last: Make Fighter
        if(random(100) < 60) 
        {
            cout<<"creating Fighter"<<endl;
            bool canMake = false;
            int tmpY = random(5) - 1, tmpX = 23, counter = 1;
            while(canMake == false)
            {
                canMake = true;
                counter++;
                tmpY++;
                if(tmpY > 5)
                    tmpY -= 5;
                if(counter == 5)
                {
                    cout<<"there is no space availaible"<<endl;
                    break; // !!! Place holder, put end game since it becomes impossible to finish
                }
                for(Prince* i : Princes)
                {
                    if(tmpY == i->getPositionY() && tmpX == i->getPositionX())
                    {
                        canMake = false;
                    }
                }

                for(Dorc* i : Dorcs)
                {
                    if(tmpY == i->getPositionY() && tmpX == i->getPositionX())
                    {
                        canMake = false;
                    }
                }

                for(Borc* i : Borcs)
                {
                    if(tmpY == i->getPositionY() && tmpX == i->getPositionX())
                    {
                        canMake = false;
                    }
                }

                for(Porc* i : Porcs)
                {
                    if(tmpY == i->getPositionY() && tmpX == i->getPositionX())
                    {
                        canMake = false;
                    }
                }
            }

            switch (random(3))
            {
                case 0:
                {  
                    cout<<"         Dorc"<<endl;
                    Dorc* d = new Dorc();
                    d->setPosition(tmpY, tmpX);
                    Dorcs.push_back(d);
                    break;
                }
                
                case 1:
                {
                    cout<<"         Borc"<<endl;
                    Borc* b = new Borc();
                    b->setPosition(tmpY, tmpX);
                    Borcs.push_back(b);
                    break;  
                }
                    
                
                case 2:
                {
                    cout<<"         Porc"<<endl;
                    Porc* p = new Porc();
                    p->setPosition(tmpY, tmpX);
                    Porcs.push_back(p);
                    break;
                }
            }
        }
        
    }
}

void Controler::Colisions(int mY, int mX, int tY, int tX)
{

}