

// Game System Processing

namespace GameSystem {


        //Varable Declaration

        char name[100],foe_name[100];

        short clas,sh,ch,ad;

        int atk=1,def=1,hp=10,money=10,invasion[10],sk_ch=1,sk_igdef=0,cp,lv=0,sk_crich=0,sk_evach=1;

        int earn,sex,n_gacha;

        float en_hp,en_atk,en_def,my_hp,my_atk,my_def,baseatk,sk_muti=1.1,sk_cripo=0,pen_en_def=0;

        char s[1];
        int a[6]={0,0,0,0,0,0};
        int n[6]={1,1,1,1,1,1};
        bool boss = false,kill[5] = {false,false,false,false,false},stun=false;

        char bossname[10][20]={"King Of Forest","King Of Sea","King Of Snow","Rhinoceros Beetles","Zomboss"};
        std::string item_name[400],item_type[400];
        std::string user_item;
        bool use_item[400];



        //Method Declaration


        void logo(){
            printf("********************");
            printf("RPG games V3.5 By ModelZ");
            printf("********************");
            printf("\n");
        }
        void newgame(){
            do{
                text("Choose Your Sex\n");
                text("--0.Male has adventage on ATK on Battle x1.25\n");
                text("--1.Female has adventage on DEF on Battle x1.25\n");
                text("Choose:");
                scanf("%d",&sex);
            }while(sex!=0&&sex!=1);
            do{
                text("\nChoose your class:");
                text("\n--Warrior 0 (SKILL:FATAL BLOW)");
                text("\n--Priest 1 (SKILL:HEALING AURA)");
                text("\n--Assassin 2 (SKILL:HIDDEN STRIKE)");
                text("\nChoose:");
                scanf("%d",&clas);
            }while(clas!=0&&clas!=1&&clas!=2);
            text("Enter Name:");
            scanf("%s",name);

            //loading();

        }
        void loading(){
            cls();
            logo();
            delaytext("\nLoading........",0.1);
            delaytext("\n||||||||||||||||||||||||||||||||",0.1);
            printf(" Complete!");
            cls();
        }
        void status(){
            cp=atk+def+(hp/10);
            logo();
            text("Your Data\n");
            text(sex==0?"Sex: Male\n":"Sex: Female\n");
            text("Name: ");printf("%s",name);
            text("\nATK: ");printf("%d",atk); text("     CP: ");printf("%d",cp);
            text("\nDEF: ");printf("%d",def);
            text("\nHP: ");printf("%d",hp);
            text("\nMONEY: ");printf("%d",money);





        }

