#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ders{
    char ders_adi[20];
    float vize;
    float finall;
    struct Ders* sonraki;
}Ders;

typedef struct Ogrenci{
    char ad[25];
    char soyad[15];
    int num;
    Ders* dersler;
    struct Ogrenci* sonraki;
}Ogrenci;

Ogrenci* ogrenci_listesi = NULL;

//ogrenci ekleme
void ekle(Ogrenci** liste, char* ad,char* soyad,int num)
{
    Ogrenci* yeni_ogr = (Ogrenci*)malloc(sizeof(Ogrenci));
    strcpy(yeni_ogr->ad, ad);
    strcpy(yeni_ogr->soyad,soyad);
    yeni_ogr ->num = num;
    yeni_ogr -> dersler = NULL;
    yeni_ogr -> sonraki = *liste;
    *liste = yeni_ogr;

}
//secilecek dersleri listeleme
void listele_ders(){
    printf("1. Veri Yapilari\n");
    printf("2. AVP1\n");
    printf("3. AVP2\n");
    printf("4. Veri Tabani\n");
    printf("5. Web Programlama\n");
};


void ders_ekle(Ogrenci* ogrenci, char* ders_adi, float vize, float finall) {
    Ders* yeni_ders = (Ders*)malloc(sizeof(Ders));
    strcpy(yeni_ders-> ders_adi, ders_adi);
    yeni_ders->vize = vize;
    yeni_ders->finall = finall;
    yeni_ders->sonraki = NULL;

    Ders *gecici = ogrenci->dersler;

    if (gecici == NULL) {
        ogrenci->dersler = yeni_ders;
    } else {
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni_ders;
    }
}

//siralama
void sirala() {
    Ogrenci* i = ogrenci_listesi;
    Ogrenci* j = NULL;
    int temp_num;
    char temp_ad[25], temp_soyad[15];
    Ders* temp_dersler;

    for (i = ogrenci_listesi; i != NULL; i = i->sonraki) {
        for (j = i->sonraki; j != NULL; j = j->sonraki) {
            if (i->num > j->num) {

                temp_num = i->num;
                i->num = j->num;
                j->num = temp_num;

                strcpy(temp_ad, i->ad);
                strcpy(i->ad, j->ad);
                strcpy(j->ad, temp_ad);

                strcpy(temp_soyad, i->soyad);
                strcpy(i->soyad, j->soyad);
                strcpy(j->soyad, temp_soyad);

                temp_dersler = i->dersler;
                i->dersler = j->dersler;
                j->dersler = temp_dersler;
            }
        }
    }
}


//silme
void sil(char* soyad)
{
    Ogrenci* temp = ogrenci_listesi;
    Ogrenci* onceki = NULL;

    while(temp !=NULL)
    {
        if(strcmp(temp->soyad,soyad) == 0)
        {
            if(onceki==NULL)
            {
                ogrenci_listesi = temp->sonraki;
            }
            else{
                onceki->sonraki = temp->sonraki;
            }
            Ogrenci* silinecek = temp;
            temp = temp->sonraki;
            free(silinecek);
        }
        else{
          onceki = temp;
          temp = temp ->sonraki;
        }
    }

}
void listele()
{
    sirala();
    Ogrenci* temp = ogrenci_listesi;
    while(temp !=NULL)
    {
        printf("Ogrenci No: %d, Ad: %s, Soyad: %s\n", temp-> num, temp-> ad, temp->soyad);
        Ders* ders_temp = temp -> dersler;
        while(ders_temp != NULL)
        {
            printf("\tDers: %s, Vize: %.2f, Final: %.2f\n", ders_temp->ders_adi,ders_temp->vize, ders_temp-> finall);
            ders_temp = ders_temp-> sonraki;
        }
        temp = temp -> sonraki;
    }

}

void ders_listele(char* ders_adi)
{
    Ogrenci* temp = ogrenci_listesi;
    while(temp !=NULL)
    {
        Ders* ders_temp = temp ->dersler;
        while(ders_temp !=NULL)
        {
            if(strcmp(ders_temp -> ders_adi,ders_adi) ==0)
            {
                printf("Ogrenci No: %d, Ad: %s, Soyad: %s\n", temp-> num, temp->ad, temp->soyad);
                break;
            }
            ders_temp = ders_temp->sonraki;
        }
        temp = temp->sonraki;
    }
}

