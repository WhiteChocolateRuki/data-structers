//21100011057
//Rukiye Uçar

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;



Node* dugum_ekle(int data) {

    Node* yeni_dugum= (Node*)malloc(sizeof(Node));
    yeni_dugum->data= data;
    yeni_dugum->left= NULL;
    yeni_dugum->right= NULL;
    yeni_dugum->parent=NULL;
    return yeni_dugum;
}


Node* ekle(Node* root,int data) {
    if (root ==NULL) {
        return dugum_ekle(data);
    }

    if (data <root->data) 
    {
        Node*sola=ekle(root->left,data);
        root->left =sola;
       sola->parent= root;
    } 

    else if (data> root->data) 
    {
        Node* saga= ekle(root->right,data);

        root->right= saga;
        saga->parent=root;
    }

    return root;


}


Node* kucuk(Node* root) {

    while (root->left != NULL) {

        root= root->left;
    }

    return root;
}


Node* sil(Node* root,int data) {

    if (root== NULL) 
    {
        return NULL;
    }
    if (data <root->data) {
        root->left= sil(root->left,data);
    } 
    else if (data> root->data) {
        root->right= sil(root->right,data);
    } 
    
    else {
        
        if (root->left ==NULL) 
        {
            Node* tut= root->right;
            free(root);
            return tut;
        } 
        
        else if (root->right ==NULL) 
        {
            Node* tut= root->left;
            free(root);
            return tut;
        }
        
        Node* tut=kucuk(root->right);
        root->data= tut->data;

        root->right= sil(root->right,tut->data);
    }
    return root;
}
void dolas(Node* root) 
{

    if (root != NULL) 
    {
        dolas(root->left);
        printf("%d ",root->data);
        dolas(root->right);
    }

}


Node* dosya(const char* dosya_ad) 
{
    FILE* file=fopen(dosya_ad,"r");
    if (file== NULL) 
    {
        printf("HATA\n");
        return NULL;
    }


    Node* root= NULL;
    int data;


    while (fscanf(file,"%d",&data)!=EOF) {
        root= ekle(root,data);

    }

    fclose(file);
    return root;


}


int yolB(Node* root,int data,int* yol,int* yol_index) {
    if (root== NULL) {
        return 0;
    }
 
    yol[(*yol_index)++]= root->data;

    if (root->data== data) {
        return 1; 

    } 
    else if (data <root->data) 
    {
        return yolB(root->left,data,yol,yol_index);
    } 
    else {

        return yolB(root->right,data,yol,yol_index);
    }
}


void menu() {
    printf("1)Agaci sirali olarak goruntule\n");
    printf("2)Sayi ekle\n");
    printf("3)Sayi sil\n");
    printf("4)Degeri ara ve yolu goster\n");
    printf("5)Cikis\n");
    printf("Seciminiz: ");
}

int main() {

    Node* root= dosya("sayi.txt"); 
    if (root== NULL) {
        printf("BASLAGIC ICIN DEGER YOK\n");
        return 1;
    }

    int secim,deger;

    do {
        menu();
        scanf("%d",&secim);

        switch (secim) {
            case 1:
                printf("Sirali Agac : ");
                dolas(root);
                printf("\n");

                break;

            case 2:
                printf("Eklenecek deger: ");
                scanf("%d",&deger);
                root= ekle(root,deger);
                printf("%d eklenmistir...\n",deger);
                break;

            case 3:
                printf("Silinecek degeri: ");
                scanf("%d",&deger);
                root= sil(root,deger);
                printf("%d silinmistir\n",deger);
                break;

            case 4:
                printf("Aranacak deger: ");
                scanf("%d",&deger);

                int yol[100],yol_index= 0; 

                if (yolB(root,deger,yol,&yol_index)) 
                {
                    printf("%d bulundu... izlenen yol: ",deger);

                    for (int i= 0; i <yol_index; i++) {
                        printf("%d ",yol[i]);
                    }
                    printf("\n");
                } 
                else
                 {
                    printf("%d bulunamadi.\n",deger);
                }

                break;

            case 5:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Tekrar dene...\n");

        }
    } while (secim != 5);


    return 0;
    
}
