
UNIX signals SIGUSR1 and SIGUSR2 for inter-process communication:


Server Operation:

The server program operates as part of a client-server model, utilizing UNIX signals for inter-process communication. After setting up the signal handlers, the server enters an infinite loop (while (1)) to remain active and continuously wait for incoming signals. This asynchronous signal reception enables the server to respond to signals as they are received, ensuring a persistent communication channel between the server and client processes. The server implementation minimizes concerns about resource consumption, focusing primarily on waiting for and handling signals, thus consuming minimal CPU resources during the wait period between signals.

extract_pid Function:
The extract_pid function is responsible for converting the received full process ID (PID) to an integer using ft_atoi and subsequently sending the SIGUSR1 signal to that process. Its purpose is to extract the complete PID from the received bits and appropriately send the signal.

countbit Function:
The countbit function calculates and returns the decimal value of 2 raised to the power of a given bit. It achieves this using a loop and serves as a utility function commonly used in scenarios involving binary operations or bitwise manipulations. In the context of this program, it calculates the decimal value of a received bit, which is then accumulated in the let variable. The line let += countbit(bit) calculates the decimal value of the received bit and adds it to the let variable. The countbit function enables the calculation of the decimal value for a specific bit position in a binary number.

Signal Handlers:
Signal handlers are responsible for processing the received signals. They are registered using the signal function to handle SIGUSR1 and SIGUSR2 signals. These signal handler functions perform appropriate actions based on the received signal type.

Infinite Loop:
The server program employs an infinite loop (while (1)) to continuously run and wait for signals. This loop ensures that the server remains responsive and capable of handling multiple signals without exiting or terminating. Asynchronous signal reception is achieved, allowing the server to respond to signals as they are received.

Client Operation:

The bugs function validates command line arguments (argc and argv), checking for issues such as too few or too many arguments and invalid PID values (e.g., non-digit characters). If any issues are detected, the program exits with a non-zero status.

Receiver Process ID:
The receiver process ID is extracted from the command line arguments (av[1]) and converted to an integer using ft_atoi.

Sender Process ID:
The sender process ID is obtained by calling getpid and converted to a string using ft_itoa. It is then sent to the receiver process by invoking p_sender with the PID and the sender process ID string.

Message Transmission:
The sender program iterates through each bit of the message. If the current bit is 1 (message & 1 is true), the "kill" function is called with the PID and SIGUSR1 to send a SIGUSR1 signal to the receiver. If the current bit is 0, the "kill" function is called with the PID and SIGUSR2 to send a SIGUSR2 signal. A delay using usleep(1000) is introduced after each signal to provide a short pause. This process repeats for each bit, allowing the entire message to be transmitted bit by bit.

Terminating Null Character:
Finally, a terminating null character (0) is sent to indicate the end of the message.






The "signal" function sets up signal handling by registering a signal handler for the specified signal. It takes two arguments: signum (usually a macro constant defined in the <signal.h> header file) and the handler. Some signals, such as SIGKILL and SIGSTOP, cannot be caught or ignored.

The "kill" function sends a specified signal to the process identified by a given PID. It takes two arguments: the PID of the target process and the signal to be sent.

The "usleep" function introduces a delay in program execution, specified in microseconds. It is useful for pausing execution without requiring precise timing.




I hope this provides a clearer and more readable explanation of the program's functionality! Let me know if you have any further questions
