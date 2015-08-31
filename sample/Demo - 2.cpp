#define NOCONFIRMONEXIT
#define INHERITCURRENTCURSOR

#include <Shlwapi.h>
#include <direct.h>
#include <fstream>
#include <cctype>
#include <vector>
#define getcwd _getcwd


#include "../headers/Terminal"

/*
    Mimic ls utility of unix using the Terminal Library
*/

enum filetype {NONAME, EXECUTABLE, FOLDER, DOCUMENT, DIRECTORY, PICTURE};

COLOR exe;
COLOR doc;
COLOR dir;
COLOR pic;

std::vector <std::string> exefiletype;
std::vector <std::string> docfiletype;
std::vector <std::string> picfiletype;

std::string exePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    std::string::size_type pos = std::string( buffer ).find_last_of( "\\/" );
    return std::string( buffer ).substr( 0, pos);
}

std::string getFileType (std::string name)
{
    std::string substr = "NULL";
    int pos = -1;
    for (int i = 0; i < name.size(); i++)
    {
        if (name.at(i) == '.')
            pos = i;
    }

    if (pos != -1)
    substr = name.substr(pos);
    else
    substr = "DIRECTORY";
    return substr;

}

int largest (int a, int b, int c)
{
    int bb[3] = {a, b, c};
    int lg;
    for (int i = 0; i < 3; i++)
        if (i == 0 || lg < bb[i])
            lg = bb[i];
    return lg;

}

std::string transform (std::string str)
{
    for (int i = 0; i < str.size(); i++)
        str.at(i) = toupper(str.at(i));
    return str;
}



std::string getStringEquivalent (COLOR clr)
{
    std::string cc;
    switch (clr)
    {
        case DARKBLUE:
            cc = "DARKBLUE";
            break;
        case DARKCYAN:
            cc = "DARKCYAN";
            break;
        case DARKGREEN:
            cc = "DARKGREEN";
            break;
        case DARKRED:
            cc = "DARKRED";
            break;
        case DARKYELLOW:
            cc = "DARKYELLOW";
            break;
        case DARKPURPLE:
            cc = "DARKPURPLE";
            break;
        case DEFAULT:
            cc = "DEFAULT";
            break;
        case BLUE:
            cc = "BLUE";
            break;
        case CYAN:
            cc = "CYAN";
            break;
        case GREEN:
            cc = "GREEN";
            break;
        case RED:
            cc = "RED";
            break;
        case YELLOW:
            cc = "YELLOW";
            break;
        case PURPLE:
            cc = "PURPLE";
            break;
        case GREY:
            cc = "GREY";
            break;
    }
    return cc;
}

COLOR getColorEquivalent (std::string str)
{
    for (int i = 0; i < 14; i++)
    {
        if (getStringEquivalent((COLOR)i) == str)
        return (COLOR)i;
    }
    return DEFAULT;
}


void readType ()
{
    std::ifstream file(exePath() + "\\lsappvar.config");
    std::string buffer;

    while (!file.eof())
    {

        file >> buffer;
        if (buffer == "COLOR")
        {
            file >> buffer;
            while (buffer != "END")
            {
                if (buffer == "EXE")
                {
                    file >> buffer;
                    exe = getColorEquivalent(buffer);
                }
                else if (buffer == "DOC")
                {
                    file >> buffer;
                    doc = getColorEquivalent(buffer);
                }
                else if (buffer == "DIRECTORY")
                {
                    file >> buffer;
                    dir = getColorEquivalent(buffer);
                }
                else if (buffer == "PIC")
                {
                    file >> buffer;
                    pic = getColorEquivalent(buffer);
                }

                file >> buffer;
            }
        }
        else if (buffer == "FILEMIMIC")
        {
            file >> buffer;
            while (buffer != "END")
            {
                if (buffer == "EXE")
                {
                    file >> buffer;
                    while (1)
                    {
                        ExeL:
                        if (buffer == "END")
                            break;
                        else if (buffer == "DOC")
                            goto DocL;
                        else if (buffer == "PIC")
                            goto PicL;
                        exefiletype.insert(exefiletype.end(), buffer);

                        file >> buffer;
                    }

                }
                else if (buffer == "DOC")
                {
                    file >> buffer;
                    while (1)
                    {
                        DocL:
                        if (buffer == "END")
                            break;
                        else if (buffer == "EXE")
                            goto ExeL;
                        else if (buffer == "PIC")
                            goto PicL;


                        docfiletype.insert(docfiletype.end(), buffer);

                        file >> buffer;
                    }
                }
                else if (buffer == "PIC")
                {
                    file >> buffer;
                    while (1)
                    {
                        PicL:
                        if (buffer == "END")
                            break;
                        else if (buffer == "EXE")
                            goto ExeL;
                        else if (buffer == "DOC")
                            goto DocL;
                        picfiletype.insert(picfiletype.end(), buffer);

                        file >> buffer;
                    }
                }

                file >> buffer;
            }
        }
    }

}

