# Operating System - Shell Implementation Project

This repository contains a progressive implementation of Unix shell functionality in C, developed as part of an Operating Systems course. The project demonstrates fundamental operating system concepts including process management, inter-process communication, signal handling, and system calls.

## 🎯 Project Overview

This educational project implements multiple versions of a Unix shell, each building upon the previous version to add more sophisticated features. Starting from a basic command executor, the implementations progressively add I/O redirection, pipes, job control, command history, and environment variable management.

## 📚 Learning Objectives

Students working with this project will learn:
- **Process Management**: Creating and managing child processes using `fork()` and `exec()`
- **System Calls**: Working with Linux system calls for file operations and process control
- **Signal Handling**: Managing signals for job control and process cleanup
- **Inter-Process Communication**: Implementing pipes for command chaining
- **File Operations**: Input/output redirection and file descriptor manipulation
- **Memory Management**: Dynamic memory allocation and proper cleanup
- **String Processing**: Parsing and tokenizing command-line input

## 🚀 Features by Version

### Version 1 (shell1.c)
- **Basic Command Execution**: Execute simple commands with arguments
- **Dynamic Memory Management**: Tokenize input and manage memory allocation
- **Process Creation**: Fork processes to execute commands
- **Basic Prompt**: Display shell prompt and read user input

### Version 2 (myshellv2.c)
- **All Version 1 features**
- **I/O Redirection**: Support for input (`<`) and output (`>`) redirection
- **Pipe Support**: Execute commands connected by pipes (`|`)
- **Enhanced Parsing**: Parse complex command lines with redirection and pipes
- **File Descriptor Management**: Handle file operations and descriptor manipulation

### Version 3 (myshellv3.c)
- **Job Control Foundation**: Basic background process support
- **Signal Handling**: Handle SIGCHLD to prevent zombie processes
- **Background Jobs**: Execute commands in background with `&`
- **Process Reaping**: Automatic cleanup of completed child processes

### Version 4 (myshellv4.c)
- **All previous features**
- **Enhanced Job Control**: More robust background job management
- **Built-in Commands**: Support for shell built-in commands
- **Error Handling**: Improved error checking and user feedback

### Version 5 (myshellv5.c) - Most Advanced
- **Complete Job Control**: Full background/foreground job management
- **Command History**: Store and recall last 10 commands
- **Signal Management**: Comprehensive signal handling (SIGCHLD, SIGINT, etc.)
- **Job List Management**: Track and display active background jobs
- **Built-in Commands**: `history`, `jobs`, `kill`, `exit`
- **Process Groups**: Proper process group management

### Version 6 (version6.c)
- **Environment Variables**: Set and manage shell variables
- **Variable Scoping**: Support for global and local variables
- **Built-in Commands**: `printenc` (print environment), variable assignment
- **Variable Expansion**: Reference variables in commands

## 🛠️ Prerequisites

- **GCC Compiler**: GNU Compiler Collection for C
- **Linux/Unix Environment**: POSIX-compliant system
- **Basic C Knowledge**: Understanding of C programming and system calls

## 📦 Installation & Compilation

### Clone the Repository
```bash
git clone https://github.com/usman9522/Operating-System.git
cd Operating-System/Assignment01
```

### Compile Individual Versions
```bash
# Basic shell (Version 1)
gcc -o shell1 shell1.c

# Shell with I/O redirection and pipes (Version 2)  
gcc -o myshellv2 myshellv2.c

# Shell with basic job control (Version 3)
gcc -o myshellv3 myshellv3.c

# Enhanced job control (Version 4)
gcc -o myshellv4 myshellv4.c

# Full-featured shell (Version 5)
gcc -o myshellv5 myshellv5.c

# Shell with environment variables (Version 6)
gcc -o version6 version6.c
```

### Compile All Versions
```bash
# Compile all versions at once
for file in *.c; do
    gcc -o "${file%.c}" "$file"
    echo "Compiled $file successfully"
done
```

