#include "ModelZ_RPG.h"
#include "iostream"
#include "string"
#include "gamesystem.cpp"

using namespace std;
using namespace GameSystem;


int main(){

    //Add gacha shop
   // gacha_storage();


    //
    //Test Command Here
    //
/*
//	lv=1;
    invasion[0]=100;
    invasion[1]=100;
    invasion[2]=100;
    invasion[3]=100;
    invasion[4]=100;
    atk = 100;
    def = 1000000;
    hp = 10;
    money = 10000000;
    sk_crich=25;
    sk_evach=75;
    sk_cripo=3;
    clas=2;
    sex=1;
    battle(1);
    atk = 100;
    battle(2);
    atk = 300;
    battle(3);
    atk = 500;
    battle(4);
    atk = 1000;
    battle(5);*/

    //
    //
    //
    srand(time(NULL));

    //
    logo();
    do{
        text("--1.Play Game\n--2.Options\n--3.Exit");
        text("\nChoose:");
        scanf("%c",s);
    }while(s[0]!='1'&&s[0]!='2'&&s[0]!='3');

    switch(s[0]){
        case '1':
            newgame();
        do{
            cls();
            status();
            menu();


            switch(ch){

                case 1: //1.Shop

                        cls();
                        logo();
                        shop();
                    do{
                        upgrade();
                        Sleep(100);
                        if(sh != 7){
                            cls();
                            shopfast();
                        }
                    }while(sh != 7);
                    cls();
                    break;
                case 2: //2.Adventure
                do{
                    cls();
                    logo();
                    advt();

                    switch(ad){ //Choose Adventure
                        case 1 :

                            battle(ad);
                            cls();
                        break;
                        case 2 : case 3: case 4: case 5:
                        if(kill[ad-2]){ //Check previous boss was killed
                            battle(ad);
                            cls();
                        }else{
                            text("Locked!! Boss ");printf("[%s]",bossname[ad-2]);text(" is not killed\n");
                            Sleep(1000);
                        }

                            break;

                    }

                }while(ad != 0);
                cls();



                    break;
                case 3: //3.skill
                    cls();
                    skill();
                    cls();
                    break;
                case 4: //4.Gacha
                break;
                case 5: //5.Equipment
                    break;
                case 6: exit(0); //5.Exit
            }

        }while(true);
            break;
        case '2':break;
        case '3':exit(0);break;
    }

}






