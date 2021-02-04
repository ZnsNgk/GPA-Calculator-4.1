
// 平均绩点计算器Dlg.h : 头文件
//

#pragma once

// C平均绩点计算器Dlg 对话框
class C平均绩点计算器Dlg : public CDialogEx
{
// 构造
public:
	C平均绩点计算器Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
	afx_msg LRESULT OnGetmsg(WPARAM wParam, LPARAM lParam);
public:
	int m_num;
	CString m_name;
	float m_credit;
	int m_point;
	bool m_ins;
	int m_level;
	short error=0;
	CString GPA;
	double m_GPA;
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedMore();
	afx_msg void OnBnClickedPriv();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedAc();
	afx_msg void OnBnClickedAllac();
	afx_msg void OnBnClickedInput();
	afx_msg void OnBnClickedOutput();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedPredict();
	afx_msg void OnBnClickedPointIns();
	afx_msg void OnBnClickedLevelIns();
	afx_msg void OnBnClickedA();
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedF();
	afx_msg void OnBnClickedFirst();
	afx_msg void OnBnClickedLast();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedButton9();
};

