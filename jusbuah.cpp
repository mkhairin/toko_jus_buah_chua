#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string pilihan_kembali, pilihanSortingUser;
string jusBuah[10] = {"Apel", "Jeruk", "Anggur", "Melon", "Alpukat", "Semangka", "Pisang", "Mangga", "Durian", "Stroberi"};
int hargaJusBuah[10] = {10000, 15000, 12000, 20000, 5000, 30000, 15000, 10000, 35000, 40000};
int pilihanBuah, jumlahPesanan, pembayaran, totalKembalian;

// fungsi katalog buah
void katalogBuah() {
    system("cls");
    cout << "=========================================" << endl;
    cout << "              Katalog Buah       " << endl;
    cout << "=========================================" << endl << endl;
    for( int i = 0; i < 10; i++) {
        cout << "\t" << i+1 << ".Jus " << jusBuah[i] << endl;
    }
    cout << endl << "=========================================" << endl;
}

// fungsi katalog harga
void katalogHarga() {
    system("cls");
    cout << "=========================================" << endl;
    cout << "            Katalog Harga Buah       " << endl;
    cout << "=========================================" << endl << endl;
    for(int i = 0; i < 10; i++) {
        cout << "\t" << i+1 << ".Jus " << jusBuah[i] << " : Rp.";
        cout << hargaJusBuah[i] << endl;
    }
    cout << endl << "=========================================" << endl;
}

// fungsi pembelian buah
void pembelianBuah() {
    system("cls");
    katalogHarga();
    cout << endl;

    //program untuk menampilkan pilihan buah
    cout << "\tPilih Buah : "; cin >> pilihanBuah;
    if(pilihanBuah == 1) {
        cout << "\t" << jusBuah[0] << endl;
    } else if (pilihanBuah != 1)
    {
        cout << "\t" << jusBuah[pilihanBuah-1] << endl;
    }
    
    // program menghitung jumlah pesanan/harga
    cout << "\tJumlah Pesanan : "; cin >> jumlahPesanan;
    if(pilihanBuah == 1) {
        cout << "\tTotal Harga : Rp." << jumlahPesanan * hargaJusBuah[0];
    } else if (pilihanBuah != 1)
    {
        cout << "\tTotal Harga : Rp." << jumlahPesanan * hargaJusBuah[pilihanBuah-1];
    }

    cout << endl;
    cout << endl << "=========================================" << endl << endl;
    cout << "\tPembayaran : "; cin >> pembayaran;
    if(pembayaran == jumlahPesanan * hargaJusBuah[pilihanBuah-1]) {
        cout << "\tTerimakasih Sudah Membeli:)" << endl;
    } else if(pembayaran != jumlahPesanan * hargaJusBuah[pilihanBuah-1]) {
        totalKembalian = pembayaran - jumlahPesanan * hargaJusBuah[pilihanBuah-1];
        cout << "\tKembalian : " << totalKembalian;
    }
}

// fungsi struk belanja
void strukBelanja() {
        ofstream fileStruk;
        string infoBuah;
        int infoHarga, infoKembalian ;

        // info jus buah
        if(pilihanBuah == 1) {
            infoBuah = jusBuah[0];
        } else if (pilihanBuah != 1)
        {
           infoBuah = jusBuah[pilihanBuah-1];
        }

        // info harga buah
        if(pilihanBuah == 1) {
        infoHarga = jumlahPesanan * hargaJusBuah[0];
        } else if (pilihanBuah != 1)
        {
            infoHarga = jumlahPesanan * hargaJusBuah[pilihanBuah-1];
        }

        // info total pembayaran
        if(pembayaran == jumlahPesanan * hargaJusBuah[pilihanBuah-1]) {
            
        } else if(pembayaran != jumlahPesanan * hargaJusBuah[pilihanBuah-1]) {
            infoKembalian = pembayaran - jumlahPesanan * hargaJusBuah[pilihanBuah-1];
        }

        fileStruk.open("struk-pembelian.txt");
        fileStruk << "=========================================" << endl;
        fileStruk << "           TOKO JUS BUAH CHUA            " << endl;
        fileStruk << "   JL. KENANGAN MANIS No.25 JAKARTA      " << endl;
        fileStruk << "=========================================" << endl << endl;
        fileStruk << "\tJus Buah : " << infoBuah << endl;
        fileStruk << "\tJumlah Pesanan : " << jumlahPesanan << endl;
        fileStruk << "\tTotal Harga : " << infoHarga << endl;
        fileStruk << "\tTotal Pembayaran : " << pembayaran << endl;
        fileStruk << "\tTotal Kembalian : " << totalKembalian << endl << endl;
        fileStruk << "=========================================" << endl << endl;
        fileStruk << "KAPAN-KAPAN MAMPIR LAGI GUYS JANGAN KE\n JANJI JIWA TERUS:) " << endl << endl;
        fileStruk << "=========================================" << endl;
        system("START /MIN NOTEPAD /P struk-pembelian.txt");
        fileStruk.close();
}

