#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct mat{
    int H;
    int L;
    float data[10][10]={0};
}mat;
mat OUT;

void initial_mat(mat &mat,int H,int L){
    mat.H=H;
    mat.L=L;
}

void data_in(mat &mat,int i,int j,float data){
    mat.data[i][j]=data;
}

float MUL(mat A,mat B,int I,int J){
    float data=0;
    for(int i=0;i<A.L;i++){
        data+=A.data[I][i]*B.data[i][J];
    }
    return data;
}
void multp(mat A,mat B,mat &OUT){
    OUT.H=A.H;
    OUT.L=B.L;
    for(int i=0;i<A.H;i++)
        for(int j=0;j<B.L;j++)
            data_in(OUT,i,j,MUL(A,B,i,j));

}
void getdata(mat &mat){
    printf("你个兔崽子搁这磨叽啥呢，麻利点，矩阵行数？");
    scanf("%d",&mat.H);
    printf("咋心眼那实诚，叫你讲行数就只讲行数？ 特娘的矩阵列数呢？");
    scanf("%d",&mat.L);
    printf("麻溜的，把矩阵给我打上，用空格隔开，用回车换行。你少给我咬文嚼字，咱老粗一个，靠玩嘴皮子可打不走鬼子。\n");
    for(int i=0;i<mat.H;i++)
        for(int j=0;j<mat.L;j++){
            scanf("%f",&mat.data[i][j]);
        }

}
void putdata(mat &mat){
    printf(" 这就是你特娘的要的答案： \n");
    for(int i=0;i<mat.H;i++){
        for(int j=0;j<mat.L;j++)
            printf("%0.2f  ",mat.data[i][j]);
        printf("\n");
    }

}

int main(){
    mat A,B;
    printf("我是你要找的八路军独立团团长李云龙，告诉你特娘的，老子当年你怎么打枪，现在就教你怎么算矩阵乘法，你特娘的站在山坡上学着点。  \n");
    printf("第一个矩阵\n");
    getdata(A);
    printf("第二个矩阵\n");
    getdata(B);
    if(A.L!=B.H){
        printf("你个狗样娘的，咋不随便找两个矩阵来乘?这两个矩阵能乘一块那就有鬼了！你小子还敢发牢骚，小心老子揍你！");
        return 0;
    }
    multp(A,B,OUT);
    putdata(OUT);


    return 0;
}