#pragma once
#include "Observer.h"
#include <string>
#include <iostream>
using namespace std;

class SpamObserver : public Observer {
    string name;

public:
    SpamObserver(string name) : name(name) {}
    void Update() override {
        cout << name << ": WTF?! Зачем мне это сообщение?!" << endl;
    }
};
