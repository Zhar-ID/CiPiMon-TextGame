#include <iostream>

using namespace std;

struct stats{
    string nama;
    int darah;
};
struct elemen{
    int api;
    int air;
    int tanah;
};

stats player = {"",10};
stats boss1 = {"Adamon",10};
stats boss2 = {"Yudai",5};
stats boss3 = {"F",10};

elemen dmgplayer = {1,10,99};
elemen dmgboss1 = {3,3,3};
elemen dmgboss2 = {7,7,7};
elemen dmgboss3 = {10,10,10};

void Tarung(){
    if (boss1.darah <= 0)
    cout <<"Menang, Lawan Terbantai";
    if (player.darah <= 0)
    cout <<"Kamu Kalah";
}

void MainGa(){
    cout <<"Apakah Anda Ingin Bermain?(y/n) :";
}

void Main(char pilihan){
    if (pilihan == 'y'){
        cout << "Anda memilih untuk bermain\nBersiaplah Untuk bertempur\n";
    }
    else if (pilihan == 'n'){
        cout << "Anda memilih untuk tidak bermain\nAnda adalah pengecut\n";
        exit(0);
    }
    else {
        cout << "Pilihan Tidak Valid\n";
    }
}

void Spasi(){
    cout << endl;
}

void Infodarah(){
    cout << "Darah " << player.nama << " Sekarang Adalah : " << player.darah;
}

void Serangan(){
    
}

void Bersiap(int level){
    switch (level) {
        case 1:
            cout << "Bersiap, Lawanmu Sekarang adalah " << boss1.nama << " Mulai Serangan Dengan : ";
            cout << "\n1.Elemen Api\n2.Elemen Air\n3.Elemen Tanah";
            break;
        case 2:
            cout << "Bersiap, Lawanmu Sekarang adalah " << boss2.nama << " Mulai Serangan Dengan : ";
            cout << "\n1.Elemen Api\n2.Elemen Air\n3.Elemen Tanah";
            break;
        case 3:
            cout << "Bersiap, Lawanmu Sekarang adalah " << boss3.nama << " Mulai Serangan Dengan :";
            cout << "\n1.Elemen Api\n2.Elemen Air\n3.Elemen Tanah";
            break;
        default:
            cout << "Tidak ada lawan yang ditentukan untuk level ini";
            break;
    }
}

void Serang(int elemen,int &power){
    if (elemen == 1){
        power = dmgplayer.api;
        cout << "Elemen Api";
    }
    else if (elemen == 2){
        cout << "Elemen Air";
        power = dmgplayer.air;
    }
    else if (elemen == 3){
        cout << "Elemen Tanah";
        power = dmgplayer.tanah;
    }
    else {
        cout << "Pilihan Tidak Valid";
    }
}

void SeranganPlayer (int level, int power){
    switch (level) {
        case 1:
        cout << power << " Damage Diberikan\n";
        boss1.darah -= power;
        cout << boss1.darah << " Boss Darah Tersisa\n";
        break;
        case 2:
        boss2.darah -= power;
        break;
        case 3:
        boss3.darah -= power;
        break;
        default:
        break;
    }
}

int main (){
    char input = 'v';
    int efek = 50;
    int elemen = 0;
    int kesempatan = 3;
    int power;
    cout << "Selamat Datang Di Game Cipipimon", Spasi();
    do {
        MainGa();
        cin >> input;
        Main(input);
    }while (input != 'y' && input != 'n');
    cout <<"Sebelum Itu Berikan Nama Untuk Cipipimon Mu\nMasukan Nama : ";
    cin >> player.nama;
    Infodarah();
    int i;
    for (int level = 1; level <= 3;level++){
        //for (int nyawa = 3; nyawa >= 1; nyawa--){
            if (level == 1){
                do{
                    Bersiap(level);
                    cin >> elemen;
                    Spasi();
                    Serang(elemen, power);
                    Spasi();
                    cout << "Player Menyerang";
                    Spasi();
                    SeranganPlayer(level, power);
                }while (boss1.darah > 0 && player.darah > 0);
                Tarung();
                break;
            }
            else if (level == 2){
                Bersiap(level);
            }
            else if (level == 3){
                Bersiap(level);
            }
            else {
                cout << "Kamu Berhasil Menamatkan Game Ini";
            }
        //}
    }   
}