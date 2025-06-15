CREATE TABLE media_promosi (
    id_kampanye INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    nama_kampanye VARCHAR(255) NOT NULL,
    platform VARCHAR(100),
    tanggal_mulai DATE NOT NULL,
    tanggal_akhir DATE NOT NULL,
    strategi TEXT,
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);
