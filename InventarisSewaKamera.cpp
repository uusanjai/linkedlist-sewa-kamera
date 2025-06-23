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

void tampilanAwal() {
    cout << "==============================================" << endl;
    cout << "  SELAMAT DATANG DI GALURA SEWA KAMERA" << endl;
    cout << "  \"Galura, Solusi Sewa Kamera Andal dan Terjangkau.\"" << endl;
    cout << "==============================================" << endl;
    cout << "Tekan ENTER untuk masuk ke menu..." << endl;
    cin.ignore();
}

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

void menu() {
    int pilihan, harga, posisi;
    string nama;

    do { 
        cout << endl << "===== MENU INVENTARIS KAMERA =====" << endl;
        cout << "1. Tampilkan Semua Kamera" << endl;
        cout << "2. Tambah Kamera" << endl;
        cout << "3. Hapus Kamera" << endl;
        cout << "4. Sisipkan Kamera di Posisi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                showKamera();
                break;
            case 2:
                cout << "Nama Kamera: ";
                getline(cin, nama);
                cout << "Harga Sewa per Hari: ";
                cin >> harga;
                cin.ignore();
                addKamera(nama, harga);
                break;
            case 3:
                cout << "Nama Kamera yang Dihapus: ";
                getline(cin, nama);
                deleteKamera(nama);
                break;
            case 4:
                cout << "Nama Kamera: ";
                getline(cin, nama);
                cout << "Harga Sewa per Hari: ";
                cin >> harga;
                cout << "Posisi Sisip: ";
                cin >> posisi;
                cin.ignore();
                insertKamera(nama, harga, posisi);
                break;
            case 0:
                cout << ">> Terima kasih, keluar dari program." << endl;
                break;
            default:
                cout << ">> Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);
}

int main() {
    tampilanAwal(); 
    menu();         
    return 0;

}

