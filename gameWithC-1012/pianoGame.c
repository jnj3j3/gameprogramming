#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

void draw_check02(int c, int r);
void gotoxy(int x, int y);
void display_piano_keyboard(void);
void touch_keyboard(int code);
void display_manual(void);
void display_manual2(void);
void display_manual3(void);
void practice_piano(void);
int calc_frequency(int octave, int inx);  //À½°èÀÇ ÁÖÆÄ¼ö °è»ê
void touch_keyboard_half(int code);
void touch_half(int x, int* freq_half);
void touch_keyboard_clear(int code);
void play_piano_correct(void);
void touch_answer(int x,int answer,int* freq);
void start_piano_correct(void);
void start_piano_matching(void);
void play_piano_matching(void);
char qwerty[17][4]={"q ","w ","e ","r ","t ","y ","u ","i ","o ","p ","z ","x ","c ","v ","b ","n ","m "};
void clear(){
	system("cls");
	gotoxy(1,1);
}
void start_music(){ 
	Beep(calc_frequency(4, 6),500);
	Beep(calc_frequency(4, 10),500);
	Beep(calc_frequency(4, 11),500);
	Beep(calc_frequency(4, 12),500);
	Beep(calc_frequency(4, 14),500);
	Beep(calc_frequency(4, 15),500);
}
void ending_music(){
	Beep(calc_frequency(4, 15),500);
	Beep(calc_frequency(4, 12),500);
	Beep(calc_frequency(4, 11),500);
	Beep(calc_frequency(4, 10),500);
	Beep(calc_frequency(4, 12),500);
	Beep(calc_frequency(4, 6),500);
}
int main(void)
{
	SMALL_RECT windowSize = {0 , 0 , 70 , 20}; //change the values
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
	SetConsoleTitle("Piano Game App");
	int ch;
	draw_check02(8, 2);
	printf("\n");
	puts("		  ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦¢   PIANO GAMES COLLECTION   ¦¢");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n");
	puts("		        MAIN MENU: [ENTER]\n");
	puts("		             EXIT: [ESC]");
	start_music();
	do{
		ch = getch();
		if (ch == 27) {
			clear();
	gotoxy(1,5) ;
	puts("		  ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦¢           ( T-T)«Î         ¦¢");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦¢      SEE YOU NEXT TIME     ¦¢");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n");
	ending_music();
	return 0;
		}
	}while(ch!='\r');
	do{
		clear();
		gotoxy(1,5);
		puts("          ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬  menu ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
		puts("          ¦¢                                               ¦¢");
		puts("          ¦¢                1: ÇÇ¾Æ³ë ¿¬½À.                ¦¢");
		puts("          ¦¢                                               ¦¢");
		puts("          ¦¢                2: À½ ¸ÂÃß±â.                  ¦¢");
		puts("          ¦¢                                               ¦¢");
		puts("          ¦¢                3: ¼ø¼­ ±â¾ïÇÏ±â.              ¦¢");
		puts("          ¦¢                                               ¦¢");
		puts("          ¦¢                  [ESC]: Á¾·á                  ¦¢");
		puts("          ¦¢                                               ¦¢");
		puts("          ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n");
		ch = getch();
		clear();
		if(ch=='1'){
			display_manual();
			practice_piano();
			clear();
		}else if(ch=='2'){
			play_piano_correct();
			clear();
		}else if(ch=='3'){
			play_piano_matching();
			clear();
		}
	}while(ch !=27);
	clear();
	gotoxy(1,5) ;
	puts("		  ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦¢           ( T-T)«Î         ¦¢");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦¢      SEE YOU NEXT TIME     ¦¢");
	puts("		  ¦¢                            ¦¢");
	puts("		  ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n");
	ending_music();
	return 0;
}

