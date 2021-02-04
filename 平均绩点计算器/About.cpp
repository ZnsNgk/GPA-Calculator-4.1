// About.cpp: 实现文件
//

#include "stdafx.h"
#include "平均绩点计算器.h"
#include "About.h"
#include "afxdialogex.h"


// About 对话框

IMPLEMENT_DYNAMIC(About, CDialog)

About::About(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ABOUTBOX, pParent)
{
}

About::~About()
{
}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(About, CDialog)
END_MESSAGE_MAP()


// About 消息处理程序
