#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    virtual int getAttack() = 0;
    virtual int getSpeed() = 0;
    virtual int getHealth() = 0;
    virtual int getDefense() = 0;
    virtual void move() = 0;
    virtual string getDescription() = 0;
    virtual ~Character() {}
};

class BaseCharacter : public Character {
public:
    int getAttack() override { return 0; }

    int getSpeed() override { return 0; }

    int getHealth() override { return 0; }

    int getDefense() override { return 0; }

    void move() override {
        cout << "Двигается со скоростью: " << getSpeed() << endl;
    }

    string getDescription() override {
        return "Базовый персонаж";
    }
};

class CharacterDecorator : public Character {
protected:
    Character* wrappedCharacter;

public:
    CharacterDecorator(Character* character) : wrappedCharacter(character) {}

    virtual ~CharacterDecorator() {
        delete wrappedCharacter;
    }

    int getAttack() override {
        return wrappedCharacter->getAttack();
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed();
    }

    int getHealth() override {
        return wrappedCharacter->getHealth();
    }

    int getDefense() override {
        return wrappedCharacter->getDefense();
    }

    void move() override {
        wrappedCharacter->move();
    }

    string getDescription() override {
        return wrappedCharacter->getDescription();
    }
};

class Human : public CharacterDecorator {
public:
    Human(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 20;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 20;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 150;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense();
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Человек";
    }
};

class Elf : public CharacterDecorator {
public:
    Elf(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 15;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 30;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 100;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense();
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Эльф";
    }
};

class Warrior : public CharacterDecorator {
public:
    Warrior(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 20;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 10;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 50;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() + 20;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Воин";
    }
};

class SwordMaster : public CharacterDecorator {
public:
    SwordMaster(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 40;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() - 10;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 50;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() + 40;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Мастер меча";
    }
};

class Archer : public CharacterDecorator {
public:
    Archer(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 20;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 20;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 50;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() + 10;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Лучник";
    }
};

class Rider : public CharacterDecorator {
public:
    Rider(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() - 10;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 40;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 200;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() + 100;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Всадник";
    }
};

class EvilMage : public CharacterDecorator {
public:
    EvilMage(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 70;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 20;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth();
    }

    int getDefense() override {
        return wrappedCharacter->getDefense();
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Злой маг";
    }
};

class GoodMage : public CharacterDecorator {
public:
    GoodMage(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 50;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 30;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 100;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() + 30;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Добрый маг";
    }
};

class Crossbowman : public CharacterDecorator {
public:
    Crossbowman(Character* character) : CharacterDecorator(character) {}

    int getAttack() override {
        return wrappedCharacter->getAttack() + 20;
    }

    int getSpeed() override {
        return wrappedCharacter->getSpeed() + 10;
    }

    int getHealth() override {
        return wrappedCharacter->getHealth() + 50;
    }

    int getDefense() override {
        return wrappedCharacter->getDefense() - 10;
    }

    string getDescription() override {
        return wrappedCharacter->getDescription() + " + Арбалетчик";
    }
};

void showStats(Character* character) {
    cout << "Описание: " << character->getDescription() << endl;

    cout << "Атака: " << character->getAttack() << endl;

    cout << "Скорость: " << character->getSpeed() << endl;

    cout << "Здоровье: " << character->getHealth() << endl;

    cout << "Защита: " << character->getDefense() << endl;

    character->move();

    cout << "-----------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "");

    Character* baseChar = new BaseCharacter();

    cout << "Персонаж 1: Человек -> Воин -> Мастер меча -> Всадник" << endl;
    Character* human = new Human(baseChar);
    Character* warrior = new Warrior(human);
    Character* swordMaster = new SwordMaster(warrior);
    Character* rider = new Rider(swordMaster);
    showStats(rider);

    cout << endl;

    cout << "Персонаж 2: Человек -> Воин -> Лучник" << endl;
    Character* human2 = new Human(new BaseCharacter());
    Character* warrior2 = new Warrior(human2);
    Character* archer = new Archer(warrior2);
    showStats(archer);

    cout << endl;

    cout << "Персонаж 3: Эльф -> Маг -> Злой маг" << endl;
    Character* elf = new Elf(new BaseCharacter());
    Character* elfMage = new EvilMage(elf);
    showStats(elfMage);

    cout << endl;

    cout << "Персонаж 4: Эльф -> Маг -> Добрый маг" << endl;
    Character* elf2 = new Elf(new BaseCharacter());
    Character* goodMage = new GoodMage(elf2);
    showStats(goodMage);

    cout << endl;

    cout << "Персонаж 5: Эльф -> Воин -> Арбалетчик" << endl;
    Character* elf3 = new Elf(new BaseCharacter());
    Character* elfWarrior = new Warrior(elf3);
    Character* crossbowman = new Crossbowman(elfWarrior);
    showStats(crossbowman);

    delete rider;
    delete archer;
    delete elfMage;
    delete goodMage;
    delete crossbowman;

    return 0;
}
