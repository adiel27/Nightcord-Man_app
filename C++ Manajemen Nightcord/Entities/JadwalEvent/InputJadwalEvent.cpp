#include "Entities/JadwalEvent/InputJadwalEvent.hpp"
#include <iostream>

JadwalEvent* InputJadwalEvent::masukkanData(sql::Connection* con) {
    int idArtis;
    std::string nama, tanggal, waktu, lokasi, jenis;

    std::cout << "Masukkan ID Artis: ";
    std::cin >> idArtis;
    std::cin.ignore();

    std::cout << "Masukkan Nama Acara: ";
    std::getline(std::cin, nama);

    std::cout << "Masukkan Tanggal (YYYY-MM-DD): ";
    std::cin >> tanggal;

    std::cout << "Masukkan Waktu (HH:MM): ";
    std::cin >> waktu;
    std::cin.ignore();

    std::cout << "Masukkan Lokasi Acara: ";
    std::getline(std::cin, lokasi);

    std::cout << "Masukkan Jenis Acara (Publik/Private/etc): ";
    std::getline(std::cin, jenis);

    auto* jadwal = new JadwalEvent(idArtis, nama, tanggal, waktu, lokasi, jenis, con);
    jadwal->simpan();  // langsung simpan ke DB

    return jadwal;
}
