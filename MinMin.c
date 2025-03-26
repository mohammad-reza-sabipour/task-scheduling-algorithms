#include<stdio.h>
#include<limits.h>

#define INF  1e8

int main()
{
    int n = 3, m = 2;
	int array[n][m];
	int tmp[n][m];
	int makespan = 0;
	
	for ( int i = 0 ; i < n ; i++ )
	{
		for ( int j = 0 ; j < m ; j++ )
		{
			scanf("%d", &array[i][j]);
			tmp[i][j] = array[i][j];
		}
		printf("\n");
	}
	int resultTask[n];
	int resultMachine[n];
	int resultTime[n];
	int ptr = -1;
	while( ptr < n-1 )
	{
		int time[n], machine[n];
		for (int i = 0 ; i < n ; ++i )
		{
			int minimum = INF;
			int pos = -1;
			for ( int j = 0 ; j < m ; ++j )
			{
				if ( array[i][j] < minimum )
				{	
					minimum = array[i][j];
					pos = j;
				}
			}
			time[i] = minimum;
			machine[i] = pos;
		}
		int minimum = INF;
		int pos = -1;
		for ( int i = 0 ; i < n ; ++i )
		{
			if ( time[i] < minimum )
			{
				minimum = time[i];
				pos = i;
			}
		}
		resultTask[++ptr] = pos;
		resultMachine[ptr] = machine[pos];
		resultTime[ptr] = tmp[pos][machine[pos]];
		if( minimum > makespan )
			makespan = minimum;

		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < m ; ++j )
			{
				if( i == resultTask[ptr] )
					array[i][j] = INF;
				else if ( j == resultMachine[ptr] && array[i][j] != INF )
					array[i][j] += minimum;
				else
					continue;
			}
		}
	
	}
	// Visualize Results 
	printf("\n ----- Scheduled Tasks are -----\n");
	for ( int i = 0 ; i < n ; ++i )
	{
		printf("\nTask %d Runs on Machine %d with Time %d ms\n",resultTask[i]+1, resultMachine[i]+1, resultTime[i]);
	}
	printf("\nMakespan : %d ms\n", makespan);
	
	return 0;
}
