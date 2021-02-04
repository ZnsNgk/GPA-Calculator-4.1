// InDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "平均绩点计算器.h"
#include "InDlg.h"
#include "afxdialogex.h"


// InDlg 对话框

IMPLEMENT_DYNAMIC(InDlg, CDialog)

LPWSTR pFilePath;

InDlg::InDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_In, pParent)
{
}

InDlg::~InDlg()
{
}

void InDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &InDlg::OnBnClickedButton1)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// InDlg 消息处理程序


void InDlg::OnBnClickedButton1()
{
	OnCancel();
}




void InDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR pFilePath[MAX_PATH];
	DragQueryFile(hDropInfo, 0, pFilePath, MAX_PATH);// 获取拖放第一个文件的完整路径
	CString str = pFilePath;
	CWnd *pWnd = AfxGetMainWnd();
	::SendMessage(*pWnd, WM_GETMsg, (WPARAM)&str, NULL);
	OnOK();
}
