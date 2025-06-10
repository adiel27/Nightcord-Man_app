#ifndef MANAJEMEN_KONTRAK_HPP
#define MANAJEMEN_KONTRAK_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class manajemenKontrak{
    private:
        int idKontrak;
        int idArtis;
        string tanggalMulai;
        string tanggalAkhir;
        double nilaiKontrak;
        string ketentuan;
        sql::Connection* con;

    public:
        manajemenKontrak(int idA, string mulai, string akhir, double nilai, string ketentuan, sql::Connection* conn);
        void simpanKontrak();
        void tampilKontrak();
};
#endif
