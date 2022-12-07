# CSProjects
These are my personal projects. Below are the descriptions of the projects.

**Redistricting Program**
This program redirects the state of New Jersey and focuses on improving the current 2020 sensus map. The purpose of redistricting was to increase competitiveness. The algorithm is based on the Flip and Recominaition algorithm by Amaria Becker and Justin Solomon in their article, Redistricting Algorithms. The algorithm focuses on creating a map based on an existing one, which has many benefits. Our algorithm takes the current 2022 map and identifies the potential precincts for redistricting. We then assign these precincts to the other bordering districts they are not a part of unless they violate the state’s redistricting rules (not contiguous or population deviation overflow). For example, if precinct C is between districts A and B, we assign the precinct to district B because it is in A unless it violates the rules. This process is known as the flip step and is done many times over and over again. This will in turn create a map that is different from the original one. 

In the code, the function swap_district takes a precinct and a district and determines if a swap should be made. The function has four checks: partisanship, population, compactness, and contiguity. For the partisanship check, the function calculates the change in partisanship from the swap, if this causes the district to become more partisan it doesn't swap. For the second check population, the function ensures that after the swap, both districts stay within some tolerance which we set to 4%. For compactness, it calculates the Polsby Popper compactness once at the beginning of the program, stored in the "district_compactness" variable. Then it makes sure that the compactness stays within 0.5 of the original value. For contiguity, swap_district checks that the district formed is contiguous by checking to see if it is a polygon. Swap_district takes an input, n, which is the number of swaps that occur. The algorithm first identifies potential swaps (grey areas above) by checking a precinct compared to its neighbors and then the swap_district function is called. The function stops when n is reached and if there are no swaps to be made it ends, otherwise it keeps going until it runs out of iterations. The output shows what percentage of potential swaps meet the criteria. The function is deterministic and also will end given restrictive constraints.

**Housing Machine Learning Program**
This program is a minor machine learning program that uses historical data to predict
house prices based on particular attributes. What I learned from this program is that machine learning is very linear algebra based, there are a lot of vectors and matrices involved. In this program I read the data and based on it I multiplyed,  transposed, and inverted the matrices. I used Gauss-Jordan elimination for finding inverses.

Our goal will be to estimate the prices Y for some houses with attributes X′. This is easily done
if we know the weights W, but we do not.

You will write a program estimate that uses a training data set to learn weights for a set of house
attributes, and then applies those weights to a set of input data to calculate prices for those houses estimate takes two arguments, which are the paths to files containing the training data and input
data.




**Assigning Student Housing Program**
We first put all the students who wanted housing into a master list. We separated the undergraduate students from the graduate students. We then separated the graduate and undergraduate housing. The algorithm chooses students at random based on our priority rules (below), the algorithm does not choose a room at random it chooses the first room in the list that satisfies the student’s needs. To use this we used python lists and python tables. 

(CASE 1)
if students column contains ['undergrad'],accessibility==1, and low_income ==1:
    pick them first and assign to a random room
    remove the empty room from list
    remove that student from master list
    
(CASE 2)
else if accessibility==1, and low_income ==1:
    pick them second and assign to a random room
    remove the empty room from list
    remove that student from master list

(CASE 3)
else if accessibility==1:
    pick them third and assign to a random room
    remove the empty room from list
    remove that student from master list

(CASE 4)
else if low_income ==1:
    pick them fourth and assign to a random room
    remove the empty room from list
    remove that student from master list

(CASE 5)
else if undergraduate=1:
    pick them fifth and assign to a random room
    remove the empty room from list
    remove that student from master list

(CASE 6)
else if graduate==1:
    pick them five and assign to a random room
    remove the empty room from list
    remove that student from master list

We did this for each student and had a separate list for the removed students and housing rooms. 





**Student Course Selection Program**
The program I want to talk about is Student Selection Program. So how the project works is that it takes in an ID number that represents a student, and from that ID number, you can add and remove classes. You can also view all the courses you are taking and exit the program. This is all in a little menu. When adding a course the program asks you for the name, section, and credit amount. You can add as many classes as you would like.
 I made this project for 2 reasons I wanted to have a program that could help me organize the classes I wanted to take. You can add up to 3 people or sections of data and each person/section represented the courses in the semesters I had left for college. 
The second reason I created this program was to learn more about linked lists. After completing the project I learned that linked lists are a great way to efficiently add and remove elements in a list. For each of the 3 people/sections, I made a linked list so that their information was separate. And what linked lists taught me was that just by the nature of how linked lists are made adding and removing elements is easy; you just change the pointers and references of the nodes around to the new node you are adding. 

**Linked list program** - I made this program because I wanted to learn more about linked lists and C. This program takes user input and based on that input the program can insert, delete, and print the length of the list. To do this I used head nodes and tail nodes. 


**Movie Recommendation Program** - So watching movies is one of my passions, and I wanted to have a program that could recommend movies to others. In this program, you can choose from many different genres of movies such as romance, action, or horror, and the program will give you recommendations. 

**Base Converter** - This program is used to convert a hex number into its decimal equivalent. As you know hexadecimal is a numbering system with a base of 16, it's used to represent large numbers with few digits. It goes from the numbers 0-9 to the letters A, B, C, D, E, and F from there it is converted to the decimals of base 10.

**Lock Program** - This program sets a three-digit lock and from there you can close the lock, alter the combination, see what number is at the top of the combination attempt, and check the status of the lock (see if it opened or closed), and finally, you can attempt to open the lock. In this program, I used getters and setters to display and turn the lock. 




**Binary Tree program** - I made this program because I wanted to learn more about binary trees and C. This program takes user input and based on that input the program can insert, search, and print the length of the tree. To do this I used head nodes and tail nodes. 
Set the current node to be the root node of the tree.
If the target value equals the key value for the current node, then the target value is found. ...
If the target value is less than the key value for a node, make the current node the left child.

