# 📡 Minitalk – 42 Project  

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/minitalke.png" alt="Minitalk 42 project badge"/>
</p>

## 📝 Overview  
**Minitalk** is a communication project at **42** that involves creating a client-server system using UNIX signals (`SIGUSR1` and `SIGUSR2`). The goal is to send messages from a client to a server one character at a time, demonstrating an understanding of low-level system calls and signal handling.  

This project is a great way to dive into the world of inter-process communication (IPC) and explore how signals can be used creatively to transmit data between processes.  


---

## 📂 Project Structure  
```
├── 42-ft_printf/
│   ├── Makefile
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ft_putchar.c
│   ├── ft_puthex.c
│   ├── ft_putnbr.c
│   ├── ft_putp.c
│   ├── ft_putstr.c
│   ├── ft_putu.c
│   ├── ft_strlen.c
│   ├── Makefile
│
├── client.c
├── client_bonus.c
├── server.c
├── server_bonus.c
├── utils.c
├── minitalk.h
```

---

## ⚙️ Installation & Usage

### 🔧 Compilation
To compile the mandatory part:
```bash
make
```
To compile the bonus part:

```bash
make bonus
```
🚀 Running the Program
Start the server:

```bash
./server
```

This will output the PID of the server.

Send a message using the client:

```bash
./client <server_pid> "Your message here"
```

🎯 Example Usage
```bash
./server
```
# Output: Server running. PID: 12345
```
./client 12345 "Hello, Minitalk!"
```
# Output on the server: Received message: Hello, Minitalk!

🛠 Features
✅ Implements signal-based communication using SIGUSR1 and SIGUSR2.

✅ Handles variable-length messages without shared memory or sockets.

✅ Includes a bonus version that handles Unicode characters and acknowledgments.

✅ Uses ft_printf for better formatting (custom implementation).

🏆 Bonus Features
✨ Unicode Support – Handles extended character sets.

✨ Acknowledge System – Server sends a response upon receiving messages.

✨ Better Error Handling – Detects invalid PIDs and handles interruptions.
## 📜 Allowed Functions
The following functions are allowed for this project:
- `write`  `getpid` `signal` `sigemptyset` `sigaddset` `sigaction`
- `kill`   `pause`  `sleep`  `usleep`  `exit`

---

## 📚 Resources
- [UNIX Signals](https://www.geeksforgeeks.org/signals-c-language/) – Signals in C language on signals.
- [Inter-Process Communication (IPC)](https://en.wikipedia.org/wiki/Inter-process_communication) – Wikipedia article on IPC.
- [Custom `ft_printf` Implementation](https://github.com/aarab-ayoub/42-ft_printf) – Link to my custom `ft_printf` implementation .

---

## 📝 Author
👨‍💻 **Aarab Ayoub**  
📧 [ayoubaarab570@gmail.com](mailto:ayoubaarab570@gmail.com)  
🔗 [GitHub Profile](https://github.com/aarab-ayoub)  

---

## 🎉 Acknowledgments
- Thanks to **42 School** for providing this challenging and educational project.
- Special thanks to peers and mentors for their support and feedback during the development process.
