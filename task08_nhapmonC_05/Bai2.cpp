#include<stdio.h>
typedef struct
{
    int ng;
    char t[10];
    int nam;
}date;

typedef struct
{
    date dates;
    date datecq;
    float luong;
}person;

main()
{
    person p;
    printf("\n Ngay sinh: ngay  thang nam  ");
    scanf("%d%s%d", &p.dates.ng, &p.dates.t, &p.dates.nam);
    printf("\nNgay vao co quan: ngay thang nam ");

    scanf("%d%s%d", &p.datecq.ng, &p.datecq.t, &p.datecq.nam);
    printf("\nTien luong");
    scanf("%f", &p.luong);

    printf("\n%2d %3s %d",&p.dates.ng, &p.dates.t, &p.dates.nam);
    printf("\n%2d %3s %d",&p.datecq.ng, &p.datecq.t, &p.datecq.nam);
    printf("\nLuong = %7.2f ", p.luong);
}

