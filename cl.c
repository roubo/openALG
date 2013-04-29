#include <stdio.h>

int count[402]={0};
int n_count=0;
float fun(int n)
{
	float ans=0;
	int i,j;
	switch(n)
	{
		case 1:
			return 1.00000;
		case 2:
			return 2.00000;
		case 3: 
			return 2.66667;
	}
	if(n%2==0)
	{
		for(i=0;i<n/2;i++)
		{
			ans+=2/n*(1+fun(i+2));
		}
	}
	else
	{
		for(j=0;j<(n-1)/2;j++)
		{
			ans+=2/n*(1+fun(j+3));
			
		}ans+=1/n*(1+fun(2));
	}
	
	return ans;
}


int init ()
{
	int i,j;
	scanf("%d",&n_count);
	if(n_count==0) return 0;
	for(i=0;i<n_count;i++) 
	{
	//if(i==0)
	//{
//	count=(int *)malloc(400*sizeof(int));}	
	scanf("%d",&j);
	count[i]=j;
	

	
	}
	return 1;
}

int main()
{       int i;
	float anss;
	while(init())
	{
		i=0;
		while(i<n_count)
		{
			anss=fun(count[i++]);
			printf("%.5f \n",anss);
		}
		return 0;
	}	
}
