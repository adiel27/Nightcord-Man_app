#include "InputTimManajemen.hpp"

TimManajemen InputTimManajemen::masukkanData(sql::Connection* con) {
    int idArtis;
    string nama, peran, tanggalMulai, kontak;

    cout << "Masukkan ID Artis: ";
    cin >> idArtis;

    cout << "Masukkan Nama Anggota Tim: ";
    cin.ignore();
    getline(cin, nama);

    cout << "Masukkan Peran dalam Manajemen Artis: ";
    getline(cin, peran);

    cout << "Masukkan Tanggal Mulai (YYYY-MM-DD): ";
    cin >> tanggalMulai;

    cout << "Masukkan Kontak Anggota Tim: ";
    cin.ignore();
    getline(cin, kontak);

    TimManajemen timBaru(idArtis, nama, peran, tanggalMulai, kontak, con);
    timBaru.simpanAnggotaTim();

    return timBaru;
}
