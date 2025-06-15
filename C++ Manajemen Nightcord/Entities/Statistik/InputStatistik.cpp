#include "Entities/Statistik/InputStatistik.hpp"

StatistikAnalitik InputStatistik::masukkanData(sql::Connection* con) {
    int idArtis;
    int jumlahStreaming, penjualanAlbum, engagementSosial;
    string periode;

    cout << "Masukkan ID Artis: ";
    cin >> idArtis;

    cout << "Masukkan Jumlah Streaming: ";
    cin >> jumlahStreaming;

    cout << "Masukkan Penjualan Album: ";
    cin >> penjualanAlbum;

    cout << "Masukkan Engagement Sosial (jumlah likes, shares, dll.): ";
    cin >> engagementSosial;

    cout << "Masukkan Periode Analisis (Mingguan, Bulanan, Tahunan): ";
    cin.ignore();
    getline(cin, periode);

    StatistikAnalitik statistikBaru(idArtis, jumlahStreaming, penjualanAlbum, engagementSosial, periode, con);
    statistikBaru.simpanData();

    return statistikBaru;
}
