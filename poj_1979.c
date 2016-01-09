#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(vector<vector<char> >&matrix, int i, int j, int h, int w, int &result){
	if (matrix[i][j] == '#') return;
	else if (matrix[i][j] == '1')return;//visited
	else{
		result++;
		matrix[i][j] = '1';
		if (j + 1 < w){ dfs(matrix, i, j + 1, h, w,result); }//go right;
		if (i + 1 < h){ dfs(matrix, i + 1, j, h, w,result); }// go down;
		if (j - 1 >= 0){ dfs(matrix, i, j - 1, h, w,result); }// go left;
		if (i - 1 >= 0){ dfs(matrix, i - 1, j, h, w,result); }// go up;
	}
}
int main(){
	int w, h;

	while (cin >> w >> h){
		if (w == 0 && h == 0)break;
		vector<vector<char> >matrix(h, vector<char>(w, '0'));
		int startw, starth;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> matrix[i][j];
				if (matrix[i][j] == '@')
				{
					startw = j;
					starth = i;
				}
			}
		}
		int result = 0;
		dfs(matrix, starth, startw, h, w, result);
		cout << result << endl;



	}
}