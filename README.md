# Minitalk in two process using signals

## Project Information

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### Description

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**
- Add reception acknowledgement system
- Support Unicode characters

## Compilation

1. Clone repo including [`libft`](../../../42-libft) submodule via `git clone https://github.com/kay30kim/Minitalk_server_client.git`.
2. Compile files into `server` & `client` executables via `make -C 42-minitalk`.
