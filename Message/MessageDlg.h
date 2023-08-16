
// MessageDlg.h: 헤더 파일
//

#pragma once
#include "Message.h"

// CMessageDlg 대화 상자
class CMessageDlg : public CDialogEx
{
// 생성입니다.
public:
	CMessageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MESSAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	BOOL PreTranslateMessage(MSG * pMsg);
	afx_msg HCURSOR OnQueryDragIcon();
	LRESULT OnReceiveMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CListBox m_listOutput; // List Box 컨트롤 멤버 변수
	CEdit m_editInput;
public:
	CString m_sFilePath;
	afx_msg void OnEnKillFocusEditInput();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonSave();
	afx_msg BOOL OnEditEnterKey();
};

