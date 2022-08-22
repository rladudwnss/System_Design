
// 20220401HMYDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20220401HMY.h"
#include "20220401HMYDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ++ =============================================================
// >> AXL(AjineXtek Library) ���� Header���� ���Խ�ŵ�ϴ�.
// �� [CAUTION] ������ �����Ͽ� �ٸ� ��ġ���� ����� ������� ������ �ʿ��մϴ�.
// ---------------------------------------------------------------
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXL.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXM.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXDev.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXHS.h"
// ++ =============================================================
// >> AXL(AjineXtek Library) ���� Library������ Link��ŵ�ϴ�.
// �� [CAUTION] ������ �����Ͽ� �ٸ� ��ġ���� ����� ������� ������ �ʿ��մϴ�.
// ----------------------------------------------------------------
#ifdef _M_X64
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/64Bit/AxL.lib")
#else
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/32Bit/AxL.lib")
#endif





// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeUserNameInput();
	//	CString user_name_input;
	afx_msg void OnBnClickedOk();
	CString user_name_input;
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
, user_name_input(_T(""))
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_USER_NAME_INPUT, user_name_input);
	DDX_Text(pDX, IDC_USER_NAME_INPUT, user_name_input);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_EN_CHANGE(IDC_USER_NAME_INPUT, &CAboutDlg::OnEnChangeUserNameInput)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMy20220401HMYDlg ��ȭ ����



CMy20220401HMYDlg::CMy20220401HMYDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy20220401HMYDlg::IDD, pParent)
	, rose_3leaf(FALSE)
	, rose_4leaf(FALSE)
	, rose_5leaf(FALSE)
	, rose_7leaf(FALSE)
	, rose_8leaf(FALSE)
	, m_combo_str(_T(""))
	, fast_mode(TRUE)
	, slow_mode(FALSE)
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
	DDX_Control(pDX, IDC_COMBO2, m_combo_control);
	DDX_CBString(pDX, IDC_COMBO2, m_combo_str);
	DDX_Control(pDX, IDC_EDIT_SIZE_INPUT, inputsize);
	DDX_Control(pDX, IDC_BUTTON1, leaf_input_btn);
	DDX_Radio(pDX, IDC_RADIO_OLD, slow_mode);
	DDX_Radio(pDX, IDC_RADIO3, fast_mode);
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
	ON_BN_CLICKED(IDC_RADIO1, &CMy20220401HMYDlg::OnBnClickedRadio1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMy20220401HMYDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy20220401HMYDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RADIO3, &CMy20220401HMYDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO_OLD, &CMy20220401HMYDlg::OnBnClickedRadioOld)
END_MESSAGE_MAP()


// CMy20220401HMYDlg �޽��� ó����

