/** 
* @file               SatirListesi.cpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "SatirListesi.hpp"
#include "TekYonluBagilListe.hpp"
#include "YonetimListesi.hpp"
#include "ikiYonluBagilListe.hpp"
using namespace std;

SatirListesi::SatirListesi()
{
    ilk=0;
    dosyaSatir=satirSayisiBul();                  //program çalıştığında çalışacak kurucu fonksiyonun içeriği
}
SatirListesi::~SatirListesi()
{
     TekYonlu* gec=ilk;
       while (gec!=0)                             //program sonlandığında yıkıcı çalıştığında düğümleri silmek için oluşturduğumuz fonksiyon
       {
            TekYonlu* sil=gec;
            gec=gec->sonraki;
            delete sil;
       }
}

void SatirListesi::ekle(int veri)
{
    TekYonlu *yeni = new TekYonlu(veri);
    if(ilk==0)
    {
        ilk=yeni;
       
    }
    else
    {                                                //satır listesinde sona ekleme fonksiyonu
       TekYonlu* gec=ilk;
       while (gec->sonraki!=0)
       {
            gec=gec->sonraki;
       }
       gec->sonraki=yeni;
       
    }
}

void SatirListesi::yazdirKbasinca(ikiYonlu* adres,int indexSira,int indexSatir,int rastgele)
{   
  ikiYonlu* yonetimGec=adres;
    for(int i=0; i<indexSatir;i++)
    {
        yonetimGec=yonetimGec->sonraki;
    }
    TekYonlu* gec=yonetimGec->satirAdresi;                 //klavyeden k tuşuna basıldığında ekrana yazılacakları ayarlıyacak yazdır fonksiyonumuz
    int sayac=0;
    int ksayaci=0;
    while (gec!=0)
        {  
            if(sayac==0)
            {
                cout<<setw(indexSira*13)<<""<<"^^^^^^^^^^"<<endl;
                sayac++;
            }
            
            if(gec->sonraki==0)
            {   
                cout<<setw(indexSira*13)<<""<<" "<<gec<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|   "<<gec->veri<<"   |";
                if(ksayaci==rastgele)
                {
                    cout<<setw(10)<<""<<"<---- silinecek secili";      //silinecek düğümü gösterir
                }
                cout<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|"
                <<"00000000"<<"|"<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n\n\n";
            }
            else
            {
            cout<<setw(indexSira*13)<<""<<" "<<gec<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|   "<<gec->veri<<"   |";
                if(ksayaci==rastgele)
                {
                    cout<<setw(10)<<""<<"<---- silinecek secili";
                }
            cout<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|"
            <<gec->sonraki<<"|"<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n\n";
            }
            gec=gec->sonraki;
            ksayaci++;
            
        }
       cout<<endl;
    
}
void SatirListesi::yazdir(ikiYonlu* adres,int indexSira,int indexSatir)
{   
    ikiYonlu* yonetimGec=adres;
    for(int i=0; i<indexSatir;i++)
    {
        yonetimGec=yonetimGec->sonraki;                    //satır listesi düğümlerinin ekrana yazdırılması için tanımlanan metot.
    }
    TekYonlu* gec=yonetimGec->satirAdresi;
    int sayac=0;
    while (gec!=0)
        {   if(sayac==0)
            {
                cout<<setw(indexSira*13)<<""<<"^^^^^^^^^^"<<endl;
                sayac++;
            }
            
            if(gec->sonraki==0)
            {   
                cout<<setw(indexSira*13)<<""<<" "<<gec<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|   "<<gec->veri<<"   |"
                <<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|"
                <<"00000000"<<"|"<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n\n\n";
            }
            else
            {
            cout<<setw(indexSira*13)<<""<<" "<<gec<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|   "<<gec->veri<<"   |"
            <<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n"<<setw(indexSira*13)<<""<<"|"
            <<gec->sonraki<<"|"<<"\n"<<setw(indexSira*13)<<""<<"----------"<<"\n\n";
            }
            gec=gec->sonraki;
            
        }
       cout<<endl;
}
void SatirListesi::cikar(TekYonlu* adres)
{   ilk=adres;
    if(ilk==0)
    {
        return;
    }
    if(ilk->sonraki==0)
    {
        delete ilk;                              //satir listesi düğümlerinde son elemanı çıkarmak için tanımlanan metot.
        ilk=0;
    }
    else
    {
        TekYonlu *gec=ilk;
        while(gec->sonraki->sonraki!=0)
        {
            gec=gec->sonraki;
        }
       delete gec->sonraki;
       gec->sonraki=0;
    }
}
int SatirListesi::rastgeleCikar(ikiYonlu* adres,int sira,int indexSatir)
{  
    ikiYonlu* yonetGec=adres;
    YonetimListesi* yonetimListesi=new YonetimListesi();
    TekYonlu* gec=0;
    TekYonlu* gecici=0;
    TekYonlu* geciciSonra=0;
    int siraGecici=0;
    while(yonetGec!=0)
    {   
        if(siraGecici==indexSatir)
        {
            gec=yonetGec->satirAdresi;
            break;                            //klavyeden k tuşuna basıldığında rastgele seçilen satır listesi düğümü silmek için tanımlanan metot
        }
        yonetGec=yonetGec->sonraki;
        siraGecici++;
    }
    if(gec==0)
    {
        return -1;
    }
    if(gec->sonraki==0)
    {
        delete gec;
        gec=0;
        yonetimListesi->cikar(indexSatir,adres);            //eğer satır listesinden son düğüm silinirse satır listesi bittiği için yönetim listesi
        return 1;                                           //düğümünü siliyor.
    }
    else
    {
        int sayac=0;
        while(gec!=0)
        {   
            if(sira==0)
            {   geciciSonra=gec->sonraki;
                delete gec;
                gec=geciciSonra;
                yonetGec->satirAdresi=gec;
                break;
            }
            else if(sayac==sira) 
            {   geciciSonra=gec->sonraki;
                delete gec;
                gec=gecici;
                gec->sonraki=geciciSonra;
                break;
            }
            sayac++;
            gecici=gec;
            gec=gec->sonraki;
        }
        
        
    }
    return 0;
}

int SatirListesi::satirSayisiBul()
{   
    ifstream dosyaOku("veriler.txt");dosyaSatir=0;
    if (dosyaOku.is_open()) 
    { 
        while (getline(dosyaOku, satir))               //dosyamızdaki satır sayısını döndüren fonksiyon
        {   
            dosyaSatir++;
        }
       dosyaOku.close();
    }
   return dosyaSatir;
}
void SatirListesi::ortalama()
{
  
    TekYonlu* gec=ilk;
    float toplam =0;
    float ortalama=0;
    float dugumSayisi=0;                                      //satır listesi düğümündeki verilerin ortalamasını alıp düğümün ortalama 
    while (gec!=0)                                            //değişkenine atayan fonksiyon
    {            
        toplam +=(float)gec->veri;
        gec=gec->sonraki;
        dugumSayisi++;
    }
    ortalama=round((toplam/dugumSayisi)*10)/10;
    
    ilk->ortalama=ortalama;   
    
}
void SatirListesi::ortalamaDegistir(ikiYonlu* adres,int indexSatir)
{  
    ikiYonlu* yonetGec=adres;
    YonetimListesi* yonetimListesi=new YonetimListesi();
    TekYonlu* gec=0;
    int siraGecici=0;
    while(yonetGec!=0)
    {   
        if(siraGecici==indexSatir)
        { 
            gec=yonetGec->satirAdresi;
            break;                                  //klavyeden k tuşuna basıldığında silinen satır listesi düğümünnden geri kalan satır listesi
        }                                           //düğümlerinin tekrardan ortalamsını alıp ortalama değişkenini güncelletyen fonksiyonumuz
        yonetGec=yonetGec->sonraki; 
        siraGecici++;
    }
    float toplam =0;
    float ortalama=0;
    float dugumSayisi=0;
    while (gec!=0)
    {       
        toplam +=(float)gec->veri;
        gec=gec->sonraki;
        dugumSayisi++;
    }
   
    ortalama=round((toplam/dugumSayisi)*10)/10;
    gec=yonetGec->satirAdresi; 
    gec->ortalama=ortalama;
    int sira=0;
    yonetGec=adres;
    yonetimListesi->cikar(indexSatir,adres);                  //eğer silinen düğüm satır listesinin son düğümü ise satır listesinde eleman kalmadığı için
            while(yonetGec!=0)                              // yonetim listesi düğümü silinir
            {    
                if ((ortalama) >= (yonetGec->satirAdresi->ortalama))
                {
                    sira++;
                }
                else                                                 
                {  
                    yonetimListesi->onuneEkle(sira,gec,adres);
                break;
                }
            yonetGec=yonetGec->sonraki;
            }
}
int SatirListesi::elemanSayisi(int sira,ikiYonlu* adres)
{  
    ikiYonlu* yonetGec=adres;
    TekYonlu* gec=0;
    int siraGecici=0;
    while(yonetGec!=0)
    {
        if(siraGecici==sira)
        {   
            gec=yonetGec->satirAdresi;
            break;
        }                                //seçilen yönetim listesi düğümündeki satır listesi düğümlerinin sayısını döndüren fonksiyon.
        yonetGec=yonetGec->sonraki;
        siraGecici++;
    }
    
    int dugumSayisi=0;
    while(gec!=0)
    {   dugumSayisi++;
        gec=gec->sonraki;

    }
    return dugumSayisi;
}


