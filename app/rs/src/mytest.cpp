
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string.h>
#include <io.h>
#pragma   comment(lib,"shlwapi.lib")

#include <shlwapi.h>
using namespace std;


void getFiles(string path, vector<string>& files)
{
    //文件句柄
    intptr_t   hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}


void test27()
{
    char* filePath =(char*) "F:\\video\\4摄像头\\1";
    vector<string> files;

            getFiles(filePath, files);

    char str[30];
    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        cout << files[i].c_str() << endl;
    }
}

