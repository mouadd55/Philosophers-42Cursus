<div align=center >
<h1>Philosophers</h1>
</div>
<p align="center">
    <img src="https://user-images.githubusercontent.com/81205527/210457725-477080a7-1a97-4968-9621-35c3e747c22b.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/get_next_line?color=blue" />
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

---

## 💡 About the project

> _In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes._

For more detailed information, look at the [**subject of this project**](https://github.com/mouadd55/Philosophers-42Cursus/blob/234696dae77b35b63a6171bf54b09b2d5c736392/Philosophers.pdf).
<br><br><br>

# Philosophers: A Concurrent Programming Journey

Philosophers is an intriguing project that draws inspiration from Edsger Dijkstra's acclaimed dining philosophers problem. This project, a vital component of the 42 school curriculum, provides a comprehensive exploration into concurrent programming, emphasizing synchronization mechanisms such as threads, mutexes, processes, and semaphores.

---

**Dive Deeper in English:**
* [Explore Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)

---


## 🧠 Project Overview

### 🍝 Defined Problem:

- Philosophers, engrossed in profound contemplation, are seated around a table.
- The table hosts a large bowl of spaghetti, necessitating two forks for consumption.
- Forks are limited to the number of philosophers present.
- Philosophers alternate between states of eating, sleeping, and thinking.
- Philosophers need to eat within specified timeframes to avoid starvation.
- Direct communication between philosophers is strictly prohibited.

The endeavor here is to formulate algorithms, addressing both mandatory and bonus requirements, that ensure the longevity of philosophers under the specified constraints.

### 🖥️ Program Parameters:

1. ```number_of_philosophers```: Specifies the number of philosophers around the table.
2. ```time_to_die```: The maximum time (in milliseconds) a philosopher can endure without eating.
3. ```time_to_eat```: The duration (in milliseconds) a philosopher needs to consume a meal.
4. ```time_to_sleep```: The time (in milliseconds) a philosopher spends sleeping.
5. ```number_of_times_each_philosopher_must_eat```: An optional argument dictating the minimum number of meals each philosopher must consume before the program concludes.

### 🗣️ Output Format:
```
[timestamp_in_ms] [X] has taken a fork
[timestamp_in_ms] [X] is eating
[timestamp_in_ms] [X] is sleeping
[timestamp_in_ms] [X] is thinking
[timestamp_in_ms] [X] died
```


## 📘 Mandatory Section: Threads and Mutexes

In this section, philosophers are represented as threads and forks as mutexes. Each philosopher must secure the adjacent forks to eat.

### 🏗️ How to Use:

Navigate to the mandatory part’s directory and compile:
```shell
cd philosophers/philo
make
```

Execute the program with suitable arguments:
```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
```

Example:
```shell
./philo 4 800 200 200 5
```

## 🌟 Bonus Section: Processes and Semaphores

Here, philosophers are processes, and forks are represented by a counting semaphore.

### 🏗️ How to Use:

Navigate to the bonus part’s directory and compile:
```shell
cd philosophers/philo_bonus
make
```

Execute the program similarly with appropriate arguments:
```shell
./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
```

Example:
```shell
./philo_bonus 4 800 200 200 5
```
