#include<bits/stdc++.h>

using namespace std;

int board[10][10];
int countMoves = 0; 

void knightMove(int x,int y,int moveLeft){
    if(moveLeft==0&&x<10&&y<10&&x>=0&&y>=0){
        countMoves++;
        return;
    }
    
    board[x][y] = 1;
    
    if(x+1>=0&&x+1<10&&y+2>=0&&y+2<10&&board[x+1][y+2]==0)
        knightMove(x+1,y+2,moveLeft-1);
    
    if(y+1>=0&&y+1<10&&x+2>=0&&x+2<10&&board[x+2][y+1]==0)
        knightMove(x+2,y+1,moveLeft-1);
        
    if(x+2>=0&&x+2<10&&y-1>=0&&y-1<10&&board[x+2][y-1]==0)
        knightMove(x+2,y-1,moveLeft-1);
        
    if(x+1>=0&&x+1<10&&y-2>=0&&y-2<10&&board[x+1][y-2]==0)
        knightMove(x+1,y-2,moveLeft-1);
    
    if(x-1>=0&&x-1<10&&y-2>=0&&y-2<10&&board[x-1][y-2]==0)
        knightMove(x-1,y-2,moveLeft-1);
        
    if(x-2>=0&&x-2<10&&y-1>=0&&y-1<10&&board[x-2][y-1]==0)
        knightMove(x-2,y-1,moveLeft-1);
        
    if(x-2>=0&&x-2<10&&y+1>=0&&y+1<10&&board[x-2][y+1]==0)
        knightMove(x-2,y+1,moveLeft-1);
        
    if(x-1>=0&&x-1<10&&y+2>=0&&y+2<10&&board[x-1][y+2]==0)
        knightMove(x-1,y+2,moveLeft-1);
        
}


int main(){
    
    int i,j,n;
    cin>>i>>j>>n;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board[i][j]=0;
        }
    }
    
    knightMove(i,j,n);
    
    cout<<countMoves<<"\n";
    
    return 0;
    
}