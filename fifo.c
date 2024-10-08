#include <stdio.h>
void FIFO(int pg[], int n, int frame)
{
int pagefault = 0, hit = 0, k = 0, flag;
int temp[frame];
printf("\nValues\t");
for (int i = 1; i <= frame; i++)
printf("Frame%d\t", i);
printf("\n");
for (int i = 0; i < frame; i++)
{
temp[i] = -1;
}
for (int i = 0; i < n; i++)
{
flag= 0;
printf("\n%d =>\t", pg[i]);
for (int j = 0; j < frame; j++)
{
if (temp[j] == pg[i])
{
flag= 1;
hit++;
printf("\tHit!!!");
}
}
if (flag == 0)
{
temp[k] = pg[i];
k = (k + 1) % frame;
pagefault++;
for (int j = 0; j < frame; j++)
{
if (temp[j] != -1)
printf("%d\t", temp[j]);
}
}
}
printf("\nTotal Page Faults: %d\n", pagefault);
printf("\nTotal Page hits = %d\n", hit);
printf("Hit ratio = %f",hit/(float)n);
}
void main()
{
int n, frame;
printf("Enter the Length of sequence: ");
scanf("%d", &n);
int pg[n];
printf("Enter the Sequence: ");
for (int i = 0; i < n; i++)
scanf("%d", &pg[i]);
printf("Enter the number of frames: ");
scanf("%d", &frame);
FIFO(pg,n,frame);
}
