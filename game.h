#ifndef _GAME_H
#define _GAME_H
#include <iostream>
#include <vector>
#include <deque>
#include <conio.h>
#include <time.h>
#include "player.h"
#include "lane.h"

using namespace std;

class Game{
    private:
        bool quit;
        int numLanes;
        int width;
        int score;
        Player * player;
        vector<Lane *> map;
    public:
        Game(int w = 20, int h = 10);

        ~Game();

        void Draw();

        void Input();

        void Logic();

        void Run();
};

#endif