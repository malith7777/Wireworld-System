#include <stdio.h>
#include <stdlib.h>
#include"map.h"
#include"color.h"
#include"newSleep.h"

void printmap(char** map1, int Rows, int Cols)
{
int b,c;
 for(b=0;b<Rows;b++)
 {
 for(c=0;c<Cols;c++)
   {
    switch(map1[b][c])
    {
     case'0':
     {
      setBackground("black");
      setForeground("black");
      printf("0 ");
     }
     break;
     case '1':
     {
      setBackground("blue");
      setForeground("blue");
      printf("1 ");
     }      
     break;
     case '2':
     {
      setBackground("red");
      setForeground("red");
      printf("2 ");
     }
     break;
     case '3':
     {
      setBackground("yellow");
      setForeground("yellow");
      printf("3 ");
     }
     break;
    }
    setBackground("reset");
    setForeground("reset");   
   }
   printf("\n");
  }
}
void Cellmap(char** map1, float slp, int steps, int Rows, int Cols)
{
int y, b, c, a, p, g, h, i, j, k,l;
int int_count;
int d = 0;
int e = 0;
char** map2;


for(y=0; y<steps; y++)
{

    map2 = (char**)malloc((Rows) * sizeof(char*));
    
    for(a=0; a<(Rows);a++)
    {
       map2[a] = (char*)malloc((Cols)*sizeof(char));
    }
    for(k=0;k<Rows;k++)
    {
    for(l=0;l<Cols;l++)
     {
       map2[k][l] = '0';
     }
    }
    
 newSleep(slp);
 for(b=0;b<Rows;b++)
 {
 for(c=0;c<Cols;c++)
   {
   
    if(map1[b][c]=='3')
    {
     int_count=0;
     if(b+1<Rows)
     {
      if(map1[b+1][c]=='1')
      {
       map2[b][c] = '1';
       int_count++;
      }
     }
     
    if(b-1>=0)
    {
      if(map1[b-1][c]=='1')
      {
       map2[b][c] = '1';
       int_count++;
      }
    }
    if(c+1<Cols)
    {
      if(map1[b][c+1]=='1')
      {
       map2[b][c] = '1';
       int_count++;
      }
    }
   if(c-1>=0)
   {
      if(map1[b][c-1]=='1')
      {
       map2[b][c] = '1';
       int_count++;
      }
    }
   if((b-1>=0)&&(c-1>=0))
   {
    if(map1[b-1][c-1]=='1')
    {
       map2[b][c] = '1';
       int_count++;
      }
  }
  if((b+1<Rows)&&(c+1<Cols))
  {
   if(map1[b+1][c+1]=='1')
   {
       map2[b][c] = '1';
       int_count++;
      }
  }
  if((b-1>=0)&&(c+1<Cols))
  {
   if(map1[b-1][c+1]=='1')
   {
       map2[b][c] = '1';
       int_count++;
      }
  }
  if((b+1<Rows)&&(c-1>=0))
  {
   if(map1[b+1][c-1]=='1')
   {
       map2[b][c] = '1';
       int_count++;
      }
  }
  if((map2[b][c] == '1')&&(int_count>2))
  {
   map2[b][c] = '0';
  }
}

   }
}

for(d=0;d<Rows;d++)
{
for(e=0;e<Cols;e++)
  {
   if(map1[d][e]=='2')
   {
    map1[d][e] = '3';
   }
   
   }
}

for(p=0;p<Rows;p++)
{
for(g=0;g<Cols;g++)
  {
   if(map1[p][g]=='1')
   {
    map1[p][g] = '2';
   }
   
   }
}

for(p=0;p<Rows;p++)
{
for(g=0;g<Cols;g++)
  {
   if(map1[p][g]=='1')
   {
    map1[p][g] = '2';
   }
   
   }
}

for(h=0;h<Rows;h++)
{
for(i=0;i<Cols;i++)
  {
   if(map2[h][i]=='1')
   {
    map1[h][i] = '1';
   }
   
   }
}

for(h=0;h<Rows;h++)
{
for(i=0;i<Cols;i++)
  {
   if(map2[h][i]=='1')
   {
    map1[h][i] = '1';
   }
   
   }
}

 system("clear");
 printmap(map1, Rows, Cols);
 
 
   for(j = 0; j<Rows;j++)
   {
        free(map2[j]);
    }
   free(map2);
}
}
   


   
     
     
      