BOOL CMy20220401HMYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	//ASSERT(IDM_ABOUTBOX < 0xF000);

	//CMenu* pSysMenu = GetSystemMenu(FALSE);
	//if (pSysMenu != NULL)
	//{
	//	BOOL bNameValid;
	//	CString strAboutMenu;
	//	bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
	//	ASSERT(bNameValid);
	//	if (!strAboutMenu.IsEmpty())
	//	{
	//		pSysMenu->AppendMenu(MF_SEPARATOR);
	//		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	//	}
	//}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//leaf_input_btn.LoadBitmaps(IDB_BITMAP2, NULL, NULL, NULL);
	//leaf_input_btn.SizeToContent();
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
	InitState();
	button_disable();
	m_hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP5));
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy20220401HMYDlg::OnPaint()
{
	CString strPosX, strPosY, strEndPos;

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);


	}
	else
	{
		CDialogEx::OnPaint();
		CClientDC dc(this);
		CRect rect;
		GetWindowRect(&rect);
		//��� �̹��� �ҷ�����
		HDC hMemDC = CreateCompatibleDC(dc);
		SetStretchBltMode(hMemDC, HALFTONE);
		SelectObject(hMemDC, m_hBitmap);
		StretchBlt(dc, 430, 100, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth + 220, m_bitmap.bmHeight + 180, SRCCOPY);
		DeleteDC(hMemDC);

		// XY Stage ����� �׸��ϴ�.
		dc.Rectangle(&m_rectStage);

		// XY Stage�� ���� ���鿡�� MARGIN����ŭ ������ ��ġ�� Y�� ���ؼ��� �׸��ϴ�.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN);
		dc.LineTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);

		// XY Stage�� �ϴ� ���鿡�� MARGIN����ŭ ������ ��ġ�� X�� ���ؼ��� �׸��ϴ�.
		dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);
		dc.LineTo(m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

		// �� ���� ������(0,0)�� ǥ���մϴ�.
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.bottom - MARGIN + 5, "(0, 0)");

		// X���� �� ����(?, 0)�� ǥ���մϴ�.
		strEndPos.Format("(%d, 0)", (int)((double)((m_rectStage.right - m_rectStage.left) -
			(MARGIN * 2)) * m_posRevisionX));
		dc.TextOut(m_rectStage.right - MARGIN - 30, m_rectStage.bottom - MARGIN + 5,
			strEndPos);

		// Y���� �� ����(0, ?)�� ǥ���մϴ�.
		strEndPos.Format("(0, %d)", (int)((double)((m_rectStage.bottom - m_rectStage.top)
			- (MARGIN * 2)) * m_posRevisionY));
		dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.top + MARGIN - 20,
			strEndPos);

		//������������ƹ� ������ Ŭ������ �ʰ� �⺻ Ŭ������ �ش� ��ǥ�� �̵��ϴ� �ڵ�//������������
		if (!btn_ptp && !btn_cp && !btn_rose && One_click_flag)
		{
			// point ��ġ�� ��Ÿ���� ���� �簢���� �׸��ϴ�. Y��ǥ�� ���� ������ �����մϴ�.
			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) -
				m_pointY;
			dc.Rectangle((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
				MARGIN + iNewPointY) + 5,
				(m_rectStage.left + MARGIN + m_pointX) - 5, (m_rectStage.top + MARGIN +
					iNewPointY) - 5);

			// ������ ��ġ ���� �ϴܿ� �۰� ��ǥ�� ǥ���մϴ�.
			strPosX.Format("X:%d", m_realPointX);
			strPosY.Format("Y:%d", m_realPointY);
			if (default_click_flag == true)
			{
				dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
					MARGIN + iNewPointY) + 5, strPosX);
				dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +
					MARGIN + iNewPointY) + 20, strPosY);
			}

			One_click_flag = 0;

		}
		//������������Lbuttondown�� ���� ���� ��ǥ�� �ص� ������ �׷��ִ� �κ�//������������
		else if (ptp_start_flag)
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
					dc.MoveTo(m_rectStage.left + MARGIN + ptp_points[i][0], m_rectStage.top + MARGIN + iNewPointRectY[i]);		/////  ���� �������� Ư����ġ�� �̵�
					dc.LineTo(m_rectStage.left + MARGIN + ptp_points[i + 1][0], m_rectStage.top + MARGIN + iNewPointRectY[i + 1]);	/////  �̵��� Ư����ġ���� ������ �������� �� �׸�
				}
			}
			//AfxMessageBox("����!");
		}
		else if (cp_start_flag)
		{
			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - cp_points[1];

			dc.Ellipse((m_rectStage.left + MARGIN + cp_points[0]) - cp_radious, (m_rectStage.top + MARGIN + iNewPointY) - cp_radious,
				(m_rectStage.left + MARGIN + cp_points[0]) + cp_radious, (m_rectStage.top + MARGIN + iNewPointY) + cp_radious);
			dc.Rectangle((m_rectStage.left + MARGIN + cp_points[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5,
				(m_rectStage.left + MARGIN + cp_points[0]) - 5, (m_rectStage.top + MARGIN + iNewPointY) - 5);

			strPosX.Format("X:%d", (int)(m_pointX * m_posRevisionX));
			strPosY.Format("Y:%d", (int)(m_pointY * m_posRevisionY));
			dc.TextOut((m_rectStage.left + MARGIN + cp_points[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5, strPosX);
			dc.TextOut((m_rectStage.left + MARGIN + cp_points[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 20, strPosY);
		}
		//���������������� �׷��ִ� �κ�//������������
		//���������������� ������ ���� 180��, 360���� �ٸ��� ������ �ΰ��� ���ǹ��� �ְ� ������ ���Ŀ� ���� ���� �׷�����//������������
		else if (btn_rose)
		{
			if (rose_start_flag == true)
			{
				int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - cp_points[1];
				if (leaf_cnt % 2 == 1)  //Ȧ�� -> 3,5,7��
				{
					for (double i = 0; i < THETA_2; i += 0.01)
					{
						dc.MoveTo(m_rectStage.left + MARGIN + cp_points[0] + leaf_size_num * cos(leaf_cnt * i) * cos(i), m_rectStage.top + MARGIN + iNewPointY + leaf_size_num * cos(leaf_cnt * i) * sin(i));		/////  ���� �������� Ư����ġ�� �̵�
						dc.LineTo(m_rectStage.left + MARGIN + cp_points[0] + leaf_size_num * cos(leaf_cnt * (i + 0.01)) * cos(i + 0.01), m_rectStage.top + MARGIN + iNewPointY + leaf_size_num * cos(leaf_cnt * (i + 0.01)) * sin(i + 0.01));	/////  �̵��� Ư����ġ���� ������ �������� �� �׸�

					}

				}
				else if (leaf_cnt % 2 == 0)  //¦�� -> 4, 8��
				{
					for (double i = 0; i < THETA; i += 0.01)
					{
						dc.MoveTo(m_rectStage.left + MARGIN + cp_points[0] + leaf_size_num * cos(leaf_cnt * i) * cos(i), m_rectStage.top + MARGIN + iNewPointY + leaf_size_num * cos(leaf_cnt * i) * sin(i));		/////  ���� �������� Ư����ġ�� �̵�
						dc.LineTo(m_rectStage.left + MARGIN + cp_points[0] + leaf_size_num * cos(leaf_cnt * (i + 0.01)) * cos(i + 0.01), m_rectStage.top + MARGIN + iNewPointY + leaf_size_num * cos(leaf_cnt * (i + 0.01)) * sin(i + 0.01));	/////  �̵��� Ư����ġ���� ������ �������� �� �׸�

					}
				}
				dc.Rectangle((m_rectStage.left + MARGIN + cp_points[0]) + 2, (m_rectStage.top + MARGIN + iNewPointY) + 2,
					(m_rectStage.left + MARGIN + cp_points[0]) - 2, (m_rectStage.top + MARGIN + iNewPointY) - 2);
				strPosX.Format("X:%d", (int)(rose_point_X * m_posRevisionX));
				strPosY.Format("Y:%d", (int)(rose_point_Y * m_posRevisionY));
				dc.TextOut((m_rectStage.left + MARGIN + cp_points[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5, strPosX);
				dc.TextOut((m_rectStage.left + MARGIN + cp_points[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 20, strPosY);

				rose_start_flag = false;
			}
		}
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy20220401HMYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20220401HMYDlg::OnBnClickedChkXServoOn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_X_SERVO_ON);
	// ���� ���� Servo On/Off ��ȣ�� ����մϴ�.
	dwRetCode = AxmSignalServoOn(m_lAxisNoX, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnXAlarmClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// X���� Servo Off�̸� �� �۾��� �������� �ʽ��ϴ�.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// X���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// - �� ���� ������ AXM �Ŵ����� �����Ͻñ� �ٶ��ϴ�.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXStop = FALSE;

	// Edit control���� �ӵ�, ���ӵ� ���� �޾ƿɴϴ�.
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
	// �����˻��� ���Ǵ� �˻������ �����մϴ�.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoX, DIR_CCW, Signal_HomeSensor,
		UNUSED, 1000, 0);

	// �����˻��� ���Ǵ� �ܰ躰 �ӵ��� �����մϴ�.
	dwRetCode = AxmHomeSetVel(m_lAxisNoX, dHomeVelFirst, dHomeVelSecond,
		dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// X�� �����˻��� �����մϴ�.
	m_prgXHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoX);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult);
		m_prgXHomeRate.EnableWindow(FALSE);
		return;
	}
	// ���� �˻� ���� ��Ȳ�� ǥ���� Ÿ�̸Ӹ� �����մϴ�.
	m_bXIsMoving = TRUE;
	SetTimer(TM_X_HOME_INFO, 200, NULL); // ������ �ֱ�� ����Ǵ� �����˻� ���������� Control�� �ݿ��� Ÿ�̸Ӹ� �����մϴ�. 
}


void CMy20220401HMYDlg::OnBnClickedBtnXPosClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode;
	CString strResult;

	// Command��ġ�� Actual��ġ�� ������ ������ �����մϴ�.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoX, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnXSstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveSStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;

}


void CMy20220401HMYDlg::OnBnClickedBtnXEstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveEStop(m_lAxisNoX);
	m_bXIsMoving = FALSE;
	m_bXStop = TRUE;

}


void CMy20220401HMYDlg::OnBnClickedChkYServoOn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_Y_SERVO_ON);
	// ���� ���� Servo On/Off ��ȣ�� ����մϴ�.
	dwRetCode = AxmSignalServoOn(m_lAxisNoY, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnYAlarmClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// Y���� Servo Off�̸� �� �۾��� �������� �ʽ��ϴ�.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// Y���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
	// - �� ���� ������ AXM �Ŵ����� �����Ͻñ� �ٶ��ϴ�.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bYStop = FALSE;

	// Edit control���� �ӵ�, ���ӵ� ���� �޾ƿɴϴ�.
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

	// �����˻��� ���Ǵ� �˻������ �����մϴ�.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoY, DIR_CCW, Signal_HomeSensor,
		UNUSED, 1000, 0);

	// �����˻��� ���Ǵ� �ܰ躰 �ӵ��� �����մϴ�.
	dwRetCode = AxmHomeSetVel(m_lAxisNoY, dHomeVelFirst, dHomeVelSecond,
		dHomeVelThird, dHomeVelLast,
		dHomeAccFirst, dHomeAccSecond);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// Y�� �����˻��� �����մϴ�.
	m_prgYHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoY);
	if (dwRetCode != AXT_RT_SUCCESS) {
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home search fail.\nError Msg : " + strResult);
		m_prgYHomeRate.EnableWindow(FALSE);
		return;
	}

	// ���� �˻� ���� ��Ȳ�� ǥ���� Ÿ�̸Ӹ� �����մϴ�.
	m_bYIsMoving = TRUE;
	SetTimer(TM_Y_HOME_INFO, 200, NULL); // ������ �ֱ�� ����Ǵ� �����˻� ���������� Control�� �ݿ��� Ÿ�̸Ӹ� �����մϴ�. 
}


void CMy20220401HMYDlg::OnBnClickedBtnYPosClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwRetCode;
	CString strResult;
	// Command��ġ�� Actual��ġ�� ������ ������ �����մϴ�.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoY, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	}
}


