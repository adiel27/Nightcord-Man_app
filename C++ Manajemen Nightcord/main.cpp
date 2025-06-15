#include "Database/Database.hpp"
#include "Entities/Artis/InputArtis.hpp"
#include "Entities/Kontrak/InputKontrak.hpp"
#include "Entities/JadwalEvent/InputJadwalEvent.hpp"
#include "Entities/Keuangan/InputKeuangan.hpp"
#include "Entities/MediaPromosi/InputMediaPromosi.hpp"
#include "Entities/TimManajemen/InputTimManajemen.hpp"
#include "Entities/Statistik/InputStatistik.hpp"

#include <iostream>

int main() {
    // 🔗 Hubungkan ke Database MySQL
    sql::Driver* driver = get_driver_instance();
    sql::Connection* conn = driver->connect("tcp://localhost:3306", "root", "password");
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
                auto* artis = InputArtis::masukkanData(conn);
                artis->tampilkan();
                delete artis;
                break;
            }
            case 2: {
                auto* kontrak = InputKontrak::masukkanData(conn);
                kontrak->tampilkan();
                delete kontrak;
                break;
            }
            case 3: {
                auto* event = InputJadwalEvent::masukkanData(conn);
                event->tampilkan();
                delete event;
                break;
            }
            case 4: {
                auto* keuangan = InputKeuangan::masukkanData(conn);
                keuangan->tampilkan();
                delete keuangan;
                break;
            }
            case 5: {
                auto* media = InputMediaPromosi::masukkanData(conn);
                media->tampilkan();
                delete media;
                break;
            }
            case 6: {
                auto* tim = InputTimManajemen::masukkanData(conn);
                tim->tampilkan();
                delete tim;
                break;
            }
            case 7: {
                auto* statistik = InputStatistik::masukkanData(conn);
                statistik->tampilkan();
                delete statistik;
                break;
            }
            case 8: {
                    std::cout << "\n===== DATA ARTIS =====\n";
                    auto* artisTemp = new Artis(0, "", "", "", false, conn);
                    artisTemp->tampilkan();
                    delete artisTemp;

                    std::cout << "\n===== DATA KONTRAK =====\n";
                    auto* kontrakTemp = new Kontrak(0, "", "", 0, "", conn);
                    kontrakTemp->tampilkan();
                    delete kontrakTemp;

                    std::cout << "\n===== DATA JADWAL EVENT =====\n";
                    auto* eventTemp = new JadwalEvent(0, "", "", "", "", "", conn);
                    eventTemp->tampilkan();
                    delete eventTemp;

                    std::cout << "\n===== DATA KEUANGAN =====\n";
                    auto* keuanganTemp = new Keuangan(0, 0, "", conn);
                    keuanganTemp->tampilkan();
                    delete keuanganTemp;

                    std::cout << "\n===== DATA MEDIA PROMOSI =====\n";
                    auto* mediaTemp = new MediaPromosi(0, "", "", conn);
                    mediaTemp->tampilkan();
                    delete mediaTemp;

                    std::cout << "\n===== DATA TIM MANAJEMEN =====\n";
                    auto* timTemp = new TimManajemen(0, "", "", conn);
                    timTemp->tampilkan();
                    delete timTemp;

                    std::cout << "\n===== DATA STATISTIK & ANALITIK =====\n";
                    auto* statistikTemp = new StatistikAnalitik(0, "", conn);
                    statistikTemp->tampilkan();
                    delete statistikTemp;
                break;


                }
        case 9:
            std::cout << "Keluar dari sistem...\n";
        break;
        
        default:
        std::cout << "Pilihan tidak valid!\n";
        
    }

    }

    delete conn;
    std::cout << "Terima kasih telah menggunakan sistem!\n";
    return 0;
}
