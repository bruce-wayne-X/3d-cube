    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <cctype>
    #include <vector>

using namespace std;
int arra[10][10][10]={0};
struct coord
{
	int x;
	int y;
	int z;
	coord()
	{
		x=0;y=0;z=0;
	}
	coord(int a,int b,int c)
	{
		x=a;y=b;z=c;
	}
};
vector<coord> myvector;
int player[3][3][3];
coord arax[1000];
int check(int n,int x)
{
	if(x>=n)
		{x=x-n;}
	if(x<0)
		{x+=n;}
return x;
}

void oddmagicube(int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++)
				{arra[i][j][k]=0;
				 arax[(i*n)+(j*n)+k].x=0;
				 arax[(i*n)+(j*n)+k].y=0;
				 arax[(i*n)+(j*n)+k].z=0;}}}
	

	arra[0][n/2][n/2]=1;
	arax[0].x=0;
	arax[0].y=n/2;
	arax[0].z=n/2;
	
	int x=0,y=n/2,z=n/2;
	for(int i=1;i<=n*n*n;i++)
	{
		arra[x][y][z]=i;
		arax[i-1].x=x;
		arax[i-1].y=y;
		arax[i-1].z=z;
		x--;
		x=check(n,x);
		z--;
		z=check(n,z);
		if(arra[x][y][z]!=0)
		{
			y--;
			y=check(n,y);
			z++;
			z=check(n,z);
			if(arra[x][y][z]!=0)
			{
				y++;
				y=check(n,y);
				x+=2;
				x=check(n,x);
			}

		}
	}	

}
bool cordcom(coord x,coord y,coord z)
{
	if((x.x-y.x==y.x-z.x)&&(x.y-y.y==y.y-z.y)&&(x.z-y.z==y.z-z.z))
	{
		return false;
	}
	if((x.x-z.x==z.x-y.x)&&(x.y-z.y==z.y-y.y)&&(x.z-z.z==z.z-y.z))
	{
		return false;
	}
	if((y.x-x.x==x.x-z.x)&&(y.y-x.y==x.y-z.y)&&(y.z-x.z==x.z-z.z))
	{
		return false;
	}		
	return true;
}
void printcube(int n)
{
	cout<<"Herein Lies the magic cube!\n";
	for(int i1=0;i1<n;i1++)
	{
		for(int j1=0;j1<n;j1++)
		{
					for(int k1=0;k1<n;k1++)
						{cout<<player[i1][j1][k1]<<" ";}
					cout<<"\n";			
		}
		cout<<"\n";
	}	
}
void printer(int n)
{
	int x;
	int y;
	int z;
	for(int i=1;i<=n*n*n;i++)
	{
		x=i;
		for(int j=1;j<=n*n*n;j++)
		{
			y=j;
			if(y!=x)
			{
				for(int k=1;k<=n*n*n;k++)
				{
					z=k;
					if(z!=y && z!=x && (x+y+z==((n)*((n*n*n)+1))/(2)) && cordcom(arax[x-1],arax[y-1],arax[z-1]) && x <y && y<z)
					{
						cout<<x<<" "<<y<<" "<<z<<"\n";
						myvector.push_back(coord(x,y,z));
					}
				}								
			}
		}		
	}
	cout<<"Herein Lies the magic cube!\n";
	for(int i1=0;i1<n;i1++)
	{
		for(int j1=0;j1<n;j1++)
		{
					for(int k1=0;k1<n;k1++)
						{cout<<arra[i1][j1][k1]<<" ";}
					cout<<"\n";			
		}
		cout<<"\n";
	}	
}
void cubestat()
{
	cout<<"\n";
	for(int i1=0;i1<3;i1++)
	{
		for(int j1=0;j1<3;j1++)
		{
					for(int k1=0;k1<3;k1++)
						{
						if(player[i1][j1][k1]==0)
							{cout<<"_ ";}
						else if(player[i1][j1][k1]==1)
							{cout<<"C ";}
						else if(player[i1][j1][k1]==2)
							{cout<<"H ";}
						}
					cout<<"\n";			
		}
		cout<<"\n";
	}	
}
int returnval(coord a)
{
	return player[a.x][a.y][a.z];
}
bool poswin()
{
	int x;
	int y;
	int z;

	for(int i=1;i<=27;i++)
	{
		x=i;
		for(int j=1;j<=27;j++)
		{
			y=j;
			for(int k=1;k<=27;k++)
			{
				z=k;
				if(z!=y && z!=x && !cordcom(arax[x-1],arax[y-1],arax[z-1]) && x <y && y<z)
				{
					if( returnval(arax[x-1])==0 && returnval(arax[y-1])==1 && returnval(arax[z-1])==1 )
					{
						player[arax[x-1].x][arax[x-1].y][arax[x-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==1 && returnval(arax[y-1])==1 && returnval(arax[z-1])==0)
					{
						player[arax[z-1].x][arax[z-1].y][arax[z-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==1 && returnval(arax[y-1])==0 && returnval(arax[z-1])==1 )
					{
						player[arax[y-1].x][arax[y-1].y][arax[y-1].z]=1;
						return true;
					}
				}
			}								
		}		
	}
	return false;
}

bool poslose()
{
	int x;
	int y;
	int z;
	for(int i=1;i<=27;i++)
	{
		x=i;
		for(int j=1;j<=27;j++)
		{
			y=j;
			for(int k=1;k<=27;k++)
			{
				z=k;
				if(z!=y && z!=x && !cordcom(arax[x-1],arax[y-1],arax[z-1]) && x <y && y<z)
				{
					if( returnval(arax[x-1])==0 && returnval(arax[y-1])==2 && returnval(arax[z-1])==2 )
					{
						player[arax[x-1].x][arax[x-1].y][arax[x-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==2 && returnval(arax[y-1])==2 && returnval(arax[z-1])==0)
					{
						player[arax[z-1].x][arax[z-1].y][arax[z-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==2 && returnval(arax[y-1])==0 && returnval(arax[z-1])==2 )
					{
						player[arax[y-1].x][arax[y-1].y][arax[y-1].z]=1;
						return true;
					}
				}
			}								
		}		
	}
	return false;
}
bool nowin()
{
	int x;
	int y;
	int z;
	for(int i=1;i<=27;i++)
	{
		x=i;
		for(int j=1;j<=27;j++)
		{
			y=j;
			for(int k=1;k<=27;k++)
			{
				z=k;
				if(z!=y && z!=x && !cordcom(arax[x-1],arax[y-1],arax[z-1]) && x <y && y<z)
				{
					if( returnval(arax[x-1])==0 && returnval(arax[y-1])==1 && returnval(arax[z-1])==0 )
					{
						player[arax[x-1].x][arax[x-1].y][arax[x-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==1 && returnval(arax[y-1])==0 && returnval(arax[z-1])==0)
					{
						player[arax[z-1].x][arax[z-1].y][arax[z-1].z]=1;
						return true;
					}
					else if(returnval(arax[x-1])==0 && returnval(arax[y-1])==0 && returnval(arax[z-1])==1 )
					{
						player[arax[y-1].x][arax[y-1].y][arax[y-1].z]=1;
						return true;
					}
				}
			}								
		}		
	}
	return false;
}

int main()
{
    int testcase;
    oddmagicube(3);
    printer(3);
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		for(int k=0;k<3;k++)
    		{
    			player[i][j][k]=0;
    		}
    	}
    }
    
    int x;
    cout<<"Enter if you are player 1 or 2\n";
    cin>>x;
    if(x==2)
    {
	    player[1][1][1]=1;
	    cout<<"Computer plays :-\n";
	    cubestat();
	    cout<<"second players move,mind,enter x y z coordinates from 0 to 2 only!\n";
		int x;
		int y;
		int z;
	    cin>>x>>y>>z;
	    int px=0;
	    player[x][y][z]=2;
	    cout<<"You have played\n";
	    cubestat();
	    int a=1;
	    for(int r1=0;r1<18;r1++)
	    {
	    	if(a==1)
	    	{
	    		if(poswin())
	    		{
	    			//dowin();
	    			cout<<"poswin\n";
	    		}
	    		else if(poslose())
	    		{
	    			cout<<"doblock\n";
	    		}
	    		else
	    		{
	    			cout<<"nowin\n";
	    			nowin();
	    		}
	    		a=2;//Player 2's chance
	    		cout<<"Computer plays :- \n";
	    		cubestat();
	    	}
	    	else if(a==2)
	    	{
	    		cin>>x>>y>>z;
	    		while(player[x][y][z]!=0)
	    		{
	    			cout<<"Enter a valid output\n";
	    			cin>>x>>y>>z;
	    		}

	    		player[x][y][z]=2;
	    		a=1;//player 1's chance
	    		cout<<"You have played\n";
	    		cubestat();
	    	}
	    }
    }
    else if(x==1)
    {
	    cout<<"second players move,mind,enter x y z coordinates from 0 to 2 only!\n";
		int x;
		int y;
		int z;
	    cin>>x>>y>>z;
		while(player[x][y][z]!=0)
		{
			cout<<"Enter a valid output\n";
			cin>>x>>y>>z;
		}
		player[x][y][z]=2;
		cout<<"You have played\n";
		cubestat();
		if(x==1 && y==1 && z==1)
		{
			player[x-1][y][z]=1;
		}
		else
		{
			player[1][1][1]=1;
		}
		cout<<"Computer plays :-\n";
		cubestat();
	    int a=1;
	    for(int r1=0;r1<18;r1++)
	    {
	    	if(a==1)
	    	{
	    		if(poswin())
	    		{
	    			//dowin();
	    			cout<<"poswin\n";
	    		}
	    		else if(poslose())
	    		{
	    			cout<<"doblock\n";
	    		}
	    		else
	    		{
	    			cout<<"nowin\n";
	    			nowin();
	    		}
	    		cout<<"Computer plays :-\n";
	    		a=2;//Player 2's chance
	    		cubestat();
	    	}
	    	else if(a==2)
	    	{
	    		cin>>x>>y>>z;
	    		while(player[x][y][z]!=0)
	    		{
	    			cout<<"Enter a valid output\n";
	    			cin>>x>>y>>z;
	    		}

	    		player[x][y][z]=2;
	    		a=1;//player 1's chance
	    		cout<<"You have played\n";
	    		cubestat();
	    	}
	    }

    }




int y,z;
int comp=0;
int user=0;
	for(int i=1;i<=27;i++)
	{
		x=i;
		for(int j=1;j<=27;j++)
		{
			y=j;
			for(int k=1;k<=27;k++)
			{
				z=k;
				if(z!=y && z!=x && !cordcom(arax[x-1],arax[y-1],arax[z-1]) && x <y && y<z)
				{
					if( returnval(arax[x-1])==1 && returnval(arax[y-1])==1 && returnval(arax[z-1])==1 )
					{
						comp++;
					}
					else if(returnval(arax[x-1])==2 && returnval(arax[y-1])==2 && returnval(arax[z-1])==2)
					{
						user++;
					}
				}
			}								
		}		
	}
cout<<comp<<" haha "<<user;










    return 0;
}