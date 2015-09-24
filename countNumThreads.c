#include <omp.h>
#include <stdio.h>

/* This counts the number of threads */
/* compile: gcc -o <exe> -fopenmp countNumThreads.c -std=c99 */
/* usage: ./<exe>
int main()
{

 //   #pragma omp parallel
 //   parallel_prog();

    int this_thread = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    int my_start = ( this_thread ) * 10 / num_threads;
    int my_end = ( this_thread + 1 ) * 10 / num_threads;

    for( int n = my_start; n < my_end; ++n )
    {
        printf( "%d\n", n );
    }

    return 0;
}
