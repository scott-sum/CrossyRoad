#include <iostream>
#include <vector>
#include <deque>
#include <conio.h>
#include <time.h>

#include "player.h"
#include "lane.h"
#include "game.h"

using namespace std;

int main() {
    srand(time(NULL));

    Game game(30, 10);
    game.Run();
    cout << "Game Over" << endl;

    getchar();
    return 0;
}