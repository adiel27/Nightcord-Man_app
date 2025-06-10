#ifndef JADWALEVENT_HPP
#define JADWALEVENT_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class JadwalEvent {
private:
    int idArtis;
    string namaAcara;
    string tanggal;
    string waktu;
    string lokasi;
    string jenisAcara;
    sql::Connection* con;

public:
    JadwalEvent(int idA, string nama, string tgl, string wkt, string lok, string jenis, sql::Connection* conn);
    void simpanEvent();
    void tampilkanEvent();
};

#endif // JADWALEVENT_HPP
