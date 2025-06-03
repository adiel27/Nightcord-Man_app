#ifndef ARTIS_HPP
#define ARTIS_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class Artis {
    private:
        string nama;
        string tanggalLahir;
        string genreMusik;
        bool statusKontrak;
        sql::Connection* con;
    public:
        Artis(string nm, string tgl, string genre, bool kontrak, sql::Connection* conn);
        void simpanKeDatabase();
        void tampilkaninfo();    
};