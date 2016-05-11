#include <iostream>

#include <stdlib.h>     /* srand, rand */

#include <time.h>       /* time */
//x and the Y have been switched
using namespace std;

const int height=31,width=31; // bilo 31

class Maze{

    public:

    char type;

    bool visited;
 };
 class Player{
       public:
              
       int X;
       int Y;
       int goalX;
       int goalY;
       
       };

bool checkState(Maze maze[height][width],int arrayX,int arrayY){

   if(maze[arrayX+1][arrayY].visited==false &&

       maze[arrayX-1][arrayY].visited==false &&

       maze[arrayX][arrayY+1].visited==false &&

       maze[arrayX][arrayY-1].visited==false && arrayX<height)return true;  

   else return false;

}


void initMaze(Maze maze[height][width]){

    for(int i=0;i<height;i++){

    for(int j=0;j<width;j++){

         if(i%2==0 || j%2==0){

           maze[i][j].type='#';

           maze[i][j].visited=false;}

           else{ maze[i][j].type=' ';

                 maze[i][j].visited=true;}

               
           }

           }

    }

     
void showMaze(Maze maze[height][width]){

    for(int i=0;i<height;i++){

    for(int j=0;j<width;j++){

           cout<<maze[i][j].type;

           }

           cout<<endl;

           }

    }

void mazeGenerator(Maze maze[height][width],Player &player){

    int startX,startY;bool startLoop=true;

   int cellNumber=0,random;

   int able=-1;

   int ableX[4],ableY[4],destroyX[4],destroyY[4];

    int arrayX[width*5],arrayY[height*5];                   // bug finding add extra large array

    do{

    startX = rand() % (height-2)+1;

    startY = rand() %(width-2) +1;

    if(maze[startX][startY].type==' '){

      startLoop=false;

      maze[startX][startY].visited=true;                                      

       }

    }while(startLoop==true);

    arrayX[0]=startX;

    arrayY[0]=startY;

    //--------

    while(cellNumber>=0){

        maze[arrayX[cellNumber]][arrayY[cellNumber]].visited=true;

        maze[arrayX[cellNumber]][arrayY[cellNumber]].type=' ';

  /* system("pause");

    system("CLS");

    showMaze(maze);
cout<<"arrayX: "<<arrayX[cellNumber]<<endl;*/


    if(checkState(maze,arrayX[cellNumber]+2,arrayY[cellNumber]) && arrayX[cellNumber]<width){

    able++;

    ableX[able]=arrayX[cellNumber]+2;

    ableY[able]=arrayY[cellNumber];

    destroyX[able]=arrayX[cellNumber]+1;

    destroyY[able]=arrayY[cellNumber];

    }

    if(checkState(maze,arrayX[cellNumber]-2,arrayY[cellNumber]) && arrayX[cellNumber]-2>0){

    able++;

    ableX[able]=arrayX[cellNumber]-2;

    ableY[able]=arrayY[cellNumber];

    destroyX[able]=arrayX[cellNumber]-1;

    destroyY[able]=arrayY[cellNumber];

    }

     if(checkState(maze,arrayX[cellNumber],arrayY[cellNumber]+2) && arrayY[cellNumber]+2<height-1){

    able++;

    ableX[able]=arrayX[cellNumber];

    ableY[able]=arrayY[cellNumber]+2;

    destroyX[able]=arrayX[cellNumber];

    destroyY[able]=arrayY[cellNumber]+1;

}
     if(checkState(maze,arrayX[cellNumber],arrayY[cellNumber]-2) && arrayY[cellNumber]-2>0){

    able++;

    ableX[able]=arrayX[cellNumber];

    ableY[able]=arrayY[cellNumber]-2;

    destroyX[able]=arrayX[cellNumber];

    destroyY[able]=arrayY[cellNumber]-1;

}

    if(able!=-1){

        random=rand()%(able+1);

        cellNumber++;

        arrayX[cellNumber]=ableX[random];

        arrayY[cellNumber]=ableY[random];

        maze[destroyX[random]][destroyY[random]].visited=true;

        maze[destroyX[random]][destroyY[random]].type=' ';

        able=-1;

    }
    else cellNumber--;
    }  

 
        do{
startLoop=true;
    player.X = rand() % (height-2)+1;

    player.Y = rand() %(width-2) +1;

    if(maze[player.X][player.Y].type==' '){

      startLoop=false;

      maze[player.X][player.Y].type='P';                                      

       }
          
    }while(startLoop==true);
    
    do{
startLoop=true;
    player.goalX = rand() % (height-2)+1;

    player.goalY = rand() %(width-2) +1;
    if(maze[player.goalX][player.goalY].type==' '){

      startLoop=false;
      maze[player.goalX][player.goalY].type='G';                                      

       }
          
    }while(startLoop==true);
                                           

    }


int main(){
    Player player;
    srand (time(NULL));
    char input='A';
    Maze maze[height][width];
    bool lvCompleate=false;
    initMaze(maze);
    mazeGenerator(maze,player);
    showMaze(maze);
    //                                     game loop
    
    do{    
            system("CLS");
            showMaze(maze);
            cout<<"input movement: "<<endl;
         cin>>input;
         switch(input){
                       case 'a':if(maze[player.X][player.Y-1].type=='G'){maze[player.X][player.Y].type=' '; player.Y--;maze[player.X][player.Y].type='P';lvCompleate=true; }break;
                       case 'w':if(maze[player.X-1][player.Y].type=='G'){maze[player.X][player.Y].type=' '; player.X--;maze[player.X][player.Y].type='P';lvCompleate=true; }break;
                       case 's':if(maze[player.X+1][player.Y].type=='G'){maze[player.X][player.Y].type=' '; player.X++;maze[player.X][player.Y].type='P';lvCompleate=true; }break;
                       case 'd':if(maze[player.X][player.Y+1].type=='G'){maze[player.X][player.Y].type=' '; player.Y++;maze[player.X][player.Y].type='P';lvCompleate=true; }break;
                               }
         switch(input){
                       case 'a':if(maze[player.X][player.Y-1].type==' '){maze[player.X][player.Y].type=' '; player.Y--;maze[player.X][player.Y].type='P'; }break;
                       case 'w':if(maze[player.X-1][player.Y].type==' '){maze[player.X][player.Y].type=' '; player.X--;maze[player.X][player.Y].type='P'; }break;
                       case 's':if(maze[player.X+1][player.Y].type==' '){maze[player.X][player.Y].type=' '; player.X++;maze[player.X][player.Y].type='P'; }break;
                       case 'd':if(maze[player.X][player.Y+1].type==' '){maze[player.X][player.Y].type=' '; player.Y++;maze[player.X][player.Y].type='P'; }break;
                       default: cin.ignore();cin.clear();cout<<"only wsad "<<endl;
                               }
             
    if(lvCompleate==true){
       lvCompleate=false;
        initMaze(maze);
         mazeGenerator(maze,player);
          showMaze(maze);
          }
           }while(input!='q');
    system("pause");
    return 0;}



