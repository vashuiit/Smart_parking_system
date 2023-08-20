# Smart-Parking-System

The project is an attempt to solve the parking planning program to give timely and efficient guide information to vehicles for a real time smart parking system.

# Motivation behind the project:

● The increasing number of vehicles leading to parking problems

● Introducing Smart Parking to ease off parking problems

● Smart Parking requires Parking Planning to make best possible use of resources

● Preliminary research revealed that a real life feasible code doesn’t exist

● This project was inspired by the research paper by Xuejian Zhao, Kui Zhao and Feng Hai. There exists no code implementation of this research paper which also motivated    me to take on this challenge
# Problem Definition:

Transformed the parking planning problem into a kind of 
LINEAR ASSIGNMENT problem.

Vehicles ↔ JOBS

 
 Parking spaces ↔ AGENTS
 
Distances between 
vehicles and parking 
spaces ↔ AGENTS DOING 
JOBS

● The distances between vehicle and parking spaces are already known. Real 
  life implementation will require the use of GPS for finding this data
  
● Size of M <<< N
  where M, number of vehicles in queue is in hundreds and N is total parking 
  spots in millions
  
● If number of vehicles in the system is more than the queue then we will 
  take first M vehicles on a first come first serve basis. Our algorithm works 
  for each queue of M size which is also the size of the total vehicles in input.
  
  # Input: 
●  P, denoting the set of all vehicles having parking query in the queue ( 
     Size : M )
     
● S, denoting the set of all available parking spaces included in the 
  smart parking system ( Size : N )
  
● D; denoting the set of dij , and dij is the distance between the vehicle 
  pi (pi 
∈ P) and the parking space sj
 (sj 
∈ S) ( Size : M*N )

# Output:
● Best possible assignment
● Total cost for that assignment

# GREEDY APPROACH
● In this method we guide the vehicle, which is querying parking 
space, to the nearest available parking space.

● This approach fails miserably but is the quickest. This is actually 
real-time allotment.

● This gives us local optimization but fails for global optimization and 
is gives really high cost for our problem

● Our Modern approach will queue a fixed no of cars on first come 
first serve basis and apply a modified version of hungarian 
algorithm or linear problem assignment algorithm which is faster 
than the classical one.

● This way we can improve the time complexity of classical Hungarian 
Algorithm and optimize the cost for our greedy approach
# THE HUNGARIAN ALGORITHM (classical approach)
● The Hungarian Algorithm consists of FOUR steps
● Steps 1 and 2 are executed once only
● Steps 3 and 4 are repeated until an optimal assignment is found
● INPUT : (N X N) Square Matrix with non-negative elements only 

STEPS:
1. SUBTRACT ROW MINIMA: For each row, find the 
lowest element and 
subtract it from each 
element in that row

2. SUBTRACT COLUMN MINIMA: For each column, find 
the lowest element and 
subtract it from each 
element in that column

3. COVER ALL ZEROS WITH A MINIMUM NUMBER OF LINES: If n lines are required, an 
optimal assignment exists 
and algorithm stops; else 
step 4

4. CREATE ADDITIONAL ZEROS: ind smallest element, k not 
covered by a line in Step 3, 
Subtract k from uncovered 
elements and add k to 
elements covered twice

# MODERN APPROACH
This is achieved by selecting only the first M lowest cost spots out 
of N spots, corresponding to each vehicle P. Now, we sum up all these spots and create an array S where each 
spot is present only one time and its size is n which at worst case theoretically is M2 but practically is M <= n <<< M2 (is a constant 
multiplication of M in real life). We then create a square matrix D of size n x n, where n columns 
corresponds to S and n rows corresponding to m P vehicles and 
n-m P virtual vehicles whose distance from all spots is 0.

This method is based on classical Hungarian algorithm. Hungarian Algorithms time complexity is O(N3) which makes it impossible to solve a real life scenarios especially for parking allotment problem for a city, where N=no of spots can be in Millions. Our Modern algorithm based on the research paper solves this 
problem in O(n3) where n<<<N (of order hundreds in real life). So, Time Complexity is drastically reduced and is therefore practically implementable. Final solution doesn’t give the optimal cost rather is close to the optimal cost. 





  
  



