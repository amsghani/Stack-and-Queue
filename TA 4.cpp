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
    StackBuku() {
        topPtr = nullptr;
    }

    bool isEmpty() {
        return topPtr == nullptr;
    }

    void tambahBuku(string judul) {
        Node* newNode = new Node;
        newNode->judulBuku = judul;
        newNode->next = topPtr;
        topPtr = newNode;
        cout << "Buku \"" << judul << "\" berhasil ditambahkan ke tumpukan.\n";
    }

    void ambilBuku() {
        if (isEmpty()) {
            cout << "Tumpukan kosong, tidak ada buku untuk diambil.\n";
            return;
        }
        Node* temp = topPtr;
        cout << "Buku \"" << temp->judulBuku << "\" diambil dari tumpukan.\n";
        topPtr = topPtr->next;
        delete temp;
    }

    void lihatBukuTeratas() {
        if (isEmpty()) {
            cout << "Tidak ada buku di tumpukan.\n";
        } else {
            cout << "Buku teratas saat ini: \"" << topPtr->judulBuku << "\"\n";
        }
    }

    void tampilkanTumpukan() {
        if (isEmpty()) {
            cout << "Tidak ada buku di tumpukan.\n";
            return;
        }
        cout << "\nDaftar Buku dalam Tumpukan:\n";
        Node* current = topPtr;
        int nomor = 1;
        while (current != nullptr) {
            cout << nomor++ << ". " << current->judulBuku << endl;
            current = current->next;
        }
    }
};

int main() {
    StackBuku perpustakaan;
    int pilihan;
    string judul;

    do {
        cout << "\n=== SISTEM PENGELOLAAN TUMPUKAN BUKU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku ke Tumpukan\n";
        cout << "2. Ambil Buku dari Tumpukan\n";
        cout << "3. Lihat Buku Teratas\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Masukkan judul buku: ";
            getline(cin, judul);
            perpustakaan.tambahBuku(judul);
            break;
        case 2:
            perpustakaan.ambilBuku();
            break;
        case 3:
            perpustakaan.lihatBukuTeratas();
            break;
        case 4:
            perpustakaan.tampilkanTumpukan();
            break;
        case 5:
            cout << "Program selesai. Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}