filetype getFileName (std::string name)
{
    filetype type = NONAME;
    std::string Type = getFileType(name);
    if (Type == "NULL")
    {
        return NONAME;
    }


    for (int i = 0; i < largest(docfiletype.size(), exefiletype.size(), picfiletype.size()); i++)
    {
        if (i < exefiletype.size())
        {
            if (transform(Type) == transform(exefiletype.at(i)))
            {
                type = EXECUTABLE;
                break;
            }
        }

        if (i < docfiletype.size())
        {
            if (transform(Type) == transform(docfiletype.at(i)))
            {
                type = DOCUMENT;
                break;
            }
        }

        if (i < picfiletype.size())
        {
            if (transform(Type) == transform(picfiletype.at(i)))
            {
                type = PICTURE;
                break;
            }
        }

    }

    return type;
}

void fixType (std::string *ptr)
{
    char *s = "\\";

    for (int32_t i = 0; i < ptr->size(); i++)
    {

        if (ptr->at(i) == '\\')
        {
            ptr->insert(i, s);
            i++;
        }
    }

}

void shorten (std::string &strtmp, int limit)
{
    if (strtmp.size() <= limit)
    return;

    std::string tmp = strtmp;
    strtmp = "";

    for (int i = 0; i < limit - 3; i++)
    {
        strtmp += tmp.at(i);
    }

    strtmp += "...";
}

std::string getDrive (std::string msg)
{
    std::string org;
    int sub = -1;
    for (int i = 0; i < msg.size(); i++)
    {
        if (msg.at(i) == '\\')
        {
            sub = i;
            break;
        }
    }

    return msg.substr(0, sub -1);
}

char* getDriveC (std::string msg)
{
    char *org = new char[20];
    for (int i = 0; i < msg.size(); i++)
    {
        org[i] = msg.at(i);
        if (msg.at(i) == '\\')
        {
            org[i] = '\\';
            org[i + 1] = '\0';
            break;
        }
    }

    return org;
}

class CUSTOMTERMINAL : Terminal
{
    private:

    public:

    friend int main (int argc, char ** argv);
};

