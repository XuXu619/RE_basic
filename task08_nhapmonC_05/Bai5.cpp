#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct
{
    char ht[25]; // ho ten
    int ns; // nam sinh
}person;

typedef struct
{
    char tenphong[30];
    int sonhanvien;
    person *nhanvien;
}ppp;
typedef struct
{
    char tenvien[30];
    int sophong;
    ppp *phong;
}vvv;

vvv *vien;
int sovien;
main()
{
    int i, j ,k, ngay , thang, nam , sophong , sonhanvien, ns;
system("cls");
    printf("Sovien: \n");
    scanf("%d%*c", &sovien);

    vien = (vvv*)malloc ((sovien + 1 )*sizeof(vvv));// vao so lieu tung vien

    for(i= 1; i <= sovien; i++)
    {
        printf("\n Ten vien thu %d: ",i);
        gets(vien[i].tenvien);
        printf("\nSo phong cua vien %s", vien[i].tenvien);
        scanf("%d%*c", &sophong); vien[i].sophong = sophong;
        vien[i].phong = (ppp*)malloc((sophong + 1 )*sizeof(ppp));
        for(j = 1; j<= sophong; j++)
        {
            printf("\n Ten phong % cuar vien %s: ", j, vien[i].tenvien);
            gets(vien[i].phong[j].tenphong);
            printf("\n so nhan vien cua phong %s vien %s:", vien[i].phong[j].tenphong, vien[i].tenvien);
            scanf("\n%d%*c", &sonhanvien);
            vien[i].phong[j].sonhanvien=sonhanvien;
            printf("\n Vien %s phong %s", vien[i].tenvien, vien[i].phong[j].tenphong);

            for ( k = 1; k <= sonhanvien; k++)
            {
                printf("\n Ho ten nhan vien %d: ", k);
                gets(vien[i].phong[j].nhanvien[k].ht);
                printf("\n nam sinh nhan vien ", k);
                scanf("%d%*c", &ns);
                vien[i].phong[j].nhanvien[k].ns=ns;
            }
        }
    }
// dau ra man hinh
system("cls");
for (i = 1 ; i <= sovien; i++ );
{
    printf("\n Vien %s co %d phong",vien[i].tenvien, vien[i].sophong);
    for(j = 1 ; j <= vien[i].sophong; i ++ );
    {
        printf("\n phong %s vien %s cos %d nhan vien : ",vien[i].phong[j].tenphong, vien[i].tenvien, vien[i].phong[j].sonhanvien);
        for ( k = 1; k <= vien [i].phong[j].sonhanvien; i++);
        {
            printf("\n Ho ten %s sinh nawm %d ", vien[i].phong[j].nhanvien[k].ht, vien[i].phong[j].nhanvien[k].ns);
        }
    }
}
getch();
}
