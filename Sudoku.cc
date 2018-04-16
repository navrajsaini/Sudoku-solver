/*
  By: Navraj Saini
  AI - Spring 2018
  A3
  Sudoku problem
  recursively solve for any sudoku problem given
*/

#include <iostream>

using namespace std;

int S_in[9][9];//var to store the input

void print();// print the solution

bool solve();//solve the input

//check if the number is a valid input
bool Ccol (int, int);//row, col, num
bool Cbox (int, int, int);//start row, start col, num
bool Crow (int, int);
//check to see which location is still unassigned aka 0
bool Loc(int&, int&);

int main ()
{
   int in;
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
	 cin >> in;
	 while (in > 9 || in < 0)
	 {
	    cout << "please input a value between 1-9" << endl;
	    cin >> in;
	 }
	 S_in[i][j] = in;
      }
   }
   
   bool check = solve();
   if (check)
   {
      print();
   }
   else
      cout << "no sol... I'm out yo :D" << endl;
   return 0;
}
// check if the number exists in any row or col in the puzzle
bool Ccol (int col, int num)
{
   for (int i = 0; i < 9; i++)
   {
      if (S_in[i][col] == num)
	 return true;
   }
   return false;
}

// check the row this time... tried to combine the row and col check but didn't work
bool Crow (int row, int num)
{
   for (int i = 0; i < 9; i++)
   {
      if (S_in[row][i] == num)
	 return true;
   }
   return false;
}
// check to make sure the number isn't in the 3x3 box
bool Cbox (int srow, int scol, int num)
{
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
      {
	 if(S_in[i+srow][j+scol] == num)
	    return true;
      }
   return false;
}

//find the loction where row and col are 0
bool Loc(int& row, int& col)
{
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
      {
	 if (S_in[row][col] == 0)
	    return true;
      }
   return false;
}

void print ()
{
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
	 cout << S_in [i][j];
	 if (j == 8)
	    cout << " ";
	 else
	    cout << ", ";
      }
      cout << endl;
   }
}

bool solve()
{
   int row = 0;
   int col = 0;

   if (!Loc(row, col))// if the puzzle is complete exit
      return true;
   
   for (int i = 1; i < 10; i++)
   {
      if (!Ccol (col, i) && !Crow (row, i) &&
	  !Cbox (row-row%3, col-col%3, i))// check if the value is avaliable
      {
	 S_in [row][col] = i;// place the value in the location
	 
	 if (solve())// if it works return, the recursive part
	    return true;

	 S_in[row][col] = 0;//if it doesn't work undo and retry
      }
   }
   return false;
}
