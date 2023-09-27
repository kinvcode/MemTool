
// MemToolDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemTool.h"
#include "MemToolDlg.h"
#include "afxdialogex.h"
#include "process.h"
#include "mem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemToolDlg 对话框



CMemToolDlg::CMemToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_CHECK2, m_checkbox1);
	DDX_Control(pDX, IDC_CHECK3, m_checkbox2);
	DDX_Control(pDX, IDC_CHECK4, m_checkbox3);
	DDX_Control(pDX, IDC_CHECK5, m_checkbox4);
	DDX_Control(pDX, IDC_CHECK6, m_checkbox5);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_COMBO4, m_combo4);
	DDX_Control(pDX, IDC_COMBO5, m_combo5);
	DDX_Control(pDX, IDC_EDIT2, m_base_addr);
	DDX_Control(pDX, IDC_EDIT3, m_offset1);
	DDX_Control(pDX, IDC_EDIT4, m_offset2);
	DDX_Control(pDX, IDC_EDIT5, m_offset3);
	DDX_Control(pDX, IDC_EDIT6, m_offset4);
	DDX_Control(pDX, IDC_EDIT7, m_offset5);
	DDX_Control(pDX, IDC_EDIT8, m_offset6);
	DDX_Control(pDX, IDC_EDIT9, m_offset7);
	DDX_Control(pDX, IDC_EDIT10, m_offset8);
	DDX_Control(pDX, IDC_EDIT11, m_offset9);
	DDX_Control(pDX, IDC_EDIT12, m_offset10);
	DDX_Control(pDX, IDC_EDIT13, m_loop1);
	DDX_Control(pDX, IDC_EDIT15, m_loop2);
	DDX_Control(pDX, IDC_EDIT17, m_loop3);
	DDX_Control(pDX, IDC_EDIT19, m_loop4);
	DDX_Control(pDX, IDC_EDIT21, m_loop5);
	DDX_Control(pDX, IDC_EDIT14, m_inc1);
	DDX_Control(pDX, IDC_EDIT16, m_inc2);
	DDX_Control(pDX, IDC_EDIT18, m_inc3);
	DDX_Control(pDX, IDC_EDIT20, m_inc4);
	DDX_Control(pDX, IDC_EDIT22, m_inc5);
	DDX_Control(pDX, IDC_EDIT1, m_pid);
}

