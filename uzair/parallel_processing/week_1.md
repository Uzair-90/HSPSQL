# Week no. 1 notes

The state of a single thread is thus very similar to that of a process.
It has a program counter (PC) that tracks where the program is fetching instructions from. Each thread has its own private set of registers it
uses for computation; thus, if there are two threads that are running on
a single processor, when switching from running one (T1) to running the
other (T2), a context switch must take place. The context switch between
threads is quite similar to the context switch between processes, as the
register state of T1 must be saved and the register state of T2 restored
before running T2. With processes, we saved state to a process control
block (PCB); now, we’ll need one or more thread control blocks (TCBs)
to store the state of each thread of a process. There is one major difference,
though, in the context switch we perform between threads as compared
to processes: the address space remains the same (i.e., there is no need to
switch which page table we are using).

### Page table

In operating systems that use virtual memory, every process is given the impression that it is working with large, contiguous sections of memory. Physically, the memory of each process may be dispersed across different areas of physical memory, or may have been moved (paged out) to secondary storage, typically to a hard disk drive (HDD) or solid-state drive (SSD).

When a process requests access to data in its memory, it is the responsibility of the operating system to map the virtual address provided by the process to the physical address of the actual memory where that data is stored. The page table is where the operating system stores its mappings of virtual addresses to physical addresses, with each mapping also known as a page table entry (PTE).

### Stack in multi-thread programme
In a multi-threaded process, each thread runs independently
and of course may call into various routines to do whatever work it is doing. Instead of a single stack in the address space, there will be one per
thread. Let’s say we have a multi-threaded process that has two threads
in it; the resulting address space looks different. There will be a single programme
code section single head but number of stacks will be equal to number of threads
in the programme.

There is also a threat which is an exception in some cases you may run out of programme
space.

## Why do we need threads?

There are at least two major reasons you should use
threads. The first is simple: parallelism. Imagine you are writing a program that performs operations on very large arrays, for example, adding
two large arrays together, or incrementing the value of each element in
the array by some amount. If you are running on just a single processor, the task is straightforward: just perform each operation and be done.
However, if you are executing the program on a system with multiple
processors, you have the potential of speeding up this process considerably by using the processors to each perform a portion of the work. The
task of transforming your standard single-threaded program into a program that does this sort of work on multiple CPUs is called parallelization, and using a thread per CPU to do this work is a natural and typical
way to make programs run faster on modern hardware.
The second reason is a bit more subtle: to avoid blocking program
progress due to slow I/O. Imagine that you are writing a program that
performs different types of I/O: either waiting to send or receive a message, for an explicit disk I/O to complete, or even (implicitly) for a page
fault to finish. Instead of waiting, your program may wish to do something else, including utilizing the CPU to perform computation, or even
issuing further I/O requests. Using threads is a natural way to avoid
getting stuck; while one thread in your program waits (i.e., is blocked
waiting for I/O), the CPU scheduler can switch to other threads, which
are ready to run and do something useful. Threading enables overlap of
I/O with other activities within a single program, much like multiprogramming did for processes across programs; as a result, many modern
server-based applications (web servers, database management systems,
and the like) make use of threads in their implementations.
Of course, in either of the cases mentioned above, you could use multiple processes instead of threads. However, threads share an address space
and thus make it easy to share data, and hence are a natural choice when
constructing these types of programs. Processes are a more sound choice
for logically separate tasks where little sharing of data structures in memory is 
needed.

## Example of thread creation

Let us take an example of a thread printing two different strings s1 and s2 in parallel
using multi threads:
```c
#include <stdio.h>
#include<string.h>
#include <assert.h>
#include <pthread.h> //include the prthread library

void *mythread(void *str) {
	printf("%s\n", (char *) str);
	return NULL;
}
int main(int argc, char *argv[]) {
	pthread_t p1, p2;
 	int rc;
 	printf("main: begin\n");
 	pthread_create(&p1, NULL, mythread, "uzair");
 	printf(" ");
	pthread_create(&p2, NULL, mythread, "rehman");
 // join waits for the threads to finish
 	pthread_join(p1, NULL);
 	pthread_join(p2, NULL);
 	printf("main: end\n");
 return 0;
}
```

