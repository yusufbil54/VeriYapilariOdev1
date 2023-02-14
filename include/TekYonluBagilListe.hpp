/** 
* @file               TekYonluBagilListe.hpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#ifndef TekYonluBagilListe_hpp
#define TekYonluBagilListe_hpp
class TekYonlu
{
    public:
    TekYonlu(int veri);
    ~TekYonlu();
    int veri;                              //satir listesi düğümlerinin oluşacağı yerin kütüphanesi
    float ortalama;
    TekYonlu* sonraki;
};
#endif