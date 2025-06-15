#ifndef MEDIAPROMOSI_HPP
#define MEDIAPROMOSI_HPP

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

class MediaPromosi {
private:
    int idArtis;
    string namaKampanye;
    string platform;
    string tanggalMulai;
    string tanggalAkhir;
    string strategi;
    sql::Connection* con;

public:
    MediaPromosi(int idA, string nama, string plat, string mulai, string akhir, string strat, sql::Connection* conn);
    void simpanKampanye();
    void tampilkanKampanye();
};

void editData();
void deleteData();
void showData();

#endif // MEDIAPROMOSI_HPP
