#include<stdio.h>
#include<math.h>
int main(){
    int i,j,k,a,b;
    scanf("%d%d",&a,&b);
        for(j=0;j<a;j++)
		
		{
        	printf("|*****|");
        	for(i=0;i<b-2;i++)
			{
            	printf("*****|");
        	}
        	printf("*****|\n");
        	printf("|  |  |");
        	for(i=0;i<b-2;i++)
			{
            	printf("  |  |");
        	}
        	printf("  |  |\n");
    		printf("|--+--|");
        	for(i=0;i<b-2;i++)
			{
            	printf("--+--|");
        	}
        	printf("--+--|\n");
    		printf("|  |  |");
        	for(i=0;i<b-2;i++)
			{
            	printf("  |  |");
        	}
        	printf("  |  |\n");
		}
    		printf("|*****|");
        	for(i=0;i<b-2;i++)
			{
            	printf("*****|");
        	}
        	printf("*****|\n");
    return 0;
}
