
// 20220401HMYDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "20220401HMY.h"
#include "20220401HMYDlg.h"
#include "afxdialogex.h"
#include "CvvImage.h"
#include <ctime>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ++ =============================================================
// >> AXL(AjineXtek Library) 관련 Header파일 포함시킵니다.
// ※ [CAUTION] 예제를 복사하여 다른 위치에서 실행시 참조경로 변경이 필요합니다.
// ---------------------------------------------------------------
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXL.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXM.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXDev.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXHS.h"
// ++ =============================================================
// >> AXL(AjineXtek Library) 관련 Library파일을 Link시킵니다.
// ※ [CAUTION] 예제를 복사하여 다른 위치에서 실행시 참조경로 변경이 필요합니다.
// ----------------------------------------------------------------
#ifdef _M_X64
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/64Bit/AxL.lib")
#else
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/32Bit/AxL.lib")
#endif





// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

														// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CEdit User_name;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, User_name);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CAboutDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMy20220401HMYDlg 대화 상자



CMy20220401HMYDlg::CMy20220401HMYDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy20220401HMYDlg::IDD, pParent)
	, vision_btn(FALSE)
	, cp_btn(FALSE)
	, ptp_btn(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20220401HMYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLI_X, m_sliX);
	DDX_Control(pDX, IDC_SLI_Y, m_sliY);
	DDX_Control(pDX, IDC_EDT_X_INPUT_VEL, m_edtXInputVel);
	DDX_Control(pDX, IDC_EDT_X_INPUT_ACC, m_edtXInputAcc);
	DDX_Control(pDX, IDC_EDT_X_INPUT_DEC, m_edtXInputDec);
	DDX_Control(pDX, IDC_EDT_X_COMMAND_POS, m_stcXCommPos);
	DDX_Control(pDX, IDC_EDT_X_FEEDBACK_POS, m_stcXFeedPos);
	DDX_Control(pDX, IDC_EDT_X_FEEDBACK_VEL, m_stcXFeedVel);
	DDX_Control(pDX, IDC_CHK_X_SERVO_ON, m_chkXServoOn);
	DDX_Control(pDX, IDC_CHK_X_IN_MOTION, m_chkXInMotion);
	DDX_Control(pDX, IDC_CHK_X_ALARM, m_chkXAlarm);
	DDX_Control(pDX, IDC_CHK_X_HOME_SIGNAL, m_chkXHomeSignal);
	DDX_Control(pDX, IDC_CHK_X_IN_POSITION, m_chkXInPosition);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_P, m_chkXLimitP);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_N, m_chkXLimitN);
	DDX_Control(pDX, IDC_CHK_X_EMG, m_chkXEmg);
	DDX_Control(pDX, IDC_PRG_X_HOME_RATE, m_prgXHomeRate);
	DDX_Control(pDX, IDC_EDT_X_P, m_stcXP);
	DDX_Control(pDX, IDC_EDT_X_I, m_stcXI);
	DDX_Control(pDX, IDC_EDT_X_D, m_stcXD);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_VEL, m_edtYInputVel);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_ACC, m_edtYInputAcc);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_DEC, m_edtYInputDec);
	DDX_Control(pDX, IDC_EDT_Y_COMMAND_POS, m_stcYCommPos);
	DDX_Control(pDX, IDC_EDT_Y_FEEDBACK_POS, m_stcYFeedPos);
	DDX_Control(pDX, IDC_EDT_Y_FEEDBACK_VEL, m_stcYFeedVel);
	DDX_Control(pDX, IDC_CHK_Y_SERVO_ON, m_chkYServoOn);
	DDX_Control(pDX, IDC_CHK_Y_IN_MOTION, m_chkYInMotion);
	DDX_Control(pDX, IDC_CHK_Y_ALARM, m_chkYAlarm);
	DDX_Control(pDX, IDC_CHK_Y_HOME_SIGNAL, m_chkYHomeSignal);
	DDX_Control(pDX, IDC_CHK_Y_IN_POSITION, m_chkYInPosition);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_P, m_chkYLimitP);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_N, m_chkYLimitN);
	DDX_Control(pDX, IDC_CHK_Y_EMG, m_chkYEmg);
	DDX_Control(pDX, IDC_PRG_Y_HOME_RATE, m_prgYHomeRate);
	DDX_Control(pDX, IDC_EDT_Y_P, m_stcYP);
	DDX_Control(pDX, IDC_EDT_Y_I, m_stcYI);
	DDX_Control(pDX, IDC_EDT_Y_D, m_stcYD);
	DDX_Control(pDX, IDC_EDT_X_MOVE_POS, m_edtXMovePos);
	DDX_Control(pDX, IDC_EDT_Y_MOVE_POS, m_editYMovePos);
	DDX_Control(pDX, IDC_BTN_X_ALARM_CLEAR, m_btnXAlarmClear);
	DDX_Control(pDX, IDC_BTN_X_HOME_SEARCH, m_btnXHomeSearch);
	DDX_Control(pDX, IDC_BTN_X_POS_CLEAR, m_btnXPosClear);
	DDX_Control(pDX, IDC_BTN_X_SSTOP, m_btnXSStop);
	DDX_Control(pDX, IDC_BTN_X_ESTOP, m_btnXEStop);
	DDX_Control(pDX, IDC_BTN_Y_ALARM_CLEAR, m_btnYAlarmClear);
	DDX_Control(pDX, IDC_BTN_Y_HOME_SEARCH, m_btnYHomeSearch);
	DDX_Control(pDX, IDC_BTN_Y_POS_CLEAR, m_btnYPosClear);
	DDX_Control(pDX, IDC_BTN_Y_SSTOP, m_btnYSStop);
	DDX_Control(pDX, IDC_BTN_Y_ESTOP, m_btnYEStop);
	DDX_Control(pDX, IDC_BTN_LOAD_FILE, m_btnLoadFile);
	DDX_Control(pDX, IDC_BTN_BOTH_HOME_SEARCH, m_btnBothHomeSearch);
	DDX_Control(pDX, IDC_BTN_MOVE_ZERO_POS, m_btnMoveZeroPos);
	DDX_Control(pDX, IDC_BTN_BOTH_ESTOP, m_btnBothStop);
	DDX_Control(pDX, IDC_PC_STAGE, m_pcstage);
	DDX_Control(pDX, IDC_BTN_POS_MOVE, m_btnPosMove);
	//DDX_Radio(pDX, IDC_VISION_BTN, vision_btn);
	//DDX_Radio(pDX, IDC_RADIO_CP, cp_btn);
	//DDX_Radio(pDX, IDC_RADIO_PTP, ptp_btn);
}

BEGIN_MESSAGE_MAP(CMy20220401HMYDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHK_X_SERVO_ON, &CMy20220401HMYDlg::OnBnClickedChkXServoOn)
	ON_BN_CLICKED(IDC_BTN_X_ALARM_CLEAR, &CMy20220401HMYDlg::OnBnClickedBtnXAlarmClear)
	ON_BN_CLICKED(IDC_BTN_X_HOME_SEARCH, &CMy20220401HMYDlg::OnBnClickedBtnXHomeSearch)
	ON_BN_CLICKED(IDC_BTN_X_POS_CLEAR, &CMy20220401HMYDlg::OnBnClickedBtnXPosClear)
	ON_BN_CLICKED(IDC_BTN_X_SSTOP, &CMy20220401HMYDlg::OnBnClickedBtnXSstop)
	ON_BN_CLICKED(IDC_BTN_X_ESTOP, &CMy20220401HMYDlg::OnBnClickedBtnXEstop)
	ON_BN_CLICKED(IDC_CHK_Y_SERVO_ON, &CMy20220401HMYDlg::OnBnClickedChkYServoOn)
	ON_BN_CLICKED(IDC_BTN_Y_ALARM_CLEAR, &CMy20220401HMYDlg::OnBnClickedBtnYAlarmClear)
	ON_BN_CLICKED(IDC_BTN_Y_HOME_SEARCH, &CMy20220401HMYDlg::OnBnClickedBtnYHomeSearch)
	ON_BN_CLICKED(IDC_BTN_Y_POS_CLEAR, &CMy20220401HMYDlg::OnBnClickedBtnYPosClear)
	ON_BN_CLICKED(IDC_BTN_Y_SSTOP, &CMy20220401HMYDlg::OnBnClickedBtnYSstop)
	ON_BN_CLICKED(IDC_BTN_Y_ESTOP, &CMy20220401HMYDlg::OnBnClickedBtnYEstop)
	ON_BN_CLICKED(IDC_BTN_LOAD_FILE, &CMy20220401HMYDlg::OnBnClickedBtnLoadFile)
	ON_BN_CLICKED(IDC_BTN_BOTH_HOME_SEARCH, &CMy20220401HMYDlg::OnBnClickedBtnBothHomeSearch)
	ON_BN_CLICKED(IDC_BTN_MOVE_ZERO_POS, &CMy20220401HMYDlg::OnBnClickedBtnMoveZeroPos)
	ON_BN_CLICKED(IDC_BTN_BOTH_ESTOP, &CMy20220401HMYDlg::OnBnClickedBtnBothEstop)
	ON_BN_CLICKED(IDC_BTN_POS_MOVE, &CMy20220401HMYDlg::OnBnClickedBtnPosMove)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_RADIO_PTP, &CMy20220401HMYDlg::OnBnClickedRadioPtp)
	ON_BN_CLICKED(IDC_RADIO_CP, &CMy20220401HMYDlg::OnBnClickedRadioCp)
	ON_BN_CLICKED(IDC_VISION_BTN, &CMy20220401HMYDlg::OnBnClickedVisionBtn)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy20220401HMYDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_Object_Cap_btn, &CMy20220401HMYDlg::OnBnClickedObjectCapbtn)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy20220401HMYDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy20220401HMYDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy20220401HMYDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy20220401HMYDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy20220401HMYDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy20220401HMYDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy20220401HMYDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy20220401HMYDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy20220401HMYDlg::OnBnClickedButton10)
	//	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTON11, &CMy20220401HMYDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy20220401HMYDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMy20220401HMYDlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CMy20220401HMYDlg 메시지 처리기

