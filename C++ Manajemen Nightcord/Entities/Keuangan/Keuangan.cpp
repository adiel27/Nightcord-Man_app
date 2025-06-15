#include "Entities/Keuangan/Keuangan.hpp"

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

void Keuangan::editData() {
    string newJenisTransaksi, newTanggal, newDeskripsi;
    double newJumlahUang;

    cout << "Masukkan Jenis Transaksi Baru: ";
    cin.ignore();
    getline(cin, newJenisTransaksi);

    cout << "Masukkan Jumlah Uang Baru: ";
    cin >> newJumlahUang;

    cout << "Masukkan Tanggal Baru (YYYY-MM-DD): ";
    cin >> newTanggal;

    cout << "Masukkan Deskripsi Baru: ";
    cin.ignore();
    getline(cin, newDeskripsi);

    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("UPDATE keuangan SET jenis_transaksi=?, jumlah_uang=?, tanggal=?, deskripsi=? WHERE id_artis=?");
        pstmt->setString(1, newJenisTransaksi);
        pstmt->setDouble(2, newJumlahUang);
        pstmt->setString(3, newTanggal);
        pstmt->setString(4, newDeskripsi);
        pstmt->setInt(5, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data keuangan berhasil diperbarui!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void Keuangan::deleteData() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("DELETE FROM keuangan WHERE id_artis=?");
        pstmt->setInt(1, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data keuangan berhasil dihapus!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void Keuangan::showData() {
    try {
        sql::PreparedStatement* pstmt;
        sql::ResultSet* res;
        pstmt = con->prepareStatement("SELECT * FROM keuangan");
        res = pstmt->executeQuery();

        cout << "===== Data Keuangan =====\n";
        while (res->next()) {
            cout << "ID Artis: " << res->getInt("id_artis") << endl;
            cout << "Jenis Transaksi: " << res->getString("jenis_transaksi") << endl;
            cout << "Jumlah Uang: " << res->getDouble("jumlah_uang") << endl;
            cout << "Tanggal: " << res->getString("tanggal") << endl;
            cout << "Deskripsi: " << res->getString("deskripsi") << endl;
            cout << "---------------------\n";
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}
