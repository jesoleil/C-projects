#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *dosya;                            //tanimlamalar yapiliyor.
int hp=100;
int parkur_uzunluk,engel_sayisi;
int i, engel[4];
int *engelPtr;


void dosya_olustur();                    //fonksiyon prototipleri tanimlaniyor.
void random_olustur();
int engeller(int parkur_uzunluk , int engel_sayisi, int *engelPtr);
int obeb(int a,int b);
int asal(int a,int b);
int kontrol(int *engelPtr);
int kontrol2(int *engelPtr);
int kontrol3(int hp);
void dosya_kapat();


int main()
{
    dosya_olustur();                    //fonksiyonlar cagiriliyor
    random_olustur();
    engeller(parkur_uzunluk,engel_sayisi,engelPtr);
    dosya_kapat();
    return 0;
}

void dosya_olustur()
{

    dosya=fopen("log.txt","a");            //dosya olusturuluyor
    if((dosya=fopen("log.txt","a"))==NULL)
    {
        printf("Dosya acma hatasi !!");
        exit(1);
    }

}
void dosya_kapat()                      //dosya kapatiliyor
{
    fclose(dosya);
}
void random_olustur()
{

    srand(time(NULL));
    parkur_uzunluk= 50 + rand() % 50;           //parkur uzunlugu rastgele belirleniyor

    srand(time(NULL));                          //engel sayisi rastgele belirleniyor
    engel_sayisi= 2 + rand() % 3;

    fprintf(dosya,"\nXurvivor Yarismasi Basladi..\n\n");
    fprintf(dosya,"Yarismaci yasam puani HP = %d\n",hp);
    printf("Parkur uzunlugu %d metre\n",parkur_uzunluk);
    printf("Engel sayisi %d\n\n",engel_sayisi);
}
int engeller(int parkur_uzunluk , int engel_sayisi, int *engelPtr)
{
    engelPtr=engel;             //pointer kullanýlarak engellerin uzunluðu rastgele belirleniyor
    srand(time(NULL));
    *engelPtr = 1 + rand() % parkur_uzunluk ;       //ilk engel
    printf("\nEngel [1] = %d \n ",*engelPtr);
    fprintf(dosya,"Yarismaci %d. metreye kadar bir engelle karsilasmadi..\n",*engelPtr);
    fprintf(dosya,"%d. metrede bir engel var..\n",*engelPtr);
    kontrol(engelPtr);          //asallýk kontrolu yapiliyor

     for(i=1;i<engel_sayisi;i++)                //sonraki engeller for dongusunde olusturuluyor
    {
        srand(time(NULL));
        *(engelPtr+i)= *(engelPtr+i-1) + rand() % (parkur_uzunluk - *(engelPtr+i-1));
        if(*(engelPtr+i) == *(engelPtr+i-1))
        {
             *(engelPtr+i)= (*(engelPtr+i-1)+1) + rand() % ((parkur_uzunluk+1) - *(engelPtr+i-1));
        }

    }
    for(i=1;i<engel_sayisi;i++)
    {
        printf("\n\nEngel [%d] = %d \n ",i+1,*(engelPtr+i));
        fprintf(dosya,"Yarismaci %d. metreye kadar bir engelle karsilasmadi..\n",*(engelPtr+i));
        fprintf(dosya,"%d. metrede bir engel var..\n",*(engelPtr+i));
        kontrol2(engelPtr);         //asallik kontrolu yapiliyor

    }
    kontrol3(hp);                   //yasam puani kontrolu yapiliyor
}
int kontrol(int *engelPtr)
{
     if(asal(hp,*engelPtr))         //ilk engel icin asallik kontrolu
       {
           fprintf(dosya,"%d ile %d aralarinda asaldir..",hp,*engelPtr);
           hp=hp-*engelPtr;
           fprintf(dosya,"Yarismaci HP = %d\n",hp);
       }
    else
        {
            fprintf(dosya,"%d ile %d aralarinda asal degildir...",hp,*engelPtr);
            fprintf(dosya,"Yarismaci HP = %d\n",hp);
        }

}

int kontrol2(int *engelPtr)
{
    if(asal(hp,*(engelPtr+i)))          //for dongusunde olusturulan diger engeller için asallik kontrolu
        {
           fprintf(dosya,"%d ile %d aralarinda asaldir..",hp,*(engelPtr+i));
           hp=hp-*(engelPtr+i);
           fprintf(dosya,"Yarismaci HP = %d\n",hp);



        }
        else
        {
            fprintf(dosya,"%d ile %d aralarinda asal degildir...",hp,*(engelPtr+i));
            fprintf(dosya,"Yarismaci HP = %d\n",hp);
        }

}
int kontrol3(int hp)
{
      if(hp<=0)             //yasam puani kontrolu
            {
               fprintf(dosya,"\nUzgunum, yarismayi tamamlayamadin..\n");


            }
            else
            {
               fprintf(dosya,"\nTebrikler !! Yarismayi %d puan ile bitirdiniz..\n",hp);
            }

}
int obeb(int a,int b)
{
    if(b==0)
        return a;
    else
        return obeb(b,a%b);
}
int asal(int a,int b)
{
    if(obeb(a,b)==1)
        return 1;
    return 0;
}

