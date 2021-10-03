/*C program to design flying characters Screen Saver.*/

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

/*will return character based on passed number*/
char getCHAR(int n)
{
    char ok[] = "~!@#$%^&*:;'\",{}|<>=";
    
}

/*function to identify that any key hit by the keyboard*/
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    

    

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        
        return 1;
    }

   
}

/*move cursor on specified position on screen*/
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

int main(void)
{
    int x, y;
    
    i = j = 0;

    x = 1;
    
    system("clear");

    /*program will run until any key hit*/
    while (!kbhit()) {
        x = rand() % ((150 - 1 + 1) + 1);
        y = rand() % ((50 - 1 + 1) + 1);
        gotoxy(x, y);
        
        fflush(stdout);
        ++i;
        if (i == 10000) {
            ++j;
            i = 0;
        }
        
        if (j <= 1000)
            usleep(3000);
        if (j <= 10000)
            usleep(300);
    }
    return 0;
}
