CREATE TABLE statistik_analitik (
    id_statistik INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    jumlah_streaming INT NOT NULL,
    penjualan_album INT NOT NULL,
    engagement_sosial INT NOT NULL,
    periode VARCHAR(50) NOT NULL,
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);
