#include <stdio.h>
void main()
{
int f, p;
int pages[50], frame[10], hit = 0, count[50], time[50];
int page, flag, least, minTime, temp;
printf("Enter no of pages : ");
scanf("%d", &p);
printf("Enter no of frames : ");
scanf("%d", &f);
for (int i = 0; i < f; i++)
{
frame[i] = -1;
}
for (int i = 0; i < 50; i++)
{
count[i] = 0;
}
printf("Enter page no : \n");
for (int i = 0; i < p; i++)
{
scanf("%d", &pages[i]);
}
for (int i = 1; i <= f; i++)
printf("Frame%d\t", i);
printf("\n");
for (int i = 0; i < p; i++)
{
count[pages[i]]++;
time[pages[i]] = i;
flag = 1;
least = frame[0];
for (int j = 0; j < f; j++)
{
if (frame[j] == -1 || frame[j] == pages[i])
{
if (frame[j] != -1)
{
hit++;
}
flag = 0;
frame[j] = pages[i];
break;
}
if (count[least] > count[frame[j]])
{
least = frame[j];
}
}
if (flag)
{
minTime = 50;
for (int j = 0; j < f; j++)
{
if (count[frame[j]] == count[least] && time[frame[j]] < minTime)
{
temp = j;
minTime = time[frame[j]];
}
}
count[frame[temp]] = 0;
frame[temp] = pages[i];
}
for (int j = 0; j < f; j++)
{
if(frame[j]!=-1)
printf("%d \t\t", frame[j]);
}
printf("\n");
}
printf("Page faults = %d\n", p-hit);
printf("Page hit = %d\n", hit);
printf("Hit Ratio = %f\n", hit/(float)p);
}
