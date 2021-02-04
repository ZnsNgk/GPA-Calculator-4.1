// Money.cpp: 实现文件
//

#include "stdafx.h"
#include "平均绩点计算器.h"
#include "Money.h"
#include "afxdialogex.h"


// Money 对话框

IMPLEMENT_DYNAMIC(Money, CDialog)

Money::Money(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Money, pParent)
{

}

Money::~Money()
{
}

void Money::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Money, CDialog)
END_MESSAGE_MAP()


// Money 消息处理程序
