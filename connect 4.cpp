
#include <iostream>
using namespace std;
int arr[50];


	//Function to print a board.
	void printBoard(char** board, int width, int height) {
	cout << endl;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			cout << board[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	}





//Function to insert tokens.
bool insert(char** arr1,int height,char c,int x){
//To assure that user should not be able to enter value for the height +1 time in the same column checking that current column where user want to enter input id filled or not. The maximum inputs in one column is 6 means upto 5 indexes. now if user enter same column for the 7th time it will not take input and if condition wil fail.
 if(arr[x]!=height){  
        arr1[(height-1)-arr[x]][x]=c;    //arr[x] k har index par initially 0 value pari hai 
        arr[x]++;              //means arr[x] ab filled hai ta k user dobara na input kar sake udhar hi
        return true;
    }
    return false;            //when it will return false to playconnect4 function that function will show the user that column is filled. choose another column.
}





//Functio to check that which user wins.
bool isWinning(int width,int height,char **board,char c){
int count=0;
    // Check horizontal
   // It will check every cell horizontally like it move like [0][0] then [0][1] then [0][2] and so on. Then on i=1 it will be like [1][0] then [1][1] and so on.
    for (int i = 0; i < height; i++)
    {
        count = 0;
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] == c)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == 4)
            {
                cout << "Player " << c << " wins!" << endl;
                return true;
            }
        }
    }
    
			    // Check vertical
			   // It will check every cell vertically like it will move like [0][0] then [1][0] then [2][0] and so on. Then on j=1 it will be like [0][1] then [1][1] then [2][1] and so on.
			    for (int j = 0; j < width; j++)
			    {
				count = 0;
				for (int i = 0; i < height; i++)
				{
				    if (board[i][j] == c)
				    {
					count++;
				    }
				    else
				    {
					count = 0;
				    }

				    if (count >= 4)
				    {
					cout << "Player " << c << " wins!" << endl;
					return true;
				    }
				}
			    }
			    

    // Check diagonal (top left to bottom right)
    //it will check every four cell in diagonals. It will move like [0][0]==[1][1]==[2][2]==[3][3] then on j=1 it will be like [0][1]==[1][2]==[2][3]==[3][4] and so on.
    for (int i = 0; i <= height-4; i++) {
    for (int j = 0; j <= width-4; j++) {
        if (board[i][j] == c && board[i+1][j+1] == c && board[i+2][j+2] == c && board[i+3][j+3] == c) {    
            cout << "Player " << c << " wins!" << endl;
                return true;
        }
    }
}


			 // Check diagonal (top right to bottom left)
			//it will check every four cell in diagonals. It will move like [0][3]==[1][2]==[2][1]==[3][0] then on j=4 it will be like [0][4]==[1][3]==[2][2]==[3][1] and so on.
			for (int i = 0; i <= height-4; i++) {
			    for (int j = 3; j < width; j++) {
				if (board[i][j] == c && board[i+1][j-1] == c && board[i+2][j-2] == c && board[i+3][j-3] == c) {
				    cout << "Congratulations :)\nPlayer " << c << " wins the game!\nSee you Soon :)" << endl;
					return true;
				}
			    }
			}
                         return false;              //when no player it will return false.
}






//my main function.
void playConnect4(int width, int height, char** board) {
  // Your implementation here
 cout<<"\nWelcome to connect4 game"<<endl;
 cout<<"Each player must choose a column from 1 to "<<width<<" to put their token. "<<endl;

//printing the connect4 box with '_'
     printBoard(board, width, height);

    
//I will use these variables later on to check that whether any of the players wins or my board is filled or not. If the board is filled or either player wins, below loop will terminate and it will go back from where it is called.
  bool filled,win;
  while ((!filled)&&(!win)) {
    again1:
    cout<<"Player + turn : ";
    int player1; 
    cin>>player1;
    
			if ((player1<1)||(player1>width)){
			cout << "Invalid column. Please enter a number between 1 and " <<width<< "." << endl<<endl;
			goto again1;}
			player1--;  // Convert to 0-based index
    
    
    
    bool check1=insert(board,height,'+',player1);
       if(check1){                         //this condition will run when I get true from insert function
          check1= false;                  //done this so the next while loop will not run which is only for when any column is full.
          printBoard(board,width,height);
        }
        else{
            check1=true;               //this will be true when from the insert function we will get false and we will get false only when insert functio will tell us that current column is full
        }
        while(check1){
            cout<<"This column is full! please,choose another column "<<endl;
            cin>>player1;
            check1=insert(board,height,'+',player1);
            if(check1){
                check1= false;      //agar ye condition chale to matlab ab current loop khatam ho jaye gi because check1 is false now.
            }
            else{
                check1=true;      //agar ye condition chali to matlab hmari current loop dobara chale gi aur user se dobara input le gay jab tak wo sahi input na dal le
            }
        } 
        
        //after every tur of player1 below function will check that if any of the players win or not at the current stage.
        win=isWinning(width,height,board,'+');
        if(win==true){                //if any of the players the current outer while loop will be terminated and function will be given to from where it is called.
           break;}              
                    
   
     again2:  
     cout<<"Player X turn : ";
     int player2;
     cin>>player2;
        
                        if((player2<1)||(player2>width)){
			cout << "Invalid column. Please enter a number between 1 and " <<width<< "."<<endl<<endl;
			goto again2;}
			player2--;  // Convert to 0-based index
        
        
        bool check2=insert(board,height,'X',player2);
        if(check2){
            check2= false;
            printBoard(board,width,height);
        }
        else{
            check2=true;
        }
        while(check2){
            cout<<"This column is full! please,choose another column "<<endl;
            cin>>player2;
            check2=insert(board,height,'X',player2);
            if(check2){
                check2= false;
            }
            else{
                check2=true;
            }
        }

        //after every turn of player2 below function will check that if any of the players win or not at the current stage.
         win=isWinning(width,height,board,'X');
         if(win==true){
           break;}            //if any of the players the current outer while loop will be terminated and function will be given to from where it is called.
                    
        
  filled = true;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (board[i][j] == '_') {
        filled = false;              //if it find any blank space it will exit from this loop.
        break;
      }
    }
  }
 if (filled==true){     //this is for thw while if this is true it will become false in outer while  loop and the program will not run anymore.
     break;}
  
   }
}

int main(){
int width;
int height;
cout<<"\n\nFor Size of the Connect4 board:\nEnter Width : ";
  cin>>width;
  cout<<"Enter Height : ";
  cin>>height;
  
  char** board = new char*[height];        //dynamically allocated a memory 
  for (int i = 0; i < height; i++) {
    board[i] = new char[width];
    for (int j = 0; j < width; j++) {
      board[i][j] = '_';                        //each cell of 2D array will be firstly filled with ' _ '
    }
  }
  

 

  playConnect4(width, height, board);





return 0;
}


					
					
					















