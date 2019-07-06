#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;
float round(float a);

int main()
{
int gd=DETECT,gm;
// gd=graphics driver (detects best graphics driver and assigns it as default, gm=graphics mode.
int x1,y1,x2,y2,steps,dx,dy,k;
float xincr,yincr,x,y;

cout<<"Enter x1, y1";
cin>>x1>>y1;
cout<<"\nEnter x2, y2";
cin>>x2>>y2;

initgraph(&gd,&gm,"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib");//initializes the graph
dx=float(x2-x1);
dy=float(y2-y1);

if(abs(dx)>abs(dy))
  steps=abs(dx);
else
  steps=abs(dy);
  
xincr=dx/steps;
yincr=dy/steps;

x=x1;
y=y1;

for(k=1;k<=steps;k++)
{
 delay(100);//for seeing the line drawing process slowly.
 x+=xincr;
 y+=yincr;
 putpixel(round(x),round(y),WHITE);
}

outtextxy(200,20,"DDA"); // for printing text at desired screen location.
outtextxy(x1+5,y1-5,"(x1,y1)");
outtextxy(x2+5,y2+5,"(x2,y2)");


closegraph(); // closes the graph and comes back to previous graphic mode.
return 0;
}
float round(float a)
{
int b=a+0.5;
return b;
}