void CMy20220401HMYDlg::OnBnClickedBtnYSstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveSStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy20220401HMYDlg::OnBnClickedBtnYEstop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AxmMoveEStop(m_lAxisNoY);
	m_bYIsMoving = FALSE;
	m_bYStop = TRUE;
}


void CMy20220401HMYDlg::OnBnClickedBtnLoadFile()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString temp;
	CFileDialog dlg(TRUE, "Mot", NULL, OFN_HIDEREADONLY, "AXM File (*.mot)|*.mot|AllFiles (*.*)|*.*||");

	if (dlg.DoModal() == IDOK) {
		LPTSTR strFilename;
		temp = dlg.GetPathName();
		strFilename = temp.GetBuffer(0);

		// �Լ� ���� ������ ������ Mot������ ���������� ����� ������ �ϰ� ����˴ϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch();
}


void CMy20220401HMYDlg::OnBnClickedBtnMoveZeroPos()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double dPosX = 0.0, dPosY = 0.0;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	// (0, 0) ��ǥ�� �̵��մϴ�. 
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;
	Invalidate();
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// �� �࿡ ���� ESTOP ����� �����մϴ�.
	OnBnClickedBtnXEstop();
	OnBnClickedBtnYEstop();
}


void CMy20220401HMYDlg::OnBnClickedBtnPosMove()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strMovePosX, strMovePosY, strMsg;
	int iMovePosX, iMovePosY, iLimitPosX, iLimitPosY;
	double dPosX, dPosY;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	// XY Stage���� �̵� �Ѱ����� ����մϴ�.
	iLimitPosX = (int)((m_rectStage.right - m_rectStage.left - (MARGIN * 2)) *
		m_posRevisionX);
	iLimitPosY = (int)((m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) *
		m_posRevisionX);

	// Edit Control���� �Է� ��ǥ ���� �޾ƿɴϴ�.
	m_edtXMovePos.GetWindowText(strMovePosX);
	strMovePosX = strMovePosX.Trim();
	iMovePosX = atoi(strMovePosX);
	// �Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosX < 0 || iMovePosX > iLimitPosX)
	{
		strMsg.Format("��ȿ�� X��ǥ ���� �Է��ϼ���. (�Է¹��� : 0 ~ %d)", iLimitPosX);
		AfxMessageBox(strMsg);
		return;
	}

	m_editYMovePos.GetWindowText(strMovePosY);
	strMovePosY = strMovePosY.Trim();
	iMovePosY = atoi(strMovePosY);
	// �Է¹��� ��ǥ�� XY Stage�� ��� ��ǥ�̸� ���� �˾��� ����ϰ� �̵����� �ʽ��ϴ�.
	if (iMovePosY < 0 || iMovePosY > iLimitPosY)
	{
		strMsg.Format("��ȿ�� Y��ǥ ���� �Է��ϼ���. (�Է¹��� : 0 ~ %d)", iLimitPosY);
		AfxMessageBox(strMsg);
		return;
	}

	// �ش� ��ǥ�� �̵��մϴ�.
	m_pointX = (int)((double)iMovePosX / (m_posRevisionX));
	m_pointY = (int)((double)iMovePosY / (m_posRevisionY));
	Invalidate();
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

//���������������� ��ư�� ������  Ok�� ������ �������� ���ư��� ���α׷��� ����ȴ�. No�� �������� �������� �Ȱ���.
void CMy20220401HMYDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// "���� �Ͻðڽ��ϱ�?" Ȯ�� �˾� â�� ����Ͽ� ���� ���θ� �� �� �� Ȯ���մϴ�.
	if (AfxMessageBox("���� �Ͻðڽ��ϱ�?", MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}
	else
	{
		OnBnClickedBtnXHomeSearch();
		OnBnClickedBtnYHomeSearch();
		AfxMessageBox("�ȳ���������");
	}
	CDialogEx::OnClose();
}




void CMy20220401HMYDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// ���� ó���� ���Ͽ� AXL ���̺귯���� ���� ������ �ݽ��ϴ�.
	if (AxlIsOpened())
	{
		AxlClose();
	}
}


