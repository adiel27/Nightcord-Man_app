#include "Entities/JadwalEvent/JadwalEvent.hpp"
#include <iostream>

JadwalEvent::JadwalEvent(int idArtis, const std::string& nama, const std::string& tgl,
                         const std::string& wkt, const std::string& lok, const std::string& jenis,
                         sql::Connection* conn)
    : EntitasDatabase(conn), namaAcara(nama), tanggal(tgl),
      waktu(wkt), lokasi(lok), jenisAcara(jenis) {
    setId(idArtis);
    perbaruiTimestamp();
    logAktivitas("Jadwal event dibuat untuk ID artis: " + std::to_string(idArtis));
}

void JadwalEvent::simpan() {
    try {
        auto* pstmt = con->prepareStatement("INSERT INTO jadwal_event (id_artis, nama_acara, tanggal, waktu, lokasi, jenis_acara) VALUES (?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, getId());
        pstmt->setString(2, namaAcara);
        pstmt->setString(3, tanggal);
        pstmt->setString(4, waktu);
        pstmt->setString(5, lokasi);
        pstmt->setString(6, jenisAcara);
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Jadwal event disimpan");
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void JadwalEvent::edit() {
    std::string newNama, newTanggal, newWaktu, newLokasi, newJenis;
    std::cin.ignore();
    std::cout << "Nama baru: "; std::getline(std::cin, newNama);
    std::cout << "Tanggal (YYYY-MM-DD): "; std::cin >> newTanggal;
    std::cout << "Waktu (HH:MM): "; std::cin >> newWaktu;
    std::cin.ignore();
    std::cout << "Lokasi: "; std::getline(std::cin, newLokasi);
    std::cout << "Jenis acara: "; std::getline(std::cin, newJenis);

    try {
        auto* pstmt = con->prepareStatement("UPDATE jadwal_event SET nama_acara=?, tanggal=?, waktu=?, lokasi=?, jenis_acara=? WHERE id_artis=?");
        pstmt->setString(1, newNama);
        pstmt->setString(2, newTanggal);
        pstmt->setString(3, newWaktu);
        pstmt->setString(4, newLokasi);
        pstmt->setString(5, newJenis);
        pstmt->setInt(6, getId());
        pstmt->executeUpdate();
        delete pstmt;

        namaAcara = newNama;
        tanggal = newTanggal;
        waktu = newWaktu;
        lokasi = newLokasi;
        jenisAcara = newJenis;

        perbaruiTimestamp();
        logAktivitas("Jadwal event diedit");
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void JadwalEvent::hapus() {
    try {
        auto* pstmt = con->prepareStatement("DELETE FROM jadwal_event WHERE id_artis=?");
        pstmt->setInt(1, getId());
        pstmt->executeUpdate();
        delete pstmt;
        logAktivitas("Jadwal event dihapus");
    } catch (sql::SQLException& e) {
        std::cerr << "[SQL ERROR] " << e.what() << std::endl;
    }
}

void JadwalEvent::tampilkan() {
    std::cout << toString() << std::endl;
}

std::string JadwalEvent::toString() const {
    return "Event [" + namaAcara + "] di " + lokasi + " pada " + tanggal + " " + waktu + " - Jenis: " + jenisAcara;
}