BOOL CMy20220401HMYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	//IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.

	/*ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	}*/
	CAboutDlg Dlgabout;
	Dlgabout.DoModal();
	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

									// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitState();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy20220401HMYDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy20220401HMYDlg::OnPaint()
{
	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// 아이콘을 그립니다.
	//	dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}

	CString strPosX, strPosY, strEndPos;

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CClientDC dc(this);

		// XY Stage 배경을 그립니다.
		dc.Rectangle(&m_rectStage);

		// XY Stage의 좌측 벽면에서 MARGIN값만큼 떨어진 위치에 Y축 기준선을 그립니다.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN);
		dc.LineTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);

		// XY Stage의 하단 벽면에서 MARGIN값만큼 떨어진 위치에 X축 기준선을 그립니다.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);
		dc.LineTo(m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

		// 각 축의 시작점(0,0)을 표시합니다.
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.bottom - MARGIN + 5, "(0, 0)");

		// X축의 끝 지점(?, 0)을 표시합니다.
		strEndPos.Format("(%d, 0)", (int)((double)((m_rectStage.right - m_rectStage.left) -
			(MARGIN * 2)) * m_posRevisionX));
		dc.TextOut(m_rectStage.right - MARGIN - 30, m_rectStage.bottom - MARGIN + 5,
			strEndPos);

		// Y축의 끝 지점(0, ?)을 표시합니다.
		strEndPos.Format("(0, %d)", (int)((double)((m_rectStage.bottom - m_rectStage.top)
			- (MARGIN * 2)) * m_posRevisionY));
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.top + MARGIN - 20,
			strEndPos);

		if (!btn_ptp && !btn_cp)
		{
			// point 위치를 나타내는 작은 사각형을 그립니다. Y좌표는 상하 반전을 수행합니다.
			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) -
				m_pointY;
			dc.Rectangle((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
				MARGIN + iNewPointY) + 5,
				(m_rectStage.left + MARGIN + m_pointX) - 5, (m_rectStage.top + MARGIN +
					iNewPointY) - 5);

			// 포인터 위치 우측 하단에 작게 좌표를 표시합니다.
			strPosX.Format("X:%d", m_realPointX);
			strPosY.Format("Y:%d", m_realPointY);
			dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
				MARGIN + iNewPointY) + 5, strPosX);
			dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
				MARGIN + iNewPointY) + 20, strPosY);
		}
		else if (btn_ptp)
		{
			int iNewPointRectY[PTP_MAX];

			for (int i = 0; i < ptp_click_count; i++)
			{
				iNewPointRectY[i] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - ptp_points[i][1];
				if (iNewPointRectY[i] > 0)
				{
					dc.Rectangle((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5,
						(m_rectStage.left + MARGIN + ptp_points[i][0]) - 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) - 5);
					strPosX.Format("X:%d", (int)(ptp_points[i][0] * m_posRevisionX));
					strPosY.Format("Y:%d", (int)(ptp_points[i][1] * m_posRevisionY));
					dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5, strPosX);
					dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 20, strPosY);
				}
			}
			if (ptp_click_count == PTP_MAX)
			{
				for (int i = 0; i < ptp_click_count - 1; i++)
				{
					dc.MoveTo(m_rectStage.left + MARGIN + ptp_points[i][0], m_rectStage.top + MARGIN + iNewPointRectY[i]);		/////  현재 포지션을 특정위치로 이동
					dc.LineTo(m_rectStage.left + MARGIN + ptp_points[i + 1][0], m_rectStage.top + MARGIN + iNewPointRectY[i + 1]);	/////  이동된 특정위치에서 지정한 지점까지 선 그림
				}
			}
		}
		else if (btn_cp)
		{

		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy20220401HMYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20220401HMYDlg::OnBnClickedChkXServoOn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_X_SERVO_ON);
	// 지정 축의 Servo On/Off 신호를 출력합니다.
	dwRetCode = AxmSignalServoOn(m_lAxisNoX, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnXAlarmClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoX, ENABLE);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnXHomeSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// X축이 Servo Off이면 이 작업을 수행하지 않습니다.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// X축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// - 그 외의 정보는 AXM 매뉴얼을 참고하시기 바랍니다.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop 확인 변수를 초기화합니다.
	m_bXStop = FALSE;

	// Edit control에서 속도, 가속도 값을 받아옵니다.
	m_edtXInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtXInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;
	// 원점검색에 사용되는 검색방법을 설정합니다.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoX, DIR_CCW, Signal_HomeSensor,
		UNUSED, 1000, 0);

	// 원점검색에 사용되는 단계별 속도를 설정합니다.
	dwRetCode = AxmHomeSetVel(m_lAxisNoX, dHomeVelFirst, dHomeVelSecond,
		dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// X축 원점검색을 진행합니다.
	m_prgXHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoX);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult);
		m_prgXHomeRate.EnableWindow(FALSE);
		return;
	}
	// 원점 검색 진행 상황을 표시할 타이머를 시작합니다.
	m_bXIsMoving = TRUE;
	SetTimer(TM_X_HOME_INFO, 200, NULL); // 일정한 주기로 변경되는 원점검색 관련정보를 Control에 반영할 타이머를 실행합니다. 
}


void CMy20220401HMYDlg::OnBnClickedBtnXPosClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwRetCode;
	CString strResult;

	// Command위치와 Actual위치를 지정한 값으로 설정합니다.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoX, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnXSstop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmMoveSStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;

}


void CMy20220401HMYDlg::OnBnClickedBtnXEstop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmMoveEStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;

}


void CMy20220401HMYDlg::OnBnClickedChkYServoOn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_Y_SERVO_ON);
	// 지정 축의 Servo On/Off 신호를 출력합니다.
	dwRetCode = AxmSignalServoOn(m_lAxisNoY, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnYAlarmClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoY, ENABLE);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnYHomeSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// Y축이 Servo Off이면 이 작업을 수행하지 않습니다.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// Y축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// - 그 외의 정보는 AXM 매뉴얼을 참고하시기 바랍니다.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop 확인 변수를 초기화합니다.
	m_bYStop = FALSE;

	// Edit control에서 속도, 가속도 값을 받아옵니다.
	m_edtYInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtYInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;

	// 원점검색에 사용되는 검색방법을 설정합니다.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoY, DIR_CCW, Signal_HomeSensor,
		UNUSED, 1000, 0);

	// 원점검색에 사용되는 단계별 속도를 설정합니다.
	dwRetCode = AxmHomeSetVel(m_lAxisNoY, dHomeVelFirst, dHomeVelSecond,
		dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// Y축 원점검색을 진행합니다.
	m_prgYHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoY);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home search fail.\nError Msg : " + strResult);
		m_prgYHomeRate.EnableWindow(FALSE);
		return;
	}

	// 원점 검색 진행 상황을 표시할 타이머를 시작합니다.
	m_bYIsMoving = TRUE;
	SetTimer(TM_Y_HOME_INFO, 200, NULL); // 일정한 주기로 변경되는 원점검색 관련정보를 Control에 반영할 타이머를 실행합니다. 
}


