#include "Database.hpp"
#include "Artis.hpp"

int main() {
    // Membuat koneksi ke database
    sql::Connection* con = Database::koneksi();
    if (con != nullptr) {
        // Membuat objek Artis
        Artis artisTest("Adiel Idol", "03 Juni 1995", "Pop", true, con);

        // Menyimpan data ke database
        artisTest.simpanKeDatabase();

        // Menampilkan data artis
        artisTest.tampilkanInfo();

        // Membersihkan koneksi database
        delete con;
    } else {
        cout << "Koneksi ke database gagal!" << endl;
    }

    return 0;
}
