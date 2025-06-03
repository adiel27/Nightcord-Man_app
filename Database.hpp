#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mysql_driver.h>
#include <mysql_connection.h>

using namespace sql;

class Database {
    public:
        static sql::Connection* koneksi();
};

#endif