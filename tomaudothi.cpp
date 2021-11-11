#include<conio.h>
#include<stdio.h>

int n,maudinh[50],a[50][50];
FILE *f;
void Input()
{
	int i,j;
	fscanf(f,"%d",&n);
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= n; j++ )
			fscanf(f,"%d",&a[i][j]);
}

void Tomau()
{
	int i,j;
	maudinh[1] = 1;
	for ( i = 2; i <= n; i++ )
	{
		maudinh [i] = 1;
		j =1;
		nhan:
		for ( j = 1; j <= i-1; j++ )
			if ( a[j] != 0 && maudinh [i] == maudinh[j])
				maudinh [i]++;
		for ( j = 1; j <= n; j++ )
			if (a[j]!=0 && maudinh [i] == maudinh[j]) goto nhan;
	}
}

main()
{
int i;
f = fopen("tomaudothi.txt","rt");
printf("Hello World");
Input();
Tomau();
for ( i = 1; i <= n; i++ )
printf("\nDinh %d to mau %d ",i,maudinh);
getch();
}