        void menu(){
            bool out=true;
            do{
                printf("\n**************Menu*************\n");
                text("--1.Shop\n");
                text("--2.Adventure!!\n");
                text("--3.Skill\n");
                text("--4.Gacha\n");
                text("--5.Equipment\n");
                text("--6.Exit Game\n");
                printf("*******************************\n");
                text("Choose:");
                scanf("%d",&ch);
                switch(ch){
                    case 1: case 2: case 3: case 4: case 5: case 6: out=false; break;
                }
            }while(out);
        }
        void shop(){
            printf("----------------SHOP---------------\n");
            text("\nYour Money: ");printf("%d",money);
            text("\n--1.ATK UPGRADE     ");printf("ATK:%d (+%d) Cost %d",atk,n[0],atk*10*n[0]);
            text("\n--2.DEF UPGRADE     ");printf("DEF:%d (+%d) Cost %d",def,n[1],def*10*n[1]);
            text("\n--3.HP UPGRADE      ");printf("HP:%d (+%d) Cost %d",hp,n[2]*10,hp*n[2]);


        /*
            text("\n--4.SKILL UPGRADE 1  ");printf("SKILL CHANCE:%d (+%d) Cost %d",sk_ch,n[3],sk_ch*100*n[3]);
            text("\n--5.SKILL UPGRADE 2  ");printf("SKILL MULTIPLIER:%.1f (+%d) Cost %d",sk_muti,n[4],sk_muti*1000*n[4]);
            if(clas==0){
                text("\n--6.SKILL UPGRADE 3  ");printf("SKILL BREAK DEF:%d (+%d) Cost %d",sk_igdef,n[5],(sk_igdef+1)*250*n[5]);
            }else{
                text("\n--6.SKILL UPGRADE 3  ");printf("SKILL INCREASE DEF:%d (+%d) Cost %d",sk_igdef,n[5],(sk_igdef+1)*250*n[5]);
            }
        */

            text("\n--7.EXIT SHOP");
            printf("\n-----------------------------------\n");

        }
        void shopfast(){
            printf("----------------SHOP---------------\n");
            text("\nYour Money: ");printf("%d",money);
            printf("\n--1.ATK UPGRADE     ATK:%d (+%d) Cost %d",atk,n[0],atk*10*n[0]);
            printf("\n--2.DEF UPGRADE     DEF:%d (+%d) Cost %d",def,n[1],def*10*n[1]);
            printf("\n--3.HP UPGRADE      HP:%d (+%d) Cost %d",hp,n[2]*10,hp*n[2]);

        /*
            printf("\n--4.SKILL UPGRADE 1  SKILL CHANCE:%d (+%d) Cost %d",sk_ch,n[3],sk_ch*100*n[3]);
            printf("\n--5.SKILL UPGRADE 2  SKILL MULTIPLIER:%.1f (+%d) Cost %d",sk_muti,n[4],sk_muti*1000*n[4]);
            if(clas==0){
                text("\n--6.SKILL UPGRADE 3  ");printf("SKILL BREAK DEF:%d (+%d) Cost %d",sk_igdef,n[5],(sk_igdef+1)*250*n[5]);
            }else{
                text("\n--6.SKILL UPGRADE 3  ");printf("SKILL INCREASE DEF:%d (+%d) Cost %d",sk_igdef,n[5],(sk_igdef+1)*250*n[5]);
            }
        */

            printf("\n--7.EXIT SHOP");
            printf("\n-----------------------------------\n");
        }
        void upgrade(){

            text("Choose:");
            scanf("%d",&sh);
            switch(sh){
                case 1:

                    if(money>=atk*10*n[0]){
                        money -= atk*10*n[0];
                        atk+=n[0];
                        a[0]++;
                        if(a[0]==5){
                            a[0]=0;n[0]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }

                    break;

                case 2:
                    if(money>=def*10*n[1]){
                        money -= def*10*n[1];
                        def+=n[1];
                        a[1]++;
                        if(a[1]==5){
                            a[1]=0;n[1]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }
                    break;
                case 3:
                    if(money>=hp*n[2]){
                        money-= hp*n[2];
                        hp+=10*n[2];
                        a[2]++;
                        if(a[2]==5){
                            a[2]=0;n[2]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }
                    break;
                    /*
                case 4:
                    if(money>=sk_ch*100*n[3]){
                        money-= sk_ch*100*n[3];
                        sk_ch+=1*n[3];
                        a[3]++;
                        if(a[3]==5){
                            a[3]=0;n[3]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }
                    break;
                case 5:
                    if(money>=sk_muti*1000*n[4]){
                        money-= sk_muti*1000*n[4];
                        sk_muti+=1*n[4];
                        a[4]++;
                        if(a[4]==5){
                            a[4]=0;n[4]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }
                    break;
                case 6:
                    if(money>=(sk_igdef+1)*250*n[5]){
                        money-= (sk_igdef+1)*250*n[5];
                        sk_igdef+=1*n[5];
                        a[5]++;
                        if(a[5]==5){
                            a[5]=0;n[5]++;
                        }
                        text("Upgrade Complete!\n");
                    }else{
                        text("Cannot Upgrade\n");
                    }
                    break;
                    */
            }
        }

        void advt(){
            printf("\n----------------Adventure---------------");
            printf("\nBoss Appear When Invasion Point Reaches 100 or above");
            text("\n---0.Exit Adventure");
            text("\n---1.Forest  ");printf("Invasion[%d] (CP:2-36)",invasion[0]); if(kill[0]) text(" [Boss has been slain]");
            text("\n---2.Sea  ");printf("Invasion[%d] (CP:10-150)",invasion[1]); if(kill[1]) text(" [Boss has been slain]");
            text("\n---3.Snow  ");printf("Invasion[%d] (CP:30-350)",invasion[2]); if(kill[2]) text(" [Boss has been slain]");
            text("\n---4.Desert  ");printf("Invasion[%d] (CP:48-600)",invasion[3]); if(kill[3]) text(" [Boss has been slain]");
            text("\n---5.Graveyard  ");printf("Invasion[%d] (CP:88-1800)",invasion[4]); if(kill[4]) text(" [Boss has been slain]");
            printf("\n----------------------------------------");
            text("\nChoose:");
            scanf("%d",&ad);
        }

        short enemy(short ad){
            short monster,n;
            char mon[10][6][20]={ // 40 25 15 10 10
                            "rat","bat","lion","tiger","elephant","King Of Forest", //1.Forest
                            "fish","crab","whale","shark","hummerhead","King Of Sea", //2.Sea
                            "penguin","snowman","polarbear","Ice Monster","Frosty","King Of Snow",//3.Snow
                            "Camel","Zebra","Hawk","Ice Monster","Cougar","Rhinoceros Beetles",//4.Desert
                            "Zombie","Walking Eye","Ghost","Leaper","Curse Shrine","Zomboss"//5.Graveyard
                        };
                        monster = rand()%5;

                        //BOSS APPEAR
                        if(invasion[ad-1] >= 100&&!kill[ad-1]){
                            strcpy(foe_name,mon[ad-1][5]);
                            n=6;
                            invasion[ad-1]=0;
                            boss = true;
                        }else

                        if(monster==0){
                            strcpy(foe_name,mon[ad-1][0]);
                            n=1; invasion[ad-1] += 1;
                        }else if(monster==1){
                            strcpy(foe_name,mon[ad-1][1]);
                            n=2; invasion[ad-1] += 2;
                        }else if(monster==2){
                            strcpy(foe_name,mon[ad-1][2]);
                            n=3; invasion[ad-1] += 3;
                        }else if(monster==3){
                            strcpy(foe_name,mon[ad-1][3]);
                            n=4; invasion[ad-1] += 4;
                        }else{
                            strcpy(foe_name,mon[ad-1][4]);
                            n=5; invasion[ad-1] += 5;
                        }


                        return n;

        }


        void tier (int en_cp,int my_cp){
            if(en_cp>= my_cp+10){ //Enemy Very Strong
                text("Threat: Imposible [*****]\n");
            }else if(en_cp >= my_cp+5){ //Enemy Strong
                text("Threat: Insane [****]\n");
            }else if(en_cp >= my_cp+2){ //Enemy Hard
                text("Threat: Hard [***]\n");
            }else if(en_cp >= my_cp-2){ //Enemy Normal
                text("Threat: Normal [**]\n");
            }else if(en_cp >= my_cp-5){ //Enemy Easy
                text("Threat: Easy [*]\n");
            }else{ //Enemy Noobster
                text("Threat: Noobster []\n");
            }
        }


        float atk_system(float atk,float def){

            float tdmg,mutidmg;

            if(def>=0){
                mutidmg = baseatk/(baseatk+def);
            }else{
                mutidmg = 2 - (baseatk/(baseatk+fabs(def)));
            }
            tdmg = mutidmg*atk;

            return tdmg;
        }


        void battle_system(short ad){

            //turn system
            bool turn,def_down=false;short time=0;
            //repeat until hp hero or enemy = 0
                int sk_chr[10];

                bool shield=false; //Boss Shield Skill 3
                short du_shield,du_def_down; //Turn Of Shield Destory
                float shield_pow;
            while( my_hp > 0 && en_hp > 0&& time != 10){



                //Random Skill Chance
                sk_chr[0] = rand100(); //Skill Check1
                sk_chr[1] = rand100(); //Skill Check2
                sk_chr[2] = rand100(); //Skill Check3
                sk_chr[3] = rand100(); //Skill Check4
                sk_chr[4] = rand100(); //Skill Check5
                sk_chr[5] = rand100(); //Skill Check6

                float tdmg,heal;
                if(rand()%5>=2) turn = true; else turn = false; //60% chance

                    //Boss Skill 3 All Turn Not Depend On Attack
                    if(def_down) du_def_down--;
                    if(du_def_down<=0&&def_down){
                        text("Boss Regain Balance!!\n");
                        def_down=false;
                    }
                    if(shield) du_shield--;
                    if(shield&&shield_pow<=0){
                        text("Boss Shield is Broken!!\n");
                        text("Boss is weakening DMG Recieved UP 50% For 5 Turns\n");
                        du_def_down=5;
                        shield=false;
                        def_down=true;
                    }else
                    if(shield&&du_shield>0){
                        text("Boss Shield Duration: ");printf("[%d] ",du_shield);text("Turn\n");
                    }else
                    if(shield&&du_shield<=0){
                        tdmg = atk_system(shield_pow,sex==1?my_def*1.25:my_def);

                            //Before Enemy Explode Attack Skill Method
                            switch(clas){
                                case 2: //Assassin
                                    if(sk_chr[5]<=sk_evach){ // Normal Skill Activated
                                        text("You Evaded Enemy Attack!!\n");
                                        tdmg = 0;
                                    }
                                    break;
                            }
                        my_hp -= tdmg;
                        text("Boss Shield Explodes and You Take ");printf("%.2f ",tdmg);text("Damage\n");
                        text("Your HP: ");printf("%.2f\n",my_hp);
                        shield=false;
                    }else
                    if(sk_chr[4]<=10*(ad-2)&&boss&&ad>=3&&!shield&&!def_down){
                        du_shield = 10;
                        shield_pow = (ad-2)*1000;
                        text("Boss Create Shield That Absorb Damage!!\n");
                        text("Boss Shield: ");printf("[%.2f]\n",shield_pow);
                        text("Boss Shield Duration: 10 Turn\n");
                        shield=true;
                    }




                //Battle System
                if(turn){
                 //My Turn

                    //Before Hero Add Attack Skill Method
                        switch(clas){
                            case 2: //Assassin
                                if(sk_chr[0]<=sk_crich){ // Awaken Skill Activated
                                    text("CRITICAL STRIKE!!\n");
                                    my_atk *= sk_cripo;
                                }
                                break;
                        }


                    baseatk = def_down?(sex==0?my_atk*2.5:my_atk*2):(sex==0?my_atk*1.25:my_atk);
                    tdmg = atk_system(def_down?(sex==0?my_atk*2.5:my_atk*2):(sex==0?my_atk*1.25:my_atk),en_def);

                    //Before Hero Attack Method
                    if(sk_chr[3]<=5*ad&&boss){ //Skill Boss 2
                        text("Boss Evaded Your Attack!!\n");
                        tdmg = 0;
                    }

                    if(shield){
                        shield_pow -= tdmg;
                        text("Shield Absorbs Your Attack For ");printf("%.2f ",tdmg);text("Damage\n");
                        tdmg = 0;
                        text("Shield Power: ");printf("[%.2f]\n",shield_pow);
                    }

                    en_hp -= tdmg;
                    my_atk = atk; // Reset Cri Atk
                    if(!shield){// Boss Skill 3 Shielded

                        if(tdmg<0){
                            text("Enemy absorbed your attack by "); printf("%.2f",fabs(tdmg)); text(" Damage\n");
                        }else{
                            text("You attacked enemy with "); printf("%.2f",tdmg); text(" Damage\n");
                        }

                        text("Enemy HP: ");printf("%.2f\n",en_hp);
                    }


                    //After Hero Attack Skill Methods
                        switch(clas){
                            case 0: //Warrior
                                if(sk_chr[0]<=sk_ch){ //Skill Activated
                                    tdmg = atk_system(sex==0?my_atk*sk_muti*1.25:my_atk*sk_muti,en_def);
                                    en_hp -= tdmg;
                                    if(tdmg<0){
                                        text("Enemy absorbed your Fatal Blow Skill by "); printf("%.2f",fabs(tdmg)); text(" Damage\n");
                                    }else{
                                        text("Release Fatal Blow Skill to enemy with "); printf("%.2f",tdmg); text(" Damage!!!\n");
                                    }
                                    text("Enemy HP: ");printf("%.2f\n",en_hp);
                                    if(sk_igdef != 0){
                                        Sleep(500);
                                        en_def -= sk_igdef;
                                        text("BREAK ENEMY DEF ");printf("%d\n",sk_igdef);
                                        text("Enemy DEF: ");printf("%.2f\n",en_def);
                                        Sleep(500);
                                    }
                                }
                            break;
                            case 1: //Priest
                                if(sk_chr[0]<=sk_ch){ //Skill Activated
                                    heal = my_atk*sk_muti;
                                    my_hp += heal;

                                    text("Release HEALING AURA to heal with "); printf("%.2f",heal); text(" Damage!!!\n");
                                    text("My HP: ");printf("%.2f\n",my_hp);
                                    if(sk_igdef != 0){
                                        Sleep(500);
                                        my_def += sk_igdef;
                                        text("INCREASE MY DEF ");printf("%d\n",sk_igdef);
                                        text("My DEF: ");printf("%.0f\n",my_def);
                                        Sleep(500);
                                    }
                                }
                            break;

                        }


                    if(tdmg != 0)time = 0;
                }else{
                //Enemy Turn

                //Before Enemy Add Attack Skill Method
                        switch(clas){

                        }


                    baseatk = en_atk;
                    tdmg = atk_system(en_atk,sex==1?my_def*1.25:my_def);

                //Before Enemy Attack Skill Method
                        switch(clas){
                            case 2: //Assassin
                                if(sk_chr[1]<=sk_evach){ // Normal Skill Activated
                                    text("You Evaded Enemy Attack!!\n");
                                    tdmg = 0;
                                }
                                break;
                        }

                    my_hp -= tdmg;
                    if(tdmg<0){
                        text("You absorbed enemy attack by "); printf("%.2f",fabs(tdmg)); text(" Damage\n");
                    }else{
                        text("Enemy attacked you with "); printf("%.2f",tdmg); text(" Damage\n");
                    }

                    text("Your HP: ");printf("%.2f\n",my_hp);

                    //Boss Skill Method
                    if(sk_chr[0]<=5*ad&&boss){ //Skill 1 Boss
                            tdmg = atk_system(en_atk*ad*3,sex==1?my_def*1.25:my_def);

                    //Before Boss Use Attack Skill Method
                        switch(clas){
                            case 2: //Assassin
                                if(sk_chr[2]<=sk_crich){ // Normal Skill Activated
                                    text("You Evaded Enemy Attack!!\n");
                                    tdmg = 0;
                                }
                                break;
                        }

                            my_hp -= tdmg;
                        if(tdmg<0){
                            text("You absorbed Boss Curse Skill by "); printf("%.2f",fabs(tdmg)); text(" Damage\n");
                        }else{
                            text("Release Boss Curse Skill with "); printf("%.2f",tdmg); text(" Damage!!!\n");
                        }

                                Sleep(500);
                                my_def -= ad*5;
                                text("BREAK YOUR DEF ");printf("%d\n",ad*5);
                                text("Your DEF: ");printf("%.2f\n",my_def);
                                Sleep(500);
                    }



                    if(tdmg != 0)time = 0;
                }
                time++;	// if still fighting 10 times DRAW
            }
            //Battle Ended
            if(my_hp <= 0){
                text("You lose....\n");
                if(money > earn) money -= earn; else money = 0;
                text("You lose money "); printf("%d",earn); text(" coins\n");
            }else if(en_hp <= 0){
                text("You win!!\n");
                money += earn;
                text("You earned money "); printf("%d",earn); text(" coins\n");
                if(boss){
                    text("Boss has been slain!!\n");
                    kill[ad-1]=true;
                }
            }else{
                text("Draw.....\n");
            }
            boss = false;
            text("\nENTER TO CONTINUE....\n");
            getch();
        }


        void fighting(short ad){

            my_hp = hp;
            my_atk = atk;
            my_def = def;
            text("-----------------");     text("FIGHT");           text("------------------");

            text("\n------You------");    printf("            ");     text("-----Enemy-----\n");
            text("HP: ");printf("%.0f",my_hp);     printf("                     ");     text("HP: "); printf("%.0f\n",en_hp);
            text("ATK: ");printf("%.0f",my_atk);     printf("                     ");      text("ATK: ");printf("%.0f\n",en_atk);
            text("DEF: ");printf("%.0f",my_def);      printf("                     ");     text("DEF: ");printf("%.0f\n",en_def);
            text("--------------------------------------------");printf("\n");
            battle_system(ad);
        }

        void enemy_stat(short ad,short n){

            switch(ad){

                case 1: //1.Forest

                    switch(n){
                        case 1: en_hp = random(5,10);
                                en_def = 0;
                                en_atk = random(1,2);
                                earn = random(1,5);
                                break;
                        case 2: en_hp = random(10,20);
                                en_def = 1;
                                en_atk = random(1,3);
                                earn = random(10,20);
                                break;
                        case 3: en_hp = random(20,35);
                                en_def = random(1,3);
                                en_atk = random(3,5);
                                earn = random(25,50);
                                break;
                        case 4: en_hp = random(30,50);
                                en_def = random(3,5);
                                en_atk = random(5,10);
                                earn = random(50,100);
                                break;
                        case 5: en_hp = random(50,60);
                                en_def = random(5,10);
                                en_atk = random(10,20);
                                earn = random(200,300);
                                break;
                        case 6: en_hp = 200;
                                en_def = 15;
                                en_atk = 20;
                                earn = 1000;
                                break;
                    }
                break;

                case 2: //2.Sea

                    switch(n){
                        case 1: en_hp = random(150,300);
                                en_def = random(10,15);
                                en_atk = random(10,20);
                                earn = random(300,500);
                                break;
                        case 2: en_hp = random(300,500);
                                en_def = random(15,20);
                                en_atk = random(15,25);
                                earn = random(500,1000);
                                break;
                        case 3: en_hp = random(500,1000);
                                en_def = random(25,35);
                                en_atk = random(25,40);
                                earn = random(1000,2000);
                                break;
                        case 4: en_hp = random(800,1500);
                                en_def = random(40,60);
                                en_atk = random(45,65);
                                earn = random(2000,4000);
                                break;
                        case 5: en_hp = random(1200,2200);
                                en_def = random(65,85);
                                en_atk = random(55,75);
                                earn = random(3000,6000);
                                break;
                        case 6: en_hp = 3000;
                                en_def = 100;
                                en_atk = 100;
                                earn = 10000;
                                break;
                    }

                break;

                case 3: //3.Snow

                    switch(n){
                        case 1: en_hp = random(2000,4000);
                                en_def = random(85,125);
                                en_atk = random(95,115);
                                earn = random(5000,7500);
                                break;
                        case 2: en_hp = random(3000,5000);
                                en_def = random(100,150);
                                en_atk = random(120,140);
                                earn = random(7000,10000);
                                break;
                        case 3: en_hp = random(5000,7500);
                                en_def = random(125,175);
                                en_atk = random(140,165);
                                earn = random(10000,15000);
                                break;
                        case 4: en_hp = random(7000,10000);
                                en_def = random(150,200);
                                en_atk = random(165,190);
                                earn = random(15000,22000);
                                break;
                        case 5: en_hp = random(10000,20000);
                                en_def = random(175,225);
                                en_atk = random(180,220);
                                earn = random(25000,40000);
                                break;
                        case 6: en_hp = 30000;
                                en_def = 250;
                                en_atk = 225;
                                earn = 150000;
                                break;
                    }

                break;

                case 4: //4.Desert

                    switch(n){
                        case 1: en_hp = random(20000,40000);
                                en_def = random(200,300);
                                en_atk = random(200,300);
                                earn = random(30000,50000);
                                break;
                        case 2: en_hp = random(30000,50000);
                                en_def = random(250,325);
                                en_atk = random(225,325);
                                earn = random(40000,65000);
                                break;
                        case 3: en_hp = random(45000,60000);
                                en_def = random(300,400);
                                en_atk = random(275,375);
                                earn = random(50000,75000);
                                break;
                        case 4: en_hp = random(50000,75000);
                                en_def = random(350,450);
                                en_atk = random(350,450);
                                earn = random(65000,80000);
                                break;
                        case 5: en_hp = random(70000,100000);
                                en_def = random(400,500);
                                en_atk = random(400,500);
                                earn = random(75000,100000);
                                break;
                        case 6: en_hp = 200000;
                                en_def = 1000;
                                en_atk = 1000;
                                earn = 500000;
                                break;
                    }

                break;

                case 5: //5.Graveyard

                    switch(n){
                        case 1: en_hp = random(150000,300000);
                                en_def = random(1000,1200);
                                en_atk = random(1000,1200);
                                earn = random(100000,150000);
                                break;
                        case 2: en_hp = random(200000,400000);
                                en_def = random(1200,1500);
                                en_atk = random(1200,1500);
                                earn = random(200000,300000);
                                break;
                        case 3: en_hp = random(250000,500000);
                                en_def = random(1500,2000);
                                en_atk = random(1500,2000);
                                earn = random(300000,400000);
                                break;
                        case 4: en_hp = random(350000,650000);
                                en_def = random(1750,2250);
                                en_atk = random(1750,2250);
                                earn = random(500000,600000);
                                break;
                        case 5: en_hp = random(500000,800000);
                                en_def = random(2000,2500);
                                en_atk = random(2000,2500);
                                earn = random(600000,800000);
                                break;
                        case 6: en_hp = 1000000;
                                en_def = 3000;
                                en_atk = 3000;
                                earn = 2500000;
                                break;
                    }

                break;
            }
        }


        void battle(short ad){
            short n,ch,en_cp;

            n=enemy(ad);
            enemy_stat(ad,n);
            printf("--------------Your Enemy--------------\n");
            en_cp=en_atk+en_def+(en_hp/10);
            tier(en_cp,cp);
            text("Monster: ");printf("%s\n",foe_name);
            text("HP: ");printf("%.0f\n",en_hp);
            text("ATK: ");printf("%.0f\n",en_atk);
            text("DEF: ");printf("%.0f\n",en_def);
            printf("-----------------------------------\n");
            if(en_cp >= cp-5){
                text("--1.Fight!\n");
                text("--2.Run!\n");
                text("Choose:");
                scanf("%d",&ch);
                if(ch==1){
                    fighting(ad);
                }else{
                    //run();
                    boss = false;
                }
            }
            else{
                text("You win!!\n");
                money += earn;
                text("You earned money "); printf("%d",earn); text(" coins\n");
                if(boss){
                    text("Boss has been slain!!\n");
                    kill[ad-1]=true;
                }
                boss = false;
            }

        }


        void skill_up(){
            float sk_muti1[10]={1.2,1.5,1.8,2.2,2.6,3.2,3.8,4,4.7,5.5};
            int sk_ch1[10]={1,2,3,4,5,7,9,11,13,15};
            int pay[10]={100,250,400,600,800,1000,1500,2500,3500,5000};

            if(money >= pay[lv]){ // check money
                money -= pay[lv];
                sk_muti = sk_muti1[lv];
                sk_ch = sk_ch1[lv];
                lv++;
            }else{
                text("Cannot Upgrade\n");
            }
        }

        void skill(){
            // skill normal
            float sk_muti1[10]={1.2,1.4,1.6,2.0,2.4,2.8,3.2,3.6,4.0,4.4}; // For Priest and Warrior
            int sk_ch1[10]={1,2,3,4,5,7,9,11,13,15}; // For Priest and Warrior and Assassin
            int pay[10]={100,250,400,600,800,1000,1500,2500,3500,5000}; //Normal Payment
            //skill awaken
            int sk_def[10]={10,15,20,25,40,55,70,85,100,200}; // For Priest and Warrior
            int sk_ch2[10]={20,22,24,26,28,30,32,34,36,40}; // For Priest and Warrior and Assassin
            int sk_crich1[10]={1,2,3,4,5,7,9,12,15,20}; //Assassin
            int pay2[10]={10000,15000,30000,40000,50000,60000,70000,80000,90000,100000}; //Normal Payment
            float sk_muti2[10]={6.0,6.2,6.6,7.0,7.4,7.9,8.4,9.3,10,12}; // For Priest and Warrior
            float sk_cripo1[10]={1.25,1.3,1.35,1.4,1.5,1.6,1.7,1.8,2,3}; //Assassin
            short a;
        do{
            printf("\n***************************Your Skill**************************\n");
            text("Money:");printf("%d\n",money);
            text("LV SKILL:");printf("%d\n",lv);
            switch(clas){ //Normal Skill Now
                case 0: text("\nSKILL: (FATAL BLOW) Has ");printf("%d",sk_ch);text("% Chance to Deal ");printf("%d (x%.2f) ",atk,sk_muti);text("Damage ");
                    break;
                case 1: text("\nSKILL: (HEALING AURA) Has ");printf("%d",sk_ch);text("% Chance to Heal ");printf("%d (x%.2f) ",atk,sk_muti);text("Damage ");
                    break;
                case 2: text("\nSKILL: (HIDDEN STRIKE) Has ");printf("%d",sk_evach);text("% Chance to Evade ");
                    break;
            }

            if(lv>=11){ // Awaken Skill Now
                switch(clas){
                    case 0: text("AND break Enemy DEF ");printf("%d",sk_igdef);
                        break;
                    case 1: text("AND increases My DEF ");printf("%d",sk_igdef);
                        break;
                    case 2: text("AND Add My Cri Chance to ");printf("%d",sk_crich);text("% AND Cri Power ");printf("%d (x%.2f)",atk,sk_cripo);text(" Damage");
                        break;
                }

            }

            printf("\n\n                             |                              \n");
            printf("                             |                              \n");
            printf("                             V                              \n");

            if(lv==10){
                textln("            ||||||||||||SKILL AWAKEN|||||||||||        ");
            }


            if(lv<20){
                if(lv<10){

                    switch(clas){ // Normal Skill Next
                        case 0: text("\nSKILL: (FATAL BLOW) Has ");printf("%d",sk_ch1[lv]);text("% Chance to Deal ");printf("%d (x%.2f) ",atk,sk_muti1[lv]);text("Damage ");
                            break;
                        case 1: text("\nSKILL: (HEALING AURA) Has ");printf("%d",sk_ch1[lv]);text("% Chance to Heal ");printf("%d (x%.2f) ",atk,sk_muti1[lv]);text("Damage ");
                            break;
                        case 2: text("\nSKILL: (HIDDEN STRIKE) Has ");printf("%d",sk_ch1[lv]+1);text("% Chance to Evade ");
                            break;
                    }

                }else{

                    if(lv >= 10){ // Awaken Skill Next

                        switch(clas){
                            case 0:
                                text("\nSKILL: (FATAL BLOW) Has ");printf("%d",sk_ch2[lv-10]);text("% Chance to Deal ");printf("%d (x%.2f) ",atk,sk_muti2[lv-10]);text("Damage ");
                                text("AND break Enemy DEF ");printf("%d",sk_def[lv-10]);
                                break;
                            case 1:
                                text("\nSKILL: (HEALING AURA) Has ");printf("%d",sk_ch2[lv-10]);text("% Chance to Heal ");printf("%d (x%.2f) ",atk,sk_muti2[lv-10]);text("Damage ");
                                text("AND increases My DEF ");printf("%d",sk_def[lv-10]);
                                break;
                            case 2:
                                text("\nSKILL: (HIDDEN STRIKE) Has ");printf("%d",sk_ch2[lv-10]);text("% Chance to Evade ");
                                text("AND Add My Cri Chance to ");printf("%d",sk_crich1[lv-10]);text("% AND Cri Power ");printf("%d (x%.2f) ",atk,sk_cripo1[lv-10]);text("Damage");
                                break;

                        }

                    }
                }



            }else{
                text("\n\n               ***************MAX SKILL***************            \n");
            }

        if(lv<20){
            if(lv<10){
                text("\n\n--1.UPGRADE");printf(" (%d Coins)",pay[lv]);
            }else{
                text("\n\n--1.UPGRADE");printf(" (%d Coins)",pay2[lv-10]);
            }

        }
            text("\n--0.EXIT\n");
            text("Choose:");
            scanf("%d",&a);

        //Upgrading Process

        if(a == 1 && lv<20){
            if(lv<10){
                if(money >= pay[lv]){ // check money
                    text("Upgrade Complete\n");
                    money -= pay[lv];
                    //Skill Upgrade Process//

                    switch(clas){
                        case 0: case 1:  /*Warrior and Priest*/
                            sk_muti = sk_muti1[lv];
                            sk_ch = sk_ch1[lv];
                            break;
                        case 2: sk_evach = sk_ch1[lv]+1; /*Assassin*/
                            break;
                    }

                    //
                    lv++;
                }else{
                    text("Cannot Upgrade\n");
                }
            }else{
                if(money >= pay2[lv-10]){ // check money
                    text("Upgrade Complete\n");
                    money -= pay2[lv-10];
                    //Skill Upgrade Process

                    switch(clas){
                        case 0: case 1: /*Warrior and Priest*/
                        sk_muti = sk_muti2[lv-10];
                        sk_ch = sk_ch2[lv-10];
                        sk_igdef = sk_def[lv-10];
                        break;
                        case 2: /*Assassin*/
                        sk_evach = sk_ch2[lv-10];
                        sk_crich = sk_crich1[lv-10];
                        sk_cripo = sk_cripo1[lv-10];
                        break;
                    }


                    //
                    lv++;
                }else{
                    text("Cannot Upgrade\n");
                }
            }

        }

            cls();

        }while(a!=0);



        }
/*
        void gacha_storage(){

             //Grade S item id array 0-99

                item_name[0]="ModelZ Sabers";item_type[0]="sword";
                item_name[1]="Excalibur";item_type[1]="sword";
                item_name[2]="Glacial Cutlass";item_type[2]="sword";
                item_name[3]="Nebula Blade";item_type[3]="sword";
                item_name[4]="Solaris Katana";item_type[4]="sword";

                item_name[5]="Immune Shield";item_type[5]="shield";
                item_name[6]="Arthur Shield";item_type[6]="shield";
                item_name[7]="Fairy Fortress";item_type[7]="shield";
                item_name[8]="Mythical Shield";item_type[8]="shield";
                item_name[9]="Sigon's Guard";item_type[9]="shield";

            //Grade A item id array 100-199

                item_name[100]="Spartan Sword";item_type[100]="sword";
                item_name[101]="Dao Sword";item_type[101]="sword";
                item_name[102]="Falcata Sword";item_type[102]="sword";
                item_name[103]="Messer Sword";item_type[103]="sword";
                item_name[104]="Ninja Sword";item_type[104]="sword";
                item_name[105]="Bastard Sword";item_type[105]="sword";
                item_name[106]="Claymore Sword";item_type[106]="sword";
                item_name[107]="Fantasy Sword";item_type[107]="sword";
                item_name[108]="Masonic Sword";item_type[108]="sword";
                item_name[109]="Roman Sword";item_type[109]="sword";

                item_name[110]="Spartan Shield";item_type[110]="shield";
                item_name[111]="Dao Shield";item_type[111]="shield";
                item_name[112]="Falcata Shield";item_type[112]="shield";
                item_name[113]="Messer Shield";item_type[113]="shield";
                item_name[114]="Ninja Shield";item_type[114]="shield";
                item_name[115]="Bastard Shield";item_type[115]="shield";
                item_name[116]="Claymore Shield";item_type[116]="shield";
                item_name[117]="Fantasy Shield";item_type[117]="shield";
                item_name[118]="Masonic Shield";item_type[118]="shield";
                item_name[119]="Roman Shield";item_type[119]="shield";

            //Grade B item id array 200-299

                item_name[200]="Pure Sword";item_type[200]="sword";
                item_name[201]="Foe Sword";item_type[201]="sword";
                item_name[202]="Sender Sword";item_type[202]="sword";
                item_name[203]="Knight Sword";item_type[203]="sword";
                item_name[204]="Member Sword";item_type[204]="sword";
                item_name[205]="Coner Sword";item_type[205]="sword";
                item_name[206]="Dead Sword";item_type[206]="sword";
                item_name[207]="Sunrise Sword";item_type[207]="sword";
                item_name[208]="Thief Sword";item_type[208]="sword";
                item_name[209]="Human Sword";item_type[209]="sword";
                item_name[210]="Animal Sword";item_type[210]="sword";
                item_name[211]="Korean Sword";item_type[211]="sword";
                item_name[212]="Yomo Sword";item_type[212]="sword";
                item_name[213]="Unmei Sword";item_type[213]="sword";
                item_name[214]="Omoi Sword";item_type[214]="sword";
                item_name[215]="Standard Sword";item_type[215]="sword";
                item_name[216]="God Sword";item_type[216]="sword";
                item_name[217]="Devil Sword";item_type[217]="sword";
                item_name[218]="Restore Sword";item_type[218]="sword";
                item_name[219]="Cure Sword";item_type[219]="sword";

                item_name[220]="Pure shield";item_type[220]="shield";
                item_name[221]="Foe shield";item_type[221]="shield";
                item_name[222]="Sender shield";item_type[222]="shield";
                item_name[223]="Knight shield";item_type[223]="shield";
                item_name[224]="Member shield";item_type[224]="shield";
                item_name[225]="Coner shield";item_type[225]="shield";
                item_name[226]="Dead shield";item_type[226]="shield";
                item_name[227]="Sunrise shield";item_type[227]="shield";
                item_name[228]="Thief shield";item_type[228]="shield";
                item_name[229]="Human shield";item_type[229]="shield";
                item_name[230]="Animal shield";item_type[230]="shield";
                item_name[231]="Korean shield";item_type[231]="shield";
                item_name[232]="Yomo shield";item_type[232]="shield";
                item_name[233]="Unmei shield";item_type[233]="shield";
                item_name[234]="Omoi shield";item_type[234]="shield";
                item_name[235]="Standard shield";item_type[235]="shield";
                item_name[236]="God shield";item_type[236]="shield";
                item_name[237]="Devil shield";item_type[237]="shield";
                item_name[238]="Restore shield";item_type[238]="shield";
                item_name[239]="Cure shield";item_type[239]="shield";
            //Grade C item id array 300-399
                item_name[300]="A Sword";item_type[300]="sword";
                item_name[301]="B Sword";item_type[301]="sword";
                item_name[302]="C Sword";item_type[302]="sword";
                item_name[303]="D Sword";item_type[303]="sword";
                item_name[304]="E Sword";item_type[304]="sword";
                item_name[305]="F Sword";item_type[305]="sword";
                item_name[306]="G Sword";item_type[306]="sword";
                item_name[307]="H Sword";item_type[307]="sword";
                item_name[308]="I Sword";item_type[308]="sword";
                item_name[309]="J Sword";item_type[309]="sword";
                item_name[310]="K Sword";item_type[310]="sword";
                item_name[311]="L Sword";item_type[311]="sword";
                item_name[312]="M Sword";item_type[312]="sword";
                item_name[313]="N Sword";item_type[313]="sword";
                item_name[314]="O Sword";item_type[314]="sword";
                item_name[315]="P Sword";item_type[315]="sword";
                item_name[316]="Q Sword";item_type[316]="sword";
                item_name[317]="R Sword";item_type[317]="sword";
                item_name[318]="S Sword";item_type[318]="sword";
                item_name[319]="T Sword";item_type[319]="sword";

                item_name[320]="A shield";item_type[320]="shield";
                item_name[321]="B shield";item_type[321]="shield";
                item_name[322]="C shield";item_type[322]="shield";
                item_name[323]="D shield";item_type[323]="shield";
                item_name[324]="E shield";item_type[324]="shield";
                item_name[325]="F shield";item_type[325]="shield";
                item_name[326]="G shield";item_type[326]="shield";
                item_name[327]="H shield";item_type[327]="shield";
                item_name[328]="I shield";item_type[328]="shield";
                item_name[329]="J shield";item_type[329]="shield";
                item_name[330]="K shield";item_type[330]="shield";
                item_name[331]="L shield";item_type[331]="shield";
                item_name[332]="M shield";item_type[332]="shield";
                item_name[333]="N shield";item_type[333]="shield";
                item_name[334]="O shield";item_type[334]="shield";
                item_name[335]="P shield";item_type[335]="shield";
                item_name[336]="Q shield";item_type[336]="shield";
                item_name[337]="R shield";item_type[337]="shield";
                item_name[338]="S shield";item_type[338]="shield";
                item_name[339]="T shield";item_type[339]="shield";
        }

        void gacha_menu(){
            text("-------------------------\n");
            text("      Gacha Shop\n");
            text("-------------------------\n");

            do{
                text("Gacha Armour and Sword\n");
                text("How many time do you gacha?\n");
                text("Once Type[1], Ten Type [10]");
                text("TYPE:");
                cin >> n_gasha;
            }while(n_gacha!=10||n_gacha!=1);


        }
*/




}
