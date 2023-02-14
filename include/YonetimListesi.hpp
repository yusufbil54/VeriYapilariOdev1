/** 
* @file               YonetimListesi.hpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#ifndef YonetimListesi_hpp
#define YonetimListesi_hpp
#include <iostream>
#include "ikiYonluBagilListe.hpp"
#include "TekYonluBagilListe.hpp"
#include "SatirListesi.hpp"
class YonetimListesi
{
public:
    YonetimListesi();
    ~YonetimListesi();
    void ekle(TekYonlu* satirAdresi);
    void cikar();
    void cikar(int sira, ikiYonlu* adres);                    //yonetim listesi metotlarını tanımlıyoruz.
    void onuneEkle(int sira,TekYonlu* satirAdresi,ikiYonlu* adres);
    void yazdir(int index,int satirSayisi);
    ikiYonlu* ilk;
private:
    
    ikiYonlu* dugumGetir(int sira, ikiYonlu* adres);  
};
#endif