bool DirectoryExists(LPCTSTR szPath)
{
  DWORD dwAttrib = GetFileAttributes(szPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

bool file_exist (std::string name)
{
    std::ifstream file(name);
    return file;
}

std::streampos fileSize( const char* filePath ){

    std::streampos fsize = 0;
    std::ifstream file( filePath, std::ios::binary );

    fsize = file.tellg();
    file.seekg( 0, std::ios::end );
    fsize = file.tellg() - fsize;
    file.close();

    return fsize;
}



int main (int argc, char ** argv)
{
    uint64_t filenum = 0, dirnum = 0;
    if (!file_exist(exePath() + "\\lsappvar.config"))
    {
        std::ofstream file(exePath() + "\\lsappvar.config");
        file << "COLOR" << std::endl;
        file << "\tEXE GREEN" << std::endl;
        file << "\tDOC YELLOW" << std::endl;
        file << "\tPIC PURPLE" << std::endl;
        file << "\tDIRECTORY CYAN" << std::endl;
        file << "END" << std::endl;
        file << "\nFILEMIMIC" << std::endl;
        file << "\tEXE .exe" << std::endl;
        file << "\tDOC .doc .txt" << std::endl;
        file << "\tPIC .png .jpg .bmp" << std::endl;
        file << "END" << std::endl;
    }
    cnTerm_Activate;
    COLOR clr = DEFAULT;
    HANDLE hFind;
    WIN32_FIND_DATA FilePicker;
    std::string Directory;
    readType();

    char buffer[256];
    char *answer = getcwd(buffer, sizeof(buffer));
    if (answer)
    {
        Directory = answer;
    }
    std::string Original = Directory;
    fixType(&Directory);
    std::string UnFixedOriginal = Directory;

    Directory += "\\\\*.*";
    hFind = FindFirstFile(Directory.c_str(), &FilePicker);

    int y = 0;
    int x = 0;

    CUSTOMTERMINAL console;
    console.getxy(&x, &y);
    y += 6;




    LPCTSTR szHD = getDriveC(Directory);
    char *szFileSys[255],szVolNameBuff[255];
    DWORD dwSerial,dwMFL,dwSysFlags;
    BOOL bSuccess;

    bSuccess = GetVolumeInformation(szHD,(LPTSTR)szVolNameBuff,
                         255,&dwSerial, &dwMFL,&dwSysFlags,
                         (LPTSTR)szFileSys,255);
    char buff[256];
    sprintf(buff, "%p", dwSerial);
    std::string serialhdd = buff;
    serialhdd = transform(serialhdd);
    serialhdd.insert(4, "-");
    std::string szVolNameStr = szVolNameBuff;

    if (szVolNameStr != "")
    {
        console.print("\n Volume in drive ");
        console.print(DARKGREEN, "[%s]",getDrive(Original).c_str());
        console.print(" is ");
        console.print(DARKGREEN, "[%s]\n", szVolNameBuff);
    }
    else
    {
        console.print("\n Volume in drive ");
        console.print(DARKGREEN, "[%s]", getDrive(Original).c_str());
        console.print(" has no label");
    }

    console.print("\n Volume Serial Number is ");
    console.print(DARKGREEN, "[%s]", serialhdd.c_str());

    console.print("\n\n Directory of ");
    console.print(DARKGREEN, "[%s]\n\n", Original.c_str());
    if (UnFixedOriginal.at(UnFixedOriginal.size() - 2) != ':')
    {
        console.gotoxy(x, y);
        console.print(dir, "[.]");
        x += 24;
        dirnum++;
    }


    while (FindNextFile(hFind, &FilePicker))
    {
        std::string msg = FilePicker.cFileName;
        shorten(msg, 23);

        if (msg == "[..]")
        {
            clr = PURPLE;
        }
        else
        {
            std::string cc = UnFixedOriginal + "\\\\" + msg;
            if (DirectoryExists(cc.c_str()))
            {
                dirnum++;
                clr = dir;
                msg = "[" + msg + "]";
            }
            else
            {
                filenum++;
                switch (getFileName(msg))
                {
                    case EXECUTABLE:
                        clr = exe;
                        break;
                    case DOCUMENT:
                        clr = doc;
                        break;
                    case PICTURE:
                        clr = pic;
                        break;
                    default:
                        clr = DEFAULT;
                }
            }


        }


        console.gotoxy(x, y);
        console.print(clr, "%s", msg.c_str());

        x += 24;
        if (x > 48)
        {
            x = 0;
            y++;
        }

    }

    y++;
    x = 15;
    console.gotoxy(x, y);
    console.print("%d File(s)", filenum);
    y++;
    x = 15;
    console.gotoxy(x, y);
    console.print("%d Dir(s)\n\n", dirnum);

    cnTerm_Deactivate;
    return 0;
}
