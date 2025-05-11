#pragma once
#include "Observer.h"
#include <vector>
#include <iostream>
using namespace std;

class Broadcaster {
    vector<Observer*> allObservers; // всех оповещаем
public:
    void Register(Observer* observer) {
        allObservers.push_back(observer);
    }

    void SendSpam() {
        for (Observer* o : allObservers) {
            o->Update(); // всем разослали
        }
    }
};
