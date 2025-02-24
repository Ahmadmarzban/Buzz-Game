#include<iostream>
#include <windows.h> 
using namespace std;
void errorPlayer(bool a);
void loading(bool c_l_s, float time);
int errorConfig(int errorCounter);

int main(){
	
	int a, c=0, m;
	bool gamemode;
	cout<<"(Gamemode with reset screen type -> 1),\n(Gamemode without reset screen type -> 0) : ";
	cin>>gamemode;
	system("cls");
	
	loading(1, 0.1);
	
	cout<<"Zarib ra vared konid(HoP = 0): ";
	cin>>m;
	system("cls");
	int errorCounter = 0;
	while(true){
		if( m < 2){
			system("Color 0C");
			cout<<"Invalid Count! ("<<errorCounter<<"/6)\nZarib ra vared konid(HoP=0):";
			cin>>m;
			errorCounter++;
			system("cls");
			errorConfig(errorCounter);
		}else{
			break;
		}	
	}
	
	int t = 1;
	while(true){
		
		if(t==1){
			system("Color 0A");
			cout<<"Player 1: ";
			t=2;
		}else if(t == 2){
			system("Color 0B");
			cout<<"Player 2: ";
			t = 1;
		}
		
		if(gamemode == 1){
			cin>>a;
			system("cls");
		}else{
			cin>>a;
		}
		
		cout<<"--------"<<endl;
		
		if(a == c+1){
			c=a;
			if(a%m==0){
				if(a != 0){
					if(t == 1){
						errorPlayer(1);
					}else if(t == 2){
						errorPlayer(0);
					}
					break;
				}
			}
			
		}else{
			c++;
			if(a!=0){
				if(t == 1){
					errorPlayer(1);
				}else if(t == 2){
					errorPlayer(0);
				}
				break;
			}else if(c%m != 0 && a == 0){
				system("Color 0C");
				cout<<"ERROR!";
				break;
			}
		}
		
	}
}

void errorPlayer(bool a){
	if(a==1){
		system("Color 0C");
		cout<<"Player 2 Lose!"<<endl;
	}else{
		system("Color 0C");
		cout<<"Player 1 Lose!"<<endl;
	}
}

void loading(bool c_l_s, float time){
	
	for(int i=1; i<=2; i++){
		sleep(0.5);
		for(int i=1; i<=5; i++){
			cout<<".";
			_sleep(time*1000);
		}
		if(c_l_s == 1){
			system("cls");
		}
		
		
	}
}

int errorConfig(int errorCounter){
	if(errorCounter==3){
				string shookhi;
				cout<<"Shookhi dari?(are/na)\n:";
				cin>>shookhi;
				if(shookhi == "are"){
					cout<<"Pas mindazamet biroon hal koni";
					exit(0);
				}else if(shookhi == "na"){
					cout<<"Afarin pas dobare dorost bezan";
					loading(0, 0.3);
					system("cls");
				}else{
					system("cls");
					cout<<"Eshtebahe bozorgi kardi!";
					exit(0);
				}
			}
			if(errorCounter==6){
				string shookhi;
				cout<<"dobare miporsam, shookhi dari?(are/na)\n:";
				cin>>shookhi;
				if(shookhi == "are"){
					while(true){
						cout<<"*";
					}
				}else if(shookhi == "na"){
					cout<<"Afarin pas dobare dorost bezan";
					loading(0, 0.3);
					system("cls");
					
					cout<<"He he haghete";
					exit(0);
				}else{
					system("cls");
					cout<<"Eshtebahe bozorgi kardi!";
					exit(0);
				}
			}
}
