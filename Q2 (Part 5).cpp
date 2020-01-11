#include <iostream>
using namespace std;

#define N 8
//  '1' denotes the positions where queens are placed

void print(int chessBoard[N][N]) 
{
   cout<<"\nN queens can be printed as:\n";
   for (int i = 0; i < N; i++) 
   {
      for (int j = 0; j < N; j++)
	  {
           cout<<chessBoard[i][j]<<" ";
      }
      cout<<endl;
   }
}

// checks if a queen can be attacked by any of the other queens.If not then place it there.
// This can be checked whether queens placed in columns [0...col-1] can attack this cell or not.     

bool check(int chessBoard[N][N], int row, int col) 
{
   for (int i = 0; i < col; i++) 
   {
      // checking for queens placed in the left 
      if (chessBoard[row][i] == 1) 
	  {
         return false;
      }
   }

   for (int i=row,j=col; i >= 0 && j >= 0; i--,j++) 
   {
      // checking for queens present in the upper left diagonal
      if (chessBoard[i][j] == 1) 
	  {
         return false;
      }
   }


   for (int i=row,j=col;i < N && j >= 0; i++,j--) 
   {
      //  checking for queens present in the lower left diagonal
      if (chessBoard[i][j] == 1) 
	  {
         return false;
      }
   }
   return true;
}

// find the row in which a queen can be placed for a particular column
bool placeQueen(int chessBoard[N][N], int col)
{
   if (col >= N) 
   {
      return true;	 // all N queens are successfully placed on the chess board
   }  
   for (int i = 0; i < N; i++)
   {
      if (check(chessBoard, i, col)) 
	  {
         chessBoard[i][col] = 1;
         if (placeQueen(chessBoard, col + 1) == true )
            return true;
         chessBoard[i][col] = 0;
      }
   }
   return false;
}


int main() 
{
   cout<<"**************EIGHT QUEENS PROBLEM*****************";
   int chessBoard[N][N] = { {0, 0, 0, 0},{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0} };
   bool ifQueen = placeQueen(chessBoard,0);
   if (ifQueen == false)
   {
      cout<<"\nQueens will attack!";
   }
   else 
   {
      cout<<"\nQueen will not attack!"<<endl;
      print(chessBoard);
   }
   cout<<endl;
   system("pause");
   return 0;
}
//T(n)=O(n^n)