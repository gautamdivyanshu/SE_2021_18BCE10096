#include<bits/stdc++.h>
using namespace std;


struct cord{
    int x,y;
    
};

class Game{
    public:
    vector<vector<string>> board;
    map<string,cord> player[2];
    
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
        g.player[0][userInput].x = i;
        g.player[0][userInput].y = 4;
        g.placeplayer("A-" + userInput,4,i);
    }

    cout<<"player2 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        g.player[1][userInput].x = i;
        g.player[1][userInput].y = 0;
        g.placeplayer("B-" + userInput,0,i);
    }
    g.displayBoard();
    int i=1;
    while(1){
        string st;
        cout<<"player " <<i<<" Input: ";
        cin>>st;
        int a=0,b=0;
        if( (int)(st[1] - '0') == i){
            if(st[st.length() - 1] == 'L'){
              int k = g.player[i][st.substr(0,2)].x;
              if(k == 0){
                cout<<"can't move left";
                continue;
              }
              else{
                a = g.player[i][st.substr(0,2)].x -1;
                b =g.player[i][st.substr(0,2)].y;
                string tmp = g.board[k][b];
                g.board[k][b] = "-";
                g.placeplayer(tmp,a,b);
              }
              
            }
            else if(st[st.length() - 1] == 'R'){
              int k = g.player[i][st.substr(0,2)].x;
              if(k == 4){
                cout<<"can't move right";
                continue;
              }
              else{
                a = g.player[i][st.substr(0,2)].x -1;
                b =g.player[i][st.substr(0,2)].y;
                string tmp = g.board[k][b];
                g.board[k][b] = "-";
                g.placeplayer(tmp,a,b);
              }
            }
            else if(st[st.length() - 1] == 'F'){
              int k = g.player[i][st.substr(0,2)].y;
              if(k == 4){
                cout<<"can't move forward";
                continue;
              }
              else{
                a = g.player[i][st.substr(0,2)].x;
                b =g.player[i][st.substr(0,2)].y+1;
                string tmp = g.board[a][k];
                g.board[a][k] = "-";
                g.placeplayer(tmp,a,b);
              }
            }
            else if(st[st.length() - 1] == 'B'){
              int k = g.player[i][st.substr(0,2)].y;
              if(k == 0){
                cout<<"can't move back";
                continue;
              }
              else{
                a = g.player[i][st.substr(0,2)].x;
                b =g.player[i][st.substr(0,2)].y - 1;
                string tmp = g.board[a][k];
                g.board[k][b] = "-";
                g.placeplayer(tmp,a,b);
              }
            }
            else{
              cout<<"Invalid input"<<endl;
              continue;
            }
        }
        else{
          cout<<"Not your turn "<<i;
          continue;
        }
        g.displayBoard();
        i++;
        i = i%2;
    }
    g.displayBoard();
    return 0;
}
