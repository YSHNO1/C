#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#define Leafnum 27
#define Hufnum 2*Leafnum
#define maxdouble 9999.9
using namespace std;
typedef char DateType;

typedef struct Tnode{
    DateType name;
    double weight;
    int lchild, rchild, parent;
}Huftree;

typedef struct Cnode{
    char bits[Leafnum+1];
    int start;
    char ch;
}Hufcode;

Hufcode code[Leafnum+1];
Huftree tree[Hufnum+1];
char Huffmancode[1000];
char ch[]={'\0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
float w[]={0,186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};

void CreatTreeHuffman(Huftree tree[]){
    int i, j, p1, p2;
    double least1, least2;
    for(i=1; i<=Hufnum; i++){
        tree[i].name='\0';
        tree[i].parent=0;
        tree[i].lchild=0;
        tree[i].rchild=0;
        tree[i].weight=0.0;
    }
    for(i=1; i<=Leafnum; i++){
        tree[i].name=ch[i];
        tree[i].weight=w[i];
    }
    for(i=Leafnum+1; i<=Hufnum; i++){
        p1=0;
        p2=0;
        least1=least2=maxdouble;
        for(j=1; j<i; j++){
            if(tree[j].parent==0){
                if(tree[j].weight<least1){
                    least2=least1;
                    least1=tree[j].weight;
                    p2=p1;
                    p1=j;
                }
                else{
                    if(tree[j].weight<least2){
                        least2=tree[j].weight;
                        p2=j;
                    }
                }
            }
        }
       tree[p1].parent=i;
       tree[p2].parent=i;
       tree[i].lchild=p1;
       tree[i].rchild=p2;
       tree[i].weight=tree[p1].weight+tree[p2].weight;
    }
    tree[Hufnum-1].parent=0;
}

void CreatCodeHuffman(Hufcode code[], Huftree tree[]){
    int i, c, p;
    Hufcode buf;
    for(i=1; i<=Leafnum; i++){
        buf.ch=ch[i];
        buf.start=Leafnum;
        c=i;
        p=tree[i].parent;
        while(p!=0){
            buf.start--;
            if(tree[p].lchild==c){
                buf.bits[buf.start]='0';
            }
            else{
                buf.bits[buf.start]='1';
            }
            c=p;
            p=tree[p].parent;
        }
        code[i]=buf;
    }
}

void WriteCodeHuffman(Hufcode code[], Huftree tree[]){
    int i, j, k, n=0;
    char c[100];
    cout<<"请输入字符串："<<endl;
    gets(c);
    cout<<endl;
    cout<<"则字符串的哈夫曼编码为："<<endl;
    for(i=0; i<strlen(c); i++){
        for(j=1; j<Leafnum; j++){
            if(c[i]==tree[j].name){
                for(k=code[j].start; k<Leafnum; k++){
                    cout<<code[j].bits[k];
                    Huffmancode[n]=code[j].bits[k];
                    n++;
                }
            }
        }
    }
}

void TransCodeHuffman(Hufcode code[], Huftree tree[], char s[]){
    int i;
    char *q=NULL;
    i=Hufnum-1;
    q=s;
    while(*q!='\0'){
        if(*q=='0'){
            i=tree[i].lchild;
        }
        if(*q=='1'){
            i=tree[i].rchild;
        }
        if((tree[i].lchild==0)&&tree[i].rchild==0){
            cout<<code[i].ch;
            i=Hufnum-1;
        }
        q++;
    }
    cout<<endl;
}

void PrintTreeHuffman(Huftree tree[]){
    int i;
    cout<<"根据字符的使用概率所建立的哈夫曼树为："<<endl;
    cout<<"字符序号字符名称字符频率双亲位置左孩子右孩子"<<endl;
    for(i=1; i<Hufnum; i++){
        cout<<"  "<<i<<"\t    "<<tree[i].name<<"\t";
        cout<<tree[i].weight<<"\t    "<<tree[i].parent<<"\t    "<<tree[i].lchild<<"    "<<tree[i].rchild<<endl;
    }
}

void PrintCodeHuffman(Hufcode code[]){
    int i, j;
    cout<<"根据哈夫曼树队字符所建立的哈夫曼编码为："<<endl;
    cout<<"字符序号字符名称字符编码"<<endl;
    for(i=1; i<Leafnum; i++){
        cout<<"   "<<i<<"\t    "<<code[i].ch<<"      ";
        for(j=code[i].start; j<Leafnum; j++){
            cout<<code[i].bits[j];
        }
        cout<<"\t\t"<<endl;
    }
}

int main()
{
    CreatTreeHuffman(tree);
    PrintTreeHuffman(tree);
    CreatCodeHuffman(code, tree);
    PrintCodeHuffman(code);
    WriteCodeHuffman(code, tree);
    char *filename="";
    ofstream ofs(filename);
    ofs<<Huffmancode;
    ofs.close();
    ifstream ifs(filename);
    if(!ifs){
        cout<<"Error: failed to open file"<<endl;
        exit(0);
    }
    char buffer[100];
    ifs>>buffer;
    cout<<endl<<endl;
    cout<<"codefile文件中的代码如下："<<endl;
    cout<<buffer<<endl<<endl;
    ifs.close();
    cout<<"codefile文件中代码的译码如下："<<endl;
    TransCodeHuffman(code, tree, buffer);
    return 0;
}
