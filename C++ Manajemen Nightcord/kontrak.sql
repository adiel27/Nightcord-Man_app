CREATE TABLE kontrak (
    id_kontrak INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    tanggal_mulai DATE NOT NULL,
    tanggal_akhir DATE NOT NULL,
    nilai_kontrak DOUBLE NOT NULL,
    ketentuan TEXT,
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);