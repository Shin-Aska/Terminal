#include <iostream>
#include <iomanip>
#include <cstring>
#include "../headers/Terminal"

# define RIGHTDOWN     218
# define RIGHTUP       192
# define LEFTDOWN      191
# define LEFTUP        217
# define VERTICAL    196
# define HORIZONTAL      179
# define VERTICALRIGHT 195
# define VERTICALLEFT  180

using namespace std;

#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

int main (void) {

    HANDLE HolderOutput;
    CONSOLE_SCREEN_BUFFER_INFO BoxSize;
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    int x;
    int y;

    HolderOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(HolderOutput, &BoxSize);

    x = BoxSize.srWindow.Right;
    y = BoxSize.srWindow.Bottom * 1.6;
    DisplayArea.Right = x;
    DisplayArea.Bottom = y;
    SetConsoleWindowInfo(HolderOutput, TRUE, &DisplayArea);


    cnTerm_Activate;

    cnTitle("GLaDOS - Still Alive - Windows Port");
    Terminal LyricBox;
    Terminal CreditBox;
    Terminal PictureBox;

    CreditBox.setGlobalColor(DARKYELLOW);
    CreditBox.setStartPoint(32);
    CreditBox.setxy(32, 0);
    CreditBox.setLimit(90);
    for (int i = 0; i < 14; i++) {

        if (i == 0)
            CreditBox.print("%c", RIGHTDOWN);
        else if (i == 13)
            CreditBox.print("%c", RIGHTUP);
        else
            CreditBox.print("%c", HORIZONTAL);

        for (int j = 0; j < 46; j++) {

            if (i == 0 || i == 13)
                CreditBox.print("%c", VERTICAL);
            else
                CreditBox.print(" ");
        }

        if (i == 0)
            CreditBox.print("%c", LEFTDOWN);
        else if (i == 13)
            CreditBox.print("%c", LEFTUP);
        else
            CreditBox.print("%c", HORIZONTAL);

        if (i + 1 != 23)
            CreditBox.print("\n");
    }


    LyricBox.setGlobalColor(DARKYELLOW);
    for (int i = 0; i < 38; i++) {

        if (i == 0)
            LyricBox.print("%c", RIGHTDOWN);
        else if (i == 37)
            LyricBox.print("%c", RIGHTUP);
        else
            LyricBox.print("%c", HORIZONTAL);

        for (int j = 0; j < 30; j++) {

            if (i == 0 || i == 37)
                LyricBox.print("%c", VERTICAL);
            else
                LyricBox.print(" ");
        }

        if (i == 0)
            LyricBox.print("%c", LEFTDOWN);
        else if (i == 37)
            LyricBox.print("%c", LEFTUP);
        else
            LyricBox.print("%c", HORIZONTAL);

        if (i != 37)
            LyricBox.print("\n");
    }


    Sleep(2000);

    LyricBox.setxy(0, 1);
    LyricBox.setStartPoint(1);
    LyricBox.setxy(1, 1);
    LyricBox.setLimit(30);
    string t2 = "FORM FOEM-2921342 - 12";
    string t3 = "\nTest Assessment Report\n\n\n";

    for (int i = 0; i <= t2.length(); i++)
    {
        LyricBox.putch(YELLOW, t2[i]);
        Sleep(100);
    }
    for (int i = 0; i <= t3.length(); i++)
    {
        LyricBox.putch(YELLOW, t3[i]);
        Sleep(100);
    }

    mciSendString("play stillalive.mp3",NULL,0,NULL);

    string phrase = "\nThis was a triumph.";
    string phrase1 = "\nI'm making a note here:";
    string phrase2 = "\nHUGE SUCCESS.";
    string phrase3 = "\nIt's hard to overstate\nmy satisfaction.";
    string phrase4 = "\nAperture Science:";
    string phrase5 = "\nWe do what we must";
    string phrase6 = "\nbecause we can.";
    string phrase7 = "\nFor the good of all of us.";
    string phrase8 = "\nExcept the ones who are dead.";
    string phrase9 = "\n\nBut there's no sense crying \nover every mistake.";
    string phrase10 = "\nYou just keep on trying till\nyou run out of cake.";
    string phrase11 = "\nAnd the Science gets done.";
    string phrase12 = "\nAnd you make a neat gun.";
    string phrase13 = "\nFor the people who are still\nalive.";

    string refrain = "\n\nI'm not even angry.";
    string refrain1 = "\nI'm being so sincere right\nnow.";
    string refrain2 = "\nEven though you broke my\nheart.";
    string refrain3 = "\nAnd killed me.";
    string refrain4 = "\nAnd tore me to pieces.";
    string refrain5 = "\nAnd threw every piece\ninto a fire.";
    string refrain6 = "\n\nAs they burned it hurt\nbecause I was so happy\nfor you!";
    string refrain7 = "\nNow these points of data\nmake a beautiful line.";
    string refrain8 = "\nAnd we're out of beta.";
    string refrain9 = "\nWe're releasing on time.";
    string refrain10 = "\nSo I'm GLaD. I got burned.";
    string refrain11 = "\nThink of all the things\nwe learned";
    string refrain12 = "\nfor the people who are still\nalive.";

    string chorus = "\nI think I prefer\nto stay inside.";
    string chorus1 = "\nMaybe you'll find someone\nelse to help you.";
    string chorus2 = "\nMaybe Black Mesa";
    string chorus3 = "\nTHAT WAS A JOKE. ";
    string chorus4 = "FAT CHANCE.";
    string chorus5 = "\nAnyway, this cake is great.";
    string chorus6 = "\nIt's so delicious and moist.";
    string chorus7 = "\nLook at me still talking";
    string chorus8 = "\nwhen there's Science to do.";
    string chorus9 = "\nWhen I look out there,\nit makes me GLaD I'm not you.";
    string chorus10 = "\nI've experiments to run.";
    string chorus11 = "\nThere is research to be done.";
    string chorus12 = "\nOn the people who are\nstill alive.\n";
    string chorus13 = "\nPS: And believe me\nI'm still alive.\n";
    string chorus14 = "\nPSS: I'm doing Science and\nI'm still alive\n";
    string chorus15 = "\nPSSSS: \nI feel FANTASTIC and\nI'm still alive.\n";
    string chorus16 = "\nFinal Though\nWhile you're dying\nI'll be still alive.\n";
    string chorus17 = "\nFinal Though PS\nAnd when you're dead\nI will be still alive.\n";
    string chorus18 = "\nStill Alive...\n";
    string chorus19 = "\nStill Alive!";

    int i;

    while ( !kbhit())
    {

        for (i = 0; i <= phrase.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase[i]);
            Sleep(100);
        }
        Sleep(2100);
        for (i=0; i <= phrase1.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase1[i]);
            Sleep(80);
        }

        for (i=0; i <= phrase2.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase2[i]);
            Sleep(100);
        }

        /*PictureBox.setGlobalColor(DARKYELLOW);
        PictureBox.setStartPoint(32);
        PictureBox.setxy(32, 14);
        PictureBox.setLimit(90);
        for (int i = 0; i < 24; i++) {

            if (i == 0)
                PictureBox.print("%c", VERTICALRIGHT);
            else if (i == 23)
                PictureBox.print("%c", RIGHTUP);
            else
                PictureBox.print("%c", HORIZONTAL);

            for (int j = 0; j < 46; j++) {

                if (i == 0 || i == 23)
                    PictureBox.print("%c", VERTICAL);
                else
                    PictureBox.print(" ");
            }

            if (i == 0)
                PictureBox.print("%c", VERTICALLEFT);
            else if (i == 23)
                PictureBox.print("%c", LEFTUP);
            else
                PictureBox.print("%c", HORIZONTAL);

            if (i != 23)
                PictureBox.print("\n");
        }*/


        Sleep(1200);
        for (i = 0; i <= phrase3.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase3[i]);
            if (i > 14 && i < 18)
                Sleep(250);
            else if (i >= 19 && i <= 20)
                Sleep(180);
            else if (i > 20 && i <= 28)
                Sleep(230);
            else if (i > 28) {
                Sleep(150);
            }
            else
                Sleep(40);
        }
        Sleep(6000 - (phrase3.length() * 100));

        for (i = 0; i <= phrase4.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase4[i]);
            if (i > 20 && i <= 28)
                Sleep(200);
            else if (i > 28) {
                Sleep(120);
            }
            else
                Sleep(80);
        }

        PictureBox.setGlobalColor(YELLOW);
        PictureBox.setStartPoint(35);
        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");


        Sleep(3900 - (phrase4.length() * 100));

        for (i = 0; i <= phrase5.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase5[i]);
            Sleep(80);
        }

        for (i = 0; i <= phrase6.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase6[i]);
            Sleep(80);
        }

        Sleep(3130 - (phrase6.length() * 100));

        for (i = 0; i <= phrase7.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase7[i]);
            if (i > 4 && i < 9)
                Sleep(250);
            else if (i > 23 && i < 26)
                Sleep(160);
            else
                Sleep(80);
        }

        Sleep(3400 - (phrase7.length() * 100));

        for (i = 0; i <= phrase8.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase8[i]);
            Sleep(70);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }
        PictureBox.setxy(35, 15);

        PictureBox.print("             =+$HM####@H%;,\n");
        PictureBox.print("          /H###############M$,\n");
        PictureBox.print("          ,@################+\n");
        PictureBox.print("           .H##############+\n");
        PictureBox.print("             X############/\n");
        PictureBox.print("               $##########/\n");
        PictureBox.print("                %########/\n");
        PictureBox.print("                /X/;;+X/\n");
        PictureBox.print("                 -XHHX-\n");
        PictureBox.print("                ,######,\n");
        PictureBox.print("#############X  .M####M.  X#############\n");
        PictureBox.print("##############-   -//-   -##############\n");
        PictureBox.print("X##############%,      ,+##############X\n");
        PictureBox.print("-##############X        X##############-\n");
        PictureBox.print("%############%          %############% \n");
        PictureBox.print(" %##########;            ;##########% \n");
        PictureBox.print(" ;#######M=              =M#######;\n");
        PictureBox.print(" .+M###@,                ,@###M+.\n");
        PictureBox.print("   :XH.                  .HX:\n");


        for (i = 0; i <= phrase9.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase9[i]);
            Sleep(70);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");

        for (i = 0; i <= phrase10.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase10[i]);
            Sleep(60);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("                 =/;;/-  \n");
        PictureBox.print("                 +:    //\n");
        PictureBox.print("                /;      /;\n");
        PictureBox.print("              -X        H. \n");
        PictureBox.print(".//;;;:;;-,   X=        :+   .-;:=;:;%;. \n");
        PictureBox.print(" M-       ,=;;;#:,      ,:#;;:=,       ,@\n");
        PictureBox.print(":%           :%.=/++++/=.$=           %= \n");
        PictureBox.print(" ,%;         %/:+/;,,/++:+/         ;+. \n");
        PictureBox.print("   ,+/.    ,;@+,        ,%H;,    ,/+, \n");
        PictureBox.print("       ;+;;/= @.  .H##X   -X :///+;\n");
        PictureBox.print("      ;+=;;;.@,  .XM@$.  =X.//;=%/. \n");
        PictureBox.print("   ,;:      :@%=        =$H:     .+%- \n");
        PictureBox.print("  ,%=         %;-///==///-//         =%,\n");
        PictureBox.print(";+           :%-;;;:;;;;-X-           +: \n");
        PictureBox.print("@-      .-;;;;M-        =M/;;;-.      -X \n");
        PictureBox.print(" :;;::;;-.    %-        :+    ,-;;-;:== \n");
        PictureBox.print("              ,X        H. \n");
        PictureBox.print("               ;/      %= \n");
        PictureBox.print("                 //    +;\n");
        PictureBox.print("                  ,////, \n");

         for (i = 0; i <= phrase11.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase11[i]);
            Sleep(80);
        }

        for (i = 0; i <= phrase12.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase12[i]);
            Sleep(80);
        }

            for (i = 0; i < 22; i++) {
                PictureBox.setxy(35, 15 + i);
                for (int j = 0; j < 44; j++) {

                    PictureBox.print(" ");
                }
            }
            PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");


        for (i = 0; i <= phrase13.length(); i++)
        {
            LyricBox.putch(YELLOW, phrase13[i]);
            Sleep(60);
        }


        LyricBox.setxy(1, 1);
        LyricBox.setLimit(40);
        for (int i = 0; i < 36; i++) {


            for (int j = 0; j < 30; j++) {

                LyricBox.print(" ");
            }

            if (i != 36)
                LyricBox.print("\n");
        }
        LyricBox.setLimit(30);
        LyricBox.setxy(1, 1);
        string t4 = "FORM FOEM-555551 - 5";
        string t5 = "\nPersonel File Addenum \n \n \n";
        string t6 = "\nDear, <<Subject Name Here>>";


        for (int i = 0; i <= t4.length(); i++)
        {
            LyricBox.putch(YELLOW, t4[i]);
            Sleep(80);
        }
        for (int i = 0; i <= t5.length(); i++)
        {
            LyricBox.putch(YELLOW, t5[i]);
            Sleep(80);
        }
        for (int i = 0; i <= t6.length(); i++)
        {
            LyricBox.putch(YELLOW, t6[i]);
            Sleep(80);
        }

        Sleep(3800 - ((phrase13.length() * 100)));

        for (i = 0; i <= refrain.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain[i]);
            Sleep(80);
        }
        Sleep(4600 - (refrain.length() * 100));

        for (i = 0; i <= refrain1.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain1[i]);
            Sleep(100);
        }

        Sleep(4400 - (refrain1.length() * 100) );

        for (i = 0; i <= refrain2.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain2[i]);
            if (i == 16) {

                for (int k = 0; k < 22; k++) {
                    PictureBox.setxy(35, 15 + k);
                    for (int j = 0; j < 44; j++) {

                        PictureBox.print(" ");
                    }
                }

                PictureBox.setxy(35, 15);
                PictureBox.print("                          .,---.\n");
                PictureBox.print("                        ,/XM#MMMX;,\n");
                PictureBox.print("                      -%##########M%,\n");
                PictureBox.print("                     -@######%  $###@=\n");
                PictureBox.print("      .,--,         -H#######$   $###M:\n");
                PictureBox.print("   ,;$M###MMX;     .;##########$;HM###X=\n");
                PictureBox.print(" ,/@##########H=      ;################+\n");
                PictureBox.print("-+#############M/,      %##############+\n");
                PictureBox.print("%M###############=      /##############:\n");
                PictureBox.print("H################      .M#############;.\n");
                PictureBox.print("@###############M      ,@###########M:.\n");
                PictureBox.print("X################,      -$=X#######@:\n");
                PictureBox.print("/@##################%-     +######$-\n");
                PictureBox.print(".;##################X     .X#####+,\n");
                PictureBox.print(" .;H################/     -X####+.\n");
                PictureBox.print("   ,;X##############,       .MM/\n");
                PictureBox.print("      ,:+$H@M#######M#$-    .$$=\n");
                PictureBox.print("           .,-=;+$@###X:    ;/=.\n");
                PictureBox.print("                  .,/X$;   .::,\n");
                PictureBox.print("                      .,    ..\n");
            }
            else {

                Sleep(100);
            }
        }

        for (i = 0; i <= refrain3.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain3[i]);
            Sleep(80);
        }

        Sleep(4200 - (refrain3.length() * 100));


        for (i = 0; i <= refrain4.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain4[i]);
            Sleep(80);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("            .+ \n");
        PictureBox.print("              /M;\n");
        PictureBox.print("              H#@:              ;, \n");
        PictureBox.print("              -###H-          -@/ \n");
        PictureBox.print("               %####$.  -;  .%#X \n");
        PictureBox.print("                M#####+;#H :M#M. \n");
        PictureBox.print(" ..          .+/;%#########X###-\n");
        PictureBox.print(" -/%H%+;-,    +##############/  \n");
        PictureBox.print("    .:$M###MH$%+############X  ,--=;- \n");
        PictureBox.print("         -/H#####################H+=.\n");
        PictureBox.print("           .+#################X. \n");
        PictureBox.print("         =%M####################H;. \n");
        PictureBox.print("            /@###############+;;/%%; \n");
        PictureBox.print("         -%###################$. \n");
        PictureBox.print("        ;H######################M=\n");
        PictureBox.print("    ,%#####MH$%;+#####M###-/@####% \n");
        PictureBox.print("  :$H%+;=-      -####X.,H#   -+M##@- \n");
        PictureBox.print(" .              ,###;    ;      =$##+\n");
        PictureBox.print("                .#H,               :XH, \n");
        PictureBox.print("                 +                   .;- \n");

        Sleep(4000 - (refrain4.length() * 100));

       for (i = 0; i <= refrain5.length(); i++)
        {
            LyricBox.putch(YELLOW, refrain5[i]);
            Sleep(100);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("                             -$-\n");
        PictureBox.print("                    .H##H,\n");
        PictureBox.print("                   +######+\n");
        PictureBox.print("                .+#########H.\n");
        PictureBox.print("              -$############@.\n");
        PictureBox.print("            =H###############@  -X:\n");
        PictureBox.print("          .$##################:  @#@-\n");
        PictureBox.print("     ,;  .M###################;  H###;\n");
        PictureBox.print("   ;@#:  @###################@  ,#####:\n");
        PictureBox.print(" -M###.  M#################@.  ;######H\n");
        PictureBox.print(" M####-  +###############$   =@#######X\n");
        PictureBox.print(" H####$   -M###########+   :#########M,\n");
        PictureBox.print("  /####X-   =########%   :M########@/.\n");
        PictureBox.print("    ,;%H@X;   .$###X   :##MM@%+;:-\n");
        PictureBox.print("                 ..\n");
        PictureBox.print("  -/;:-,.              ,,-==+M########H\n");
        PictureBox.print(" -##################@HX%%+%%$%%%+:,,\n");
        PictureBox.print("    .-/H%%%+%%$H@###############M@+=:/+:\n");
        PictureBox.print("/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$\n");
        PictureBox.print("$@#MX %+;-\n");

        Sleep(4200 - (refrain5.length() * 100));

        for (int x = 0; x < refrain6.length(); x++)
        {

            LyricBox.putch(YELLOW, refrain6[x]);

            if (x == 26) {


                for (int k = 0; k < 22; k++) {
                    PictureBox.setxy(35, 15 + k);
                    for (int l = 0; l < 44; l++) {

                        PictureBox.print(" ");
                    }
                }

                PictureBox.setxy(35, 15);
                PictureBox.print("                                    :X-\n");
                PictureBox.print("                                  :X###\n");
                PictureBox.print("                                ;@####@\n");
                PictureBox.print("                              ;M######X\n");
                PictureBox.print("                            -@########$\n");
                PictureBox.print("                          .$##########@\n");
                PictureBox.print("                         =M############-\n");
                PictureBox.print("                        +##############$\n");
                PictureBox.print("                      .H############$=.\n");
                PictureBox.print("         ,/:         ,M##########M;.\n");
                PictureBox.print("      -+@###;       =##########M;\n");
                PictureBox.print("   =%M#######;     :#########M/\n");
                PictureBox.print("-$M###########;   :#########/\n");
                PictureBox.print(" ,;X###########; =########$.\n");
                PictureBox.print("     ;H#########+#######M=\n");
                PictureBox.print("       ,+##############+\n");
                PictureBox.print("          /M#########@-\n");
                PictureBox.print("            ;M######% \n");
                PictureBox.print("              +####:\n");
                PictureBox.print("               ,$M-\n");
            }
            else {
                Sleep(80);
            }
        }

        Sleep(1000);


        Sleep(5800 - (refrain6.length() * 100));

        int z = 0;

        for (z = 0; z <= refrain7.length(); z++)
        {
            LyricBox.putch(YELLOW, refrain7[z]);
            Sleep(80);
        }

        for (int p = 0; p < 22; p++) {
            PictureBox.setxy(35, 15 + p);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("            .+ \n");
        PictureBox.print("              /M;\n");
        PictureBox.print("              H#@:              ;, \n");
        PictureBox.print("              -###H-          -@/ \n");
        PictureBox.print("               %####$.  -;  .%#X \n");
        PictureBox.print("                M#####+;#H :M#M. \n");
        PictureBox.print(" ..          .+/;%#########X###-\n");
        PictureBox.print(" -/%H%+;-,    +##############/  \n");
        PictureBox.print("    .:$M###MH$%+############X  ,--=;- \n");
        PictureBox.print("         -/H#####################H+=.\n");
        PictureBox.print("           .+#################X. \n");
        PictureBox.print("         =%M####################H;. \n");
        PictureBox.print("            /@###############+;;/%%; \n");
        PictureBox.print("         -%###################$. \n");
        PictureBox.print("        ;H######################M=\n");
        PictureBox.print("    ,%#####MH$%;+#####M###-/@####% \n");
        PictureBox.print("  :$H%+;=-      -####X.,H#   -+M##@- \n");
        PictureBox.print(" .              ,###;    ;      =$##+\n");
        PictureBox.print("                .#H,               :XH, \n");
        PictureBox.print("                 +                   .;- \n");

       for (z = 0; z <= refrain8.length(); z++)
        {
           LyricBox.putch(YELLOW, refrain8[z]);
            Sleep(60);
        }

        for (z = 0; z <= refrain9.length(); z++)
        {
            LyricBox.putch(YELLOW, refrain9[z]);
            Sleep(60);
        }

        for (int z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");

        for (z = 0; z <= refrain10.length(); z++)
        {
            LyricBox.putch(YELLOW, refrain10[z]);
            Sleep(80);
        }

         for (z = 0; z <= refrain11.length(); z++)
        {
            LyricBox.putch(YELLOW, refrain11[z]);
            Sleep(60);
        }

        for (z = 0; z <= refrain12.length(); z++)
        {
            LyricBox.putch(YELLOW, refrain12[z]);
            Sleep(80);
        }

    for (z = 0; z < 22; z++) {
        PictureBox.setxy(35, 15 + z);
        for (int j = 0; j < 44; j++) {

            PictureBox.print(" ");
        }
    }

    PictureBox.setxy(35, 15);

    PictureBox.print("                   ;=         \n");
    PictureBox.print("                   /=         \n");
    PictureBox.print("                   ;=         \n");
    PictureBox.print("                   /=         \n");
    PictureBox.print("                   ;=         \n");
    PictureBox.print("                   /=         \n");
    PictureBox.print("                   ;=         \n");
    PictureBox.print("                   /=         \n");
    PictureBox.print("            ,--==-:$;         \n");
    PictureBox.print("        ,/$@#######@X+-       \n");
    PictureBox.print("     ./@###############X=     \n");
    PictureBox.print("    /M#####X+/;;;;+H#####$.   \n");
    PictureBox.print("   %####M/;+H@XX@@%;;@####@,  \n");
    PictureBox.print("  +####H=+##$,--,=M#X-%####@. \n");
    PictureBox.print(" -####X,X@HHXH##MXHXXH-+####$ \n");
    PictureBox.print(" X###@.X/$M$:####$=@X/X,X####-\n");
    PictureBox.print(".####:+$:##@:####$:##H/X=####% \n");
    PictureBox.print("-%%$%,+==%$+-$+:$;-$$%-+,/$%%+\n");
    PictureBox.print("-/+%%X$XX$$$$$$$%$$$%$X$X$%+/-\n");


        Sleep(500);


        LyricBox.setxy(1, 1);
        LyricBox.setLimit(40);
        for (int z = 0; z < 36; z++) {


            for (int j = 0; j < 30; j++) {

                LyricBox.print(" ");
            }

            if (z != 36)
                LyricBox.print("\n");
        }
        LyricBox.setLimit(30);
        LyricBox.setxy(1, 1);
        string t7 = "FORM FOEM-555551 - 6";
        string t8 = "\nPersonel File Addenum Addenum\n";
        string t9 = "\nOne last thing,\n";


        for (int z = 0; z <= t7.length(); z++)
        {
            LyricBox.putch(YELLOW, t7[z]);
            Sleep(60);
        }
        for (int z = 0; z <= t8.length(); z++)
        {
            LyricBox.putch(YELLOW, t8[z]);
            Sleep(40);
        }
        for (int z = 0; z <= t9.length(); z++)
        {
            LyricBox.putch(YELLOW, t9[z]);
            Sleep(60);
        }

        string tmp = "\nGo ahead and leave me...";
        Sleep(1500);

        for (z = 0; z <= tmp.length(); z++) {

            LyricBox.putch(YELLOW, tmp[z]);
            Sleep(80);
        }
        Sleep(1200);
        for (z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");


         for (z = 0; z <= chorus.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus[z]);
            Sleep(100);
        }
        Sleep(4700 - chorus.length() * 100);


        for (z = 0; z <= chorus1.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus1[z]);

            if (z < 7) {
                Sleep(300);
            }
            else if (z >= 14 && z <= 18) {
                Sleep(160);
            }
            else {
                Sleep(60);
            }
        }
        Sleep(7600 - chorus1.length() * 100);

        for (z = 0; z <= chorus2.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus2[z]);
            Sleep(100);
        }

        for (z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("           .-;+$XHHHHHHX$+;-.\n");
        PictureBox.print("        ,;X@@X%/;=----=:/%X@@X/,\n");
        PictureBox.print("      =$@@%=.              .=+H@X:\n");
        PictureBox.print("    -XMX:                      =XMX=\n");
        PictureBox.print("   /@@:                          =H@+\n");
        PictureBox.print("  %@X,                            .$@$\n");
        PictureBox.print(" +@X.                               $@%\n");
        PictureBox.print("-@@,                                .@@=\n");
        PictureBox.print("%@%                                  +@$\n");
        PictureBox.print("H@:                                  :@H\n");
        PictureBox.print("H@:         :HAAAAAAAAAAAAAAAAAX!,    =@H\n");
        PictureBox.print("%@%         ;@M@@@@@@@@@@@@@@@@@H-   +@$\n");
        PictureBox.print("=@@,        :@@@@@@@@@@@@@@@@@@@@@= .@@:\n");
        PictureBox.print(" +@X        :@@@@@@@@@@@@@@@M@@@@@@:%@%\n");
        PictureBox.print("  $@$,      ;@@@@@@@@@@@@@@@@@M@@@@@@$.\n");
        PictureBox.print("   +@@HHHHHHH@@@@@@@@@@@@@@@@@@@@@@@+\n");
        PictureBox.print("    =X@@@@@@@@@@@@@@@@@@@@@@@@@@@@X=\n");
        PictureBox.print("      :$@@@@@@@@@@@@@@@@@@@M@@@@$:\n");
        PictureBox.print("        ,;$@@@@@@@@@@@@@@@@@@X/-\n");
        PictureBox.print("           .-;+$XXHHHHHX$+;-.\n");


        Sleep(3800 - chorus2.length() * 100);



        for (z = 0; z <= chorus3.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus3[z]);
            Sleep(100);
        }

        for (z = 0; z <= chorus4.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus4[z]);
            Sleep(100);
        }

        for (z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("            ,:/+/-                      \n");
        PictureBox.print("            /M/              .,-=;//;-  \n");
        PictureBox.print("       .:/= ;MH/,    ,=/+%$XH@MM#@:     \n");
        PictureBox.print("      -$##@+$###@H@MMM#######H:.    -/H#\n");
        PictureBox.print(" .,H@H@ X######@ -H#####@+-     -+H###@X\n");
        PictureBox.print("  .,@##H;      +XM##M/,     =%@###@X;-  \n");
        PictureBox.print("X%-  :M##########$.    .:%M###@%:       \n");
        PictureBox.print("M##H,   +H@@@$/-.  ,;$M###@%,          -\n");
        PictureBox.print("M####M=,,---,.-%%H####M$:          ,+@##\n");
        PictureBox.print("@##################@/.         :%H##@$- \n");
        PictureBox.print("M###############H,         ;HM##M$=     \n");
        PictureBox.print("#################.    .=$M##M$=         \n");
        PictureBox.print("################H..;XM##M$=          .:+\n");
        PictureBox.print("M###################@%=           =+@MH% \n");
        PictureBox.print("@################M/.          =+H#X%=   \n");
        PictureBox.print("=+M##############M,       -/X#X+;.      \n");
        PictureBox.print("  .;XM##########H=    ,/X#H+:,          \n");
        PictureBox.print("     .=+HM######M+/+HM@+=.              \n");
        PictureBox.print("         ,:/%XM####H/.                  \n");
        PictureBox.print("              ,.:=-.                    \n");

        Sleep(700);


        for (z = 0; z <= chorus5.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus5[z]);
            Sleep(100);
        }

        Sleep(3000 - chorus5.length() * 100);

        for (z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");

        for (z = 0; z <= chorus6.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus6[z]);
            Sleep(70);
        }
        for (z = 0; z <= chorus7.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus7[z]);
            Sleep(70);
        }

        for (z = 0; z <= chorus8.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus8[z]);
            Sleep(70);
        }

        for (i = 0; i < 22; i++) {
            PictureBox.setxy(35, 15 + i);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("                 =/;;/-  \n");
        PictureBox.print("                 +:    //\n");
        PictureBox.print("                /;      /;\n");
        PictureBox.print("              -X        H. \n");
        PictureBox.print(".//;;;:;;-,   X=        :+   .-;:=;:;%;. \n");
        PictureBox.print(" M-       ,=;;;#:,      ,:#;;:=,       ,@\n");
        PictureBox.print(":%           :%.=/++++/=.$=           %= \n");
        PictureBox.print(" ,%;         %/:+/;,,/++:+/         ;+. \n");
        PictureBox.print("   ,+/.    ,;@+,        ,%H;,    ,/+, \n");
        PictureBox.print("       ;+;;/= @.  .H##X   -X :///+;\n");
        PictureBox.print("      ;+=;;;.@,  .XM@$.  =X.//;=%/. \n");
        PictureBox.print("   ,;:      :@%=        =$H:     .+%- \n");
        PictureBox.print("  ,%=         %;-///==///-//         =%,\n");
        PictureBox.print(";+           :%-;;;:;;;;-X-           +: \n");
        PictureBox.print("@-      .-;;;;M-        =M/;;;-.      -X \n");
        PictureBox.print(" :;;::;;-.    %-        :+    ,-;;-;:== \n");
        PictureBox.print("              ,X        H. \n");
        PictureBox.print("               ;/      %= \n");
        PictureBox.print("                 //    +;\n");
        PictureBox.print("                  ,////, \n");

        for (z = 0; z <= chorus9.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus9[z]);
            Sleep(70);
        }

        for (int p = 0; p < 22; p++) {
            PictureBox.setxy(35, 15 + p);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);
        PictureBox.print("            .+ \n");
        PictureBox.print("              /M;\n");
        PictureBox.print("              H#@:              ;, \n");
        PictureBox.print("              -###H-          -@/ \n");
        PictureBox.print("               %####$.  -;  .%#X \n");
        PictureBox.print("                M#####+;#H :M#M. \n");
        PictureBox.print(" ..          .+/;%#########X###-\n");
        PictureBox.print(" -/%H%+;-,    +##############/  \n");
        PictureBox.print("    .:$M###MH$%+############X  ,--=;- \n");
        PictureBox.print("         -/H#####################H+=.\n");
        PictureBox.print("           .+#################X. \n");
        PictureBox.print("         =%M####################H;. \n");
        PictureBox.print("            /@###############+;;/%%; \n");
        PictureBox.print("         -%###################$. \n");
        PictureBox.print("        ;H######################M=\n");
        PictureBox.print("    ,%#####MH$%;+#####M###-/@####% \n");
        PictureBox.print("  :$H%+;=-      -####X.,H#   -+M##@- \n");
        PictureBox.print(" .              ,###;    ;      =$##+\n");
        PictureBox.print("                .#H,               :XH, \n");
        PictureBox.print("                 +                   .;- \n");

        for (z = 0; z <= chorus10.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus10[z]);
            Sleep(70);
        }

        for (z = 0; z <= chorus11.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus11[z]);
            Sleep(70);
        }
        for (z = 0; z < 22; z++) {
            PictureBox.setxy(35, 15 + z);
            for (int j = 0; j < 44; j++) {

                PictureBox.print(" ");
            }
        }

        PictureBox.setxy(35, 15);

            PictureBox.print("              .,-:;//;:=,\n");
            PictureBox.print("       . :H@@@MM@M#H/.,+%;,\n");
            PictureBox.print("       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n");
            PictureBox.print("   -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n");;
            PictureBox.print("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n");
            PictureBox.print("  ,%MM@@MH ,@%=            .---=-=:=,. \n");
            PictureBox.print("  =@#@@@MX .,              -%HX$$%%%+;  \n");
            PictureBox.print(" =-./@M@M$                  .;@MMMM@MM: \n");
            PictureBox.print(" X@/ -$MM/                    .+MM@@@M$ \n");
            PictureBox.print(",@M@H: :@:                    . =X#@@@@-\n");
            PictureBox.print(",@@@MMX, .                    /H- ;@M@M=\n");
            PictureBox.print(".H@@@@M@+,                    %MM+..%#$.\n");
            PictureBox.print(" /MMMM@MMH/.                  XM@MH; =;\n");
            PictureBox.print("  /%+%$XHH@$=              , .H@@@@MX,\n");
            PictureBox.print("   .=--------.           -%H.,@@@@@MX,\n");
            PictureBox.print("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM% \n");
            PictureBox.print("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n");
            PictureBox.print("       =%@M@M#@$-.=$@MM@@@M; %M%=\n");
            PictureBox.print("         ,:+$+-,/H#MMMMMMM@= =,\n");
            PictureBox.print("               =++%%%%+/:-.\n");


        Sleep(100);

        for (z = 0; z <= chorus12.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus12[z]);
            Sleep(70);
        }

        LyricBox.setxy(1, 1);
        LyricBox.setLimit(40);
        for (int z = 0; z < 36; z++) {


            for (int j = 0; j < 30; j++) {

                LyricBox.print(" ");
            }

            if (z != 36)
                LyricBox.print("\n");
        }
        LyricBox.setLimit(30);
        LyricBox.setxy(1, 6);

        Sleep(700);

        for (z = 0; z <= chorus13.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus13[z]);
            Sleep(90);
        }

        Sleep(100);

        for (z = 0; z <= chorus14.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus14[z]);
            if (z <= 3)
                Sleep(120);
            else
                Sleep(80);
        }

        Sleep(300);

        for (z = 0; z <= chorus15.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus15[z]);
            Sleep(60);
        }

        for (z = 0; z <= chorus16.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus16[z]);
            Sleep(60);
        }

        for (z = 0; z <= chorus17.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus17[z]);
            if (z == 17) {
                Sleep(150);
            }
            else {
                Sleep(60);
            }

        }

        Sleep(500);

        for (z = 0; z <= chorus18.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus18[z]);
            Sleep(60);
        }

        Sleep(500);

        for (z = 0; z <= chorus19.length(); z++)
        {
            LyricBox.putch(YELLOW, chorus19[z]);
            Sleep(60);
        };
        Sleep(3500);
        break;
    }

    cnTerm_Deactivate;
}
