// Cal3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Cal3.h"
#include "Cal3Dlg.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCal3Dlg ��ȭ ����




CCal3Dlg::CCal3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCal3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCal3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, resEidt);
}

BEGIN_MESSAGE_MAP(CCal3Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CCal3Dlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CCal3Dlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CCal3Dlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CCal3Dlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CCal3Dlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CCal3Dlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CCal3Dlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CCal3Dlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CCal3Dlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CCal3Dlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_ROOT, &CCal3Dlg::OnBnClickedButtonRoot)
	ON_BN_CLICKED(IDC_BUTTON_PNCHANGE, &CCal3Dlg::OnBnClickedButtonPnchange)
	ON_BN_CLICKED(IDC_BUTTON_FLOATING, &CCal3Dlg::OnBnClickedButtonFloating)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCal3Dlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCal3Dlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCal3Dlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CCal3Dlg::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCal3Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCal3Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCal3Dlg::OnBnClickedButtonEqual)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CCal3Dlg �޽��� ó����

BOOL CCal3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCal3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCal3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCal3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCal3Dlg::InsertOut()
{
	CString temp=_T("");
	if(NumMem.GetSize()==0) temp=_T("\r\n\r\n")+strNum;
	else {
		for(int i=0; i<OperMem.GetSize(); i++)
			temp+=NumMem[i]+OperMem[i];
		temp+=_T("\r\n\r\n")+strNum;
	}
	resEidt.SetWindowTextW(temp);
}

void CCal3Dlg::InsertNum(CString num)
{
	if(strNum.Compare(_T("0"))==0) strNum=num;
	else if(Flag==1) {
		Flag=0;
		strNum=num;
	} else if(strNum.Right(1)==_T(")")) ;
	else strNum+=num;

	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonNum0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(OperMem.GetSize()&&(OperMem[OperMem.GetSize()-1]==_T("��"))) ;
	else InsertNum(_T("0"));
}

void CCal3Dlg::OnBnClickedButtonNum1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("1"));
}

void CCal3Dlg::OnBnClickedButtonNum2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("2"));
}

void CCal3Dlg::OnBnClickedButtonNum3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("3"));
}

void CCal3Dlg::OnBnClickedButtonNum4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("4"));
}

void CCal3Dlg::OnBnClickedButtonNum5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("5"));
}

void CCal3Dlg::OnBnClickedButtonNum6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("6"));
}

void CCal3Dlg::OnBnClickedButtonNum7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("7"));
}

void CCal3Dlg::OnBnClickedButtonNum8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("8"));
}

void CCal3Dlg::OnBnClickedButtonNum9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InsertNum(_T("9"));
}

void CCal3Dlg::OnBnClickedButtonRoot()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	strNum=_T("��(")+strNum+_T(")");
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonPnchange()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(strNum.Left(1)==_T("-")) strNum=strNum.Right(strNum.GetLength()-1);
	else strNum=_T("-")+strNum;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonFloating()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(strNum.Right(1)==_T(")")) strNum=_T("0.");
	else if(strNum.Find(_T("."))==-1) strNum+=_T(".");
	else ;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	strNum=_T("0");
	NumMem.RemoveAll();
	OperMem.RemoveAll();
	Flag=0;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(strNum.Right(1)==_T(")")) ;
	else if(strNum.GetLength()<2) strNum=_T("0");
	else strNum=strNum.Left(strNum.GetLength()-1);
	InsertOut();
}

void CCal3Dlg::OperCal(CString oper)
{
	NumMem.Add(strNum);
	OperMem.Add(oper);

	CString temp=_T("");
	for(int i=0; i<NumMem.GetSize(); i++)
		temp+=NumMem[i]+OperMem[i];
	strNum=_T("0");
	resEidt.SetWindowTextW(temp);
}

void CCal3Dlg::OnBnClickedButtonPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OperCal(_T("+"));
}

void CCal3Dlg::OnBnClickedButtonMin()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OperCal(_T("-"));
}

void CCal3Dlg::OnBnClickedButtonMul()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OperCal(_T("��"));
}

void CCal3Dlg::OnBnClickedButtonDiv()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OperCal(_T("��"));
}

float CCal3Dlg::NumChange(CString num)
{
	float change;
	if(num.Left(1)==_T("��")) {
		int count=0;
		num=num.Mid(2, num.GetLength()-3);
		while(num.Left(1)==_T("��")) {
			count++;
			num=num.Mid(2, num.GetLength()-3);
		}
		change=_tstof(num);
		for(int i=0; i<=count; i++) change=sqrt(change);
	} else change=_tstof(num);
	return change;
}

void CCal3Dlg::OnBnClickedButtonEqual()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	NumMem.Add(strNum);
	float res=NumChange(NumMem[0]);
	float next;
	for(int i=0; i<OperMem.GetSize(); i++) {
		if(OperMem[i]==_T("+")) {
			next=NumChange(NumMem[i+1]);
			res=res+next;
		} else if(OperMem[i]==_T("-")) {
			next=NumChange(NumMem[i+1]);
			res=res-next;
		} else if(OperMem[i]==_T("��")) {
			next=NumChange(NumMem[i+1]);
			res=res*next;
		} else if(OperMem[i]==_T("��")) {
			next=NumChange(NumMem[i+1]);
			res=res/next;
		}
	}
	CString temp;
	temp.Format(_T("%f"), res);
	while(temp.Right(1)==_T("0")) temp=temp.Left(temp.GetLength()-1);
	if(temp.Right(1)==_T(".")) temp=temp.Left(temp.GetLength()-1);
	strNum=temp;
	temp=_T("\r\n\r\n")+temp;
	resEidt.SetWindowTextW(temp);
	Flag=1;
	NumMem.RemoveAll();
	OperMem.RemoveAll();
}

BOOL CCal3Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(200, 200, 230));
	return true;

	return CDialog::OnEraseBkgnd(pDC);
}
