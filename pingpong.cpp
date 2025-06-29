#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <algorithm>

int max_x, max_y;
int paddle_x, paddle_width = 14;
int ball_x, ball_y, ball_dx = 1, ball_dy = -1;
bool gameOver = false;
int score = 0;

void initGame() {
    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    timeout(100);  // Non-blocking input with 100ms delay
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, max_y, max_x);
    paddle_x = max_x / 2 - paddle_width / 2;
    ball_x = max_x / 2;
    ball_y = max_y / 2;
}

void draw() {
    clear();

    // Draw paddle
   mvprintw(max_y - 2, paddle_x, "==============");

    // Draw ball
    mvprintw(ball_y, ball_x, "X");

    // Draw border
   // for (int i = 0; i < max_x; ++i) {
  	 //  mvprintw(0, i, "#");
          // mvprintw(max_y - 1, i, "#");
   // }
    std::string scoreText = "hits: " + std::to_string(score);
    mvprintw(max_y - 1, max_x - scoreText.size() - 2, "%s", scoreText.c_str());

    refresh();
}

void update() {
    // Move ball
    ball_x += ball_dx;
    ball_y += ball_dy;

    // Ball bounce left/right
    if (ball_x <= 0 || ball_x >= max_x - 1)
        ball_dx *= -1;

    // Ball bounce top
    if (ball_y <= 1)
        ball_dy *= -1;

    // Ball hits paddle
    if (ball_y == max_y - 3 &&
        ball_x >= paddle_x &&
        ball_x < paddle_x + paddle_width) {
        ball_dy *= -1;
	score ++;
    }

    // Missed ball
    if (ball_y >= max_y - 2)
        gameOver = true;
}
bool showGameOverScreen() {
    clear();

    std::string border = "==================================================";
    std::string msg1   = "=                  Ball missed!                  =";
    std::string msg2   = "=                   [Game Over]                  =";
    std::string msg3   = "=       Press [r] to restart or [q] to quit      =";
    std::string blank  = "=                                                =";
    std::string msg4   = "=                Final hits: " + std::to_string(score) + "  =" ;

    while(msg4.size() < border.size() -1){
    	msg4.insert(msg4.size()-1," ");
    }
    int row, col;
    getmaxyx(stdscr, row, col);
    int start_y = row / 2 - 4;

    mvprintw(start_y + 0, (col - border.size()) / 2, "%s", border.c_str());
    mvprintw(start_y + 1, (col - msg1.size()) / 2, "%s", msg1.c_str());
    mvprintw(start_y + 2, (col - msg2.size()) / 2, "%s", msg2.c_str());
    mvprintw(start_y + 3, (col - msg4.size()) / 2, "%s", msg4.c_str());
    mvprintw(start_y + 4, (col - msg3.size()) / 2, "%s", msg3.c_str());
    mvprintw(start_y + 5, (col - blank.size()) / 2, "%s", blank.c_str());
    mvprintw(start_y + 6, (col - border.size()) / 2, "%s", border.c_str());

    refresh();

    int ch;
    while (true) {
        ch = getch();
        if (ch == 'r' || ch == 'R') return true;  // Restart
        if (ch == 'q' || ch == 'Q') return false; // Quit
    }
}

void handleInput() {
    int ch = getch();
    if (ch == 'a' || ch == KEY_LEFT)
        paddle_x = std::max(0, paddle_x - 2);
    else if (ch == 'd' || ch == KEY_RIGHT)
        paddle_x = std::min(max_x - paddle_width, paddle_x + 2);
    else if (ch == 'q')
        gameOver = true;
}
void showStartScreen() {
    clear();

    std::string border = "=================================================";
    std::string line1  = "=  Welcome to Terminal Games By Ashok Kushwaha  =";
    std::string line2  = "=             TERMINAL PING PONG                =";
    std::string line3  = "=     Press [Enter] to boot | [q] to abort      =";
    std::string line4  = "=                                               =";

    int row, col;
    getmaxyx(stdscr, row, col);

    int start_y = row / 2 - 3;

    mvprintw(start_y + 0, (col - border.size()) / 2, "%s", border.c_str());
    mvprintw(start_y + 1, (col - line1.size()) / 2, "%s", line1.c_str());
    mvprintw(start_y + 2, (col - line2.size()) / 2, "%s", line2.c_str());
    mvprintw(start_y + 3, (col - line3.size()) / 2, "%s", line3.c_str());
    mvprintw(start_y + 4, (col - line4.size()) / 2, "%s", line4.c_str());
    mvprintw(start_y + 5, (col - border.size()) / 2, "%s", border.c_str());

    refresh();

    // Wait for Enter or q
    int ch;
    while (true) {
        ch = getch();
        if (ch == '\n' || ch == KEY_ENTER) break;
        if (ch == 'q' || ch == 'Q') {
            endwin();
            printf("Session terminated.\n");
            exit(0);
        }
    }
}

int main() {
    bool play = true;
   // initGame();
   // showStartScreen();
    while(play){
    initGame();
    showStartScreen();
    gameOver = false;
    score = 0;
    while (!gameOver) {
        draw();
        handleInput();
        update();
        usleep(5000);  // Delay for smoother motion
    }
    play = showGameOverScreen();
   
    }
    endwin();
    printf("Thanks for playing.\n");
    return 0;
}

