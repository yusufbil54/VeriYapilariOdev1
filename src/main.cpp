/** 
* @file               main.cpp
* @description        Bağıl Listelerle Düğümleri Sıralama
* @course             Veri Yapıları 1-C Grubu
* @assignment         1.Ödev
* @date               20.11.2022
* @author             Yusuf İslam Bil yusuf.bil@ogr.sakarya.edu.tr
*/
#include "TekYonluBagilListe.hpp"
#include "SatirListesi.hpp"
#include "YonetimListesi.hpp"
#include "ikiYonluBagilListe.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{  
    ifstream dosya("veriler.txt");                        //dosyamızı açıyoruz
    string satir="";
    SatirListesi* satirListesi = new SatirListesi();
    YonetimListesi* yonetimListesi=new YonetimListesi();
    while(getline(dosya,satir)) 
    {   
        SatirListesi* satirListesi = new SatirListesi();
        stringstream ss(satir);                                    
        int siradakiSayi;                                      //dosyadaki satırlarımızdaki sayıları teker teker çekiyoruz.
        while(ss>>siradakiSayi)
        {  
            satirListesi->ekle(siradakiSayi);                   //dosyadan çekilen sayıları satir listesine ekliyoruz.
        }
        satirListesi->ortalama();                             //satır listesindeki düğümlerin verilerinin ortalamasını alıyoruz
        ikiYonlu* yonetGec=yonetimListesi->ilk;
        TekYonlu* satirGec=satirListesi->ilk;                 //satır listesi ve yönetim listesinin ilk düğüm adreslerini alıyoruz.
        int sira=0;
        if(yonetGec==0)
        {   
            yonetimListesi->ekle(satirListesi->ilk);              //satır listesi düğümünün ilk elemanını yönetimlistesine ekliyoruz
        }
        else
        {   
            while(yonetGec!=0)
            {    
            if ((satirGec->ortalama) > (yonetGec->satirAdresi->ortalama))
            {  
                sira++;                                                          //yonetim listesinde yeni ortalamayı düğümdeki diğer ortalamalarla
            }                                                  //kıyaslayıp büyük olduğu düğüm sayısını geçerek artırıyor
            else                                                
            {   
                yonetimListesi->onuneEkle(sira,satirListesi->ilk,yonetimListesi->ilk);   //yerleşeceği sıranın önüne ekliyoruz.
                break;
            }
            if(yonetGec->sonraki==0)
            {
                yonetimListesi->ekle(satirListesi->ilk);   //eğer ortalama düğümlerdeki bütün ortalamalardan büyükse en sona ekliyoruz.
                break;
            }
            yonetGec=yonetGec->sonraki;
            }
            

            
        }
   }
    int satirSayisi=satirListesi->dosyaSatir;
    char karakter;
    int indexSira=0;
    int indexSatir=0;                                              //gerekli değişkenlerimizi tanımlıyoruz.
    int tamTurSayac=0;
    yonetimListesi->yazdir(indexSatir,satirSayisi);
    satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
    do  
    {  
        cin>>karakter;                     
        if(karakter=='c')                     
        {   if(indexSatir>=satirSayisi-1)                            //klavyeden c tuşuna basıldığında seçili düğüm bir sonraki düğüme geçiyor
            {   
                indexSatir=satirSayisi-2;
                indexSira=(satirSayisi%8)-1;
            }
            else if(indexSira==0)
            {
                indexSira++;
            }
            else if(indexSira%7==0)
            {
                indexSira=0;
            }else
            { 
                indexSira++;
            }
            indexSatir++;
            system("cls");
            yonetimListesi->yazdir(indexSatir,satirSayisi);         //düğümler ekrana yazdırılıyor.
            satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
        }
        if(karakter=='z')
        {   if(indexSira==0 && indexSatir%8==0 && indexSatir>0)
            {
                indexSira=7;
                indexSatir--;                                       //klavyeden z tuşuna basıldığında seçili düğüm bir önceki düğüme geçiyor
            }
            else if(indexSira==0)
            {
                indexSira=0;
                indexSatir=0;
            }
            else
            {
                indexSira--;
                indexSatir--;
            }
            
            system("cls");
            yonetimListesi->yazdir(indexSatir,satirSayisi);                  //düğümler ekrana yazdırılıyor.
            satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
        }
        if(karakter=='d')
        {   if(indexSatir>=satirSayisi-(satirSayisi%8))
            {
                indexSatir=satirSayisi-(satirSayisi%8);                   //klavyeden d tuşuna basıldığında ekrandaki yazılı olan 8 yönetim listesi düğümü 
            }                                                        //bir sonraki 8 düğüme geçiyor
            else
            {
                indexSatir=((indexSatir/8)+1)*8;   
            }
            indexSira=0;
            system("cls");
            yonetimListesi->yazdir(indexSatir,satirSayisi);                 //düğümler ekrana yazdırılıyor.
            satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
           
        }
        if(karakter=='a')
        {                                                  //klavyeden a tuşuna basıldığında ekrandaki yazılı olan 8 yönetim listesi düğümü
                                                            //bir önceki 8 düğüme geçiyor
            if(indexSatir<8)
            {
                indexSatir=(indexSatir/8)*8;
            }
            else
            {
                indexSatir=(indexSatir/8-1)*8;
            }

            indexSira=0;
            system("cls");
            yonetimListesi->yazdir(indexSatir,satirSayisi);                //düğümler ekrana yazdırılıyor.
            satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
            
        }
        if(karakter=='p')                                               //klavyeden p tuşuna basıldığında seçili düğüm siliniyor
        {  
            yonetimListesi->cikar(indexSatir,yonetimListesi->ilk);      //çıkar fonksiyonuyla seçili yönetimlistesi düğümü siliniyor
            system("cls"); 
            if((indexSatir+1)==satirSayisi)                                  //eğer son düğüm silinirse indexsatir bir fazla oluyor hata döndürmemesi
            {   satirSayisi--;                                               //için özel koşul yazıyoruz.
                yonetimListesi->yazdir(indexSatir,satirSayisi);                 //düğümler ekrana yazdırılıyor.
                satirListesi->yazdir(yonetimListesi->ilk,indexSira-1,indexSatir-1);
            }
            else
            {   satirSayisi--;
                yonetimListesi->yazdir(indexSatir,satirSayisi);                 //düğümler ekrana yazdırılıyor.
                satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
            }
            
        }
        if(karakter=='k')                                       //klavyeden k tuşuna basıldığında rastgele satır lsitesi düğümünden bir düğüm seçiliyor 
        {   srand(time(0));                                             
            int rastgele=rand() % ((satirListesi->elemanSayisi(indexSatir,yonetimListesi->ilk))-0);   //rastgele satır listesi seçmek için rand fonskiyonu kullanıyoruz
            yonetimListesi->yazdir(indexSatir,satirSayisi);                                             //düğümler ekrana yazdırılıyor.
            satirListesi->yazdirKbasinca(yonetimListesi->ilk,indexSira,indexSatir,rastgele);
            cin>>karakter; 
            if(karakter=='k')                        //ikinci kez klayeden k tuşuna basıldığında seçili olan satır listesi düğümünü siliyor
            {   
                int dondurulen=satirListesi->rastgeleCikar(yonetimListesi->ilk,rastgele,indexSatir);
                if(dondurulen==1)               //eğer silinen satır listesi düğümü son düğüm ise o yonetim listesi düğümü siliniyor.
                {
                    satirSayisi--;
                }
            }
            satirListesi->ortalamaDegistir(yonetimListesi->ilk,indexSatir);        //satır listesi düğümlerinde geri kalan düğümlerdeki 
            system("cls");                                                          //verilerin tekrar ortalaması alınıyor
            yonetimListesi->yazdir(indexSatir,satirSayisi);                            //düğümler ekrana yazdırılıyor.
            satirListesi->yazdir(yonetimListesi->ilk,indexSira,indexSatir);
            
        }

        if(karakter=='e')       //klavyeden e tuşuna basıldığında  programdan çıkılyor.
        {   
            break;           
        }

    } while (true);
    
delete satirListesi;
delete yonetimListesi;            //satır listesi düğümleri program sonlandığında siliniyor.
    
}




