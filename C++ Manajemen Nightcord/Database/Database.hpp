#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>

using namespace sql;


using namespace sql;

class Database {
    public:
        static sql::Connection* koneksi();
};

#endif
