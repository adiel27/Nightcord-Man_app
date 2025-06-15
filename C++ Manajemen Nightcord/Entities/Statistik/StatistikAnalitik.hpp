#ifndef STATISTIKANALITIK_HPP
#define STATISTIKANALITIK_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class StatistikAnalitik {
private:
    int idArtis;
    int jumlahStreaming;
    int penjualanAlbum;
    int engagementSosial;
    string periode;
    sql::Connection* con;

public:
    StatistikAnalitik(int idA, int stream, int album, int sosial, string per, sql::Connection* conn);
    void simpanData();
    void tampilkanStatistik();
};

void editData();
void deleteData();
void showData();

#endif // STATISTIKANALITIK_HPP
