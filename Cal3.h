// Cal3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCal3App:
// �� Ŭ������ ������ ���ؼ��� Cal3.cpp�� �����Ͻʽÿ�.
//

class CCal3App : public CWinApp
{
public:
	CCal3App();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCal3App theApp;