#include<stdio.h>

#define INF 1e8
int main(void)
{
	int n = 3, m = 2;
	int taskLength[3] = {28000, 25000, 70000};
	int vmMips[2] = {500, 1000};
	int MinMax[n][m], tmp[n][m];
	for( int i = 0 ; i < n ; ++i )
	{
		for ( int j = 0 ; j < m ; ++j )
		{
			MinMax[i][j] = taskLength[i]/vmMips[j];
			tmp[i][j] = taskLength[i]/vmMips[j];
			printf("| %d |", MinMax[i][j]);
		}
		printf("\n");
	}
	int resultTime[n];
	int resultMachine[n];
	int resultTask[n];
	int ptr = -1;
	int makespan = 0;
	while( ptr < n -1 )
	{
		int time[n], machine[n];
		for ( int i = 0 ; i < n ; ++i )
		{
			int max = -1;
			int pos = -1;
			for ( int j = 0 ; j < m ; ++j )
			{
				if ( MinMax[i][j] > max )
				{	
					max = MinMax[i][j];
					pos = j;
				}
			}
			machine[i] = pos;
			time[i] = max;
		}
		int min = INF;
		int pos = -1;
		for ( int i = 0 ; i < n ; ++i )
		{
			if ( time[i] < min && time[i] != INF)
			{	
				min = time[i];
				pos = i;
			}
		}
		
		resultTask[++ptr] = pos;
		resultTime[ptr] = tmp[pos][machine[pos]];
		resultMachine[ptr] = machine[pos];
		
		if ( min > makespan )
			makespan = min;
		
		for ( int i = 0 ; i < n ; ++i )
		{
			for ( int j = 0 ; j < m ; ++j )
			{
				if ( i == pos )
					MinMax[i][j] = INF;
				else if ( j == resultMachine[ptr] && MinMax[i][j] != INF )
					MinMax[i][j] += min;
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
		
		
		
			
		