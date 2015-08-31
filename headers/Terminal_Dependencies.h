/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.

 * This header file consists of libraries and functions from different platforms
 * being interfaced in-order to achieve a cross-platform set of functions for the
 * Terminal Class
*/

# define FAIL -2147084 //Value returned when stack process

#include <iostream>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <vector>
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>

    static HANDLE hOut =  GetStdHandle(STD_OUTPUT_HANDLE);
    enum BEHAVIOR { ALTERNATING, RAINBOW, NORMAL};
    enum COLOR
    {
        DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKPURPLE, DARKYELLOW, DEFAULT, GREY, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW
    };

    void gotoxy(int8_t x, int8_t y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

#elif defined __linux__
    #include <termios.h>

     #define hOut        1

    enum COLOR
    {
        DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKPURPLE, DARKYELLOW, DEFAULT, GREY, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW
    };

    #define DARKBLUEstr    "\033[22;34m"
    #define DARKGREENstr   "\033[22;32m"
    #define DARKCYANstr    "\033[22;36m"
    #define DARKREDstr     "\033[22;31m"
    #define DARKPURPLEstr  "\033[22;35m"
    #define DARKYELLOWstr  "\033[01;33m"
    #define DEFAULTstr     "\033[0m"
    #define GREYstr        "\033[22;37"
    #define BLUEstr        "\033[01;34m"
    #define GREENstr       "\033[01;32m"
    #define CYANstr        "\033[01;36m"
    #define REDstr         "\033[01;31m"
    #define PURPLEstr      "\033[01;35m"
    #define YELLOWstr      "\033[01;33m"



    struct COORD
    {
        int8_t x, y;
    };

    static termios TermOld, TermNew;

    void SetConsoleColor(COLOR color) // Since console terminals rely on
    {                                 // escape character sequence compare
        switch (color)                // to Microsoft's DOS service which
        {                             // relies on sending signal to the
            case DARKBLUE:            // console services handler.
                printf(DARKBLUEstr);
            break;                    // what this does is to secretly
            case DARKGREEN:           // print the equivalent color code
                printf(DARKGREENstr); // to the terminal. Which gives the
            break;                    // similar effect to that off in
            case DARKCYAN:            // windows.
                printf(DARKCYANstr);
            break;
            case DARKRED:
                printf(DARKREDstr);
            break;
            case DARKPURPLE:
                printf(DARKPURPLEstr);
            break;
            case DARKYELLOW:
                printf(DARKYELLOWstr);
            break;
            case DEFAULT:
                printf(DEFAULTstr);
            break;
            case GREY:
                printf(GREYstr);
            break;
            case BLUE:
                printf(BLUEstr);
            break;
            case GREEN:
                printf(GREENstr);
            break;
            case CYAN:
                printf(CYANstr);
            break;
            case RED:
                printf(REDstr);
            break;
            case PURPLE:
                printf(PURPLEstr);
            break;
            case YELLOW:
                printf(YELLOWstr);
            break;
        }
    }

    /**
        Since Unix doesn't have the getch function built in.
        Or rather Window's <conio.h> is a nonstandard library header
        We will try to emulate getch by temporarily swapping i/o port
        to a new one.
    */

    void initTerm(int echo)
    {
        tcgetattr(0, &TermOld);                 // grabs current i/o port of terminal
        TermNew = TermOld;                      // copy settings
        TermNew.c_lflag &= ~ICANON;             // disable current i/o port
        TermNew.c_lflag &= echo ? ECHO : ~ECHO; // sets echo if either enabled or disabled.
        tcsetattr(0, TCSANOW, &TermNew);        // sets current i/o port to the new one
    }

    void resetTerm (void)
    {
        tcsetattr(0, TCSANOW, &TermOld);        // reset attribute
    }

    char getch_(bool printStream)
    {
        char ch;
        initTerm((int)printStream);
        ch = getchar();
        resetTerm();
        return ch;
    }

    char getch (void)
    {
        return getch_(false);
    }

    char getche (void)
    {
        return getch_(true);
    }

    void gotoxy(int8_t x, int8_t y)
    {
        printf("%c[%d;%df", 0x1B, x, y);
    }



#endif

char *itoa(long i, char* s, int dummy_radix) {
    sprintf(s, "%ld", i);
    return s;
}


int check_char (char character)
{
    if (character >= '0' && character <= '9')
        return character - '0';
    return '\0';
}

//Template function for counting digits
template <class Type>
Type Calculate_for_Num_Digit(Type Val)
{
    int Num_Digits = 0;
    while (Val /= 10)
    {
        Num_Digits++;
    }
    return Num_Digits + 1;

};

void CopyStr (char fmt1[], char fmt2[])
{
    int length = strlen(fmt2);
    for (int i = 0; i < length; i++)
    fmt1[i] = fmt2[i];
}

void GetInputUser (char fmt[256])
{
    char fmtbuf[256];
    int input = -1;
    int index = 0;
    do
    {
        input = getche();
        fmtbuf[index] = input;
        if (input == 8)
        {
            if (index > 0)
            index--;
            continue;
        }
        index++;
        } while (input != 13);
        fmtbuf[index] = '\0';
        strcpy(fmt, fmtbuf);

}



void Disect (char fmtbuf[256])
{
    std::cout<<"\n\nError chk: \n"<<fmtbuf;
    int length = strlen(fmtbuf);
    for (int i = 0; i < length; i++)
    {
        printf("%d) %c  %d\n", i, fmtbuf[i], fmtbuf[i]);
    }
}

/*The boolean value that checks and indicates if the
terminal functions are allowed, turning it off will make
all the functions in the terminal command invalid!*/
bool Override_Ctrl;

//Function that converts an int into a string
std::string ConvertNum_To_Str(int num)
{
    int Numbers_ = Calculate_for_Num_Digit(num);
    std::string P;
    for (int i = Numbers_ ; i > 0; i--)
    {
        char a = (num % 10) + 48;
        P += a;
        num /= 10;
    }
    P[Numbers_] = '\0';
    std:: string p;
    for (int i = P.length() - 1; i >= 0; i--)
    {
        p += P[i];
    }
    p[Numbers_] = '\0';
    return p;
}

/* This function is inefficient and will be
   replaced by a better one which uses the
   C++'s stream buffers, which handles much
   better than converting it on your own.
 */

int ConvertStr_To_Num(char paragraph[])
{

    int length = strlen(paragraph);
    int Pow = pow(10, length - 2);
    int Num = 0;
    //gotoxy(3, 10);
    //cout<<Pow<<endl;
    for (int i = 0;i < length; Pow /= 10)
    {
        Num += (check_char(paragraph[i]) * Pow);
        //gotoxy(3, 11 + i);
        //cout<<"NUM: "<<i<<" "<<paragraph[i]<<"  "<<Pow<<endl;
        i++;
    }
    return Num;
}

//Stack Implementation for IO manips such as reverse print

class Stack //Class Name
{
    private:
        std::vector<int>arrayList;
        int limit;
        int reg;

    public:
        Stack()
        {
            reg = 0;
            limit = 10;
        };
        void push(int value)
        {
            reg++;
            arrayList.insert(arrayList.end(), value);
        };
        int stackTop()
        {
            if (reg > 0)
            return arrayList.at(arrayList.size() - 1);
            return FAIL;
        };
        int pop()
        {
            reg--;
            if (stackTop() != FAIL)
            {
                int toReturn = stackTop();
                arrayList.resize(arrayList.size() - 1);
                return toReturn;
            }
            return FAIL;
        };
        bool isEmpty()
        {
            if (arrayList.size() == 0)
            return true;
            return false;
        };

        bool isFull()
        {
            if (arrayList.size() == 10)
            return true;
            return false;
        };

        int stackCount()
        {
            if (arrayList.size() > 0);
            return arrayList.size();
        };

        int Peek(int index)
        {
            if (index < reg)
            {
                return arrayList.at(index);
            }
            else
            {
                return FAIL;
            }
        };

};
