/********************
 * File:
 * 	ping_pong.c
 *
 * Purpose:
 * 	Pass a message between two nodes
 *
 * Input:
 * 	Size of message n
 *
 * Output:
 * 	Average time to send a message of size n from one machine to the other
 * 
 * Compile:
 *  	mpicc -g -Wall -o ping_pong ping_pong.c
 *  	or use Makefile
 *
 *  Usage:
 *      mpiexec -np <number of processes> -hostfile open1.host 
 *      		./ping_pong <size of message in bytes>
 *  
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main( int argc, char** argv )
{
	int my_rank;    //current process rank
	int comm_sz;    //number of processes
	long n; //number of bytes in message
	double start, finish, average;	//time variables
	int i;	//counter

	//grab the size of message
	n = atol( argv[1] );
	char* buffer;
	//allocate for it
	buffer = (char*) malloc( n );	
	//fill with character 'k' just to know for sure
	//that the message is filled with characters
	for( i = 0; i < n; i++ )
	{
		buffer[i] = 'k';
	}

	//start up mpi
	MPI_Init( &argc, &argv );
	//get number of processes
	MPI_Comm_size( MPI_COMM_WORLD, &comm_sz );
	//get my rank among all the processes
	MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
	
	if( my_rank == 0 )
	{
		//start the timer
		start = MPI_Wtime();
		//send the message to Process 1
		MPI_Send( buffer, n, MPI_CHAR, my_rank + 1, 0, MPI_COMM_WORLD );
		//recieve the message back from Process 1
		MPI_Recv( buffer, n, MPI_CHAR, my_rank + 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//stop the timer
		finish = MPI_Wtime();
		//calculate the average time to send a message
		//from one machine to the other
		average = (finish - start) / 2;
		//Anddddd print!
		fprintf( stderr, "Average: %lf seconds\n", average );
	}
	
	if( my_rank == 1 )
	{
		//recieve the message from Process 0
		MPI_Recv( buffer, n, MPI_CHAR, my_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		//immediately send the message back to Process 0
		MPI_Send( buffer, n, MPI_CHAR, my_rank - 1, 1, MPI_COMM_WORLD );
	}

	//shut down this mpbitch
	MPI_Finalize();

	return 0;
}
