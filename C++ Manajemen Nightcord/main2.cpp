#include "Database.hpp"
#include "ManajemenKontrak.hpp"

int main() {
    sql::Connection* con = Database::koneksi();
    if (con != nullptr) {
        ManajemenKontrak kontrak1(1, "2025-06-01", "2027-06-01", 5000000, "Eksklusif, 3 album wajib", con);
        kontrak1.simpanKontrak();
        kontrak1.tampilkanKontrak();
        delete con;
    }
    return 0;
}