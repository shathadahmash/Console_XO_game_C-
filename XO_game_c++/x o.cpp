#include<iostream>
#include<windows.h>
using namespace std;



string player_one,player_two;
//the matrix i used to store players playing values
char matrix[3][3]={'1','2','3',
                   '4','5','6',
				   '7','8','9'};
				   
char player ='X';

//drow the updated values in the array
void drow(){
	cout<<"----------\n";
	for(int r=0; r<3; r++){
		cout<<"|";
		for(int c=0; c<3; c++){
			cout<<" "<<matrix[r][c]<<" ";
		}
		cout<<"|";
		cout<<endl;
	}
	cout<<"----------\n";
}

// replace player O and X
void replace(){
	char position;
	if(player == 'X'){
	  cout<<"enter your position - Player : ( "<<player_one<<" )  \n";	
	  cin>>position;
	}
	else{
	   cout<<"enter your position - Player : ( "<<player_two<<" )  \n";	
	   cin>>position;
	}
	for(int r=0; r<3; r++){
		for(int c=0; c<3; c++){
			if(matrix[r][c] == position){
				matrix[r][c] = player;
			}
		}
	}
	if(player == 'X'){
		player = 'O';
	}
	else{
		player='X';
	}
}


//check for the winner or equal and if you should countinue playing or stop
char check(){
	int X = 0 , O = 0, counter = 0;
	for(int r=0; r<3; r++){
		for(int c=0; c<3; c++){
			if(matrix[r][c]=='X'){
			X++;
	    	}
			if(matrix[r][c]=='O'){
			O++;
    		}
			if(X==3)
			return'X';
			if(O==3)
			return 'O';
		}
		X=0,O=0;
	}
	
	for(int c=0; c<3; c++){
		for(int r=0; r<3; r++){
			if(matrix[r][c]=='X')
			X++;
			if (matrix[r][c]=='O')
			O++;
			if(X==3)
			return 'X';
			if(O==3)
			return 'O';
		}
		X=0,O=0;
	} 
	
	if(matrix[0][0]=='X'&& matrix[1][1]=='X'&&matrix[2][2]=='X')
	return 'X';
	if(matrix[0][0]=='O'&& matrix[1][1]=='O'&&matrix[2][2]=='O')
	return 'O';
	
	if(matrix[0][2]=='X'&&matrix[1][1]=='X'&&matrix[2][0]=='X')
	return'X';
	if(matrix[0][2]=='O'&&matrix[1][1]=='O'&&matrix[2][0]=='O')
	return'O';
	
	for(int r=0; r<3; r++){
		for(int c=0; c<3; c++){
			if(matrix[r][c]!='X'&& matrix[r][c]!='O')
			counter++;
		}
	}
	if(counter==0)
	return'=';
	
	return'*';
}


int main(){
	cout<<"enter the X player name: ";
	cin>>player_one;
    cout<<"enter the Y player name: ";
	cin>>player_two;
	while(check()=='*'){
   system("cls");
   drow();
   replace();
   check();
}
   drow();
   if(check()=='X'){
   	cout<<"The Winner Is Player : "<<player_one<<" \n";
   }
   else if(check()=='O'){
   	cout<<"The Winner Is Player  "<<player_two<<" \n";
   }
   else if(check()=='='){
   	cout<<"NO Winner";
   }
   return 0;
}