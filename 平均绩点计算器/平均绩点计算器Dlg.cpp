
// 平均绩点计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "平均绩点计算器.h"
#include "平均绩点计算器Dlg.h"
#include "afxdialogex.h"
#include "PreditDlg.h"
#include "InDlg.h"
#include "About.h"
#include "Money.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
struct Node
{
	CString name;
	bool ins;
	float credit;
	int point;
	double GPA;
};

Node List[150];

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_UseList;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// C平均绩点计算器Dlg 对话框



C平均绩点计算器Dlg::C平均绩点计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_num(1)
	, m_name(_T(""))
	, m_credit(0)
	, m_point(0)
	, m_ins(true)
	, m_GPA(0)
	, GPA(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C平均绩点计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Num, m_num);
	DDX_Text(pDX, IDC_Name, m_name);
	DDX_Text(pDX, IDC_Credit, m_credit);
	DDX_Text(pDX, IDC_Point, m_point);
	DDX_Text(pDX, IDC_Point, m_point);
	DDX_Text(pDX, IDC_GPA, GPA);
}

BEGIN_MESSAGE_MAP(C平均绩点计算器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Exit, &C平均绩点计算器Dlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_Back, &C平均绩点计算器Dlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_More, &C平均绩点计算器Dlg::OnBnClickedMore)
	ON_BN_CLICKED(IDC_Priv, &C平均绩点计算器Dlg::OnBnClickedPriv)
	ON_BN_CLICKED(IDC_Next, &C平均绩点计算器Dlg::OnBnClickedNext)
	ON_BN_CLICKED(IDC_Ac, &C平均绩点计算器Dlg::OnBnClickedAc)
	ON_BN_CLICKED(IDC_AllAc, &C平均绩点计算器Dlg::OnBnClickedAllac)
	ON_BN_CLICKED(IDC_Input, &C平均绩点计算器Dlg::OnBnClickedInput)
	ON_BN_CLICKED(IDC_Output, &C平均绩点计算器Dlg::OnBnClickedOutput)
	ON_BN_CLICKED(IDC_Start, &C平均绩点计算器Dlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_Predict, &C平均绩点计算器Dlg::OnBnClickedPredict)
	ON_BN_CLICKED(IDC_Point_Ins, &C平均绩点计算器Dlg::OnBnClickedPointIns)
	ON_BN_CLICKED(IDC_Level_Ins, &C平均绩点计算器Dlg::OnBnClickedLevelIns)
	ON_BN_CLICKED(IDC_A, &C平均绩点计算器Dlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_B, &C平均绩点计算器Dlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_C, &C平均绩点计算器Dlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_D, &C平均绩点计算器Dlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_F, &C平均绩点计算器Dlg::OnBnClickedF)
	ON_MESSAGE(WM_GETMsg, OnGetmsg)
	ON_BN_CLICKED(IDC_FIRST, &C平均绩点计算器Dlg::OnBnClickedFirst)
	ON_BN_CLICKED(IDC_LAST, &C平均绩点计算器Dlg::OnBnClickedLast)
	ON_BN_CLICKED(IDC_About, &C平均绩点计算器Dlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_BUTTON9, &C平均绩点计算器Dlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// C平均绩点计算器Dlg 消息处理程序

BOOL C平均绩点计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CButton *PI = (CButton*)GetDlgItem(IDC_Point_Ins);
	PI->SetCheck(true);
	CWnd *GroupI = GetDlgItem(IDC_Point);
	CWnd *a_A = GetDlgItem(IDC_A);
	CWnd *a_B = GetDlgItem(IDC_B);
	CWnd *a_C = GetDlgItem(IDC_C);
	CWnd *a_D = GetDlgItem(IDC_D);
	CWnd *a_F = GetDlgItem(IDC_F);
	GroupI->EnableWindow(true);
	a_A->EnableWindow(false);
	a_B->EnableWindow(false);
	a_C->EnableWindow(false);
	a_D->EnableWindow(false);
	a_F->EnableWindow(false);
	for (int i = 1; i < 150; i++)
	{
		List[i].ins = true;
	}
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C平均绩点计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C平均绩点计算器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C平均绩点计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C平均绩点计算器Dlg::OnBnClickedExit()
{
	OnCancel();
}


void C平均绩点计算器Dlg::OnBnClickedBack()
{
	CEdit *input = (CEdit*)GetDlgItem(IDC_Input);
	CEdit *back = (CEdit*)GetDlgItem(IDC_Back);
	CEdit *more = (CEdit*)GetDlgItem(IDC_More);
	CEdit *start = (CEdit*)GetDlgItem(IDC_Start);
	CEdit *predict = (CEdit*)GetDlgItem(IDC_Predict);
	CEdit *output = (CEdit*)GetDlgItem(IDC_Output);
	CEdit *first = (CEdit*)GetDlgItem(IDC_FIRST);
	CEdit *last = (CEdit*)GetDlgItem(IDC_LAST);
	CEdit *next = (CEdit*)GetDlgItem(IDC_Next);
	CEdit *priv = (CEdit*)GetDlgItem(IDC_Priv);
	CEdit* Abo = (CEdit*)GetDlgItem(IDC_About);
	CEdit* money = (CEdit*)GetDlgItem(IDC_BUTTON9);
	CEdit* ac = (CEdit*)GetDlgItem(IDC_Ac);
	CEdit* allac = (CEdit*)GetDlgItem(IDC_AllAc);
	input->ShowWindow(true);
	back->ShowWindow(false);
	more->ShowWindow(true);
	start->ShowWindow(true);
	predict->ShowWindow(false);
	output->ShowWindow(false);
	first->ShowWindow(false);
	last->ShowWindow(false);
	next->ShowWindow(true);
	priv->ShowWindow(true);
	Abo->ShowWindow(false);
	money->ShowWindow(false);
	ac->ShowWindow(true);
	allac->ShowWindow(true);
}


void C平均绩点计算器Dlg::OnBnClickedMore()
{
	CEdit *input = (CEdit*)GetDlgItem(IDC_Input);
	CEdit *back = (CEdit*)GetDlgItem(IDC_Back);
	CEdit *more = (CEdit*)GetDlgItem(IDC_More);
	CEdit *start = (CEdit*)GetDlgItem(IDC_Start);
	CEdit *predict = (CEdit*)GetDlgItem(IDC_Predict);
	CEdit *output = (CEdit*)GetDlgItem(IDC_Output);
	CEdit *first = (CEdit*)GetDlgItem(IDC_FIRST);
	CEdit *last = (CEdit*)GetDlgItem(IDC_LAST);
	CEdit *next = (CEdit*)GetDlgItem(IDC_Next);
	CEdit *priv = (CEdit*)GetDlgItem(IDC_Priv);
	CEdit *Abo = (CEdit*)GetDlgItem(IDC_About);
	CEdit *money = (CEdit*)GetDlgItem(IDC_BUTTON9);
	CEdit* ac = (CEdit*)GetDlgItem(IDC_Ac);
	CEdit* allac = (CEdit*)GetDlgItem(IDC_AllAc);
	input->ShowWindow(false);
	back->ShowWindow(true);
	more->ShowWindow(false);
	start->ShowWindow(false);
	predict->ShowWindow(true);
	output->ShowWindow(true);
	first->ShowWindow(true);
	last->ShowWindow(true);
	next->ShowWindow(false);
	priv->ShowWindow(false);
	Abo->ShowWindow(true);
	money->ShowWindow(true);
	ac->ShowWindow(false);
	allac->ShowWindow(false);
}


void C平均绩点计算器Dlg::OnBnClickedPriv()
{
	if (m_num == 1) {
		MessageBox(_T("已经是第一门了！"),_T("注意"), MB_ICONINFORMATION|MB_OK);
		error = 1;
		return;
	}
	CButton *A = (CButton*)GetDlgItem(IDC_A);
	CButton *B = (CButton*)GetDlgItem(IDC_B);
	CButton *C = (CButton*)GetDlgItem(IDC_C);
	CButton *D = (CButton*)GetDlgItem(IDC_D);
	CButton *F = (CButton*)GetDlgItem(IDC_F);
	CButton *PI = (CButton*)GetDlgItem(IDC_Point_Ins);
	CButton *LI = (CButton*)GetDlgItem(IDC_Level_Ins);
	UpdateData(TRUE);
	m_num--;
	m_name = List[m_num].name;
	m_credit = List[m_num].credit;
	m_ins = List[m_num].ins;
	if (m_ins == true)
	{
		List[m_num].ins = m_ins;
		CWnd *GroupI = GetDlgItem(IDC_Point);
		CWnd *a_A = GetDlgItem(IDC_A);
		CWnd *a_B = GetDlgItem(IDC_B);
		CWnd *a_C = GetDlgItem(IDC_C);
		CWnd *a_D = GetDlgItem(IDC_D);
		CWnd *a_F = GetDlgItem(IDC_F);
		GroupI->EnableWindow(true);
		a_A->EnableWindow(false);
		a_B->EnableWindow(false);
		a_C->EnableWindow(false);
		a_D->EnableWindow(false);
		a_F->EnableWindow(false);
		PI->SetCheck(true);
		LI->SetCheck(false);
		m_point = List[m_num].point;
		A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false);
	}
	else
	{
		CWnd *GroupI = GetDlgItem(IDC_Point);
		CWnd *a_A = GetDlgItem(IDC_A);
		CWnd *a_B = GetDlgItem(IDC_B);
		CWnd *a_C = GetDlgItem(IDC_C);
		CWnd *a_D = GetDlgItem(IDC_D);
		CWnd *a_F = GetDlgItem(IDC_F);
		GroupI->EnableWindow(false);
		a_A->EnableWindow(true);
		a_B->EnableWindow(true);
		a_C->EnableWindow(true);
		a_D->EnableWindow(true);
		a_F->EnableWindow(true);
		PI->SetCheck(false);
		LI->SetCheck(true);
		switch (List[m_num].point)
		{
		case 95:A->SetCheck(true); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false); break;
		case 85:A->SetCheck(false); B->SetCheck(true); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false); break;
		case 75:A->SetCheck(false); B->SetCheck(false); C->SetCheck(true); D->SetCheck(false); F->SetCheck(false); break;
		case 65:A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(true); F->SetCheck(false); break;
		case 0:A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(true); break;
		}
		m_point = NULL;
	}
	UpdateData(FALSE);
	error = 0;
}


