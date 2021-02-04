#pragma once


// Money 对话框

class Money : public CDialog
{
	DECLARE_DYNAMIC(Money)

public:
	Money(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Money();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Money };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
