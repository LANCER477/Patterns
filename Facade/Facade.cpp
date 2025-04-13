#include <iostream>
using namespace std;

class PowerSupply {
public:
    void enable() {
        cout << "PowerSupply: Power is now on" << endl;
    }

    void disable() {
        cout << "PowerSupply: Power off initiated" << endl;
    }
};

class Sensors {
public:
    bool voltageOK() {
        cout << "Sensors: Voltage levels are normal" << endl;
        return true;
    }

    bool temperatureOK() {
        cout << "Sensors: Temperature within limits" << endl;
        return true;
    }

    void runFullTempScan() {
        cout << "Sensors: Temperature scan complete on all units" << endl;
    }
};

class GPU {
public:
    void initialize() {
        cout << "GPU: Initialization successful" << endl;
    }

    void renderStatus() {
        cout << "GPU: Rendering system status" << endl;
    }
};

class RAM {
public:
    void initialize() {
        cout << "RAM: Activated" << endl;
    }

    void cleanup() {
        cout << "RAM: Cleared old data" << endl;
    }

    void diagnostic() {
        cout << "RAM: Diagnostics complete" << endl;
    }
};

class HDD {
public:
    void initialize() {
        cout << "HDD: Spinning up" << endl;
    }

    void halt() {
        cout << "HDD: Stopping operations" << endl;
    }

    void verifyBoot() {
        cout << "HDD: Boot sector verified" << endl;
    }
};

class OpticalDrive {
public:
    void initialize() {
        cout << "OpticalDrive: Ready to read" << endl;
    }

    void inspectDisk() {
        cout << "OpticalDrive: HDD inspection finished" << endl;
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
        graphics.renderStatus();

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

        power.enable(); // Simulate one last system check
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
