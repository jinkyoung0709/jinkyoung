// Cal3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Cal3.h"
#include "Cal3Dlg.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCal3Dlg 대화 상자




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


// CCal3Dlg 메시지 처리기

BOOL CCal3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCal3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(OperMem.GetSize()&&(OperMem[OperMem.GetSize()-1]==_T("÷"))) ;
	else InsertNum(_T("0"));
}

void CCal3Dlg::OnBnClickedButtonNum1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("1"));
}

void CCal3Dlg::OnBnClickedButtonNum2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("2"));
}

void CCal3Dlg::OnBnClickedButtonNum3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("3"));
}

void CCal3Dlg::OnBnClickedButtonNum4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("4"));
}

void CCal3Dlg::OnBnClickedButtonNum5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("5"));
}

void CCal3Dlg::OnBnClickedButtonNum6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("6"));
}

void CCal3Dlg::OnBnClickedButtonNum7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("7"));
}

void CCal3Dlg::OnBnClickedButtonNum8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("8"));
}

void CCal3Dlg::OnBnClickedButtonNum9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InsertNum(_T("9"));
}

void CCal3Dlg::OnBnClickedButtonRoot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	strNum=_T("√(")+strNum+_T(")");
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonPnchange()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(strNum.Left(1)==_T("-")) strNum=strNum.Right(strNum.GetLength()-1);
	else strNum=_T("-")+strNum;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonFloating()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(strNum.Right(1)==_T(")")) strNum=_T("0.");
	else if(strNum.Find(_T("."))==-1) strNum+=_T(".");
	else ;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	strNum=_T("0");
	NumMem.RemoveAll();
	OperMem.RemoveAll();
	Flag=0;
	InsertOut();
}

void CCal3Dlg::OnBnClickedButtonBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OperCal(_T("+"));
}

void CCal3Dlg::OnBnClickedButtonMin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OperCal(_T("-"));
}

void CCal3Dlg::OnBnClickedButtonMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OperCal(_T("×"));
}

void CCal3Dlg::OnBnClickedButtonDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OperCal(_T("÷"));
}

float CCal3Dlg::NumChange(CString num)
{
	float change;
	if(num.Left(1)==_T("√")) {
		int count=0;
		num=num.Mid(2, num.GetLength()-3);
		while(num.Left(1)==_T("√")) {
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		} else if(OperMem[i]==_T("×")) {
			next=NumChange(NumMem[i+1]);
			res=res*next;
		} else if(OperMem[i]==_T("÷")) {
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(200, 200, 230));
	return true;

	return CDialog::OnEraseBkgnd(pDC);
}
