# Weel #1 notes

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


















