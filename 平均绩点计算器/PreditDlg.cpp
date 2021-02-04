// PreditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "平均绩点计算器.h"
#include "平均绩点计算器Dlg.h"
#include "PreditDlg.h"
#include "afxdialogex.h"

struct Node
{
	CString name;
	bool ins;
	float credit;
	int point;
	double GPA;
};
// PreditDlg 对话框

IMPLEMENT_DYNAMIC(PreditDlg, CDialog)

PreditDlg::PreditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PRE, pParent)
	, m_NGPA(0)
	, m_NCredit(0)
	, m_FCredit(0)
	, m_gGPA(0)
	, m_NGCredit(0)
{
	
}

PreditDlg::~PreditDlg()
{
}

void PreditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NOW_GPA, m_NGPA);
	DDX_Text(pDX, IDC_NOW_GET_CREDIT, m_NCredit);
	DDX_Text(pDX, IDC_FALL_CREDIT, m_FCredit);
	DDX_Text(pDX, IDC_GET_GPA, m_gGPA);
	DDX_Text(pDX, IDC_NEED_GET_CREDIT, m_NGCredit);
}


BEGIN_MESSAGE_MAP(PreditDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &PreditDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &PreditDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &PreditDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &PreditDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &PreditDlg::OnBnClickedRadio4)
	ON_MESSAGE(WM_GETLIST, OnGetList)
	ON_BN_CLICKED(IDC_BUTTON1, &PreditDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// PreditDlg 消息处理程序


void PreditDlg::OnBnClickedButton2()
{
	OnCancel();
}


void PreditDlg::OnBnClickedRadio1()
{
	m_pos = 0;
	UpdateData(TRUE);
	m_NGCredit = 0;
	m_gGPA = 0;
	UpdateData(FALSE);
	CWnd *need = GetDlgItem(IDC_GET_GPA);
	CWnd *need_GPA = GetDlgItem(IDC_NEED_GET_CREDIT);
	CButton *A = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton *B = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton *C = (CButton*)GetDlgItem(IDC_RADIO3);
	CButton *D = (CButton*)GetDlgItem(IDC_RADIO4);
	need->EnableWindow(false);
	need_GPA->EnableWindow(false);
	A->SetCheck(true);
	B->SetCheck(false); 
	C->SetCheck(false);
	D->SetCheck(false);
}


void PreditDlg::OnBnClickedRadio2()
{
	m_pos = 1;
	CWnd *need = GetDlgItem(IDC_GET_GPA);
	CWnd *need_GPA = GetDlgItem(IDC_NEED_GET_CREDIT);
	CButton *A = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton *B = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton *C = (CButton*)GetDlgItem(IDC_RADIO3);
	CButton* D = (CButton*)GetDlgItem(IDC_RADIO4);
	need->EnableWindow(true);
	need_GPA->EnableWindow(true);
	A->SetCheck(false);
	C->SetCheck(false);
	D->SetCheck(false);
}


void PreditDlg::OnBnClickedRadio3()
{
	m_pos = 2;
	CWnd *need = GetDlgItem(IDC_GET_GPA);
	CWnd *need_GPA = GetDlgItem(IDC_NEED_GET_CREDIT);
	CButton *A = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton *B = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton *C = (CButton*)GetDlgItem(IDC_RADIO3);
	CButton* D = (CButton*)GetDlgItem(IDC_RADIO4);
	need->EnableWindow(true);
	need_GPA->EnableWindow(true);
	A->SetCheck(false);
	B->SetCheck(false);
	D->SetCheck(false);
}
void PreditDlg::OnBnClickedRadio4()
{
	if (MessageBox(_T("近年来学校取消了毕业清考，若你是18级或以后的学生，该功能对你并不可用！"), _T("注意"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
	{
		OnBnClickedRadio1();
		return;
	}
	m_pos = 3;
	CWnd* need = GetDlgItem(IDC_GET_GPA);
	CWnd* need_GPA = GetDlgItem(IDC_NEED_GET_CREDIT);
	CButton* A = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* B = (CButton*)GetDlgItem(IDC_RADIO2);
	CButton* C = (CButton*)GetDlgItem(IDC_RADIO3);
	CButton* D = (CButton*)GetDlgItem(IDC_RADIO4);
	need->EnableWindow(true);
	need_GPA->EnableWindow(false);
	A->SetCheck(false);
	B->SetCheck(false);
	C->SetCheck(false);
}


LRESULT PreditDlg::OnGetList(WPARAM wParam, LPARAM lParam)
{
	Node *s = (Node*)lParam;
	int *num = (int*)wParam;
	UpdateData(TRUE);
	float tmp = 0;
	for (int i = 1; i < *num + 1; i++)
	{
		m_NGPA += *(&(s + i)->GPA);
		tmp += *(&(s + i)->credit);
		if (*(&(s + i)->GPA) == 0)
		{
			m_FCredit += *(&(s + i)->credit);
		}
		else
		{
			m_NCredit += *(&(s + i)->credit);
			GetGPA += *(&(s + i)->GPA);
		}
	}
	m_NGPA = round((m_NGPA / tmp)*100.0f) / 100.0f;
	if (m_NCredit > 0)
	{
		GetGPA = GetGPA / m_NCredit;
	}
	UpdateData(FALSE);
	return 0;
}


void PreditDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	switch (m_pos)
	{
	case -1:
		MessageBox(_T("请考虑一下补考的事情")); return;
	case 0:
	{
		if (m_FCredit == 0)
		{
			MessageBox(_T("你没有需要补考的科目"));
			return;
		}
		double tem = 0;
		tem = (1.2*m_FCredit) + (GetGPA*m_NCredit);
		tem = round(tem / (m_FCredit + m_NCredit)*100.0f) / 100.0f;
		CString str1 = _T("通过补考后，你的绩点将提升到");
		CString str2;
		str2.Format(_T("%.2lf"), tem);
		str2 = str2 + _T("!");
		MessageBox(str1 + str2);
		return;
	}
	case 1:
	{
		if (m_gGPA > 5 || m_gGPA < 0)
		{
			MessageBox(_T("请输入正确的绩点！"));
			return;
		}
		if (m_NGCredit == 0)
		{
			MessageBox(_T("你的学分有点问题"));
			return;
		}
		if (m_NGPA > m_gGPA)
		{
			MessageBox(_T("你是我见过的少数想拉低自己绩点的人。。。"));
			return;
		}
		if (m_NGPA == m_gGPA)
		{
			CString s1, s2;
			s1.Format(_T("%.1f"), m_NGCredit);
			s1 = s1 + _T("个学分中平均考到");
			int tem;
			if (m_gGPA == 4.8)
			{
				tem = 96;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分以上即可！");
			}
			else if (m_gGPA < 4.8&&m_gGPA >= 1.2)
			{
				tem = round(m_gGPA * 10) + 48;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分即可！");
			}
			else
			{
				MessageBox(_T("预测不了，随便考考吧！"));
				return;
			}
			s1 = s1 + s2;
			MessageBox(_T("想要保持绩点，只要后面的") + s1);
			return;
		}
		if (m_FCredit == 0)
		{
			CString s1, s2;
			double tmp1 = 0;
			double tmp2 = 0;
			double tmp3 = 0;
			int p = 0;
			tmp1 = GetGPA*m_NCredit;
			tmp2 = m_gGPA*(m_NCredit + m_NGCredit);
			tmp3 = (tmp2 - tmp1) / m_NGCredit;
			tmp3 = round(tmp3 * 100.0f) / 100.0f;
			if (tmp3 > 4.8)
			{
				double tem = 0;
				tem = (4.8*m_NGCredit + tmp1) / (m_NCredit + m_NGCredit);
				s1.Format(_T("%.2lf"), tem);
				s1 = s1 + _T("。");
				MessageBox(_T("这显然是不可能的！\n但是你最多可以把绩点提升到") + s1);
				return;
			}
			else if (tmp3 == 4.8)
			{
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到96分以上即可！");
				MessageBox(_T("若想把绩点提升到") + s1);
				return;
			}
			else if (tmp3 < 1.2)
			{
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到60分以上即可！");
				MessageBox(_T("若想把绩点提升到") + s1);
			}
			else
			{
				p = round(tmp3 * 10) + 48;
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到");
				s2 = _T("");
				s2.Format(_T("%d"), p);
				s1 = s1 + s2 + _T("分即可！");
				MessageBox(_T("若想把绩点提升到") + s1);
				return;
			}
		}
		else
		{
			double tem = 0;
			tem = (1.2*m_FCredit) + (GetGPA*m_NCredit);
			tem = round(tem / (m_FCredit + m_NCredit)*100.0f) / 100.0f;
			CString s1, s2;
			double tmp1 = 0;
			double tmp2 = 0;
			double tmp3 = 0;
			int p = 0;
			tmp1 = tem*(m_NCredit + m_FCredit);
			tmp2 = m_gGPA*(m_NCredit + m_FCredit + m_NGCredit);
			tmp3 = (tmp2 - tmp1) / m_NGCredit;
			tmp3 = round(tmp3 * 100.0f) / 100.0f;
			if (tmp3 > 4.8)
			{
				double tem = 0;
				tem = (4.8*m_NGCredit + tmp1) / (m_NCredit + m_FCredit + m_NGCredit);
				s1.Format(_T("%.2lf"), tem);
				s1 = s1 + _T("。");
				MessageBox(_T("在补考全部通过的情况下，这显然是不可能的！\n但是你最多可以把绩点提升到") + s1);
				return;
			}
			else if (tmp3 == 4.8)
			{
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到96分以上即可！");
				MessageBox(_T("在补考全部通过的情况下，若想把绩点提升到") + s1);
				return;
			}
			else if (tmp3 < 1.2)
			{
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到60分以上即可！");
				MessageBox(_T("在补考全部通过的情况下，若想把绩点提升到") + s1);
				return;
			}
			else
			{
				p = round(tmp3 * 10) + 48;
				s1.Format(_T("%.2f"), m_gGPA);
				s2.Format(_T("%.1f"), m_NGCredit);
				s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到");
				s2 = _T("");
				s2.Format(_T("%d"), p);
				s1 = s1 + s2 + _T("分即可！");
				MessageBox(_T("在补考全部通过的情况下，若想把绩点提升到") + s1);
				return;
			}
		}
	}
	case 2:
	{
		if (m_gGPA > 5 || m_gGPA < 0)
		{
			MessageBox(_T("请输入正确的绩点！"));
			return;
		}
		if (m_NGCredit == 0)
		{
			MessageBox(_T("你的学分有点问题"));
			return;
		}
		if (m_NGPA > m_gGPA)
		{
			MessageBox(_T("你是我见过的少数想拉低自己绩点的人。。。"));
			return;
		}
		if (m_NGPA == m_gGPA)
		{
			CString s1, s2;
			s1.Format(_T("%.1f"), m_NGCredit);
			s1 = s1 + _T("个学分中平均考到");
			int tem;
			if (m_gGPA == 4.8)
			{
				tem = 96;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分以上即可！");
			}
			else if (m_gGPA < 4.8&&m_gGPA >= 1.2)
			{
				tem = round(m_gGPA * 10) + 48;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分即可！");
			}
			else
			{
				MessageBox(_T("预测不了，随便考考吧！"));
				return;
			}
			s1 = s1 + s2;
			MessageBox(_T("想要保持绩点，只要后面的") + s1);
			return;
		}
		CString s1, s2;
		double tmp1 = 0;
		double tmp2 = 0;
		double tmp3 = 0;
		int p = 0;
		tmp1 = m_NGPA*(m_NCredit + m_FCredit);
		tmp2 = m_gGPA*(m_NCredit + m_FCredit + m_NGCredit);
		tmp3 = (tmp2 - tmp1) / m_NGCredit;
		tmp3 = round(tmp3 * 100.0f) / 100.0f;
		if (tmp3 > 4.8)
		{
			double tem = 0;
			tem = (4.8*m_NGCredit + tmp1) / (m_NCredit + m_FCredit + m_NGCredit);
			s1.Format(_T("%.2lf"), tem);
			s1 = s1 + _T("。");
			MessageBox(_T("在不补考的情况下，这显然是不可能的！\n但是你最多可以把绩点提升到") + s1);
			return;
		}
		else if (tmp3 == 4.8)
		{
			s1.Format(_T("%.2f"), m_gGPA);
			s2.Format(_T("%.1f"), m_NGCredit);
			s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到96分以上即可！");
			MessageBox(_T("在不补考的情况下，若想把绩点提升到") + s1);
			return;
		}
		else if (tmp3 < 1.2)
		{
			s1.Format(_T("%.2f"), m_gGPA);
			s2.Format(_T("%.1f"), m_NGCredit);
			s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到60分以上即可！");
			MessageBox(_T("在不补考的情况下，若想把绩点提升到") + s1);
			return;
		}
		else
		{
			p = round(tmp3 * 10) + 48;
			s1.Format(_T("%.2f"), m_gGPA);
			s2.Format(_T("%.1f"), m_NGCredit);
			s1 = s1 + _T(",\n你要在接下来的") + s2 + _T("个学分中平均考到");
			s2 = _T("");
			s2.Format(_T("%d"), p);
			s1 = s1 + s2 + _T("分即可！");
			MessageBox(_T("在不补考的情况下，若想把绩点提升到") + s1);
			return;
		}
	}
	case 3:
	{
		if (m_FCredit == 0)
		{
			MessageBox(_T("你没有需要清考的科目"));
			return;
		}
		if (m_gGPA > 5 || m_gGPA < 0)
		{
			MessageBox(_T("请输入正确的绩点！"));
			return;
		}
		if (m_NGPA > m_gGPA)
		{
			MessageBox(_T("你是我见过的少数想拉低自己绩点的人。。。"));
			return;
		}
		if (m_NGPA == m_gGPA)
		{
			CString  s2;
			int tem;
			if (m_gGPA == 4.8)
			{
				tem = 96;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分以上即可！");
			}
			else if (m_gGPA < 4.8 && m_gGPA >= 1.2)
			{
				tem = round(m_gGPA * 10) + 48;
				s2.Format(_T("%d"), tem);
				s2 = s2 + _T("分即可！");
			}
			else
			{
				MessageBox(_T("预测不了，随便考考吧！"));
				return;
			}
			MessageBox(_T("想要保持绩点，只要在清考中平均考到") + s2);
			return;
		}
		CString s1, s2;
		double tmp1 = 0;
		double tmp2 = 0;
		double tmp3 = 0;
		int p = 0;
		tmp1 = GetGPA * m_NCredit;
		tmp2 = m_gGPA * (m_NCredit + m_FCredit);
		tmp3 = (tmp2 - tmp1) / m_FCredit;
		tmp3= round(tmp3 * 100.0f) / 100.0f;
		if (tmp3 > 4.8)
		{
			double tem = 0;
			tem = (4.8 * m_FCredit + tmp1) / (m_NCredit + m_FCredit);
			s1.Format(_T("%.2lf"), tem);
			s1 = s1 + _T("。");
			MessageBox(_T("这显然是不可能的！\n但是你最多可以把绩点提升到") + s1);
			return;
		}
		else if (tmp3 == 4.8)
		{
			s1.Format(_T("%.2f"), m_gGPA);
			s1 = s1 + _T(",\n你要在清考中平均考到96分以上即可！");
			MessageBox(_T("若想把绩点提升到") + s1);
			return;
		}
		else if (tmp3 < 1.2)
		{
			s1.Format(_T("%.2f"), m_gGPA);
			s1 = s1 + _T(",\n你要在清考中平均考到60分以上即可！");
			MessageBox(_T("若想把绩点提升到") + s1);
		}
		else
		{
			p = round(tmp3 * 10) + 48;
			s1.Format(_T("%.2f"), m_gGPA);
			s1 = s1 + _T(",\n你要在清考中平均考到");
			s2 = _T("");
			s2.Format(_T("%d"), p);
			s1 = s1 + s2 + _T("分即可！");
			MessageBox(_T("若想把绩点提升到") + s1);
			return;
		}
	}
	}
	UpdateData(FALSE);
}


