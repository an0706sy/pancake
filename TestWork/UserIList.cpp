// UserIList.cpp: 구현 파일
//

#include "pch.h"
#include "TestWork.h"
#include "UserIList.h"
#include "afxdialogex.h"
#include "Register.h"
#include "TestWorkDlg.h"
#include <fstream>
#include <sstream>


// UserIList 대화 상자

IMPLEMENT_DYNAMIC(UserIList, CDialogEx)

UserIList::UserIList(CWnd* pParent /*=nullptr*/, const std::vector<User>& userInfos)
	: CDialogEx(IDD_USER_LIST, pParent), m_UserInfos(userInfos)
{
	
}



UserIList::~UserIList()
{
}

void UserIList::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(UserIList, CDialogEx)
END_MESSAGE_MAP()

BOOL UserIList::OnInitDialog()
{
    CDialogEx::OnInitDialog();
	
   
    m_ListCtrl.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 100);
    m_ListCtrl.InsertColumn(1, _T("아이디"), LVCFMT_LEFT, 100);
    m_ListCtrl.InsertColumn(2, _T("비밀번호"), LVCFMT_LEFT, 100);
    m_ListCtrl.InsertColumn(3, _T("등급"), LVCFMT_LEFT, 100);

    // 회원 정보 표시
    
	CListCtrl* pListCtrl = GetListCtrl();
	
	if (pListCtrl) {
		ShowUserInfo();
		ReadUserFile(_T("user_data.txt"));
	}
	
    return TRUE;
}
CListCtrl* UserIList::GetListCtrl()
{
	return static_cast<CListCtrl*>(GetDlgItem(IDC_LIST));
}
void UserIList::ShowUserInfo()
{
	CListCtrl* pListCtrl = GetListCtrl();
    ;
	if (pListCtrl) {
		pListCtrl->DeleteAllItems();
        
		// 회원 정보 추가
		for (const User& userInfo : m_UserInfos)
		{
			int nIndex = pListCtrl->InsertItem(pListCtrl->GetItemCount(), userInfo.UserName);
			pListCtrl->SetItemText(nIndex, 1, userInfo.UserId);
			pListCtrl->SetItemText(nIndex, 2, userInfo.UserPassword);
			CString strGrade;
			strGrade.Format(_T("%d"), userInfo.Grade);
			pListCtrl->SetItemText(nIndex, 3, strGrade);
           
		}
	}
	else {
		return;
	}
}
// UserIList 메시지 처리기

void UserIList::ReadUserFile(const CString& fileName)
{
    m_UserInfos.clear(); // 기존 데이터를 초기화합니다.

    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            User userInfo;

            if (!line.empty())
            {
                CString cstr(line.c_str());
                int pos1 = cstr.Find(_T('\t'));

                if (pos1 != -1)
                {
                    userInfo.UserName = cstr.Left(pos1);
                    CString rest = cstr.Mid(pos1 + 1);

                    int pos2 = rest.Find(_T('\t'));

                    if (pos2 != -1)
                    {
                        userInfo.UserId = rest.Left(pos2);
                        CString rest2 = rest.Mid(pos2 + 1);

                        int pos3 = rest2.Find(_T('\t'));

                        if (pos3 != -1)
                        {
                            userInfo.UserPassword = rest2.Left(pos3);
                            CString strGrade = rest2.Mid(pos3 + 1);
                            userInfo.Grade = _ttoi(strGrade);
                            m_UserInfos.push_back(userInfo);
							//TRACE(_T("Read User: %s, %s, %s, %d\n"),
							//	userInfo.UserName, userInfo.UserId, userInfo.UserPassword, userInfo.Grade);
						}
                        
                    }
                }
            }
        }

        file.close();

       //ShowUserInfo();
    }
}

