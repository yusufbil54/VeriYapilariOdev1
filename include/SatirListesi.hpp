/** 
* @file               SatirListesi.hpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "TekYonluBagilListe.hpp"
#include "YonetimListesi.hpp"
#include "ikiYonluBagilListe.hpp"
#include <iostream>
#include <string>
using namespace std;
class SatirListesi
{
public:
    SatirListesi();
    ~SatirListesi();                                                        //satır listesi metotlarını tanımlıyoruz.
    void ekle(int veri);
    void yazdirKbasinca(ikiYonlu* adres,int indexSira,int indexSatir,int rastgele);
    int elemanSayisi(int sira,ikiYonlu* adres);
    int rastgeleCikar(ikiYonlu* adres,int sira,int indexSatir);
    void cikar(TekYonlu* adres);
    int satirSayisiBul();
    void ortalama();
    void ortalamaDegistir(ikiYonlu* adres,int indexSatir);
    void yazdir(ikiYonlu* adres,int indexSira,int indexSatir);
    
    int dosyaSatir=0;
    TekYonlu* ilk;
private:
    string satir = "";
   
    
    
};

#endif