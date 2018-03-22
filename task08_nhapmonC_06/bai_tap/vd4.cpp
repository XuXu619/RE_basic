#include <stdio.h>
#include <stdlib.h>

void Enter(int &save, int &max)
{
	int n, a[1000], b[10000];
	FILE* fi = NULL;
	fi = fopen("TANSO.inp","r");
	fscanf(fi,"%d", &n);
	for (int i = 1; i < n + 1; i++)
		{
			fscanf(fi,"%d", &a[i]);
			b[a[i]]++;
			if (b[a[i]] > max)
				{
					save = a[i];
					max = b[a[i]];
				}
		}
	fclose(fi);
}
void Output(int save, int max)
{
	FILE *fo = NULL;
	fo = fopen("TANSO.out","w");
	fprintf(fo,"%d %d",save, max);
	fclose(fo);
}
int main()
{
	int max = 0, save;
	Enter(save, max);
	Output(save, max);
	return 0;
}
