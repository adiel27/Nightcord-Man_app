#include "Artis.hpp"

Artis::Artis(string nm, string genre, bool kontrak, sql::Connection* conn) {
    nama = nm;
    tanggalLahir = tgl;
    genreMusik = genre;
    statusKontrak = kontrak;
    conn = conn;
}

void Artis::simpanKeDatabase() {
    try {
        sql::PreparedStatment* pstmt;
        pstmt = con->prepareStatement("INSERT INTO artis (nama, tanggal_lahir, genre_musik,
        status_kontrak) VALUES (?, ?, ?, ?)");
        pstmt->setString(1, nama);
        pstmt->setString(2, tanggalLahir);
        pstmt->setString(3, genreMusik);
        pstmt->setBoolean(4, statusKontrak);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data artis berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void Artis::tampilkaninfo() {
    cout << "Nama: " << nama << endl;
    cout << "Tanggal Lahir: " << tanggalLahir << endl;
    cout << "Status kontrak: " << (statusKontrak ? "Aktif" : "Tidak Aktif") << endl;
}