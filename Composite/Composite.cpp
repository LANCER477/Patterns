#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component {
protected:
    string name;
    double price;

public:
    Component(string name, double price) : name(name), price(price) {}

    virtual void Add(Component* c) = 0;
    virtual void Remove(Component* c) = 0;
    virtual void Display(int depth) = 0;
    virtual double GetTotalPrice() = 0;
};

class Composite : public Component {
    vector<Component*> children;

public:
    Composite(string name, double price = 0) : Component(name, price) {}

    void Add(Component* comp) override {
        children.push_back(comp);
    }

    void Remove(Component* comp) override {
        auto it = find(children.begin(), children.end(), comp);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    void Display(int depth) override {
        cout << name << " (Цена: " << price << ")\n";

        for (auto child : children) {
            child->Display(depth + 2);
        }
    }

    double GetTotalPrice() override {
        double total = price;

        for (auto child : children) {
            total += child->GetTotalPrice();
        }

        return total;
    }
};

class Leaf : public Component {
public:
    Leaf(string name, double price) : Component(name, price) {}

    void Add(Component* c) override {
        cout << "Невозможно добавить в: " << name << endl;
    }

    void Remove(Component* c) override {
        cout << "Невозможно удалить из: " << name << endl;
    }

    void Display(int depth) override {
        cout << name << " (Цена: " << price << ")\n";
    }

    double GetTotalPrice() override {
        return price;
    }
};

int main() {
    setlocale(LC_ALL, "");

    Component* office = new Composite("Офис");

    
    Component* reception = new Composite("Приемная");
    reception->Add(new Leaf("Журнальный столик", 150));
    reception->Add(new Leaf("Мягкий диван", 620));

    Component* secDesk = new Composite("Стол секретаря");
    secDesk->Add(new Leaf("Компьютер", 950));
    secDesk->Add(new Leaf("Офисный инструментарий", 180));
    reception->Add(secDesk);

    reception->Add(new Leaf("Кулер с водой", 270));
    office->Add(reception);

    
    Component* room1 = new Composite("Аудитория 1");
    room1->Add(new Leaf("10 столов", 1100));
    room1->Add(new Leaf("Доска", 130));

    Component* teachDesk = new Composite("Стол учителя");
    teachDesk->Add(new Leaf("Компьютер", 870));
    room1->Add(teachDesk);

    room1->Add(new Leaf("Плакаты великих математиков", 65));
    office->Add(room1);

    
    Component* dining = new Composite("Столовая");
    dining->Add(new Leaf("Кофейный автомат", 890));
    dining->Add(new Leaf("Стол с 4 стульями", 340));
    dining->Add(new Leaf("Холодильник", 750));
    dining->Add(new Leaf("Умывальник", 280));
    office->Add(dining);

    cout << "\nСТРУКТУРА ОБЪЕКТОВ В ОФИСЕ:\n\n";
    office->Display(1);

    cout << "\n===============================\n";
    cout << "Общая стоимость: " << office->GetTotalPrice() << " $\n";
    cout << "===============================\n";

    system("pause");
    return 0;
}
