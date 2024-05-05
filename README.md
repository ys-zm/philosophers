Implementation of the **Dining Philosophers Problem**. A simulation of concurrent programming where multiple threads run independently and the read/write access of shared resources are protected (using mutexes).

---
Overview
N philosophers sit around a circular table, each one having brought one fork only. Tragically, they are only able to eat using two forks, so when hungry, they must borrow the fork of their neighbour (hygiene is not an issue here). This means two philosophers that are sitting next one another cannot eat at the same time. 

Throughout the simulation, the philosophers complete three tasks on repeat for a given amount of time: eat, sleep and think. If they do not eat in time, they die.

The simulation runs with the inputted time data, and stops if/ when a philosopher dies, or the user quits the program.

---
Compiling:  
1.`make` creates the executable named "philo"  
2. `make clean` removes object files  
3. `make fclean` removes object files and the executable  
4. `make re` calls `make fclean` followed by `make`  

Usage:
```
./philo [n_philos] [time_to_die] [time_to_eat] [time_to_sleep] (max_meals)
```
Parameters:
n_philos: the number of philosophers in the simulation, minimum 1 and maximum 200
time_to_die: the number of milliseconds it takes for a philospher to die without eating
time_to_eat: the number of millisecondsfor a philosopher to eat
time_to_sleep: the number of milliseconds for a philosopher to sleep
