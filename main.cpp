#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


string anahtarUret() {
    string anahtar;
    cout << "Lutfen anahtar giriniz (sadece buyuk harfler kullanin): ";
    cin >> anahtar;
    return anahtar;
}


string sifrele(string mesaj, string anahtar) {
    string sifreliMesaj;
    for (int i = 0; i < mesaj.length(); ++i) {
        char sifreliKarakter = ((mesaj[i] - 'A') + (anahtar[i] - 'A')) % 26 + 'A'; // Şifreleme işlemi
        sifreliMesaj += sifreliKarakter;
    }
    return sifreliMesaj;
}


string coz(string sifreliMesaj, string anahtar) {
    string cozulmusMesaj;
    for (int i = 0; i < sifreliMesaj.length(); ++i) {
        char cozulmusKarakter = ((sifreliMesaj[i] - 'A') - (anahtar[i] - 'A') + 26) % 26 + 'A'; // Şifre çözme işlemi
        cozulmusMesaj += cozulmusKarakter;
    }
    return cozulmusMesaj;
}

int main() {
    

    string mesaj, anahtar;

    
    cout << "Lutfen sifrelenecek mesaji giriniz (sadece buyuk harfler kullanin): ";
    cin >> mesaj;

    
    do {
        anahtar = anahtarUret();
        if (anahtar.length() != mesaj.length()) {
            cout << "Anahtar, mesaj ile aynı uzunlukta olmalıdır. Lütfen tekrar giriniz." << endl;
        }
    } while (anahtar.length() != mesaj.length());

    
    string sifreliMesaj = sifrele(mesaj, anahtar);
    cout << "Sifreli Mesaj: " << sifreliMesaj << endl;

    
    string cozulmusMesaj = coz(sifreliMesaj, anahtar);
    cout << "Cozulmus Mesaj: " << cozulmusMesaj << endl;

    return 0;
}