void CMy20220401HMYDlg::OnBnClickedBtnYPosClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwRetCode;
	CString strResult;
	// Command위치와 Actual위치를 지정한 값으로 설정합니다.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoY, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnYSstop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmMoveSStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy20220401HMYDlg::OnBnClickedBtnYEstop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmMoveEStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy20220401HMYDlg::OnBnClickedBtnLoadFile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString temp;
	CFileDialog dlg(TRUE, "Mot", NULL, OFN_HIDEREADONLY, "AXM File (*.mot)|*.mot|AllFiles (*.*)|*.*||");

	if (dlg.DoModal() == IDOK) {
		LPTSTR strFilename;
		temp = dlg.GetPathName();
		strFilename = temp.GetBuffer(0);

		// 함수 실행 성공시 지정한 Mot파일의 설정값으로 모션축 설정이 일괄 변경됩니다.
		if (AxmMotLoadParaAll(strFilename) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("File load fail!");
		}
		else
		{
			AfxMessageBox("File load success!");
			UpdateState();
		}
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnBothHomeSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch();
}


void CMy20220401HMYDlg::OnBnClickedBtnMoveZeroPos()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double dPosX = 0.0, dPosY = 0.0;
	int nSliderEndPosY = m_sliY.GetRangeMax();
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, 100);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, 100);
	// (0, 0) 좌표로 이동합니다. 
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;
	//Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	AxmMoveStartPos(m_lAxisNoX, dPosX,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	AxmMoveStartPos(m_lAxisNoY, dPosY,
		GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));


}


void CMy20220401HMYDlg::OnBnClickedBtnBothEstop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 전 축에 대한 ESTOP 명령을 수행합니다.
	OnBnClickedBtnXEstop();
	OnBnClickedBtnYEstop();
}


