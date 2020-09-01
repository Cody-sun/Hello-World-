#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InorderTraversal( BinTree BT ){
    if(!BT)
        return;
    InorderTraversal(BT->Left);
    printf(" %c",BT->Data);
    InorderTraversal(BT->Right);
    return;
}
void PreorderTraversal( BinTree BT ){
    if(!BT)
        return;
    printf(" %c",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
    return;
}
void PostorderTraversal( BinTree BT ){
    if(!BT)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c",BT->Data);
    return;
}
void LevelorderTraversal( BinTree BT ){
    if(!BT)
        return;
    BinTree Queue[100];
    int front = 0,rear = 0;
    Queue[0] = BT;
    rear++;
    while(front != rear){
        printf(" %c",Queue[front]->Data);
        if(Queue[front]->Left)
            Queue[rear++] = Queue[front]->Left;
        if(Queue[front]->Right)
            Queue[rear++] = Queue[front]->Right;
        front++;
    }
    return;
}

BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BinTree BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else{
        if(X > BST->Data){
            BST->Right = Insert(BST->Right,X);
        }
        else if(X < BST->Data){
            BST->Left = Insert(BST->Left,X);
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(X == BST->Data)
            return BST;
        if(X > BST->Data)
            BST = BST->Right;
        if(X < BST->Data)
            BST = BST->Left;
    }
    return NULL;
}

Position FindMin( BinTree BST ){
    if(!BST)
        return NULL;
    else if(!BST->Left)
        return BST;
    return FindMin(BST->Left);
}

Position FindMax( BinTree BST ){
    if(!BST)
        return NULL;
    else if(!BST->Right)
        return BST;
    return FindMax(BST->Right);
}

BinTree Delete( BinTree BST, ElementType X ){
    if(!BST)
        printf("Not Found\n");
    else{
        if(X < BST->Data)
            BST->Left = Delete(BST->Left,X);
        else if(X > BST->Data)
            BST->Right = Delete(BST->Right,X);
        else{
            if(BST->Left && BST->Right){
                BinTree temp = FindMin(BST->Right);
                BST->Data = temp->Data;
                BST->Right = Delete(BST->Right,temp->Data);
            }
            else{
                BinTree temp = BST;
                if(!BST->Left)
                    BST = BST->Right;
                else if(!BST->Right)
                    BST = BST->Left;
                free(temp);
            }
        }
    }
    return BST;
}

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");
    getchar();getchar();
    return 0;
}