void ogrenci_arama(char* ad)
{
    Ogrenci* temp_ogr= ogrenci_listesi;

    while(temp_ogr !=NULL)
    {

        if(strcmp(temp_ogr -> ad,ad)==0)
        {
            printf("Ogrenci No: %d, Ad: %s, Soyad: %s\n", temp_ogr-> num, temp_ogr->ad, temp_ogr->soyad);

            Ders* ders_temp = temp_ogr-> dersler;
            while(ders_temp !=NULL)
            {
                printf("\tDers: %s,Vize: %.2f, Final: %.2f\n",ders_temp->ders_adi, ders_temp->vize, ders_temp->finall);
                ders_temp = ders_temp->sonraki;
            }
        }
        temp_ogr = temp_ogr ->sonraki;
    }

}

void dosyadan_yukle(const char* dosya_adi, Ogrenci** liste) {
    FILE* dosya = fopen(dosya_adi, "r");
    char satir[256];
    Ogrenci* ogrenci = NULL;

    while (fgets(satir, sizeof(satir), dosya)) {
        if (strncmp(satir, "Ogrenci No", 10) == 0) {
            char ad[25], soyad[15];
            int num;
            sscanf(satir, "Ogrenci No: %d, Ad: %[^,], Soyad: %s", &num, ad, soyad);
            ekle(liste, ad, soyad, num);
            ogrenci = *liste;
        } else if (strncmp(satir, "Ders:", 5) == 0 && ogrenci != NULL) {
            char ders_adi[15];
            float vize, finall;
            sscanf(satir, "Ders: %[^,], Vize: %f, Final: %f", ders_adi, &vize, &finall);
            ders_ekle(ogrenci, ders_adi, vize, finall);
        }
    }

    fclose(dosya);
}


//menu
void menu()
{
    int secim,num;
    char ad[25], soyad[15],ders_adi[20];
    float vize,finall;
    dosyadan_yukle("metin.txt",&ogrenci_listesi);

    while(1)
    {
        printf("\n******MENU******\n");
        printf("1.Ogrenci Ekle\n");
        printf("2.Ogrenci Sil\n");
        printf("3.Listele\n");
        printf("4.Dersi Alan Ogrenciler\n");
        printf("5.Belirli Ogrenci Bilgileri Listeleme\n");
        printf("6.Cikis\n");
        printf("Seciminiz: ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:

                printf("Ogrenci Adi: ");
                scanf("%s",ad);
                printf("Ogrenci Soyadi: ");
                scanf("%s",soyad);
                printf("Ogrenci Numarasi: ");
                scanf("%d",&num);
                ekle(&ogrenci_listesi,ad,soyad,num);

                int ders_sayisi;
                printf("Kac ders eklemek istiyorsunuz: ");
                scanf("%d",&ders_sayisi);
                for(int i=0;i<ders_sayisi;i++)
                {
                    printf("Ders Adi: ");
                    scanf("%s", ders_adi);
                    printf("Vize Notu: ");
                    scanf("%f", &vize);
                    printf("Final Notu: ");
                    scanf("%f",&finall);
                    ders_ekle(ogrenci_listesi, ders_adi,vize,finall);
                }
                printf("Ogrenci ve ders bilgileri basariyla eklendi..\n");
                break;

            case 2:
                printf("Silinecek ogrencinin soyadi: ");
                scanf("%s",soyad);
                sil(soyad);
                printf("Ogrenci basariyla silindi...\n");
                break;

            case 3:
                listele();
                break;

            case 4:
                printf("Ders adi: ");
                scanf("%s",ders_adi);
                ders_listele(ders_adi);
                break;

            case 5:
                printf("Aranacak ogrenci adi: ");
                scanf("%s",ad);
                ogrenci_arama(ad);
                break;

            case 6:
                exit(0);

            default:
                 printf("Gecersiz secim:/ Tekrar dene..");
        }
    }
}

int main()
{
    menu();
    return 0;
}
