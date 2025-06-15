#ifndef TIMMANAJEMEN_HPP
#define TIMMANAJEMEN_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class TimManajemen {
private:
    int idArtis;
    string nama;
    string peran;
    string tanggalMulai;
    string kontak;
    sql::Connection* con;

public:
    TimManajemen(int idA, string nm, string prn, string mulai, string kontakInfo, sql::Connection* conn);
    void simpanAnggotaTim();
    void tampilkanAnggotaTim();
};

void editData();
void deleteData();
void showData();

#endif // TIMMANAJEMEN_HPP
