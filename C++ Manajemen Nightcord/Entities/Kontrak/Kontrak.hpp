#ifndef KONTRAK_HPP
#define KONTRAK_HPP

#include "Core/EntitasDatabase.hpp"
#include "Core/Identifiable.hpp"
#include "Core/Loggable.hpp"
#include "Core/Timestampable.hpp"
#include "Core/Serializable.hpp"

#include <string>
#include <mysql_connection.h>

class Kontrak : public EntitasDatabase, public Identifiable, public Loggable, public Timestampable, public Serializable {
private:
    std::string tanggalMulai, tanggalAkhir, ketentuan;
    double nilaiKontrak;

public:
    Kontrak(int idArtis, std::string mulai, std::string akhir, double nilai, std::string ket, sql::Connection* conn);

    void simpan() override;
    void edit() override;
    void hapus() override;
    void tampilkan() override;
    std::string toString() const override;
};

#endif
