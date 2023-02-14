/** 
* @file               ikiYonluBagilListe.cpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "ikiYonluBagilListe.hpp"

ikiYonlu::ikiYonlu(TekYonlu* satirAdresi)
{
    this->satirAdresi=satirAdresi;                        //Yonetim listesi düğümlerini tanımlamak için oluşturduğumuz düğüm sınıfı için
    onceki=sonraki=0;                                    //oluşturduğumuz metotların içeriğini  yazıyoruz
}
ikiYonlu::~ikiYonlu()
{
    cout<<this<<": adresindeki dugum silindi"<<endl;         // Yıkıcı fonksiyon çalıştığında ekrana yazılacak yazı.
}