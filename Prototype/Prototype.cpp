#include <iostream>
#include <string>
using namespace std;

class AbstractComponent
{
protected:
    string producer;
public:
    virtual ~AbstractComponent() {}
    void SetProducer(const string& p)
    {
        producer = p;
    }
    string GetProducer() const
    {
        return producer;
    }
    virtual AbstractComponent* Clone() const = 0;
};

class LoadBearingStructure : public AbstractComponent
{
    string material;
public:
    void SetMaterial(const string& m)
    {
        material = m;
    }
    string GetMaterial() const
    {
        return material;
    }
    AbstractComponent* Clone() const override
    {
        return new LoadBearingStructure(*this);
    }
};

class ControlUnit : public AbstractComponent
{
    string type;
public:
    void SetType(const string& t)
    {
        type = t;
    }
    string GetType() const
    {
        return type;
    }
    AbstractComponent* Clone() const override
    {
        return new ControlUnit(*this);
    }
};

class Engine : public AbstractComponent
{
    int horsepower;
public:
    void SetHorsePower(int hp)
    {
        horsepower = hp;
    }
    int GetHorsePower() const
    {
        return horsepower;
    }
    AbstractComponent* Clone() const override
    {
        return new Engine(*this);
    }
};

class Transmission : public AbstractComponent
{
    string transmissionType;
public:
    void SetTransmissionType(const string& t)
    {
        transmissionType = t;
    }
    string GetTransmissionType() const
    {
        return transmissionType;
    }
    AbstractComponent* Clone() const override
    {
        return new Transmission(*this);
    }
};

class SuspensionSystem : public AbstractComponent
{
    string suspensionType;
public:
    void SetSuspensionType(const string& t)
    {
        suspensionType = t;
    }
    string GetSuspensionType() const
    {
        return suspensionType;
    }
    AbstractComponent* Clone() const override
    {
        return new SuspensionSystem(*this);
    }
};

class ElectricalEquipment : public AbstractComponent
{
    int voltage;
public:
    void SetVoltage(int v)
    {
        voltage = v;
    }
    int GetVoltage() const
    {
        return voltage;
    }
    AbstractComponent* Clone() const override
    {
        return new ElectricalEquipment(*this);
    }
};

class Car
{
    LoadBearingStructure* structure;
    ControlUnit* controlUnit;
    Engine* engine;
    Transmission* transmission;
    SuspensionSystem* suspension;
    ElectricalEquipment* electrical;
public:
    Car()
        : structure(nullptr), controlUnit(nullptr), engine(nullptr),
        transmission(nullptr), suspension(nullptr), electrical(nullptr)
    {
    }

    ~Car()
    {
        delete structure;
        delete controlUnit;
        delete engine;
        delete transmission;
        delete suspension;
        delete electrical;
    }

    void SetStructure(LoadBearingStructure* s)
    {
        structure = s;
    }

    void SetControlUnit(ControlUnit* cu)
    {
        controlUnit = cu;
    }

    void SetEngine(Engine* e)
    {
        engine = e;
    }

    void SetTransmission(Transmission* t)
    {
        transmission = t;
    }

    void SetSuspension(SuspensionSystem* s)
    {
        suspension = s;
    }

    void SetElectrical(ElectricalEquipment* e)
    {
        electrical = e;
    }

    Car* Clone() const
    {
        Car* clone = new Car();
        if (structure) clone->SetStructure(static_cast<LoadBearingStructure*>(structure->Clone()));
        if (controlUnit) clone->SetControlUnit(static_cast<ControlUnit*>(controlUnit->Clone()));
        if (engine) clone->SetEngine(static_cast<Engine*>(engine->Clone()));
        if (transmission) clone->SetTransmission(static_cast<Transmission*>(transmission->Clone()));
        if (suspension) clone->SetSuspension(static_cast<SuspensionSystem*>(suspension->Clone()));
        if (electrical) clone->SetElectrical(static_cast<ElectricalEquipment*>(electrical->Clone()));
        return clone;
    }

    void Print() const
    {
        cout << "Car configuration:\n";
        if (structure) cout << "Load-Bearing Structure: " << structure->GetProducer() << ", Material: " << structure->GetMaterial() << endl;
        if (controlUnit) cout << "Control Unit: " << controlUnit->GetProducer() << ", Type: " << controlUnit->GetType() << endl;
        if (engine) cout << "Engine: " << engine->GetProducer() << ", Horsepower: " << engine->GetHorsePower() << endl;
        if (transmission) cout << "Transmission: " << transmission->GetProducer() << ", Type: " << transmission->GetTransmissionType() << endl;
        if (suspension) cout << "Suspension System: " << suspension->GetProducer() << ", Suspension: " << suspension->GetSuspensionType() << endl;
        if (electrical) cout << "Electrical Equipment: " << electrical->GetProducer() << ", Voltage: " << electrical->GetVoltage() << "V" << endl;
    }
};

Car* CreateCrossover()
{
    Car* car = new Car();

    auto* structure = new LoadBearingStructure();
    structure->SetProducer("Audi AG");
    structure->SetMaterial("Aluminum Space Frame");
    car->SetStructure(structure);

    auto* control = new ControlUnit();
    control->SetProducer("Bosch");
    control->SetType("Audi Drive Select");
    car->SetControlUnit(control);

    auto* engine = new Engine();
    engine->SetProducer("Audi");
    engine->SetHorsePower(340);
    car->SetEngine(engine);

    auto* transmission = new Transmission();
    transmission->SetProducer("Audi");
    transmission->SetTransmissionType("7-Speed S tronic");
    car->SetTransmission(transmission);

    auto* suspension = new SuspensionSystem();
    suspension->SetProducer("Audi");
    suspension->SetSuspensionType("Adaptive Air Suspension");
    car->SetSuspension(suspension);

    auto* electrical = new ElectricalEquipment();
    electrical->SetProducer("Continental");
    electrical->SetVoltage(48);
    car->SetElectrical(electrical);

    return car;
}

int main()
{
    Car* audiCrossover = CreateCrossover();
    audiCrossover->Print();

    cout << "\n--- Cloning the car ---\n";
    Car* cloneCar = audiCrossover->Clone();
    cloneCar->Print();

    delete audiCrossover;
    delete cloneCar;

    return 0;
}
