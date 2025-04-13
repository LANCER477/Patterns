#include <iostream>
using namespace std;

class PowerSupply {
public:
    void enable() {
        cout << "PowerSupply: Supply power" << endl;
    }

    void disable() {
        cout << "PowerSupply: Shut down" << endl;
    }
};

class Sensors {
public:
    bool voltageOK() {
        cout << "Sensors: Check voltage" << endl;
        return true;
    }

    bool temperatureOK() {
        cout << "Sensors: Check all systems temperature" << endl;
        return true;
    }

    void runFullTempScan() {
        cout << "Sensors: Check all systems temperature" << endl;
    }
};

class GPU {
public:
    void initialize() {
        cout << "GPU: Start" << endl;
    }

    void renderStatus() {
        cout << "GPU: Display info" << endl;
    }

    void checkConnection() {
        cout << "GPU: Check monitor connection" << endl;
    }
};

class RAM {
public:
    void initialize() {
        cout << "RAM: Start devices" << endl;
    }

    void cleanup() {
        cout << "RAM: Clear memory" << endl;
    }

    void diagnostic() {
        cout << "RAM: Analyze memory" << endl;
    }
};

class HDD {
public:
    void initialize() {
        cout << "HDD: Start" << endl;
    }

    void halt() {
        cout << "HDD: Stop" << endl;
    }

    void verifyBoot() {
        cout << "HDD: Boot sector verified" << endl; 
    }
};

class OpticalDrive {
public:
    void initialize() {
        cout << "OpticalDrive: Start" << endl;
    }

    void inspectDisk() {
        cout << "OpticalDrive: Check disk presence" << endl;
    }

    void eject() {
        cout << "OpticalDrive: Tray returned to base position" << endl;
    }
};

class PCFacade {
private:
    PowerSupply power;
    Sensors sensors;
    GPU graphics;
    RAM ram;
    HDD storage;
    OpticalDrive optical;

public:
    void startup() {
        cout << "\n=== Powering Up System ===" << endl;
        power.enable();

        sensors.voltageOK();
        sensors.temperatureOK();
        sensors.temperatureOK();

        graphics.initialize();
        graphics.checkConnection();

        sensors.temperatureOK();

        ram.initialize();
        ram.diagnostic();
        graphics.renderStatus();

        optical.initialize();
        optical.inspectDisk();
        graphics.renderStatus();

        storage.initialize();
        storage.verifyBoot();
        graphics.renderStatus();

        sensors.runFullTempScan();
        cout << "=== System Successfully Powered Up ===\n" << endl;
    }

    void shutdown() {
        cout << "=== Beginning Shutdown Procedure ===" << endl;
        storage.halt();
        ram.cleanup();
        ram.diagnostic();
        graphics.renderStatus();
        optical.eject();

        power.enable(); 
        sensors.voltageOK();
        power.disable();

        cout << "=== Shutdown Complete ===" << endl;
    }
};

int main() {
    srand(time(nullptr));
    PCFacade system;
    system.startup();
    system.shutdown();
    return 0;
}
