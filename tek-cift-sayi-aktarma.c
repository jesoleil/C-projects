#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dizi[10],i;
    int *diziPtr;
    diziPtr=dizi;

    srand(time(NULL));
    printf("\n\n\t******* DIZIMIZE 1-100 ARASI ATANAN DEGERLER *******\n\n");

    for(i=0;i<10;i++)
    {
        *(diziPtr+i)=1+rand()%100;
        printf("%d.sayi  - dizi[%d] :  %d\n",(i+1),i,*(diziPtr+i));
    }

    int diziCift[10], diziTek[10],x=0,y=0;
    int *ciftPtr, *tekPtr;
    ciftPtr=diziCift;
    tekPtr=diziTek;
    printf("\n\n\t*** DIZIDEKI CIFT SAYI DIZISI VE TEK SAYI DIZISI ***\n\n");

    for(i=0;i<10;i++)
    {
        if(*(diziPtr+i)%2==0)
        {
            *(ciftPtr+x)=*(diziPtr+i);
            x++;
        }

        else
        {
            *(tekPtr+y)=*(diziPtr+i);
            y++;
        }

    }
    printf("<<<Cift Sayilar>>>\t\t\t<<<Tek Sayilar>>>\n");
    for(i=0;i<10;i++)
    {
        printf("\n%d\t\t\t\t\t%d",*(ciftPtr+i),*(tekPtr+i));
    }


    return 0;
}
