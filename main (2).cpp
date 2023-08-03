//by Rajveer Gill

#include <iostream>
#include <iomanip>
using namespace std;

void printTable (char[3][3]);
char CheckWinner(char[3][3]);
bool boardFull(char board[3][3]);
bool boardFull(char board[3][3]);

int main(){
    bool gameOver = false;
    bool full=false;
    int count = 0;
    char winner = 'n';
    char board[3][3];
    //this fills the board with *
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            board[x][y] = '*';
        }
    }
    //this while loop repeats in order for multiple turns occur and It
    //keeps going until a player wins or the board is full
    while(gameOver == false){
        printTable(board);
        int userRow;
        int userCol;
        int check = count%2;
        char player;
        //this part of the code checks who's turn it is
        if (check == 0){
            cout << "It is player 1 turn!\n";
            player = 'X';
        }
        
        else{
            cout << "It is player 2 turn!\n";
            player='O';
        }
        
        //this part of the code checks where the player will put their mark
        cout<<"Enter the row you wanna place the letter\n";
        cin>>userRow;
        cout<<"Enter the column you wanna place the letter\n";
        cin>>userCol;
        userRow--;
        userCol--;
        board[userRow][userCol] = player;
        count++;
        winner = CheckWinner(board);
        full = boardFull(board);
        //this part of the code checks if the board is full or a player won
        if (winner != 'n'){
            gameOver = true;
        }
        if (full == true){
            gameOver = true;
        }
    }
    //this part of the code outputs who won
    if (winner == 'n'){
        cout << "It was a tie.\n";
    }
    else if(winner == 'X'){
        cout << "Player 1 won!\n";
    }
    else if(winner == 'O'){
        cout << "Player 2 won!\n";
    }
    

    return 0;
}

//this function prints the board
void printTable (char board[3][3]){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

//this function checks if a winner exists
char CheckWinner(char board[3][3]){
    char check = 'n';
    //this checks every row for a winner
    for(int row =0; row<3; row++){
        int countX = 0;
        int countO = 0;
        for (int col = 0; col < 3; col++){
            if (board[row][col] =='X'){
                countX++;
            }
            if (board[row][col] == 'O'){
                countO++;
            }
        }
        if (countX == 3){
            check = 'X';
        }
        if (countO == 3){
            check = 'O';
        }
    }
    
    //this checks every col for a winner
    for(int col = 0; col < 3; col++){
        int countX = 0;
        int countO = 0;
        for(int row =0; row<3; row++){
            if (board[row][col] =='X'){
                countX++;
            }
            if (board[row][col] == 'O'){
                countO++;
            }
        }
        if (countX == 3){
            check = 'X';
        }
        if (countO == 3){
            check = 'O';
        }
    }
    
    //this loop checks a left to right diagonal for a winner
    int countX = 0;
    int countO = 0;
    for (int spot = 0; spot < 3; spot++){
        if(board[spot][spot] == 'X'){
            countX++;
        }
        if(board[spot][spot] == 'O'){
            countO++;
        }
        if (countX == 3){
            check = 'X';
        }
        if (countO == 3){
            check = 'O';
        }
    }
    
    //this loop checks a right to left diagonal
    countX = 0;
    countO = 0;
    for (int spot = 0; spot < 3; spot++){
        if(board[spot][2 - spot] == 'X'){
            countX++;
        }
        if(board[spot][2 - spot] == 'O'){
            countO++;
        }
        if (countX == 3){
            check = 'X';
        }
        if (countO == 3){
            check = 'O';
        }
    }
    
    return check;
    
}

//this function checks if the board is full
bool boardFull(char board[3][3]){
   bool check=false;
   int count=0;
   for(int row =0; row<3; row++){
        for (int col = 0; col < 3; col++){
            if(board[row][col]!='*'){
                count++;
            }
        }
   }
    if (count==9){
        check=true;
        
    }
    return check;
}



