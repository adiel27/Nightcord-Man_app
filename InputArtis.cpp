#include "InputArtis.hpp"

Artis InputArtis::masukkanData(sql::Connection* con) {
    string nama, tanggalLahir, genre;
    bool statusKontrak;

    cout << "Masukkan Nama Artis: ";
    getline(cin, nama);
    
    cout << "Masukkan Tanggal Lahir (YYYY-MM-DD): ";
    cin >> tanggalLahir;
    
    cout << "Masukkan Genre Musik: ";
    cin.ignore();
    getline(cin, genre);
    
    cout << "Status Kontrak (1 = Aktif, 0 = Tidak Aktif): ";
    cin >> statusKontrak;

    Artis artisBaru(nama, tanggalLahir, genre, statusKontrak, con);
    artisBaru.simpanKeDatabase();

    return artisBaru;
}
