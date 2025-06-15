#include "Entities/TimManajemen/TimManajemen.hpp"

TimManajemen::TimManajemen(int idA, string nm, string prn, string mulai, string kontakInfo, sql::Connection* conn) {
    idArtis = idA;
    nama = nm;
    peran = prn;
    tanggalMulai = mulai;
    kontak = kontakInfo;
    con = conn;
}

void TimManajemen::simpanAnggotaTim() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO tim_manajemen (id_artis, nama, peran, tanggal_mulai, kontak) VALUES (?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setString(2, nama);
        pstmt->setString(3, peran);
        pstmt->setString(4, tanggalMulai);
        pstmt->setString(5, kontak);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Anggota tim berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void TimManajemen::tampilkanAnggotaTim() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Nama: " << nama << endl;
    cout << "Peran: " << peran << endl;
    cout << "Tanggal Mulai: " << tanggalMulai << endl;
    cout << "Kontak: " << kontak << endl;
}

void TimManajemen::editData() {
    string newNama, newPeran, newTanggalMulai, newKontak;

    cout << "Masukkan Nama Baru: ";
    cin.ignore();
    getline(cin, newNama);

    cout << "Masukkan Peran Baru: ";
    getline(cin, newPeran);

    cout << "Masukkan Tanggal Mulai Baru (YYYY-MM-DD): ";
    cin >> newTanggalMulai;

    cout << "Masukkan Kontak Baru: ";
    cin.ignore();
    getline(cin, newKontak);

    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("UPDATE tim_manajemen SET nama=?, peran=?, tanggal_mulai=?, kontak=? WHERE id_artis=?");
        pstmt->setString(1, newNama);
        pstmt->setString(2, newPeran);
        pstmt->setString(3, newTanggalMulai);
        pstmt->setString(4, newKontak);
        pstmt->setInt(5, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data tim manajemen berhasil diperbarui!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void TimManajemen::deleteData() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("DELETE FROM tim_manajemen WHERE id_artis=?");
        pstmt->setInt(1, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data tim manajemen berhasil dihapus!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void TimManajemen::showData() {
    try {
        sql::PreparedStatement* pstmt;
        sql::ResultSet* res;
        pstmt = con->prepareStatement("SELECT * FROM tim_manajemen");
        res = pstmt->executeQuery();

        cout << "===== Data Tim Manajemen =====\n";
        while (res->next()) {
            cout << "ID Artis: " << res->getInt("id_artis") << endl;
            cout << "Nama: " << res->getString("nama") << endl;
            cout << "Peran: " << res->getString("peran") << endl;
            cout << "Tanggal Mulai: " << res->getString("tanggal_mulai") << endl;
            cout << "Kontak: " << res->getString("kontak") << endl;
            cout << "---------------------\n";
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}
