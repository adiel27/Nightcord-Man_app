#include "JadwalEvent.hpp"

JadwalEvent::JadwalEvent(int idA, string nama, string tgl, string wkt, string lok, string jenis, sql::Connection* conn) {
    idArtis = idA;
    namaAcara = nama;
    tanggal = tgl;
    waktu = wkt;
    lokasi = lok;
    jenisAcara = jenis;
    con = conn;
}

void JadwalEvent::simpanEvent() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO jadwal_event (id_artis, nama_acara, tanggal, waktu, lokasi, jenis_acara) VALUES (?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setString(2, namaAcara);
        pstmt->setString(3, tanggal);
        pstmt->setString(4, waktu);
        pstmt->setString(5, lokasi);
        pstmt->setString(6, jenisAcara);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Event berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void JadwalEvent::tampilkanEvent() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Nama Acara: " << namaAcara << endl;
    cout << "Tanggal: " << tanggal << endl;
    cout << "Waktu: " << waktu << endl;
    cout << "Lokasi: " << lokasi << endl;
    cout << "Jenis Acara: " << jenisAcara << endl;
}
