#the purpose of this progran is to ask the user information on,team name, city, sport, mascot, team batting average, team pitching average all about a team, then give that information back using getters and setters
import chp11_spring2022_lab_def

def intro():
	print("the purpose of this progran is to ask the user information on,team name, city, sport, mascot, team batting average, team pitching average all about a team, then give that information back using getters and setters")



def main(): #main feild
	intro()
	
	test = making() #creates list to be used
		

		
	
	display(test) #displays the information entered to user

	exit() #exits program
	
def making():
	again = 'y' #variable for repeating information
	ball_list= [] #lsit for user
	
	while again.lower()=='y': #repeates when allowed
		name = input("What is the team name? ") #asks user name
		city =input("what city are they located? ") #asks user city
		sport =input("what sport do they play? ") #asks user sport
		mascot = input("What is their mascot? ") #asks user mascot
		batting = input("What is there batting average? ") #asks user batting average
		ERA = input("What is there team pitching average? ") #asks user pitching average
		
		ball = chp11_spring2022_lab_def.MLB_Teams(name,city,sport,mascot,batting,ERA) #sends information to getters
		
		ball_list.append(ball) #expands lists
		
		again=input("enter more data again? (y/n)" ) #resets the again variable
	return ball_list #returns school lists
	
		

def display(ball_list): #displays list
	for item in ball_list: #allows list answers to be shown to user
		print(f'team:  {item.get_team_name()}') #displays name answers
		print(f'city:  {item.get_home_city()}')# displays city answers
		print(f'Sport:  {item.get_sport()}') #displays sport answers
		print(f'mascot:  {item.get_mascot()}') #displays mascot answers
		print(f'team batting average:  {item.get_team_batting_average()}')# displays batting average answers
		print(f'team pitching average:  {item.get_team_pitching_ERA()}') #displays pitching average answers


main() #starts program