#include "Entities/MediaPromosi/InputMediaPromosi.hpp"

MediaPromosi InputMediaPromosi::masukkanData(sql::Connection* con) {
    int idArtis;
    string namaKampanye, platform, tanggalMulai, tanggalAkhir, strategi;

    cout << "Masukkan ID Artis: ";
    cin >> idArtis;

    cout << "Masukkan Nama Kampanye: ";
    cin.ignore();
    getline(cin, namaKampanye);

    cout << "Masukkan Platform (YouTube, Instagram, TV, dll.): ";
    getline(cin, platform);

    cout << "Masukkan Tanggal Mulai (YYYY-MM-DD): ";
    cin >> tanggalMulai;

    cout << "Masukkan Tanggal Akhir (YYYY-MM-DD): ";
    cin >> tanggalAkhir;

    cout << "Masukkan Strategi Promosi: ";
    cin.ignore();
    getline(cin, strategi);

    MediaPromosi kampanyeBaru(idArtis, namaKampanye, platform, tanggalMulai, tanggalAkhir, strategi, con);
    kampanyeBaru.simpanKampanye();

    return kampanyeBaru;
}
