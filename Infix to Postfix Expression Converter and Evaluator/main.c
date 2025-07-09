#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct postFix{
    int eleman[25];
    int ust_index;

}postFix;

typedef struct Node{
    char data;
    struct Node* sonraki;
}Node;

void yigin_islem(postFix* stackk)
{
    stackk->ust_index = -1;

}

int kontrol(postFix* stackk)
{
    return stackk->ust_index ==-1;

}

int dolu_kontrol(postFix* stackk)
{
    return stackk->ust_index ==24;  //max
}

void ekle(postFix* stackk, int elem)
{


    if(!dolu_kontrol(stackk))
    {
        stackk->eleman[++stackk->ust_index] = elem;
    }
}

int cikar(postFix* stackk)
{
    if(!kontrol(stackk))
    {
       return stackk->eleman[stackk->ust_index--];
    }
    return 0;
}

int ustteki_eleman(postFix* stackk)
{
    if(!kontrol(stackk))
    {
        return stackk->eleman[stackk->ust_index];
    }
    return 0;

}

Node* node_olustur(char data) {
    Node* yeni_node =(Node*)malloc(sizeof(Node));
    yeni_node->data =data;
    yeni_node->sonraki =NULL;
    return yeni_node;
}

void listeye_ekle(Node** head,char data) {
    Node* yeni_node =node_olustur(data);
    if (*head ==NULL) {
        *head =yeni_node;
    } else {
        Node* temp =*head;
        while (temp->sonraki!=NULL) {
            temp =temp->sonraki;
        }
        temp->sonraki =yeni_node;
    }
}

////////////////////////
int oncelik_kontrol(char operatorr)
{
    switch(operatorr)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;

    }
}

void enter()
{
    printf("Enter'a Tikla\n");
    getchar();
}

void donusum(char * infix, Node** postfix)
{
    postFix stackk;
    yigin_islem(&stackk);
    char* karakter=infix;
    printf("\nAdimlar: \n");
    while(*karakter!='0')
    {
        if(isdigit(*karakter))
        {
            listeye_ekle(postfix,*karakter);
            printf("Karakter: %c, sayi olarak ekleniyor...\n ",*karakter);
            enter();

        }
        else if(*karakter =='(')
        {
            ekle(&stackk,*karakter);
            printf("Karakter: %c yiginda...\n",*karakter);
            enter();
        }
        else if(*karakter==')')
        {
            while(!kontrol(&stackk)&&ustteki_eleman(&stackk)!='(')
            {
                char operatorr=cikar(&stackk);
                listeye_ekle(postfix,operatorr);
                printf("karakter: %c yigindan alinip postfixe ekleniyor...\n",operatorr);
                enter();
            }
            cikar(&stackk);
            printf("'(' yigindan cikariliyor...\n");
            enter();

        }
        else
        {
            while(!kontrol(&stackk)&&oncelik_kontrol(ustteki_eleman(&stackk))>=oncelik_kontrol(*karakter))
            {
                char operatorr= cikar(&stackk);
                listeye_ekle(postfix,operatorr );
                printf("%c yigindan alinip postfixe ekleniyor...\n",operatorr);
                enter();
            }
            ekle(&stackk, *karakter);
            printf("Karakter '%c'yiginda...\n", *karakter);
            enter();

        }
        karakter++;
    }
    while(!kontrol(&stackk))
        {
            char operatorr=cikar(&stackk);
            listeye_ekle(postfix,operatorr);
            printf("%c yigindan alinip postfixe ekleniyor...\n",operatorr);
            enter();

        }
}
int sonuc(Node*postfix) {
    postFix stackk;
    yigin_islem(&stackk);
    Node* temp =postfix;
    printf("\npostfixin degerlendirilme adimlari:\n");
    while (temp !=NULL)
        {
        if (isdigit(temp->data))
        {
            ekle(&stackk,temp->data -'0');
            printf("Karakter '%c': yigina gidiyor...\n",temp->data);
            enter();
        } else {
            int deger2 =cikar(&stackk);
            int deger1 =cikar(&stackk);
            int result;
            switch (temp->data) {
                case '+':
                    result=deger1 + deger2;
                    break;
                case '-':
                    result=deger1 - deger2;
                    break;
                case '*':
                    result=deger1 * deger2;
                    break;
                case '/':
                    result=deger1 / deger2;
                    break;
            }
            ekle(&stackk,result);
            printf("operator '%c': %d ve %d isleme konuyor... \n", temp->data, deger1, deger2);
            enter();
        }
        temp =temp->sonraki;
    }
    return cikar(&stackk);
}

int main()
{
    char infix[100];
    FILE* file=fopen("metin.txt","r");
    fgets(infix,100,file);
    infix[strcspn(infix,"\n")]='\0';
    fclose(file);
    printf("Infix ifade: %s\n",infix);
    Node* postfix =NULL;
    donusum(infix,&postfix);
    printf("postfix degerlendiriliyor...\n");
    int result=sonuc(postfix);
    printf("\nSonuc: %d\n",result);
    return 0;
}














