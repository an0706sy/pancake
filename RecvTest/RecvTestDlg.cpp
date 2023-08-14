
// RecvTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "RecvTest.h"
#include "RecvTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRecvTestDlg 대화 상자



CRecvTestDlg::CRecvTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RECVTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sFilePath = _T("F:\\Memo\\txt\\aaa.txt");
}

void CRecvTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_listOutput);

}

BEGIN_MESSAGE_MAP(CRecvTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_COPYDATA, OnReceiveMessage)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CRecvTestDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CRecvTestDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CRecvTestDlg 메시지 처리기

BOOL CRecvTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRecvTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRecvTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRecvTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
LRESULT CRecvTestDlg::OnReceiveMessage(WPARAM wParam, LPARAM lParam)
{
	PCOPYDATASTRUCT pCDS = (PCOPYDATASTRUCT)lParam;
	if (pCDS->dwData == 0) {
		CString receivedText = (LPCTSTR)(pCDS->lpData);

		COleDateTime currentTime = COleDateTime::GetCurrentTime();
		CString dateTimeStr = currentTime.Format(_T("[%Y-%m-%d %H:%M:%S] "));
		CString outputText = dateTimeStr + receivedText;

		// 리스트 박스에 추가
		m_listOutput.AddString(outputText);
		TRACE(_T("Added to list box: %s\n"), outputText);

		return 0;
	}
}

void CRecvTestDlg::OnBnClickedButtonDelete()
{
	m_listOutput.ResetContent();
}
void CRecvTestDlg::OnBnClickedButtonSave()
{
	
	
	LPCTSTR lpszFilter = _T("TXT Files(*.txt)|*.txt|");

	// 파일 공용컨트롤 대화상자 인스턴스 생성.. 첫번째 인자가 TRUE 이면 읽기 FALSE 이면 쓰기.
	CFileDialog FileDlg(FALSE, _T(".txt"), _T("aaa.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, NULL);

	if (FileDlg.DoModal() == IDOK)      
	{

		CString sPath(FileDlg.GetPathName());
		//CFile File(sPath, CFile::modeWrite | CFile::modeCreate);
		TRACE(_T("Selected Path: %s\n"), sPath);
		CStdioFile file;
		
		if (file.Open(sPath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite | CFile::typeText)) {
			CString line;
			for (int i = 0; i < m_listOutput.GetCount(); ++i) {
				m_listOutput.GetText(i, line);
				line += _T("\n");
				file.Write((LPCTSTR)line, line.GetLength() * sizeof(TCHAR));
			}
			
			//File.Flush();
			file.Close();
		}
		
     }


}