### Output

```html
khans-Air:desktop khan$ ./a.out
main: begin
 uzair
rehman
main: end

```
Let us also see another example

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
	// Store the value argument passed to this thread
	int *myid = (int *)vargp;

	// Let us create a static variable to observe its changes
	static int s = 0;

	// Change static and global variables
	++s; ++g;

	// Print the argument, static and global variables
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main()
{
	int i;
	pthread_t tid;

	// Let us create three threads
	for (i = 0; i < 3; i++)
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid);

	pthread_exit(NULL);
	return 0;
}


```
### Output
```html
khans-MacBook-Air:desktop khan$ ./a.out
Thread ID: 148045824, Static: 2, Global: 3
Thread ID: 148045824, Static: 2, Global: 2
Thread ID: 148045824, Static: 4, Global: 5
```
Above programme shows thread id and each thread progress.

## Problems

In the first example there is no guarantee that which thead will run first whether
thread T1 is created first it will run first and T2 will wait for the return of the
first thread or vice versa there is no guarantee that which will run first so what 
is the actual problem here? Let us discuss it.

### Share data

The simple thread example we showed above was useful in showing
how threads are created and how they can run in different orders depending on how the scheduler decides to run them. What it doesn’t show you,
though, is how threads interact when they access shared data.
Let us imagine a simple example where two threads wish to update a
global shared variable. 

Look at the following code and see what kind of results those threads produce and then
we will discuss the problems in it and its solutions.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        counter += 1;
    }
    return NULL;
}

int main() {
    pthread_t p1, p2;

    pthread_create(&p1, NULL, mythread, NULL);
    pthread_create(&p2, NULL, mythread, NULL);

    pthread_join(p1, NULL); // Wait for thread p1 to finish
    pthread_join(p2, NULL); // Wait for thread p2 to finish

    printf("The counter value is: %d\n", counter);

    return 0;
}

```

### Output

```html
khans-Air:desktop khan$ gcc m_thread.c -lpthread
khans-Air:desktop khan$ ./a.out
The counter value is: 1280392
```

The value needs to be 2000000 but it's 1000000 why?

Let us answer the question the heart of the problem is uncotrolled scheduling.

To understand why this happens, we must understand the code sequence that the compiler generates for the update to counter. In this
case, we wish to simply add a number (1) to counter. Thus, the code
sequence for doing so might look something like this (in x86);
mov 0x8049a1c, %eax
add $0x1, %eax
mov %eax, 0x8049a1c
This example assumes that the variable counter is located at address
0x8049a1c. In this three-instruction sequence, the x86 mov instruction is
used first to get the memory value at the address and put it into register
eax. Then, the add is performed, adding 1 (0x1) to the contents of the
eax register, and finally, the contents of eax are stored back into memory
at the same address.
Let us imagine one of our two threads (Thread 1) enters this region of
code, and is thus about to increment counter by one. It loads the value
of counter (let’s say it’s 50 to begin with) into its register eax. Thus,
eax=50 for Thread 1. Then it adds one to the register; thus eax=51.
Now, something unfortunate happens: a timer interrupt goes off; thus,
the OS saves the state of the currently running thread (its PC, its registers
including eax, etc.) to the thread’s TCB.
Now something worse happens: Thread 2 is chosen to run, and it enters this same piece of code. It also executes the first instruction, getting
the value of counter and putting it into its eax (remember: each thread
when running has its own private registers; the registers are virtualized
by the context-switch code that saves and restores them). The value of
counter is still 50 at this point, and thus Thread 2 has eax=50. Let’s
then assume that Thread 2 executes the next two instructions, incrementing eax by 1 (thus eax=51), and then saving the contents of eax into
counter (address 0x8049a1c). Thus, the global variable counter now
has the value 51.
Finally, another context switch occurs, and Thread 1 resumes running.
Recall that it had just executed the mov and add, and is now about to
perform the final mov instruction. Recall also that eax=51. Thus, the final
mov instruction executes, and saves the value to memory; the counter is
set to 51 again.
Put simply, what has happened is this: the code to increment counter
has been run twice, but counter, which started at 50, is now only equal
to 51. A “correct” version of this program should have resulted in the
variable counter equal to 52.

