#include "unknown.h"
#include<iostream>

using namespace std;

Unknown::Unknown() {
    Unknown_Init();
}

void Unknown::Unknown_Init() {
    unknown_state = 0;
    coin_state = 0;
    coin = 0;
}


void Unknown::Unknown_State() {
    if (unknown_state == 750) {
        unknown_state = 0;
    }
    unknown_state += 50;
}


void Unknown::Unknown_crash(QVector < QVector < int >> ::iterator it){
    coin_state = 30;
    coin_x = *it->begin() + 10;
    coin_y = *(it->begin() + 1);
}

void Unknown::Crash_state() {

    if (coin_state > 0 && coin_state < 240) {
        //cout << coin_y << endl;
        coin_state += 30;
        coin_y -= 20;
    } else if (coin_state == 240) {
        coin_state = 0;
    }
}
