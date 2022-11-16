#include <iostream>

using namespace std;

const int PLAYER_ONE=1;
const int PLAYER_TWO=2;

int currentPlayer=PLAYER_ONE;

char gameBoard[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void printBoard(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<gameBoard[i][j];
            if(j!=2)
                cout<<"|";
        }
        if(i!=2)
            cout<<endl<<"------"<<endl;
    }

    cout<<endl<<endl;

}

void switchTurn(){

    if(currentPlayer==PLAYER_ONE){
        currentPlayer=PLAYER_TWO;
    }else{
        currentPlayer=PLAYER_ONE;
    }

}

void posToIndex(int pos, int &x,int &y){

    switch(pos){
        case 1: x=0;
                y=0;
                return;

        case 2: x=0;
                y=1;
                return;

        case 3: x=0;
                y=2;
                return;

        case 4: x=1;
                y=0;
                return;

        case 5: x=1;
                y=1;
                return;
        
        case 6: x=1;
                y=2;
                return;

        case 7: x=2;
                y=0;
                return;
        
        case 8: x=2;
                y=1;
                return;

        case 9: x=2;
                y=2;
                return;

        default : x=-1;
                  y=-1;
                return;
        
    }

}

bool isValidIndex(int x,int y){
    if(x<0 && x>2 && y<0 && y>2)
        return false;
    
    return gameBoard[x][y]==' ';

}

void playTurn(){
    cout<<"Turn of Player "<<currentPlayer<<endl<<endl;

    char value;
    int x,y,pos;

    if(currentPlayer==PLAYER_ONE){
        value='X';
    }else{
        value='O';
    }

    do{
        cout<<"Enter Empty Position between 1-9"<<endl;
        cin>>pos;
        posToIndex(pos,x,y);
    }while(!isValidIndex(x,y));

    
    gameBoard[x][y]=value;
    printBoard();
}

bool isBoardFull(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(gameBoard[i][j]==' ') return false;
        }
    }
    return true;
}

bool playerWon(){
    // checks rows and coloums
    for(int i=0;i<3;i++){
        if(( (gameBoard[i][0]!=' ') && (gameBoard[i][0]==gameBoard[i][2]) && gameBoard[i][0]==gameBoard[i][1]))
            return true;
        
        if( (gameBoard[2][i]!=' ') && gameBoard[0][i]==gameBoard[1][i] && gameBoard[0][i]==gameBoard[2][i])
            return true;
    }

    // checks diagonals
    if(gameBoard[0][0]!=' ' && gameBoard[0][0]==gameBoard[2][2] && gameBoard[0][0]==gameBoard[1][1] ) 
        return true;
    
    if(gameBoard[0][2]!=' ' && gameBoard[0][2]==gameBoard[2][0] && gameBoard[0][2]==gameBoard[1][1])
        return true;
    

    return false;
}

bool isGameEnded(){

    if(playerWon()){
        cout<<"Player "<<currentPlayer<<" Won ";
        return true;
    }


    if(isBoardFull()){
        cout<<"Board is full, Game ended";
        return true;
    }
    return false;
}

int main(){

    cout<<"Positions are numbered as"<<endl<<
          "1|2|3"<<endl<<
          "------"<<endl<<
          "4|5|6"<<endl<<
          "------"<<endl<<
          "7|8|9"<<endl<<endl;
    
    while(true){   
        playTurn();
        if(isGameEnded()) break;
        switchTurn();
    }
    return 0;
}
