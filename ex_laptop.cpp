/*
Name: NGUYEN QUOCS BAO KHANG
Class: 24110FIE4
ID: 24110099
DOB: 25/09/2006
*/
#include <iostream>
#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    int ram;
    int storage;
    int gpu;

public:
    Laptop(string brand, string model, int ram, int storage, int gpu)
    {
        this->brand = brand;
        this->model = model;
        this->ram = ram;
        this->storage = storage;
        this->gpu = gpu;
    }
    void checkRAM(int requiredRAM) {
        if (ram >= requiredRAM) {
            cout << "This laptop has enough RAM to run the software." << endl;
        }
        else {
            cout << "This laptop does not have enough RAM to run the software." << endl;
        }
    }
    void checkGPU(int requiredGPU) {
        if (gpu >= requiredGPU) {
            cout << "This laptop has enough GPU power to play the game." << endl;
        }
        else {
            cout << "This laptop does not have enough GPU power to play the game." << endl;
        }
    }
    void upgradeRAM(int additionalRAM) {
        if (additionalRAM > 0) {
            ram += additionalRAM;
            cout << "RAM has been upgraded. New RAM: " << ram << " GB" << endl;
        }
        else {
            cout << "Invalid RAM upgrade value." << endl;
        }
    }
    void displayInfo() {
        cout << "-------------------------------------------------------\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "GPU: " << gpu << " GB" << endl;
    }
};

int main() {
    Laptop myLaptop("Dell", "XPS 15", 8, 512, 4);
    myLaptop.displayInfo();
    myLaptop.checkRAM(16);
    myLaptop.checkGPU(6); cout << endl;
    myLaptop.upgradeRAM(8); 
    myLaptop.displayInfo();
    return 0;
}
