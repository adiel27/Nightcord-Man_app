#include "Entities/Kontrak/Kontrak.hpp"
#include <iostream>

Kontrak::Kontrak(int idArtis, std::string mulai, std::string akhir, double nilai, std::string ket, sql::Connection* conn)
    : EntitasDatabase(conn), tanggalMulai(mulai), tanggalAkhir(akhir), nilaiKontrak(nilai), ketentuan(ket) {
    setId(idArtis);
    perbaruiTimestamp();
    logAktivitas("Kontrak dibuat untuk ID Artis: " + std::to_string(getId()));
}

void Kontrak::simpan() {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO kontrak (id_artis, tanggal_mulai, tanggal_akhir, nilai_kontrak, ketentuan) VALUES (?, ?, ?, ?, ?)");
        pstmt->setInt(1, getId());
        pstmt->setString(2, tanggalMulai);
        pstmt->setString(3, tanggalAkhir);
        pstmt->setDouble(4, nilaiKontrak);
        pstmt->setString(5, ketentuan);
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Kontrak disimpan");
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void Kontrak::edit() {
    // Mirip dengan implementasi Artis::edit(), baca ulang input dan update nilai lokal serta ke DB
}

void Kontrak::hapus() {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM kontrak WHERE id_artis=?");
        pstmt->setInt(1, getId());
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Kontrak dihapus");
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void Kontrak::tampilkan() {
    // Ambil dan tampilkan data dari DB sesuai getId()
}

std::string Kontrak::toString() const {
    return "Kontrak ID Artis: " + std::to_string(getId()) + " | Nilai: " + std::to_string(nilaiKontrak);
}
