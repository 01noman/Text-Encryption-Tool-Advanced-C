#  Text Encryption Tool (Advanced C Project)

A secure and feature-rich **Text Encryption/Decryption Tool** written in **C language**, designed for beginners and intermediate programmers to explore **string handling**, **file I/O**, and **ASCII operations** in depth.

---

##  Project Overview

This project allows users to:

* **Signup/Login** securely using a text-based account system.
* **Encrypt and Decrypt** both text and files using two different methods:

  * ASCII Shift Encryption
  * XOR Encryption
* Generate **random keys** for stronger encryption.
* Maintain a **history log** of all encryption/decryption actions with timestamps.

It’s built entirely in **C**, with no external libraries beyond the standard C library.

---

##  Features by Phase

| Phase       | Description                  | Key Functions                                                          |
| ----------- | ---------------------------- | ---------------------------------------------------------------------- |
| **Phase 1** | User Authentication          | `signup()`, `login()`                                                  |
| **Phase 2** | Encryption/Decryption Engine | `encryptText()`, `decryptText()`, `encryptFile()`, `decryptFile()`     |
| **Phase 3** | Advanced Features            | `readPassword()` (masked input), `generateRandomKey()`, `logHistory()` |

---

##  Tech Stack

* **Language:** C (ANSI C)
* **Libraries Used:**
  `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `conio.h`
* **Environment:** GCC / MinGW / Code::Blocks / Visual Studio Code

---

##  How to Run

### 1. Clone this Repository

```bash
git clone https://github.com/01noman/Text-Encryption-Tool-Advanced-C.git
cd Text-Encryption-Tool-Advanced-C
```

### 2. Compile

Using GCC:

```bash
gcc encryption_tool.c -o encryption_tool
```

### 3. Run

```bash
./encryption_tool
```

---

##  Example Usage

```
=====================================
   TEXT ENCRYPTION TOOL (SECURE)
=====================================

1. Login
2. Signup
3. Exit
Enter choice: 2
Enter new username: noman
Enter password: ****
-> Signup successful!

1. Login
2. Signup
3. Exit
Enter choice: 1
Username: noman
Password: ****
-> Login Successful!

=================================
      SECURE ENCRYPTION MENU
=================================
1. Encrypt Text
2. Decrypt Text
3. Encrypt File
4. Decrypt File
5. View History
6. Logout
---------------------------------
Enter your choice: 1
Choose Encryption Method:
1. ASCII Shift
2. XOR
Enter method: 1
Enter key (0 = auto-generate): 0
Enter text to encrypt: hello
Encrypted Text: khoor
```

---

##  Files Used

| File Name                  | Purpose                                   |
| -------------------------- | ----------------------------------------- |
| `encryption_tool.c`     | Main program source code                  |
| `users.txt`                | Stores registered usernames and passwords |
| `history.txt`              | Stores encryption/decryption logs         |
| `input.txt` / `output.txt` | Sample files for encryption/decryption    |

---

##  Encryption Methods

| Method             | Description                                          | Example                       |
| ------------------ | ---------------------------------------------------- | ----------------------------- |
| **ASCII Shift**    | Shifts each character’s ASCII code by a key value.   | `A (65)` → key `3` → `D (68)` |
| **XOR Encryption** | XORs each byte with the key, reversible by same key. | `'A' (65)` XOR `3` → `B (66)` |

---

##  Future Enhancements (Phase 4 Ideas)

*  Password hashing (store encrypted passwords)
*  GUI interface (WinAPI / GTK / ncurses)
*  Support for custom cipher algorithms (Caesar, AES-lite)
*  Network encryption demo

---

##  Author

**Abdullah Noman**
 Email: *abnoman957@gmail.com*
 GitHub: [01noman](https://github.com/01noman)

---

##  License

This project is open-source and available under the **MIT License**.
