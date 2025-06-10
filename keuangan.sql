CREATE TABLE keuangan (
    id_transaksi INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    jenis_transaksi VARCHAR(100) NOT NULL,
    jumlah_uang DECIMAL(15,2) NOT NULL,
    tanggal DATE NOT NULL,
    deskripsi TEXT,
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);
