
# Dining Philosophers Problem

### In **computer science**, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

N philosophers dine together at the same table. Each philosopher has his own plate at the table. There is a fork between each plate. The dish served is a kind of **spaghetti** which has to be **eaten with two forks**. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat his spaghetti when **he has both a left and right fork**. Thus two forks will only be available when his two nearest neighbors are not eating. After an individual philosopher finishes eating, he will put down both forks. 


<img src='https://user-images.githubusercontent.com/59456000/198906008-4135d5d2-de53-4a8b-9c24-744181f04851.png' width='275' heigth='275'></img>

• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.


