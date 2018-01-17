#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int i,j,k,col,row,start_row,start_col,max;
    int sum[20];
    start_row=0;
    start_col=0;
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    for(k=0;k<16;k++){
        row=start_row;
        col=start_col;
        for(i=row;i<(row+3);i+2){
            for(j=col;j<(col+3);j++){
                sum[k]+=arr[i][j];
                  }
            col=start_col;
            if(i==row+2)
                sum[k]+=arr[start_row+1][start_col+1];
            }
        if(start_col<4)
            start_col++;
        else{
            start_col=0;
             start_row++;
        }
           
    }
    max=sum[0];
    for(k=1;k<16;k++){
     if(sum[k]>max)
         max=sum[k];
    }
    cout<<endl<<max;
    return 0;
}