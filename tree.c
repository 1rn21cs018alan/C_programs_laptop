#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink,*rlink;
    int info;
};

typedef struct node * NODE;
NODE getNode()
{
    NODE x;
    x= (NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("NO Space");
        exit(0);
    }
    return x;
}

NODE insert_BST(NODE root,int elem)
{
    NODE temp;
    temp=getNode();
    temp->llink=temp->rlink=NULL;
    temp->info=elem;
    if(root==NULL)
        return temp;
    NODE cur=root,prev;
    while(cur!=NULL)
    {
        prev=cur;
        if(elem>cur->info)
            cur=cur->rlink;
        else    
            cur=cur->llink;
    }
    if(prev->info>elem)
        prev->llink=temp;
    else 
        prev->rlink=temp;
    return root;
}
void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d,",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d,",root->info);
    inorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)
        return;
    
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d,",root->info);
}
void search(NODE root,int elem)
{
    if(root==NULL)
    {
        printf("NULL\nElement not found\n");
        return;
    }
    printf("(%d)",root->info);
    if(root->info==elem)
        return;
    printf("->");
    if(root->info<elem)
        search(root->rlink,elem);
    else    
        search(root->llink,elem);
}
int main()
{
    NODE root=NULL;
    for(int i=1000;i<=1025;i++)
        root=insert_BST(root,i*(1-(2*i%2)));
    root=insert_BST(root,4);
    root=insert_BST(root,2);
    root=insert_BST(root,7);
    root=insert_BST(root,6);
    root=insert_BST(root,1);
    root=insert_BST(root,3);
    root=insert_BST(root,5);
    root=insert_BST(root,71);
    root=insert_BST(root,72);
    root=insert_BST(root,43);
    root=insert_BST(root,78);
    root=insert_BST(root,-12);
    root=insert_BST(root,998);
    root=insert_BST(root,-29);
    root=insert_BST(root,0);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    search(root,0);
    printf("\n");
    search(root,-1);
    return 0;
}