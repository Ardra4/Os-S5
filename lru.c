#include <stdio.h>
int findLRU(int time[], int n)
{
int minimum = time[0], pos = 0;
for (int i = 1; i < n; i++) {
if (time[i] < minimum)
{
minimum = time[i];
pos = i;
}
}
return pos;
}
void LRU(int pg[], int n, int frame)
{
int temp[frame], counter = 0, time[10], flag1, flag2,pos;
int hit=0, pagefault = 0;
printf("\nValues\t");
for (int i = 1; i <= frame; i++)
printf("Frame%d\t", i);
printf("\n");
for (int i = 0; i < frame; i++)
temp[i] = -1;
for (int i = 0; i < n; i++)
{
flag1 = flag2 = 0;
printf("%d =>\t", pg[i]);
for (int j = 0; j < frame; j++)
{
if (temp[j] == pg[i])
{
counter++;
time[j] = counter;
flag1 = flag2 = 1;
hit++;
printf("\tHit!!!\n");
break;
}
}
if (flag1 == 0)
{
for (int j = 0; j < frame; j++)
{
if (temp[j] == -1)
{
counter++;
pagefault++;
temp[j] = pg[i];
time[j] = counter;
flag2 = 1;
for (int k = 0; k < frame; k++)
{
if (temp[k] != -1)
printf("%d\t", temp[k]);
}
printf("\n");
break;
}
}
}
if (flag2 == 0)
{
pos = findLRU(time, frame);
counter++;
pagefault++;
temp[pos] = pg[i];
time[pos] = counter;
for (int j = 0; j < frame; j++)
{
if (temp[j] != -1)
printf("%d\t", temp[j]);
}
printf("\n");
}
}
printf("\nTotal Page Faults = %d\n", pagefault);
printf("Total Page hits = %d\n", hit);
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
LRU(pg,n,frame);
}