void CMy20220401HMYDlg::OnBnClickedBtnPosMove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strMovePosX, strMovePosY, strMsg;
	int iMovePosX, iMovePosY, iLimitPosX, iLimitPosY;
	double dPosX, dPosY;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	// XY Stage내의 이동 한계점을 계산합니다.
	iLimitPosX = (int)((m_rectStage.right - m_rectStage.left - (MARGIN * 2)) *
		m_posRevisionX);
	iLimitPosY = (int)((m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) *
		m_posRevisionX);

	// Edit Control에서 입력 좌표 값을 받아옵니다.
	m_edtXMovePos.GetWindowText(strMovePosX);
	strMovePosX = strMovePosX.Trim();
	iMovePosX = atoi(strMovePosX);
	// 입력받은 좌표가 XY Stage를 벗어난 좌표이면 에러 팝업을 출력하고 이동하지 않습니다.
	if (iMovePosX < 0 || iMovePosX > iLimitPosX)
	{
		strMsg.Format("유효한 X좌표 값을 입력하세요. (입력범위 : 0 ~ %d)", iLimitPosX);
		AfxMessageBox(strMsg);
		return;
	}

	m_editYMovePos.GetWindowText(strMovePosY);
	strMovePosY = strMovePosY.Trim();
	iMovePosY = atoi(strMovePosY);
	// 입력받은 좌표가 XY Stage를 벗어난 좌표이면 에러 팝업을 출력하고 이동하지 않습니다.
	if (iMovePosY < 0 || iMovePosY > iLimitPosY)
	{
		strMsg.Format("유효한 Y좌표 값을 입력하세요. (입력범위 : 0 ~ %d)", iLimitPosY);
		AfxMessageBox(strMsg);
		return;
	}

	// 해당 좌표로 이동합니다.

	m_pointX = (int)((double)iMovePosX / (m_posRevisionX));
	m_pointY = (int)((double)iMovePosY / (m_posRevisionY));
	//Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	dPosX = iMovePosX;
	m_realPointX = iMovePosX;
	AxmMoveStartPos(m_lAxisNoX, dPosX,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	dPosY = iMovePosY;
	m_realPointY = iMovePosY;
	AxmMoveStartPos(m_lAxisNoY, dPosY,
		GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
}


void CMy20220401HMYDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// "종료 하시겠습니까?" 확인 팝업 창을 출력하여 종료 여부를 한 번 더 확인합니다.
	if (AfxMessageBox("종료 하시겠습니까?", MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}
	else   //종료시 로그파일 작성.
	{
		sTime.Format(_T("사용자 이름 : %s /시간 : %d년 %d월 %d일 %d시 %d분\n[Correct Detection : %d개] | [Wrong Detection : %d개] | [Error Detection : %d개]"), user_name, tmCur.GetYear(), tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetHour(), tmCur.GetMinute(), correct_detection, false_detection, error_detection);
		//파일명"이 없으면 만들고 있으면 작성되어 있는 기록 다음줄에 작성하도록 하는 조건문들.
		if (file.Open(_T("Detection_Result.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, NULL))
		{
			file.SeekToEnd();
			file.WriteString(sTime + "\n");
		}
		file.Close();
	}
	vision_btn = false;
	CDialogEx::OnClose();
}


void CMy20220401HMYDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 종료 처리를 위하여 AXL 라이브러리가 열려 있으면 닫습니다.
	if (AxlIsOpened())
	{
		AxlClose();
	}
}


void CMy20220401HMYDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl *pSlider = (CSliderCtrl *)pScrollBar;
	double dPosX = 0.0;
	// 매 이벤트마다 마지막으로 자동호출되는 이벤트에만 작업을 수행합니다.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// X축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion(..) : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
	case IDC_SLI_X:
		m_pointX = pSlider->GetPos();
		break;
	}
	//Invalidate();

	UpdateData(TRUE);

	dPosX = m_pointX * m_posRevisionX;
	m_realPointX = (int)dPosX;

	// 이동 정보값을 각 Edit Control에서 읽어옵니다.
	dVel = GetDlgItemDouble(IDC_EDT_X_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_X_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_X_INPUT_DEC);
	// Absolute 좌표계 이동으로 설정합니다.
	AxmMotSetAbsRelMode(m_lAxisNoX, POS_ABS_MODE);

	// 이동을 수행합니다.
	dwRetCode = AxmMoveStartPos(m_lAxisNoX, dPosX, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy20220401HMYDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dPosX = 0.0, dPosY = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	CWinThread* pWinThread;	//쓰레드 변수


	if (m_bXIsMoving || m_bYIsMoving)
	{
		return;
	}

	// 영역 판단
	CRect rect1(&m_rectStage);
	CRect rect2(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN, m_rectStage.right
		- MARGIN, m_rectStage.bottom - MARGIN);

	if (rect1.PtInRect(point))
	{
		if (rect2.PtInRect(point))
		{
			Set_Cursor = 2;
		}
		else
		{
			Set_Cursor = 1;
		}
	}
	else
	{
		Set_Cursor = 0;
	}

	if (Set_Cursor == 1)
	{
		AfxMessageBox("표현할 수 없는 위치입니다.");
	}
	else if (Set_Cursor == 2)
	{
		if (btn_cap == false)
		{
			if (!btn_ptp && !btn_cp)
			{
				m_pointX = point.x - (m_rectStage.left + MARGIN);
				// Y좌표계를 상하 반전하여 적용합니다.
				m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
					(m_rectStage.top + MARGIN));

				Invalidate();
				m_sliX.SetPos(m_pointX);
				m_sliY.SetPos(nSliderEndPosY - m_pointY);

				dPosX = m_pointX * m_posRevisionX;
				m_realPointX = (int)dPosX;
				AxmMoveStartPos(m_lAxisNoX, dPosX,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				if (dwRetCode != AXT_RT_SUCCESS)
				{
					strResult = TranslateAxmResult(dwRetCode);
					AfxMessageBox("X Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
					return;
				}

				dPosY = m_pointY * m_posRevisionY;
				m_realPointY = (int)dPosY;
				AxmMoveStartPos(m_lAxisNoY, dPosY,
					GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
				if (dwRetCode != AXT_RT_SUCCESS)
				{
					strResult = TranslateAxmResult(dwRetCode);
					AfxMessageBox("Y Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
					return;
				}
			}
			else if (btn_ptp)
			{
				ptp_points[ptp_click_count][0] = point.x - (m_rectStage.left + MARGIN);
				ptp_points[ptp_click_count][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));

				Invalidate();
				m_sliX.SetPos(ptp_points[ptp_click_count][0]);
				m_sliY.SetPos(nSliderEndPosY - ptp_points[ptp_click_count][1]);  //////  이 부분 역시 y좌표계를 상하 반전하여 적용

				ptp_click_count++;

				if (ptp_click_count == PTP_MAX)
				{
					Invalidate();
					UpdateWindow();

					DWORD StatusX = FALSE, StatusY = FALSE;

					lAxis[0] = 0;
					lAxis[1] = 1;

					AxmContiWriteClear(lCoordinate);
					AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
					AxmContiSetAbsRelMode(lCoordinate, 0);
					AxmContiBeginNode(lCoordinate);
					for (int i = 0; i < PTP_MAX; i++)
					{
						dPos[0] = ptp_points[i][0] * m_posRevisionX;
						dPos[1] = ptp_points[i][1] * m_posRevisionY;

						AxmLineMove(lCoordinate, dPos,
							GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
							GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
							GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
					}

					pWinThread = AfxBeginThread(ThreadStart, this);
					AxmContiEndNode(lCoordinate);
					AxmContiStart(lCoordinate, 0, 0);
					ptp_click_count = 0;
					return;
				}
			}
			else if (btn_cp)
			{

			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMy20220401HMYDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dXCommPos = 0.0, dXFeedPos = 0.0, dXFeedVel = 0.0;
	double dYCommPos = 0.0, dYFeedPos = 0.0, dYFeedVel = 0.0;
	DWORD dwRetCode = 0, dwValue = 0, dwStepMain = 0, dwStepSub = 0;
	WORD wGainP = 0, wGainI = 0, wGainD = 0;
	long lCheck = 0;
	CString strResult;
	CString strGainXP, strGainXI, strGainXD, strGainYP, strGainYI, strGainYD;

	switch (nIDEvent) {
	case TM_DISPLAY:
		// X, Y축의 지령(Command)위치를 반환합니다.
		AxmStatusGetCmdPos(m_lAxisNoX, &dXCommPos);
		if (m_dXOldCommPos != dXCommPos) {
			SetDlgItemDouble(IDC_EDT_X_COMMAND_POS, dXCommPos);
			m_dXOldCommPos = dXCommPos;
		}
		AxmStatusGetCmdPos(m_lAxisNoY, &dYCommPos);
		if (m_dYOldCommPos != dYCommPos) {
			SetDlgItemDouble(IDC_EDT_Y_COMMAND_POS, dYCommPos);
			m_dYOldCommPos = dYCommPos;
		}

		// X, Y축의 실제(Feedback)위치를 반환합니다.
		AxmStatusGetActPos(m_lAxisNoX, &dXFeedPos);
		if (m_dXOldFeedPos != dXFeedPos) {
			SetDlgItemDouble(IDC_EDT_X_FEEDBACK_POS, dXFeedPos);
			m_dXOldFeedPos = dXFeedPos;
		}
		AxmStatusGetActPos(m_lAxisNoY, &dYFeedPos);
		if (m_dYOldFeedPos != dYFeedPos) {
			SetDlgItemDouble(IDC_EDT_Y_FEEDBACK_POS, dYFeedPos);
			m_dYOldFeedPos = dYFeedPos;
		}

		// X, Y축의 구동 속도를 반환합니다.
		AxmStatusReadVel(m_lAxisNoX, &dXFeedVel);
		if (m_dXOldFeedVel != dXFeedVel) {
			SetDlgItemDouble(IDC_EDT_X_FEEDBACK_VEL, dXFeedVel);
			m_dXOldFeedVel = dXFeedVel;
		}
		AxmStatusReadVel(m_lAxisNoY, &dYFeedVel);
		if (m_dYOldFeedVel != dYFeedVel) {
			SetDlgItemDouble(IDC_EDT_Y_FEEDBACK_VEL, dYFeedVel);
			m_dYOldFeedVel = dYFeedVel;
		}

		// X축 외부 센서 및 모터 관련 신호들의 상태를 가져옵니다.
		dwRetCode = AxmStatusReadMechanical(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			// + Limit
			lCheck = dwValue & 0x1;
			CheckDlgButton(IDC_CHK_X_LIMIT_P, lCheck);

			// - Limit
			lCheck = (dwValue >> 1) & 0x1;
			CheckDlgButton(IDC_CHK_X_LIMIT_N, lCheck);

			// Alarm
			lCheck = (dwValue >> 4) & 0x1;
			CheckDlgButton(IDC_CHK_X_ALARM, lCheck);

			// Inposition
			lCheck = (dwValue >> 5) & 0x1;
			CheckDlgButton(IDC_CHK_X_IN_POSITION, lCheck);

			// Emergency
			lCheck = (dwValue >> 6) & 0x1;
			CheckDlgButton(IDC_CHK_X_EMG, lCheck);

			// Home
			lCheck = (dwValue >> 7) & 0x1;
			CheckDlgButton(IDC_CHK_X_HOME_SIGNAL, lCheck);
		}

		// In Motion
		dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwValue);

		if (dwRetCode == AXT_RT_SUCCESS)
		{
			lCheck = dwValue & QIDRIVE_STATUS_0;
			CheckDlgButton(IDC_CHK_X_IN_MOTION, lCheck);
			// 이동 중이면 이동 관련 컨트롤을 비활성화하고, 이동이 종료하면 활성화합니다.
			if (lCheck)
			{
				m_bXIsMoving = TRUE;
				m_sliX.EnableWindow(FALSE);
				m_btnXHomeSearch.EnableWindow(FALSE);
				m_btnPosMove.EnableWindow(FALSE);
			}
			else
			{
				m_bXIsMoving = FALSE;
				m_sliX.EnableWindow(TRUE);
				m_btnXHomeSearch.EnableWindow(TRUE);
			}
		}

		// Servo On
		dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwValue);
		CheckDlgButton(IDC_CHK_X_SERVO_ON, dwValue);

		// X축의 P 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainXP.Format("%d", (wGainP / 10));
		m_stcXP.SetWindowText(strGainXP);

		// X축의 D 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainXD.Format("%d", (wGainD / 10));
		m_stcXD.SetWindowText(strGainXD);

		// X축의 I 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX, GAIN_MAIN_ADDRESS_I,
			GAIN_SUB_ADDRESS, &wGainI);
		strGainXI.Format("%d", (wGainI / 10));
		m_stcXI.SetWindowText(strGainXI);

		// Y축 외부 센서 및 모터 관련 신호들의 상태를 가져옵니다.
		dwRetCode = AxmStatusReadMechanical(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			// + Limit
			lCheck = dwValue & 0x1;
			CheckDlgButton(IDC_CHK_Y_LIMIT_P, lCheck);

			// - Limit
			lCheck = (dwValue >> 1) & 0x1;
			CheckDlgButton(IDC_CHK_Y_LIMIT_N, lCheck);

			// Alarm
			lCheck = (dwValue >> 4) & 0x1;
			CheckDlgButton(IDC_CHK_Y_ALARM, lCheck);

			// Inposition
			lCheck = (dwValue >> 5) & 0x1;
			CheckDlgButton(IDC_CHK_Y_IN_POSITION, lCheck);

			// Emergency
			lCheck = (dwValue >> 6) & 0x1;
			CheckDlgButton(IDC_CHK_Y_EMG, lCheck);

			// Home
			lCheck = (dwValue >> 7) & 0x1;
			CheckDlgButton(IDC_CHK_Y_HOME_SIGNAL, lCheck);
		}

		// In Motion
		dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS)
		{
			lCheck = dwValue & QIDRIVE_STATUS_0;
			CheckDlgButton(IDC_CHK_Y_IN_MOTION, lCheck);
			// 이동 중이면 이동 관련 컨트롤을 비활성화하고, 이동이 종료하면 활성화합니다.
			if (lCheck)
			{
				m_bYIsMoving = TRUE;
				m_sliY.EnableWindow(FALSE);
				m_btnYHomeSearch.EnableWindow(FALSE);
				m_btnPosMove.EnableWindow(FALSE);
			}
			else
			{
				m_bYIsMoving = FALSE;
				m_sliY.EnableWindow(TRUE);
				m_btnYHomeSearch.EnableWindow(TRUE);
			}
		}

		// Servo On
		dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwValue);
		CheckDlgButton(IDC_CHK_Y_SERVO_ON, dwValue);

		// Y축의 P 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainYP.Format("%d", (wGainP / 10));
		m_stcYP.SetWindowText(strGainYP);

		// Y축의 D 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainYD.Format("%d", (wGainD / 10));
		m_stcYD.SetWindowText(strGainYD);

		// Y축의 I 게인 튜닝값을 표시합니다.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY, GAIN_MAIN_ADDRESS_I,
			GAIN_SUB_ADDRESS, &wGainI);
		strGainYI.Format("%d", (wGainI / 10));
		m_stcYI.SetWindowText(strGainYI);

		// X축과 Y축의 이동이 종료되면 좌표이동 버튼을 활성화
		if ((m_btnPosMove.IsWindowEnabled() == FALSE) && (m_bXIsMoving == FALSE) &&
			(m_bYIsMoving == FALSE))
		{
			m_btnPosMove.EnableWindow(TRUE);

			// 현재 위치로 스테이지 좌표를 이동합니다.
			m_pointX = (int)(dXFeedPos / m_posRevisionX);
			m_pointY = (int)(dYFeedPos / m_posRevisionY);
			m_realPointX = (int)(dXFeedPos);
			m_realPointY = (int)(dYFeedPos);
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(m_sliY.GetRangeMax() - m_pointY);
			//Invalidate();
		}

		break;

	case TM_X_HOME_INFO:
		// 긴급 정지일 때에는 종료 처리를 합니다.
		if (m_bXStop)
		{
			m_prgXHomeRate.EnableWindow(FALSE);
			m_bXIsMoving = FALSE;
			m_bXStop = FALSE;
			KillTimer(TM_X_HOME_INFO);
			AfxMessageBox("X Axis Home Search Stop.", MB_OK | MB_ICONQUESTION);

			m_prgXHomeRate.SetPos(0);
			break;
		}

		// X축의 원점검색 진행율을 확인합니다.
		dwRetCode = AxmHomeGetRate(m_lAxisNoX, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgXHomeRate.SetPos(dwStepSub);
		}

		// X축의 원점검색 결과를 확인합니다.
		dwRetCode = AxmHomeGetResult(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// 원점 검색 작업이 정상적으로 종료함에 따른 후속 처리를 합니다.
				m_prgXHomeRate.EnableWindow(FALSE);
				m_bXIsMoving = FALSE;
				KillTimer(TM_X_HOME_INFO);
				AfxMessageBox("X Axis Home Search Success.");
			}
		}
		else
		{
			// 원점 검색 작업이 비정상적으로 종료함에 따른 후속 처리를 합니다.
			strResult = TranslateAxmResult(dwRetCode);
			m_bXIsMoving = FALSE;
			m_prgXHomeRate.EnableWindow(FALSE);
			KillTimer(TM_X_HOME_INFO);
			AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult, MB_OK
				| MB_ICONQUESTION);
			m_prgXHomeRate.SetPos(0);
		}
		break;

	case TM_Y_HOME_INFO:
		// 긴급 정지일 때에는 종료 처리를 합니다.
		if (m_bYStop)
		{
			m_prgYHomeRate.EnableWindow(FALSE);
			m_bYIsMoving = FALSE;
			m_bYStop = FALSE;
			KillTimer(TM_Y_HOME_INFO);
			AfxMessageBox("Y Axis Home Search Stop.", MB_OK | MB_ICONQUESTION);
			m_prgYHomeRate.SetPos(0);
			break;
		}

		// Y축의 원점검색 진행율을 확인합니다.
		dwRetCode = AxmHomeGetRate(m_lAxisNoY, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgYHomeRate.SetPos(dwStepSub);
		}

		// Y축의 원점검색 결과를 확인합니다.
		dwRetCode = AxmHomeGetResult(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// 원점 검색 작업이 정상적으로 종료함에 따른 후속 처리를 합니다.
				m_prgYHomeRate.EnableWindow(FALSE);
				m_bYIsMoving = FALSE;
				KillTimer(TM_Y_HOME_INFO);
				AfxMessageBox("Y Axis Home Search Success.");
			}
		}
		else
		{
			// 원점 검색 작업이 비정상적으로 종료함에 따른 후속 처리를 합니다.
			strResult = TranslateAxmResult(dwRetCode);
			m_bYIsMoving = FALSE;
			m_prgYHomeRate.EnableWindow(FALSE);
			KillTimer(TM_Y_HOME_INFO);
			AfxMessageBox("Y Axis Home Search fail.\nError Msg : " + strResult, MB_OK
				| MB_ICONQUESTION);
			m_prgYHomeRate.SetPos(0);
		}
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMy20220401HMYDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl *pSlider = (CSliderCtrl *)pScrollBar;
	double dPosY = 0.0;
	int nSliderEndPosY = pSlider->GetRangeMax();

	// 매 이벤트마다 마지막으로 자동호출되는 이벤트에만 작업을 수행합니다.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}
	// Y축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion(..) : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
	case IDC_SLI_Y:
		m_pointY = nSliderEndPosY - pSlider->GetPos();
		break;
	}
	Invalidate();

	UpdateData(TRUE);

	dPosY = m_pointY * m_posRevisionY;
	m_realPointY = (int)dPosY;

	// 이동 정보값을 각 Edit Control에서 읽어옵니다.
	dVel = GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC);

	// Absolute 좌표계 이동으로 설정합니다.
	AxmMotSetAbsRelMode(m_lAxisNoY, POS_ABS_MODE);

	// 이동을 수행합니다.
	dwRetCode = AxmMoveStartPos(m_lAxisNoY, dPosY, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CMy20220401HMYDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	// Esc키 입력에 대한 처리를 합니다.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
		&& (pMsg->wParam == VK_ESCAPE))
	{
		// 전 축에 대한 ESTOP 명령을 수행합니다. 
		OnBnClickedBtnBothEstop();

		return TRUE;
	}

	// Enter키 입력에 대한 처리를 합니다.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
		&& (pMsg->wParam == VK_RETURN))
	{
		// 아무 것도 수행하지 않습니다.
		return TRUE;
	}
	if (move_key_flag)
	{
		if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
			&& (pMsg->wParam == VK_UP))
		{
			AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.

			if (pos_move_up[0] < 199)
			{
				pos_move_up[0] += 10;
				lAxis[0] = 0;
				lAxis[1] = 1;
				AxmContiWriteClear(lCoordinate);
				AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
				AxmContiSetAbsRelMode(lCoordinate, 0);
				AxmContiBeginNode(lCoordinate);
				AxmLineMove(lCoordinate, pos_move_up,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				AxmContiEndNode(lCoordinate);
				AxmContiStart(lCoordinate, 0, 0);

			}
			else if (pos_move_up[0] >= 199)
			{
				AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
			}
		}
		if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
			&& (pMsg->wParam == VK_DOWN))
		{
			AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			if (pos_move_up < 0)
			{
				AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
			}
			else if (pos_move_up > 0)
			{
				pos_move_up[0] -= 10;
				lAxis[0] = 0;
				lAxis[1] = 1;
				AxmContiWriteClear(lCoordinate);
				AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
				AxmContiSetAbsRelMode(lCoordinate, 0);
				AxmContiBeginNode(lCoordinate);
				AxmLineMove(lCoordinate, pos_move_up,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				AxmContiEndNode(lCoordinate);
				AxmContiStart(lCoordinate, 0, 0);
			}
		}
		if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
			&& (pMsg->wParam == VK_LEFT))
		{
			AxmStatusGetActPos(0, &pos_move_right[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			AxmStatusGetActPos(1, &pos_move_right[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			if (pos_move_right[1] < 0)
			{
				AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
			}
			else if (pos_move_right[1] > 0)
			{
				pos_move_right[1] -= 10;
				lAxis[0] = 0;
				lAxis[1] = 1;
				AxmContiWriteClear(lCoordinate);
				AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
				AxmContiSetAbsRelMode(lCoordinate, 0);
				AxmContiBeginNode(lCoordinate);
				AxmLineMove(lCoordinate, pos_move_right,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				AxmContiEndNode(lCoordinate);
				AxmContiStart(lCoordinate, 0, 0);
			}
		}
		if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
			&& (pMsg->wParam == VK_RIGHT))
		{
			AxmStatusGetActPos(0, &pos_move_right[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			AxmStatusGetActPos(1, &pos_move_right[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			if (pos_move_right[1] < 199)
			{
				pos_move_right[1] += 10;
				lAxis[0] = 0;
				lAxis[1] = 1;
				AxmContiWriteClear(lCoordinate);
				AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
				AxmContiSetAbsRelMode(lCoordinate, 0);
				AxmContiBeginNode(lCoordinate);
				AxmLineMove(lCoordinate, pos_move_right,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				AxmContiEndNode(lCoordinate);
				AxmContiStart(lCoordinate, 0, 0);

			}
			else if (pos_move_right[1] >= 199)
			{
				AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
			}
		}
	}



	return CDialog::PreTranslateMessage(pMsg);
}




BOOL CMy20220401HMYDlg::InitState()
{
	//멤버 변수 초기화
	btn_ptp = false;
	btn_cp = false;
	vision_btn = false;
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_Object_Cap_btn)->EnableWindow(false);
	default_joy_btn();
	ptp_click_count = 0;
	lPosSize = 2;
	//실행 시 버튼 눌려있는 현상 제거
	CButton* pCheckHist;
	pCheckHist = (CButton*)GetDlgItem(IDC_VISION_BTN);
	pCheckHist->SetCheck(FALSE);
	// AXL 변수 초기화
	long lAxisCount = 0;
	DWORD dwRetCode = 0;
	long lPulse = 0;
	CString strResult;
	int nSliderEndPosX, nSliderEndPosY;

	// AXL 초기화
	if ((AxlIsOpened() == FALSE))
	{
		if (AxlOpenNoReset(7) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("AxlOpen Fail");
			return FALSE;
		}
	}

	// 현재 보드에서 인식할 수 있는 최대 축수가 2개 이상이 아니면 에러를 출력합니다.
	dwRetCode = AxmInfoGetAxisCount(&lAxisCount);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("AxmInfoGetAxisCount fail.\nError Msg : " + strResult);
		return FALSE;
	}
	else if (lAxisCount < 2)
	{
		AfxMessageBox("Please connect 2 Axis");
		return FALSE;
	}

	// X축과 Y축의 번호를 임의로 설정합니다.
	m_lAxisNoX = DEFAULT_AXIS_NUMBER_X;
	m_lAxisNoY = DEFAULT_AXIS_NUMBER_Y;

	// 좌표를 초기화합니다.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;

	// 사용하지 않는 Emergency 신호를 UNUSED로 설정
	dwRetCode = AxmSignalSetStop(m_lAxisNoX, EMERGENCY_STOP, UNUSED);
	dwRetCode = AxmSignalSetStop(m_lAxisNoY, EMERGENCY_STOP, UNUSED);

	// Limit Level을 LOW로 설정합니다.
	dwRetCode = AxmSignalSetLimit(m_lAxisNoX, EMERGENCY_STOP, LOW, LOW);
	dwRetCode = AxmSignalSetLimit(m_lAxisNoY, EMERGENCY_STOP, LOW, LOW);

	// Unit Per Pulse를 10:1048576으로 설정합니다.
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoX, 10, 1048576);
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoY, 10, 1048576);

	// Edit Contorl에 초기값을 설정합니다.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_DEC, DEFAULT_DEC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_DEC, DEFAULT_DEC, 1);
	m_edtXMovePos.SetWindowText("0");
	m_editYMovePos.SetWindowText("0");

	// 원점검색 진행율을 표시할 프로그래스바를 초기화합니다.
	m_prgXHomeRate.SetRange(0, 100);
	m_prgXHomeRate.SetStep(1);
	m_prgXHomeRate.SetPos(0);
	m_prgXHomeRate.EnableWindow(FALSE);
	m_prgYHomeRate.SetRange(0, 100);
	m_prgYHomeRate.SetStep(1);
	m_prgYHomeRate.SetPos(0);
	m_prgYHomeRate.EnableWindow(FALSE);

	// Dialog내에서의 XY Stage의 위치를 저장합니다.
	m_pcstage.GetWindowRect(&m_rectStage);
	ScreenToClient(&m_rectStage);

	// X, Y축 슬라이더를 초기화합니다.
	nSliderEndPosX = m_rectStage.right - m_rectStage.left - (MARGIN * 2);
	nSliderEndPosY = m_rectStage.bottom - m_rectStage.top - (MARGIN * 2);
	m_sliX.SetRange(0, nSliderEndPosX, FALSE);
	m_sliY.SetRange(0, nSliderEndPosY, FALSE);
	m_sliX.SetPos(0);
	m_sliY.SetPos(nSliderEndPosY);

	// X, Y축의 이동 확인 변수를 초기화합니다.
	m_bXIsMoving = FALSE;
	m_bYIsMoving = FALSE;

	// Stop 명령 확인 변수를 초기화합니다.
	m_bXStop = FALSE;
	m_bYStop = FALSE;

	// 좌표 보정치값을 계산합니다.
	m_posRevisionX = DEFAULT_REVISION_X / (m_rectStage.right - m_rectStage.left -
		(MARGIN * 2));
	m_posRevisionY = DEFAULT_REVISION_Y / (m_rectStage.bottom - m_rectStage.top -
		(MARGIN * 2));

	// X, Y축의 현재 위치와 각종 상태값을 주기적으로 표시할 타이머를 활성화합니다.
	SetTimer(TM_DISPLAY, 100, NULL);
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch();
	return TRUE;
}

void CMy20220401HMYDlg::SetDlgItemDouble(int nID, double value, int nPoint)
{
	CString sTemp, sTemp2;
	sTemp2.Format("%%.%df", nPoint);
	sTemp.Format(sTemp2, value);
	GetDlgItem(nID)->SetWindowText(sTemp);
}

double CMy20220401HMYDlg::GetDlgItemDouble(int nID)
{
	double dRet;
	CString sTemp;
	GetDlgItem(nID)->GetWindowText(sTemp);
	dRet = atof((LPCTSTR)sTemp);
	return dRet;
}

CString CMy20220401HMYDlg::TranslateAxmResult(DWORD dwAxmResult)
{
	CString strResult;

	switch (dwAxmResult) {
	case AXT_RT_SUCCESS:
		strResult.Format("[0000] API함수 수행 성공"); break;
	case AXT_RT_OPEN_ERROR:
		strResult.Format("[1001] 라이브러리가 오픈되어 있지 않음"); break;
	case AXT_RT_OPEN_ALREADY:
		strResult.Format("[1002] 라이브러리가 오픈되어 있고 사용 중임"); break;
	case AXT_RT_NOT_OPEN:
		strResult.Format("[1053] 라이브러리 초기화 실패"); break;
	case AXT_RT_NOT_SUPPORT_VERSION:
		strResult.Format("[1054] 지원하지 않는 하드웨어"); break;
	case AXT_RT_NETWORK_ERROR: strResult.Format("[1152] 네트워크에 연결된 슬레이브 노드 연결되지 않았거나 연결상태가 불량함"); break;
	case AXT_RT_MOTION_OPEN_ERROR:
		strResult.Format("[4001] 모션 라이브러리 Open 실패"); break;
	case AXT_RT_MOTION_NOT_MODULE:
		strResult.Format("[4051] 시스템에 장착된 모션 모듈이 없음"); break;
	case AXT_RT_MOTION_INVALID_AXIS_NO:
		strResult.Format("[4101] 해당 축이 존재하지 않음"); break;
	case AXT_RT_MOTION_INVALID_METHOD: strResult.Format("[4102] 해당 축 구동에 필요한 설정이 잘못됨"); break;
	case AXT_RT_MOTION_INVALID_VELOCITY: strResult.Format("[4113] 모션 구동 속도 값이 0으로 설정되어 모션 에러 발생"); break;
	case AXT_RT_MOTION_INVALID_ACCELTIME: strResult.Format("[4114] 모션 구동 가속 시간 값이 0으로 설정되어 모션 에러 발생"); break;
	case AXT_RT_MOTION_ERROR_IN_MOTION: strResult.Format("[4152] 모션 구동 중에 다른 모션 구동 함수를 실행함"); break;
	case AXT_RT_MOTION_ERROR: strResult.Format("[4153] 다축 구동 정지 함수 실행 중 에러 발생함"); break;
	case AXT_RT_MOTION_HOME_SEARCHING: strResult.Format("[4201] 홈을 찾고 있는 중일 때 다른 모션 함수를 사용함"); break;
	case AXT_RT_MOTION_SETTING_ERROR: strResult.Format("[4255] 속도, 가속도 등 설정이 잘못됨"); break;
	case AXT_RT_PROTECTED_DURING_SERVOON: strResult.Format("[4260] 서보 온 상태에서 사용할 수 없는 함수 또는 입력 값을 사용하였음"); break;
	case AXT_RT_HW_ACCESS_ERROR: strResult.Format("[4261] 보드의 H/W 접근 오류가 발생함"); break;
	default: strResult.Format("기타에러발생"); break;
	}

	return strResult;
}

BOOL CMy20220401HMYDlg::UpdateState()
{
	DWORD dwRetCode = 0;
	double dUnit = 0.0, dMaxRangeX = 0.0, dMaxRangeY = 0.0;
	long lPulse = 0;

	// 좌표 보정치값을 계산합니다.
	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoX, &dUnit, &lPulse);
	dMaxRangeX = DEFAULT_REVISION_X * (double)(DEFAULT_PULSE / DEFAULT_UNIT) *
		(dUnit / lPulse);
	m_posRevisionX = dMaxRangeX / (m_rectStage.right - m_rectStage.left - (MARGIN * 2));

	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoY, &dUnit, &lPulse);
	dMaxRangeY = DEFAULT_REVISION_Y * (double)(DEFAULT_PULSE / DEFAULT_UNIT) *
		(dUnit / lPulse);
	m_posRevisionY = dMaxRangeY / (m_rectStage.bottom - m_rectStage.top - (MARGIN *
		2));

	Invalidate();

	return TRUE;
}

void CMy20220401HMYDlg::OnBnClickedRadioPtp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = true;
	btn_cp = false;
	vision_btn = false;
}