void CMy20220401HMYDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	double dPosX = 0.0;
	// �� �̺�Ʈ���� ���������� �ڵ�ȣ��Ǵ� �̺�Ʈ���� �۾��� �����մϴ�.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// X���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion(..) : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
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
	Invalidate();

	UpdateData(TRUE);

	dPosX = m_pointX * m_posRevisionX;
	m_realPointX = (int)dPosX;

	// �̵� �������� �� Edit Control���� �о�ɴϴ�.
	dVel = GetDlgItemDouble(IDC_EDT_X_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_X_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_X_INPUT_DEC);
	// Absolute ��ǥ�� �̵����� �����մϴ�.
	AxmMotSetAbsRelMode(m_lAxisNoX, POS_ABS_MODE);

	// �̵��� �����մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dPosX = 0.0, dPosY = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	if (m_bXIsMoving || m_bYIsMoving)
	{
		return;
	}

	// ���� �Ǵ�
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
		AfxMessageBox("ǥ���� �� ���� ��ġ�Դϴ�.");
	}
	else if (Set_Cursor == 2)
	{
		//�����������ᰢ �÷��׿� ���� ������ �޶���.
		if (!btn_ptp && !btn_cp && !btn_rose)  //Ŭ���� ��ǥ�� ���������� �̵��ϴ� �κ�.
		{
			Invalidate();
			One_click_flag = true;
			m_pointX = point.x - (m_rectStage.left + MARGIN);
			// Y��ǥ�踦 ���� �����Ͽ� �����մϴ�.
			m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
				(m_rectStage.top + MARGIN));

			Invalidate();
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(nSliderEndPosY - m_pointY);
			default_click_flag = true;
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
			r_point_x = (int)dPosX;
			r_point_y = (int)dPosY;
		}
		else if (btn_ptp) //���� ���� �κ�
		{
			ptp_start_flag = true;
			ptp_points[ptp_click_count][0] = point.x - (m_rectStage.left + MARGIN);
			ptp_points[ptp_click_count][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));

			Invalidate();
			m_sliX.SetPos(ptp_points[ptp_click_count][0]);
			m_sliY.SetPos(nSliderEndPosY - ptp_points[ptp_click_count][1]);  //////  �� �κ� ���� y��ǥ�踦 ���� �����Ͽ� ����

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
		else if (btn_cp) //�� �׷��ִ� �κ�.
		{
			if (point.x >= rect2.left + 35 && point.x <= rect2.right - 35)
			{
				if (point.y <= rect2.bottom - 35 && point.y >= rect2.top + 35)
				{
					cp_start_flag = true;
					lAxis[0] = 0;
					lAxis[1] = 1;
					m_pointX = point.x - (m_rectStage.left + MARGIN);
					// Y��ǥ�踦 ���� �����Ͽ� �����մϴ�.
					m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
						(m_rectStage.top + MARGIN));

					m_sliX.SetPos(m_pointX);
					m_sliY.SetPos(nSliderEndPosY - m_pointY);

					cp_points[0] = m_pointX;
					cp_points[1] = m_pointY;

					Invalidate();
					UpdateWindow();
					AxmContiWriteClear(lCoordinate);
					AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
					AxmContiSetAbsRelMode(lCoordinate, 0);
					AxmContiBeginNode(lCoordinate);

					for (int i = 0; i < 360; i++)
					{
						dPos[0] = (m_pointX + cos(i * (PI / 180)) * cp_radious) * m_posRevisionX;
						dPos[1] = (m_pointY + sin(i * (PI / 180)) * cp_radious) * m_posRevisionY;
						if (i == 0)
						{
							cp_start[0] = dPos[0];
							cp_start[1] = dPos[1];
						}

						AxmLineMove(lCoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
					}
					pWinThread = AfxBeginThread(ThreadStart, this);
					AxmContiEndNode(lCoordinate);
					AxmContiStart(lCoordinate, 0, 0);
					r_point_x = (int)m_pointX;
					r_point_y = (int)m_pointY;
					return;
				}
				else
				{
					AfxMessageBox("���� �� �Դϴ�.");
				}

			}
			else
			{
				AfxMessageBox("���� �� �Դϴ�.");
			}

		}
		else if (btn_rose)  //���� �׸��� �κ�. �� ������� MAX150,MIN50�̴�.
		{
			if (leaf_size_num <= 150 && leaf_size_num >= 50)
			{
				if (point.x >= rect2.left + leaf_size_num + 5 && point.x <= rect2.right - leaf_size_num)  //�Է¹��� ���� ������ + 5���־�� ���������� �� �׷�����.
				{
					if (point.y <= rect2.bottom - leaf_size_num + 5 && point.y >= rect2.top + leaf_size_num + 5)
					{
						//AfxMessageBox("����");
						draw_rose(point, nSliderEndPosY);
					}
					else
					{
						AfxMessageBox("���� �� �Դϴ�.");
					}

				}
				else
				{
					AfxMessageBox("���� �� �Դϴ�.");
				}
			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMy20220401HMYDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dXCommPos = 0.0, dXFeedPos = 0.0, dXFeedVel = 0.0;
	double dYCommPos = 0.0, dYFeedPos = 0.0, dYFeedVel = 0.0;
	DWORD dwRetCode = 0, dwValue = 0, dwStepMain = 0, dwStepSub = 0;
	WORD wGainP = 0, wGainI = 0, wGainD = 0;
	long lCheck = 0;
	CString strResult;
	CString strGainXP, strGainXI, strGainXD, strGainYP, strGainYI, strGainYD;

	switch (nIDEvent) {
	case TM_DISPLAY:
		// X, Y���� ����(Command)��ġ�� ��ȯ�մϴ�.
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

		// X, Y���� ����(Feedback)��ġ�� ��ȯ�մϴ�.
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

		// X, Y���� ���� �ӵ��� ��ȯ�մϴ�.
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

		// X�� �ܺ� ���� �� ���� ���� ��ȣ���� ���¸� �����ɴϴ�.
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
			// �̵� ���̸� �̵� ���� ��Ʈ���� ��Ȱ��ȭ�ϰ�, �̵��� �����ϸ� Ȱ��ȭ�մϴ�.
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

		// X���� P ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainXP.Format("%d", (wGainP / 10));
		m_stcXP.SetWindowText(strGainXP);

		// X���� D ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainXD.Format("%d", (wGainD / 10));
		m_stcXD.SetWindowText(strGainXD);

		// X���� I ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX, GAIN_MAIN_ADDRESS_I,
			GAIN_SUB_ADDRESS, &wGainI);
		strGainXI.Format("%d", (wGainI / 10));
		m_stcXI.SetWindowText(strGainXI);

		// Y�� �ܺ� ���� �� ���� ���� ��ȣ���� ���¸� �����ɴϴ�.
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
			// �̵� ���̸� �̵� ���� ��Ʈ���� ��Ȱ��ȭ�ϰ�, �̵��� �����ϸ� Ȱ��ȭ�մϴ�.
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

		// Y���� P ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
		strGainYP.Format("%d", (wGainP / 10));
		m_stcYP.SetWindowText(strGainYP);

		// Y���� D ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
			GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
		strGainYD.Format("%d", (wGainD / 10));
		m_stcYD.SetWindowText(strGainYD);

		// Y���� I ���� Ʃ�װ��� ǥ���մϴ�.
		dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY, GAIN_MAIN_ADDRESS_I,
			GAIN_SUB_ADDRESS, &wGainI);
		strGainYI.Format("%d", (wGainI / 10));
		m_stcYI.SetWindowText(strGainYI);

		// X��� Y���� �̵��� ����Ǹ� ��ǥ�̵� ��ư�� Ȱ��ȭ
		if ((m_btnPosMove.IsWindowEnabled() == FALSE) && (m_bXIsMoving == FALSE) &&
			(m_bYIsMoving == FALSE))
		{
			m_btnPosMove.EnableWindow(TRUE);

			// ���� ��ġ�� �������� ��ǥ�� �̵��մϴ�.
			m_pointX = (int)(dXFeedPos / m_posRevisionX);
			m_pointY = (int)(dYFeedPos / m_posRevisionY);
			m_realPointX = (int)(dXFeedPos);
			m_realPointY = (int)(dYFeedPos);
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(m_sliY.GetRangeMax() - m_pointY);
			Invalidate();
		}

		break;

	case TM_X_HOME_INFO:
		// ��� ������ ������ ���� ó���� �մϴ�.
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

		// X���� �����˻� �������� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetRate(m_lAxisNoX, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgXHomeRate.SetPos(dwStepSub);
		}

		// X���� �����˻� ����� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetResult(m_lAxisNoX, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// ���� �˻� �۾��� ���������� �����Կ� ���� �ļ� ó���� �մϴ�.
				m_prgXHomeRate.EnableWindow(FALSE);
				m_bXIsMoving = FALSE;
				KillTimer(TM_X_HOME_INFO);
				AfxMessageBox("X�� ���� ���� �Ϸ�");
				button_enable();
			}
		}
		else
		{
			// ���� �˻� �۾��� ������������ �����Կ� ���� �ļ� ó���� �մϴ�.
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
		// ��� ������ ������ ���� ó���� �մϴ�.
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

		// Y���� �����˻� �������� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetRate(m_lAxisNoY, &dwStepMain, &dwStepSub);
		if (dwRetCode == AXT_RT_SUCCESS) {
			m_prgYHomeRate.SetPos(dwStepSub);
		}

		// Y���� �����˻� ����� Ȯ���մϴ�.
		dwRetCode = AxmHomeGetResult(m_lAxisNoY, &dwValue);
		if (dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
			(dwValue == HOME_SEARCHING)))
		{
			if (dwValue == HOME_SUCCESS)
			{
				// ���� �˻� �۾��� ���������� �����Կ� ���� �ļ� ó���� �մϴ�.
				m_prgYHomeRate.EnableWindow(FALSE);
				m_bYIsMoving = FALSE;
				KillTimer(TM_Y_HOME_INFO);
				AfxMessageBox("Y�� ���� ���� �Ϸ�.");
				button_enable();
			}
		}
		else
		{
			// ���� �˻� �۾��� ������������ �����Կ� ���� �ļ� ó���� �մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	double dPosY = 0.0;
	int nSliderEndPosY = pSlider->GetRangeMax();

	// �� �̺�Ʈ���� ���������� �ڵ�ȣ��Ǵ� �̺�Ʈ���� �۾��� �����մϴ�.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}
	// Y���� ���� ���̸� �� �۾��� �������� �ʽ��ϴ�.
	// AxmStatusReadMotion(..) : ���� ���� ��� ���� ���� ���� ��ȯ�մϴ�.
	// - dwStatus ��Ʈ���� �ǹ� : (0x00000001) 0 bit. ����̺� ���� ��
	// (0x00000002) 1 bit. ���� ��
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

	// �̵� �������� �� Edit Control���� �о�ɴϴ�.
	dVel = GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC);

	// Absolute ��ǥ�� �̵����� �����մϴ�.
	AxmMotSetAbsRelMode(m_lAxisNoY, POS_ABS_MODE);

	// �̵��� �����մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CDialogEx::PreTranslateMessage(pMsg);

	// EscŰ �Է¿� ���� ó���� �մϴ�.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
		&& (pMsg->wParam == VK_ESCAPE))
	{
		// �� �࿡ ���� ESTOP ����� �����մϴ�. 
		OnBnClickedBtnBothEstop();

		return TRUE;
	}

	// EnterŰ �Է¿� ���� ó���� �մϴ�.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))
		&& (pMsg->wParam == VK_RETURN))
	{
		// �ƹ� �͵� �������� �ʽ��ϴ�.
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}




