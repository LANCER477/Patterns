#pragma once
#include "Observer.h"
#include <string>
#include <iostream>
using namespace std;

class HappyObserver : public Observer {
    string name;

public:
    HappyObserver(string name) : name(name) {}
    void Update() override {
        cout << name << ": GOOD" << endl;
    }
};
