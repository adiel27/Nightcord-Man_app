#include "Keuangan.hpp"

Keuangan::Keuangan(int idA, string jenis, double jumlah, string tgl, string desk, sql::Connection* conn) {
    idArtis = idA;
    jenisTransaksi = jenis;
    jumlahUang = jumlah;
    tanggal = tgl;
    deskripsi = desk;
    con = conn;
}

void Keuangan::simpanTransaksi() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO keuangan (id_artis, jenis_transaksi, jumlah_uang, tanggal, deskripsi) VALUES (?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setString(2, jenisTransaksi);
        pstmt->setDouble(3, jumlahUang);
        pstmt->setString(4, tanggal);
        pstmt->setString(5, deskripsi);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Transaksi berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void Keuangan::tampilkanTransaksi() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Jenis Transaksi: " << jenisTransaksi << endl;
    cout << "Jumlah Uang: " << jumlahUang << endl;
    cout << "Tanggal: " << tanggal << endl;
    cout << "Deskripsi: " << deskripsi << endl;
}
