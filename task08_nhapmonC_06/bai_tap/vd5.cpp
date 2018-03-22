#include<stdio.h>
#include<conio.h>

void taomoi(void);
void bosung(void);
void suachua(void);
void xem(void);

typedef struct
{
    char ht[25];
    int bl;
    float nc;
}person;


long size = sizeof(person);

main()
{
    int sg;
    while (1)
    {
        clrscr();
        printf("\n 1. Tao moi");
        printf("\n 2. Bo sung");
        printf("\n 3. Sua chua");
        printf("\n 4. Xem");
        printf("\n 5. Ket thuc");

        sg=getch();

        if(sg== '1')
            taomoi();
        else if (sg == '2')
            bosung();
        else if (sg == '3')
            suachua();
        else if (sg == '4')
            xem();
        else
        {
            clrscr();
            exit(1);
        }
    }
}


void taomoi(void)
{
    person cb;
    FILE *fp;
    int n = 0;

    fp=fopen("dscb.sl","wb");
    while(1)
    {
        clrscr();
        printf("\n Nguoi thu %d/n/n",n+1);
        printf("\n Ho ten:");
        gets(cb.ht);
        if(cb.ht[0] == 0)break;

        printf("\n Bac luong:");
        scanf("%d", &cb.bl);
        printf("\n Ngay cong:");
        scanf("%f*c", &cb.nc);
        ++n;

        fwrite(&cb, size, 1, fp);
    }
    fclose(fp);
}

void bosung(void)

{
    person cb;
    FILE *fp
    long n;

    fp = fopen("dscb.sl",""ab");

    // Xac dinh n = so ban ghi

    fseek(fp, 0, SEEK_END);

    n = ftell(fp)/size;

    while(1)
    {
        clrscr();
        printf("\n Nguoi thu %ld\n\n", n+1);
        printf("\n Ho ten:");
        gets(cb.ht);
        if(cb.ht[0] == 0)break;

        printf("\n Bac luong:");
        scanf("%d", &cb.bl);
        printf("\n Ngay cong:");
        scanf("%f*c", &cb.nc);
        ++n;

        fwrite(&cb, size, 1, fp);
    }
    fclose(fp);
}

void suachua(void)

{
    person cb;

    FILE *fp; long i,n;

    if((fp = fopen("dscb.sl","r+b")) == NULL)
    {
        printf("\n Chua co du lieu");
        return;
    }

    // Xac dinh n bawng so ban ghi

    fseek(fp)\size;

    while(1)
    {
        clrscr();
        printf("\n Sua nguoi thu (n <= %1d)", n);
        scanf("%ld*c", &i);

        if( i > 0 && i <= n)
        {
            fseek(fp,(i - 1)* size, SEEK_SET);
            fread (&cb, size, 1, fp);
            printf("\n So lieu hien tai:");
            printf("\n Ho ten: %s", cb.ht);
            printf("\n Bac luong: %d", cb.bl);
            printf("\n Ngay cong: %0.2f", cb.nc);
            printf ("\n Sua la:");

            printf("\n Ho ten: %s");
            gets(cb.ht);
            if(cb.ht == o)break;
            printf("\n Bac luong: %d");
            scanf("%d", &cb.bl);
            printf("\n Ngay cong:  );
            scanf("%f%*c", %cb.nc);

            printf("\n Co Ghi sua? - C/K");
            if(toupper(getch())=='C')
            {
               fseek(fp, m, SEEK_SET);
               fwrite(&cb,size1,fp);
            }
        }
    }
    fclose(fp);
}

void xem(void)
{

    person cb;

    FILE *fp; int i=0;

    if((fp = fopen("dscb.sl","rb")) == NULL)
    {
        printf("\n Chua co du lieu");
        return;
    }
    clrscr();

    whlie(fread(&cb, size, 1, fp)>0)
    {
        ++i;
        printf("\n Nguoi %d", i);
        printf("\n Ho ten: %s", cb.ht);
        printf("\n Bac luong: %d", cb.bl);
        printf("\n Ngay cong: %0.2f", cb.nc);

    }
    fclose(fp);
    getch();
}
