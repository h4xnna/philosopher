

# 🍽️ Philosopher

An elegant and robust implementation of the **Dining Philosophers Problem** in C, exploring the fundamental challenges of concurrency, mutex synchronization, and deadlock prevention.

https://github.com/user-attachments/assets/fbca47c1-416a-430b-a03d-9a544070dccf
## About

This project simulates **N philosophers** seated around a circular table, each alternating between three states: **thinking**, **eating**, and **sleeping**. To eat, a philosopher must acquire both adjacent forks, creating a classic concurrency scenario where management of shared resources becomes critical.

**Main objective**: Implement a solution that avoids deadlock and guarantees that philosophers can eat without ever starving.

## Features

- ✅ **Multi-threaded Simulation**: Each philosopher runs in its own thread
- ✅ **Mutex Synchronization**: Safe management of shared forks
- ✅ **Starvation Detection**: Continuous monitoring to identify dead philosophers
- ✅ **Real-time Logging**: Visualize each action with timestamps
- ✅ **Deadlock Prevention**: Robust resource management algorithm
- ✅ **Customizable**: Adjust the number of philosophers and timings

## Installation

### Prerequisites
- **Compiler**: gcc/clang
- **System**: Linux/macOS
- **Libraries**: pthreads (included by default)

### Compilation

```bash
git clone git@github.com:h4xnna/philosopher.git
cd philosopher
make
```

The `philo` binary will be created in the current directory.

## Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Parameters

| Parameter | Description | Value (ms) |
|-----------|-------------|---|
| `number_of_philosophers` | Number of philosophers (min: 1) | - |
| `time_to_die` | Delay before a philosopher dies if they don't eat | milliseconds |
| `time_to_eat` | Duration of a meal | milliseconds |
| `time_to_sleep` | Duration of sleep | milliseconds |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Number of meals before termination | - |

### Examples

```bash
# 5 philosophers, 800ms before starvation, 200ms to eat, 200ms to sleep
./philo 5 800 200 200

# Same as above, but each philosopher must eat at least 7 times
./philo 5 800 200 200 7
```

## Output Example

```
0 ms: Philosopher 1 has taken a fork
0 ms: Philosopher 1 has taken a fork
0 ms: Philosopher 1 is eating
200 ms: Philosopher 1 is sleeping
205 ms: Philosopher 2 has taken a fork
...
```

## Architecture

```
philosopher/
├── src/                    # Main source code
│   ├── main.c             # Entry point
│   ├── init.c             # Thread and mutex initialization
│   ├── simulation.c        # Main simulation loop
│   ├── routine_utils.c    # Philosopher routine utilities
│   └── routine_utils2.c   # Advanced utilities
├── parsing/               # Argument validation
│   ├── check_args.c       # Parameter checking
│   ├── print_error.c      # Error handling
│   └── utils.c            # General utilities
├── printf/                # Mini ft_printf implementation
└── philo.h                # Main header file
```

## Key Concepts

### Data Structures

- **`t_philo`**: Represents each philosopher with their ID, state, and forks
- **`t_data`**: Shared data between all threads (global mutexes, parameters)

### Synchronization Mechanisms

- **Fork Mutexes**: Ensures that each fork is used by only one philosopher
- **Meal Mutex**: Protects access to last meal information
- **Print Mutex**: Prevents interleaving of log messages

### Deadlock Prevention

The implementation uses an ordered fork management strategy to avoid circular blocking situations.

## Testing

Some interesting test cases:

```bash
# Stable case - normal situation
./philo 3 310 100 100

# Unstable case - potential starvation
./philo 3 100 60 60

# Single philosopher (edge case)
./philo 1 800 200 200

# Many philosophers
./philo 200 800 200 200
```

## Cleanup

```bash
make clean      # Remove object files
make fclean     # Remove all compiled files
make re         # Recompile completely
```

## Learning Outcomes

This project covers:
-  **Multi-threaded Programming**: Thread creation and management
-  **Synchronization**: Mutexes and critical sections
-  **Deadlock & Starvation**: Identification and prevention
-  **Time Management**: Precision timing and timers
-  **Robustness**: Error handling and resource management

## 👨‍💻 Author

**hmimouni**


**Bon appétit to the philosophers! 🍴✨**
