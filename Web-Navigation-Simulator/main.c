#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char web_site[25][25];
    int top;
}Stack;


void baslangic(Stack *yigin)
{
    yigin->top=-1;

}
int bos_kontrol(Stack *yigin)
{
    return yigin->top== -1;

}
int dolu_kontrol(Stack *yigin)
{

    return yigin->top==24;
}
void push (Stack *yigin,const char* site)
{
    if(dolu_kontrol(yigin))
    {
        printf("Daha fazla gidemezsiniz...\n");
        return;
    }
    strcpy(yigin->web_site[++(yigin->top)],site);
}

void pop(Stack *yigin,char *site)
{
    if(dolu_kontrol(yigin))
    {
        printf("Geriye gidemezsiniz...\n");
        return;
    }
    strcpy(site,yigin->web_site[(yigin->top)--]);

}
void mevcut_fonk(const char* site)
{
    printf("Su anda buradasiniz:) ->%s\n",site);
}


int main()
{
    Stack yigin_g,yigin_i;
    int secim;
    char yeni_s[25];
    char mevcut[25]="google.com";
    char temp[25];
    baslangic(&yigin_g);
    baslangic(&yigin_i);
    while(1)
    {
        printf("\n\n1-)Yeni siteye git \n");
        printf("2-)Onceki Site \n");
        printf("3-)Sonraki Site\n");
        printf("4-)Cikis\n");
        printf("Secim: ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
            printf("Gidilecek site: ");
            scanf("%s",yeni_s);
            push(&yigin_g,mevcut);
            strcpy(mevcut,yeni_s);
            baslangic(&yigin_i);
            mevcut_fonk(mevcut);
            break;

            case 2:
                if(!bos_kontrol(&yigin_g))
                {
                    push(&yigin_i,mevcut);
                    pop(&yigin_g,mevcut);
                    mevcut_fonk(mevcut);

                }
                else
                {
                    printf("Onceki site bulunmamaktadir...\n");
                }
                break;
            case 3:
                if(!bos_kontrol(&yigin_i))
                {
                    push(&yigin_g,mevcut);
                    pop(&yigin_i,mevcut);
                    mevcut_fonk(mevcut);
                }
                else
                {
                    printf("Sonraki site bulunmamaktadir...\n");
                }
                break;
            case 4:
                printf("Cikis islemi basariyla gerceklesti...\n");
                exit(0);


            default:
                printf("Tekrar dene !!!\n");


        }

    }
    return 0;


}