BEGIN_MESSAGE_MAP(CMemToolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK2, &CMemToolDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMemToolDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CMemToolDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CMemToolDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CMemToolDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_BUTTON1, &CMemToolDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMemToolDlg 消息处理程序

BOOL CMemToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	SetWindowText(L"基址遍历助手");

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	// 初始化列表框
	initListCtr();
	// 初始化勾选框
	initCheckBoxs();
	// 初始化组合框
	initComboxs();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMemToolDlg::initListCtr()
{
	m_list.InsertColumn(0, TEXT("地址"), LVCFMT_CENTER, 180);
	m_list.InsertColumn(1, TEXT("地址指针"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(2, TEXT("整数型"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(3, TEXT("长整数"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(4, TEXT("小数型"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(5, TEXT("双精度小数"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(6, TEXT("文本型-U"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(7, TEXT("解密-int"), LVCFMT_CENTER, 150);
}

void CMemToolDlg::initCheckBoxs()
{
	// 二级遍历复选框禁用
	m_checkbox2.EnableWindow(false);
	// 三级遍历复选框禁用
	m_checkbox3.EnableWindow(false);
	// 四级遍历复选框禁用
	m_checkbox4.EnableWindow(false);
	// 五级遍历复选框禁用
	m_checkbox5.EnableWindow(false);
}

void CMemToolDlg::initComboxs()
{
	// 一级遍历组合框禁用
	m_combo1.EnableWindow(false);
	m_combo1.InsertString(0, L"基址偏移");
	m_combo1.InsertString(1, L"一级偏移");
	m_combo1.InsertString(2, L"二级偏移");
	m_combo1.InsertString(3, L"三级偏移");
	m_combo1.InsertString(4, L"四级偏移");
	m_combo1.InsertString(5, L"五级偏移");
	m_combo1.InsertString(6, L"六级偏移");
	m_combo1.InsertString(7, L"七级偏移");
	m_combo1.InsertString(8, L"八级偏移");
	m_combo1.InsertString(9, L"九级偏移");
	m_combo1.InsertString(10, L"十级偏移");
	m_combo1.SetCurSel(0);

	// 二级遍历组合框禁用
	m_combo2.EnableWindow(false);
	m_combo2.InsertString(0, L"基址偏移");
	m_combo2.InsertString(1, L"一级偏移");
	m_combo2.InsertString(2, L"二级偏移");
	m_combo2.InsertString(3, L"三级偏移");
	m_combo2.InsertString(4, L"四级偏移");
	m_combo2.InsertString(5, L"五级偏移");
	m_combo2.InsertString(6, L"六级偏移");
	m_combo2.InsertString(7, L"七级偏移");
	m_combo2.InsertString(8, L"八级偏移");
	m_combo2.InsertString(9, L"九级偏移");
	m_combo2.InsertString(10, L"十级偏移");
	m_combo2.SetCurSel(0);

	// 三级遍历组合框禁用
	m_combo3.EnableWindow(false);
	m_combo3.InsertString(0, L"基址偏移");
	m_combo3.InsertString(1, L"一级偏移");
	m_combo3.InsertString(2, L"二级偏移");
	m_combo3.InsertString(3, L"三级偏移");
	m_combo3.InsertString(4, L"四级偏移");
	m_combo3.InsertString(5, L"五级偏移");
	m_combo3.InsertString(6, L"六级偏移");
	m_combo3.InsertString(7, L"七级偏移");
	m_combo3.InsertString(8, L"八级偏移");
	m_combo3.InsertString(9, L"九级偏移");
	m_combo3.InsertString(10, L"十级偏移");
	m_combo3.SetCurSel(0);

	// 四级遍历组合框禁用
	m_combo4.EnableWindow(false);
	m_combo4.InsertString(0, L"基址偏移");
	m_combo4.InsertString(1, L"一级偏移");
	m_combo4.InsertString(2, L"二级偏移");
	m_combo4.InsertString(3, L"三级偏移");
	m_combo4.InsertString(4, L"四级偏移");
	m_combo4.InsertString(5, L"五级偏移");
	m_combo4.InsertString(6, L"六级偏移");
	m_combo4.InsertString(7, L"七级偏移");
	m_combo4.InsertString(8, L"八级偏移");
	m_combo4.InsertString(9, L"九级偏移");
	m_combo4.InsertString(10, L"十级偏移");
	m_combo4.SetCurSel(0);

	// 五级遍历组合框禁用
	m_combo5.EnableWindow(false);
	m_combo5.InsertString(0, L"基址偏移");
	m_combo5.InsertString(1, L"一级偏移");
	m_combo5.InsertString(2, L"二级偏移");
	m_combo5.InsertString(3, L"三级偏移");
	m_combo5.InsertString(4, L"四级偏移");
	m_combo5.InsertString(5, L"五级偏移");
	m_combo5.InsertString(6, L"六级偏移");
	m_combo5.InsertString(7, L"七级偏移");
	m_combo5.InsertString(8, L"八级偏移");
	m_combo5.InsertString(9, L"九级偏移");
	m_combo5.InsertString(10, L"十级偏移");
	m_combo5.SetCurSel(0);
}


void CMemToolDlg::OnBnClickedCheck2()
{
	// 一级遍历勾选
	bool checked = m_checkbox1.GetCheck();
	if (checked) {
		m_combo1.EnableWindow(true);
		m_checkbox2.EnableWindow(true);
	}
	else {
		// 判断二级遍历是否勾选
		if (m_checkbox2.GetCheck()) {
			m_checkbox1.SetCheck(true);
			MessageBox(L"二级遍历未关闭");
			return;
		}

		m_combo1.EnableWindow(false);
		m_checkbox2.EnableWindow(false);
		m_checkbox2.SetCheck(false);
	}
}


void CMemToolDlg::OnBnClickedCheck3()
{
	// 二级遍历勾选
	bool checked = m_checkbox2.GetCheck();
	if (checked) {
		m_combo2.EnableWindow(true);
		m_checkbox3.EnableWindow(true);
	}
	else {
		// 判断三级遍历是否勾选
		if (m_checkbox3.GetCheck()) {
			m_checkbox2.SetCheck(true);
			MessageBox(L"三级遍历未关闭");
			return;
		}

		m_combo2.EnableWindow(false);
		m_checkbox3.EnableWindow(false);
		m_checkbox3.SetCheck(false);
	}
}


void CMemToolDlg::OnBnClickedCheck4()
{
	// 三级遍历勾选
	bool checked = m_checkbox3.GetCheck();
	if (checked) {
		m_combo3.EnableWindow(true);
		m_checkbox4.EnableWindow(true);
	}
	else {
		// 判断四级遍历是否勾选
		if (m_checkbox4.GetCheck()) {
			m_checkbox3.SetCheck(true);
			MessageBox(L"四级遍历未关闭");
			return;
		}

		m_combo3.EnableWindow(false);
		m_checkbox4.EnableWindow(false);
		m_checkbox4.SetCheck(false);
	}
}


void CMemToolDlg::OnBnClickedCheck5()
{
	// 四级遍历勾选
	bool checked = m_checkbox4.GetCheck();
	if (checked) {
		m_combo4.EnableWindow(true);
		m_checkbox5.EnableWindow(true);
	}
	else {
		// 判断五级遍历是否勾选
		if (m_checkbox5.GetCheck()) {
			m_checkbox4.SetCheck(true);
			MessageBox(L"五级遍历未关闭");
			return;
		}

		m_combo4.EnableWindow(false);
		m_checkbox5.EnableWindow(false);
		m_checkbox5.SetCheck(false);
	}
}


void CMemToolDlg::OnBnClickedCheck6()
{
	// 五级遍历勾选
	bool checked = m_checkbox5.GetCheck();
	if (checked) {
		m_combo5.EnableWindow(true);
	}
	else {
		m_combo5.EnableWindow(false);
	}
}


void CMemToolDlg::OnBnClickedButton1()
{
	// 开始遍历
	int pid = getProcessPID(L"DNF.exe");
	if (pid == 0)
	{
		AfxMessageBox(L"DNF未启动");
		return;
	}

	// 更新PID
	CString pid_str;
	pid_str.Format(_T("%d"), pid);
	m_pid.SetWindowText(pid_str);

	// 组合地址


	CString base_address_num;
	m_base_addr.GetWindowText(base_address_num);

	__int64 base_address = wcstoul(base_address_num, NULL, 16);
	if (!base_address) {
		MessageBox(L"基址不能为空");
		return;
	}

	bool offset1_exists = true,
		offset2_exists = true,
		offset3_exists = true,
		offset4_exists = true,
		offset5_exists = true,
		offset6_exists = true,
		offset7_exists = true,
		offset8_exists = true,
		offset9_exists = true,
		offset10_exists = true;

	CString offset1_str;
	m_offset1.GetWindowText(offset1_str);
	if (offset1_str.IsEmpty()) {
		// 读取基址
		offset1_exists = false;
	}

	CString offset2_str;
	m_offset2.GetWindowText(offset2_str);
	if (offset2_str.IsEmpty()) {
		offset2_exists = false;
	}

	CString offset3_str;
	m_offset3.GetWindowText(offset3_str);
	if (offset3_str.IsEmpty()) {
		offset3_exists = false;
	}

	CString offset4_str;
	m_offset4.GetWindowText(offset4_str);
	if (offset4_str.IsEmpty()) {
		offset4_exists = false;
	}

	CString offset5_str;
	m_offset5.GetWindowText(offset5_str);
	if (offset5_str.IsEmpty()) {
		offset5_exists = false;
	}

	CString offset6_str;
	m_offset6.GetWindowText(offset6_str);
	if (offset6_str.IsEmpty()) {
		offset6_exists = false;
	}

	CString offset7_str;
	m_offset7.GetWindowText(offset7_str);
	if (offset7_str.IsEmpty()) {
		offset7_exists = false;
	}

	CString offset8_str;
	m_offset8.GetWindowText(offset8_str);
	if (offset8_str.IsEmpty()) {
		offset8_exists = false;
	}

	CString offset9_str;
	m_offset9.GetWindowText(offset9_str);
	if (offset9_str.IsEmpty()) {
		offset9_exists = false;
	}

	CString offset10_str;
	m_offset10.GetWindowText(offset10_str);
	if (offset10_str.IsEmpty()) {
		offset10_exists = false;
	}

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (handle == NULL)
	{
		MessageBox(L"打开进程句柄失败");
		return;
	}

	// 一层循环
	if (m_checkbox1.GetCheck()) {
		// 循环次数
	}
	else {
		// 没有循环，只读取一次地址

		// 先读基址

		// 获取指针

		// 判断一级偏移
		if (offset1_exists) {
			// 获取指针
		}
		else {
			// 获取数据
			// 拼接地址
			CString th_addr;
			th_addr.Format(L"[%llX]", base_address);

			// 获取指针
			__int64 tmp_pointer = readLong(handle, base_address);
			CString pointer_str;
			pointer_str.Format(L"%llX", tmp_pointer);

			// 获取整数
			int tmp_int = readInt(handle, base_address);
			CString int_str;
			int_str.Format(L"%d", tmp_int);

			// 获取长整数
			CString long_str;
			long_str.Format(L"%lld", tmp_pointer);

			// 获取小数
			float tmp_float = readFloat(handle, base_address);
			CString float_str;
			float_str.Format(L"%f", tmp_float);

			// 获取双精度浮点
			double tmp_double = readDouble(handle, base_address);
			CString double_str;
			double_str.Format(L"%f", tmp_double);

			// 获取字符串
			CString tmp_str = readCString(handle, tmp_pointer, 50);

			// 解密整型
			int tmp_res = readInt(handle, tmp_pointer);
			CString res;
			res.Format(L"%d", tmp_res);
			insertRowData(0, th_addr, pointer_str, int_str, long_str, float_str, double_str, tmp_str, res);

		}
	}
}


BOOL CMemToolDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

// 插入一行数据
void CMemToolDlg::insertRowData(
	int row,
	CString addr,
	CString pointer,
	CString int_str,
	CString long_str,
	CString float_str,
	CString double_str,
	CString str,
	CString res
)
{
	m_list.InsertItem(row, addr);
	m_list.SetItemText(row, 1, pointer);
	m_list.SetItemText(row, 2, int_str);
	m_list.SetItemText(row, 3, long_str);
	m_list.SetItemText(row, 4, float_str);
	m_list.SetItemText(row, 5, double_str);
	m_list.SetItemText(row, 6, str);
	m_list.SetItemText(row, 7, res);
}
