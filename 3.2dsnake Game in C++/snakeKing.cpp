#include<iostream>
#include<conio.h> //to use functions of getch
#include<Windows.h> //To use the functions of sleep
using namespace std;

enum Direction{STOP =0, LEFT, RIGHT, UP, DOWN};
Direction dir;
bool gameover;
const int height =20;
const int width=20;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100];
int tail_len;

void setup();
void draw();
void input();
void logic();

int main(){
    char start;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"  \t\t     : Snake King :"<<endl;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\tPress 's' to Start : ";
    cin>>start;
    if (start=='s'){
        setup();
        while(!gameover){
            draw();
            input();
            logic();
            Sleep(30);
            //system("cls");
            gameover=true;
        }
    }
    return 0; 
}

void setup(){
    gameover =false;
    dir= STOP;
    headX =width/2;
    headY= height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void draw(){
    system("cls");
    //Upper border
    cout<<"\t\t";
    for(int i=0; i<width-8;i++){
        cout<<"||";
    }
    cout<<endl;

    // for snake, fruit, space, and side border
    for(int i=0; i< height; i++){
        for(int j=0; j<width; j++){
            if(j==0){ //left border
                cout<<"\t\t||";
            }
            if(i== headY && j == headX){ //snake head
                cout<<'O';
            }
            else if(i==fruitY && j==fruitX){  //fruit
                cout<<"*";
            }
            else{   //space, snake tail
                bool print =false;
                for(int k=0; k<tail_len; k++){  //tail
                    if(tailx[k] == j && taily[k]==i){
                        cout<<'o';
                        print=true;
                    }
                }
                if(!print){ //space
                    cout<<" ";
                }
            }
            if(j==width -1){ //right border
                cout<<"||";
            }
        }
        cout<<endl;
    }
    cout<<"\t\t"; //Lower border
    for(int i=0; i<width-8;i++){
        cout<<"||";
    }
    cout<<endl;
    cout<<"\t\t\tScore :"<<score<<endl;
}
void input(){

}
void logic(){

}