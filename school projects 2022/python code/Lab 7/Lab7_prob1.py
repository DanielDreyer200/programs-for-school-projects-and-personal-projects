#This program is designed to ask the user for there zodiac sign and eye color and give them a superhero name based on those 2 factors
def intro():
	print("This program is designed to ask the user for there zodiac sign and eye color and give them a superhero name based on those 2 factors") #intro for the program


def main():
	intro() #intro plays in main function
	data_zodiac = {'Aries' : 'Red','Taurus' : 'Orange','Gemini' : 'Yellow','Cancer' : 'Green','Leo' : 'Blue','Virgo' : 'Indigo','Libra' : 'Violet','Scorpio' : 'Pink','Sagittarious' : 'Brown','Capricorn' : 'Gray','Aquarious' : 'Lavender','Pisces' : 'Turquoise'} #dictionary for the zodiac sign corispondents
	data_color = {'Brown' : 'Thor','Blue' : 'Wolverine','Hazel' : 'Iron Man','Green' : 'Ghost Rider','Grey' : 'Daredevil','Amber' : 'Hulk'} #eye color dictionary corispondents
	x = input("What is your Zodiac sign? (first letter must be capitalized)") #question for zodiac
	y = input("What color are your eyes? (first letter must be capitalized)")#question for eye color
	print("your superhero name is:", data_zodiac.get(x), data_color.get(y)) #final product that combines both veriables together
main() #runs program