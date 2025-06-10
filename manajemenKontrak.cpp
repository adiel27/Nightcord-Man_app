#include "manajemenKontrak.hpp"

manajemenKontrak::manajemenKontrak(int idA, string mulai, string akhir, double nilai, string ktnt, sql::(Connection* conn)) {
    idArtis = idA;
    tanggalMulai = mulai;
    tanggalAkhir = akhir;
    nilaiKontrak = nilai;
    ketentuan = ktnt;
    con = conn;
}

void manajemenKontrak::simpanKontrak(){
    try {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO kontrak(id_artis, tanggal_mulai, tanggal_akhir, nilai_kontrak, ketentuan) VALUES
        (?, ?, ?, ?, ?)");
        pstmt->setInt(1, idArtis);
        pstmt->setString(2, tanggalMulai);
        pstmt->setString(3, tanggalAkhir);
        pstmt->setDouble(4, nilaiKontrak);
        pstmt->setString(5, ketentuan);
        pstmt->executeUpdate();
        delete pstmt;
        cout << "Kontrak berhasil disimpan!" << endl;
    }   catch (sql::SQLException& e) {
        cout << "Kesalahan MySQL: " << e.what() << endl;
    }
}

void manajemenKontrak::tampilkanKontrak() {
    cout << "ID Artis: " << idArtis << endl;
    cout << "Tanggal Mulai: " << tanggalMulai << endl;
    cout << "Tanggal Akhir: " << tanggalAkhir << endl;
    cout << "Nilai Kontrak: Rp" << nilaiKontrak << endl;
    cout << "Ketentuan: " << ketentuan << endl;
}