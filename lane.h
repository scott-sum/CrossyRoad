#ifndef _LANE_H
#define _LANE_H
#include <iostream>
#include <vector>
#include <deque>
#include <conio.h>
#include <time.h>

using namespace std;

class Lane {
    private:
        deque <bool> cars;
        bool right;
    public:
        Lane(int width);

        void Move();

        bool CheckPosn(int posn);

        void ChangeDirection();
};


#endif