#the point of this program is to tell the user the title, author, price, and rating on amazon, and displays them back to the user using the getter and setter methods


import Books


def intro(): #intro statment
	print("the point of this program is to tell the user the title, author, price, and rating on amazon, and displays them back to the user using the getter and setter methods")



def main(): #main feild
	intro()  #returns intro
	
	read1 = Books.Book('Green Eggs and Ham', 'Dr.Seuss', '$5.98','4.9 Stars on amazon') #info for book 1
	read2 = Books.Book('Polar Express 30th Anniversary Edition', 'Chris Van Allsburg ', '$9.67','4.9 Stars on amazon') #info for book 2
	read3 = Books.Book('The Boundless', 'Kenneth Oppel', '$7.70','4.5 Stars on amazon') #info for book 3
	read4 = Books.Book('A Clash of Kings: A Song of Ice and Fire, Book 2', 'George R.R. Martin', '$15.99','4.7 Stars on amazon') #info for book 4

	print(read1) #reads book 1 info
	print(read2) #reads book 2 info
	print(read3) #reads book 3 info
	print(read4) #reads book 4 info
	
main() #starts program