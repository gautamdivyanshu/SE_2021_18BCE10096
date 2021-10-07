
#include<bits/stdc++.h>
using namespace std;


class Player{
    public:
    string name;
    int x,y;
    public:
    bool mvt(string st){

    }
};

class Game{
    public:
    vector<vector<string>> board;
    vector<Player> playerA,playerB;
    
    
    Game(){
        board.resize(5,vector<string>(5,"-"));
    }
    
    void displayBoard(){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                cout<<board[i][j]<<" \t ";
            }
            cout<<endl;
        }
    }
    
    void placeplayer(string p,int x,int y){
        board[x][y]=p;
    }

};


int main(){
    Game g;
    
    string userInput;
    
    g.displayBoard();
    
    cout<<"player1 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        userInput="A-"+userInput;
        g.placeplayer(userInput,4,i);
    }

    cout<<"player2 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        userInput="B-"+userInput;
        g.placeplayer(userInput,0,i);
    }
    int i=1;
    while(1){
        string st;
        cout<<"player " <<i%2<<"Input: ";
        cin>>st;

        g.displayBoard();
        i++;
    }
    g.displayBoard();
    return 0;
}
