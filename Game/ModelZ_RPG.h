// This file created by ModelZ
// This Code consist of game computing
// You can modify if you want 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
//delaytext for decoration

void delaytext(const char *str,float time_s){ 
	while(*str != '\0'){
		printf("%c",*str);
		Sleep(float(time_s)*1000);
		str++;
	}
}
void text(const char *str){
	delaytext(str,0.03);
}
void textln(const char *str){
	delaytext(str,0.03);
	printf("\n");
}
//loop characters to not messy when coding
void lch(char ch,int n){ 
	char c[n];
	int i=0;
	for(;i<n;i++){
		c[i] = ch;
	}
	c[i] = '\0';

}

void lc(const char ch,int n){
	for(int i=0;i<n;i++){
		printf("%c",ch);
	}	
}

void cls(){
	system("cls");
}

/*char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}*/
int rand100(){
	return 1 + (rand()*rand())%100;
}
int random(int num1,int num2){
	return num1 + (rand()*rand())%(num2-num1+1);
}
int floor5(float dmg){
	float redmg = ceil(dmg);
	dmg -= ceil(dmg);
	if(dmg >= 0.5){
		return redmg+1;
	}else{
		return redmg;
	}
}

