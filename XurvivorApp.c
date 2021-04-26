#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int HP=100;
int engel , parkuruzunlugu , tut,gecici;
int engelyerleri[];
FILE *fp;

int main ()
{
    fp =fopen("log.txt","w");
    srand(time(NULL));
    yarismaBaslangici();
    parkur();
    engelBelirleme();
    engelYerler();
    asalKontrol();
    yarismaBitis();
    fclose(fp);
}
int yarismaBaslangici()
{
    fprintf(fp,"Yarisma Basladi !!!\nYarismaci HP=%d\n",HP);
}
int parkur()
{
    parkuruzunlugu=50+rand()%51;
}
int engelBelirleme()
{
    engel=2+rand()%4;
}
int engelYerler()
{
    for (int i=0;i<engel;i++)
    {
        engelyerleri[i]=5+rand()%parkuruzunlugu;
        for (int x=0;x<i;x++)
            if(engelyerleri[i]==engelyerleri[x])
                i--;
    }
    for(gecici=1;gecici<engel;gecici++)
    {
        for (int i=0;i<engel-1;i++)
        {
            if (engelyerleri[i]>engelyerleri[i+1])
           {
               tut=engelyerleri[i];
               engelyerleri[i]=engelyerleri[i+1];
               engelyerleri[i+1]=tut;
           }
        }
    }

}
int asalKontrol()
{
    for(int i=0;i<engel;i++)
    {
        tut=1;
        for(int x=2;x<=engelyerleri[i];x++)
        {
            if(engelyerleri[i]%x==0 && HP%x==0)
            {
               tut=0;
            }
        }
        if(tut==1)
            {
                fprintf(fp,"Yarismaci %d. metreye kadar bir engelle karsilasmadi. %d. metrede bir engel var. %d ve %d aralarinda asaldir.\n",engelyerleri[i],engelyerleri[i],HP,engelyerleri[i]);
                HP=HP-engelyerleri[i];
                fprintf(fp,"Yarismaci HP = %d\n",HP);
            }
            else
            {
                fprintf(fp,"Yarismaci %d. metreye kadar bir engelle karsilasmadi. %d. metrede bir engel var. %d ve %d aralarinda asal degildir.\nYarismaci HP = %d\n",engelyerleri[i],engelyerleri[i],HP,engelyerleri[i],HP);
            }
    }
}

int yarismaBitis()
{
    if (HP>0)
        fprintf(fp,"Tebrikler !!! Yarismayi %d HP ile bitirdiniz.",HP);
    else
        fprintf(fp,"Uzgunum !!! Yarismayi tamamlayamadiniz");
}