BOOL CMy20220401HMYDlg::InitState()
{
	//��� ���� �ʱ�ȭ'

	btn_ptp = false;
	btn_cp = false;
	btn_rose = false;
	ptp_click_count = 0;
	rose_click_count = 0;
	lPosSize = 2;
	rose_PoseSize = 4;
	cp_radious = 30;
	// AXL ���� �ʱ�ȭ
	long lAxisCount = 0;
	DWORD dwRetCode = 0;
	long lPulse = 0;
	CString strResult;
	int nSliderEndPosX, nSliderEndPosY;
	//�������������޺��ڽ� ����Ʈ �߰�//������������
	m_combo_control.AddString(_T("3"));
	m_combo_control.AddString(_T("4"));
	m_combo_control.AddString(_T("5"));
	m_combo_control.AddString(_T("7"));
	m_combo_control.AddString(_T("8"));

	//������������rose leaf combo box �����. �ʱ⿡�� ������ �� ������
	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(FALSE);
	// AXL �ʱ�ȭ
	if ((AxlIsOpened() == FALSE))
	{
		if (AxlOpenNoReset(7) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("AxlOpen Fail");
			return FALSE;
		}
	}

	// ���� ���忡�� �ν��� �� �ִ� �ִ� ����� 2�� �̻��� �ƴϸ� ������ ����մϴ�.
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

	// X��� Y���� ��ȣ�� ���Ƿ� �����մϴ�.
	m_lAxisNoX = DEFAULT_AXIS_NUMBER_X;
	m_lAxisNoY = DEFAULT_AXIS_NUMBER_Y;

	// ��ǥ�� �ʱ�ȭ�մϴ�.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;

	// ������� �ʴ� Emergency ��ȣ�� UNUSED�� ����
	dwRetCode = AxmSignalSetStop(m_lAxisNoX, EMERGENCY_STOP, UNUSED);
	dwRetCode = AxmSignalSetStop(m_lAxisNoY, EMERGENCY_STOP, UNUSED);

	// Limit Level�� LOW�� �����մϴ�.
	dwRetCode = AxmSignalSetLimit(m_lAxisNoX, EMERGENCY_STOP, LOW, LOW);
	dwRetCode = AxmSignalSetLimit(m_lAxisNoY, EMERGENCY_STOP, LOW, LOW);

	// Unit Per Pulse�� 10:1048576���� �����մϴ�.
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoX, 10, 1048576);
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoY, 10, 1048576);

	// Edit Contorl�� �ʱⰪ�� �����մϴ�.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_DEC, DEFAULT_DEC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_DEC, DEFAULT_DEC, 1);
	m_edtXMovePos.SetWindowText("0");
	m_editYMovePos.SetWindowText("0");

	// �����˻� �������� ǥ���� ���α׷����ٸ� �ʱ�ȭ�մϴ�.
	m_prgXHomeRate.SetRange(0, 100);
	m_prgXHomeRate.SetStep(1);
	m_prgXHomeRate.SetPos(0);
	m_prgXHomeRate.EnableWindow(FALSE);
	m_prgYHomeRate.SetRange(0, 100);
	m_prgYHomeRate.SetStep(1);
	m_prgYHomeRate.SetPos(0);
	m_prgYHomeRate.EnableWindow(FALSE);

	// Dialog�������� XY Stage�� ��ġ�� �����մϴ�.
	m_pcstage.GetWindowRect(&m_rectStage);
	ScreenToClient(&m_rectStage);

	// X, Y�� �����̴��� �ʱ�ȭ�մϴ�.
	nSliderEndPosX = m_rectStage.right - m_rectStage.left - (MARGIN * 2);
	nSliderEndPosY = m_rectStage.bottom - m_rectStage.top - (MARGIN * 2);
	m_sliX.SetRange(0, nSliderEndPosX, FALSE);
	m_sliY.SetRange(0, nSliderEndPosY, FALSE);
	m_sliX.SetPos(0);
	m_sliY.SetPos(nSliderEndPosY);

	// X, Y���� �̵� Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXIsMoving = FALSE;
	m_bYIsMoving = FALSE;

	// Stop ��� Ȯ�� ������ �ʱ�ȭ�մϴ�.
	m_bXStop = FALSE;
	m_bYStop = FALSE;

	// ��ǥ ����ġ���� ����մϴ�.
	m_posRevisionX = DEFAULT_REVISION_X / (m_rectStage.right - m_rectStage.left -
		(MARGIN * 2));
	m_posRevisionY = DEFAULT_REVISION_Y / (m_rectStage.bottom - m_rectStage.top -
		(MARGIN * 2));

	// X, Y���� ���� ��ġ�� ���� ���°��� �ֱ������� ǥ���� Ÿ�̸Ӹ� Ȱ��ȭ�մϴ�.
	SetTimer(TM_DISPLAY, 100, NULL);
	//������������SYSYEM ON �� ��� ����ON -> HOMESEARCH
	AxmSignalServoOn(m_lAxisNoY, 1);
	AxmSignalServoOn(m_lAxisNoX, 1);

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
		strResult.Format("[0000] API�Լ� ���� ����"); break;
	case AXT_RT_OPEN_ERROR:
		strResult.Format("[1001] ���̺귯���� ���µǾ� ���� ����"); break;
	case AXT_RT_OPEN_ALREADY:
		strResult.Format("[1002] ���̺귯���� ���µǾ� �ְ� ��� ����"); break;
	case AXT_RT_NOT_OPEN:
		strResult.Format("[1053] ���̺귯�� �ʱ�ȭ ����"); break;
	case AXT_RT_NOT_SUPPORT_VERSION:
		strResult.Format("[1054] �������� �ʴ� �ϵ����"); break;
	case AXT_RT_NETWORK_ERROR: strResult.Format("[1152] ��Ʈ��ũ�� ����� �����̺� ��� ������� �ʾҰų� ������°� �ҷ���"); break;
	case AXT_RT_MOTION_OPEN_ERROR:
		strResult.Format("[4001] ��� ���̺귯�� Open ����"); break;
	case AXT_RT_MOTION_NOT_MODULE:
		strResult.Format("[4051] �ý��ۿ� ������ ��� ����� ����"); break;
	case AXT_RT_MOTION_INVALID_AXIS_NO:
		strResult.Format("[4101] �ش� ���� �������� ����"); break;
	case AXT_RT_MOTION_INVALID_METHOD: strResult.Format("[4102] �ش� �� ������ �ʿ��� ������ �߸���"); break;
	case AXT_RT_MOTION_INVALID_VELOCITY: strResult.Format("[4113] ��� ���� �ӵ� ���� 0���� �����Ǿ� ��� ���� �߻�"); break;
	case AXT_RT_MOTION_INVALID_ACCELTIME: strResult.Format("[4114] ��� ���� ���� �ð� ���� 0���� �����Ǿ� ��� ���� �߻�"); break;
	case AXT_RT_MOTION_ERROR_IN_MOTION: strResult.Format("[4152] ��� ���� �߿� �ٸ� ��� ���� �Լ��� ������"); break;
	case AXT_RT_MOTION_ERROR: strResult.Format("[4153] ���� ���� ���� �Լ� ���� �� ���� �߻���"); break;
	case AXT_RT_MOTION_HOME_SEARCHING: strResult.Format("[4201] Ȩ�� ã�� �ִ� ���� �� �ٸ� ��� �Լ��� �����"); break;
	case AXT_RT_MOTION_SETTING_ERROR: strResult.Format("[4255] �ӵ�, ���ӵ� �� ������ �߸���"); break;
	case AXT_RT_PROTECTED_DURING_SERVOON: strResult.Format("[4260] ���� �� ���¿��� ����� �� ���� �Լ� �Ǵ� �Է� ���� ����Ͽ���"); break;
	case AXT_RT_HW_ACCESS_ERROR: strResult.Format("[4261] ������ H/W ���� ������ �߻���"); break;
	default: strResult.Format("��Ÿ�����߻�"); break;
	}

	return strResult;
}

