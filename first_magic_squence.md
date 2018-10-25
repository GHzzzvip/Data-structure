
/*
 * 幻方构造
 * 首先将所给数字排序
 * 将第一个数字填入首行中间列 
 * 然后向右上方移动填入下个数字 如果越过边界 下个位置为下一列的最下端 或者上一行的最左端
 * 如果下个位置已经填入数字 那么将下个数字填入原始位置的下方
 * 最后判断每一行每一列以及对角线上的数字是否相同
 * 时间复杂度O(nlgn)
 * 
 */



	#include <bits/stdc++.h>
	using namespace std;
	//Magic square
	int magic_square[3][3];
	int arr[9];
	bool make_magic_square() {
    	magic_square[0][1] = arr[0];
    	int x = 0,y = 1;
    	for(int i = 1; i < 9; i++) {
    	    int x1 = x - 1,y1 = y + 1; // x向上y向右;
    	    
    	    if(x1 < 0) x1 = 2;
    	    if(y1 > 2) y1 = 0;
    	    if(magic_square[x1][y1] != 0) x1 = x + 1, y1 = 	y;
    	    
    	    magic_square[x1][y1] = arr[i];
    	    
    	    x = x1, y = y1;
    	}
    	int row0 = magic_square[0][0] + magic_square[0][1] 	+ magic_square[0][2];
    	int row1 = magic_square[1][0] + magic_square[1][1] 	+ magic_square[1][2];
    	int row2 = magic_square[2][0] + magic_square[2][1] 	+ magic_square[2][2];
	
    	int col0 = magic_square[0][0] + magic_square[1][0] 	+ magic_square[2][0];
    	int col1 = magic_square[0][1] + magic_square[1][1] 	+ magic_square[2][1];
    	int col2 = magic_square[0][2] + magic_square[1][2] 	+ magic_square[2][2];
	
    	int xie0 = magic_square[0][0] + magic_square[1][1] 	+ magic_square[2][2];
    	int xie1 = magic_square[0][2] + magic_square[1][1] 	+ magic_square[2][0];
    	
    	if(row0 == row1 && row0 == row2 && row0 == col0 && 	row0 == col1 && row0 == col2 && row0 == xie0 	&& row0 == xie1)
    	    return 1;
    	return 0;
	}	
	int main() {
    	
    	for(int i = 0; i < 9; i++) cin >> arr[i];
    	sort(arr, arr + 9);
    	if(make_magic_square()) {
    	    for(int i = 0; i <= 2; i++) {
    	        for(int j = 0; j <= 2; j++)
    	            cout << magic_square[i][j] << " ";
    	        cout << endl;
    	    }
    	}
    	else {
    	    cout << "无解" << endl;
    	}
    	return 0;
	}