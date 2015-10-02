#include <omp.h>
#include <stdio.h>

/* This counts the number of threads */
/* compile: gcc -o <exe> -fopenmp countNumThreads.c -std=c99 */
/* usage: ./<exe> */

void hello( void )
{
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();

  printf( "Hello from thread %d of %d\n", my_rank, thread_count );
}

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
        return 0;
    }

    int desired_num_threads = strtol( argv[1], NULL, 10 );
 
    // current thread ID in parallel region
    int this_thread = omp_get_thread_num();
    // number of threads available in this parallel region
    int num_threads = omp_get_num_threads();
    // number of processes
    int num_procs = omp_get_num_procs();
    // max number of threads requested
    int max_threads = omp_get_max_threads();

    printf( "Current thread: %d\n", this_thread );
    printf( "Number of threads available in this parallel region: %d\n", num_threads );
    printf( "Number of processes: %d\n", num_procs );
    printf( "Max number of threads requested: %d\n", max_threads );

    # pragma omp parallel num_threads( num_procs )
    hello();
    
    # pragma omp critical
    printf( "We are done\n" );

    int i;
    int n = 249;
    printf( "N: %d\n", n );
    # pragma omp parallel for num_threads( num_procs )
    for( i = 0; i < n; i++ )
    {
        this_thread = omp_get_thread_num();
        printf( "Hi from thread %d\n", this_thread );
    }

    return 0;
}
