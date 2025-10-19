#include <iostream>
#include <string>
using namespace std;

struct Node {
    string judulBuku;
    Node* next;
};

class StackBuku {
private:
    Node* topPtr;

public:
    StackBuku() : topPtr(nullptr) {}

    bool isEmpty() { 
        return topPtr == nullptr; 
    }

    void operasi(int pilihan) {
        string judul;
        Node* temp;

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul buku: ";
                getline(cin, judul);
                temp = new Node{judul, topPtr};
                topPtr = temp;
                cout << "Buku \"" << judul << "\" berhasil ditambahkan.\n";
                break;

            case 2:
                if (isEmpty()) {
                    cout << "Tumpukan kosong.\n";
                    break;
                }
                temp = topPtr;
                cout << "Buku \"" << temp->judulBuku << "\" diambil.\n";
                topPtr = topPtr->next;
                delete temp;
                break;

            case 3:
                if (isEmpty())
                    cout << "Tidak ada buku di tumpukan.\n";
                else
                    cout << "Buku teratas: \"" << topPtr->judulBuku << "\"\n";
                break;

            case 4:
                if (isEmpty()) {
                    cout << "Tumpukan kosong.\n";
                    break;
                }
                cout << "\nDaftar Buku dalam Tumpukan:\n";
                temp = topPtr;
                int i = 1;
                while (temp) {
                    cout << i++ << ". " << temp->judulBuku << endl;
                    temp = temp->next;
                }
                break;
        }
    }
};

int main() {
    StackBuku perpustakaan;
    int pilihan;

    do {
        cout << "\n=== SISTEM TUMPUKAN BUKU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Ambil Buku\n";
        cout << "3. Lihat Buku Teratas\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan >= 1 && pilihan <= 4)
            perpustakaan.operasi(pilihan);
        else if (pilihan == 5)
            cout << "Program selesai. Terima kasih!\n";
        else
            cout << "Pilihan tidak valid.\n";

    } while (pilihan != 5);

    return 0;
}