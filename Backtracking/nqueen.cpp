#include<iostream>
using namespace std;

//sarthak
int num =0;
bool isvalid(int i,int j, int n, bool **board)
{
  if(i<0||j<0||i>=n||j>=n)
    return false;
  if(board[i][j])
    return false;
  return true;
}


void display(int n, bool **visited)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<visited[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

bool isSafe(int i, int j, bool **board, int n)
{
  //UP
  int row = i, col = j;
  while(isvalid(row, col, n, board))
  {
    row--;
  }
  if(row!=-1)
  {
  	cout<<"bcoz of up"<<endl;
    return false;
  }
  
  //Left Diagonal
  row = i;
  while(isvalid(row, col, n, board))
  {
    row--;
    col--;
  }
  if(row!=-1&&col!=-1)
  {
  	cout<<"bcoz of ld"<<endl;
    return false;
  }
  
  //Right Diagonal
  row =i; col=j;
  while(isvalid(row, col, n, board))
  {
    row--;
    col++;
  }
  if(row!=-1&&col!=n)
  {
   cout<<"bcoz of rd"<<endl;
    return false;
  }
  return true;
}

bool nQ(int n, bool **board, int row, int q)
{
	if(q==0){
		::num++;
	
    display(n, board);  
	cout<<endl;
		cout<<"\nAt iter "<<num<<endl;                                
    return true;
  }
 // if(row>=n)
  //{
   // return false;
  //}
  
  cout<<"At queen "<<n-q+1<<endl;
  bool isP= false;
  for(int i =0;i<n;i++)
  {
    if(isSafe(row, i, board, n)){                      
       board[row][i] = true;
       if(num == 4)
	   display(n, board);
       isP = nQ(n, board, row+1, q-1);
       board[row][i] = false;
    }
  }
  return false;
  
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  bool **board = new bool*[n]; 
  for(int i=0;i<n;i++)
       board[i] = new bool[n]();
  bool ans = nQ(n, board, 0, n);
   
}

int main()
{
	placeNQueens(5);
	cout<<"\nways "<<num;
	return 0;
}
