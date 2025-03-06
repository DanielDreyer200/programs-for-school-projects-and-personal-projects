# Daniel Dreyer
# This file and the other file called store_inventory.py contain errors.
# 1. Read the problem in Canvas.
# 2. Fix the mistakes in the code. There are 5 mistakes to find. (4 points each) 
# 3. Put a comment next to the corrected code using the # symbol to explain each mistake.
# 4. Save both corrected files, zip, and submit to Canvas.

class RetailItem:
    def __init__(self, description, inventory, price):
        self.__description = description
        self.__inventory = inventory
        self.__price = price
        
    def set_description(self, description):
        self.__description = description

    def set_inventory(self, inventory):
        self.__inventory = inventory

    def set_price(self, price):
        self.__price = price
#fix 3: all def functions are on the wrong lines and need to be moved back
#fix 4: all return dunctions are on the wrong lines and need to be moved back
    def get_description(self):
        return self.__description
            
    def get_inventory(self):
        return self.__inventory
            
    def get_price(self):
        return self.__price
#fix 5: make price into a string so it can be printed out
    def __str__(self):
        result = 'Description: ' + self.get_description() + '\n' + \
                     'Units in inventory: ' + str(self.get_inventory()) + \
                     '\nPrice: $' + str(self.get_price())
        return result


