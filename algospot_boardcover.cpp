#include <iostream>
#include <string>
#include <vector>
using namespace std;
int c, h, w;

 const int covertype[4][3][2] = {
	{{0,0},{1,0},{0,1}},
{{0,0},{0,1},{1,1}},
{{0,0},{1,0},{1,1}},
{{0,0},{1,0},{1,-1}}
};

bool set(vector<vector<int>> & board, int y, int x, int type, int delta) {
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		const int ny = y + covertype[type][i][0];
		const int nx = x + covertype[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false; // 범위가벗어나거나
		
		else if ((board[ny][nx] += delta) > 1) //겹쳐질 경우

			ok = false;
	}
	return ok;
}

int cover(vector<vector<int>> &board) {
	int y = -1;
	int x = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) 
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
			
		
		if (y != -1)
			break;
	} // 중복을없애기위해 맨위 왼쪽부터찾아줌

	if (y == -1)return 1;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (set(board, y, x,i, 1))
			ret += cover(board);
		set(board, y, x,i, -1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> c;
	//int board[20][20];
	//char bw[20];
	
	for (int i = 0; i < c; i++) {
		cin >> h >> w;
		vector<vector<char>>input;
		vector<vector<int>>board;

		input.assign(h, vector<char>(w));
		board.assign(h, vector<int>(w));
		
		for (int i = 0; i < h; i++) {
			//cin >> bw;
			for (int j = 0; j < w; j++) {
				//if (bw[j] == '#')board[i][j] = 1;
				//else board[i][j] = 0;
				cin >> input[i][j];
				board[i][j] = (input[i][j] == '#') ? 1 : 0;
			}
		}

		cout << cover(board) << endl;
	}

	return 0;
}
//연속된 정수값찾을때 해결방법