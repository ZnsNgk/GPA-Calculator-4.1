#pragma once


// InDlg 对话框

class InDlg : public CDialog
{
	DECLARE_DYNAMIC(InDlg)

public:
	InDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_In };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
