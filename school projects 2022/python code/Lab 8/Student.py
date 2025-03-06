

class Student: #class for students
	
	def __init__(self,name,major,credit_earned): #initial definition for the 3 main variables
		self.__name = name #defines name feild
		self.__major = major #define major feild
		self.__credit_earned = credit_earned #define credit earnd feild
		
	def set_name(self, name): #sets feild name
		self.__name = name #defines a vakue
	def set_major(self, major): #sets feild major
		self.__major = major #defines a vakue
	def set_credit_earned(self, credit_earned): #sets feild credit earned
		self.__credit_earned = credit_earned #defines a vakue

	def get_name(self): #creates a get to get information from user
		return self.__name #returns information to setter
	def get_major(self): #creates a get to get information from user
		return self.__major #returns information to setter
	def get_credit_earned(self): #creates a get to get information from user
		return self.__credit_earned #returns information to setter