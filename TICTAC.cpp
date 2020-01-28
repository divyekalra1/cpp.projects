#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<graphics.h>	
int z,r=0,n,p=0,won=0;
char w[9],c='O';
int submatwin(int m);
int checktracker();
char a[9][3][3];
/*
void line2(int a,int b,int c,int d,int e,int f)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	line(a,b,e,f);
	line(c,d,e,f);
	closegraph();
}
void line3(int a,int b,int c,int d,int e,int f,int g,int h)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	line(a,b,c,d);
	line(e,f,g,h);
	line(g,h,c,d);
	closegraph();
}
void line4(int a,int b,int c,int d,int e,int f,int g,int h)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	line(a,b,c,d);
	line(e,f,g,h);
	line(g,h,c,d);
	line(a,b,e,f);
	closegraph();
}
*/
void printmat()
{
	clrscr();
	int i,j,q=3,sp=1,m,k;
	for(i=0;i<3;i++)
	{
		for(k=q-3;k<q;k++)
		{
			for(j=0;j<3;j++)
			{
				cout<<" "<<a[k][i][j]<<"|";
			}
			cout<<"\b\t";
		}
		cout<<endl;
		if(i==2)
		{
			i=-1;
			q+=3;
			cout<<"\n\n";
			if(sp==3)
			break;
			sp++;
		}
		if(i!=-1)
		{
			for(m=0;m<3;m++)
			{
				cout<<"--|--|--"<<"\t";
			}
			cout<<endl;
		}
	}
}
void initialise()
{
	int i,j,k;
	for(k=0;k<9;k++)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				a[k][i][j]=' ';
			}
		}
	}
	for(i=0;i<9;i++)
	{
		w[i]=' ';
	}
}
void readsym()
{
	int i,j,l,index;
	if(p==0)
		r++;
	else
		p=0;
	if(r%2==1)
	{
		cout<<"Player 1's Turn : ";
		c='O';
	}
	else
	{
		cout<<"Player 2's Turn : ";
		c='X';
	}
	n=getch();
	if(n>6)
	{
		n-=6;
		i=0;
		j=n-7;
	}
	else if(n<4)
	{
		n+=6;
		i=2;
		j=n-1;
	}
	else
	{
		i=1;
		j=n-4;
	}
	if(r==1)
		{
			a[4][i][j]=c;
		}
	else if(r!=1&&a[z][i][j]==' '&&submatwin(z)==0)
		a[z][i][j]=c;
	else
		{
			cout<<"Cell already occupied or sub-tictactoe already won! ";
//Make the same player enter a number again instead of quitting the game exit(0);
		}
	if(submatwin(z)==1)
	{
		w[z]=c;
		if(checktracker()==1)
		{
			won=1;
			if(r%2==1)
			{
				clrscr();
				cout<<"Player 1 Wins ";
			}
			else
			{
				clrscr();
				cout<<"Player 2 Wins ";
			}
		}
	}
	printmat();
	z=n-1;
	if(w[z]=='X'||w[z]=='O')
	{
		//l=getch();
		cin>>l;
		if(l>6)
			l-=6;
		else if(l<4)
			l+=6;
		l-=1;
		//index=getch();
		cin>>index;
		if(index>6)
		{
			index-=6;
			i=0;
			j=index-7;
		}
		else if(index<4)
		{
			index+=6;
			i=2;
			j=index-1;
		}
		else
		{
			i=1;
			j=index-4;
		}
		r++;
		p=1;
		if(r%2==1)
			a[l][i][j]='O';
		else
			a[l][i][j]='X';
		printmat();

	}
}
int submatwin(int m)
{
	int i,j,flag=0;
	for(i=0;i<3;i++)
	{
		if(a[m][i][0]==a[m][i][1]&&a[m][i][0]==a[m][i][2])
		{
			flag=1;
			break;
		}
	}
	for(j=0;j<3;j++)
	{
		if(a[m][0][j]==a[m][1][j]&&a[m][0][j]==a[m][2][j])
		{
			flag=1;
			break;
		}
	}
	if(a[m][0][0]==a[m][1][1]&&a[m][0][0]==a[m][2][2])
		flag=1;
	else if(a[m][0][2]==a[m][1][1]&&a[m][0][2]==a[m][2][0])
		flag=1;
	if(flag==1)
		return 1;
	else
		return 0;
}
int checktracker()
{
	int i,flag=0;
	for(i=0;i<3;i+=3)
	{
		if(w[i]==w[i+3]&&w[i]==w[i+6])
		{
			flag=1;
			break;
		}
		else if(w[i]==w[i+1]&&w[i]==w[i+2])
		{
			flag=1;
			break;
		}
	}
	if((w[0]==w[4]&&w[0]==w[8])||(w[2]==w[4]&&w[4]==w[6]))
		flag=1;
	if(flag==1)
		return 1;
	else
		return 0;
}
void main()
{
	clrscr();
	initialise();
	printmat();
	while(won==0)
		readsym();
	getch();
}
