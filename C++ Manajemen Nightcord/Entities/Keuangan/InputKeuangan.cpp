#include "Entities/Keuangan/InputKeuangan.hpp"

Keuangan InputKeuangan::masukkanData(sql::Connection* con) {
    int idArtis;
    string jenisTransaksi, tanggal, deskripsi;
    double jumlahUang;

    cout << "Masukkan ID Artis: ";
    cin >> idArtis;

    cout << "Masukkan Jenis Transaksi: ";
    cin.ignore();
    getline(cin, jenisTransaksi);

    cout << "Masukkan Jumlah Uang: ";
    cin >> jumlahUang;

    cout << "Masukkan Tanggal Transaksi (YYYY-MM-DD): ";
    cin >> tanggal;

    cout << "Masukkan Deskripsi Transaksi: ";
    cin.ignore();
    getline(cin, deskripsi);

    Keuangan transaksiBaru(idArtis, jenisTransaksi, jumlahUang, tanggal, deskripsi, con);
    transaksiBaru.simpanTransaksi();

    return transaksiBaru;
}