void CMy20220401HMYDlg::OnBnClickedRadioCp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = false;
	btn_cp = true;
	vision_btn = false;
}

UINT CMy20220401HMYDlg::ThreadStart(LPVOID pParam)
{
	CMy20220401HMYDlg* line_thread = (CMy20220401HMYDlg*)AfxGetApp()->m_pMainWnd;
	double m_posrevX = 0.504051;
	double m_posrevY = 0.492911;

	CWnd* pWnd = AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	HDC h_screen_dc = ::GetDC(hWnd);
	CDC* dc = CDC::FromHandle(h_screen_dc);

	int kk = 0;
	kk = (line_thread->m_rectStage.left) + MARGIN;

	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = dc->SelectObject(&pen);

	if (line_thread->btn_ptp)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
			AxmStatusGetActPos(1, &dreal_posY);	////  Y축위 현재 위치값을 받아와 dreal_posX에 저장해준다.


			if (abs(line_thread->ptp_points[0][0] * line_thread->m_posRevisionX - dreal_posX) < 10.0 &&
				abs(line_thread->ptp_points[0][1] * line_thread->m_posRevisionX - dreal_posY) < 10.0)
			{
				if (flag == 0)
					flag = 1;
			}

			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}
			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);
			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
	}
	else if (line_thread->btn_cp)
	{

	}

	return 0;
}

