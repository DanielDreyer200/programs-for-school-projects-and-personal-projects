#this program will print cal ripken batting average to the user and the years as well

import matplotlib.pyplot as plt #inports the plot diagrams for what is needed to be created
import numpy as np

def intro():
	print("this program will print cal ripken batting average to the user and the years as well")

def main(): #main part of the program
	intro()
	file = open('cal-ripken-jr-avg.txt', 'r')#creates a way to open and read files

	num = file.readlines() #reads the lines of the file
	file.close
	
	for index in range(len(num)):
		num[index]=num[index].rstrip('\n') #combines all numbers into one line
	

#plots the points for the years on the x axis
	xpoints = np.array([1981,1982,1983,1984,1985,1986,1987,1988,1989,1990,1991,1992,1993,1994,1995,1996,1997,1998,1999,2000,2001,2002])
#plots the points for the average batting score per year on the y axis
	ypoints = np.array(num)
#lables the y axis as years
	plt.xlabel("years")
#lables the x axis as cal ripken batting average
	plt.ylabel("cal ripken batting average")
#plots the points on the graph
	plt.plot(xpoints, ypoints)
#shows the ploted graph to the user
	plt.show()
main()