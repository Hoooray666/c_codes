int isPerfect(int n)
{
	int i,sum=0;
	if(n==1)
	  return 0;
	for(i=1;i<=n/2;i++)
	{
		if(n%i==0)
		  sum+=i;
	}
	if(sum==n)
	  return 1;
	else
	  return 0;
}
void printPerfect(int n)
{
	int i,cnt=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
		  if(cnt==0)
		  {
		  printf("%d=%d",n,i);
		  cnt=1;
	      }
	      else if(cnt!=0)
	      printf("+%d",i);
		}
	}
	printf("\n");
}

