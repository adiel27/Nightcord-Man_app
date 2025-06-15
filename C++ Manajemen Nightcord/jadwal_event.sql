CREATE TABLE jadwal_event (
    id_event INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    nama_acara VARCHAR(255) NOT NULL,
    tanggal DATE NOT NULL,
    waktu TIME NOT NULL,
    lokasi VARCHAR(255),
    jenis_acara VARCHAR(100),
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);