// fungsi mencari data
void searchingData() {
    int length = sizeof(jusBuah)/sizeof(*jusBuah);
    string dataPencarian; 
    int hasilPencarian;
    cout << "\tMasukkan Nama Buah : "; cin >> dataPencarian;
    int i = 0;
        if(dataPencarian == jusBuah[i]) {
            hasilPencarian++;
        }
        if(hasilPencarian < 0) {
            system("cls");
            cout << "\tData Tidak Ditemukan" << endl;
        } else {
            cout << "\tData " << dataPencarian << " Ditemukan di : ";
            for(int a = 0; a < length; a++) {
                if(dataPencarian == jusBuah[a]) {
                    cout << "Index ke-" << a << endl;
                    cout << "\tHarga : Rp. " << hargaJusBuah[a] << endl;
                }
            }

        }
}

// fungsi sorting data
void sortingData() {
    int lengthHarga = sizeof(hargaJusBuah)/sizeof(*hargaJusBuah);
    int temporaryFile;

    for(int i = 1; i < lengthHarga; i++) {
        for(int a = 0; a < lengthHarga-i; a++) {
            if(hargaJusBuah[a] > hargaJusBuah[a+1]){
                temporaryFile = hargaJusBuah[a];
                hargaJusBuah[a] = hargaJusBuah[a+1];
                hargaJusBuah[a+1] = temporaryFile;
            }
        }
    }

    cout << "\tHasil Sorting Harga Jus : " << endl << endl;
    for(int x = 0; x < lengthHarga; x++){
        cout << "\tRp. " << hargaJusBuah[x] << endl;
    }

    cout << endl;
}

// fungsi utama
int main() {
    int pilihan_user;

    menu_utama:
    cout << "=========================================" << endl;
    cout << "           TOKO JUS BUAH CHUA            " << endl;
    cout << "   JL. KENANGAN MANIS No.25 JAKARTA      " << endl;
    cout << "=========================================" << endl << endl;
    cout << "           Menu Pilihan" << endl;
    cout << "           1.Katalog Buah" << endl;
    cout << "           2.Katalog Harga" << endl;
    cout << "           3.Pencarian Buah" << endl;
    cout << "           4.Pembelian Buah" << endl;
    cout << "           5.Keluar" << endl << endl;
    cout << "=========================================" << endl << endl;
    
    cout << "\tPilih Menu [1-5] : "; cin >> pilihan_user;

    switch (pilihan_user)
    {
    case 1:
        system("cls");
        katalogBuah();
        cout << endl;
        cout << "\tKembali (y/n) : ";
        cin >> pilihan_kembali;
        if (pilihan_kembali == "y") {
            system("cls");
            goto menu_utama;
        } else {
            do
            {
                system("cls");
                katalogBuah();
                cout << endl;
                cout << "\tKembali (y/n) : ";
                cin >> pilihan_kembali;
                if(pilihan_kembali == "y") {
                    system("cls");
                    goto menu_utama;
                }
            } while (pilihan_kembali != "y");
        }
        break;
    case 2:
        system("cls");
        katalogHarga();
        cout << endl;
        cout << "\tSorting Harga Menu (y/n) : "; cin >> pilihanSortingUser;
        if(pilihanSortingUser == "y") {
            sortingData();
        }
        cout << "\tKembali (y/n) : ";
        cin >> pilihan_kembali;
        if (pilihan_kembali == "y") {
            system("cls");
            goto menu_utama;
        } else {
            do
            {
                system("cls");
                katalogHarga();
                cout << endl;
                cout << "\tSorting Harga Menu (y/n) : "; cin >> pilihanSortingUser;
                if(pilihanSortingUser == "y") {
                    sortingData();
                }
                cout << "\tKembali (y/n) : ";
                cin >> pilihan_kembali;
                if(pilihan_kembali == "y") {
                    system("cls");
                    goto menu_utama;
                }
            } while (pilihan_kembali != "y");
            
        }
        break;
    case 3:
        system("cls");
        searching:
        katalogHarga();
        cout << endl;
        cout << "\tCari Data (y/n) : "; cin >> pilihan_kembali;
        if (pilihan_kembali == "y") {
            searchingData();
        }
        cout << "\tKembali (y/n) : ";
            cin >> pilihan_kembali;
            if (pilihan_kembali == "y") {
                system("cls");
                goto menu_utama;
            } else {
                goto searching;
            }
        break;
    case 4:
        pembelian:
        pembelianBuah();
        cout << endl;
        int pilihan;
        cout << "\t1.Cetak Struk Pembelian" << endl; 
        cout << "\t2.Kembali Ke Menu" << endl;
        cout << "\tPilih [1-2] : "; cin >> pilihan;
        if(pilihan == 1) {
            strukBelanja();
        } else {
            system("cls");
            goto menu_utama;
        }
        cout << "\tKembali (y/n) : ";
        cin >> pilihan_kembali;
        if (pilihan_kembali == "y") {
            system("cls");
            goto menu_utama;
        } else {
            goto pembelian;
        }
        break;
    case 5:
        system("cls");
        system("color 4");
        cout << "Program Berakhir!!!";
        exit;
        break;
    default:
        cout << "Mohon Masukkan Pilihan!!!" << endl;
        cout << "Kembali (y/n) : ";
        cin >> pilihan_kembali;
        if (pilihan_kembali == "y") {
            system("cls");
            goto menu_utama;
        }
        break;
    }


    cout << endl;
    system("pause");
    return 0;
}