void display_manual(void)
{
	printf("Å°º¸¸¦ ´­·¯ ÇÇ¾Æ³ë¸¦ ¿¬ÁÖÇØ º¾½Ã´Ù! \n");
	printf("ÇØ´ç °Ç¹Ý¿¡ À½ÀÌ Ç¥½ÃµÇ°í,\n");
	printf("ÇØ´ç À½ÀÌ ½ºÇÇÄ¿·Î Ãâ·ÂµË´Ï´Ù.\n");
	printf("* ¹ÝÀ½Àº 0~9¿Í [-]Å°¿Í [=]Å°·Î ÀÛµ¿µË´Ï´Ù.\n");
}
void display_manual2(){
	printf("À½ÀÌ Ãâ·ÂµÇ¾ú½À´Ï´Ù! \n");
	printf("°ú¿¬ ¾î¶² À½À» Ãâ·ÂÇÑ °Í ÀÏ±î¿ä?\n");
	printf("¿¹»óÇÏ´Â À½ÀÇ À½¹ÝÀ» ´­·¯ È®ÀÎÇØ º¸¼¼¿ä\n");
	printf("ÇÁ·Î±×·¥ Á¾·á´Â Esc Å° ÀÔ´Ï´Ù.\n");
};
void display_manual3(){
	printf("À½ÀÌ Ãâ·ÂµÇ°í ÀÖ½À´Ï´Ù! \n");
	printf("Ãâ·ÂÀÌ ¿Ï·áµÇ¸é ¿Ü¿ü´ø ¼ø¼­´ë·Î À½¹ÝÀ» ´­·¯º¸¼¼¿ä\n");
	printf("°ú¿¬ ¾î¶² ¼ø¼­°¡ ¸ÂÀ» ±î¿ä?\n");
	printf("ÇÁ·Î±×·¥ Á¾·á´Â Esc Å° ÀÔ´Ï´Ù.\n");

};
void touch(int x,int* freq,int length){
	touch_keyboard(x);
	Beep(freq[x],length);
	display_piano_keyboard();
}
void touch_half(int x, int* freq_half){
	touch_keyboard_half(x);
	Beep(freq_half[x],300);
	touch_keyboard_clear(x);
	gotoxy(1,15);
}
void touch_answer(int x,int answer,int* freq){
	touch_keyboard(x);
	Beep(freq[x],300);
	system("cls");
	if(x==answer){
		gotoxy(1,5);
		puts("		      ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â\n");\
		puts("		      ¦¢          Á¤´äÀÔ´Ï´Ù.           ¦¢\n");
		puts("		      ¦¢    ´ë´ÜÇØ¿ä!! ¡Ò(o£Þ¡ä£Þo)«Î   ¦¢\n");
		puts("		      ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
	}
	else {
		gotoxy(1,5);
		printf("		         Æ²·È½À´Ï´Ù...   ( ¢¥¡â£à)\n\n");
		printf("		      ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â\n");\
		printf("		      ¦¢   Á¤´äÀº: %s Å°¿´½À´Ï´Ù.   ¦¢\n",qwerty[answer]);
		printf("		      ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
	}sleep(3);
	gotoxy(1,1);
}
void play_piano_matching(){
	int ch;
	do{
		clear();
		gotoxy(1,5);
		puts("		  ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
		puts("		  ¦¢                            ¦¢");
		puts("		  ¦¢      À½ ¼ø¼­¸¦ ¸ÂÃç¶ó!     ¦¢");
		puts("		  ¦¢                            ¦¢");
		puts("		  ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
		puts("                           START: [ENTER]\n");
		puts("		            EXIT: [ESC]");
		ch = getch();
		if(ch == '\r')
			start_piano_matching();	
	}while(ch!=27);
}
void start_piano_matching(){ 
	int index[]={0, 2, 4, 5, 7, 9, 11, 12,14,16,17,19,21,23,25,26,28,30};
	int freq[17], code, i;
	int index_half[] = {1,3,6,8,10,13,15,18,20,22,24,27,29};
	int freq_half[13];
	for(i = 0; i < 13; i++)
		freq_half[i] = calc_frequency(4, index_half[i]); //ÁÖÆÄ¼ö°è»ê
	for(i=0;i<17;i++)
		freq[i]=calc_frequency(4, index[i]); //ÁÖÆÄ¼ö°è»ê //È­¸é¿¡ °Ç¹ÝÇ¥½Ã
	int count =3;
	int memoryNum[count];
	int randNum,arr=0;
	do{
		clear();
		gotoxy(23,10);
		printf("3ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("2ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("1ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		display_manual3();
		printf("[ESC]: EXIT\n\n");
		draw_check02(8, 2);
		display_piano_keyboard();
		arr=0,count=3;
		int check  = 0;
		do
		{
			int length = 600;
			randNum  = rand()%17;
			memoryNum[arr++] = randNum;
			touch(randNum,freq,length);
		
		}while(count-->0);
		count =3;
		arr=0;
		do{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			code=getch();
			if(code=='q'||code=='Q') touch(0,freq,300);
			else if(code=='w'||code=='W') touch(1,freq,300);
			else if(code=='e'||code=='E') touch(2,freq,300);
			else if(code=='r'||code=='R') touch(3,freq,300);
			else if(code=='t'||code=='T') touch(4,freq,300);
			else if(code=='y'||code=='Y') touch(5,freq,300);
			else if(code=='u'||code=='U') touch(6,freq,300);
			else if(code=='i'||code=='I') touch(7,freq,300);
			else if(code=='o'||code=='O') touch(8,freq,300);
			else if(code=='p'||code=='P') touch(9,freq,300);
			else if(code=='z'||code=='A') touch(10,freq,300);
			else if(code=='x'||code=='S') touch(11,freq,300);
			else if(code=='c'||code=='D') touch(12,freq,300);
			else if(code=='v'||code=='F') touch(13,freq,300);
			else if(code=='b'||code=='G') touch(14,freq,300);
			else if(code=='n'||code=='H') touch(15,freq,300);
			else if(code=='m'||code=='J') touch(16,freq,300);
			else if(code=='0'){
				touch_half(9,freq_half);
			} 
			else if(code =='-'){
				touch_half(10,freq_half);
			}
			else if(code =='='){ 
				touch_half(11,freq_half);
			}
			else if ('1'<=code && code<='9'){
				code-=49;
				touch_half(code,freq_half);
			}
			int qwertyArr = memoryNum[arr++];
			if(code == 27) break;
			else if(code != qwerty[qwertyArr][0]){
				clear();
				gotoxy(1,5);
				printf("		         Æ²·È½À´Ï´Ù...   ( ¢¥¡â£à)\n\n");
				printf("		      ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â\n");\
				printf("		      ¦¢   Á¤´äÀº: %s Å°¿´½À´Ï´Ù.   ¦¢\n",qwerty[qwertyArr]);
				printf("		      ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
				sleep(3);
				gotoxy(1,1);
				check = 1;
				break;
			}
		}while(count-->0);
		if(check == 0 ){
			clear();
			gotoxy(1,5);
			puts("		      ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â\n");\
			puts("		      ¦¢          Á¤´äÀÔ´Ï´Ù.           ¦¢\n");
			puts("		      ¦¢    ´ë´ÜÇØ¿ä!! ¡Ò(o£Þ¡ä£Þo)«Î   ¦¢\n");
			puts("		      ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
			sleep(3);
			gotoxy(1,1);
		}
		clear();
		printf("°è¼ÓÇÏ½Ã·Á¸é ENTERÅ°¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä.\n");
		printf("ESCÅ°¸¦ ´©¸£¸é °ÔÀÓ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.\n");
		do{
			code = getch();
		}while(code!=27&&code!='\r');
	}while(code!=27);
}
void practice_piano(void)
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12,14,16,17,19,21,23,25,26,28,30};
	int freq[17], code, i;
	int index_half[] = {1,3,6,8,10,13,15,18,20,22,24,27,29};
	int freq_half[13];
	for(i = 0; i < 13; i++)
		freq_half[i] = calc_frequency(4, index_half[i]); //ÁÖÆÄ¼ö°è»ê
	for(i=0;i<17;i++)
		freq[i]=calc_frequency(4, index[i]); //ÁÖÆÄ¼ö°è»ê
	printf("[ESC]: EXIT\n\n");
	draw_check02(8, 2);
	display_piano_keyboard();  //È­¸é¿¡ °Ç¹ÝÇ¥½Ã
	do
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		code=getch();
		if(code=='q'||code=='Q') touch(0,freq,300);
		else if(code=='w'||code=='W') touch(1,freq,300);
		else if(code=='e'||code=='E') touch(2,freq,300);
		else if(code=='r'||code=='R') touch(3,freq,300);
		else if(code=='t'||code=='T') touch(4,freq,300);
		else if(code=='y'||code=='Y') touch(5,freq,300);
		else if(code=='u'||code=='U') touch(6,freq,300);
		else if(code=='i'||code=='I') touch(7,freq,300);
		else if(code=='o'||code=='O') touch(8,freq,300);
		else if(code=='p'||code=='P') touch(9,freq,300);
		else if(code=='z'||code=='A') touch(10,freq,300);
		else if(code=='x'||code=='S') touch(11,freq,300);
		else if(code=='c'||code=='D') touch(12,freq,300);
		else if(code=='v'||code=='F') touch(13,freq,300);
		else if(code=='b'||code=='G') touch(14,freq,300);
		else if(code=='n'||code=='H') touch(15,freq,300);
		else if(code=='m'||code=='J') touch(16,freq,300);
		else if(code=='0'){
			touch_half(9,freq_half);
		} 
		else if(code =='-'){
			touch_half(10,freq_half);
		}
		else if(code =='='){ 
			touch_half(11,freq_half);
		}
		else if ('1'<=code && code<='9'){
			code-=49;
			touch_half(code,freq_half);
		}
	
	}while(code!=27);
}
void play_piano_correct(){
	int ch;
	do{
		clear();
		gotoxy(1,5);
		puts("		  ¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
		puts("		  ¦¢                            ¦¢");
		puts("		  ¦¢         À½À» ¸ÂÃç¶ó!       ¦¢");
		puts("		  ¦¢                            ¦¢");
		puts("		  ¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä\n\n");
		puts("                           START: [ENTER]\n");
		puts("		            EXIT: [ESC]");
		ch = getch();
		if(ch == '\r')
			start_piano_correct();	
	}while(ch!=27);
}
void start_piano_correct(){ 
	//À½ ¸ÂÃß±â
	int freq[17],i;
	for(i = 0; i < 17; i++)
		freq[i] = calc_frequency(4, i); //ÁÖÆÄ¼ö°è»ê
	int code;
	do
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		clear();
		gotoxy(23,10);
		printf("3ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("2ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("1ÃÊ ÈÄ¿¡ À½ÀÌ Ãâ·ÂµË´Ï´Ù.");
		sleep(1);
		clear();
		display_manual2();
		printf("[ESC]: EXIT\n\n");
		draw_check02(8, 2);
		display_piano_keyboard();  //È­¸é¿¡ °Ç¹ÝÇ¥½Ã
		int random = rand()%17;
		Beep(freq[random],300);
		code=getch();
		if(code=='q'||code=='Q') touch_answer(0,random,freq);
		else if(code=='w'||code=='W')	touch_answer(1,random,freq);
		else if(code=='e'||code=='E')	touch_answer(2,random,freq);
		else if(code=='r'||code=='R')	touch_answer(2,random,freq);
		else if(code=='t'||code=='T')	touch_answer(4,random,freq);
		else if(code=='y'||code=='Y')	touch_answer(5,random,freq);
		else if(code=='u'||code=='U')	touch_answer(6,random,freq);
		else if(code=='i'||code=='I')	touch_answer(7,random,freq);
		else if(code=='o'||code=='O')	touch_answer(8,random,freq);
		else if(code=='p'||code=='P')	touch_answer(9,random,freq);
		else if(code=='z'||code=='A')	touch_answer(10,random,freq);
		else if(code=='x'||code=='S')	touch_answer(11,random,freq);
		else if(code=='c'||code=='D')	touch_answer(12,random,freq);
		else if(code=='v'||code=='F')	touch_answer(13,random,freq);
		else if(code=='b'||code=='G')	touch_answer(14,random,freq);
		else if(code=='n'||code=='H')	touch_answer(15,random,freq);
		else if(code=='m'||code=='J')	touch_answer(16,random,freq);
		clear();
		printf("°è¼ÓÇÏ½Ã·Á¸é ENTERÅ°¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä.\n");
		printf("ESCÅ°¸¦ ´©¸£¸é ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.\n");
		do{
			code = getch();
		}while(code!=27&&code!='\r');
	}while(code!=27);

}
void draw_check02(int c, int r)
{
	puts("¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢");
	puts("¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢");
	puts("¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢");
	puts("¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢ ¦¢ ¦¢  ¦¢  ¦¢ ¦¢ ¦¢ ¦¢  ¦¢");
	puts("¦¢  ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä  ¦¢  ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä  ¦¢  ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä  ¦¢  ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä  ¦¢  ¦Æ¦¬¦Ä ¦Æ¦¬¦Ä  ¦¢");
	puts("¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢");
	puts("¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢");
	puts("¦Æ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦Ä");
}
void display_piano_keyboard(void)
{
	int i;
	for(i=0;i<17;i++)
	{
		gotoxy(3+i*4,13);
		printf("%2d", i+1); 
	}
	for(i=0;i<17;i++)
	{
		gotoxy(3+i*4,13);
		printf("%s", qwerty[i]);
	}
}
void touch_keyboard(int code)
{
	gotoxy(3+code*4,13);
	printf("%c%c", 0xa1, 0xe3);
}
void touch_keyboard_half(int code)
{
	int i,codeNum=code; 
	for(i=1;i<=codeNum;i++){
		if(i==2||i==5||i==7||i==10) code+=1;
	}
	gotoxy(5+code*4,10.5);
	printf("%c%c", 0xa1, 0xe3);
}
void touch_keyboard_clear(int code)
{
	int i,codeNum=code; 
	for(i=1;i<=codeNum;i++){
		if(i==2||i==5||i==7||i==10) code+=1;
	}
	gotoxy(4+code*4,10.5);
	printf("¦¢ ¦¢");
}
int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
