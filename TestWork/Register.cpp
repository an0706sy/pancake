// Register.cpp: 구현 파일
//

#include "pch.h"
#include "TestWork.h"
#include "Register.h"
#include "afxdialogex.h"
#include "UserIList.h"
#include <fstream>

// Register 대화 상자

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_REG, pParent)
	
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_User[0].UserName);
	DDX_Text(pDX, IDC_EDIT2, m_User[0].UserId);
	DDX_Text(pDX, IDC_EDIT3, m_User[0].UserPassword);
	DDX_Text(pDX, IDC_EDIT4, m_User[0].Grade);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDC_SUBMIT, &Register::OnBnClickedRegister)

END_MESSAGE_MAP()


// Register 메시지 처리기
void Register::OnBnClickedRegister()
{
	UpdateData(TRUE);
	User newUser;
	newUser.UserName = m_User[0].UserName;
	newUser.UserId = m_User[0].UserId;
	newUser.UserPassword = m_User[0].UserPassword;
	newUser.Grade = m_User[0].Grade;
	m_UserInfo.push_back(newUser);
	SaveUserFile(newUser);
	AfxMessageBox(_T("회원 등록이 완료되었습니다."));
	

}
const UserInfo& Register::GetUserInfo(int index) const
{
	return m_User[index];
}

void Register::SaveUserFile(const User& user)
{
	CString fileName = _T("user_data.txt");
	CStdioFile file;
	if (file.Open(fileName, CFile::modeWrite | CFile::modeNoTruncate | CFile::typeText))
	{
		file.SeekToEnd(); // 파일 끝으로 이동하여 추가 저장
		CString line;
		line.Format(_T("%s\t%s\t%s\t%d\n"),
			user.UserName, user.UserId, user.UserPassword, user.Grade); // 수정된 부분
		file.WriteString(line);
		file.Close();
	}

}
