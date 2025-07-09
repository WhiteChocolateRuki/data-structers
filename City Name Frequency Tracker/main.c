//21100011057
//Rukiye UÇAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct BListe
{
    char kelime[15];
    int sayac;
    int frekans;
    struct BListe* sonraki;
    struct BListe* onceki;

}BListe;

BListe* kelime_ekle(BListe* head,char* kelime)
{
    if(head==NULL)
    {
        head = (BListe*)malloc (sizeof(BListe));
        strcpy(head->kelime, kelime);
        head->sayac=1;
        head ->sonraki = head;
        head ->onceki = head;
        return head;
    }

    BListe* simdiki = head;
    BListe* onceki= NULL;

    do
    {
        if(strcmp(simdiki->kelime,kelime)==0)
        {
            simdiki-> sayac++;
            return head;
        }

        onceki=simdiki;
        simdiki =simdiki->sonraki;

    } while(simdiki !=head);

    BListe* yeni_BListe = (BListe*) malloc(sizeof(BListe));
    strcpy(yeni_BListe -> kelime,kelime);
    yeni_BListe->sayac =1;

    yeni_BListe -> sonraki = head;
    yeni_BListe ->onceki =onceki;
    onceki ->sonraki =yeni_BListe;
    head->onceki = yeni_BListe;
    return head;
}
void listeyi_yaz(BListe* head)
{
    if (head==NULL) return;

    BListe* simdiki = head;
    do
    {
        printf("%s: %d\n",simdiki->kelime,simdiki->sayac);
        simdiki = simdiki ->sonraki;
    } while(simdiki!= head);

}

void dosyadan_oku(BListe** head,const char* filename)
{
    FILE *file =fopen(filename,"r");
    char kelime[15];
    while(fscanf(file,"%s", kelime)!= EOF)
    {
        *head = kelime_ekle(*head, kelime);

    }
    fclose(file);
}

BListe* alfabetik_sirala(BListe* head)
{
    if (head==NULL || head -> sonraki ==NULL) return head;

    BListe* sirali = NULL;
    BListe* simdiki = head;

    do{
        BListe* sonraki_BListe= simdiki->sonraki;
        if(sirali==NULL)
        {
            sirali=simdiki;
            sirali-> sonraki = sirali;
            sirali->onceki = sirali;
        }
        else
        {
            BListe* sirali_simdiki = sirali;
            BListe* sirali_onceki = NULL;

            do
            {
                if(strcmp(simdiki->kelime,sirali_simdiki->kelime)<0)
                {
                    break;
                }
                sirali_onceki =sirali_simdiki;
                sirali_simdiki= sirali_simdiki->sonraki;

            }while (sirali_simdiki!=sirali);

            if(sirali_onceki ==NULL)
            {
                BListe* son =sirali;
                while(son->sonraki!=sirali)
                {
                    son = son->sonraki;
                }
                simdiki->sonraki =sirali;
                simdiki->onceki = son;
                son->sonraki = simdiki;
                sirali->onceki= simdiki;
                sirali=simdiki;
            }
            else
            {
                simdiki->sonraki =sirali_onceki ->sonraki;
                simdiki->onceki = sirali_onceki;
                sirali_onceki->sonraki->onceki =simdiki;
                sirali_onceki->sonraki=simdiki;

            }

        }
        simdiki =sonraki_BListe;
    }while(simdiki!=head);
    return sirali;


}

BListe* frekans_siralama(BListe* head)
{
    if (head==NULL || head->sonraki ==head)
    {
        return head;
    }
    BListe* kuyruk = head;
    while(kuyruk->sonraki!=head)
    {
        kuyruk =kuyruk->sonraki;
    }

    kuyruk->sonraki =NULL;
    BListe* sirali= NULL;
    BListe* simdiki = head;

    while(simdiki != NULL)
    {
        BListe* sonraki_BListe = simdiki->sonraki;
        if(sirali==NULL || simdiki->sayac > sirali-> sayac)
        {
            simdiki ->sonraki =sirali;
            sirali =simdiki;
        }
        else
        {
            BListe* temp =sirali;
            while(temp->sonraki !=NULL && temp->sonraki->sayac >=simdiki->sayac)
            {
                temp = temp->sonraki;
            }

            simdiki->sonraki=temp->sonraki;
            temp->sonraki = simdiki;
        }
        simdiki=sonraki_BListe;

    }
    BListe* sirali_kuyruk = sirali;
    while(sirali_kuyruk->sonraki !=NULL)
    {
        sirali_kuyruk=sirali_kuyruk->sonraki;
    }
    sirali_kuyruk->sonraki =sirali;
    sirali->onceki = sirali_kuyruk;

    return sirali;
}

