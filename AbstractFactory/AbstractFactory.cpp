#include <iostream>
#include <string>
using namespace std;

class Herbivore {
protected:
    int weight;
    bool alive;

public:
    Herbivore() : weight(0), alive(true) {}
    virtual ~Herbivore() = default;

    virtual void eat_grass() = 0;
    int get_weight() const
    { 
        return weight;
    }
    bool is_alive() const 
    { 
        return alive;
    }
    void die()
    { 
        alive = false;
    }
};

class Carnivore {
protected:
    int power;

public:
    Carnivore() : power(0) {}
    virtual ~Carnivore() = default;

    virtual void eat(Herbivore* herbivore) = 0;
};

class Continent
{
public:
    virtual Herbivore* create_herbivore() = 0;
    virtual Carnivore* create_carnivore() = 0;
    virtual ~Continent() = default;
};

// === Африка ===
class Wildebeest : public Herbivore 
{
public:
    Wildebeest() { weight = 150; }

    void eat_grass() override 
    {
        weight += 5;
        cout << "Антилопа ест траву и становится тяжелее. Вес: " << weight << " кг." << endl;
    }
};

class Lion : public Carnivore
{
public:
    Lion() { power = 200; }

    void eat(Herbivore* herbivore) override {
        if (herbivore->is_alive() && power > herbivore->get_weight())
        {
            herbivore->die();
            power += 10;
            cout << "Лев поймал и съел антилопу. Сила льва: " << power << endl;
        }
        else
        {
            power -= 10;
            cout << "Лев остался голодным. Сила льва: " << power << endl;
        }
    }
};

class Africa : public Continent 
{
public:
    Herbivore* create_herbivore() override 
    {
        return new Wildebeest();
    }
    Carnivore* create_carnivore() override
    {
        return new Lion();
    }
};

// === Северная Америка ===
class Bison : public Herbivore 
{
public:
    Bison() { weight = 300; }

    void eat_grass() override 
    {
        weight += 5;
        cout << "Бизон жует траву. Вес: " << weight << " кг." << endl;
    }
};

class Wolf : public Carnivore
{
public:
    Wolf() { power = 180; }

    void eat(Herbivore* herbivore) override {
        if (herbivore->is_alive() && power > herbivore->get_weight())
        {
            herbivore->die();
            power += 10;
            cout << "Волк съел бизона. Сила волка: " << power << endl;
        }
        else
        {
            power -= 10;
            cout << "Волк не справился с добычей. Сила волка: " << power << endl;
        }
    }
};

class NorthAmerica : public Continent
{
public:
    Herbivore* create_herbivore() override
    {
        return new Bison();
    }
    Carnivore* create_carnivore() override 
    {
        return new Wolf();
    }
};

// === Евразия ===
class Elk : public Herbivore
{
public:
    Elk() { weight = 250; }

    void eat_grass() override
    {
        weight += 5;
        cout << "Лось пощипывает траву. Вес: " << weight << " кг." << endl;
    }
};

class Tiger : public Carnivore
{
public:
    Tiger() { power = 220; }

    void eat(Herbivore* herbivore) override {
        if (herbivore->is_alive() && power > herbivore->get_weight())
        {
            herbivore->die();
            power += 10;
            cout << "Тигр поймал лося. Сила тигра: " << power << endl;
        }
        else
        {
            power -= 10;
            cout << "Тигр промахнулся. Сила тигра: " << power << endl;
        }
    }
};

class Eurasia : public Continent {
public:
    Herbivore* create_herbivore() override
    {
        return new Elk();
    }
    Carnivore* create_carnivore() override 
    {
        return new Tiger();
    }
};

// === Мир животных ===
class AnimalWorld {
private:
    Herbivore* herbivore;
    Carnivore* carnivore;
    string continent_name;

public:
    AnimalWorld(Continent* continent, const string& name) : continent_name(name)
    {
        herbivore = continent->create_herbivore();
        carnivore = continent->create_carnivore();
    }

    ~AnimalWorld()
    {
        delete herbivore;
        delete carnivore;
    }

    void herbivore_eat()
    {
        if (herbivore->is_alive())
            herbivore->eat_grass();
        else
            cout << "Травоядное уже не в состоянии есть" << endl;
    }

    void carnivore_eat()
    {
        carnivore->eat(herbivore);
    }

    void info()
    {
        cout << "Вы выбрали мир: " << continent_name << endl;
    }
};

// === Меню ===
void menu() {
    cout << "\n=== Меню ===" << endl;
    cout << "1. Африка" << endl;
    cout << "2. Северная Америка" << endl;
    cout << "3. Евразия" << endl;
    cout << "4. Травоядное ест" << endl;
    cout << "5. Хищник охотится" << endl;
    cout << "6. Выход" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    Continent* continent = nullptr;
    AnimalWorld* world = nullptr;
    int choice;
    bool running = true;

    while (running) {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            delete world;
            delete continent;
            continent = new Africa();
            world = new AnimalWorld(continent, "Африка");
            world->info();
            break;
        case 2:
            delete world;
            delete continent;
            continent = new NorthAmerica();
            world = new AnimalWorld(continent, "Северная Америка");
            world->info();
            break;
        case 3:
            delete world;
            delete continent;
            continent = new Eurasia();
            world = new AnimalWorld(continent, "Евразия");
            world->info();
            break;
        case 4:
            if (world)
                world->herbivore_eat();
            else
                cout << "Сначала выбери континент" << endl;
            break;
        case 5:
            if (world)
                world->carnivore_eat();
            else
                cout << "Сначала выбери континент" << endl;
            break;
        case 6:
            running = false;
            break;
        default:
            cout << "Некорректный выбор" << endl;
        }

        cout << endl;
    }

    delete world;
    delete continent;
    return 0;
}
