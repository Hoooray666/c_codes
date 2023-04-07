#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	int a[110][110];
	int row,col;
	for(row=0;row<n;row++)         
		for(col=0;col<n;col++)
			scanf("%d",&a[row][col]);

	for(row=0;row<n;row++)     
	{ 
		for(int i=0;i<n;i++)
			a[row][n]+=a[row][i];
		
	}
	int loc,i,temp[110],q;
	for(loc=0;loc<n-1;loc++)        
	{
	for(i=n-1;i>=loc+1;i--)
	{
		if(a[i][n]<a[i-1][n])
		{
			for(q=0;q<=n;q++)
			{
				temp[q]=a[i][q];      
				a[i][q]=a[i-1][q];
				a[i-1][q]=temp[q];
			}
		}
	}
	}
	for(row=0;row<n;row++)  
	{
		for(col=0;col<n-1;col++){
		    printf("%d ",a[row][col]);
	    }
        printf("%d",a[row][col]);
        printf("\n");
    }
    

return 0;
}

