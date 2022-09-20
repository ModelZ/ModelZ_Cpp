//Guessnum By ModelZ
//You can play 5+ ages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int start,dif=1,guess_time=0,lv=1,shield=1;
long ans,guess;
bool detect=false;

long diff(int choose,int lv);
bool detector(int guess,int num_detect,long ans,int * shield);
void moved(long * ans,int dif);


int main(){
	srand(time(NULL));
	printf("******************************\n");
	printf("* Welcome To Number Guessing *\n");
	printf("******************************\n");
	do{
		printf("Press 1 to play:");
		scanf("%d",&start);		
	}while(start != 1);



do{

	do{
		printf("******************************\n");
		if(lv==2){
			printf("******************************\n");
			printf("This Level and Higher Level has Guessing detector that can reset number\n");
			printf("Your shield can evade detector\n");
			printf("Be careful!!! Before you guess the number\n");
			printf("******************************\n");
	
		}
		
		if(lv==4){
			printf("******************************\n");
			printf("From Level 4-5 has the Number Changer that can move the number in distance\n");
			printf("The Number Changer will active when you guess every 5 times\n");
			printf("The Effect make you confuse the number for guessing\n");
			printf("******************************\n");
		}
		
		ans = diff(dif,lv);
		int power = dif - 1,num_detect;
		if(lv>=2){
			int base[5]={1,3,5,10,20};
			num_detect = base[lv-2]*pow(10,power); 
			printf("Normal detector +-%d\n",num_detect);		
		}
	
	
	
		printf("******************************\n");	
		
			do{
				printf("Shield: %d\n",shield);
			//	printf("%d\n",ans);	
				printf("Guess:");
				scanf("%ld",&guess);
				guess_time++;
				
				if(lv>=2){
					detect = detector(guess,num_detect,ans,&shield);
					if(detect){
						printf("You lose the detector has captured!!\n");
						printf("Answer is : %d\n",ans);
						printf("******************************\n");	
						shield += 2;
						ans = diff(dif,lv);
	
					}
				}
				
				if(lv>=4 && guess_time % 5 == 0){	
					moved(&ans,dif);
				}
			
			if(detect != true){
				if(guess > ans){
					printf("Your Guessing > Answer\n");
					printf("******************************\n");
				}else if(guess < ans){
					printf("Your Guessing < Answer\n");
					printf("******************************\n");
				}else{
					printf("You win\n");
					printf("Your Guessing : %d\n",guess_time);
					printf("You got 2 shield\n");
					shield += 2;
					lv++;
					guess_time = 0;
					
					printf("******************************\n");
				}			
			}	
	
						
			}while(guess != ans);
			
		}while(lv != 6);
	lv = 1;	
	dif++;
	
}while(dif != 6);
	
}
long diff(int choose,int lv){
	long randnum;
	switch(choose){
		case 1:
		printf("Difficuty:Easy lv %d \n",lv); 
		randnum = 1 + rand() % 100; //1-100
		break;
		case 2:
		printf("Difficuty:Normal lv %d\n",lv); 
		randnum = 1 + rand() % 1000; //1-1000
		break;
		case 3:
		printf("Difficuty:Hard lv %d \n",lv);  
		randnum = 1 + rand() % 10000; //1-10000
		break;
		case 4:
		printf("Difficuty:Insane lv %d \n",lv);  
		randnum = 1 + rand() % 100000; //1-100000
		break;
		case 5:
		printf("Difficuty:Expert lv %d \n",lv);  
		randnum = 1 + rand() % 1000000; //1-1000000
		break;
	}
	return randnum;
	
}

bool detector(int guess,int num_detect,long ans,int * shield){
	int i;
	for(i=1;i<=num_detect;i++){
		if(ans+i == guess || ans-i == guess){
			if(*shield != 0){
				printf("Your Shield is preventing the detection!!\n");
				*shield = *shield - 1;
			}else{
				return true;
			}
			
		}
	}
	return false;
}

void moved(long * ans,int dif){
	int move = pow(10,dif-1);
	short gacha = 1 + rand() % 10;
	printf("The number has been moved for %d\n",move);
	if(gacha > 5){
		*ans = *ans + move;
	}else{
		*ans = *ans - move;
	}
}





