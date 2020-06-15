#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
int satir,sutun,max=40000;
int **matris,**trans,*dizi,**matris2;
FILE *dosya;
void matris_olustur();
void matris_sirala();
void transpoze(int **trans);
void dosyaya_yazdir();
bool kaprekar_bulma(int **sayi);
int main()
{
    matris_olustur();
    matris_sirala();
    transpoze(trans);
    dosyaya_yazdir();
    kaprekar_bulma(matris2);
    printf("\n***** KAPREKAR KONTROLU *****\n");
    for (int i=0;i<satir; i++)
      {
          for(int j=0;j<sutun;j++)
            {
                if (kaprekar_bulma(matris2))
                {
                    printf("%d ",matris2[i][j]);
                }
                else
                    printf("%d\tSayisi Kaprekar Sayi Degildir..\n",matris2[i][j]);
            }
      }


    return 0;
}
void matris_olustur()
{
    int i,j;
    printf("Matrisin satir sayisini giriniz : "); //Disardan girisle matrisin satir ve sutun araligini belirliyoruz.
    scanf("%d",&satir);
    matris =(int **)malloc(satir*sizeof(int*));
    printf("Matrisin sutun sayisini giriniz : ");
    scanf("%d",&sutun);
    for(i=0;i<satir;i++)
    {
        matris[i]=(int*)malloc(sutun*sizeof(int));   //Dinamik bellek ile matrise yer aciyoruz.
    }
    srand(time(NULL));
    printf("\n***** OLUSTURULAN MATRIS *****\n");
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            matris[i][j]=5+rand()%(max-5);
            printf("%d\t",matris[i][j]);
        }
        printf("\n");
    }
        for(int i=0;i<sutun;i++)   //Matris icin actigimiz bellegi geri iade ediyoruz.
            free(matris[i]);
        free(matris);
}
void matris_sirala()
{
    int i,j;
    matris2 =(int **)malloc(satir*sizeof(int*));     // Mtrisi siraladigimizda ikinci bir matrise atayacagiz.
    for(i=0;i<satir;i++)
    {
        matris2[i]=(int*)malloc(sutun*sizeof(int));
    }

    int dizi[satir*sutun],k=0;    // Matrisi bubblesort ile siralamak icin tek boyutlu diziye aktariyoruz.
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            dizi[k++]=matris[i][j];
        }
    }
    //for(i=0;i<satir*sutun;i++) tek boyutlu diziye cevirilmis hali
        //printf("%d\t",dizi[i]);
    int swap;
    for (i=0;i<satir*sutun-1;i++)
    {
        for (j=0;j<satir*sutun-i-1;j++)
        {
            if (dizi[j]>dizi[j+1])
            {
                swap=dizi[j];
                dizi[j]=dizi[j+1];
                dizi[j+1]=swap;
            }
        }
    }
    //for (i=0; i<satir*sutun;i++) tek boyutlu dizinin siralanmis hali
       // printf("%d\n",dizi[i]);


    if(satir*sutun%satir==0 && satir*sutun%sutun==0)  // Tek boyutlu diziyi matris2 ye aktariyoruz.
    {
            int x=0,i,j;
            for(i=0; i<satir; i++)
            {
                for (j=0; j<sutun; j++)
                {
                matris2[i][j]=dizi[x];
                x++;
                }
            }
    }
    printf("\n***** SIRALANAN MATRIS *****\n");  //Bubblesort ile siralanan matrisi yazdiriyoruz.
    for(int i=0;i<satir;i++)
    {
        for(int j=0;j<sutun;j++)
            printf("%d\t",matris2[i][j]);
        printf("\n");
    }
}
void transpoze(int **trans2)
{
    int i,j;
    trans=(int**)malloc(sutun*sizeof(int*));  // Matrisin transpozesini almak icin trans dizisini yine dinamik bellekle olusturuyoruz.
    for(i=0;i<sutun;i++)
    {
        trans[i]=(int *)malloc(satir*sizeof(int));
    }

    for(i=0;i<satir;i++)  // Gerekli atamalari yapiyoruz.
    {
        for(j=0;j<sutun;j++)
        {
            trans[j][i]=matris2[i][j];
        }
    }
     printf("\n***** TRANSPOZE *****\n");  // Transpozeyi yazdiriyoruz.
    for(i=0;i<sutun;i++)
    {
        for(j=0;j<satir;j++)
        {
            printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<sutun;i++)  // Bellekte actigimiz yeri geri iade ediyoruz.
            free(trans[i]);
        free(trans);
}
void dosyaya_yazdir()
{
    int i,j;
    dosya = fopen("transpoze.txt","a");  // Text dosyasi olusturuyoruz. Her calistirildiginda üzerine yazmasi icin "a" acilis modunu kullaniyoruz.
    if((dosya= fopen("transpoze.txt","a"))== NULL)
    {
        printf("Dosya acilamadi !!\n");
        exit(1);
    }
    else
        printf("\nYAZDIRMA ISLEMI TAMAM ! :D \n");   // Text dosyasina yazdirildiðinda buna dair uyari gonderiyoruz.
    fprintf(dosya,"\n***** OLUSTURULAN MATRIS *****\n"); // Olusturulan matris text dosyasina yaziliyor.
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            fprintf(dosya,"%d\t",matris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    fprintf(dosya,"\n***** SIRALANAN MATRIS *****\n"); // Siralanan matris text dosyasina yazdiriliyor.
    for(int i=0;i<satir;i++)
    {
        for(int j=0;j<sutun;j++)
            fprintf(dosya,"%d\t",matris2[i][j]);
        fprintf(dosya,"\n");
    }
    fprintf(dosya,"\n***** TRANSPOZE *****\n"); // Transpozesi alinan siralanmis matris text dosyasina yazdiriliyor.
    for(i=0;i<sutun;i++)
    {
        for(j=0;j<satir;j++)
        {
            fprintf(dosya,"%d\t",trans[i][j]);
        }
        fprintf(dosya,"\n");
    }

    fprintf(dosya,"\n***** KAPREKAR KONTROLU *****\n"); // Kaprekar sayi kontrolleri yazdiriliyor.

     for (i=0;i<satir; i++)
      {
          for(j=0;j<sutun;j++)
            {
                if (kaprekar_bulma(matris2))
                {
                    fprintf(dosya,"%d sayisi Kaprekardir..",matris2[i][j]);
                }
                else
                    fprintf(dosya,"%d Sayisi Kaprekar Sayi Degildir..\n",matris2[i][j]);
            }
      }

fclose(dosya); // Acilan dosyayi kapatiyoruz.
}
bool kaprekar_bulma(int **sayi)
{
    if (**sayi == 1) // Sayi bire esitse sonlandiriyoruz.
       return true;


    int sayi_karesi = (**sayi) * (**sayi);
    int basamak = 0;
    while (sayi_karesi)  //Sayinin karesini kontrol ediyoruz.Evet ise basamak deðiskenini arttiriyoruz ve sayinin karesini surekli 10 a boluyoruz.
    {
        basamak++;
        sayi_karesi /= 10;
    }

    sayi_karesi= (**sayi) * (**sayi);

    for (int basamak2 =1; basamak2 <basamak; basamak2 ++) // Hayirsa basamak2 yi 1 e esitliyoruz ve basamaða kadar arttiriyoruz.
    {
         int parca = pow(10, basamak2); // Ustel deger alma islemi yapiliyor.

         if (parca == (**sayi)) // Parcanin sayiya esitligi kontrol ediliyor. Esitse islem tekrar basa donup devam ediyor.
            continue;

         int top = sayi_karesi/parca + sayi_karesi % parca;  // Degilse bu islem uygulanarak sonuca gidiliyor.
         if (top == (**sayi))
           return true;
    }
    return false;



}

