#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void AracEkle();
void AraclariListele();
typedef struct
{
    char plaka[30];
    char model[30];
    char renk[30];
}genel_ozellikler;

typedef struct
{
    genel_ozellikler ozellik;
    char giris_saati[9];
}arac_bilgisi;

typedef struct
{
    arac_bilgisi Araclar[1000];
    int aracsayisi;
}otopark;

otopark oto;

int main()
{
        printf("\n<<<<< ARAC TAKIP SISTEMINE HOSGELDINIZ.. >>>>>\n");
        AracEkle();
        AracEkle();
        AracEkle();
        AracEkle();
        AracEkle();
        AraclariListele();

    return 0;
}
 void AracEkle()
 {
     arac_bilgisi arac;

     printf("\nLutfen aracin ozelliklerini ve giris saat bilgisini giriniz !!\n");
     printf("Aracin Plakasi : "); gets(arac.ozellik.plaka);
     printf("Aracin Modeli  : "); gets(arac.ozellik.model);
     printf("Aracin Rengi   : "); gets(arac.ozellik.renk);
     printf("Giris Saati    : "); gets(arac.giris_saati);

     oto.Araclar[oto.aracsayisi]=arac;
     oto.aracsayisi++;


 }
 void AraclariListele()
 {
   int i;
   printf("\n<<<<< OTOPARKTAKI ARACLAR >>>>>\n");
   for(i=0;i<oto.aracsayisi;i++)
   {
       printf("\n%d.ARACIN\nPlakasi     >> %s\nModeli      >> %s\nRengi       >> %s\nGiris saati >> %s\n",i+1,
                                                                                 oto.Araclar[i].ozellik.plaka,
                                                                                 oto.Araclar[i].ozellik.model,
                                                                                 oto.Araclar[i].ozellik.renk,
                                                                                 oto.Araclar[i].giris_saati);
   }
 }








