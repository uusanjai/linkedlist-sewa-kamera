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

void showKamera() {
    if (head == nullptr) {
        cout << endl << ">> Tidak ada kamera dalam inventaris." << endl;
        return;
    }
    Kamera* temp = head;
    int i = 1;
    cout << endl << "--- Daftar Kamera ---" << endl;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->nama << " - Rp " << temp->hargaSewa << "/hari" << endl;
        temp = temp->next;
    }
    cout << "---------------------" << endl;
}

void addKamera(string nama, int harga) {
    Kamera* baru = new Kamera(nama, harga);
    if (head == nullptr) {
        head = baru;
    } else {
        Kamera* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << ">> Kamera '" << nama << "' berhasil ditambahkan." << endl;
}

void deleteKamera(string nama) {
    if (head == nullptr) {
        cout << ">> Inventaris kosong." << endl;
        return;
    }

    Kamera *temp = head, *prev = nullptr;
    while (temp != nullptr && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << ">> Kamera '" << nama << "' tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << ">> Kamera '" << nama << "' berhasil dihapus." << endl;
}

void insertKamera(string nama, int harga, int posisi) {
    Kamera* baru = new Kamera(nama, harga);

    if (posisi == 1) {
        baru->next = head;
        head = baru;
        cout << ">> Kamera '" << nama << "' disisipkan di posisi 1." << endl;
        return;
    }

    Kamera* temp = head;
    for (int i = 1; i < posisi - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid." << endl;
        delete baru;
        return;
    }

    baru->next = temp->next;
    temp->next = baru;
    cout << ">> Kamera '" << nama << "' disisipkan di posisi " << posisi << "." << endl;
}
