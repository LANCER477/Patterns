#include <string>
#include <iostream>

using namespace std;

class IRoute {
public:
    virtual void SetPrice(double price) = 0;
    virtual void SetTime(int minutes) = 0;
    virtual void GoToAirport() = 0;
    virtual ~IRoute() {}
};

class AirFlight : public IRoute {
private:
    double cost;
    int duration;

public:
    void SetPrice(double price) override {
        cost = price;
    }

    void SetTime(int minutes) override {
        duration = minutes;
    }

    void GoToAirport() override {
        cout << "Flying to airport via airplane" << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Time: " << duration << " minutes " << endl;
        cout << endl;
    }
};

class EcoRide : public IRoute {
private:
    double cost;
    int duration;

public:
    void SetPrice(double price) override {
        cost = price;
    }

    void SetTime(int minutes) override {
        duration = minutes;
    }

    void GoToAirport() override {
        cout << "Riding a bicycle to the airport" << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Time: " << duration << " minutes " << endl;
        cout << endl;
    }
};

class PublicBus : public IRoute {
private:
    double cost;
    int duration;

public:
    void SetPrice(double price) override {
        cost = price;
    }

    void SetTime(int minutes) override {
        duration = minutes;
    }

    void GoToAirport() override {
        cout << "Taking a bus to the airport" << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Time: " << duration << " minutes " << endl;
        cout << endl;
    }
};

class Cab : public IRoute {
private:
    double cost;
    int duration;

public:
    void SetPrice(double price) override {
        cost = price;
    }

    void SetTime(int minutes) override {
        duration = minutes;
    }

    void GoToAirport() override {
        cout << "Going by taxi to the airport" << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Time: " << duration << " minutes " << endl;
        cout << endl;
    }
};

class TripManager {
private:
    IRoute* currentOption;

public:
    TripManager() : currentOption(nullptr) {}

    void Choose(IRoute* option) {
        currentOption = option;
    }

    void SetPrice(double price) {
        if (currentOption)
            currentOption->SetPrice(price);
    }

    void SetTime(int minutes) {
        if (currentOption)
            currentOption->SetTime(minutes);
    }

    void Execute() {
        if (currentOption)
            currentOption->GoToAirport();
        else
            cout << "No option selected" << endl;
    }
};

int main() {
    TripManager manager;

    EcoRide bike;
    PublicBus bus;
    Cab taxi;
    AirFlight plane;

    manager.Choose(&bike);
    manager.SetPrice(0);
    manager.SetTime(120);
    cout << "Option 1: Bike - cheap ride" << endl;
    manager.Execute();

    manager.Choose(&bus);
    manager.SetPrice(2);
    manager.SetTime(45);
    cout << "Option 2: Bus - budget option" << endl;
    manager.Execute();

    manager.Choose(&taxi);
    manager.SetPrice(25);
    manager.SetTime(20);
    cout << "Option 3: Taxi - fast and comfy" << endl;
    manager.Execute();

    manager.Choose(&plane);
    manager.SetPrice(150);
    manager.SetTime(10);
    cout << "Option 4: Plane - pricey" << endl;
    manager.Execute();

    return 0;
}