#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dizi[10],i;  //10 elemanl� integer bir dizi tan�ml�yoruz.Daha sonra bu diziye pointer kullanarak eri�ece�iz.
    int *diziPtr;
    diziPtr=dizi;

    srand(time(NULL));  //Dizi i�in �retilen de�erlerin s�rekli olarak de�i�mesini sa�layan komuttur.
    printf("\n\n\t******* DIZIMIZE 1-100 ARASI RASTGELE ATANAN DEGERLER *******\n\n");

    for(i=0;i<10;i++)
    {
        *(diziPtr+i)=1+rand()%100; //Yukar�da tan�mlad���m�z time.h k�t�phanesine g�re 10 tane rastgele say� olu�turuyoruz.
        printf("%d.sayi\t-  dizi[%d] :  %d\n",(i+1),i,*(diziPtr+i)); //diziPtr dizinin ilk eleman�n� temsil edece�inden di�er elemanlara ula�mak i�in diziPtr ye i ekliyoruz.
    }

    int diziCift[10], diziTek[10],j=0;  //�ift say�lar� ve Tek say�lar� atayaca��m�z dizileri 10 elemanl� olacak �ekilde pointer kullanarak tan�ml�yoruz.
    int *ciftPtr, *tekPtr;
    ciftPtr=diziCift;
    tekPtr=diziTek;
    printf("\n\n\t******** DIZIDEKI CIFT SAYI DIZISI VE TEK SAYI DIZISI ********\n\n");

    for(i=0;i<10;i++)
    {
        if(*(diziPtr+i)%2==0)   //Burada mod alma i�lemi yap�larak say�n�n �ift mi tek mi oldu�una karar veriliyor.
        {
            *(ciftPtr+j)=*(diziPtr+i);
            printf("-> %d\tSayisi Cift Sayidir..\n",*(ciftPtr+i)); //diziPtr i�in i de�i�kenini kullan�rken ciftPtr ve tekPtr i�in j de�i�keni kullan�yoruz ve j yi s�f�rdan ba�latarak i artt�k�a onun da artmas�n� sa�l�yoruz.
            j++;
        }

        else
        {
            *(tekPtr+j)=*(diziPtr+i);
            printf("-> %d\tSayisi Tek  Sayidir..\n",*(tekPtr+i)); //B�ylece i ye kar��l�k gelen indiste tutulan de�erler j indisine aktar�larak tek ve �ift dizilerin elemanlar�n� meydana getirmi� oluyor.
            j++;
        }
    }

}
