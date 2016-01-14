import re
import sys
from decimal import Decimal

def main():

    # check to see if the usage is valid
    if len( sys.argv ) is not 2:
        print "Usage: python linpack_avg.py <text file from the linpack test>"
        sys.exit(0)

    # get the lines with the values
    lines_with_values = find_values()

    # extract the values from the lines with the values
    values = extract_values( lines_with_values )

    # calculate the averate
    average = calculate_average( values )
    
    print '%.3E' % Decimal( average ) + ' Gflops average'

def find_values():

    # open file
    fin = open( sys.argv[1] )

    # counter to count lines to values
    i = 1

    # hold the lines
    lines_with_values = []

    # go through each line in file
    for line in fin:   
        # if we're counting the lines
        if i <= 4:
            # if we reached the line with the values
            if i == 4:
                # grab that value
                lines_with_values = lines_with_values + [line]
                # nullify counter
                i = 10
            # if we're still counting, increment
            else:
                i = i + 1
        # start counting lines once we reached a passed test
        elif "PASSED" in line:
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

if __name__ == "__main__":
    main()
