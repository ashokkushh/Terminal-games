# 🐧 TERMINAL GAMES: Ping Pong CLI Edition

```sh
Welcome to TERMINAL GAMES by Ashok Kushwaha.
```

A retro-style **terminal-based Ping Pong game**, built with pure C++ and `ncurses`, running straight in your Linux shell. No GUI. No mouse. Just you, your keyboard, and the terminal.

---

## 🚀 Booting Up

### 🔧 Prerequisites

Ensure your system has:
- g++
- make
- libncurses5-dev

Install `ncurses` (if not already):

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

---

### 🛠️ Clone & Build

```bash
git clone https://github.com/ashok-terminal-games/pingpong.git
cd pingpong
make
./pingpong
```

> Or compile manually:
```bash
g++ pingpong.cpp -o pingpong -lncurses
```

---

## 🎮 Controls

| Key      | Action           |
|----------|------------------|
| `a` / `←` | Move Left        |
| `d` / `→` | Move Right       |
| `q`      | Quit Game        |
| `r`      | Restart (on fail)|
| `Enter`  | Start Game       |

---

## 📟 Terminal Theming

- **Startup screen**: Styled like a UNIX login banner.
- **Score label**: Uses `hits:` for a clean CLI feel.
- **Game over prompt**: Like a failed service restart with retry options.

Example output:
```sh
>> pong_packets_received = 13
```

---

## 📁 File Structure

```
pingpong/
├── pingpong.cpp    # Source code
├── README.md       # This file
└── Makefile        # Optional build file
```

---

## 📡 Inspired By

- `ping`, `top`, `uptime`, `htop`
- Classic `ncurses`-based TUIs
- Open-source minimal CLI games

---

## 💻 Demo

```sh
$ ./pingpong

=================================================
=  Welcome to Terminal Games By Ashok Kushwaha  =
=         🐧  TERMINAL PING PONG  🐧           =
=     Press [Enter] to boot | [q] to abort      =
=================================================

...play game...

hits: 14

=================================================
=                   💥 Ball missed!              =
=                   Game Over                    =
=               Final hits: 14                   =
=     Press [r] to restart or [q] to quit        =
=================================================
```

---

## 🧠 Want to Contribute?

Pull requests and forks are welcome.
```sh
# Feature idea? Bug report?
$ touch ideas.md && vim ideas.md
```

---

## 🔓 License

This game is open-source and free to modify. Built for fun and terminal nostalgia.

---

```sh
# Boot up. Bash out. Bounce back.
```

Happy hacking! 💻🎾
