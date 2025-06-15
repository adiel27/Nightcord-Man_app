#include "Database/Database.hpp"
#include "Entities/Artis/InputArtis.hpp"
#include "Entities/Kontrak/InputKontrak.hpp"
#include "Entities/JadwalEvent/InputJadwalEvent.hpp"
#include "Entities/Keuangan/InputKeuangan.hpp"
#include "Entities/MediaPromosi/InputMediaPromosi.hpp"
#include "Entities/TimManajemen/InputTimManajemen.hpp"
#include "Entities/Statistik/InputStatistik.hpp"

#include <iostream>
#include <memory> // Smart pointers

int main() {
    // 🔗 Hubungkan ke Database dengan hardcoded credentials
    sql::Driver* driver = get_driver_instance();
    sql::Connection* conn = driver->connect("tcp://localhost:3306", "root", "");
    conn->setSchema("idol_management");

    int pilihan;
    while (true) {
        std::cout << "\n===== SISTEM MANAJEMEN ARTIS IDOL =====\n";
        std::cout << "1. Tambah Artis\n";
        std::cout << "2. Tambah Kontrak\n";
        std::cout << "3. Tambah Jadwal Event\n";
        std::cout << "4. Tambah Keuangan\n";
        std::cout << "5. Tambah Media Promosi\n";
        std::cout << "6. Tambah Tim Manajemen\n";
        std::cout << "7. Tambah Statistik & Analitik\n";
        std::cout << "8. Tampilkan Semua Data\n";
        std::cout << "9. Keluar\n";
        std::cout << "Pilih opsi: ";
        std::cin >> pilihan;
        std::cin.ignore();

        if (pilihan == 9) break;

        switch (pilihan) {
            case 1: {
                auto artis = std::make_unique<InputArtis>(conn);
                artis->masukkanData()->tampilkan();
                break;
            }
            case 2: {
                auto kontrak = std::make_unique<InputKontrak>(conn);
                kontrak->masukkanData()->tampilkan();
                break;
            }
            case 3: {
                auto event = std::make_unique<InputJadwalEvent>(conn);
                event->masukkanData()->tampilkan();
                break;
            }
            case 4: {
                auto keuangan = std::make_unique<InputKeuangan>(conn);
                keuangan->masukkanData()->tampilkan();
                break;
            }
            case 5: {
                auto media = std::make_unique<InputMediaPromosi>(conn);
                media->masukkanData()->tampilkan();
                break;
            }
            case 6: {
                auto tim = std::make_unique<InputTimManajemen>(conn);
                tim->masukkanData()->tampilkan();
                break;
            }
            case 7: {
                auto statistik = std::make_unique<InputStatistik>(conn);
                statistik->masukkanData()->tampilkan();
                break;
            }
            case 8: {
                std::cout << "\n===== TAMPILKAN SEMUA DATA =====\n";
                std::make_unique<Artis>(0, "", "", "", false, conn)->tampilkan();
                std::make_unique<Kontrak>(0, "", "", 0, "", conn)->tampilkan();
                std::make_unique<JadwalEvent>(0, "", "", "", "", "", conn)->tampilkan();
                std::make_unique<Keuangan>(0, 0, "", conn)->tampilkan();
                std::make_unique<MediaPromosi>(0, "", "", conn)->tampilkan();
                std::make_unique<TimManajemen>(0, "", "", conn)->tampilkan();
                std::make_unique<StatistikAnalitik>(0, "", conn)->tampilkan();
                break;
            }
            default:
                std::cout << "Pilihan tidak valid! Mohon masukkan angka 1-9.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
        }
    }

    delete conn;
    std::cout << "Terima kasih telah menggunakan sistem!\n";
    return 0;
}
