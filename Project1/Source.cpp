#include <iostream>
#include <string>

using namespace std;

class PC
{
    string CPU;
    string RAM;
    string GPU;
    string SSD;
    string Motherboard;
public:
    void SetCPU(string cpu)
    { 
        this->CPU = cpu;
    }
    string GetCPU() 
    { 
        return this->CPU; 
    }

    void SetRAM(string ram)
    { 
        this->RAM = ram;
    }
    string GetRAM()
    { 
        return this->RAM;
    }

    void SetGPU(string gpu) 
    { 
        this->GPU = gpu;
    }
    string GetGPU() 
    { 
        return this->GPU;
    }

    void SetSSD(string ssd) 
    { 
        this->SSD = ssd;
    }
    string GetSSD()
    { 
        return this->SSD;
    }

    void SetMotherboard(string motherboard)
    { 
        this->Motherboard = motherboard;
    }
    string GetMotherboard()
    {
        return this->Motherboard;
    }

    void ShowPC()
    {
        cout << "PC Configuration: " << endl;
        cout << " CPU: " << CPU << endl;
        cout << " RAM: " << RAM << endl;
        cout << " GPU: " << GPU << endl;
        cout << " SSD: " << SSD << endl;
        cout << " Motherboard: " << Motherboard << endl;
    }
};

class PCBuilder
{
protected:
    PC pc;
public:
    PC GetPC()
    { 
        return pc;
    }
    virtual void BuildCPU() = 0;
    virtual void BuildRAM() = 0;
    virtual void BuildGPU() = 0;
    virtual void BuildSSD() = 0;
    virtual void BuildMotherboard() = 0;
};

class GamingPCBuilder : public PCBuilder
{
public:
    void BuildCPU() override 
    {
        pc.SetCPU("AMD Ryzen 9700x3D");
    }
    void BuildRAM() override 
    {
        pc.SetRAM("Kingston FURY 32GB");
    }
    void BuildGPU() override 
    {
        pc.SetGPU("NVIDIA RTX 5090");
    }
    void BuildSSD() override 
    { 
        pc.SetSSD("Samsung 990 PRO 2TB ");
    }
    void BuildMotherboard() override
    { 
        pc.SetMotherboard("MSI PRO X870");
    }
};

class DefaultPCBuilder : public PCBuilder
{
public:
    void BuildCPU() override 
    {
        pc.SetCPU("AMD Ryzen 5600x");
    }
    void BuildRAM() override 
    {
        pc.SetRAM("G-SKILL 16GB");
    }
    void BuildGPU() override
    {
        pc.SetGPU("NVIDIA RTX 3060");
    }
    void BuildSSD() override
    {
        pc.SetSSD("Samsung 970 512GB");
    }
    void BuildMotherboard() override
    {
        pc.SetMotherboard("Asus B550M");
    }
};

class PCempty
{
    PCBuilder* pcBuilder;
public:
    void SetPCBuilder(PCBuilder* builder) 
    { 
        pcBuilder = builder;
    }
    PC GetPC() 
    { 
        return pcBuilder->GetPC();
    }
    void ConstructPC()
    {
        pcBuilder->BuildCPU();
        pcBuilder->BuildRAM();
        pcBuilder->BuildGPU();
        pcBuilder->BuildSSD();
        pcBuilder->BuildMotherboard();
    }
};

void client(PCBuilder* builder)
{
    PCempty empty;
    empty.SetPCBuilder(builder);
    empty.ConstructPC();
    PC pc = empty.GetPC();
    pc.ShowPC();
}

int main()
{
    PCBuilder* builder = new GamingPCBuilder();
    client(builder);
    delete builder;

    builder = new DefaultPCBuilder();
    client(builder);
    delete builder;

    system("pause");
    return 0;
}
