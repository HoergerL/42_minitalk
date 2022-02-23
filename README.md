# 42_minitalk
In this project you create a communication between client and server. The server, which is started first, prints its process id after it's launch.
The client takes 2 arguments. The process id of the server and a string, which he will send to the server, who will print it.
The communication between the 2 processes is based on the UNIX signals  SIGUSR1 and SIGUSR2.

## how it works
The client translates the chars of the string into their binary representation. SIGUSR1 corresponds to 1 and SIGUSR2 to 2. 
The server receives the signal and translates it back to the char.

## bonus
There are 2 Boni to implement:
* Acknowledgement: The server acknowledges every signal send by the client. The client waits until it has recieved the acknowledgement from the server, only then it sends the next signal
* Unicode: The communication should also work for Unicode characters.

## goal
The goal of this project was to understand signals and to use them to send strings from one process to another one. Additionally you had to learn about processes.
