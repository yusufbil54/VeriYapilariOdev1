/** 
* @file               ikiYonluBagilListe.hpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#ifndef ikiYonluBagilListe_hpp
#define ikiYonluBagilListe_hpp
#include "TekYonluBagilListe.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ikiYonlu
{
    public:
         ikiYonlu(TekYonlu* satirAdresi);
        ~ikiYonlu();
            ikiYonlu* sonraki;
            ikiYonlu* onceki;                 //yonetiim listesi düğümlerinin sistemde aktif olması için kullandığımız düğüm sınıfı 
            TekYonlu* satirAdresi;            //metotlarını tanımlıyoruz
        
        
};
#endif