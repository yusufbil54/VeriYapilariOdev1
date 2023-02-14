/** 
* @file               YonetiListesi.cpp
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
#include "YonetimListesi.hpp"
#include "ikiYonluBagilListe.hpp"
#include "TekYonluBagilListe.hpp"
#include "SatirListesi.hpp"
using namespace std;
YonetimListesi::YonetimListesi()
{
    ilk=0;      //ilk değeri tanımlanır
}
void YonetimListesi::ekle(TekYonlu* satirAdresi)
{   
    ikiYonlu* yeniDugum=new ikiYonlu(satirAdresi);
    if(ilk==0)
    {
        ilk=yeniDugum;                      //Yonetim Listesi düğümlerinin sonuna eklem yapar
    }
    else
    {
        ikiYonlu* gec=ilk;

        while (gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }
        gec->sonraki=yeniDugum;
        yeniDugum->onceki=gec;
    }
}
void YonetimListesi::cikar()
{
    if(ilk==0)
    {
        return;
    }
    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        ikiYonlu* gec=ilk;                           //Yonetim Listesi düğümlerinin sonundan eleman çıkartır.
        while(gec->sonraki->sonraki!=0)
        {
            gec=gec->sonraki;

        }
        delete gec->sonraki;
        gec->sonraki=0;
    }
}
void YonetimListesi::cikar(int sira, ikiYonlu* adres)
{   
    ikiYonlu* silinecek= dugumGetir(sira,adres);
    if(silinecek)
    {
        ikiYonlu* silOnceki= silinecek->onceki;
        ikiYonlu* silSonraki= silinecek->sonraki;
        if(silSonraki)
        {                                                      //yonetim listesi düğümlerinden seçilen sıradakini parametre olarak alır ve o düğümü siler.
            silSonraki->onceki=silOnceki;
        }
        if(silOnceki)
        {
            silOnceki->sonraki=silSonraki;
        }
        else
        {
            ilk=silSonraki;
        }
        delete silinecek;
    }
}
void YonetimListesi::onuneEkle(int sira,TekYonlu* satirAdresi,ikiYonlu* adres)
{   
    ikiYonlu* aktifDugum=dugumGetir(sira,adres);
    if(aktifDugum)
    {   
        ikiYonlu* aktifOnceki=aktifDugum->onceki;
        ikiYonlu* yeniDugum=new ikiYonlu(satirAdresi);
        aktifDugum->onceki=yeniDugum;
                                                                  //yonetim listesi düğümlerinde listedeki seçilen sıraya yani araya ekleme yapar.
        yeniDugum->sonraki=aktifDugum;
        yeniDugum->onceki=aktifOnceki;
        if(aktifOnceki)
        {
            aktifOnceki->sonraki=yeniDugum;
        }
        else
        {
            ilk=yeniDugum;
        }
    }
}
void YonetimListesi::yazdir(int index,int satirSayisi)
{   
    SatirListesi* satirListesi = new SatirListesi();
    system("cls");
                                                    //Yonetim listesi düğümlerini ekrana yazdırır
    ikiYonlu* gec=ilk;
    if(index<8)
    {
    gec=ilk;
    }
    else if(index%8==0 && satirSayisi-(satirSayisi%8)>index)       // ekranda 8 düğüm gözükmesi gerektiği için sıra parametreleri alan fonksiyonumuz
    {                                                              //için konsoldaki sıra eğer ilk 8 lideyse ekrana ilk 8 düğüm yazılır
        gec=ilk;                                                   //eğer ortadaki değerler iste sıralama diğer 8 lileri ekrana getirmek için ayarlanmıştır
        for(int i=0; i<index; i++)                                 //Eğer ekrana son düğümleri yazdırmak istiyorsak satır sayısının modu alınır o kadar satır yazılır
        {
            gec=gec->sonraki;
        }
    }
    else
    { 
        gec=ilk;
        int kat=(index/8);
        for(int i=0; i<8*kat; i++)
        {
            gec=gec->sonraki;
        }
    }

    if(satirSayisi-(satirSayisi%8)>index)
    {   if(index<8)
        {
            cout<<"ilk"<<setw(95)<<" "<<"-->"<<endl; 
        }
        else
        {                                              // menünün üstündek okların ayarlanışı ve yonetim listesi düğümlerinin adresleri
            cout<<"<--"<<setw(95)<<" "<<"-->"<<endl;
        }
        for(int i=0; i<8; i++)
        {
            cout<<setw(1)<<" "<<gec<<setw(4)<<" ";
            gec=gec->sonraki;
        }
        cout<<endl;
    
        for(int i=0; i<8; i++)
        {
        cout<<"----------"<<setw(3)<<" ";
        }
    }
    else
    {   cout<<"<--"<<setw((satirSayisi%8)*10)<<" "<<"son"<<endl;
        for(int i=0; i<satirSayisi%8; i++)
        { 
            cout<<setw(1)<<" "<<gec<<setw(4)<<" ";             // son düğüm satırıysa son ekrana yazılan oklar ve yonetim listesi düğümlerinin adresleri
            gec=gec->sonraki;
        }
        cout<<endl;
    
        for(int i=0; i<satirSayisi%8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }
    }
    cout<<endl;


        if(index<8)
        {
        gec=ilk;
        cout<<"|"<<"00000000"<<"|"<<setw(3)<<" ";   
        }
        else if(index%8==0)
        {
            gec=ilk;
            for(int i=0; i<index; i++)
            {
                gec=gec->sonraki;
            }
            cout<<"|"<<gec->onceki<<"|"<<setw(3)<<" ";               //yonetim listesi düğümlerinin onceki adreslerinin ekrana yazıldığı alan
        }
        else 
        {   gec=ilk;
            int kat=(index/8);
            for(int i=0; i<8*kat; i++)
            {
                gec=gec->sonraki;
            }
            cout<<"|"<<gec->onceki<<"|"<<setw(3)<<" ";
        }

        
    if(satirSayisi-(satirSayisi%8)>index)
    {
        gec=gec->sonraki;
        for(int i=0; i<7; i++)
        {
            cout<<"|"<<gec->onceki<<"|"<<setw(3)<<" ";              //ilk 8 düğüm gösterilicekse ekrana ilk düğümün önceki değeri 0 olduğu için
            gec=gec->sonraki;                                       //string olarak 00000000 yazabilmek için gerisini 7 satır yazdırıyoruz.
        }
        cout<<endl;
   
        for(int i=0; i<8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }
    }
    else
    {
       
        for(int i=1; i<satirSayisi%8; i++)
        {   
            gec=gec->sonraki;
            cout<<"|"<<gec->onceki<<"|"<<setw(3)<<" "; 
        }
        cout<<endl;
   
        for(int i=0; i<satirSayisi%8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }
    }

    cout<<endl;
 
        if(index<8)
        {
            gec=ilk;
        }
        else if(index%8==0)
        {   gec=ilk;
            for(int i=0; i<index; i++)
            {
                gec=gec->sonraki;                     //yonetim listesi düğümlerinin konsoldaki sıranın düğüm adresini getirmek için for döngüsüyle
            }                                         //seçilen düğümün adresini gec değişkenine atıyoruz.
        }
        else 
        {   gec=ilk;
            int kat=(index/8);
            for(int i=0; i<8*kat; i++)
            {
                gec=gec->sonraki;
            }
        }
    if(satirSayisi-(satirSayisi%8)>index)
    {
        for(int i=0; i<8; i++)
        {                                                           //son düğüm listesi değilse çalışacak kod bloğu
            if(to_string(gec->satirAdresi->ortalama)[3]!='0')      //yonetim listesi düğümlerinin ortalama değerlerini ekrana yazıldığı alan
            {
            cout<<"|"<<setw(2)<<" "<<gec->satirAdresi->ortalama<<setw(2)<<" "<<"|"<<setw(3)<<" ";       
            }           
            else
            {
            cout<<"|"<<setw(3)<<" "<<gec->satirAdresi->ortalama<<setw(3)<<" "<<"|"<<setw(3)<<" ";
            }

            gec=gec->sonraki;
        }
        cout<<endl;
   
        for(int i=0; i<8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }
    }
    else
    {   
        for(int i=0; i<satirSayisi%8; i++)                           //son yonetim listesi düğümünde isek çalışacak kod bloğu
        {   
            if(to_string(gec->satirAdresi->ortalama)[3]!='0')       //yonetim listesi düğümlerinin ortalama değerlerinin ekrana yazıldığı alan
            {
            cout<<"|"<<setw(2)<<" "<<gec->satirAdresi->ortalama<<setw(2)<<" "<<"|"<<setw(3)<<" ";
            }
            else
            {
            cout<<"|"<<setw(3)<<" "<<gec->satirAdresi->ortalama<<setw(3)<<" "<<"|"<<setw(3)<<" ";
            }

            gec=gec->sonraki;
        }
        cout<<endl;
   
        for(int i=0; i<satirSayisi%8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }
    }
    cout<<endl;

    if(index<8)
    {
    gec=ilk;
    }
    else if(index%8==0)
    {   gec=ilk;
        for(int i=0; i<index; i++)                      //seçilen düğümün adresini gec değişkenine atıyoruz.
        {
            gec=gec->sonraki;
        }
    }
    else 
    {   gec=ilk;
        int kat=(index/8);
        for(int i=0; i<8*kat; i++)
        {
            gec=gec->sonraki;
        }
    }

    if(satirSayisi-(satirSayisi%8)>index)                       ////son düğüm listesi değilse çalışacak kod bloğu
    {

        for(int i=0; i<8; i++)                            
        {
            cout<<"|"<<gec->sonraki<<"|"<<setw(3)<<" ";
            gec=gec->sonraki;                              ////yonetim listesi düğümlerinin sonraki adreslerinin ekrana yazıldığı alan
        }
        cout<<endl;
    
        for(int i=0; i<8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";
        }

    }
    else
    {
        for(int i=0; i<satirSayisi%8; i++)
        {
            if(gec->sonraki==0)
            {

                cout<<"|"<<"00000000"<<"|"<<setw(3)<<" ";
            }
            else
            {
                cout<<"|"<<gec->sonraki<<"|"<<setw(3)<<" ";
            }
            gec=gec->sonraki;                              //son düğüm listesi ise çalışacak kod bloğu
        }
        cout<<endl;
    
        for(int i=0; i<satirSayisi%8; i++)
        {
            cout<<"----------"<<setw(3)<<" ";               
        }
    }
        cout<<endl;
        cout<<endl;
}
YonetimListesi::~YonetimListesi()
{
    ikiYonlu* gec=ilk;
    while (gec!=0)
    {
        ikiYonlu* silinecek=gec;               //program sonlandığında yıkıcı fonksiyon çalışıyor hafızayı temizliyor
        gec=gec->sonraki;
        delete silinecek;
    }
    
}
ikiYonlu* YonetimListesi::dugumGetir(int sira, ikiYonlu* adres)
{  
    ikiYonlu* gec=adres;
    while (sira>=0 && gec!=0)
    {
        if(sira==0)
        {                                //istenilen düğümün adresini getirir.
            return gec;
        }

        gec= gec->sonraki;
        sira--;
    }
    return 0;
}
