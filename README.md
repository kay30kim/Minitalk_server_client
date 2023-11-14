# Minitalk in two process using signals

<img width="80%" src= "https://github.com/kay30kim/Minitalk_server_client/assets/59407632/d358c2d9-fdfc-40b0-aba3-becc70e41619"/>

## Project Information

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### Description

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**
- Add reception acknowledgement system
- Support Unicode characters

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