#ifndef JADWALEVENT_HPP
#define JADWALEVENT_HPP

#include "Core/EntitasDatabase.hpp"
#include "Core/Identifiable.hpp"
#include "Core/Loggable.hpp"
#include "Core/Timestampable.hpp"
#include "Core/Serializable.hpp"

#include <string>
#include <mysql_connection.h>

class JadwalEvent : public EntitasDatabase,
                    public Identifiable,
                    public Loggable,
                    public Timestampable,
                    public Serializable {
private:
    std::string namaAcara;
    std::string tanggal;
    std::string waktu;
    std::string lokasi;
    std::string jenisAcara;

public:
    JadwalEvent(int idArtis, const std::string& nama, const std::string& tgl,
                const std::string& wkt, const std::string& lok, const std::string& jenis,
                sql::Connection* conn);

    void simpan() override;
    void edit() override;
    void hapus() override;
    void tampilkan() override;
    std::string toString() const override;
};

#endif
