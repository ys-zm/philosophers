Implementation of the **Dining Philosophers Problem**. A simulation using concurrent programming where multiple threads run independently and share the same memory resources.

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
