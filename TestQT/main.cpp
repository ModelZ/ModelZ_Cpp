#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int ch;
float ans[15];
// ans[0] = element or physical atk
// ans[1] = ATK
// ans[2] = SKILL%
// ans[3] = DMG PHY/ELM Bonus%
// ans[4] = Normal ATK Bonus%
// ans[5] = Other ATK Bonus%
// ans[6] = Character LV
// ans[7] = Enemy LV
// ans[8] = Enemy Phy/ELM Resistance Reduction%
// ans[9] = Character Element Type
// ans[10] = Type Of Enemy
// ans[11] = CriDmg
float tdmg;
//main variable
struct Calculation{
    float atk,skMulti,atkBonus,enDmgReduce,enDmgRes,criDmg,enDmgResReduce;
};
typedef struct Calculation dmgCal;
typedef struct {float phyRes;float elmRes;} enRes;
dmgCal stat;
enRes enemyRes;
void line(){
    printf("--------------------------------------\n");
}
enRes enemyResistance(){
    enRes res;
    printf("9. Choose Your Enemy\n");
    printf("--1.Hilichurls\n");
    printf("--2.Baby slimes\n");
    printf("--3.Mitachurl\n");
    printf("--4.Samachurl\n");
    printf("--5.Ruin Guard\n");
    printf("--6.Abyss Mage\n");
    printf("--7.Fatui Skirmisher\n");
    printf("--8.Treasure Hunter\n");
    printf("--9.Stonehide Lawachurl	\n");
    printf("--10.Ruin Hunter\n");
    printf("--11.Cryowhopper\n");
    printf("--12.Fatui Pyro Agent\n");
    printf("--13.Electro Cicin\n");
    printf("Type:");
    scanf("%f",&ans[10]);
    int a = (int)ans[10];
    switch(a){
        case 1:case 2:case 4:case 6:
            res.elmRes=0.1;
            res.phyRes=0.1;
            break;
        case 12:
            res.phyRes=0.1;
            res.elmRes=0.1;
            if(ans[9]==6)res.elmRes=0.5;
            break;
        case 13:
            res.phyRes=0.1;
            res.elmRes=0.1;
            if(ans[9]==3)res.elmRes=0.5;
            break;
        case 11:
            res.phyRes=0.35;
            res.elmRes=0.35;
            break;
        case 10:case 9:
            res.phyRes=0.5;
            res.elmRes=0.1;
            break;
        case 8:
            res.phyRes=-0.2;
            res.elmRes=0.1;
            break;
        case 7:
            res.phyRes=-0.1;
            res.elmRes=0.1;
            break;
        case 5:
            res.phyRes=0.7;
            res.elmRes=0.1;
            break;
        case 3:
            res.phyRes=0.3;
            res.elmRes=0.1;
            break;

    }
    return res;
}

float percentToDecimal(float percent){
    return percent / 100;
}

