#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
	int x = 1;
for(int i=1;i<=9;i++)
{
	for(int i2=1;i2<=9;i2++){
		gotoxy(x, i2);
		printf("%d*%d=%2d",i,i2,i2*i);	
	}
	x+=10;
}
printf("\n");
return 0;
}
void gotoxy(int x, int y)
{
COORD Pos = {x - 1, y - 1};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//3´Ü Ãâ·Â
