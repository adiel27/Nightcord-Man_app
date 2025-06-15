#ifndef ARTIS_HPP
#define ARTIS_HPP

#include "Core/EntitasDatabase.hpp"
#include "Core/Identifiable.hpp"
#include "Core/Loggable.hpp"
#include "Core/Timestampable.hpp"
#include "Core/Serializable.hpp"

#include <string>

class Artis : public EntitasDatabase,
              public Identifiable,
              public Loggable,
              public Timestampable,
              public Serializable {
private:
    std::string nama;
    std::string tanggalLahir;
    std::string genreMusik;
    bool statusKontrak;

public:
    Artis(std::string nama, std::string tglLahir, std::string genre, bool status, sql::Connection* koneksi);
    
    void simpan() override;
    void edit() override;
    void hapus() override;
    void tampilkan() override;
    std::string toString() const override;
};

#endif