void CMy20220401HMYDlg::OnBnClickedVisionBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = false;
	btn_cp = false;
	vision_btn = true;

	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_Object_Cap_btn)->EnableWindow(true);
	GetDlgItem(IDC_SLI_Y)->EnableWindow(false);
	GetDlgItem(IDC_SLI_X)->EnableWindow(false);
	CWinThread* pWinThread = AfxBeginThread(VisionThreadStart_PC, this); // 픽처컨트롤에서 현재 진행되는 상황을 보여줌.
	capture = cvCaptureFromCAM(0);
}

void CMy20220401HMYDlg::OnBnClickedObjectCapbtn()  //캡처하기 위한 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox("영역 내부에 물체를 두고 c버튼을 눌러 캡쳐해주세요.");
	btn_cap = true;
	btn_ptp = false;
	btn_cp = false;
	vision_btn = false;
	move_key_flag = true;
	GetDlgItem(IDC_Object_Cap_btn)->EnableWindow(false);
	on_joy_btn();
	CWinThread* pWinThread2 = AfxBeginThread(VisionThreadStart_ObjectCapture, this);
}
using namespace cv;
//드래그를 통한 캡쳐기능을 구현하기 위해 전역함수와 변수로 선언해주어서 사용한다.
bool mouse_is_pressing = false;
int start_X, start_Y, end_X, end_Y;
int step = 0;
Mat img_color;

