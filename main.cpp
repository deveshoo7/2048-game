/*Hi guys, we hope you like our 2048 game
 *it was made by Devesh Sharma and Sunny
 *share your high-scores with us on our git-hub ID:
 */
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class newGame{
private:
    int mat[4][4]{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int score;
public:
    newGame(){
        cout<<"Enjoy  :)";
        score=0;
        random_spawn();
    }

    //to return a random number between 0 and 3(including)
    int randomNum(){
        return (rand() % 4);
    }

    //returns either 2 or 4
    int randomDev(){
        d:
        int n = (rand()%5);
        if(n==2||n==4){
            return n;
        }
        else{
            goto d;
        }
    }

    //spawns a random 2 or 4 in the matrix
    void random_spawn(){

        aga:
            int b= randomNum();
            int a= randomNum();
            if(mat[a][b]==0){
                mat[a][b]=randomDev();
            }
            else{
                goto aga;
            }
    }

    //to print each iteration of the matrix and the choosing screen
    void printMat(){
        random_spawn();
        cout<<"Score: "<<score;
        cout<<endl
                <<"-----------------------------------------------------------------\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<"|\t"<<mat[i][j]<<"\t|";
            }
            cout<<endl
                <<"-----------------------------------------------------------------\n";
        }
        cout<<endl
            <<"choose the move(a-left,w-up,s-down,d-right):";
       ListenKey();
    }

    //to take input from user to perform a move
    void ListenKey(){
        top:
        char Key;
        cin>>Key;
        int n = (int)Key;
        if(n == 97 || n == 119 || n == 115 || n == 100){
            movee(n);
        }
        else{
            cout<<"ERROR-757:enter valid number(a-left,w-up,s-down,d-right)";
            goto top;
        }
    }
    // Key != 'a' || Key != 'w' || Key != 's' || Key != 'd'
    //n != 97 || n != 119 || n != 115 || n != 100
    //tell which move is being performed
    void movee(int l){
        switch(l){
            case 97: left_move();
                break;
            case 119: up_move();
                break;
            case 115: down_move();
                break;
            case 100: right_move();
                break;
        }
    }

    //function to move all the elements of the grid in the left direction
    void left_move(){
        int n=4;
        for(int i=0;i<4;i++){
            while(n--){
                for(int j=0;j<3;j++){
                        if(mat[i][j]==0){
                            mat[i][j]=mat[i][j+1];
                            mat[i][j+1]=0;
                        }
                        else if(mat[i][j]==mat[i][j+1]){
                            mat[i][j]+=mat[i][j+1];
                            mat[i][j+1]=0;
                            score+=mat[i][j];
                        }
                }
            }
            n=4;
        }
        system("cls");
        printMat();
     }

     //function to move all the elements of the grid in the right direction
     void right_move(){
        int n=4;
        for(int i=0;i<4;i++){
            while(n--){
                for(int j=3;j>=1;j--){
                        if(mat[i][j]==0){
                            mat[i][j]=mat[i][j-1];
                            mat[i][j-1]=0;
                        }
                        else if(mat[i][j]==mat[i][j-1]){
                            mat[i][j]+=mat[i][j-1];
                            mat[i][j-1]=0;
                            score+=mat[i][j];
                        }
                }
            }
            n=4;
        }
        system("cls");
        printMat();
    }

    //function to move all the elements of the grid in the up direction
    void up_move(){
        int n=4;
        for(int j=0;j<4;j++){
            while(n--){
                for(int i=0;i<3;i++){
                        if(mat[i][j]==0){
                            mat[i][j]=mat[i+1][j];
                            mat[i+1][j]=0;
                        }
                        else if(mat[i][j]==mat[i+1][j]){
                            mat[i][j]+=mat[i+1][j];
                            mat[i+1][j]=0;
                            score+=mat[i][j];
                        }
                }
            }
            n=4;
        }
        system("cls");
        printMat();
    }
    //function to move all the elements of the grid in the down direction
    void down_move(){
        int n=4;
        for(int j=0;j<4;j++){
            while(n--){
                for(int i=3;i>=1;i--){
                        if(mat[i][j]==0){
                            mat[i][j]=mat[i-1][j];
                            mat[i-1][j]=0;
                        }
                        else if(mat[i][j]==mat[i-1][j]){
                            mat[i][j]+=mat[i-1][j];
                            mat[i-1][j]=0;
                            score+=mat[i][j];
                        }
                }
            }
            n=4;
        }
        system("cls");
        printMat();
    }
};

int main()
{
    newGame G;
    G.printMat();
    return 0;
}
//-*-*-*-*-*-*-*