BOOL CMy20220401HMYDlg::UpdateState()
{
	DWORD dwRetCode = 0;
	double dUnit = 0.0, dMaxRangeX = 0.0, dMaxRangeY = 0.0;
	long lPulse = 0;

	// ��ǥ ����ġ���� ����մϴ�.
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

//������������ptp���� ��ư�� ������ ptp_btn�� true�� ���־ �ٸ� ������ �������� �ʵ��� �Ѵ�.
void CMy20220401HMYDlg::OnBnClickedRadioPtp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("PTP��ư�� �������ϴ�!");
	btn_ptp = true;
	btn_cp = false;
	btn_rose = false;
	ptp_start_flag = true;
	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
}

//���������������� ����
void CMy20220401HMYDlg::OnBnClickedRadioCp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("CP��ư�� �������ϴ�!");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	btn_ptp = false;
	btn_cp = true;
	btn_rose = false;
	cp_start_flag = true;
	GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE);
}
bool ptp_run_flag;
bool cp_run_flag;
bool rose_run_flag;
//������������LButtondown���� ��ǥ�� �Է¹ް� Onpaint���� �ر׸��� �׸��� Thread���� ���� �����ϴ� ��ǥ�� �׸����� �׷��ش�.
UINT CMy20220401HMYDlg::ThreadStart(LPVOID pParam)
{
	CMy20220401HMYDlg* line_thread = (CMy20220401HMYDlg*)AfxGetApp()->m_pMainWnd;
	double m_posrevX = 0.504051;
	double m_posrevY = 0.492911;
	clock_t startT, endT;
	int time_val;
	CString check;

	CWnd* pWnd = AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	HDC h_screen_dc = ::GetDC(hWnd);
	CDC* dc = CDC::FromHandle(h_screen_dc);

	int kk = 0;
	kk = (line_thread->m_rectStage.left) + MARGIN;

	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = dc->SelectObject(&pen);

	if (line_thread->ptp_start_flag)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;
		line_thread->button_disable();
		startT = clock();
		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);	////  X���� ���� ��ġ���� �޾ƿ� dreal_posX�� �������ش�.
			AxmStatusGetActPos(1, &dreal_posY);	////  Y���� ���� ��ġ���� �޾ƿ� dreal_posX�� �������ش�.


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
		endT = clock();
		time_val = (int)((endT - startT) / CLOCKS_PER_SEC);
		line_thread->log_file_write(time_val);
		line_thread->button_enable();
		line_thread->ptp_start_flag = false;


	}
	else if (line_thread->cp_start_flag)
	{
		int flag = 0;

		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;
		line_thread->button_disable();
		startT = clock();
		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			printf("%.2f : %.2f   %.2f : %.2f\n", dreal_posX, line_thread->cp_start[0], dreal_posY, line_thread->cp_start[1]);
			if (abs(line_thread->cp_start[0] - dreal_posX) < 10.0 && abs(line_thread->cp_start[1] - dreal_posY) < 10.0)
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
		endT = clock();
		time_val = (int)((endT - startT) / CLOCKS_PER_SEC);
		line_thread->log_file_write(time_val);
		line_thread->button_enable();
		line_thread->cp_start_flag = false;
	}
	else if (line_thread->btn_rose)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;
		line_thread->button_disable();
		line_thread->GetDlgItem(IDC_COMBO2)->EnableWindow(FALSE); //�����������ᵿ���� �����ϸ� ��ư ��Ȱ��ȭ
		startT = clock();//�������������� ���۽ð��� �˱� ���� ���� �� �ð��� ���� ����
		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			printf("%.2f : %.2f   %.2f : %.2f\n", dreal_posX, line_thread->rose_start[0], dreal_posY, line_thread->rose_start[1]);
			if (abs(line_thread->rose_start[0] - dreal_posX) < 10.0 && abs(line_thread->rose_start[1] - dreal_posY) < 10.0)
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
		endT = clock();//�����������ᵿ���� ������ ���� ����
		time_val = (int)((endT - startT) / CLOCKS_PER_SEC);
		line_thread->log_file_write(time_val);//������������������ ���� ���� ���� ���� log_file_write�Լ��� �Ķ���ͷ� �����־� ���.
		line_thread->button_enable();
		line_thread->GetDlgItem(IDC_COMBO2)->EnableWindow(TRUE);
		line_thread->GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(FALSE);
	}
	return 0;
}

