#this program is to take the sentance that is created by the user and make a new password from the first letter of each sentance
def intro():#intro to the user
	print("this program is to take the sentance that is created by the user and make a new password from the first letter of each sentance")
def first(letter): #creates a definition for making an algerithm for finding the first letter of each word 
 
    result = "" #variable to be the start that is then added too
 
   
    v = True
    for x in range(len(letter)):
      
        if (letter[x] == ' '):#if theres a space then v is turns 
            v = True
 
       #if true you can copy the character in the output then set v to false
        elif (letter[x] != ' ' and v == True):
            result += (letter[x])
            v = False
 #returns the combined form of all the fist letters together
    return result
 

if __name__ == "__main__": #main definition
    intro()
    letter = input("please write a sentance and i will create a pasword based on the first level of each word \n")
    print("your new password is:",first(letter))
 #prints the final result





