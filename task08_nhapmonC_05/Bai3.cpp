#include<stdio.h>
#include<conio.h>
#include<string.h>

struct sinhvien
{
  char hoten[30];
  char diachi[30];
  float diem;
};


void nhapdulieu(struct sinhvien *p, int n);

int main()
 {
  int kt;
  struct sinhvien sv[3];

  printf("\n Menu ");
  printf("\n 1.Nhap du lieu cho sinh vien ");
  printf("\n 2.Thoat ");


  while(1)
   {
    printf("\n Nhap vao muc can tim: ");
    fflush(stdin);
    scanf("%d",&kt);
    switch(kt)
     {
      case 1:
          nhapdulieu(sv,3); // truyền mảng sv vào hàm và cho biết mảng có 3 phần tử
          break ;

      case 2:
          return 0;
     }
   }
  getch();
 }

void nhapdulieu(struct sinhvien *p, int n)
 {
  int i;
  float tmp;

  printf("\n Nhap vao thong tin sinh vien ");
  for(i=0;i<n;i++)
   {
    printf("\n Thong tin sinh vien thu %d ",i+1);
    printf("\n Ho ten: ");
    fflush(stdin);
    gets(p[i].hoten);
    printf("\n Dia chi: ");
    fflush(stdin);
    gets(p[i].diachi);
    printf("\n Diem: ");
    scanf("%f",&tmp);
    p[i].diem = tmp;
   }
 }
