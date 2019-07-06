#include<iostream>
using namespace std;




//sarthak
void display(int board[][9])
{
	for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
     cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}




bool is3by3(int board[][9], int row1, int col1)
{
	int row, col, limr, limc;
	if(row1<3)
	{
		row = 0;
		limr =3;
	}
	else if(row1<6)
	{
		row = 3;
		limr =6;
	}
	else if(row1<9)
	{
		row  = 6;
		limr =  9;
	}
	
	if(col1<3)
	{
		col = 0;
		limc =3;
	}
	else if(col1<6)
	{
		col = 3;
		limc =6;
	}
	else if(col1<9)
	{
		col   = 6;
		limc =  9;
	}
	bool *check = new bool[10]();
	for(int i = row;i<limr;i++)
	{
		for(int j = col;j<limc;j++)
		{
			if(check[board[i][j]] && board[i][j]!=0)
			{
				cout<<"I failed at "<<i<<" , "<<j<<" coz of  "<<board[i][j]<<endl;
				return false;
			}
			check[board[i][j]] = true;
		}
	}
 return true;	
}





bool isRow(int board[][9], int r)
{
 //row wise
 int *check = new int[10];
  for(int i=0;i<9;i++)
  {
   if(board[r][i]==0||check[board[r][i]]==1)
   return false; 
   check[board[r][i]]=1;
  }
  return true;
}

bool isCol(int board[][9], int c)
{
 //row wise
  for(int i=0;i<9;i++)
  {
   if(board[i][c]==0)
   return false; 
  }
  return true;
}

bool canBePlaced(int board[][9], int x, int y, int a)
{
	for(int i=0;i<9;i++)
	{
		if(board[x][i]==a)
			return false;
		
		if(board[i][y]==a)
		    return false;
	}
	return true;
}



bool solve(int board[][9], int i, int j, bool **visited)
{
if(i==9)
{
	cout<<"i = "<<9<<endl;
	return true;
}
  
  display(board);
  //cout<<"i,j "<<i<<" , "<<j<<endl;
  
  for(int y=j;y<9;y++)
  {
  
 // cout<<"i,y "<<i<<" , "<<y<<" value is "<<board[i][y]<<endl;	
  	if(board[i][y]==0)
  	{
  		
  		for(int a=1;a<10;a++)
  		{
  		  if(canBePlaced(board, i, y, a))
		  {
			cout<<"Trying to fill "<<i<<" , "<<y<<" with a = "<<a<<endl;
  			board[i][y] = a;
  			if(is3by3(board, i, y))	
  			{
  			bool path = solve(board, i, y+1, visited); 
			if(path)
			{
				return true;
			 } 
			 if(!path)
			 {
			 	board[i][y]=0;
			 }
		     }
		     else
		     {
		     	board[i][y]=0;
			 }
  	     	}
  	     	//cout<<"Sorry can't be placed"<<endl;
		}
		if(board[i][y]==0)
  	     	{
  	     	  return false;	
			}
    }
	//cout<<"i,y "<<i<<" , "<<y<<"Here I am "<<endl;	
	//cout<<"Now going to i,y "<<i<<" , "<<y+1<<endl;	
  }
  if(isRow(board, i))
  {
  	return solve(board, i+1, 0, visited);
  }
	
	
  
 // board[j][y] =0; 
  return false;
}


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
  bool **visited = new bool*[9];
  for(int i=0;i<9;i++)
  {
  	visited[i] = new bool[9]();
  }
  
  return solve(board, 0, 0, visited);
  

}



int main()
{
  int board[][9] = {
  
{9, 0, 0, 0 ,2 ,0, 7, 5, 0 },
{6 ,0, 0, 0 ,5, 0 ,0, 4, 0 },
{0 ,2 ,0 ,4 ,0 ,0, 0 ,1, 0 },
{2 ,0, 8, 0, 0 ,0, 0, 0, 0 },
{0 ,7 ,0 ,5 ,0, 9, 0 ,6 ,0} ,
{0, 0, 0, 0 ,0, 0, 4 ,0, 1 },
{0 ,1 ,0 ,0, 0 ,5 ,0, 8 ,0 },
{0, 9, 0, 0 ,7, 0, 0, 0, 4 },
{0 ,8 ,2 ,0 ,4, 0 ,0 ,0 ,6}
 };
  
  
  cout<<sudokuSolver(board)<<endl;
  display(board);
  
 return 0;	
}



















