#ifndef ENTITASDATABASE_HPP
#define ENTITASDATABASE_HPP

#include <mysql_connection.h>

class EntitasDatabase {
protected:
    sql::Connection* con;
public:
    EntitasDatabase(sql::Connection* koneksi) : con(koneksi) {}
    virtual void simpan() = 0;
    virtual void edit() = 0;
    virtual void hapus() = 0;
    virtual void tampilkan() = 0;
    virtual ~EntitasDatabase() {}
};

#endif
