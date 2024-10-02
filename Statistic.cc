#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double varyans(double *veri,int uzunluk);
double ortanca(double *veri,int uzunluk);
double aralik(double *veri,int uzunluk);
double stSapma(double vary);
double mod(double *veri,int uzunluk);
void sirala(double veri[],int uzunluk);

int main(){
    int uzunluk = 0;
    double *veri = NULL;
    char cevap;

    //devam sorusuna 'e' yada 'E' cevabi verildigi surece diziye ekleme yapar.
    do{
        veri = (double*)realloc(veri,(uzunluk+1)*sizeof(double));
        if (veri == NULL){
            cout << "Hafiza yerleştirme hatasi!" << endl;
            exit(1);
        }
        cout << "veri gir: ";
        cin >> veri[uzunluk];
        uzunluk++;
        cout << "Devam (e/h): ";
        cin >> cevap;
    }while(cevap == 'e' || cevap == 'E');

    cout << "-----------------------------------" << endl << "girilen veri: ";
    for(int i = 0; i < uzunluk; i++)
        cout << veri[i] << " ";
    cout << endl << "sirali hali: ";
    sirala(veri,uzunluk);
    for(int i = 0; i < uzunluk; i++) // dizi siralandiktan sonra ekrana yazar.
        cout << veri[i] << " ";
    cout << endl << "eleman sayisi: " << uzunluk << endl;
    double vary = varyans(veri,uzunluk);
    cout << "mod : " << mod(veri,uzunluk) << endl;
    cout << "varyans : " << vary << endl;
    cout << "standart sapma : " << stSapma(vary) << endl;
    cout << "ortanca : " << ortanca(veri,uzunluk) << endl;
    cout << "aralik : " << aralik(veri,uzunluk) << endl;
    cout << "------------------------------------" << endl;

    free(veri);
    return 0;
}

// girilen verileri buyukten kucuge siralar.
void sirala(double veri[], int uzunluk){
    double yedek;
    for(int i = 0; i < uzunluk; i++)
        for(int j = 0; j < uzunluk-1; j++)
            if(veri[j] > veri[j+1]){
                yedek = veri[j];
                veri[j] = veri[j+1];
                veri[j+1] = yedek;
            }
}

//varyans bulur.
double varyans(double *veri, int uzunluk){
    double ortalama, toplam = 0, sonuc = 0;
    int i;
    for(i = 0; i < uzunluk; i++)
        toplam += *(veri + i);

    ortalama = toplam/uzunluk;
    cout << "ortalama : " << ortalama << endl;
    
    for(i = 0; i < uzunluk; i++)
        sonuc += pow(*(veri+i)-ortalama,2)/(uzunluk-1);
    
    return sonuc;
}

//standart sapma bulur.
double stSapma(double varyans){
    return sqrt(varyans);
}

//ortanca bulur.
double ortanca(double *veri, int uzunluk){
    if(uzunluk % 2 != 0)
        return *(veri + (uzunluk/2));
    else{
        return (*(veri+(uzunluk/2 - 1)) + *(veri+(uzunluk/2))) / 2.0;
    }
}

//aralik bulur.
double aralik(double *veri, int uzunluk){
    double enb = *veri, enk = *veri;
    for(int i = 0; i < uzunluk; i++){
        if(enb < *(veri+i))
            enb = *(veri+i);
        if(enk > *(veri+i))
            enk = *(veri+i);
    }
    return enb-enk;
}

//dizinin en cok tekrar eden elemanini bulur.
double mod(double *veri, int uzunluk){
    int tekrar = 1, max = 1;
    double mod = *veri;

    for(int i = 0; i < uzunluk; i++){
        if(veri[i] == veri[i+1])
            tekrar++;
        else{
            if(tekrar > max){
            max = tekrar;
            mod = *(veri+i);
            }
        tekrar = 1;
        }
    }

    if(max == 1){
        cout << "\'mod bulunamadi tum elemanalar farkli.\' ";
        return -1;
    }

    return mod;
}