float enemyResistanceReduction(float enResReductionBonus){
    if(enResReductionBonus<0){
        return 1 - (enResReductionBonus/2);
    }else if(enResReductionBonus>=0.75){
        return 1 / (4 * enResReductionBonus + 1);
    }else return 1 - enResReductionBonus;

}
void question(){
    line();
    do{
        printf("1. Your first normal attack is Elemental or Physical?\n");
        printf("--1.Physical\n");
        printf("--2.Elemental\n");
        printf("Choose:");
        scanf("%f",&ans[0]);
    }while(ans[0]!=1&&ans[0]!=2);

    line();

    printf("2. Type Your ATK (on character stats):");
    scanf("%f",&ans[1]);
    line();



    printf("3. DAMAGE BONUS\n");
    line();
    if(ans[0]==1)
        printf("3.1 Type Your Total Physical Damage Bonus%% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n");
    else
        printf("3.1 Type Your Total Element Damage Bonus%% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n");
    printf("Type:");
    scanf("%f",&ans[3]);
    line();
    printf("3.2 Type Your Total Normal Attack Bonus%% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n");
    printf("Type:");
    scanf("%f",&ans[4]);
    line();
    printf("3.3 Type Your Total Other Attack Bonus%% (not decimal) From (Some Effect from other buff or conditional effect)\n");
    printf("Like : damage increase for picking up Elemental Orbs\n");
    printf("Type:");
    scanf("%f",&ans[5]);
    line();

    printf("4. Type Your Character Level:");
    scanf("%f",&ans[6]);
    line();
    printf("5. Type Your Enemy Level:");
    scanf("%f",&ans[7]);
    line();
    if(ans[0]==1)
        printf("6. Type Your Total Enemy Physical Resistance Reduction Effect%% (non-decimal)\n");
    else
        printf("6. Type Your Total Enemy Element Resistance Reduction Effect%% (non-decimal)\n");
        printf("From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n");
        printf("Type:");
        scanf("%f",&ans[8]);
    line();
    printf("7. Your Element Attack Type\n");
    printf("--1.Wind\n");
    printf("--2.Earth\n");
    printf("--3.Lightning\n");
    printf("--4.Nature\n");
    printf("--5.Water\n");
    printf("--6.Fire\n");
    printf("--7.Frost\n");
    printf("Type:");
    scanf("%f",&ans[9]);
    line();
    enemyRes = enemyResistance();
    line();
    printf("9. Your Critical Damage%% (not decimal)\n");
    printf("Type:");
    scanf("%f",&ans[11]);
    line();
}
void define(){
    stat.atk = ans[1];
    stat.atkBonus = 1 + percentToDecimal(ans[3]+ans[4]+ans[5]);
    stat.enDmgReduce = (ans[6]+100)/(ans[6]+ans[7]+200);
    stat.criDmg = percentToDecimal(100+ans[11]);
    stat.enDmgResReduce = percentToDecimal(ans[8]);
    ans[0]==1?stat.enDmgRes = enemyResistanceReduction(enemyRes.phyRes - stat.enDmgResReduce):stat.enDmgRes = enemyResistanceReduction(enemyRes.elmRes - stat.enDmgResReduce);
}
main(){
    do{

        printf("*************************************\n");
        printf("* Genshin DMG Calculation By ModelZ *\n");
        printf("*************************************\n");
        printf("Credit ==> https://genshin-impact.fandom.com/wiki/Attributes\n");
        printf("---1. Find Tdmg from monster\n");
        printf("---2. Find Skill Multiplier\n");
        printf("Choose:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("This Checker can check only first normal attack only\n");
                question();
                printf("10. Type Your Skill%% of normal attack (decimal)\n");
                printf("Like 32.4%% type 32.4\n");
                printf("Skill%%:");
                scanf("%f",&ans[2]);
                line();



// ans[0] = element or physical atk
// ans[1] = ATK
// ans[2] = SKILL%
// ans[3] = DMG PHY/ELM Bonus%
// ans[4] = Normal ATK Bonus%
// ans[5] = Other ATK Bonus%
// ans[6] = Character LV
// ans[7] = Enemy LV
// ans[8] = Enemy Phy/ELM Resistance Reduction%
// ans[9] = Character Element Type
// ans[10] = Type Of Enemy
// ans[11] = CriDmg
// float atk,skMulti,atkBonus,enDmgReduce,enDmgRes;

            stat.skMulti = percentToDecimal(ans[2]);
            define();

            //Process
                    tdmg = stat.atk * stat.skMulti * stat.atkBonus * stat.enDmgReduce * stat.enDmgRes;

            //Output
            line();
            printf("ATK: %.2f\n",stat.atk);
            printf("SkillMultiplier: %.2f\n",stat.skMulti);
            printf("ATK Bonus Multiplier: %.2f\n",stat.atkBonus);
            printf("Enemy Damage Reduce Multiplier: %.10f\n",stat.enDmgReduce);
            printf("Enemy Damage Resist Multiplier: %.2f\n",stat.enDmgRes);
            printf("Critical Damage: %.2f\n",stat.criDmg);
            printf("TRUE DAMAGE: %.5f\n",tdmg);
            printf("CRITICAL TRUE DAMAGE: %.5f\n",tdmg*stat.criDmg);

                break;
            case 2:
            //variable declaration
            float skillDmgMultiplier;
            int a;
            printf("Find Skill Dmg accurately from not show decimal because exceeds 100%\n");
            question();
            printf("10. Is your damage critical?\n");
            printf("Yes Type 1 No Type 0\n");
            printf("Type:");
            scanf("%d",&a);
            line();
            printf("11. Type your Tdmg u saw from attacking monster\n");
            printf("Type:");
            scanf("%f",&tdmg);
            line();
            define();

            //process
            if(a==1)
            skillDmgMultiplier = tdmg / (stat.atk * stat.atkBonus * stat.enDmgReduce * stat.enDmgRes * stat.criDmg);
            else
            skillDmgMultiplier = tdmg / (stat.atk * stat.atkBonus * stat.enDmgReduce * stat.enDmgRes);

            //Output
            line();
            printf("YOUR SKILL DAMAGE IS %.10f\n",skillDmgMultiplier);
            printf("OR\n");
            printf("YOUR SKILL DAMAGE IS %.10f%%\n",skillDmgMultiplier*100);
            line();
                break;
        }
        printf("Enter to continue.....");
        getch();
        system("cls");
    }while(true);

    return 0;
}
