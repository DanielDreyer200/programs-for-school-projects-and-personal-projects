#this program is to compare 2 files of players on the orioles in 2020 and 2021 and tell the user who returned from the previouse year, along with how many that is, along with the total different players across both years, and the total number of differeent players that is.

def intro():
	print("this program is to compare 2 files of players on the orioles in 2020 and 2021 and tell the user who returned from the previouse year, along with how many that is, along with the total different players across both years, and the total number of differeent players that is.")

def main():
	intro()
	file1 = open('Orioles_2020.txt','r') #reads text file for orioles 2020
	file2 = open('Orioles_2021.txt','r')#reads text file for orioles 2021
	fileread1= file1.read()#program reads file
	fileread2= file2.read()#program reads file
	list_1 = fileread1.split() #deliminitor for each word in text file to be an individual componemt
	list_2 = fileread2.split()#deliminitor for each word in text file to be an individual componemt
	set_1= set( list_1 ) #set for each of those lists
	set_2= set( list_2 ) #set for each of those lists
	same_orioles = set_1.intersection(set_2) #only counts the words that are in both sets
	total_orioles = set_1.union(set_2) #only counts the words in each set that havent already aperared
	
	print(f" in both years 2020 and 2021 they have the following players: {same_orioles} \nTheir are {len(same_orioles)} players who were on both years." ) #displays same_orioles and the amount of words in the section
	print(f"in total the players who played at least in 1 of the years were: {total_orioles} \nThere were {len(total_orioles)} players acrross both years")#displays total_orioles and the amount of words in the section
main()