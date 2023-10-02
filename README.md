Inter-Process Communication with UNIX Signals (Client-Server Model)
Overview
This program demonstrates the power of UNIX signals, specifically SIGUSR1 and SIGUSR2, to enable seamless inter-process communication in a client-server model. Whether you're a seasoned developer or just starting with system programming, you'll find this project intriguing.

Server Operation
Our server program is a masterpiece of asynchronous communication. It elegantly sets up signal handlers and gracefully enters an infinite loop, patiently waiting for incoming signals. This ensures a persistent and responsive communication channel without gobbling up excessive system resources.

Extract PID Function
Meet the extract_pid function! It's like a magician that converts a full process ID (PID) to a numerical integer using ft_atoi and sends a SIGUSR1 signal to that process. Abracadabra!

Countbit Function
Do you love playing with bits and bytes? Our countbit function is your trusty sidekick for all your binary operations and bitwise manipulations. It meticulously calculates the decimal value of a given bit and accumulates it in a variable called 'let.' It's like a math wizard for binary data!

Signal Handlers
In the world of signals, signal handlers are the gatekeepers. Our program registers these handlers using the signal function, and they swing into action whenever a SIGUSR1 or SIGUSR2 signal is received. They are like the Sherlock Holmes of signals, making decisions based on the type of signal they encounter.

Infinite Loop
Picture our server program as a vigilant guardian, running an infinite loop to continuously listen for signals. It's always on the lookout, ensuring responsiveness even when bombarded with multiple signals.

Client Operation
Now, let's talk about the client side! The bugs function is here to ensure that everything runs smoothly. It double-checks the command line arguments, making sure the PID values are valid. If any issues are detected, it exits with a non-zero status. It's like your program's quality control inspector.

Receiver Process ID
The receiver process ID is extracted from the command line arguments, converted into an integer, and ready to receive messages. It's like your postal address in the digital world.

Sender Process ID
The sender process ID is the identity card of our sender program. It's obtained using getpid and transformed into a string. This ID card is sent to the receiver process, like introducing yourself to a new friend.

Message Transmission
Imagine sending secret messages! The sender program sends messages bit by bit. If it's a '1,' it discreetly sends a SIGUSR1 signal; if it's a '0,' a SIGUSR2 signal is dispatched. A brief pause follows each signal, creating a suspenseful atmosphere.

Terminating Null Character
Every great message needs an end, right? A terminating null character (0) is sent to mark the conclusion of your encoded message. It's like signing your name at the end of a letter.

Signal Functions
In our toolkit, we have three incredible functions. The "signal" function sets up signal handling, the "kill" function sends signals to specific processes identified by their PIDs, and the "usleep" function introduces delays in program execution, making it a well-timed performance.

Conclusion
This program is a symphony of signals, weaving a tale of inter-process communication and cooperation. Whether you're curious about the magic of signals or a seasoned pro, dive in and explore the enchanting world of UNIX signals!

Feel free to contribute, experiment, and create your own signal-driven stories. Happy coding! 🚀🔮📡🎩🪄
