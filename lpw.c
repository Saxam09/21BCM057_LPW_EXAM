#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    struct node *next;
};
struct node * Newnode(int data){
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->coeff=data;
    newnode->next=NULL;
    return newnode;
}
struct node * insert(struct node * root,int data){
    if(root==NULL){
        return Newnode(data);
    }
    else{
        while(root->next!=NULL){
            root=root->next;
        }
        root->next=Newnode(data);
    }

}
void print(struct node * root,int i){
    if(root!=NULL){
    if(i==0){
       printf(" %d ",root->coeff);
    }
    else{
        printf(" %d x^%d +",root->coeff,i);
        i--;
        print(root->next,i);
        }
    }
}
struct node * addi(struct node * root1,struct node * root2,struct node* root3){
    root3=insert(root3,root1->coeff+root2->coeff);
    root1=root1->next;
    root2=root2->next;
    insert(root3,root1->coeff+root2->coeff);
    root1=root1->next;
    root2=root2->next;
    insert(root3,root1->coeff+root2->coeff);

    return root3;
}
struct node * sub(struct node * root1,struct node * root2,struct node* root3){
    root3=insert(root3,root1->coeff-root2->coeff);
    root1=root1->next;
    root2=root2->next;
    insert(root3,root1->coeff-root2->coeff);
    root1=root1->next;
    root2=root2->next;
    insert(root3,root1->coeff-root2->coeff);

    return root3;
}
struct node * mul(struct node * root1,struct node * root2,struct node* root3){
    struct node*temp1=root1;
    struct node*temp2=root2;
    root3=insert(root3,root1->coeff*root2->coeff);
    root2=root2->next;
    temp1=temp1->next;
    int e=root1->coeff*root2->coeff+temp1->coeff*temp2->coeff;
    insert(root3,e);
    int j=root2->coeff*temp1->coeff;
    insert(root3,j);
    root1=root1->next;
    temp2=temp2->next;
    root2=root2->next;
    temp1=temp1->next;
    int k=root1->coeff*root2->coeff+temp1->coeff*temp2->coeff;
    insert(root3,k);
    int l=root2->coeff*temp1->coeff;
    insert(root3,l);
    return root3;

}
void main(){
    struct node* root1 =NULL;
    struct node* root2 =NULL;
    struct node* root3 =NULL;

    printf("The first polynomial\n");

    root1=insert(root1,2);
    insert(root1,3);
    insert(root1,6);
    print(root1,2);

    printf("\nThe second polynomial\n");

    root2=insert(root2,4);
    insert(root2,5);
    insert(root2,3);
    print(root2,2);

    printf("\nAddition of the two \n");

    root3=addi(root1,root2,root3);
    print(root3,2);

    root3=NULL;

    printf("\nSubtraction of the two\n");

    root3=sub(root1,root2,root3);
    print(root3,2);

    root3=NULL;

    printf("\nMultiplcation of the two\n");

    root3=mul(root1,root2,root3);
    print(root3,4);
}
