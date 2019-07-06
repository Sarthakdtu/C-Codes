//SARTHAK
#include<iostream>
using namespace std;
bool isvalid(int i,int j, int n, int maze[][20])
{
  if(i<0||j<0||i>=n||j>=n)
    return false;
  if(maze[i][j]==0)
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
  }
}


bool go(int maze[][20], int n, bool **visited, int i, int j)
{
  if(isvalid(i, j, n, maze))
  {
  	cout<<"Currently at i = "<<i<<" and j = "<<j<<endl;
    if(visited[i][j])
    {
      return false;
    }
    visited[i][j]= true;
    bool path1, path2, path3, path4;
    if(i==n-1&&j==n-1)
    {
      display(n, visited);
      visited[i][j] = false;
      return true;
    }
    else
    {
       path1 = go(maze, n, visited, i+1, j);
      
       path2 = go(maze, n, visited, i, j-1);
      
       path3 = go(maze, n, visited, i, j+1);
      
       path4 = go(maze, n, visited, i-1, j);
       
       if(path1||path2||path3||path4)
       {
       	cout<<"Path is present\n";
	   }
     
    }
    
    visited[i][j]=false;
    
  }
 
  return false;
  
}





void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
 bool **visited = new bool*[n];
 for(int i=0;i<n;i++)
 {
   visited[i]=new bool[n]();
 }
   //display(n,visited);
  bool ans =go(maze, n, visited, 0, 0);
  
}

int main()
{
	int arr[][20]={{1, 0, 1 },
	             {1, 0, 1},
				 {1, 1, 1}};
	ratInAMaze(arr,3);			 
	return 0;
}