void swap(int* v1, int* v2)  //마우스를 눌렀을 떄 x,y의 값을 유동적으로 변할 수 있게 만든  swap함수이다.
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
//추가됨
void mouse_callback(int event, int x, int y, int flags, void* userdata)  //마우스 클릭에 대해서 인지하는 함수를 만듬.
{
	Mat img_result = img_color.clone();

	if (event == EVENT_LBUTTONDOWN)
	{
		step = 1;

		mouse_is_pressing = true;
		start_X = x;
		start_Y = y;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		if (mouse_is_pressing)
		{
			end_X = x;
			end_Y = y;
			step = 2;
		}
	}
	else if (event == EVENT_LBUTTONUP)
	{
		mouse_is_pressing = false;
		end_X = x;
		end_Y = y;

		step = 3;
	}
}
UINT CMy20220401HMYDlg::VisionThreadStart_ObjectCapture(LPVOID pParam)
{
	CMy20220401HMYDlg* line_thread = (CMy20220401HMYDlg*)AfxGetApp()->m_pMainWnd;

	Mat roi;
	double width, height;
	double start_x, start_y, end_x, end_y;
	Mat mat;
	Mat save_img;
	Mat gray_img;
	VideoCapture cap(0);

	width = cap.get(CV_CAP_PROP_FRAME_WIDTH);  //Webcam을 통해 받아온 영상의 가로, 세로의 길이를 알아낸다.
	height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	start_x = width *0.2;
	start_y = height * 0.2;
	end_x = width * 0.8;
	end_y = height * 0.8;

	if (cap.isOpened())
	{
		ㅅ
			namedWindow("Color", 1);
		setMouseCallback("Color", mouse_callback);   //mouse_callback 함수를 추가로 만들어 주어 마우스 클릭 이벤트를 알아채어 드래그를 구현
		while (line_thread->btn_cap)
		{
			cap.read(img_color);
			switch (step)
			{
			case 1:
				circle(img_color, Point(start_X, start_Y), 10, Scalar(0, 255, 0), -1);
				break;
			case 2:
				rectangle(img_color, Point(start_X, start_Y), Point(end_X, end_Y), Scalar(224, 131, 86), 2);
				break;
			case 3:
				if (start_X > end_X)
				{
					swap(&start_X, &end_X);
					swap(&start_Y, &end_Y);
				}
				Mat ROI(img_color, Rect(start_X, start_y, end_X - start_X, end_Y - start_y));  //Mat 형식의 ROI에 각 정보를 저장하고 해당 영역만큼 캡쳐를 수행한다.
				cvtColor(ROI, ROI, COLOR_BGR2GRAY);
				GaussianBlur(ROI, ROI, Size(3, 3), 0);
				string name = "Object_img.jpg";
				imwrite(name, ROI);
				line_thread->GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
				line_thread->GetDlgItem(IDC_Object_Cap_btn)->EnableWindow(false);
				line_thread->OnBnClickedBtnMoveZeroPos();
				line_thread->end_capture_Flag = 1;
				break;
			}
			imshow("Color", img_color);
			if (waitKey(25) >= 0 || line_thread->end_capture_Flag == 1)
				break;
		}
	}
	destroyAllWindows();
	cap.release();
	line_thread->GetDlgItem(IDC_Object_Cap_btn)->EnableWindow(true);
	return 0;
}


UINT CMy20220401HMYDlg::VisionThreadStart_PC(LPVOID pParam) //픽처컨트롤에 진행 상황을 보여주기 위한 함수
{
	CMy20220401HMYDlg* State;
	State = (CMy20220401HMYDlg*)pParam;


	while (1)
	{
		cvGrabFrame(State->capture);
		State->image = cvQueryFrame(State->capture);
		State->m_CvvImage.CopyOf(State->image);
		CRect viewSize;
		State->m_pcstage.GetClientRect(&viewSize);
		State->m_CvvImage.DrawToHDC(State->m_pcstage.GetDC()->GetSafeHdc(), viewSize);
	}

	return 0;
}

