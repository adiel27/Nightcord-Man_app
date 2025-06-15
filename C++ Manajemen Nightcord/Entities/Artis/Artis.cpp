#include "Entities/Artis/Artis.hpp"
#include <iostream>

Artis::Artis(std::string n, std::string tgl, std::string g, bool s, sql::Connection* koneksi)
    : EntitasDatabase(koneksi), nama(n), tanggalLahir(tgl), genreMusik(g), statusKontrak(s) {
    perbaruiTimestamp();  // dari Timestampable
    logAktivitas("Artis dibuat: " + n);
}

void Artis::simpan() {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO artis (nama, tanggal_lahir, genre_musik, status_kontrak) VALUES (?, ?, ?, ?)");
        pstmt->setString(1, nama);
        pstmt->setString(2, tanggalLahir);
        pstmt->setString(3, genreMusik);
        pstmt->setBoolean(4, statusKontrak);
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Artis disimpan: " + nama);
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void Artis::edit() {
    std::string newNama, newTgl, newGenre;
    bool newStatus;
    std::cout << "Masukkan nama baru: "; std::cin.ignore(); getline(std::cin, newNama);
    std::cout << "Tanggal lahir baru (YYYY-MM-DD): "; std::cin >> newTgl;
    std::cout << "Genre baru: "; std::cin.ignore(); getline(std::cin, newGenre);
    std::cout << "Status kontrak (1: Aktif, 0: Tidak): "; std::cin >> newStatus;

    try {
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "UPDATE artis SET nama=?, tanggal_lahir=?, genre_musik=?, status_kontrak=? WHERE id=?");
        pstmt->setString(1, newNama);
        pstmt->setString(2, newTgl);
        pstmt->setString(3, newGenre);
        pstmt->setBoolean(4, newStatus);
        pstmt->setInt(5, getId());
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Artis diedit: " + newNama);
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void Artis::hapus() {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM artis WHERE id=?");
        pstmt->setInt(1, getId());
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Artis dihapus, ID: " + std::to_string(getId()));
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void Artis::tampilkan() {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM artis WHERE id=?");
        pstmt->setInt(1, getId());
        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next()) {
            std::cout << "ID: " << res->getInt("id") << std::endl;
            std::cout << "Nama: " << res->getString("nama") << std::endl;
            std::cout << "Tanggal Lahir: " << res->getString("tanggal_lahir") << std::endl;
            std::cout << "Genre Musik: " << res->getString("genre_musik") << std::endl;
            std::cout << "Status Kontrak: " << (res->getBoolean("status_kontrak") ? "Aktif" : "Tidak Aktif") << std::endl;
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

std::string Artis::toString() const {
    return "Artis {nama: " + nama + ", genre: " + genreMusik + ", status: " + (statusKontrak ? "Aktif" : "Nonaktif") + "}";
}
