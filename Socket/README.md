# Web-Server Program 

This repository contains a C++ client-server program designed as class wrappers around low-level C socket functionality. The program allows clients to connect to the server, send HTTP request, and receive single HTML file.

## Prerequisites

Before running the program, ensure that you have the following prerequisites installed on your system:

1. C++ Compiler: Make sure you have a C++ compiler installed. The program has been tested with GCC, but other C++ compilers should work as well.

2. Operating System: The program has been developed and tested on Unix-based systems. It should work on Linux, macOS, and other Unix-like systems. Windows users might need to adapt the code or use a Unix-like environment.

## How to Compile

To compile the program, follow these steps:

1. Clone this repository to your local machine:
    - `https://github.com/Kalashyan-1/Current-tasks.git`
    - `cd Current-tasks/Socket`
2. Compile the server and client files:
    - `g++ -o server serverMain.cpp webServer.cpp server.cpp `
    - `g++ -o http httpMain.cpp`

## How to Run

Follow these steps to run the client-server program:

1. Start the server:
    -`./server`
2. Start the client:
    -`./http`


- Terminate the program:
    - To terminate the client or server, simply press Ctrl+C.


## Troubleshooting

If you encounter any issues while compiling or running the program, please make sure you have followed the steps correctly and that your system meets the prerequisites.

If you face any specific errors or need assistance, feel free to open an issue in this repository, and we will do our best to help you.