void CMy20220401HMYDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.		
	double MovePos[2], MovePos1[2], MovePos2[2], MovePos3[2], MovePos4[2];  //ㄹ형태로 스테이지를 검색하기 위한 배열이다. 총 4번의 움직임이라 4개의 변수 존재. 
																			//또한 AxmLineMove는 파라미터가 double형을 입력받기 때문에 double로 선언하였다.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, 20);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, 20);  //속도를 늦추기 위함.
	MovePos[0] = 199;  //스테이지를 'ㄹ'로 스캔하기 위해 각 x,y 좌표값을 선언해주어 LineMove로 동작한다.
	MovePos[1] = 0;
	MovePos1[0] = 199;
	MovePos1[1] = 100;
	MovePos2[0] = 0;
	MovePos2[1] = 100;
	MovePos3[0] = 0;
	MovePos3[1] = 199;
	MovePos4[0] = 199;
	MovePos4[1] = 199;
	lAXIS[0] = 0;
	lAXIS[1] = 1;
	DWORD StatusX = FALSE, StatusY = FALSE;

	lAxis[0] = 0;
	lAxis[1] = 1;

	AxmContiWriteClear(lCoordinate);
	AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
	AxmContiSetAbsRelMode(lCoordinate, 0);
	AxmContiBeginNode(lCoordinate);
	AxmLineMove(lCoordinate, MovePos,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	AxmLineMove(lCoordinate, MovePos1,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	AxmLineMove(lCoordinate, MovePos2,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	AxmLineMove(lCoordinate, MovePos3,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	AxmLineMove(lCoordinate, MovePos4,
		GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
		GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
		GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
	AxmContiEndNode(lCoordinate);
	AxmContiStart(lCoordinate, 0, 0);
	pWinThread2 = AfxBeginThread(VisionThreadStart_TemplateMathcing, this);
}


UINT CMy20220401HMYDlg::VisionThreadStart_TemplateMathcing(LPVOID pParam)
{
	CMy20220401HMYDlg* TM_ = (CMy20220401HMYDlg*)AfxGetApp()->m_pMainWnd; //TM_이름으로 기존 함수들 끌어오기 위함.
	VideoCapture cap2(0); // access First connected webcam'
	Mat frame2;
	Mat result;
	double minVal, maxVal;
	Point minLoc, maxLoc;
	Point matchLoc;
	Mat img = imread("Object_img.jpg");

	while (char(waitKey(1)) != 'q' && cap2.isOpened())
	{
		cap2 >> frame2; // get a frame from captures
		if (frame2.empty())
		{
			break;
		}

		matchTemplate(frame2, img, result, 3);        //템플릿 매칭을 수행하고 minmaxLoc함수로 값을 뽑아낸 다음 가장 이상적인 값인  0.92를 조건으로 객체를 찾아낸다.
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		printf("minva : %.2f, maxval : %.2f\n", minVal, (maxVal));
		if (maxVal > 0.92)
		{
			rectangle(frame2, minLoc, Point(minLoc.x + img.cols, minLoc.y + img.rows), Scalar(0, 0, 0, 0), 1);
			TM_->OnBnClickedBtnXEstop();
			TM_->OnBnClickedBtnYEstop();
			imshow("Video", frame2);
			TM_->detect_object = true;
			TM_->MessageBox("객체를 찾았습니다!");
			TM_->pWinThread2 = NULL;
			break;
		}
		imshow("Video", frame2);
		if (char(waitKey(1) == 'q'))
		{
			break;
		}
	}
	destroyAllWindows();
	cap2.release();
	if (TM_->detect_object)  //객체를 찾았을 경우 원점으로 + JOY 버튼 비활성화
	{
		TM_->OnBnClickedBtnMoveZeroPos();
		TM_->default_joy_btn();
	}

	return 0;
}

void CMy20220401HMYDlg::OnBnClickedButton1() //위
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);///  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	//  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.

	if (pos_move_up[0] < 199)
	{
		pos_move_up[0] += 10;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,           //AxmLineMove함수를 사용해 원하는 동작을 진행.
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);

	}
	else if (pos_move_up[0] >= 199)                      //영역 밖의 이동시 경고 알림
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
}


void CMy20220401HMYDlg::OnBnClickedButton6() //아래
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	if (pos_move_up < 0)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
	else if (pos_move_up > 0)
	{
		pos_move_up[0] -= 10;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);
	}
}


void CMy20220401HMYDlg::OnBnClickedButton5() //오른쪽
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_right[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_right[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	if (pos_move_right[1] < 199)
	{
		pos_move_right[1] += 10;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_right,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);

	}
	else if (pos_move_right[1] >= 199)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
}


void CMy20220401HMYDlg::OnBnClickedButton4()//왼쪽
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_right[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_right[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	if (pos_move_right[1] < 0)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
	else if (pos_move_right[1] > 0)
	{
		pos_move_right[1] -= 10;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_right,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);
	}

}


void CMy20220401HMYDlg::OnBnClickedButton3()//스탑
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy20220401HMYDlg::OnBnClickedButton7()//우상향 대각선
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.

	if (pos_move_up[0] < 199)
	{
		pos_move_up[0] += 20;
		pos_move_up[1] += 20;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);

	}
	else if (pos_move_up[0] >= 199)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
}


void CMy20220401HMYDlg::OnBnClickedButton8()//좌상향대각선
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.

	if (pos_move_up < 0)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
	else if (pos_move_up > 0)
	{
		pos_move_up[0] += 20;
		pos_move_up[1] -= 20;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);
	}

}


void CMy20220401HMYDlg::OnBnClickedButton9()//좌하향대각선
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	if (pos_move_up < 0)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}
	else if (pos_move_up > 0)
	{
		pos_move_up[0] -= 20;
		pos_move_up[1] -= 20;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);
	}
}


void CMy20220401HMYDlg::OnBnClickedButton10()//우하향대각선
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AxmStatusGetActPos(0, &pos_move_up[0]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	AxmStatusGetActPos(1, &pos_move_up[1]);	////  X축위 현재 위치값을 받아와 dreal_posX에 저장해준다.
	if (pos_move_up[0] < 199)
	{
		pos_move_up[0] -= 20;
		pos_move_up[1] += 20;
		lAxis[0] = 0;
		lAxis[1] = 1;
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		AxmLineMove(lCoordinate, pos_move_up,
			GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
			GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
			GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);

	}
	else if (pos_move_up[0] >= 199)
	{
		AfxMessageBox("ERROR : 범위 밖의 입력입니다.!");
	}

}
void CMy20220401HMYDlg::default_joy_btn()    //joy 버튼 9개를 Off하는 함수
{
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(false);

}
void CMy20220401HMYDlg::on_joy_btn()   //joy 버튼 9개를 On하는 함수
{
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(true);
}

void CMy20220401HMYDlg::RESULT_BTN_OFF()   //결과 버튼 3개를 able하는 함수
{
	GetDlgItem(IDC_BUTTON11)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(false);
}
void CMy20220401HMYDlg::RESULT_BTN_ON()    //결과 버튼 3개를 Disable하는 함수
{
	GetDlgItem(IDC_BUTTON11)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(true);
}

void CAboutDlg::OnEnChangeEdit1()  //초반에 사용자 이름을 입력하고 아무것도 입력하지 않으면 못넘어 가도록 하는 다이얼로그 함수
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy20220401HMYDlg::OnBnClickedButton11() //정상검출
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	correct_detection++;
	RESULT_BTN_OFF();
}


void CMy20220401HMYDlg::OnBnClickedButton12() //오검출 : 객체를 잘못 판단하는 경우
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	false_detection++;
	RESULT_BTN_OFF();
}


void CMy20220401HMYDlg::OnBnClickedButton13() //배경검출 - total error : 시작하자마자 배경을 보고 객체를 찾았다고 하는 경우
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	error_detection++;
	RESULT_BTN_OFF();
}


void CAboutDlg::OnBnClickedOk()    //시작할 때 사용자 이름을 입력하고 "확인" 버튼을 누르게 되면 Cstring 형으로 문자열이 저장된다.
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMy20220401HMYDlg* send_name = (CMy20220401HMYDlg*)AfxGetApp()->m_pMainWnd;
	CString str;
	User_name.GetWindowTextA(str);
	send_name->user_name = str;
	CDialogEx::OnOK();
}
