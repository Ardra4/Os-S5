#include<stdio.h>
struct file
 {
 char fname[10];
 int index,size,block[10];
 }
	f[10];
	void main(){
	int n,allocated[10];
	for(int i=0;i<10;i++){
		allocated[i]=0;}
	printf("Enter no. of files:");
	scanf("%d",&n);
 	for(int i=0;i<n;i++){
		printf("\nEnterfilename:");
		scanf("%s",f[i].fname);
		x:printf("Enterindexblock:");
		scanf("%d",&f[i].index);
		if(allocated[f[i].index])
		{
			printf("Index block is already allocated--tryanother\n");
		goto x;} 
		allocated[f[i].index]=1;
		f[i].block[0]=f[i].index;
		printf("Enter no. of blocks:");
		scanf("%d",&f[i].size);
		printf("Enterblocknumbers:\n");
		for(int j=1;j<=f[i].size;j++)
		{
			y:scanf("%d",&f[i].block[j]);
			if(allocated[f[i].block[j]]==1){
	printf("Block %d is already allocated-->enteranotherblock\n",f[i].block[j]);
	goto y;
	}
	allocated[f[i].block[j]]=1;
	}
	printf("\n");
	for(int j=1;j<=f[i].size;j++)
	{
		printf("%d---->%d\n",f[i].block[0],f[i].block[j]);
}}
	printf("\nFile\tindex\tsize\n");
	for(int i=0;i<n;i++){
		printf("%s\t%d\t\t%d\n",f[i].fname,f[i].index,f[i].size);}
}