void CMy20220401HMYDlg::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox("LEAF��ư�� �������ϴ�!");
	btn_ptp = false;
	btn_cp = false;
	btn_rose = true;
	GetDlgItem(IDC_COMBO2)->EnableWindow(TRUE);
}



//������������Initstate���� �߰��� �޺��ڽ����� ����� ���� �̿��� ���� ����
void CMy20220401HMYDlg::OnCbnSelchangeCombo2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSel = m_combo_control.GetCurSel();
	m_combo_control.GetLBText(nSel, leaf_cnt_str);
	inputsize.GetWindowTextA(leaf_size);
	//SetDlgItemText(IDC_COMBO2, leaf_cnt_str);
	//
	if (leaf_cnt_str == "3")
	{
		GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(TRUE);
		leaf_cnt = 3;
		AfxMessageBox("3 LEAF");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	}
	else if (leaf_cnt_str == "4")
	{
		GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(TRUE);
		leaf_cnt = 2;
		AfxMessageBox("4 LEAF");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	}
	else if (leaf_cnt_str == "5")
	{
		leaf_cnt = 5;
		GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(TRUE);
		AfxMessageBox("5 LEAF");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	}
	else if (leaf_cnt_str == "7")
	{
		leaf_cnt = 7;
		GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(TRUE);
		AfxMessageBox("7 LEAF");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	}
	else if (leaf_cnt_str == "8")
	{
		leaf_cnt = 4;
		GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(TRUE);
		AfxMessageBox("8 LEAF");  //���� �߰� -- cp��ư�� �� ���ȴ��� Ȯ���ϱ� ����
	}
}
//������������ѹ��� �����ؾ� �ϴ� ��ư ���۵��� �Լ��� ��Ƴ���
void CMy20220401HMYDlg::button_disable()
{
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_PTP)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_CP)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SIZE_INPUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_OLD)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
}
void CMy20220401HMYDlg::button_enable()
{
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_PTP)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_CP)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_OLD)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
}

void CMy20220401HMYDlg::OnCbnSelchangeComboSize()  //������ ������ ī��Ʈ �ϴ� �޺��ڽ� �Լ�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


