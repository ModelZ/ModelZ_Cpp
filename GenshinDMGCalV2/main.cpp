#include <iostream>
#include <conio.h>

using namespace std;

class GenshinDMGCal {
        // Variable
        public :
            int ch;
            float ans[15];
            float tdmg;
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

            //main variable
            struct Calculation{
                float atk,skMulti,atkBonus,enDmgReduce,enDmgRes,criDmg,enDmgResReduce;
            };
            typedef struct Calculation dmgCal;
            typedef struct {float phyRes;float elmRes;} enRes;
            dmgCal stat;
            enRes enemyRes;

            // Method

            void line(){
                cout << "--------------------------------------\n";
            }
            enRes enemyResistance(){
                enRes res;
                cout << "9. Choose Your Enemy\n";
                cout << "--1.Hilichurls\n";
                cout << "--2.Baby slimes\n";
                cout << "--3.Mitachurl\n";
                cout << "--4.Samachurl\n";
                cout << "--5.Ruin Guard\n";
                cout << "--6.Abyss Mage\n";
                cout << "--7.Fatui Skirmisher\n";
                cout << "--8.Treasure Hunter\n";
                cout << "--9.Stonehide Lawachurl	\n";
                cout << "--10.Ruin Hunter\n";
                cout << "--11.Cryowhopper\n";
                cout << "--12.Fatui Pyro Agent\n";
                cout << "--13.Electro Cicin\n";
                cout << "Type:";
                cin >> ans[10];
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
                    cout << "1. Your first normal attack is Elemental or Physical?\n";
                    cout << "--1.Physical\n";
                    cout << "--2.Elemental\n";
                    cout << "Choose:";
                    cin >> ans[0];
                }while(ans[0]!=1&&ans[0]!=2);

                line();

                cout << "2. Type Your ATK (on character stats):";
                cin >> ans[1];
                line();



                cout << "3. DAMAGE BONUS\n";
                line();
                if(ans[0]==1)
                    cout << "3.1 Type Your Total Physical Damage Bonus% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n";
                else
                    cout << "3.1 Type Your Total Element Damage Bonus% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n";
                cout << "Type:";
                cin >> ans[3];
                line();
                cout << "3.2 Type Your Total Normal Attack Bonus% (not decimal) From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n";
                cout << "Type:";
                cin >> ans[4];
                line();
                cout << "3.3 Type Your Total Other Attack Bonus% (not decimal) From (Some Effect from other buff or conditional effect)\n";
                cout << "Like : damage increase for picking up Elemental Orbs\n";
                cout << "Type:";
                cin >> ans[5];
                line();

                cout << "4. Type Your Character Level:";
                cin >> ans[6];
                line();
                cout << "5. Type Your Enemy Level:";
                cin >> ans[7];
                line();
                if(ans[0]==1)
                    cout << "6. Type Your Total Enemy Physical Resistance Reduction Effect% (non-decimal)\n";
                else
                    cout << "6. Type Your Total Enemy Element Resistance Reduction Effect% (non-decimal)\n";                
                cout << "From (Artifact,Set Artifact,Weapon Effect,Talent Effect)\n";
                cout << "Type:";
                cin >> ans[8];
                line();
                cout << "7. Your Element Attack Type\n";
                cout << "--1.Wind\n";
                cout << "--2.Earth\n";
                cout << "--3.Lightning\n";
                cout << "--4.Nature\n";
                cout << "--5.Water\n";
                cout << "--6.Fire\n";
                cout << "--7.Frost\n";
                cout << "Type:";
                cin >> ans[9];
                line();
                enemyRes = enemyResistance();
                line();
                cout << "9. Your Critical Damage% (not decimal)\n";
                cout << "Type:";
                cin >> ans[11];
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

};


            // MAIN CODE


          int main(){
                do{

                    //Create Object
                    GenshinDMGCal GS;

                    cout << "*************************************\n";
                    cout << "* Genshin DMG Calculation By ModelZ *\n";
                    cout << "*************************************\n";
                    cout << "Credit ==> https://genshin-impact.fandom.com/wiki/Attributes\n";
                    cout << "---1. Find Tdmg from monster\n";
                    cout << "---2. Find Skill Multiplier\n";
                    cout << "Choose:";
                    cin >> GS.ch;
                    switch(GS.ch){
                        case 1:
                            cout << "This Checker can check only first normal attack only\n";
                            GS.question();
                            cout << "10. Type Your Skill% of normal attack (decimal)\n";
                            cout << "Like 32.4% type 32.4\n";
                            cout << "Skill%:";
                            cin >> GS.ans[2];
                            GS.line();



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

                       GS.stat.skMulti = GS.percentToDecimal(GS.ans[2]);
                       GS.define();

                        //Process
                                GS.tdmg = GS.stat.atk * GS.stat.skMulti * GS.stat.atkBonus * GS.stat.enDmgReduce * GS.stat.enDmgRes;

                        //Output
                        GS.line();
                        cout << "ATK: " << GS.stat.atk << endl;
                        cout << "SkillMultiplier: " << GS.stat.skMulti << endl;
                        cout << "ATK Bonus Multiplier: " << GS.stat.atkBonus << endl;
                        cout << "Enemy Damage Reduce Multiplier: " << GS.stat.enDmgReduce <<endl;
                        cout << "Enemy Damage Resist Multiplier: " << GS.stat.enDmgRes <<endl;
                        cout << "Critical Damage: " <<GS.stat.criDmg << endl;
                        cout << "TRUE DAMAGE: " <<GS.tdmg << endl;
                        cout << "CRITICAL TRUE DAMAGE: " <<GS.tdmg*GS.stat.criDmg << endl;

                            break;
                        case 2:
                        //variable declaration
                        float skillDmgMultiplier;
                        int a;
                        cout << "Find Skill Dmg accurately from not show decimal because exceeds 100%\n";
                        GS.question();
                        cout << "10. Is your damage critical?\n";
                        cout << "Yes Type 1 No Type 0\n";
                        cout << "Type:";
                        cin >> a;
                        GS.line();
                        cout << "11. Type your Tdmg u saw from attacking monster\n";
                        cout << "Type:";
                        cin >> GS.tdmg;
                        GS.line();
                        GS.define();

                        //process
                        if(a==1)
                        skillDmgMultiplier = GS.tdmg / (GS.stat.atk * GS.stat.atkBonus * GS.stat.enDmgReduce * GS.stat.enDmgRes * GS.stat.criDmg);
                        else
                        skillDmgMultiplier = GS.tdmg / (GS.stat.atk * GS.stat.atkBonus * GS.stat.enDmgReduce * GS.stat.enDmgRes);

                        //Output
                        GS.line();
                        cout << "YOUR SKILL DAMAGE IS " << skillDmgMultiplier << endl;
                        cout << "OR\n";
                        cout << "YOUR SKILL DAMAGE IS " << skillDmgMultiplier*100 <<"%\n";
                        GS.line();
                            break;
                    }
                    cout << "Enter to continue.....";
                    getch();
                    system("cls");
                }while(true);

                return 0;
            }

