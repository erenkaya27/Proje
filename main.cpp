#include <iostream>
#include <string>

using namespace std;

string sifrele( string metin, string anahtar) {
    string sifreliMetin = metin;
    for (int i = 0; i < metin.length(); ++i) {
        sifreliMetin[i] = metin[i] ^ anahtar[i % anahtar.length()];
    }
    return sifreliMetin;
}

string coz( string sifreliMetin,  string anahtar) {
    return sifrele(sifreliMetin, anahtar);  
}

int main() {
    string metin, anahtar;

    
    cout << "Şifrelenecek metni girin: ";
    cin>>metin;

    cout << "Anahtar metni girin: ";
    cin>>anahtar;

    
    string sifreliMetin = sifrele(metin, anahtar);
    cout << "Şifrelenmiş metin: " << sifreliMetin << endl;

    
    string cozulmusMetin = coz(sifreliMetin, anahtar);
    cout << "Deşifrelenmiş metin: " << cozulmusMetin << endl;

    return 0;
}


