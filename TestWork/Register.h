#pragma once


// Register 대화 상자
#include <vector>

typedef struct UserInfo
{
	CString UserName;
	CString UserId;
	CString UserPassword;
	int Grade;

}User;
class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)
public:
	UserInfo m_User[100];
	std::vector<User> m_UserInfo;
public:
	Register(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Register();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_REG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedRegister();

	const UserInfo& GetUserInfo(int index) const;

	afx_msg void SaveUserFile(const User& user);
	
};

