#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dizi[10],i;  //10 elemanlý integer bir dizi tanýmlýyoruz.Daha sonra bu diziye pointer kullanarak eriþeceðiz.
    int *diziPtr;
    diziPtr=dizi;

    srand(time(NULL));  //Dizi için üretilen deðerlerin sürekli olarak deðiþmesini saðlayan komuttur.
    printf("\n\n\t******* DIZIMIZE 1-100 ARASI RASTGELE ATANAN DEGERLER *******\n\n");

    for(i=0;i<10;i++)
    {
        *(diziPtr+i)=1+rand()%100; //Yukarýda tanýmladýðýmýz time.h kütüphanesine göre 10 tane rastgele sayý oluþturuyoruz.
        printf("%d.sayi\t-  dizi[%d] :  %d\n",(i+1),i,*(diziPtr+i)); //diziPtr dizinin ilk elemanýný temsil edeceðinden diðer elemanlara ulaþmak için diziPtr ye i ekliyoruz.
    }

    int diziCift[10], diziTek[10],j=0;  //Çift sayýlarý ve Tek sayýlarý atayacaðýmýz dizileri 10 elemanlý olacak þekilde pointer kullanarak tanýmlýyoruz.
    int *ciftPtr, *tekPtr;
    ciftPtr=diziCift;
    tekPtr=diziTek;
    printf("\n\n\t******** DIZIDEKI CIFT SAYI DIZISI VE TEK SAYI DIZISI ********\n\n");

    for(i=0;i<10;i++)
    {
        if(*(diziPtr+i)%2==0)   //Burada mod alma iþlemi yapýlarak sayýnýn çift mi tek mi olduðuna karar veriliyor.
        {
            *(ciftPtr+j)=*(diziPtr+i);
            printf("-> %d\tSayisi Cift Sayidir..\n",*(ciftPtr+i)); //diziPtr için i deðiþkenini kullanýrken ciftPtr ve tekPtr için j deðiþkeni kullanýyoruz ve j yi sýfýrdan baþlatarak i arttýkça onun da artmasýný saðlýyoruz.
            j++;
        }

        else
        {
            *(tekPtr+j)=*(diziPtr+i);
            printf("-> %d\tSayisi Tek  Sayidir..\n",*(tekPtr+i)); //Böylece i ye karþýlýk gelen indiste tutulan deðerler j indisine aktarýlarak tek ve çift dizilerin elemanlarýný meydana getirmiþ oluyor.
            j++;
        }
    }

}
