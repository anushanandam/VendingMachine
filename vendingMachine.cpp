//Student Name: Anusha Nandam
//Created on March 12, 2020
//CS 113 Project
/*
This program represents a vending machine. Users will choose the drink they want, enter the amount of money they
are putting in the machine, the program will calculate the amount of change the users get, and the program will subtract
one from the number of the drinks in the machine every time a purchase is made. A message is displayed when the user
selects a sold out drink or when the user chooses invalid input. Arrays are used to represent the options of the vending
machine and a looping menu- structure of the keypad is implemented allowing the users to choose if they would like to
continue using the vending machine or exit. In addition, there is a service technician who has the opportunity to add
beverages, remove beverages, update beverage prices, change the location of the beverage, and truth table values of the
beverage. The changes that the technician makes will take place when the next user comes to use the vending machine.
In this lab, when the users input for their choice is displayed on the screen, the actual binary input signals will be
displayed to represent what the computer reads when letters and numbers and typed into the console.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
enum BEVERAGES { //BEVERAGES is a new data type to define all beverages used in the program
	COKE,
	PEPSI,
	WATER,
	SPRITE,
	ROOT_BEER,
	FANTA,
	LEMONADE,
	MOUNTAIN_DEW
};
void request1(int total_beverages[]); //function prototype
void request2(int total_beverages[]); //function prototype
void request3(double beverage_price[]); //function prototype
void charToBinary(char ch);

int main() {
	int total_beverages[8] = {20,8,1,5,9,12,16,9}; //total beverages initially put into an array
	double beverage_price[8]={2.35,1.95,1.05,1.25,2.25,2.95,3.35,3.45}; //initial beverage prices in an array
	bool C1, C2, C3, O; //Set values for truth table
	char l; //represents letter user will input
	int n; // represents number user will input
	int total_coke =20, total_pepsi =8, total_water=1,total_sprite=5,total_rootbeer=9,total_fanta=12, total_lemonade=16,total_mdew=9; //initializing total number of drinks
	double coke_change, pepsi_change, water_change,sprite_change,rootbeer_change,fanta_change,lemonade_change,mdew_change; //variable type declaration
	int update,updates,truth,request,answer,add,remove,new_beverage;
	double code, m, coke_price=2.35, pepsi_price=1.95, water_price=1.05, sprite_price=1.25, rootbeer_price=2.25, fanta_price=2.95, lemonade_price=3.35,mdew_price=3.45;
	bool coke_C1, coke_C2, coke_C3, pepsi_C1,pepsi_C2,pepsi_C3,water_C1,water_C2,water_C3,sprite_C1,sprite_C2,sprite_C3;
	bool rootbeer_C1, rootbeer_C2, rootbeer_C3, fanta_C1, fanta_C2, fanta_C3, lemonade_C1, lemonade_C2, lemonade_C3,mdew_C1,mdew_C2,mdew_C3;
	char coke_letter = 'A', pepsi_letter= 'A', water_letter= 'A', sprite_letter= 'A', rootbeer_letter= 'B', fanta_letter= 'B', lemonade_letter= 'B', mdew_letter= 'B';
	int coke_number=1, pepsi_number=2, water_number=3, sprite_number=4, rootbeer_number=1, fanta_number=2, lemonade_number=3, mdew_number=4;
	string drinks[] = {"Coke"," Pepsi"," Water"," Sprite"," Root Beer", " Fanta", " Lemonade", " Mountain Dew"};
	char repeat = 'Y'; //initialized to Y because program needs to run at least once before the user decides if they want to repeat
	while (repeat == 'Y') { //while user wants to select options from the vending machine
		cout << "Are you a service technician (1=Yes/0=No)?"<<endl;
		cin >> answer;
			if (answer == 1) { // if it is technician
				cout << "What is the code? (XXXX)#"<<endl;
				cin >> code;
					if (code == 0000) {
						cout << "Here are the current drinks:"<<drinks[0]<<drinks[1]<<drinks[2]<<drinks[3]<<drinks[4] <<drinks[5]<<drinks[6]<<drinks[7]<<endl;
						cout <<"Would you like to:\n 1) Add new beverage \n 2) Remove beverage \n 3) Update beverage price \n 4) Reprogram order pairs for drinks \n 5) Reprogram truth values C1,C2,C3"<<endl;
						cin >> request;
							if (request ==1) { //add new beverages
								request1(total_beverages); //calling function
							}
							else if (request == 2) { //empties chosen beverage
								request2(total_beverages); //calling function
							}
							else if (request == 3) { // changes beverage price
								request3(beverage_price); //calling function
							}
							else if (request ==4) { //alters beverage location
								cout <<"Which beverage ordered pair would you like to update(0-7)?"<<endl;
								cout <<"0:Coke,1:Pepsi,2:Water,3:Sprite,4:Root Beer,5:Fanta,6:Lemonade,7:Mountain Dew"<<endl;
								cin >> updates;
								if (updates ==0){
									cout << "New Letter"<<endl;
									cin >>coke_letter;
									cout<<"New Number"<<endl;
									cin>>coke_number;
								}
								else if (updates ==1){
									cout << "New Letter"<<endl;
									cin >>pepsi_letter;
									cout<<"New Number"<<endl;
									cin>>pepsi_number;
								}
								else if (updates ==2){
									cout << "New Letter"<<endl;
									cin >>water_letter;
									cout<<"New Number"<<endl;
									cin>>water_number;
								}
								else if (updates ==3){
									cout << "New Letter"<<endl;
									cin >>sprite_letter;
									cout<<"New Number"<<endl;
									cin>>sprite_number;
								}
								else if (updates ==4){
									cout << "New Letter"<<endl;
									cin >>rootbeer_letter;
									cout<<"New Number"<<endl;
									cin>>rootbeer_number;
								}
								else if (updates ==5){
									cout << "New Letter"<<endl;
									cin >>fanta_letter;
									cout<<"New Number"<<endl;
									cin>>fanta_number;
								}
								else if (updates ==6){
									cout << "New Letter"<<endl;
									cin >>lemonade_letter;
									cout<<"New Number"<<endl;
									cin>>lemonade_number;
								}
								else if (updates ==7){
									cout << "New Letter"<<endl;
									cin >>mdew_letter;
									cout<<"New Number"<<endl;
									cin>>mdew_number;
								}
							}
							else if (request ==5) { //alters beverage truth values
								cout <<"Which beverage truth values would you like to update(0-7)?"<<endl;
								cout <<"0:Coke,1:Pepsi,2:Water,3:Sprite,4:Root Beer,5:Fanta,6:Lemonade,7:Mountain Dew"<<endl;
								cin >> truth;
									if(truth ==0) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl; // 0=False and 1=True for Bool data type
										cin>>coke_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>coke_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>coke_C3;
									}
									else if(truth ==1) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>pepsi_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>pepsi_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>pepsi_C3;
									}
									else if(truth ==2) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>water_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>water_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>water_C3;
									}
									else if(truth ==3) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>sprite_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>sprite_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>sprite_C3;
									}
									else if(truth ==4) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>rootbeer_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>rootbeer_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>rootbeer_C3;
									}
									else if(truth ==5) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>fanta_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>fanta_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>fanta_C3;
									}
									else if(truth ==6) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>lemonade_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>lemonade_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>lemonade_C3;
									}
									else if(truth ==7) {
										cout <<"New C1 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>mdew_C1;
										cout <<"New C2 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>mdew_C2;
										cout <<"New C3 (Enter 1 for T/Enter 0 for F)"<<endl;
										cin>>mdew_C3;
									}
						}
						//some functions used enumerated data type and these statements are to make it consistent with rest of the program
						total_coke = total_beverages[COKE];
						total_pepsi = total_beverages[PEPSI];
						total_water = total_beverages[WATER];
						total_sprite = total_beverages[SPRITE];
						total_rootbeer = total_beverages[ROOT_BEER];
						total_fanta = total_beverages[FANTA];
						total_lemonade = total_beverages[LEMONADE];
						total_mdew = total_beverages[MOUNTAIN_DEW];

						coke_price = beverage_price[COKE];
						pepsi_price = beverage_price[PEPSI];
						water_price = beverage_price[WATER];
						sprite_price = beverage_price[SPRITE];
						rootbeer_price = beverage_price[ROOT_BEER];
						fanta_price = beverage_price[FANTA];
						lemonade_price = beverage_price[LEMONADE];
						mdew_price = beverage_price[MOUNTAIN_DEW];

						}
						else {
							cout <<"Invalid Code."<<endl; //if the technician enters an inaccurate code
						}
	}
	if (answer ==0) { //the person is a customer

		cout<<"What beverage would you like?"<<endl;
		cout <<"Options- Coke: "<<coke_letter<<","<<coke_number<<" Pepsi: "<<pepsi_letter<<","<<pepsi_number<<" Water: "<<water_letter<<","<<water_number<<" Sprite: "<<sprite_letter<<","<<sprite_number<<" Root Beer: "<<rootbeer_letter<<","<<rootbeer_number<<" Fanta: "<<fanta_letter<<","<<fanta_number<<" Lemonade: "<<lemonade_letter<<","<<lemonade_number<<" Mountain Dew: "<<mdew_letter<<","<<mdew_number<<endl;
		cout <<"Select Letter: ";
		cin>>l; //user inputs letter
		//cout <<"ASCII: " <<(int)l<<endl;
		int l2 = (int)l; //typecast so that the character can be converted to an integer
		cout<<"Binary Input Signals:"<<endl;
		int binary;
		for (binary = 7; binary >=0; binary --) { //decimal to binary conversion
			cout << ((l2 >> binary) & 1);
		}
		cout<<"\nSelect Number: ";
		cin>>n; //user inputs number
		cout<<"Binary Input Signals:"<<endl;
			int binary2;
			int n2 = n;
			n2 = n2+48; //on ASCII table, 48 represents 0
				for (binary2 = 7; binary2 >=0; binary2 --) { //decimal to binary conversion
			cout << ((n2 >> binary2) & 1);
		}
		cout<<"\n";

		if ( l == coke_letter && n==coke_number) {
				if (total_coke != 0) { //ensuring there is coke in the machine
				string bcoke;
                 bcoke= "Coke $" ;
                 bcoke += to_string(coke_price); //since price is int, converting it to a string
                 bcoke.resize(10); //string should be only 10 characters long
                 //cout<<bcoke<<endl;
                 //cout<<"Length: "<< bcoke.length()<<endl;
                 int aa;
                 for(aa=0; bcoke[aa] != 0;aa++) { //for characters in string
					 charToBinary(bcoke[aa]);
				}
				cout <<"Coke: "<<coke_price<<" Enter the amount of money you are inserting"<<endl;

				bool coke_C1,coke_C2,coke_C3,C1,C2,C3 = false; //truth values
				C1 = coke_C1;
				C2 = coke_C2;
				C3 = coke_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==coke_C1 && C2==coke_C2 && C3==coke_C3) { //truth table values agree with beverage
				if ( m < coke_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						coke_change = m -coke_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< coke_change<< endl;
						total_coke --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Cokes Left: "<<total_coke<<endl;
					}
			}
		}
			else { //if the total coke number is 0
				cout <<"Sorry, there is no more Coke."<<endl;
				O = false;
			}
		}
			else if ( l == pepsi_letter && n==pepsi_number) {

				if (total_pepsi != 0) { //ensuring there is pepsi in the machine
					string bpepsi;
                 bpepsi= "Pepsi $" ;
                 bpepsi += to_string(pepsi_price); //since price is int, converting it to a string
                 bpepsi.resize(11); // string should be only 11 characters long
                 cout<<bpepsi<<endl;
                 cout<<"Length: "<< bpepsi.length()<<endl;
                 int bb;
                 for(bb=0; bpepsi[bb] != 0;bb++) {
					 charToBinary(bpepsi[bb]);
					}
				cout <<"Pepsi: "<<pepsi_price<<" Enter the amount of money you are inserting"<<endl;
				bool pepsi_C1,pepsi_C2,C1,C2 = false; //truth values
				bool pepsi_C3,C3 = true;
				C1 = pepsi_C1;
				C2 =pepsi_C2;
				C3 = pepsi_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==pepsi_C1 && C2==pepsi_C2 && C3==pepsi_C3) { //truth table values agree with beverage
				if ( m < pepsi_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						pepsi_change = m -pepsi_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< pepsi_change<< endl;
						total_pepsi --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Pepsi Left: "<<total_pepsi<<endl;
					}
			}
			else { //if the total pepsi number is 0
				cout <<"Sorry, there is no more Pepsi."<<endl;
				O = false;
			}
		}
	}
			else if ( l == water_letter && n==water_number) {

				if (total_water != 0) { //ensuring there is water in the machine
					string bwater;
                 bwater= "Water $" ;
                 bwater += to_string(water_price); //since price is int, converting it to a string
                 bwater.resize(11); // string should be only 11 characters long
                 cout<<bwater<<endl;
                 cout<<"Length: "<< bwater.length()<<endl;
                 int cc;
                 for(cc=0; bwater[cc] != 0;cc++) { //for characters in string
					charToBinary(bwater[cc]);
					}
				cout <<"Water: "<<water_price<<" Enter the amount of money you are inserting"<<endl;
				bool water_C1, water_C3,C1,C3 = false; //truth values
				bool water_C2,C2 = true;
				C1 = water_C1;
				C2 = water_C2;
				C3 = water_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==water_C1 && C2==water_C2 && C3==water_C3) { //truth table values agree with beverage
				if ( m < water_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						water_change = m -water_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< water_change<< endl;
						total_water --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Waters Left: "<<total_water<<endl;
					}
			}
			else { //if the total water number is 0
				cout <<"Sorry, there is no more Water"<<endl;
				O = false;
			}
		}
		}
			else if ( l == sprite_letter && n==sprite_number) {

				if (total_sprite != 0) { //ensuring there is sprite in the machine
					string bsprite;
                 bsprite= "Sprite $" ;
                 bsprite += to_string(sprite_price); //since price is int, converting it to a string
                 bsprite.resize(12); //string should only be 12 characters long
                 cout<<bsprite<<endl;
                 cout<<"Length: "<< bsprite.length()<<endl;
                 int dd;
                 for(dd=0; bsprite[dd] != 0;dd++) { //for characters in string
					charToBinary(bsprite[dd]);
						}
				cout <<"Sprite: "<<sprite_price<<" Enter the amount of money you are inserting"<<endl;
				bool sprite_C1,C1 = false;
				bool sprite_C2, sprite_C3,C2,C3 = true; //truth values
				C1 = sprite_C1;
				C2 = sprite_C2;
				C3 = sprite_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==sprite_C1 && C2==sprite_C2 && C3==sprite_C3) { //truth table values agree with beverage
				if ( m < sprite_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						sprite_change = m -sprite_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< sprite_change<< endl;
						total_sprite --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Sprites Left: "<<total_sprite<<endl;
					}
			}
			else { //if the total sprite number is 0
				cout <<"Sorry, there is no more Sprite."<<endl;
				O = false;
			}
		}
	}
			else if ( l == rootbeer_letter && n==rootbeer_number) {

				if (total_rootbeer != 0) { //ensuring there is rootbeer in the machine
					string brootbeer;
                 brootbeer= "Root Beer $" ;
                 brootbeer += to_string(rootbeer_price); // since price is int, converting it to a string
                 brootbeer.resize(15); //string should only be 15 characters long
                 cout<<brootbeer<<endl;
                 cout<<"Length: "<< brootbeer.length()<<endl;
                 int ee;
                 for(ee=0; brootbeer[ee] != 0;ee++) { //for characters in string
					charToBinary(brootbeer[ee]);
						}
				cout <<"Root Beer: "<<rootbeer_price<<" Enter the amount of money you are inserting"<<endl;
				bool rootbeer_C1,C1 = true;
				bool rootbeer_C2, rootbeer_C3,C2,C3 = false; //truth values
				C1 = rootbeer_C1;
				C2 = rootbeer_C2;
				C3 = rootbeer_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==rootbeer_C1 && C2==rootbeer_C2 && C3==rootbeer_C3) { //truth table values agree with beverage
				if ( m < rootbeer_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						rootbeer_change = m -rootbeer_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< rootbeer_change<< endl;
						total_rootbeer --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Root Beer Left: "<<total_rootbeer<<endl;
					}
			}
			else { //if the total rootbeer number is 0
				cout <<"Sorry, there is no more Root Beer."<<endl;
				O = false;
			}
		}
	}
			else if ( l == fanta_letter && n==fanta_number) {

				if (total_fanta != 0) { //ensuring there is fanta in the machine
					string bfanta;
                 bfanta= "Fanta $" ;
                 bfanta += to_string(fanta_price); // since price is int, converting it to a string
                 bfanta.resize(11); //string should be only 11 characters long
                 cout<<bfanta<<endl;
                 cout<<"Length: "<< bfanta.length()<<endl;
                 int ff;
                 for(ff=0; bfanta[ff] != 0;ff++) { //for characters in string
					charToBinary(bfanta[ff]);
					}

				cout <<"Fanta: "<<fanta_price<<" Enter the amount of money you are inserting"<<endl;
				bool fanta_C1, fanta_C3,C1,C3 = true; //truth values
				bool fanta_C2,C2 = false;
				C1 = fanta_C1;
				C2 = fanta_C2;
				C3 = fanta_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==fanta_C1 && C2==fanta_C2 && C3==fanta_C3) { //truth table values agree with beverage
				if ( m < fanta_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						fanta_change = m -fanta_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< fanta_change<< endl;
						total_fanta --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Fantas Left: "<<total_fanta<<endl;
					}
			}
			else { //if the total fanta number is 0
				cout <<"Sorry, there is no more Fantas."<<endl;
				O = false;
			}
		}
	}
			else if ( l == lemonade_letter && n==lemonade_number) {

				if (total_lemonade != 0) { //ensuring there is lemonade in the machine
					string blemonade;
                 blemonade= "Lemonade $" ;
                 blemonade += to_string(lemonade_price); // since price is int, converting it to a string
                 blemonade.resize(14); //string should be only 14 characters long
                 cout<<blemonade<<endl;
                 cout<<"Length: "<< blemonade.length()<<endl;
                 int gg;
                 for(gg=0; blemonade[gg] != 0;gg++) { //for characters in string
					charToBinary(blemonade[gg]);
						}
				cout <<"Lemonade: "<<lemonade_price<<" Enter the amount of money you are inserting"<<endl;
				bool lemonade_C1, lemonade_C2,C1,C2= true; //truth values
				bool lemonade_C3,C3 = false;
				C1 = lemonade_C1;
				C2 = lemonade_C2;
				C3 = lemonade_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==lemonade_C1 && C2==lemonade_C2 && C3==lemonade_C3) { //truth table values agree with beverage
				if ( m < lemonade_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						lemonade_change = m -lemonade_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< lemonade_change<< endl;
						total_lemonade --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Lemonades Left: "<<total_lemonade<<endl;
					}
			}
			else { //if the total coke number is 0
				cout <<"Sorry, there is no more Lemonade."<<endl;
				O = false;
			}
		}
	}
			else if ( l == mdew_letter && n==mdew_number) {

				if (total_mdew != 0) { //ensuring there is coke in the machine
					string bmdew;
                 bmdew= "Mountain Dew $" ;
                 bmdew += to_string(mdew_price); // since price is int, converting it to a string
                 bmdew.resize(18); //string should be 18 characters long
                 cout<<bmdew<<endl;
                 cout<<"Length: "<< bmdew.length()<<endl;
                 int hh;
                 for(hh=0; bmdew[hh] != 0;hh++) { //for characters in string
					charToBinary(bmdew[hh]);
					}
				cout <<"Mountain Dew: "<<mdew_price<<" Enter the amount of money you are inserting"<<endl;
				bool mdew_C1,mdew_C2,mdew_C3,C1,C2,C3 = true; //truth values
				C1 = mdew_C1;
				C2 = mdew_C2;
				C3 = mdew_C3;
				O = true;

				cin >> m; //user inputs money
				if (C1==mdew_C1 && C2==mdew_C2 && C3==mdew_C3) { //truth table values agree with beverage
				if ( m < mdew_price) { //when user does not put enough money, their money is returned
					cout <<"Money is returned."<<endl;
				}
					else {
						mdew_change = m -mdew_price; //calculate change by subtracting item cost from user input
						cout <<"Change: $ "<< mdew_change<< endl;
						total_mdew --; //decrement the total drink number each time someone makes a purchase
						cout <<"Number of Mountain Dews Left: "<<total_mdew<<endl;
					}
			}
		}
			else { //if the total Mountain Dew number is 0
				cout <<"Sorry, there is no more Mountain Dew."<<endl;
				O = false;
			}
		}

		else {
			cout<<"Invalid Input"<<endl;
		}
	}

		cout << "Would you like to continue? (Y/N)"<<endl;
		// gives the users options to continue their purchase or exit, essentially this option is what creates the looping menu structure
		cin>>repeat;
		/*if the value is Y, the program will repeat because the condition for the while loop is to execute while repeat = Y,
		however, if the value is N, the program will end because the while loop is now false*/
	}
	return (0);
}
void request1(int total_beverages[]) { //takes in user input request and uses an array to see how many drinks were initialized
	int add, new_beverage;
	cout <<"What would you like to add (0-7)?"<<endl;
	cout <<"0:Coke,1:Pepsi,2:Water,3:Sprite,4:Root Beer,5:Fanta,6:Lemonade,7:Mountain Dew"<<endl;
	cin>>add;
	cout <<"How many new beverages do you want to add?"<<endl;
	cin>>new_beverage;
	if (add >= 0 && add<=7) {
		total_beverages[add] +=new_beverage; //add new beverages to the existing number of beverages
		return;
	}
	cout<<"Invalid Input"<<endl;
}
void request2(int total_beverages[]) { //takes in user input request and uses an array to see how many drinks were initialized
	int remove;
	cout <<"What would you like to remove (0-7)?"<<endl;
	cout <<"0:Coke,1:Pepsi,2:Water,3:Sprite,4:Root Beer,5:Fanta,6:Lemonade,7:Mountain Dew"<<endl;
	cin>>remove;
	if (remove >= 0 && remove<=7) {
		total_beverages[remove] =0; //make the beverage number 0 for the chosen beverage
		return;
	}
	cout<<"Invalid Input"<<endl;
}
void request3(double beverage_price[]) { //takes in user input request and uses an array to see drink prices initialized
	int update;
	double new_price;
	cout <<"What would you like to add (0-7)?"<<endl;
	cout <<"0:Coke,1:Pepsi,2:Water,3:Sprite,4:Root Beer,5:Fanta,6:Lemonade,7:Mountain Dew"<<endl;
	cin>>update;
	cout <<"New Price:"<<endl;
	cin >> new_price;
	if (update >= 0 && update<=7) {
		beverage_price[update] =new_price; //update price of beverage
		return;
	}
	cout<<"Invalid Input"<<endl;
}
void charToBinary(char ch) { //converts characters to binary
    int bit;
	for (bit = 7; bit >=0; bit --) { //decimal to binary
			cout << ((ch >> bit) & 1);

	}
	cout <<", /* "<< ch << " */"<< endl;
}
