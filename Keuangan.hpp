#ifndef KEUANGAN_HPP
#define KEUANGAN_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class Keuangan {
private:
    int idArtis;
    string jenisTransaksi;
    double jumlahUang;
    string tanggal;
    string deskripsi;
    sql::Connection* con;

public:
    Keuangan(int idA, string jenis, double jumlah, string tgl, string desk, sql::Connection* conn);
    void simpanTransaksi();
    void tampilkanTransaksi();
};

#endif // KEUANGAN_HPP
