
class Book: #class for the getters and setters for book informations 
	
	def __init__(self,title,author,price,rating): #defines important initial variables for the program 
		self.__title = title 
		self.__author = author 
		self.__price = price
		self.__rating= rating 

	def set_title(self, title):  #all setters are defined this is to set data points for theprogram later
		self.__title = title  
	def set_major(self, author): 
		self.__author = author  
	def set_price(self, price): 
		self.__price = price 
	def set_rating(self,rating): 
		self.__rating = rating 

	def get_title(self):  #all getters are defined, this is to give data points to the user
		return self.__title 
	def get_author(self):
		return self.__author 
	def get_price(self):
		return self.__price 
	def get_rating(self):
		return self.__rating
	
	def __str__(self): #string method combines all variables together and allows them to be read to the user
		return self.__title + ' was written by ' + self.__author + ' and is priced at ' + self.__price + ' with a rating of ' + self.__rating