## 🎮 Usage Examples

### Running the Shell
```bash
# Start any version of the shell
./myshellv5
PUCITshell:- 
```

### Basic Commands
```bash
PUCITshell:- ls -la
PUCITshell:- pwd
PUCITshell:- echo "Hello World"
```

### I/O Redirection (Version 2+)
```bash
PUCITshell:- ls > output.txt          # Redirect output to file
PUCITshell:- sort < input.txt         # Read input from file
PUCITshell:- ls | grep "*.c"          # Pipe output to another command
```

### Background Jobs (Version 3+)
```bash
PUCITshell:- sleep 30 &               # Run in background
PUCITshell:- jobs                     # List active jobs (Version 5+)
```

### Command History (Version 5+)
```bash
PUCITshell:- history                  # Show command history
PUCITshell:- !!                       # Execute last command
```

### Environment Variables (Version 6)
```bash
PUCITshell:- VAR=value               # Set variable
PUCITshell:- printenc                # Print all variables
```

## 📁 File Structure

```
Operating-System/
│
├── README.md                    # This comprehensive guide
│
└── Assignment01/
    ├── shell1.c                # Version 1: Basic command execution
    ├── myshellv2.c            # Version 2: I/O redirection & pipes
    ├── myshellv3.c            # Version 3: Basic job control
    ├── myshellv4.c            # Version 4: Enhanced job control
    ├── myshellv5.c            # Version 5: Full-featured shell
    ├── version6.c             # Version 6: Environment variables
    ├── prac.c                 # Practice/testing file
    ├── AI.txt                 # Development notes and AI assistance info
    └── Ass01.pdf              # Assignment specifications
```

## 🔧 Implementation Details

### Key System Calls Used
- `fork()`: Create child processes
- `exec()` family: Execute programs
- `wait()`/`waitpid()`: Wait for child processes
- `pipe()`: Create inter-process communication channels
- `dup2()`: Duplicate file descriptors for I/O redirection
- `signal()`/`sigaction()`: Handle signals

### Memory Management
- Dynamic allocation for command parsing
- Proper cleanup of allocated memory
- Prevention of memory leaks

### Error Handling
- Comprehensive error checking for system calls
- User-friendly error messages
- Graceful handling of invalid input

## 🎓 Educational Value

This project provides hands-on experience with:
1. **Operating System Concepts**: Process lifecycle, signal handling, job control
2. **System Programming**: Direct interaction with Linux kernel through system calls
3. **C Programming**: Advanced C concepts including pointers, structures, and memory management
4. **Software Engineering**: Progressive development, modular design, and code organization

## 🤝 Credits and Acknowledgments

- **Dr. Arif Butt**: Course instructor and original guidance
  - Website: [www.arifbutt.me](http://www.arifbutt.me)
  - GitHub: [arifpucit](https://github.com/arifpucit/SP-VLecs)
- **AI Assistance**: ChatGPT and other AI tools for development support
- **System Programming Course**: PUCIT (Punjab University College of Information Technology)

## 📄 License

This project is for educational purposes. Please respect academic integrity guidelines when using this code for coursework.

## 🐛 Known Limitations

### Version 1 (shell1.c)
- Segmentation fault on empty input (Enter key only)
- Issues with input containing only spaces
- Problems with Ctrl+D input

### General Limitations
- Limited error recovery
- Basic signal handling in earlier versions
- No command completion or editing features

## 🔄 Version Progression Summary

1. **V1**: Basic execution → **V2**: +I/O redirection & pipes
2. **V2**: I/O operations → **V3**: +Background jobs & signals  
3. **V3**: Basic jobs → **V4**: +Enhanced job control
4. **V4**: Job control → **V5**: +History & full job management
5. **V5**: Full shell → **V6**: +Environment variables

Each version builds upon the previous, demonstrating incremental software development and progressive feature addition.
