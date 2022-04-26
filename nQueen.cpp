#include<bits/stdc++.h>
using namespace std;
#define N 4

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<< board[i][j]<<" ";
            cout<<endl;
	}
}


bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed then return true */
	if (col >= N)
		return true;

	
	for (int i = 0; i < N; i++) {
		
		if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1))
				return true;
                
			board[i][col] = 0; // BACKTRACK
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
		}
	}

	return false;
}

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout<<"Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// driver program to test above function
int main()
{
	solveNQ();
	return 0;
}

