// Login.cpp: 구현 파일
//

#include <vector>
#include "pch.h"
#include "TestWork.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Register.h"
#include "UserIList.h"
#include "TestWorkDlg.h"


// Login 대화 상자

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(const std::vector<User>& userInfo, CWnd* pParent /*=nullptr*/ )
	: CDialogEx(IDD_LOGIN, pParent), m_UserInfos(userInfo)
{
	
}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID, m_InputId);
	DDX_Text(pDX, IDC_PW, m_InputPassword);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &Login::OnBnClickedLoginButton)
END_MESSAGE_MAP()
BOOL Login::OnInitDialog()
{
	CDialogEx::OnInitDialog();
   
	

	return TRUE;  
				  
}



bool Login::CheckLogin(const CString& userID, const CString& password)
{
	for (const User& userInfo : m_UserInfos)
	{
		TRACE(_T("%s"), m_UserInfos);
		if (userID == userInfo.UserId && password == userInfo.UserPassword)
		{

			return true;
		}
	}
	return false;
	//Register UserInfo;
	//UserInfo.m_UserInfos = m_UserInfos;
	//dlg.ReadUserFile(_T("user_data.txt"));
	//int nCnt = m_UserInfos.size();
	//bool bMatch = false;
	//for (int i = 0; i < nCnt; i++)
	//{
	//	if (userID == m_UserInfos[i].UserId && password == m_UserInfos[i].UserPassword)
	//	{
	//		bMatch = true;
	//		break;
	//	}
	//}

	//if (bMatch)
	//{
	//	AfxMessageBox(_T("로그인 성공"));
	//}
	//else
	//{
	//	AfxMessageBox(_T("로그인 실패"));
	//}
	//return false;
}

// Login 메시지 처리기
void Login::OnBnClickedLoginButton()
{
	UpdateData(TRUE);

	if (CheckLogin(m_InputId, m_InputPassword))
	{
		AfxMessageBox(_T("로그인 성공"));
	}
	else
	{
		//AfxMessageBox(_T("로그인 실패"));
		CString errorMessage;
		errorMessage.Format(_T("로그인 실패 - 아이디: %s, 비밀번호: %s"), m_InputId, m_InputPassword);
		
		AfxMessageBox(errorMessage);

	}
}
