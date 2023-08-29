#pragma once


// UserIList 대화 상자
#include <vector>
#include <vector>
#include "Register.h"
class UserIList : public CDialogEx
{
	DECLARE_DYNAMIC(UserIList)

public:
	//UserIList(CWnd* pParent);
	UserIList(CWnd* pParent = nullptr, const std::vector<User>& userInfos = std::vector<User>());   // 표준 생성자입니다.
	virtual ~UserIList();
	BOOL OnInitDialog();
	std::vector<User> m_UserInfos;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	
	UserInfo m_UserInfo;
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	
	CListCtrl* GetListCtrl();
	void ReadUserFile(const CString& fileName);
	void ShowUserInfo();
};
