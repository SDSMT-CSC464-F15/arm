import matplotlib
import pylab

def main():

    results = [[1,0,1],[0,1,0],[1,1,0]]

    x = []
    y = []

    for ind_1, sublist in enumerate(results):
        for ind_2, ele in enumerate(sublist):
            if ele == 1:
                x.append(ind_1)
                y.append(ind_2)

    matplotlib.pyplot.scatter(x,y)
    matplotlib.pyplot.show()

if __name__ == "__main__":
    main()
