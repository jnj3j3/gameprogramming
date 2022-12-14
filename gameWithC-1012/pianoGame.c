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
int calc_frequency(int octave, int inx);  //擠啗曖 輿だ熱 啗骯
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
	puts("		  牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
	puts("		  弛                            弛");
	puts("		  弛   PIANO GAMES COLLECTION   弛");
	puts("		  弛                            弛");
	puts("		  汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");
	puts("		        MAIN MENU: [ENTER]\n");
	puts("		             EXIT: [ESC]");
	start_music();
	do{
		ch = getch();
		if (ch == 27) {
			clear();
	gotoxy(1,5) ;
	puts("		  牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
	puts("		  弛                            弛");
	puts("		  弛           ( T-T)屋         弛");
	puts("		  弛                            弛");
	puts("		  弛      SEE YOU NEXT TIME     弛");
	puts("		  弛                            弛");
	puts("		  汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");
	ending_music();
	return 0;
		}
	}while(ch!='\r');
	do{
		clear();
		gotoxy(1,5);
		puts("          牟收收收收收收收收收收收收收收收收收收收收  menu 收收收收收收收收收收收收收收收收收收收收汕");
		puts("          弛                                               弛");
		puts("          弛                1: Я嬴喻 翱蝗.                弛");
		puts("          弛                                               弛");
		puts("          弛                2: 擠 蜃蹺晦.                  弛");
		puts("          弛                                               弛");
		puts("          弛                3: 牖憮 晦橘ж晦.              弛");
		puts("          弛                                               弛");
		puts("          弛                  [ESC]: 謙猿                  弛");
		puts("          弛                                               弛");
		puts("          汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");
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
	puts("		  牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
	puts("		  弛                            弛");
	puts("		  弛           ( T-T)屋         弛");
	puts("		  弛                            弛");
	puts("		  弛      SEE YOU NEXT TIME     弛");
	puts("		  弛                            弛");
	puts("		  汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n");
	ending_music();
	return 0;
}

void display_manual(void)
{
	printf("酈爾蒂 揚楝 Я嬴喻蒂 翱輿п 瑣衛棻! \n");
	printf("п渡 勒奩縑 擠檜 ル衛腎堅,\n");
	printf("п渡 擠檜 蝶Я醴煎 轎溘腌棲棻.\n");
	printf("* 奩擠擎 0~9諦 [-]酈諦 [=]酈煎 濛翕腌棲棻.\n");
}
void display_manual2(){
	printf("擠檜 轎溘腎歷蝗棲棻! \n");
	printf("婁翱 橫雯 擠擊 轎溘и 匙 橾梱蹂?\n");
	printf("蕨鼻ж朝 擠曖 擠奩擊 揚楝 �挫恉� 爾撮蹂\n");
	printf("Щ煎斜極 謙猿朝 Esc 酈 殮棲棻.\n");
};
void display_manual3(){
	printf("擠檜 轎溘腎堅 氈蝗棲棻! \n");
	printf("轎溘檜 諫猿腎賊 諼錫湍 牖憮渠煎 擠奩擊 揚楝爾撮蹂\n");
	printf("婁翱 橫雯 牖憮陛 蜃擊 梱蹂?\n");
	printf("Щ煎斜極 謙猿朝 Esc 酈 殮棲棻.\n");

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
		puts("		      牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");\
		puts("		      弛          薑港殮棲棻.           弛\n");
		puts("		      弛    渠欽п蹂!! ÷(o�煄銫煠)屋   弛\n");
		puts("		      汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
	}
	else {
		gotoxy(1,5);
		printf("		         ぎ溜蝗棲棻...   ( ╞﹦��)\n\n");
		printf("		      牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");\
		printf("		      弛   薑港擎: %s 酈艘蝗棲棻.   弛\n",qwerty[answer]);
		printf("		      汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
	}sleep(3);
	gotoxy(1,1);
}
void play_piano_matching(){
	int ch;
	do{
		clear();
		gotoxy(1,5);
		puts("		  牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
		puts("		  弛                            弛");
		puts("		  弛      擠 牖憮蒂 蜃醮塭!     弛");
		puts("		  弛                            弛");
		puts("		  汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
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
		freq_half[i] = calc_frequency(4, index_half[i]); //輿だ熱啗骯
	for(i=0;i<17;i++)
		freq[i]=calc_frequency(4, index[i]); //輿だ熱啗骯 //�飛橦� 勒奩ル衛
	int count =3;
	int memoryNum[count];
	int randNum,arr=0;
	do{
		clear();
		gotoxy(23,10);
		printf("3蟾 �醴� 擠檜 轎溘腌棲棻.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("2蟾 �醴� 擠檜 轎溘腌棲棻.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("1蟾 �醴� 擠檜 轎溘腌棲棻.");
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
				printf("		         ぎ溜蝗棲棻...   ( ╞﹦��)\n\n");
				printf("		      牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");\
				printf("		      弛   薑港擎: %s 酈艘蝗棲棻.   弛\n",qwerty[qwertyArr]);
				printf("		      汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
				sleep(3);
				gotoxy(1,1);
				check = 1;
				break;
			}
		}while(count-->0);
		if(check == 0 ){
			clear();
			gotoxy(1,5);
			puts("		      牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕\n");\
			puts("		      弛          薑港殮棲棻.           弛\n");
			puts("		      弛    渠欽п蹂!! ÷(o�煄銫煠)屋   弛\n");
			puts("		      汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
			sleep(3);
			gotoxy(1,1);
		}
		clear();
		printf("啗樓ж衛溥賊 ENTER酈蒂 殮溘п 輿撮蹂.\n");
		printf("ESC酈蒂 援腦賊 啪歜 詭景煎 給嬴骨棲棻.\n");
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
		freq_half[i] = calc_frequency(4, index_half[i]); //輿だ熱啗骯
	for(i=0;i<17;i++)
		freq[i]=calc_frequency(4, index[i]); //輿だ熱啗骯
	printf("[ESC]: EXIT\n\n");
	draw_check02(8, 2);
	display_piano_keyboard();  //�飛橦� 勒奩ル衛
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
		puts("		  牟收收收收收收收收收收收收收收收收收收收收收收收收收收收收汕");
		puts("		  弛                            弛");
		puts("		  弛         擠擊 蜃醮塭!       弛");
		puts("		  弛                            弛");
		puts("		  汎收收收收收收收收收收收收收收收收收收收收收收收收收收收收汛\n\n");
		puts("                           START: [ENTER]\n");
		puts("		            EXIT: [ESC]");
		ch = getch();
		if(ch == '\r')
			start_piano_correct();	
	}while(ch!=27);
}
void start_piano_correct(){ 
	//擠 蜃蹺晦
	int freq[17],i;
	for(i = 0; i < 17; i++)
		freq[i] = calc_frequency(4, i); //輿だ熱啗骯
	int code;
	do
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		clear();
		gotoxy(23,10);
		printf("3蟾 �醴� 擠檜 轎溘腌棲棻.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("2蟾 �醴� 擠檜 轎溘腌棲棻.");
		sleep(1);
		clear();
		gotoxy(23,10);
		printf("1蟾 �醴� 擠檜 轎溘腌棲棻.");
		sleep(1);
		clear();
		display_manual2();
		printf("[ESC]: EXIT\n\n");
		draw_check02(8, 2);
		display_piano_keyboard();  //�飛橦� 勒奩ル衛
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
		printf("啗樓ж衛溥賊 ENTER酈蒂 殮溘п 輿撮蹂.\n");
		printf("ESC酈蒂 援腦賊 詭景煎 給嬴骨棲棻.\n");
		do{
			code = getch();
		}while(code!=27&&code!='\r');
	}while(code!=27);

}
void draw_check02(int c, int r)
{
	puts("弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛");
	puts("弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛");
	puts("弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛");
	puts("弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛  弛 弛 弛 弛 弛 弛  弛  弛 弛 弛 弛  弛");
	puts("弛  汎收汛 汎收汛  弛  汎收汛 汎收汛 汎收汛  弛  汎收汛 汎收汛  弛  汎收汛 汎收汛 汎收汛  弛  汎收汛 汎收汛  弛");
	puts("弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛");
	puts("弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛   弛");
	puts("汎收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收朴收收收汛");
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
	printf("弛 弛");
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
