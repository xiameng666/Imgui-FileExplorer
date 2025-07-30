// FileManager.h
#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct FileItem {
    std::string fileName;          // �ļ���
    std::string fullPath;          // ����·��  
    LARGE_INTEGER fileSize;        // �ļ���С
    DWORD attributes;              // �ļ�����
    FILETIME createTime;           // ����ʱ��
    FILETIME modifyTime;           // �޸�ʱ��
    bool isDirectory;              // �Ƿ�Ŀ¼
    std::string fileType;          // �ļ�����(��չ��)
};

struct DirectoryNode {
    std::string path;                   // Ŀ¼·��
    std::string name;                   // Ŀ¼��
    std::vector<DirectoryNode> subDirs; // ��Ŀ¼
    std::vector<FileItem> files;        // �ļ��б�
    bool isLoaded = false;              // �Ƿ��Ѽ���
};

class FileManager {
public:
    FileManager();
    ~FileManager();

    // ���Ĺ���
    bool LoadDrives();                                          // �����������б�
    bool LoadDirectory(const std::string& path);                // ����ָ��Ŀ¼
    bool RefreshDirectory(const std::string& path);             // ˢ��Ŀ¼

    // ���ݻ�ȡ
    std::vector<std::string> GetDriveList() const;              // ��ȡ�������б�
    std::vector<FileItem> GetFiles(const std::string& path);    // ��ȡ�ļ��б�
    std::vector<DirectoryNode> GetSubDirectories(const std::string& path); // ��ȡ��Ŀ¼

    // �ļ�����
    bool MyDeleteFile(const std::string& filePath);             // ɾ���ļ�
    bool MyCopyFile(const std::string& src, const std::string& dst); // �����ļ�
    bool MyMoveFile(const std::string& src, const std::string& dst); // �ƶ��ļ�

    // ���ߺ���
    std::string FormatFileSize(LARGE_INTEGER size);             // ��ʽ���ļ���С
    std::string FormatFileTime(FILETIME time);                  // ��ʽ��ʱ��
    std::string GetFileTypeFromExtension(const std::string& fileName); // ��ȡ�ļ�����

private:
    std::map<std::string, DirectoryNode> directoryCache_;       // Ŀ¼����
    std::vector<std::string> driveList_;                        // �������б�

    bool EnumDirectory(const std::string& path, DirectoryNode& node);
    bool IsValidPath(const std::string& path);
    
    // �ڲ�ת������
    static std::string WStringToUTF8(const std::wstring& wstr);
    static std::wstring UTF8ToWString(const std::string& str);
};