#ifndef MAP_H
#define MAP_H

#define Y_VAL 5
#define X_VAL 25

class Map
{
    public:
        Map();
        ~Map();
        void print();
        void change(int, int, char);
        void clear();

    private:
        char ui[Y_VAL][X_VAL];
        const int xSize = X_VAL;
        const int ySize = Y_VAL;

};
#endif