#include<stdio.h>
struct file
{
	char fname[10];
	int start,size,block[10];
}f[10];
void main()
{ 
	int n,allocated[10];
	for(int i=0;i<10;i++)
	{
		allocated[i]=0;}
	printf("Enter no. of files:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter file name:");
		scanf("%s",f[i].fname);
		printf("Enter starting block:");
		scanf("%d",&f[i].start);
		f[i].block[0]=f[i].start;
		printf("Enter no.of blocks:");
		scanf("%d",&f[i].size);
		printf("Enter block numbers:\n");	
		for(int j=1;j<=f[i].size;j++)
		{
			x:scanf("%d",&f[i].block[j]);
			if(allocated[f[i].block[j]]==1)
			{
				printf("Block %d is already allocated-->enter another block\n",f[i].block[j]);
		goto x;
		}
		allocated[f[i].block[j]]=1;
		}
	}
	printf("File\tstart\tsize\tblock\n");
	for(int i=0;i<n;i++)
	{
		printf("%s\t%d\t\t%d\t",f[i].fname,f[i].start,f[i].size);
		for(int j=1;j<=f[i].size-1;j++)
		{
			printf("%d--->",f[i].block[j]);
		}
		printf("%d",f[i].block[f[i].size]);
		printf("\n");}
}
