#pragma once


// Login 대화 상자
#include <vector>
#include "Register.h"
#include "UserIList.h"
class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	   // 표준 생성자입니다.
	virtual ~Login();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	//afx_msg void OnBnClickedLoginButton();
	
	DECLARE_MESSAGE_MAP()
public:
	CString m_InputId;
	CString m_InputPassword;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLoginButton();
	const std::vector<User>& m_UserInfos;
	
	bool CheckLogin(const CString& userID, const CString& password);
	Login(const std::vector<User>& userInfo, CWnd* pParent = nullptr);
};