void C平均绩点计算器Dlg::OnBnClickedNext()
{
	CButton *A = (CButton*)GetDlgItem(IDC_A);
	CButton *B = (CButton*)GetDlgItem(IDC_B);
	CButton *C = (CButton*)GetDlgItem(IDC_C);
	CButton *D = (CButton*)GetDlgItem(IDC_D);
	CButton *F = (CButton*)GetDlgItem(IDC_F);
	CButton *PI = (CButton*)GetDlgItem(IDC_Point_Ins);
	CButton *LI = (CButton*)GetDlgItem(IDC_Level_Ins);
	UpdateData(TRUE);
	if (m_ins == true &&( m_point > 100 || m_point < 0))
	{
		MessageBox(_T("你的成绩似乎出了点问题"), _T("注意"), MB_ICONINFORMATION | MB_OK);
		error = 2;
		return;
	}
	if (m_credit <= 0)
	{
		MessageBox(_T("你的学分似乎出了点问题"), _T("注意"), MB_ICONINFORMATION | MB_OK);
		error = 3;
		return;
	}
	if (m_ins == false && (A->GetCheck()==B->GetCheck() == C->GetCheck() == D->GetCheck() == F->GetCheck() == false))
	{
		MessageBox(_T("你没写等第"), _T("注意"), MB_ICONINFORMATION | MB_OK);
		error = 4;
		return;
	}
	List[m_num].name = m_name;
	List[m_num].ins = m_ins;
	List[m_num].credit = m_credit;
	List[m_num].ins = m_ins;
	if (m_ins == false) 
	{
		switch (m_level)
		{
		case 1:List[m_num].point = 95; break;
		case 2:List[m_num].point = 85; break;
		case 3:List[m_num].point = 75; break;
		case 4:List[m_num].point = 65; break;
		case 5:List[m_num].point = 0; break;
		}
	}
	else
	{
		List[m_num].point = m_point;
	}
	m_num++;
	m_name = List[m_num].name;
	m_credit = List[m_num].credit;
	m_ins = List[m_num].ins;
	if (m_ins == true)
	{
		CWnd *GroupI = GetDlgItem(IDC_Point);
		CWnd *a_A = GetDlgItem(IDC_A);
		CWnd *a_B = GetDlgItem(IDC_B);
		CWnd *a_C = GetDlgItem(IDC_C);
		CWnd *a_D = GetDlgItem(IDC_D);
		CWnd *a_F = GetDlgItem(IDC_F);
		GroupI->EnableWindow(true);
		a_A->EnableWindow(false);
		a_B->EnableWindow(false);
		a_C->EnableWindow(false);
		a_D->EnableWindow(false);
		a_F->EnableWindow(false);
		PI->SetCheck(true);
		LI->SetCheck(false);
		m_point = List[m_num].point;
		A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false);
	}
	else
	{
		CWnd *GroupI = GetDlgItem(IDC_Point);
		CWnd *a_A = GetDlgItem(IDC_A);
		CWnd *a_B = GetDlgItem(IDC_B);
		CWnd *a_C = GetDlgItem(IDC_C);
		CWnd *a_D = GetDlgItem(IDC_D);
		CWnd *a_F = GetDlgItem(IDC_F);
		GroupI->EnableWindow(false);
		a_A->EnableWindow(true);
		a_B->EnableWindow(true);
		a_C->EnableWindow(true);
		a_D->EnableWindow(true);
		a_F->EnableWindow(true);
		PI->SetCheck(false);
		LI->SetCheck(true);
		switch (List[m_num].point)
		{
		case 95:A->SetCheck(true); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false); break;
		case 85:A->SetCheck(false); B->SetCheck(true); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false); break;
		case 75:A->SetCheck(false); B->SetCheck(false); C->SetCheck(true); D->SetCheck(false); F->SetCheck(false); break;
		case 65:A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(true); F->SetCheck(false); break;
		case 0:A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(true); break;
		}
		m_point = NULL;
	}
	UpdateData(FALSE);
	error = 0;
}


