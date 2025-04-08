#include <iostream>
#include <string>

using namespace std;

// Интерфейс компонента
class IComponent abstract {
public:
    virtual string GetLabel() abstract;
    virtual string DescribeSpecs() abstract;
};

// Видеокарта
class GPU : public IComponent {
private:
    string name, chipModel, vramSize, coreClock;

public:
    GPU(string name, string chipModel, string vramSize, string coreClock)
        : name(name), chipModel(chipModel), vramSize(vramSize), coreClock(coreClock) {
    }

    string GetLabel() override {
        return name;
    }

    string DescribeSpecs() override {
        return "Модель GPU: " + chipModel + "\n" +
            "Память: " + vramSize + "\n" +
            "Частота: " + coreClock + "\n";
    }
};

// Процессор
class CPU : public IComponent {
private:
    string name, baseFreq, cacheSize;
    int threads;

public:
    CPU(string name, int threads, string baseFreq, string cacheSize)
        : name(name), threads(threads), baseFreq(baseFreq), cacheSize(cacheSize) {
    }

    string GetLabel() override {
        return name;
    }

    string DescribeSpecs() override {
        return "Потоки: " + to_string(threads) + "\n" +
            "Частота: " + baseFreq + "\n" +
            "Кэш: " + cacheSize + "\n";
    }
};

// Жесткий диск
class HDD : public IComponent {
private:
    string name, size, driveType, connector;

public:
    HDD(string name, string size, string driveType, string connector)
        : name(name), size(size), driveType(driveType), connector(connector) {
    }

    string GetLabel() override {
        return name;
    }

    string DescribeSpecs() override {
        return "Размер: " + size + "\n" +
            "Тип: " + driveType + "\n" +
            "Интерфейс: " + connector + "\n";
    }
};

// Оперативная память
class RAM : public IComponent {
private:
    string name, capacity, memType, speed;

public:
    RAM(string name, string capacity, string memType, string speed)
        : name(name), capacity(capacity), memType(memType), speed(speed) {
    }

    string GetLabel() override {
        return name;
    }

    string DescribeSpecs() override {
        return "Объем: " + capacity + "\n" +
            "Тип: " + memType + "\n" +
            "Скорость: " + speed + "\n";
    }
};

// Абстракция отчета
class ReportBuilder abstract {
protected:
    IComponent* component;

public:
    ReportBuilder(IComponent* component) : component(component) {}

    void AssignComponent(IComponent* component) {
        this->component = component;
    }

    virtual void Output() abstract;
};

// Простой отчет
class BasicReport : public ReportBuilder {
public:
    BasicReport(IComponent* component) : ReportBuilder(component) {}

    void Output() override {
        cout << "\n -|СВОДКА ПО КОМПОНЕНТУ|- \n";
        cout << "\n-----------------------\n";
        cout << "Устройство: " << component->GetLabel() << "\n";
        cout << component->DescribeSpecs();
        cout << "\n-----------------------\n";
    }
};

// Подробный отчет
class FullReport : public ReportBuilder {
public:
    FullReport(IComponent* component) : ReportBuilder(component) {}

    void Output() override {
        cout << "-|ОТЧЕТ ОБ УСТРОЙСТВЕ-|\n";
        cout << "-----------------------\n";
        cout << "Название: " << component->GetLabel() << "\n\n";
        cout << "------------------\n";
        cout << "-|ХАРАКТЕРИСТИКИ-|\n";
        cout << component->DescribeSpecs();
        cout << "-----------------\n\n";
    }
};

// Функция показа отчета
void GenerateComponentReport(IComponent* comp, ReportBuilder* reporter) {
    reporter->AssignComponent(comp);
    reporter->Output();
}

int main() {
    setlocale(LC_ALL, "");

    IComponent* card = new GPU("MSI RTX 4070 Super", "AD104", "12GB GDDR6X", "2655 MHz");
    IComponent* chip = new CPU("AMD Ryzen 9700X3D", 20, "4.5 GHz", "25MB");
    IComponent* drive = new HDD("Samsung 980 Pro", "1TB", "SSD", "PCIe 4.0");
    IComponent* memory = new RAM("Kingston Fury", "32GB", "DDR5", "6000 MHz");

    ReportBuilder* basic = new BasicReport(nullptr);
    ReportBuilder* full = new FullReport(nullptr);

    GenerateComponentReport(card, basic);
    GenerateComponentReport(chip, full);
    GenerateComponentReport(drive, basic);
    GenerateComponentReport(memory, full);

    delete card;
    delete chip;
    delete drive;
    delete memory;
    delete basic;
    delete full;

    system("PAUSE");
    return 0;
}
