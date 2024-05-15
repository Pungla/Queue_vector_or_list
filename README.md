# Round-Robin Load Balancing Simulation on C++

This project simulates the operation of a basic load balancing system at airport check-in counters using the Round-Robin algorithm. The check-in counters are selected cyclically to serve new passengers.

## Overview

The program uses two different queue implementations (vector-based and list-based) to simulate the process. It supports dynamic passenger arrivals and service times, and distributes passengers across multiple check-in counters evenly using the Round-Robin method.

## Features

- Two types of queues: vector-based and list-based
- Dynamic resizing of queues
- Cyclic distribution of passengers across check-in counters
- Simulation of passenger service times

## How It Works

### Main Functions

#### Queue Implementations

**Vector-based Queue (`queue_vector`)**
- `struct vector_Queue`
- `vector_createQueue()`
- `vector_isEmpty()`
- `resizeQueue()`
- `vector_enQueue()`
- `vector_deQueue()`
- `vector_front()`
- `vector_last()`
- `vector_clearQueue()`
- `vector_printQueue()`

**List-based Queue (`queue_list`)**
- `struct Node`
- `struct list_Queue`
- `newNode()`
- `list_createQueue()`
- `list_enQueue()`
- `list_deQueue()`
- `list_front()`
- `list_last()`
- `list_isEmpty()`
- `list_printQueue()`
- `list_clearQueue()`

#### Main Simulation (`main`)
- `main()`

### Detailed Functionality

#### Vector-based Queue

- **vector_createQueue**: Initializes a new vector-based queue.
- **vector_isEmpty**: Checks if the queue is empty.
- **resizeQueue**: Resizes the queue when it reaches capacity.
- **vector_enQueue**: Adds an element to the queue.
- **vector_deQueue**: Removes an element from the queue.
- **vector_front**: Returns the front element of the queue.
- **vector_last**: Returns the last element of the queue.
- **vector_clearQueue**: Clears the queue and frees memory.
- **vector_printQueue**: Prints the queue elements.

#### List-based Queue

- **newNode**: Creates a new queue node.
- **list_createQueue**: Initializes a new list-based queue.
- **list_enQueue**: Adds an element to the queue.
- **list_deQueue**: Removes an element from the queue.
- **list_front**: Returns the front element of the queue.
- **list_last**: Returns the last element of the queue.
- **list_isEmpty**: Checks if the queue is empty.
- **list_printQueue**: Prints the queue elements.
- **list_clearQueue**: Clears the queue and frees memory.

#### Main Simulation

- **main**: Manages the overall simulation, including:
  - Initializing queues based on user choice (vector or list).
  - Reading and parsing passenger information.
  - Distributing passengers to check-in counters using Round-Robin.
  - Simulating the passage of time and service of passengers.
  - Printing the state of each check-in counter at each time step.
  - Releasing allocated memory after simulation ends.

## Getting Started

### Prerequisites

- C++ compiler

### Example Usage

1. Enter the number of registration counters.
2. Enter the passenger information in the format `id/arrival_time/service_time` separated by spaces (e.g., `A/1/5 B/2/3 C/3/4`).
3. Choose the queue implementation method (0 for list, 1 for vector).
4. Observe the simulation output.
