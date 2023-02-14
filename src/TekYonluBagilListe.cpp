/** 
* @file               TekYonluBagilListe.cpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#include "TekYonluBagilListe.hpp"
#include "SatirListesi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
TekYonlu::TekYonlu(int veri)
{
    this->veri=veri;
    this->sonraki=0;                          //satir listesi düğümlerinin oluşacağı metotların içeriği
    this->ortalama=0;
}
TekYonlu::~TekYonlu()
{
    cout<<veri<<": dugum silindi"<<endl;      // Yıkıcı fonksiyon çalıştığında ekrana yazılacak yazı.
}
