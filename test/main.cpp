#include <iostream>

using namespace std;

char matrix[200][200];

char temp[200][200];

char target[3][3];

void rotate(int w, int h){
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            temp[i][j] = matrix[199 - j][i];

    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            matrix[i][j] = 0;

    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            matrix[i][j] = temp[i][j + 200 - h];
}


int main(){

    int m,n;
    cin>>m>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>matrix[i][j];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin>>target[i][j];


    for(int i = 0; i < 4; i++){
        rotate(m ,n);
        swap(m, n);
        for(int y = 1; y < n - 1; y++){
            for(int x = 1; x < m - 1; x++){
                bool result = true;
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        if(matrix[y + i - 1][x + j- 1] != target[i][j])
                            result = false;
                if(result)
                    cout<<x + 1<<" "<<y + 1<<endl;
            }
        }
    }

    return 0;
}
