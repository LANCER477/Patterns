#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IDispatcher
{
public:
    virtual void transmit(const string& msg, class Flyer* source) = 0;
    virtual void connect(class Flyer* flyer) = 0;

    virtual ~IDispatcher() = default;
};

class Flyer
{
protected:
    IDispatcher* tower;
    string identifier;

public:
    Flyer(const string& id, IDispatcher* ctrl)
        : identifier(id), tower(ctrl)
    {
        tower->connect(this);
    }

    void sendMessage(const string& text)
    {
        tower->transmit(text, this);
    }

    virtual void onMessage(const string& text)
    {
        cout << identifier << " получил сообщение: " << text << endl;
    }

    string getID() const { return identifier; }
};

class DispatchTower : public IDispatcher
{
private:
    vector<Flyer*> connections;

public:
    void connect(Flyer* flyer) override
    {
        connections.push_back(flyer);
    }

    void transmit(const string& msg, Flyer* source) override
    {
        for (Flyer* f : connections)
        {
            if (f != source)
            {
                f->onMessage(msg);
            }
        }
    }
};

int main()
{
    DispatchTower mainTower;

    Flyer unit1("Jet-1", &mainTower);
    Flyer unit2("Jet-2", &mainTower);
    Flyer unit3("Jet-3", &mainTower);

    unit1.sendMessage("Прошу разрешение на посадку.");
    unit2.sendMessage("Выполняю круг ожидания.");

    return 0;
}
