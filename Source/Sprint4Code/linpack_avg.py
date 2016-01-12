import re
import sys

def main():

    # check to see if the usage is valid
    if len( sys.argv ) is not 2:
        print "Usage: python linpack_avg.py <text file from the linpack test>"
        sys.exit(0)

    ## for my selfish reasons
    for a in sys.argv:
        print a


    # get the lines with the values
    lines_with_values = find_values()

    ##for my selfish reasons
    ##words = lines_with_values[2].split()
    ##print words

    # extract the values from the lines with the values
    values = extract_values( lines_with_values )

    ##for my selfish reasons
    print values

    average = calculate_average( values )

    print average


def find_values():

    # open file
    print sys.argv[1]
    fin = open( sys.argv[1] )

    # counter to count lines to values
    i = 1

    # hold the lines
    lines_with_values = []

    # go through each line in file
    for line in fin:   
        # if we're counting the lines
        if i <= 4:
            print i
            # if we reached the line with the values
            if i == 4:
                # grab that value
                lines_with_values = lines_with_values + [line]
                ##print line
                # nullify counter
                i = 10
            # if we're still counting, increment
            else:
                i = i + 1
        # start counting lines once we reached a passed test
        elif "PASSED" in line:
            print "we got a pass!"
            i = 1

    # return the lines
    return lines_with_values

def extract_values( lines ):
    
    # holds the values
    values = []

    for line in lines:
        words = line.split()
        values = values + [words[ len(words) - 1]]   

    return values

def calculate_average( str_values ):

    num_values = len( str_values ) - 1
    sum_values = 0

    for i in range( 0, len( str_values ) - 2 ):
        sum_value = sum_values + float( i )

    return sum_values / num_values

if __name__ == "__main__":
    main()
