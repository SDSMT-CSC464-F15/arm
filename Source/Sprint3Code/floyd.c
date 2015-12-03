/**********************8
 *
 * Compile:
 *  mpicc -g -Wall -lm -o floyd floyd.c
 *
 *  Usage:
 *  mpiexec -np <number of processes> -hostfile open2.host ./floyd <number verticies>
 */

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>	//for time()

void create_matrix( char* a, int n )
{
    //set all a[i,i] to 0
    //Loop through
    //determine if there is an edge between i + j
    //Probability that there is an edge is 33%
    //give those edges a distance 1 <= d <= 20
    //Give the no edges 99 (high number for maximum

	int i;
	
	//seed for rand()
	srand( time(NULL) );

	//fill multiples of n with 0
	for( i = 0; i < n*n; i++ )
	{
		//fill multiple of n with 0 (that's equivalent to a[i][i])
		if( i % n == 0 )
			a[i] = 0;
		else if( rand() % 2 == 0 )	//33%chance of an edge
			a[i] = rand() %20 + 1;
		else
			a[i] = 99;	//no edge
		
	}

}
/*
void floyd( char** a, int n )
{
	int i, j, k;

	for( k = 0; k < x; k++ )
	{
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < n; j++ )
			{
				if( a[i][j] > (a[i][k] + a[k][j]) ) 
					a[i][j] = a[i][k] + a[k][j];
			}	
		}	
	}
}
*/
void print_matrix( char* a, int n )
{
	//create an output file
	FILE* output;
	//open it
	output = fopen( "output.txt", "w" );
	
	//loop through the matrix and print it to file
	int i;
	for( i = 0; i < n * n; i++ )
	{
		if( i % n == 0 )
			fprintf( output, "\n" );
		fprintf( output, "%d ", a[i] );
	}
	
}

int main( int argc, char** argv )
{
	int my_rank;    //current process rank
	int comm_sz;    //number of processes
	double t1, t2, t3;	//time variables
	int i;
	char* a;
	int n;  //number of verticies

	//get n
	n = atol( argv[1] );

        MPI_Init( &argc, &argv );   //start up mpi
        MPI_Comm_size( MPI_COMM_WORLD, &comm_sz );  //get number of processes
        MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );  //get my rank among all processes


	//run serial	
	if( my_rank == 0 )
	{
		//start timer for serial time
		t1 = MPI_Wtime();
	        //allocate array
        	a = (char*) malloc( n*n );
		create_matrix( a, n );	//fill in matrix
		print_matrix( a, n );	//print the original

		//stop timer for serial time, start time for parallel time	
		t2 = MPI_Wtime();
	}

	//broadcast array to all processes
	//perform floyd
	//send to process 0
	//process 0 recieves them
	//repeat broadvast matrix to all processes

	//stop time for parallel portion
	t3 = MPI_Wtime();

	//calculate speedup, efficiency, and scalability


	MPI_Finalize(); //shut down the mpbitch

	//free array
	free( a );
	
	return 0;
}
