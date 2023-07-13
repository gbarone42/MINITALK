
UNIX signals SIGUSR1 and SIGUSR2 are used for inter-process communication in a client-server model.

Server Operation:
The server program sets up signal handlers and enters an infinite loop to wait for incoming signals. It responds asynchronously, ensuring a persistent communication channel without excessive resource consumption.

extract_pid Function:
This function converts a received full process ID (PID) to an integer using ft_atoi and sends a SIGUSR1 signal to that process.

countbit Function:
The countbit function calculates the decimal value of a given bit, accumulating it in the let variable. It helps with binary operations or bitwise manipulations.

Signal Handlers:
Signal handlers are registered using the signal function to handle SIGUSR1 and SIGUSR2 signals. They perform actions based on the received signal type.

Infinite Loop:
The server program runs an infinite loop to continuously wait for signals, ensuring responsiveness to multiple signals.

Client Operation:
The bugs function validates command line arguments, checking for issues like invalid PID values. It exits with a non-zero status if problems are found.

Receiver Process ID:
The receiver process ID is extracted from the command line arguments and converted to an integer.

Sender Process ID:
The sender process ID is obtained using getpid and converted to a string. It is sent to the receiver process.

Message Transmission:
The sender program sends the message bit by bit. If the bit is 1, it sends a SIGUSR1 signal; if 0, a SIGUSR2 signal. A short pause follows each signal.

Terminating Null Character:
A terminating null character (0) is sent to mark the end of the message.

Signal Functions:
The "signal" function sets up signal handling, registering a handler for a specified signal.
The "kill" function sends a signal to a process identified by a PID.
The "usleep" function introduces a delay in program execution.

I hope this provides a concise overview of the program's functionality.
