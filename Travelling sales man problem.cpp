#include <bits/stdc++.h> 
using namespace std; 
  void swap(int *x, int *y); 
  void permute(int *a, int l, int r);

void swap(int *x, int *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  int dimen;
  int cost,answer=99999;

void permute(int **m,int *a,int l, int r)  
{  

int result,makem=0;
    int i;int o;
    if (l == r)  
    {
    	    cout<<endl;
    	    
    	   

    	    cout<<"1 "<<*a<<" "<<*(a+1)<<" "<<*(a+2)<<" 1"<<"\n";
    	     	makem+=m[1][*a];

    	    for(int f=0;f<r;f++)
    	    {
    	    	o=f+1;
    	    			//	cost=m[1][*a]+m[*a][*(a+1)]+m[*(a+1)][*(a+2)];//+m[*a+2][*a+3];
    	    				makem+=m[*(a+f)][*(a+o)];
    	    				

			}
			makem+=m[*(a+o)][1];
			cost=makem;
			cout<<"cost= "<<cost<<"\n";
			if(cost<=answer)
			{
				answer=cost;
				}				
	}
    else
    {  
        for (i = l; i <= r; i++)  
        {  
            swap((a+l), (a+i));  
            permute(m,a, l+1, r);  
            swap((a+l), (a+i)); //backtrack  
        }  
    }  
}  
  
/* Driver program to test above functions */
int main()  
{  

int dimen;

cout<<"Enter dimension\n";
cin>>dimen;
int *str=NULL;
str=new int[dimen];

     int** a = new int*[dimen+1];
    for(int i = 0; i <= dimen; ++i)
    a[i] = new int[dimen];
    
    cout<<"\nINPUT MATRIX\n";
     for(int i=1;i<=dimen;i++)
     {
     	for(int j=1;j<=dimen;j++)
     	{
     	    	cin>>a[i][j];
		 }
	 } 
	 int m=2;
	 for(int k=0;k<dimen;k++)
	 {
	 	str[k]=m;
	 	m++;
	 }
	 
    permute(a,str, 0, dimen-2);  
    cout<<"\nThe min cost is "<<answer;
	    return 0;  
}  
