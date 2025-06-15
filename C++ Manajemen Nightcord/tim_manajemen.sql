CREATE TABLE tim_manajemen (
    id_tim INT AUTO_INCREMENT PRIMARY KEY,
    id_artis INT,
    nama VARCHAR(255) NOT NULL,
    peran VARCHAR(100),
    tanggal_mulai DATE NOT NULL,
    kontak VARCHAR(255),
    FOREIGN KEY (id_artis) REFERENCES artis(id)
);