## Race conditions

Race conditions are most commonly associated with computer science and programming. 
They occur when two computer program processes, or threads, attempt to access the same 
resource at the same time and cause problems in the system. Race conditions are 
considered a common issue for multithreaded applications.

Multiple threads executing this code can result in a race condition, we call this code a critical section. A critical section is a piece of
code that accesses a shared variable (or more generally, a shared resource)
and must not be concurrently executed by more than one thread.
What we really want for this code is what we call mutual exclusion.
This property guarantees that if one thread is executing within the critical
section, the others will be prevented from doing so.

## Critical Section

In computer science, a critical section refers to a segment of code that is executed
by multiple concurrent threads or processes, and which accesses shared resources.

## Tip

```txt
 USE ATOMIC OPERATIONS
Atomic operations are one of the most powerful underlying techniques
in building computer systems, from the computer architecture, to concurrent code (what
we are studying here), to file systems (which we’ll study
soon enough), database management systems, and even distributed systems [L+93].
The idea behind making a series of actions atomic is simply expressed
with the phrase “all or nothing”; it should either appear as if all of the actions you
wish to group together occurred, or that none of them occurred,
with no in-between state visible. Sometimes, the grouping of many actions into a
single atomic action is called a transaction, an idea developed in great detail in the
world of databases and transaction processing
[GR92].
In our theme of exploring concurrency, we’ll be using synchronization
primitives to turn short sequences of instructions into atomic blocks of
execution, but the idea of atomicity is much bigger than that, as we will
see. For example, file systems use techniques such as journaling or copyon-write in
order to atomically transition their on-disk state, critical for
operating correctly in the face of system failures. If that doesn’t make
sense, don’t worry — it will, in some future chapter.
```

# Solution

### The Wish For Atomicity

One way to solve this problem would be to have more powerful instructions that, in a single step, did exactly whatever we needed done
and thus removed the possibility of an untimely interrupt. For example,
what if we had a super instruction that looked like this:
memory-add 0x8049a1c, $0x1
Assume this instruction adds a value to a memory location, and the
hardware guarantees that it executes atomically; when the instruction
executed, it would perform the update as desired. It could not be interrupted mid-instruction, because that is precisely the guarantee we receive
from the hardware: when an interrupt occurs, either the instruction has
not run at all, or it has run to completion; there is no in-between state.
Hardware can be a beautiful thing, no?
Atomically, in this context, means “as a unit”, which sometimes we
take as “all or none.” What we’d like is to execute the three instruction
sequence atomically:
mov 0x8049a1c, %eax
add $0x1, %eax
mov %eax, 0x8049a1c
As we said, if we had a single instruction to do this, we could just
issue that instruction and be done. But in the general case, we won’t have
such an instruction. Imagine we were building a concurrent B-tree, and
wished to update it; would we really want the hardware to support an
“atomic update of B-tree” instruction? Probably not, at least in a sane
instruction set.
Thus, what we will instead do is ask the hardware for a few useful
instructions upon which we can build a general set of what we call synchronization primitives. By using this hardware support, in combination with some help from the operating system, we will be able to build
multi-threaded code that accesses critical sections in a synchronized and
controlled manner, and thus reliably produces the correct result despite
the challenging nature of concurrent execution. Pretty awesome, right?
This is the problem we will study in this section of the book. It is a
wonderful and hard problem, and should make your mind hurt (a bit).
If it doesn’t, then you don’t understand! Keep working until your head
hurts; you then know you’re headed in the right direction. At that point,
take a break; we don’t want your head hurting too much.

## One more problem






















