#this program is to ask the user for the steps they have taken each day, give an average, tells them the lowest amount of steps and highest

def intro():
	print("this program is to ask the user for the steps they have taken each day, give an average, tells them the lowest amount of steps and highest")


def main():
	intro() #runs intro 
	steps=question() #gets final verriable from questin argument
	totaling = total(steps) #totalof added steps
	lowest = min(steps) #lowest step total
	high=max(steps) #highest step total
	average=totaling/7 #average step total
	print("lowest amount of steps on a day: ",lowest) #prints highest
	print("highest amounts of steps on a day: ",high) #prents lowest
	print("average amounts of steps in the week: ",average) #prents average

def question(): #questions for each day of the week
	week =[] #list for all subsiquent variables
	
	#questions for amount of steps each day of the week
	x = float(input("how many steps did you walk sunday?"))
	week.append(x)
	x = float(input("how many steps did you walk monday?"))
	week.append(x)
	x = float(input("how many steps did you walk tuesday?"))
	week.append(x)
	x = float(input("how many steps did you walk wednesday?"))
	week.append(x)
	x = float(input("how many steps did you walk thursday?"))
	week.append(x)
	x = float(input("how many steps did you walk friday?"))
	week.append(x)
	x = float(input("how many steps did you walk saturday?"))
	week.append(x)
	
	return week #returns all list variables

def total(listing): #allows for all variables in the list to be added together
	total =0.0
	for num in listing:
		total += num
	return total
main()