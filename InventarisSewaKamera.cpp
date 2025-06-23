#include <iostream>
#include <string>
using namespace std;

class Kamera {
public:
    string nama;
    int hargaSewa;
    Kamera* next;

    Kamera(string n, int h) {
        nama = n;
        hargaSewa = h;
        next = nullptr;
    }
};

Kamera* head = nullptr;
