#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Tree{
    int data;
    Tree *lchild;
    Tree *rchild;
}t[40];
int postorder[40];
int inorder[40];
int levelorder[40];

void dfs(Tree* &t, int l1, int r1, int l2, int r2){
    t = new Tree();
    int i;
    for(i=l1; i<=r1; i++){
        if(inorder[i] == postorder[r2])
            break;
    }
    t->data = postorder[r2];
    if(i==l1){
        t->lchild = NULL;
    }
    else {
       dfs(t->lchild, l1, i-1, l2, l2+i-l1-1);
    }
    if(i == r1){
        t->rchild = NULL;
    }
    else{
        dfs(t->rchild, i+1, r1, r2-r1+i, r2-1);
    }
}
int cnt;
void bfs(Tree *t){
    queue<Tree*> q;
    q.push(t);
    while(!q.empty()){
        Tree *root = q.front();
        q.pop();
        levelorder[cnt++] = root->data;
        if(root->lchild != NULL){
            q.push(root->lchild);
        }
        if(root->rchild != NULL){
            q.push(root->rchild);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &postorder[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &inorder[i]);
    }

    Tree *t;
    dfs(t, 1, n, 1, n);
    cnt = 0;
    bfs(t);
    for(int i=0; i<cnt; i++){
        if(i == cnt - 1)
            printf("%d\n", levelorder[i]);
        else printf("%d ", levelorder[i]);
    }
}
