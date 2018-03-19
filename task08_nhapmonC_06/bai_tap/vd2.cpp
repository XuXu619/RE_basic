// Sao tệp dùng fread và fwrite

#include<stdio.h>
#include<conio.h>
typedef struct
{
    char  ht[25];
    int  ns;
}hs;

// khai báo và khởi đầu mảng cấu trúc

hs ds[50] =
{ {"", 0},
{"Pham THu Huong", 1976},
{"Nguyen Viet Dung", 1978},
{"Thanh Tam", 1974}
};

main()
{
   FILE *fp;
   float x[50]; int a[50]
   int i;

   // gán giá trijvho a[i] và x[i]

   for(i= 1; i<= 10,  i++)
    a[i]= 100*i;
   for(i=1; i<=5; i++)
    x[i]=0.1/i;
   // ghi mảng a, x và ds từ phần tử có chỉ số 1

   fp=fopen("mang.sl", "wb");
   fwite(a+1, sizeof(int), 10, fp);
   fwite(x+1, sizeof(float),5,fp);
   fwite(ds+1, sizeof(hs),3,fp);
   fclose(fp);

   // đọc từ tệp và đưa ra mảng từ phần từ chỉ số 11

   fp= fopen("mang.sl", "rb");
   fread(a+11, sizeof(int), 10, fp);
   fread(x+11, sizeof(float), 5, fp);
   fread(ds+11, sizeof(hs), 3, fp);
   fclose(fp);
   // in

   for(i = 11, i<=20; i++)
    printf("%d", a[i]);
   for(i=11, i<= 15; i++)
    printf("%f", x[i]);
   for(i=11, i<= 13; i++)
    printf("%s %d", ds[i].ht,ds[i].ns);


}
