#include "Database.hpp"
#include <iostream>
using namespace std;

sql::Connection* Database::koneksi() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "");
        con->setSchema("idol_management" );
        return con;
    } catch (sql::SQLException& e) {
        cout << "Kesalahan koneksi MySQL: " << e.what() << endl;
        return nullptr;
    }
}