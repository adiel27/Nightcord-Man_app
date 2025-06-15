CREATE DATABASE idol_management;
USE idol_management;

CREATE TABLE artis (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(255) NOT NULL,
    tanggal_lahir DATE NOT NULL,
    genre_musik VARCHAR(100),
    status_kontrak BOOLEAN
);
