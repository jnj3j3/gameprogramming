#include <stdio.h>
#include <math.h>
#include <windows.h>
int calc_frequency(int octave, int inx){
	double do_scale = 32.7032;
	double ratio = pow(2., 1/12.), temp;
	int i;
	temp = do_scale*pow(2,octave-1);
	for(i = 0;i<inx;i++){
		temp = (int)(temp+0.5);
		temp *= ratio;
	}
	return (int)temp;
}

int main(void){
	int index[] = {0,2,4,5,7,9,11,12};
	int freq[8];
	int i;
	for(i=0;i<8;i++){
		freq[i] = calc_frequency(4,index[i]);
	}
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[5],300);
	Sleep(300);
	Beep(freq[5],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[2],600);
	Sleep(600);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[2],300);
	Sleep(300);
	Beep(freq[2],300);
	Sleep(300);
	Beep(freq[1],600);
	Sleep(600);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[5],300);
	Sleep(300);
	Beep(freq[5],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[2],600);
	Sleep(600);
	Beep(freq[4],300);
	Sleep(300);
	Beep(freq[2],300);
	Sleep(300);
	Beep(freq[1],300);
	Sleep(300);
	Beep(freq[2],300);
	Sleep(300);
	Beep(freq[0],600);
	Sleep(600);
	return 0;
}
