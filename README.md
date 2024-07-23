# Dining Philosophers Problem

## ABOUT THE DINING PHILOSOPHERS PROBLEM

The dining philosophers problem is a synchronization problem. The way it works is that there are five philosophers sitting at a table,
and each philosopher has a plate of spaghetti. The table has five forks, one between each pair of adjacent philosophers. Each philosopher must
alternately think and eat. However a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only
one philosopher and so a philosopher can use the fork only if its not being used by another philosopher. After eating, they need to put the forks
down so that the other philosophers can use them.

## Glossary

- **thread** : A thread is a sequence of instructions that can be executed independently of other. Also known as a unit of CPU utilization.
- **mutex** : A mutex is a lock that is used to protect shared data from being accessed by multiple threads simultaneously.
- **deadlock** : A deadlock is a situation in which two or more competing actions are each waiting for the other to finish, and thus neither ever does.

## Function Description

- **pthread_create()** : This function is used to create a new thread.
- **pthread_join()** : This function is used to wait for a thread to terminate.
- **pthread_mutex_init()** : This function is used to initialize a mutex.
- **pthread_mutex_lock()** : This function is used to lock a mutex.
- **pthread_mutex_unlock()** : This function is used to unlock a mutex.
- **pthread_mutex_destroy()** : This function is used to destroy a mutex.
- **usleep()** : This function is used to suspend execution of the calling thread for a number of microseconds.
- **gettimeofday()** : This function is used to get the current time in microseconds.

## How to run the code

- First, clone the repository using the following command:
```bash
git clone https://github.com/Mr-Don-Leo/philo.git
```
- Then, navigate to the directory where the code is present:
```bash
cd philo
```
- Now, compile the code using the following command:
```bash
make
```
- Finally, run the code using the following command:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- For example, to run the code with 5 philosophers, a time to die of 800, a time to eat of 200, a time to sleep of 200 and each philosopher must eat 7 times, use the following command:
```bash
./philo 5 800 200 200 7
```

## Output
The output of the code will be as follows:
- The first number will be the timestamp in milliseconds.
- The second number will be the philosopher number.
- The third text will be the action that the philosopher is performing.

### Example
```bash
./philo 5 800 200 200 7
```
```
0 2 has taken a fork
0 4 has taken a fork
0 4 has taken a fork
0 4 is eating
0 2 has taken a fork
0 2 is eating
100 5 has taken a fork
200 2 is sleeping
200 4 is sleeping
200 1 has taken a fork
200 5 has taken a fork
200 5 is eating
200 3 has taken a fork
200 3 has taken a fork
200 3 is eating
400 4 is thinking
```