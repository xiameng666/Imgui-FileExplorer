#pragma once
#include "Interface.h"
#include "FileManager.h"

class FileWnd : public ImguiWnd {
public:
    explicit FileWnd(Context* ctx);
    void Render(bool* p_open = nullptr) override;

private:
    FileManager fileManager_;

    std::string currentPath_ = "C:\\";                     // ��ǰ·��
    std::vector<FileItem> currentFiles_;                   // ��ǰ�ļ��б�
    std::vector<DirectoryNode> currentDirs_;               // ��ǰĿ¼�б�
    int selectedFileIndex_ = -1;                           // ѡ���ļ�����
    char fileSearchFilter_[256] = "";                      // �ļ�����������

    void RenderDirectoryTree();                            // ��ȾĿ¼��
    void RenderDirectoryNode(const std::string& path);     // ��ȾĿ¼�ڵ�
    void RenderFileList();                                 // ��Ⱦ�ļ��б�
    
    void ChangeDirectory(const std::string& newPath);      // �л�Ŀ¼
    void FlushCurrentDirectory();                          // ˢ�µ�ǰĿ¼
    void NavigateUp();                                     // �����ϼ�Ŀ¼
};