#include "Entities/Kontrak/InputKontrak.hpp"
#include <iostream>

Kontrak* InputKontrak::masukkanData(sql::Connection* con) {
    int idArtis;
    std::string tanggalMulai, tanggalAkhir, ketentuan;
    double nilaiKontrak;

    std::cout << "Masukkan ID Artis: ";
    std::cin >> idArtis;

    std::cout << "Tanggal Mulai (YYYY-MM-DD): ";
    std::cin >> tanggalMulai;

    std::cout << "Tanggal Akhir (YYYY-MM-DD): ";
    std::cin >> tanggalAkhir;

    std::cout << "Nilai Kontrak: ";
    std::cin >> nilaiKontrak;
    std::cin.ignore();

    std::cout << "Ketentuan Kontrak: ";
    std::getline(std::cin, ketentuan);

    Kontrak* k = new Kontrak(idArtis, tanggalMulai, tanggalAkhir, nilaiKontrak, ketentuan, con);
    return k;
}
