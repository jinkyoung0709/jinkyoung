// Cal3Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CCal3Dlg ��ȭ ����
class CCal3Dlg : public CDialog
{
// �����Դϴ�.
public:
	CCal3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CAL3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStringArray NumMem, OperMem;
	CString strNum;
	int Flag;
	void InsertNum(CString num);
	void InsertOut();
	void OperCal(CString oper);
	float NumChange(CString num);
public:
	CEdit resEidt;
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonRoot();
	afx_msg void OnBnClickedButtonPnchange();
	afx_msg void OnBnClickedButtonFloating();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMin();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
