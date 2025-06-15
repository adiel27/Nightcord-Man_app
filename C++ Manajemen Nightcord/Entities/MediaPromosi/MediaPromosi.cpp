#include "Entities/MediaPromosi/MediaPromosi.hpp"

MediaPromosi::MediaPromosi(int idA, string nama, string plat, string mulai, string akhir, string strat, sql::Connection* conn) {
    idArtis = idA;
    namaKampanye = nama;
    platform = plat;
    tanggalMulai = mulai;
    tanggalAkhir = akhir;
    strategi = strat;
    con = conn;
}

void MediaPromosi::simpanKampanye() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO media_promosi (id_artis, nama_kampanye, platform, tanggal_mulai, tanggal_akhir, strategi) VALUES (?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setString(2, namaKampanye);
        pstmt->setString(3, platform);
        pstmt->setString(4, tanggalMulai);
        pstmt->setString(5, tanggalAkhir);
        pstmt->setString(6, strategi);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Kampanye promosi berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void MediaPromosi::tampilkanKampanye() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Nama Kampanye: " << namaKampanye << endl;
    cout << "Platform: " << platform << endl;
    cout << "Tanggal Mulai: " << tanggalMulai << endl;
    cout << "Tanggal Akhir: " << tanggalAkhir << endl;
    cout << "Strategi Promosi: " << strategi << endl;
}

void MediaPromosi::editData() {
    string newNamaKampanye, newPlatform, newTanggalMulai, newTanggalAkhir, newStrategi;

    cout << "Masukkan Nama Kampanye Baru: ";
    cin.ignore();
    getline(cin, newNamaKampanye);

    cout << "Masukkan Platform Baru (YouTube, Instagram, TV, dll.): ";
    getline(cin, newPlatform);

    cout << "Masukkan Tanggal Mulai Baru (YYYY-MM-DD): ";
    cin >> newTanggalMulai;

    cout << "Masukkan Tanggal Akhir Baru (YYYY-MM-DD): ";
    cin >> newTanggalAkhir;

    cout << "Masukkan Strategi Promosi Baru: ";
    cin.ignore();
    getline(cin, newStrategi);

    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("UPDATE media_promosi SET nama_kampanye=?, platform=?, tanggal_mulai=?, tanggal_akhir=?, strategi=? WHERE id_artis=?");
        pstmt->setString(1, newNamaKampanye);
        pstmt->setString(2, newPlatform);
        pstmt->setString(3, newTanggalMulai);
        pstmt->setString(4, newTanggalAkhir);
        pstmt->setString(5, newStrategi);
        pstmt->setInt(6, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data kampanye promosi berhasil diperbarui!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void MediaPromosi::deleteData() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("DELETE FROM media_promosi WHERE id_artis=?");
        pstmt->setInt(1, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data kampanye promosi berhasil dihapus!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void MediaPromosi::showData() {
    try {
        sql::PreparedStatement* pstmt;
        sql::ResultSet* res;
        pstmt = con->prepareStatement("SELECT * FROM media_promosi");
        res = pstmt->executeQuery();

        cout << "===== Data Media & Promosi =====\n";
        while (res->next()) {
            cout << "ID Artis: " << res->getInt("id_artis") << endl;
            cout << "Nama Kampanye: " << res->getString("nama_kampanye") << endl;
            cout << "Platform: " << res->getString("platform") << endl;
            cout << "Tanggal Mulai: " << res->getString("tanggal_mulai") << endl;
            cout << "Tanggal Akhir: " << res->getString("tanggal_akhir") << endl;
            cout << "Strategi: " << res->getString("strategi") << endl;
            cout << "---------------------\n";
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}
