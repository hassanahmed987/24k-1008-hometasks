#include<iostream>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int totalPaths = 0;


bool safe(int path[5][5],int n,int x,int y,int sol[5][5]){
    if(x>=0 && y>=0 && x<n && y<n && path[x][y]==1 && sol[x][y]==0){
        return true;
    }
    return false;
}


void solvemaze(int path[5][5],int n,int x,int y,int sol[5][5]){
    if(x==2 && y==2){
        sol[x][y]=1;
        totalPaths++;
        cout<<"Path: "<<endl;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(safe(path,n,x,y,sol)){
        sol[x][y]=1;
        for(int i=0;i<4;i++){
            solvemaze(path,n,x+dx[i],y+dy[i],sol);
        }
        sol[x][y]=0;
    }

}


int main(){
int path[5][5] = {
  { 1,1,1,0,1},
  {0,1,0,1,1},
  {1,1,1,1,0},
  {0,1,0,1,1},
  {1,1,1,0,1}
};
    int sol[5][5]={0};
    cout<<"Rabbit Paths: "<<endl;
     solvemaze(path, 5, 0, 0, sol);
     cout<<totalPaths<<endl;
     totalPaths=0;

      
     cout<<endl<<"Cat Paths: "<<endl;

     int sol2[5][5]={0};

    solvemaze(path, 5, 4, 4, sol2);
    cout<<totalPaths<<endl;
    cout<<"Intersection Point: ";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(sol[i][j]==1 && sol2[i][j]==1){
                cout<<i<<","<<j;
            }
        }
    }
}
