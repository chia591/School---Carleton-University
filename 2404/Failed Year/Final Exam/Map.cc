#include <iostream>
#include <string>
using namespace std;

#include "Map.h"

Map::Map()
{
    clear();
}

Map::~Map()
{
    
}

void Map::print()
{
    cout<<"┏";
    for(int i = 0; i < xSize; i++)
        cout<<"━";
    cout<<"┓"<<endl;
    cout<<"┃     Dragon's Hollow     ┃"<<endl;


    cout<<"┡";
    for(int i = 0; i < xSize; i++)
        cout<<"━";
    cout<<"┩"<<endl;

    for(int i = 0; i < ySize; i++)
    {
        cout<<"│";
        for(int j = 0; j < xSize; j++)
        {
            cout<<ui[i][j];
        }
        if(i == 1)
            cout<<"╘╗"<<endl;
        else if(i == 2)
            cout<<" ║*"<<endl;
        else if(i == 3)
            cout<<"╒╝"<<endl;
        else
            cout<<"│"<<endl;
    }

    cout<<"└";
    for(int i = 0; i < xSize; i++)
        cout<<"─";
    cout<<"┘"<<endl;
}

void Map::change(int y, int x, char c)
{
    ui[y][x] = c;
}

void Map::clear()
{
    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            ui[i][j] = ' ';
        }
    }
}