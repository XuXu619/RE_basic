#include<stdio.h>
#include<conio.h>
typedef struct{float x, y;}sophuc;

sophuc cong(sophuc u, sophuc v);
void insp(sophuc u);

sophuc cong(sophuc u, sophuc v)
{
    sophuc w;
    w.x=u.x+v.x;
    w.y=u.y+v.y;
    return w;
}
    void insp(sophuc u)
    {
        printf("%0.2f,%0.2f",u.x,u.y);
    }

main()
{
    sophuc u, v;
    u.x = 6.5;
    u.y = -3.6;

    v.x = 2.8;
    v.y = 12.1;

    printf("\nSo phuc u = ");
    insp(u);
    printf("\nSo phuc v = ");
    insp(v);
    printf("\nTong = ");
    insp(cong(u,v));
    getch();

}