//������������ݺ��Ǵ� �ڵ��� ���� ���� �Լ��� ����. Ŭ�� ��ǥ�� ���� ��ǥ�� �Ķ���ͷ� �޾ƿ´�.
void CMy20220401HMYDlg::draw_rose(CPoint point_x, int sePose)
{

	CPoint point_val;
	int SliderPosY;
	point_val = point_x;
	SliderPosY = sePose;
	if (rose_click_flag == true)
	{
		rose_start_flag = true;
		lAxis[0] = 0;
		lAxis[1] = 1;
		rose_point_X = point_val.x - (m_rectStage.left + MARGIN);
		// Y��ǥ�踦 ���� �����Ͽ� �����մϴ�.
		rose_point_Y = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point_val.y - (m_rectStage.top + MARGIN));

		m_sliX.SetPos(rose_point_X);
		m_sliY.SetPos(SliderPosY - rose_point_Y);

		cp_points[0] = rose_point_X;
		cp_points[1] = rose_point_Y;

		Invalidate();
		UpdateWindow();
		AxmContiWriteClear(lCoordinate);
		AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
		AxmContiSetAbsRelMode(lCoordinate, 0);
		AxmContiBeginNode(lCoordinate);
		if (leaf_cnt % 2 == 1)  //3��, 5��, 7�� �� ��� 180���� ȸ��
		{
			for (double i = 0; i < THETA_2; i += 0.01)
			{
				dPos[0] = (rose_point_X + leaf_size_num * cos(leaf_cnt * i) * cos(i)) * m_posRevisionX;
				dPos[1] = (rose_point_Y + leaf_size_num * cos(leaf_cnt * i) * sin(i)) * m_posRevisionY;
				if (i == 0)
				{
					rose_start[0] = dPos[0];
					rose_start[1] = dPos[1];
				}

				AxmLineMove(lCoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
			}
		}
		else if (leaf_cnt % 2 == 0)  //4�� 8�� �ΰ�� 360�� ȸ��
		{
			for (double i = 0; i < THETA; i += 0.01)
			{
				dPos[0] = (rose_point_X + leaf_size_num * cos(leaf_cnt * i) * cos(i)) * m_posRevisionX;
				dPos[1] = (rose_point_Y + leaf_size_num * cos(leaf_cnt * i) * sin(i)) * m_posRevisionY;
				if (i == 0)
				{
					rose_start[0] = dPos[0];
					rose_start[1] = dPos[1];
				}

				AxmLineMove(lCoordinate, dPos, GetDlgItemDouble(IDC_EDT_X_INPUT_VEL), GetDlgItemDouble(IDC_EDT_X_INPUT_ACC), GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
			}
		}
		AxmContiEndNode(lCoordinate);
		AxmContiStart(lCoordinate, 0, 0);
		pWinThread = AfxBeginThread(ThreadStart, this);
	}
	else
	{
		AfxMessageBox("������ ������ Ŭ�����ּ���!");
	}
	//������������α����Ͽ� ��ǥ�� ����ϱ� ���� ������ ���� ����
	r_point_x = (int)rose_point_X;
	r_point_y = (int)rose_point_Y;
	return;
}

//�����������ῡ��Ʈ ��Ʈ�ѿ� ���� ����� �Է¹ް� ���۹�ư�� ������ �� �� ���� �Ǵ��Ͽ� �ǵ�� �ϴ� ��ư
void CMy20220401HMYDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(IDC_EDIT_SIZE_INPUT, leaf_size);
	leaf_size_num = _ttoi(leaf_size);
	if (leaf_size_num > 150)
	{
		AfxMessageBox("�Է¹��� �ʰ� ! �ٽ� �Է��ϼ���");
		rose_click_flag = false;
	}
	else if (leaf_size_num < 50)
	{
		AfxMessageBox("�Է¹��� �ʰ� ! �ٽ� �Է��ϼ���");
		rose_click_flag = false;
	}
	else
	{
		AfxMessageBox("�Է¹�ư ����");
		rose_click_flag = true;
	}

}
//���������������糯¥, ���۽ð�, ��ǥ, ����� �̸� �� ����ϱ� ���� �Լ�
void CMy20220401HMYDlg::log_file_write(int t)
{
	CStdioFile file;
	CTime tmCur = CTime::GetCurrentTime();
	CString sTime;
	int time_val = t;
	//�Ʒ��� ���� �������� �����ϰ��� ��
	sTime.Format(_T("%d�� %d�� %d�� %d�� %d�� %d�� #Ŭ�� ��ǥ : (%d, %d) # ���� �ð� : %d��"), tmCur.GetYear(), tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetHour(), tmCur.GetMinute(), tmCur.GetSecond(), r_point_x, r_point_y, time_val);
	//������������"���ϸ�"�� ������ ����� ������ �ۼ��Ǿ� �ִ� ��� �����ٿ� �ۼ��ϵ��� �ϴ� ���ǹ���.
	if (btn_ptp && !btn_cp && !btn_rose)
	{
		if (file.Open(_T("ptp_log_file.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, NULL))
		{
			file.SeekToEnd();
			file.WriteString(sTime + "\n");
		}
	}
	else if (!btn_ptp && btn_cp && !btn_rose)
	{
		if (file.Open(_T("cp_log_file.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, NULL))
		{
			file.SeekToEnd();
			file.WriteString(sTime + "\n");
		}
	}
	else if (!btn_ptp && !btn_cp && btn_rose)
	{
		if (file.Open(_T("leaf_log_file.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, NULL))
		{
			file.SeekToEnd();
			file.WriteString(sTime + "\n");
		}
	}
	file.Close();


}



HBRUSH CMy20220401HMYDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	switch (nCtlColor) {
	case CTLCOLOR_BTN:    // ��ư�� ������ ��������...
	{
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}

//��������������, ���Ӹ�弳�� ���� ��ư
void CMy20220401HMYDlg::OnBnClickedRadio3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	fast_mode = true;
	slow_mode = false;
	SetDlgItemInt(IDC_EDT_X_INPUT_VEL, 70);
	SetDlgItemInt(IDC_EDT_Y_INPUT_VEL, 70);
}


void CMy20220401HMYDlg::OnBnClickedRadioOld()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	fast_mode = false;
	slow_mode = true;
	SetDlgItemInt(IDC_EDT_X_INPUT_VEL, 10);
	SetDlgItemInt(IDC_EDT_Y_INPUT_VEL, 10);
}


void CAboutDlg::OnEnChangeUserNameInput()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

//�������������̾�α׸� ����°� �ƴ� CAboutDlg�� ���� ������� �̸��� ����Ѵ�.
void CAboutDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_USER_NAME_INPUT, str);
	if (str.IsEmpty() == TRUE)
	{
		AfxMessageBox("�̸��� �Է����ּ���");
	}
	else
	{
		CStdioFile user_record;
		CTime tmCur = CTime::GetCurrentTime();
		CString sTime;
		//int time_val = t;
		sTime.Format(_T("%d�� %d�� %d�� %d�� %d�� %d�� �̸� : "), tmCur.GetYear(), tmCur.GetMonth(), tmCur.GetDay(), tmCur.GetHour(), tmCur.GetMinute(), tmCur.GetSecond());
		if (user_record.Open(_T("user_log.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, NULL))
		{
			user_record.SeekToEnd();
			user_record.WriteString(sTime + str + "\n");
		}

		user_record.Close();

		AfxMessageBox("�����ϰڽ��ϴ�.");
		CDialogEx::OnOK();
	}


}
