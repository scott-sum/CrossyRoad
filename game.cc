#include "game.h"

using namespace std;

Game::Game(int w, int h) {
    numLanes = h;
    width = w;
    quit = false;
    for(int i = 0; i < numLanes; ++i){
        map.emplace_back(new Lane(width));
    }
    player = new Player(width);
}

Game::~Game() {
    delete player;
    for (int i = 0; i < map.size(); i++) {
        Lane * current = map.back();
        map.pop_back();
        delete current;
    }
}

void Game::Draw() {
    system("cls");
    for (int i = 0; i < numLanes; ++i){
        for (int j = 0; j < width; ++j){
            if (i == 0 && (j== 0 || j == width - 1)) {
                cout << "|";
            }
            if (i == numLanes - 1 && (j== 0 || j == width - 1)) {
                cout << "|";
            }
            if (map[i]->CheckPosn(j) && i != 0 && i != numLanes - 1) {
                cout << "#";
            } else if (player->x == j && player->y == i) {
                cout << "&";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void Game::Input() {
    if (_kbhit()) {
        char current = _getch();
        if (current == 'a') {
            player->x--;
        }
        if (current == 'd') {
            player->x++;
        }
        if (current == 'w') {
            player->y--;
        }
        if (current == 's') {
            player->y++;
        }
        if (current == 'q') {
            quit = true;
        }
    }
}

void Game::Logic() {
    for (int i = 1; i < numLanes - 1; ++i) {
        if (rand() % 10 == 1) {
            map[i]->Move();
        }
        if (map[i]->CheckPosn(player->x) && player->y == i) {
            quit = true;
        }
    }
    if (player->y == numLanes - 1) {
        score++;
        player->y = 0;
        cout << "\x07"; //sound when crossed
        map[rand() % numLanes]->ChangeDirection();
    }
}

void Game::Run() {
    while (!quit) {
        Input();
        Draw();
        Logic();
    }
}