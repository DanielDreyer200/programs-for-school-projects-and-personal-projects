# Module for Lab #8, problem #3 problem by Rob Brown/Maria Burness.
# Class Information already exists with team name, home city, and sport played
# attributes. It also contains all setters/getters for those attributes.

# You will need to create a subclass based on this defined class in this module
# with getters and setters.
# You will need to upload your revised module file along with the other file
# for this lab problem.


class Professional_Sports_Team:
    # Directory class will create an object that stores team name,
    # home city, and sport played.
    def __init__(self, team_name, home_city, sport):
        self.__team_name = team_name
        self.__home_city = home_city
        self.__sport = sport

    # Mutators/Setters
    def set_team_name(self, team_name):
        self.__team_name = team_name

    def set_home_city(self, home_city):
        self.__home_city = home_city

    def set_sport(self, sport):
        self.__sport = sport

    # Accessors/Getters
    def get_team_name(self):
        return self.__team_name

    def get_home_city(self):
        return self.__home_city

    def get_sport(self):
        return self.__sport



class MLB_Teams(Professional_Sports_Team):
	def __init__(self,team_name, home_city, sport, mascot, team_batting_average, team_pitching_ERA):
		Professional_Sports_Team.__init__(self,team_name, home_city, sport)
		self.__mascot = mascot
		self.__team_batting_average = team_batting_average
		self.__team_pitching_ERA = team_pitching_ERA



	def set_mascot(self, mascot):
		self.__mascot = mascot

	def set_team_batting_average(self, team_batting_average):	
		self.__team_batting_average = team_batting_average

	def set_team_pitching_ERA(self, team_pitching_ERA):
		self.__team_pitching_ERA = team_pitching_ERA
    # Accessors/Getters
	def get_mascot(self):
		return self.__mascot

	def get_team_batting_average(self):
		return self.__team_batting_average
	def get_team_pitching_ERA(self):
		return self.__team_pitching_ERA