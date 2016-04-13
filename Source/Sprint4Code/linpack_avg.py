import re
import sys
from decimal import Decimal
import pylab
import matplotlib
import math

def main():

    # check to see if the usage is valid
    if len( sys.argv ) is not 1:
        print "Usage: python linpack_avg.py"
        sys.exit(0)

    # holds the average results and the number of ODROIDS to be graphed
    x = [1, 2, 3, 4, 5, 6, 7, 8]
    y = []

    # files containing the results
    results = [ 'results1.txt', 'results2.txt', 'results3new.txt', 'results4.txt', 'results5.txt', 'results6.txt', 'results7.txt', 'results8.txt' ]

    # counter for number odroids was tested
    num_odroids = 1

    # go through each test result
    for result in results:
        # get the lines with the values
        lines_with_values = find_values( result )

        # extract the values from the lines with the values
        values = extract_values( lines_with_values )
        print values

        # calculate the averate
        average = calculate_average( values )
    
        print 'Average on ' + str(num_odroids) + ' ODROIDS: ' + '%.3E' % Decimal( average ) + ' Gflops'

        # increment the ODROID counter
        num_odroids = num_odroids + 1

        # add average to graph
        y = y + [average]
	print y

    graph_scatter( x, y )

def find_values( file_name ):

    # open file
    fin = open( file_name )

    # counter to count lines to values
    i = 10

    # hold the lines
    lines_with_values = []

    # go through each line in file
    for line in fin:   
        # if we're counting the lines
        if i <= 2:
            # if we reached the line with the values
            if i == 2 and ":" not in line:
                # grab that value
                lines_with_values = lines_with_values + [line]
                # nullify counter
                i = 10
            # if we're still counting, increment
            else:
                i = i + 1
        # start counting lines once we reached a passed test
        elif "Gflops" in line:
            i = 1

    # return the lines containing the value
    return lines_with_values

def extract_values( lines ):
    
    # holds the values
    values = []

    # for each line, split into words
    for line in lines:
        words = line.split()
        # extract the last word which holds the value for that test
        values = values + [words[ len(words) - 1]]   

    # return the list of the values
    return values

def calculate_average( values ):

    num_values = len( values ) - 1
    sum_values = 0

    # add the values
    for i in range( 0, num_values ):
        # if it's a valid value, add it to the total sum
        if is_float( values[i] ):
            sum_values = sum_values + float( values[i] )

    # calculate the average and return it
    return sum_values / num_values

def is_float( value ):

    try:
        float( value )
        return True
    except:
        return False

def graph_scatter( x, y ):

    pylab.xlabel( 'Number of ODROIDS' )
    pylab.ylabel( 'Average speed (GFlops)' )
    pylab.title( 'LINPACK Test Results' )
    matplotlib.pyplot.scatter( x, y )
    matplotlib.pyplot.show()

if __name__ == "__main__":
    main()
