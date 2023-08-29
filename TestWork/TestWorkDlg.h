
// TestWorkDlg.h: 헤더 파일
//

#pragma once
#include "UserIList.h"

// CTestWorkDlg 대화 상자
class CTestWorkDlg : public CDialogEx
{
// 생성입니다.
public:
	CTestWorkDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


public:
	
// 구현입니다.
protected:
	HICON m_hIcon;
	//std::vector<User> m_UserInfo;
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnUser();
	std::vector<User> m_UserInfos;
	const std::vector<User>& GetUserInfo() const { return m_UserInfos; }
	afx_msg void OnBnClickedAdmin();
};