void C平均绩点计算器Dlg::OnBnClickedAc()
{
	UpdateData(TRUE);
	m_name = _T("");
	m_ins = true;
	CButton *A = (CButton*)GetDlgItem(IDC_A);
	CButton *B = (CButton*)GetDlgItem(IDC_B);
	CButton *C = (CButton*)GetDlgItem(IDC_C);
	CButton *D = (CButton*)GetDlgItem(IDC_D);
	CButton *F = (CButton*)GetDlgItem(IDC_F);
	CButton *PI = (CButton*)GetDlgItem(IDC_Point_Ins);
	CButton *LI = (CButton*)GetDlgItem(IDC_Level_Ins);
	CWnd *GroupI = GetDlgItem(IDC_Point);
	CWnd *a_A = GetDlgItem(IDC_A);
	CWnd *a_B = GetDlgItem(IDC_B);
	CWnd *a_C = GetDlgItem(IDC_C);
	CWnd *a_D = GetDlgItem(IDC_D);
	CWnd *a_F = GetDlgItem(IDC_F);
	GroupI->EnableWindow(true);
	a_A->EnableWindow(false);
	a_B->EnableWindow(false);
	a_C->EnableWindow(false);
	a_D->EnableWindow(false);
	a_F->EnableWindow(false);
	m_credit = 0;
	m_point = 0;
	List[m_num].credit = 0;
	List[m_num].GPA = 0;
	List[m_num].ins = 1;
	List[m_num].name = _T("");
	List[m_num].point = 0;
	A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false);
	PI->SetCheck(true);
	LI->SetCheck(false);
	UpdateData(FALSE);
}


