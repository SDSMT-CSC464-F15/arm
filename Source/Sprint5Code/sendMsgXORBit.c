// sendMsgXORBit.c
//
// This mode of communication takes the start and end node values,
// XOR's them, and from that, determine the path for communication.
// This is assuming the devices are in a hypercube
//


#include <stdio.h>
#include <stdlib.h>

// function prototypes
int getDistance( int, int );


int main()
{
    //char* startNode, endNode;
    int n1, n2;
    int flip1, flip2, flip3;
    int dist;

    printf( "%s", "Starting node: " );
    scanf( "%d", &n1 );
    printf( "%s", "Ending node: " );
    scanf( "%d", &n2 );    

    // convert to ints
    /*
    n1 = atoi( startNode );
    n2 = atoi( endNode );
    */

    // get the distance between the two
    dist = getDistance( n1, n2 );

    printf( "Distance between %d and %d: %d\n", n1, n2, dist );

    // Going by bit msb to lsb
    for( int bit = 0; i < 3; i++ )
    {
        flip1 = flipBits( &n1, dist, bit );
    }
    
    return 0;
}

int getDistance( n1, n2 )
{
    int dist;
    dist = n1 ^ n2;
    return dist;
}

flipBits( int &n1, int dist, int bit )
{

}
