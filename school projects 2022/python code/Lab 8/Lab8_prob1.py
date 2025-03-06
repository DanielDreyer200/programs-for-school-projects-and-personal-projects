#the point of this program is to ask the user for the name, major and credts they have, then display them back to the user using the getter and setter methods



import Student

def intro(): #intro statment
	print("the point of this program is to ask the user for the name, major and credts they have, then display them back to the user using the getter and setter methods")



def main(): #main feild
	intro()  #returns intro
	
	
	test = making() #creates list to be used
		

		
	
	display(test) #displays the information entered to user

	exit() #exits program
	
def making():
	again = 'y' #variable for repeating information
	school_list= [] #lsit for user
	while again.lower()=='y': #repeates when allowed
		ne = input("What is your name? ") #asks user name
		ma =input("what is your major? ") #asks user major
		credit=input("how many credits have you earned? ") #asks user credit
		
		school = Student.Student(ne,ma,credit) #sends information to getters
		school_list.append(school) #expands lists
		again=input("enter more data again? (y/n)" ) #resets the again variable
	return school_list #returns school lists
		

def display(school_list): #displays list
	for item in school_list: #allows list answers to be shown to user
		print(f'name:  {item.get_name()}') #displays name answers
		print(f'major:  {item.get_major()}')# displays major answers
		print(f'credits earned:  {item.get_credit_earned()}') #displays credits earned answers
		


main() #starts program