void C平均绩点计算器Dlg::OnBnClickedAllac()
{
	if (MessageBox(_T("是否清除所有成绩？该过程不可逆转！"), _T("警告"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDOK)
	{
		if (MessageBox(_T("你再考虑一下呢？"), _T("再次警告"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDOK)
		{
			for (int i = 1; i < 150; i++)
			{
				List[i].name = _T("");
				List[i].ins = true;
				List[i].credit = 0;
				List[i].point = 0;
			}
			UpdateData(TRUE);
			m_num = 1;
			m_ins = true;
			m_point = 0;
			m_credit = 0;
			m_name = _T("");
			CWnd *GroupI = GetDlgItem(IDC_Point);
			CWnd *a_A = GetDlgItem(IDC_A);
			CWnd *a_B = GetDlgItem(IDC_B);
			CWnd *a_C = GetDlgItem(IDC_C);
			CWnd *a_D = GetDlgItem(IDC_D);
			CWnd *a_F = GetDlgItem(IDC_F);
			CButton *A = (CButton*)GetDlgItem(IDC_A);
			CButton *B = (CButton*)GetDlgItem(IDC_B);
			CButton *C = (CButton*)GetDlgItem(IDC_C);
			CButton *D = (CButton*)GetDlgItem(IDC_D);
			CButton *F = (CButton*)GetDlgItem(IDC_F);
			CButton *PI = (CButton*)GetDlgItem(IDC_Point_Ins);
			CButton *LI = (CButton*)GetDlgItem(IDC_Level_Ins);
			GroupI->EnableWindow(true);
			a_A->EnableWindow(false);
			a_B->EnableWindow(false);
			a_C->EnableWindow(false);
			a_D->EnableWindow(false);
			a_F->EnableWindow(false);
			A->SetCheck(false); B->SetCheck(false); C->SetCheck(false); D->SetCheck(false); F->SetCheck(false);
			PI->SetCheck(true);
			LI->SetCheck(false);
			UpdateData(FALSE);
		}
	}
}


void C平均绩点计算器Dlg::OnBnClickedInput()
{
	InDlg  *In = new InDlg;
	In->Create(IDD_In, this);
	In->ShowWindow(SW_SHOW);
}

void C平均绩点计算器Dlg::OnBnClickedOutput()
{
	if (MessageBox(_T("为保证导出的完整性，请将最后一门课程置为当前课程"), _T("注意"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}
	UpdateData(TRUE);
	C平均绩点计算器Dlg::OnBnClickedStart();
	if (error >= 1)
	{
		return;
	}
	ofstream fout("Output.xls", ios::out);
	fout << "序号"<<'\t'<< "名称" << '\t' << "学分" << '\t' << "成绩" << '\t' << "该门绩点" <<endl;
	for (int i = 1; i < m_num + 1; i++)
	{
		USES_CONVERSION;
		string s(W2A(List[i].name));
		const char* tem = s.c_str();
		fout << i << '\t';
		fout << tem << '\t';
		fout << List[i].credit << '\t';
		if (List[i].ins == true)
		{
			fout << List[i].point << '\t';
		}
		else
		{
			switch (List[i].point)
			{
			case 95:fout << "优秀" << '\t'; break;
			case 85:fout << "良好" << '\t'; break;
			case 75:fout << "中等" << '\t'; break;
			case 65:fout << "及格" << '\t'; break;
			case 0:fout << "不及格" << '\t'; break;
			}
		}
		fout << List[i].GPA / List[i].credit << endl;
	}
	fout << endl << '\t' << "你的平均绩点为\t\t\t" << m_GPA;
	fout.close();
	UpdateData(FALSE);
	MessageBox(_T("导出成功！"));
}


void C平均绩点计算器Dlg::OnBnClickedStart()
{
	C平均绩点计算器Dlg::OnBnClickedNext();
	if (error > 1)
		return;
	C平均绩点计算器Dlg::OnBnClickedPriv();
	if (error == 1)
		return;
	CString str2;
	str2.Format(_T("%d"), m_num);
	CString str1 = _T("即将开始计算第1门到第") + str2 + _T("门的平均绩点！");
	MessageBox(str1);
	double tmp1 = 0; 
	double tmp2 = 0;
	UpdateData(TRUE);
	for (int i = 1; i < m_num + 1; i++)
	{
		if (List[i].point > 95)
			List[i].GPA = 48;
		else if (List[i].point < 60)
			List[i].GPA = 0;
		else
			List[i].GPA = (List[i].point - 48);
		List[i].GPA = List[i].GPA * List[i].credit / 10;
		tmp1 = tmp1 + List[i].GPA;
		tmp2 = tmp2 + List[i].credit;
	}
	m_GPA = round((tmp1 / tmp2)*100.0f) / 100.0f;
	GPA.Format(_T("%.2lf"), m_GPA);
	UpdateData(FALSE);
	error = 0;
}


void C平均绩点计算器Dlg::OnBnClickedPredict()
{
	if (MessageBox(_T("为保证预测的正确性，请将最后一门课程置为当前课程"), _T("注意"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}
	UpdateData(TRUE);
	C平均绩点计算器Dlg::OnBnClickedStart();
	if (error >= 1)
	{
		return;
	}
	PreditDlg *Pre = new PreditDlg;
	Pre->Create(IDD_PRE, this);
	Pre->ShowWindow(SW_SHOW);
	::SendMessage(Pre->m_hWnd, WM_GETLIST, (WPARAM)&m_num , (LPARAM)&List);
	UpdateData(FALSE);
}


void C平均绩点计算器Dlg::OnBnClickedPointIns()
{
	m_ins = true;
	CWnd *GroupI = GetDlgItem(IDC_Point);
	CWnd *a_A = GetDlgItem(IDC_A);
	CWnd *a_B = GetDlgItem(IDC_B);
	CWnd *a_C = GetDlgItem(IDC_C);
	CWnd *a_D = GetDlgItem(IDC_D);
	CWnd *a_F = GetDlgItem(IDC_F);
	GroupI->EnableWindow(true);
	a_A->EnableWindow(false);
	a_B->EnableWindow(false);
	a_C->EnableWindow(false);
	a_D->EnableWindow(false);
	a_F->EnableWindow(false);
}


void C平均绩点计算器Dlg::OnBnClickedLevelIns()
{
	m_ins = false;
	CWnd *GroupI = GetDlgItem(IDC_Point);
	CWnd *a_A = GetDlgItem(IDC_A);
	CWnd *a_B = GetDlgItem(IDC_B);
	CWnd *a_C = GetDlgItem(IDC_C);
	CWnd *a_D = GetDlgItem(IDC_D);
	CWnd *a_F = GetDlgItem(IDC_F);
	GroupI->EnableWindow(false);
	a_A->EnableWindow(true);
	a_B->EnableWindow(true);
	a_C->EnableWindow(true);
	a_D->EnableWindow(true);
	a_F->EnableWindow(true);
}


void C平均绩点计算器Dlg::OnBnClickedA()
{
	m_level = 1;
}


void C平均绩点计算器Dlg::OnBnClickedB()
{
	m_level = 2;
}


void C平均绩点计算器Dlg::OnBnClickedC()
{
	m_level = 3;
}


void C平均绩点计算器Dlg::OnBnClickedD()
{
	m_level = 4;
}


void C平均绩点计算器Dlg::OnBnClickedF()
{
	m_level = 5;
}

string UTF8ToGB(const char* str)

{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
	result = szRes;
	delete[]strSrc;
	delete[]szRes;
	return result;
}

LRESULT C平均绩点计算器Dlg::OnGetmsg(WPARAM wParam, LPARAM lParam)
{
	CString *s = (CString*)wParam;
	CString str = *s;
	int n = str.Find(_T(".xls"));
	int t = str.Find(_T(".xlsx"));
	int p = str.Find(_T(".csv"));
	if (n == -1 && p == -1)
	{
		MessageBox(_T("请放入一个Excel文件！"), _T("这不是Excel文件"), MB_ICONEXCLAMATION | MB_OKCANCEL);
		return 0;
	}
	if (t != -1)
	{
		MessageBox(_T("本软件暂不支持Excel 2007及更新版本的文件，你可以在Excel中选择另存为.xls或.csv文件后导入"), _T("十分抱歉"), MB_ICONEXCLAMATION | MB_OKCANCEL);
		return 0;
	}
	ifstream fin(str, ios::in);
	char tmp[1024] = { 0 };
	string strtmp;
	fin.getline(tmp, sizeof(tmp));
	strtmp = tmp;
	if (strtmp.find("xml") != -1)
	{
		if (strtmp.find("UTF-8") != -1)
		{
			while (fin.getline((tmp), sizeof(tmp)))
			{

				strtmp += UTF8ToGB(tmp);
			}
		}
		else
		{
			while (fin.getline((tmp), sizeof(tmp)))
			{
				strtmp += tmp;
			}
		}
		string search[3] = { "名称","学分","成绩" };
		for (int i = 0; i < 3; i++)
		{
			string tmp1, tmp2;
			int tem1, tem2;
			if (i == 2)
			{
				tem1 = strtmp.find(search[i]);
				tem1 = strtmp.find(search[i], tem1 + 1);
			}
			else
			{
				tem1 = strtmp.find(search[i]);
			}
			tem2 = strtmp.find("Cell ss:Index=\"", tem1 - 100);
			if (strtmp[tem2 + 16] != '\"')
			{
				tmp1 = strtmp[tem2 + 15];
				tmp1 += strtmp[tem2 + 16];
			}
			else
			{
				tmp1 = strtmp[tem2 + 15];
			}
			tmp2 = "Cell ss:Index=\"" + tmp1 + "\"";
			int num = 0;
			int flag = -1;
			while (1)
			{
				flag = strtmp.find(tmp2, flag + 1);
				if (flag == -1)
					break;
				int begin, end;
				if (i == 1)
				{
					begin = strtmp.find("\"Number\">", flag);
				}
				else
				{
					begin = strtmp.find("\"String\">", flag);
				}
				end = strtmp.find("</Data>", flag);
				string a;
				a = strtmp.substr(begin + 9, end - begin - 9);
				switch (i)
				{
				case 0:
				{
					CString Ca(a.c_str());
					List[num].name = Ca;
					break;
				}
				case 1:
				{
					float f = atof(a.c_str());
					List[num].credit = f;
					break;
				}
				case 2:
				{
					if (a.compare("优秀") == 0)
					{
						List[num].ins = false;
						List[num].point = 95;
					}
					else if (a.compare("良好") == 0)
					{
						List[num].ins = false;
						List[num].point = 85;
					}
					else if (a.compare("中等") == 0)
					{
						List[num].ins = false;
						List[num].point = 75;
					}
					else if (a.compare("及格") == 0 || a.compare("合格") == 0)
					{
						List[num].ins = false;
						List[num].point = 65;
					}
					else if (a.compare("不及格") == 0 || a.compare("不合格") == 0)
					{
						List[num].ins = false;
						List[num].point = 0;
					}
					else
					{
						List[num].ins = true;
						int point_t = atoi(a.c_str());
						List[num].point = point_t;
					}
					break;
				}
				}
				num++;
				flag++;
			}
			UpdateData(TRUE);
			m_num = num;
			UpdateData(FALSE);

		}

	}
	else
	{
		string name, credit, point;
		int nb, ne, pb, pe, cb, ce;
		int nf = 0;
		int pf = 0;
		int cf = 0;
		nb = strtmp.find("名称");
		if (nb == -1)
			nb = strtmp.find("科目");
		cb = strtmp.find("学分");
		pb = strtmp.find("成绩");
		if (pb == -1)
			pb = strtmp.find("分数");
		if (pb != -1 && cb != -1)
		{
			for (int i = 0; i < nb; i++)
			{
				if (strtmp[i] == 44)
					nf++;
				else if (strtmp[i] == 9)
					nf++;
			}
			for (int i = 0; i < cb; i++)
			{
				if (strtmp[i] == 44)
					cf++;
				else if (strtmp[i] == 9)
					cf++;
			}
			for (int i = 0; i < pb; i++)
			{
				if (strtmp[i] == 44)
					pf++;
				else if (strtmp[i] == 9)
					pf++;
			}
		}
		int flag = 1;
		while (fin.getline(tmp, sizeof(tmp)))
		{
			strtmp = tmp;
			if (strtmp.length() == 0)
			{
				break;
			}
			if (flag > 1 && strtmp.find(",,,,,,,") != -1)
			{
				break;
			}
			if ((flag > 1 && strtmp.find("\t\t\t") != -1))
			{
				break;
			}
			if (pb == -1 && cb == -1)
			{
				nb = strtmp.find("名称");
				if (nb == -1)
					nb = strtmp.find("科目");
				cb = strtmp.find("学分");
				pb = strtmp.find("成绩");
				if (pb != -1 && cb != -1)
				{
					if (nb != -1)
					{
						for (int i = 0; i < nb; i++)
						{
							if (strtmp[i] == 44)
								nf++;
							else if (strtmp[i] == 9)
								nf++;
						}
					}
					for (int i = 0; i < cb; i++)
					{
						if (strtmp[i] == 44)
							cf++;
						else if (strtmp[i] == 9)
							cf++;
					}
					for (int i = 0; i < pb; i++)
					{
						if (strtmp[i] == 44)
							pf++;
						else if (strtmp[i] == 9)
							pf++;
					}
				}
			}
			else
			{
				int nft = 0;
				int cft = 0;
				int pft = 0;
				int nbt = 0, cbt = 0, pbt = 0;
				if (nb != -1)
				{
					while (nft != nf)
					{
						if (strtmp[nbt] == 44)
						{
							nft++;
						}
						else if (strtmp[nbt] == 9)
						{
							nft++;
						}
						nbt++;
						if (nbt == strtmp.length())
						{
							CString err;
							err.Format(_T("%d"), flag + 1);
							err = err + _T("行");
							MessageBox(_T("数据导入错误，错误在第") + err, _T("警告"), MB_ICONEXCLAMATION | MB_OK);
							fin.clear();
							fin.close();
							return 0;
						}
					}
					ne = nbt + 1;
					while (strtmp[ne] != 44 && strtmp[ne] != 9)
					{
						if (ne == strtmp.length())
						{
							ne = strtmp.length();
							break;
						}
						ne++;
					}
					name = strtmp.substr(nbt, ne - nbt);
					CString namet(name.c_str());
					List[flag].name = namet;
				}
				while (cft != cf)
				{
					if (strtmp[cbt] == 44)
					{
						cft++;
					}
					else if (strtmp[cbt] == 9)
					{
						cft++;
					}
					cbt++;
					if (cbt == strtmp.length())
					{
						CString err;
						err.Format(_T("%d"), flag + 1);
						err = err + _T("行");
						MessageBox(_T("数据导入错误，错误在第") + err, _T("警告"), MB_ICONEXCLAMATION | MB_OK);
						fin.clear();
						fin.close();
						return 0;
					}
				}
				while (pft != pf)
				{
					if (strtmp[pbt] == 44)
					{
						pft++;
					}
					else if (strtmp[pbt] == 9)
					{
						pft++;
					}
					pbt++;
					if (pbt == strtmp.length())
					{
						CString err;
						err.Format(_T("%d"), flag + 1);
						err = err + _T("行");
						MessageBox(_T("数据导入错误，错误在第") + err, _T("警告"), MB_ICONEXCLAMATION | MB_OK);
						fin.clear();
						fin.close();
						return 0;
					}
				}
				pe = pbt + 1;
				while (strtmp[pe] != 44 && strtmp[pe] != 9)
				{
					if (pe == strtmp.length())
					{
						pe = strtmp.length();
						break;
					}
					pe++;
				}
				point = strtmp.substr(pbt, pe - pbt);
				if (point.compare("优秀") == 0)
				{
					List[flag].ins = false;
					List[flag].point = 95;
				}
				else if (point.compare("良好") == 0)
				{
					List[flag].ins = false;
					List[flag].point = 85;
				}
				else if (point.compare("中等") == 0)
				{
					List[flag].ins = false;
					List[flag].point = 75;
				}
				else if (point.compare("及格") == 0 || point.compare("合格") == 0)
				{
					List[flag].ins = false;
					List[flag].point = 65;
				}
				else if (point.compare("不及格") == 0 || point.compare("不合格") == 0)
				{
					List[flag].ins = false;
					List[flag].point = 0;
				}
				else
				{
					List[flag].ins = true;
					int point_t = atoi(point.c_str());
					List[flag].point = point_t;
				}
				ce = cbt + 1;
				while (strtmp[ce] != 44 && strtmp[ce] != 9)
				{
					if (ce == strtmp.length())
					{
						ce = strtmp.length();
						break;
					}
					ce++;
				}
				credit = strtmp.substr(cbt, ce - cbt);
				float credit_t = atof(credit.c_str());
				List[flag].credit = credit_t;
				flag++;
			}
		}
		UpdateData(TRUE);
		m_num = flag;
		UpdateData(FALSE);
		if (nb == -1 && cb == -1)
		{
			MessageBox(_T("导入失败，请检查你的文件格式或者另存为.csv文件！"), _T("错误"), MB_ICONEXCLAMATION | MB_OK);
			fin.clear();
			fin.close();
			return 0;
		}
	}
	C平均绩点计算器Dlg::OnBnClickedPriv();
	MessageBox(_T("导入成功！"));
	fin.clear();
	fin.close();
	return 0;
}


void C平均绩点计算器Dlg::OnBnClickedFirst()
{
	while (m_num != 1)
	{
		OnBnClickedPriv();
	}
}


void C平均绩点计算器Dlg::OnBnClickedLast()
{
	while (List[m_num].credit != 0)
	{
		OnBnClickedNext();
	}
	C平均绩点计算器Dlg::OnBnClickedPriv();
}


void C平均绩点计算器Dlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	About* Abo = new About;
	Abo->Create(IDD_ABOUTBOX, this);
	Abo->ShowWindow(SW_SHOW);
}


void C平均绩点计算器Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	Money* Mo = new Money;
	Mo->Create(IDD_Money, this);
	Mo->ShowWindow(SW_SHOW);
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
