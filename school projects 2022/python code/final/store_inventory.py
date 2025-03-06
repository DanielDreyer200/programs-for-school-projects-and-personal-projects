# Daniel Dreyer
# This file and the other file called retail.py contain errors.
# 1. Read the problem in Canvas.
# 2. Fix the mistakes in the code. There are 5 mistakes to find. (4 points each) 
# 3. Put a comment next to the corrected code using the # symbol to explain each mistake.
# 4. Save both corrected files, zip, and submit to Canvas. 

#fix 2: remove the .py  as we dont need it for the comunications and it causes errors if it where there
import retail

def main():
    # Intro message
    intro()
    
    # Create three instances of RetailItem.
    item1 = retail.RetailItem('Jacket', 12, 59.95)
    item2 = retail.RetailItem('Designer Jeans', 40, 34.95)
    item3 = retail.RetailItem('Shirt', 24.95, 20)


    # Display information.
    print ('Retail Item 1: ')
    print (item1)
    print()
    print ('Retail Item 2:')
    print (item2)
    print()
    print ('Retail Item 3:')
    print (item3)

def intro():
    print('This program will demonstrate the use of classes to create a Retail Item')
#fix 1: print statment needs an  apostrophe at the front to print correctly
    print('object to save information.')
    
# Call the main function.
main()

