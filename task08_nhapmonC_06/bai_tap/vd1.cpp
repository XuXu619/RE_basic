#include<stdio.h>

main()
{
    int c;
    char t1[14], t2[14];

    FILE *f1, *f2;

    printf("TEP NGUON: ");
    gets(t1);
    printf("TEP DICH: ");
    gets(t2);
    f1=fopen(t1, "rb");
    if(f1=NULL)
    {
        printf("TEP % khong ton tai", t1);
        getch();
        edit(1);
    }

    f2= fopen(t2,"wb");
    // sao tệp được thực hiện ở đoạn này

    while ((c=fgetc(f1))!=EOF)
        fputc(c,f2);
    fclose(f1);
    fclose(f2);
}
