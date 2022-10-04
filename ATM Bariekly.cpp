//Bariekly
#include "iostream"
using namespace std;

int PIN, saldo, inputPIN, nominalTarik, rekeningTujuan, nominalTransfer, nominalSedekah;
char pilihanMenu;
bool mengulangMenu;

int main(){


    cout << "SELAMAT DATANG DI MESIN ATM PENGGANDA UANG" << endl;
    cout << "\nSILAKAN MASUKKAN KARTU ATM ANDA" << endl;

    cout << "\nSebelum menggunakan kartu Anda, silakan setting terlebih dahulu PIN ATM Anda." << endl;
    cout << "Masukkan 6 Digit Angka PIN Baru Anda : " << endl;
    cin >> PIN;

    cout << "Masukkan Jumlah Saldo Anda : " << endl;
    cin >> saldo;

    cout << "====================================================================================== \n" << endl;


    short wrongPIN = 0;
    do {
        cout << "MASUKKAN PIN ANDA DENGAN BENAR: " << endl;
        cin >> inputPIN;
        if (inputPIN != PIN){
            wrongPIN++;
            cout << "PIN yang Anda masukkan Salah"<< endl;
            if (wrongPIN == 3){
                cout << "Maaf, Kartu Anda terblokir, Silakan datang ke Kantor Terdekat"<< endl;
                goto exitLabel;
            }
        }
    } while (inputPIN != PIN);

    do {
        do {
            char inputPilihanMenu;
            cout << "MASUKKAN PILIHAN ANDA DENGAN BENAR : " << endl;
            cout << "A : Cek Saldo" << endl;
            cout << "B : Tarik Tunai" << endl;
            cout << "C : Transfer" << endl;
            cout << "D : Sedekah" << endl;
            cout << "X : Exit Program" << endl;
            cin >> inputPilihanMenu;
            pilihanMenu = toupper(inputPilihanMenu);
        } while (pilihanMenu != 'A' && pilihanMenu != 'B' && pilihanMenu != 'C' && pilihanMenu != 'D' && pilihanMenu != 'X');


        switch (pilihanMenu) {
            case 'A':
                cout << "Saldo Anda saat ini adalah " << saldo << endl;
                break;
            case 'B':
                cout << "Masukkan Nominal yang Anda Inginkan :" << endl;
                cin >> nominalTarik;
                if (nominalTarik <= saldo){
                    cout << "Silakan Tunggu, permintaan Anda sedang kami proses." << endl;
                    saldo -= nominalTarik;
                    cout << "Uang Anda telah siap, silakan ambil" << endl;
                    cout << "Sisa saldo Anda sekarang adalah : " << saldo << endl;
                }else{
                    cout << "Maaf, Saldo Anda tidak mencukupi." << endl;
                }
                break;
            case 'C':
                cout << "Masukkan nomor rekening tujuan :" << endl;
                cin >> rekeningTujuan;
                cout << "Masukkan nominal yang ingin Anda transfer :" << endl;
                cin >> nominalTransfer;
                if (nominalTransfer <= saldo){
                    cout << "Silakan Tunggu, permintaan Anda sedang kami proses." << endl;
                    saldo -= nominalTransfer;
                    cout << "Transfer ke rekening " << rekeningTujuan << " sebesar " << nominalTransfer << " telah berhasil." << endl;
                    cout << "Sisa saldo Anda sekarang adalah : " << saldo << endl;
                }else{
                    cout << "Maaf, Saldo Anda tidak mencukupi." << endl;
                }
                break;
            case 'D':
                cout << "Masukkan nominal sedekah Anda :" << endl;
                cin >> nominalSedekah;
                if (nominalSedekah <= saldo){
                    cout << "Silakan Tunggu, permintaan Anda sedang kami proses." << endl;
                    saldo -= nominalSedekah;
                    cout << "Sedekah sebesar : " << nominalSedekah << " telah berhasil." << endl;
                    cout << "Sisa saldo Anda sekarang adalah : " << saldo << endl;
                }else{
                    cout << "Maaf, Saldo Anda tidak mencukupi." << endl;
                }
                break;
            case 'X':
                goto exitLabel;
        }

        char inputInginMengulang;
        char inginMengulang;
        do {
            cout << "Apakah Anda ingin melakukan transaksi lain? (Y/N)" << endl;

            cin >> inputInginMengulang;
            inginMengulang = toupper(inputInginMengulang);

            if (inginMengulang == 'Y'){
                mengulangMenu = true;
            } else{
                mengulangMenu = false;
            }
        } while (inginMengulang != 'Y' && inginMengulang != 'N');

    } while (mengulangMenu);
    exitLabel:
    cout << "Silakan Ambil Kartu Anda, Terima Kasih" << endl;

    return 0;
}

