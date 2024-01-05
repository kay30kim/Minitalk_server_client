# Minitalk in two process using signals

<img width="100%" src= "https://github.com/kay30kim/Minitalk_server_client/assets/59407632/d358c2d9-fdfc-40b0-aba3-becc70e41619"/>

## About

The purpose of this project is to code a small data exchange program using *UNIX signals*.


### Description
Implement a client-server system for data exchange using UNIX signals. This introductory project lays the groundwork for more complex UNIX projects. The server, started first, prints its PID. The client, taking server PID and a string, sends the string to the server, which prints it using only UNIX signals (SIGUSR1 and SIGUSR2). The server efficiently handles multiple string receptions without restarting. Bonus features include server acknowledgment for each message and Unicode character support.

## Project Highlights
- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**
- Add reception acknowledgement system
- Support Unicode characters
- Client-server data exchange using UNIX signals.
- Server acknowledges every received message.
- Unicode character support.

## Implementation Steps:
1. Create a client-server system for message exchange.
2. Server prints its PID after launch.
3. Client sends a string to the server using SIGUSR1 and SIGUSR2.
4. Server efficiently displays received strings.
5. Bonus: Server acknowledges each message, Unicode character support.

## Resources:
- Importance of error-sensitive handling.
- Avoiding memory leaks and justifying the use of global variables.
- UNIX signals: SIGUSR1 and SIGUSR2 for communication.

- - - 
<h3 align="left">
	:computer: Usage
</h3>
1- Clone this repository: </br>
<code>git clone https://github.com/kay30kim/Minitalk_server_client.git</code> </br></br>

2- Navigate to minitalk folder: </br>
<code>cd Minitalk_server_client</code><br /><br />

3- Run with make or make bonus: </br>
<code>make</code> or <code>make bonus</code><br /><br />

4- Start the server to get his PID with: </br>
<code>./server</code> or <code>./server_bonus</code><br /><br />

5- Start the client and send message with: </br>
<code>./client [PID] [Message]</code> or <code>./client_bonus [PID] [Message]</code><br /><br />
