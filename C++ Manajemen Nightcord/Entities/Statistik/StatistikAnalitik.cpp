#include "Entities/Statistik/StatistikAnalitik.hpp"

StatistikAnalitik::StatistikAnalitik(int idA, int stream, int album, int sosial, string per, sql::Connection* conn) {
    idArtis = idA;
    jumlahStreaming = stream;
    penjualanAlbum = album;
    engagementSosial = sosial;
    periode = per;
    con = conn;
}

void StatistikAnalitik::simpanData() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO statistik_analitik (id_artis, jumlah_streaming, penjualan_album, engagement_sosial, periode) VALUES (?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setInt(2, jumlahStreaming);
        pstmt->setInt(3, penjualanAlbum);
        pstmt->setInt(4, engagementSosial);
        pstmt->setString(5, periode);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data statistik berhasil disimpan!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void StatistikAnalitik::tampilkanStatistik() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Jumlah Streaming: " << jumlahStreaming << endl;
    cout << "Penjualan Album: " << penjualanAlbum << endl;
    cout << "Engagement Sosial: " << engagementSosial << endl;
    cout << "Periode Analisis: " << periode << endl;
}

void StatistikAnalitik::editData() {
    int newJumlahStreaming, newPenjualanAlbum, newEngagementSosial;
    string newPeriode;

    cout << "Masukkan Jumlah Streaming Baru: ";
    cin >> newJumlahStreaming;

    cout << "Masukkan Penjualan Album Baru: ";
    cin >> newPenjualanAlbum;

    cout << "Masukkan Engagement Sosial Baru (jumlah likes, shares, dll.): ";
    cin >> newEngagementSosial;

    cout << "Masukkan Periode Baru (Mingguan, Bulanan, Tahunan): ";
    cin.ignore();
    getline(cin, newPeriode);

    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("UPDATE statistik_analitik SET jumlah_streaming=?, penjualan_album=?, engagement_sosial=?, periode=? WHERE id_artis=?");
        pstmt->setInt(1, newJumlahStreaming);
        pstmt->setInt(2, newPenjualanAlbum);
        pstmt->setInt(3, newEngagementSosial);
        pstmt->setString(4, newPeriode);
        pstmt->setInt(5, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data statistik berhasil diperbarui!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void StatistikAnalitik::deleteData() {
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("DELETE FROM statistik_analitik WHERE id_artis=?");
        pstmt->setInt(1, idArtis);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Data statistik berhasil dihapus!" << endl;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void StatistikAnalitik::showData() {
    try {
        sql::PreparedStatement* pstmt;
        sql::ResultSet* res;
        pstmt = con->prepareStatement("SELECT * FROM statistik_analitik");
        res = pstmt->executeQuery();

        cout << "===== Data Statistik & Analitik =====\n";
        while (res->next()) {
            cout << "ID Artis: " << res->getInt("id_artis") << endl;
            cout << "Jumlah Streaming: " << res->getInt("jumlah_streaming") << endl;
            cout << "Penjualan Album: " << res->getInt("penjualan_album") << endl;
            cout << "Engagement Sosial: " << res->getInt("engagement_sosial") << endl;
            cout << "Periode: " << res->getString("periode") << endl;
            cout << "---------------------\n";
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}
