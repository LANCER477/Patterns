#include <iostream>
#include <map>
#include <string>

using namespace std;

class MilitaryUnit
{
protected:
    int speed;
    int power;

public:
    virtual ~MilitaryUnit() {}

    int GetSpeed() const { return speed; }
    int GetPower() const { return power; }

    virtual void Show(double x, double y) = 0;
};

class LightInfantry : public MilitaryUnit
{
public:
    LightInfantry()
    {
        speed = 20;
        power = 10;
    }

    void Show(double x, double y) override
    {
        cout << "Light Infantry -> (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Location: X = " << x << ", Y = " << y << endl << endl;
    }
};

class TransportVehicle : public MilitaryUnit
{
public:
    TransportVehicle()
    {
        speed = 70;
        power = 0;
    }

    void Show(double x, double y) override
    {
        cout << "Transport Vehicle -> (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Location: X = " << x << ", Y = " << y << endl << endl;
    }
};

class HeavyArmor : public MilitaryUnit
{
public:
    HeavyArmor()
    {
        speed = 15;
        power = 150;
    }

    void Show(double x, double y) override
    {
        cout << "Heavy Armor -> (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Location: X = " << x << ", Y = " << y << endl << endl;
    }
};

class LightArmor : public MilitaryUnit
{
public:
    LightArmor()
    {
        speed = 50;
        power = 30;
    }

    void Show(double x, double y) override
    {
        cout << "Light Armor -> (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Location: X = " << x << ", Y = " << y << endl << endl;
    }
};

class AircraftUnit : public MilitaryUnit
{
public:
    AircraftUnit()
    {
        speed = 300;
        power = 100;
    }

    void Show(double x, double y) override
    {
        cout << "Aircraft -> (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Location: X = " << x << ", Y = " << y << endl << endl;
    }
};

class UnitFactory
{
private:
    map<string, MilitaryUnit*> unitMap;

public:
    UnitFactory()
    {
        unitMap["LightInfantry"] = new LightInfantry();
        unitMap["TransportVehicle"] = new TransportVehicle();
        unitMap["HeavyArmor"] = new HeavyArmor();
        unitMap["LightArmor"] = new LightArmor();
        unitMap["AircraftUnit"] = new AircraftUnit();
    }

    ~UnitFactory()
    {
        for (auto& entry : unitMap)
        {
            delete entry.second;
        }
    }

    MilitaryUnit* GetUnit(const string& type)
    {
        if (unitMap.find(type) != unitMap.end())
        {
            return unitMap[type];
        }
        return nullptr;
    }
};

int main()
{
    UnitFactory* factory = new UnitFactory();

    cout << "===== Deploying Light Infantry =====" << endl;
    for (int i = 0; i < 5; ++i)
    {
        MilitaryUnit* unit = factory->GetUnit("LightInfantry");
        if (unit)
        {
            unit->Show(10 + i * 3, 15 + i * 2);
        }
    }

    cout << "===== Deploying Transport Vehicles =====" << endl;
    for (int i = 0; i < 3; ++i)
    {
        MilitaryUnit* unit = factory->GetUnit("TransportVehicle");
        if (unit)
        {
            unit->Show(50 + i * 7, 25);
        }
    }

    cout << "===== Deploying Heavy Armor Units =====" << endl;
    for (int i = 0; i < 2; ++i)
    {
        MilitaryUnit* unit = factory->GetUnit("HeavyArmor");
        if (unit)
        {
            unit->Show(90 + i * 10, 40);
        }
    }

    cout << "===== Deploying Light Armor Units =====" << endl;
    for (int i = 0; i < 4; ++i)
    {
        MilitaryUnit* unit = factory->GetUnit("LightArmor");
        if (unit)
        {
            unit->Show(70 + i * 4, 65 + i * 3);
        }
    }

    cout << "===== Deploying Aircraft Units =====" << endl;
    for (int i = 0; i < 3; ++i)
    {
        MilitaryUnit* unit = factory->GetUnit("AircraftUnit");
        if (unit)
        {
            unit->Show(200 + i * 30, 200 + i * 15);
        }
    }

    delete factory;

    system("pause");
    return 0;
}
