#include <iostream>
#include <string>
using namespace std;

class tictactoe{
    private:
        char arr[3][3]={{ ' ',' ' ,' ' },{ ' ', ' ', ' '},{ ' ' ,   ' ',  ' '}};
    public:
        tictactoe(){
            cout<<"this is the layout of the tictactoe game. Enter positions(x,y) accordingly"<<endl;
            cout<< "0,0 | 0,1 | 0,2"<<endl;
            cout<<string(17,'-')<<endl;
            cout<< "1,0 | 1,1 | 1,2"<<endl;
            cout<<string(17,'-')<<endl;
            cout<< "2,0 | 2,1 | 2,2"<<endl;

        }
        void insert(char x , int pos1 ,int pos2){
            char v = x;
            int x1,y1;
            if(arr[pos1][pos2]==' '){
                arr[pos1][pos2] = x;
            }
            else 
            {
                int k = 0;
                for (int i = 0;i<3;i++){
                    for (int j =0;j<3;j++){
                        if (arr[i][j] == ' '){
                            k++;
                        }
                    }
                }
                if (k == 0){
                    cout<<" Game tied... ";
                }
                else{
                    cout<<"Enter a position which has not been filled."<<endl;
                    cout<< k <<"positions are left"<<endl;
                    cout<<"x: ";
                    cin>>x1;
                    cout<<"y: ";
                    cin>>y1;
                    insert(v,x1,y1);
                }
                

            }
            
    }
        void display(){
            for (int i =0; i<3;i++){
                for (int j =0;j<3;j++){
                    if (j != 2){
                        cout<<"  "<<arr[i][j]<<"  |"<<" ";
                    }
                    else{
                        cout<<arr[i][j]<<endl;
                    }
                        
                }
                if (i != 2){
                    cout<< string(19,'-') <<endl;
                }
                
            }
        }
        bool check(){
            for(int i =0; i<3;i++){
                if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][1]!=' '){
                    char w = arr[i][0];
                    cout<<w<<" won!!!!";
                    return false;
                    }

            }
            for(int i =0; i<3;i++){
                if(arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i] && arr[0][i]!=' '){
                    char w = arr[0][i];
                    cout<<w<<" won!!!!";
                    return false;
                    }
                    
            }
            if(arr[1][1]==arr[0][0] && arr[0][0]==arr[2][2]&& arr[0][0]!=' '){
                char w = arr[0][0];
                cout<<w<<" won!!!!";
                return false;
            }
            if(arr[1][1]==arr[0][2] && arr[2][0]==arr[1][1] && arr[0][2]!=' '){
                char w = arr[1][1];
                cout<<w<<" won!!!!";
                return false;
            }
            return true;
        }
        

};

int main(){
    tictactoe t;
    char p1;
    char p2;
    int x , y;
    cout<<"choose....   X or O"<<endl;
    cout<<"player 1: ";
    cin>>p1;
    cout<<"player 2: ";
    cin>>p2;
    int i = 3;
    while(t.check()){
        if (i%2 != 0){
            cout<<"player 1 enter position(x,y)"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;
            t.insert(p1,x,y);
            t.display();
        }
        else{
            cout<<"player 2 enter position(x,y)"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;
            t.insert(p2,x,y);
            t.display();
            }
        i++;
    }
   

    


}