BListe* kelime_sil(BListe* head, const char* kelime)
{
    BListe* simdiki = head;
    BListe* kuyruk = head->onceki;

    do
    {
        if (strcmp(simdiki->kelime,kelime)==0)
        {

            if(simdiki==head)
            {
                if(head->sonraki==head)
                {
                    free(simdiki);
                    return NULL;
                }
                else
                {
                   head = head->sonraki;
                   kuyruk->sonraki =head;
                   head->onceki = kuyruk;
                   free(simdiki);
                   return head;
                }
            }
            else
            {
                simdiki->onceki->sonraki = simdiki->sonraki;
                simdiki->sonraki->onceki = simdiki->onceki;
                free(simdiki);
                return head;
            }

        }
        simdiki=simdiki->sonraki;
    }while(simdiki !=head);

    printf("kelime listede yok!!!");
    return head;


}
BListe* harfle_silme(BListe* head,char harf)
{
    if(head==NULL)
    {
        return NULL;
    }

    BListe* simdiki = head;
    BListe * temp;
    harf = tolower(harf);

    int kontrol(char*  kelime, char harf)
    {
        for(int i=0; i<strlen(kelime);i++)
        {
            if(tolower(kelime[i]) == harf)
            {
                return 1;
            }
        }
        return 0;
    }

    while(kontrol(head->kelime,harf))
    {
        if(head->sonraki==head)
        {
            free(head);
            return NULL;
        }

        BListe* kuyruk = head->onceki;
        temp =head;
        head=head->sonraki;
        kuyruk->sonraki=head;
        head->onceki =kuyruk;
        free(temp);
    }

    simdiki=head->sonraki;
    while(simdiki!=head)
    {
        if(kontrol(simdiki->kelime,harf))
        {
            simdiki->onceki->sonraki =simdiki->sonraki;
            simdiki->sonraki->onceki =simdiki->onceki;
            temp=simdiki;
            simdiki=simdiki->sonraki;
            free(temp);
        }
        else
        {
            simdiki=simdiki->sonraki;
        }
    }
    return head;
}

void freeList(BListe* head)
{
    if (head==NULL) return;

    BListe* simdiki = head->sonraki;
    while(simdiki!= head)
    {
        BListe* temp = simdiki;
        simdiki = simdiki->sonraki;
        free(temp);
    }
    free(head);
}
int main()
{
    int secim;
    char kelime[25];
    char harf[15];
    BListe* head =NULL;
    dosyadan_oku(&head, "sehirler.txt");

    while(1)
    {
        printf("\n\n");
        printf("1) Illerin Frekanslari Listele\n");
        printf("2) Alfabetik Sirala\n");
        printf("3) Frekans Buyuklugune Gore Siralama\n");
        printf("4) Kelime Sil\n");
        printf("5) Harf/Kelime Gecen Sehir Sil}\n");
        printf("6) Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                listeyi_yaz(head);
                printf("\nListeleme Islemi Tamamlandi...\n");
                break;

            case 2:
                listeyi_yaz(alfabetik_sirala(head));
                printf("\nListeleme Islemi Tamamlandi...\n");
                break;

            case 3:
                listeyi_yaz(frekans_siralama(head));
                printf("\nListeleme Islemi Tamamlandi...\n");
                break;

            case 4:
                printf("Silmek Istediginiz Kelimeyi Girin: \n");
                scanf("%s",kelime);
                head =kelime_sil(head,kelime);
                printf("\n%s basariyla silindi...",kelime);
                break;

            case 5:
                printf("Hangi Harfleri Silmek Istersiniz: \n");
                scanf(" %s",&harf);
                head = harfle_silme(head,harf);
                printf("\nIcinde %s gecen kelimeler basariyla silindi..\n",harf);
                break;


            case 6:
                printf("\nCikis Yapiliyor...\n");
                exit(0);

            default:
                printf("Yanlis Secim:/ Yeniden Dene...\n");
                break;

        }


    }
    freeList(head);
    return 0;
}
