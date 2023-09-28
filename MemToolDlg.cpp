
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
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMemToolDlg::OnCbnSelchangeCombo1)
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

	// 初始化基址与偏移数值
	if (!initBaseAndOffset()) {
		return;
	}

	// 初始化循环遍历勾选状态
	initLoopCheckbox();

	// 初始化循环与递增
	if (!initLoopAndInc())
	{
		return;
	}

	// 更新PID
	CString pid_str;
	pid_str.Format(_T("%d"), pid);
	m_pid.SetWindowText(pid_str);

	// 打开句柄
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (handle == NULL)
	{
		MessageBox(L"打开进程句柄失败");
		return;
	}

	// 清空列表数据
	m_list.DeleteAllItems();
	int list_index = 0;
	// 一层循环
	if (m_loop1_checked) {
		for (int loop1_index = 0; loop1_index < m_loop1_num; loop1_index++)
		{
			// 二层循环
			if (m_loop2_checked) {
				for (int loop2_index = 0; loop2_index < m_loop2_num; loop2_index++) {
					// 三层循环
					if (m_loop3_checked) {
						for (int loop3_index = 0; loop3_index < m_loop3_num; loop3_index++) {
							if (m_loop4_checked) {
								for (int loop4_index = 0; loop4_index < m_loop4_num; loop4_index++) {
									if (m_loop5_checked) {
										for (int loop5_index = 0; loop5_index < m_loop5_num; loop5_index++) {
											// 计算当前循环索引
											rowData(handle, list_index);
											*m_loop5_inc_item += m_inc5_num;
											list_index++;
										}
									}
									else {
										// 计算当前循环索引
										rowData(handle, list_index);
									}
									*m_loop4_inc_item += m_inc4_num;
									list_index++;

								}
							}
							else {
								// 计算当前循环索引
								rowData(handle, list_index);
							}
							*m_loop3_inc_item += m_inc3_num;
							list_index++;

						}
					}
					else {
						// 计算当前循环索引
						rowData(handle, list_index);
					}
					*m_loop2_inc_item += m_inc2_num;
					list_index++;
				}
			}
			else {
				// 读取一层循环的地址数据
				rowData(handle, list_index);
			}
			// 一级遍历递增
			*m_loop1_inc_item += m_inc1_num;
			list_index++;
		}
	}
	else {
		// 没有循环，只读取一次地址
		rowData(handle, list_index);
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

bool CMemToolDlg::checkIncSel(int cur)
{

	for (int i = 10; i >= 0; i--)
	{
		// 如果选择的递增选项小于本层循环的递增选项，则跳过本层递增选项
		if (cur < i) {
			continue;
		}

		switch (i)
		{
		case 10:
		{
			CString offset10_str;
			m_offset10.GetWindowText(offset10_str);
			if (offset10_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 9:
		{
			CString offset9_str;
			m_offset9.GetWindowText(offset9_str);
			if (offset9_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 8:
		{
			CString offset8_str;
			m_offset8.GetWindowText(offset8_str);
			if (offset8_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 7:
		{
			CString offset7_str;
			m_offset7.GetWindowText(offset7_str);
			if (offset7_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 6:
		{
			CString offset6_str;
			m_offset6.GetWindowText(offset6_str);
			if (offset6_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 5:
		{
			CString offset5_str;
			m_offset5.GetWindowText(offset5_str);
			if (offset5_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 4:
		{
			CString offset4_str;
			m_offset4.GetWindowText(offset4_str);
			if (offset4_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 3:
		{
			CString offset3_str;
			m_offset3.GetWindowText(offset3_str);
			if (offset3_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 2:
		{
			CString offset2_str;
			m_offset2.GetWindowText(offset2_str);
			if (offset2_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 1:
		{
			CString offset1_str;
			m_offset1.GetWindowText(offset1_str);
			if (offset1_str.IsEmpty()) {
				return false;
			}
		}
		break;
		case 0:
		{
			CString base_addr_str;
			m_base_addr.GetWindowText(base_addr_str);
			if (base_addr_str.IsEmpty()) {
				return false;
			}
		}
		break;
		default:
			return false;
			break;
		}
	}

	return true;
}

__int64* CMemToolDlg::getIncByIndex(int index)
{

	switch (index)
	{
	case 10:
	{
		return &m_offset10_numeric;
	}
	break;
	case 9:
	{
		return &m_offset9_numeric;
	}
	break;
	case 8:
	{
		return &m_offset8_numeric;
	}
	break;
	case 7:
	{
		return &m_offset7_numeric;
	}
	break;
	case 6:
	{
		return &m_offset6_numeric;
	}
	break;
	case 5:
	{
		return &m_offset5_numeric;
	}
	break;
	case 4:
	{
		return &m_offset4_numeric;
	}
	break;
	case 3:
	{
		return &m_offset3_numeric;
	}
	break;
	case 2:
	{
		return &m_offset2_numeric;
	}
	break;
	case 1:
	{
		return &m_offset1_numeric;
	}
	break;
	case 0:
	{
		return &m_base_address_numeric;
	}
	break;
	default:
		return &m_base_address_numeric;
		break;
	}
	return &m_base_address_numeric;
}

void CMemToolDlg::rowData(HANDLE handle, int row)
{
	CString th_addr;		// 定义寻址字符串
	__int64 tmp_pointer;	// 定义当前地址存放的指针
	__int64 cur_address;	// 定义当前行搜素的地址

	// 初始化当前地址
	cur_address = m_base_address_numeric;

	// 获取指针
	tmp_pointer = readLong(handle, cur_address);

	// 处理一级偏移
	if (m_offset1_numeric != -1) {
		cur_address = tmp_pointer + m_offset1_numeric;
		tmp_pointer = readLong(handle, cur_address);

		// 处理二级偏移
		if (m_offset2_numeric != -1) {
			cur_address = tmp_pointer + m_offset2_numeric;
			tmp_pointer = readLong(handle, cur_address);

			// 处理三级偏移
			if (m_offset3_numeric != -1) {
				cur_address = tmp_pointer + m_offset3_numeric;
				tmp_pointer = readLong(handle, cur_address);

				// 处理四级偏移
				if (m_offset4_numeric != -1) {
					cur_address = tmp_pointer + m_offset4_numeric;
					tmp_pointer = readLong(handle, cur_address);

					// 处理五级偏移
					if (m_offset5_numeric != -1) {
						cur_address = tmp_pointer + m_offset5_numeric;
						tmp_pointer = readLong(handle, cur_address);

						// 处理六级偏移
						if (m_offset6_numeric != -1) {
							cur_address = tmp_pointer + m_offset6_numeric;
							tmp_pointer = readLong(handle, cur_address);

							// 处理七级偏移
							if (m_offset7_numeric != -1) {
								cur_address = tmp_pointer + m_offset7_numeric;
								tmp_pointer = readLong(handle, cur_address);

								// 处理八级偏移
								if (m_offset8_numeric != -1) {
									cur_address = tmp_pointer + m_offset8_numeric;
									tmp_pointer = readLong(handle, cur_address);

									// 处理九级偏移
									if (m_offset9_numeric != -1) {
										cur_address = tmp_pointer + m_offset9_numeric;
										tmp_pointer = readLong(handle, cur_address);

										// 处理十级偏移
										if (m_offset10_numeric != -1) {
											cur_address = tmp_pointer + m_offset9_numeric;
											tmp_pointer = readLong(handle, cur_address);
											// 拼接地址（10级偏移）
											th_addr.Format(L"[[[[[[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric, m_offset6_numeric, m_offset7_numeric, m_offset8_numeric, m_offset9_numeric, m_offset10_numeric);
										}
										else {
											// 拼接地址（九级偏移）
											th_addr.Format(L"[[[[[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric, m_offset6_numeric, m_offset7_numeric, m_offset8_numeric, m_offset9_numeric);
										}
									}
									else {
										// 拼接地址（八级偏移）
										th_addr.Format(L"[[[[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric, m_offset6_numeric, m_offset7_numeric, m_offset8_numeric);
									}
								}
								else {
									// 拼接地址（七级偏移）
									th_addr.Format(L"[[[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric, m_offset6_numeric, m_offset7_numeric);
								}
							}
							else {
								// 拼接地址（六级偏移）
								th_addr.Format(L"[[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric, m_offset6_numeric);
							}
						}
						else {
							// 拼接地址（五级偏移）
							th_addr.Format(L"[[[[[[%llX]+%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric, m_offset5_numeric);
						}
					}
					else {
						// 拼接地址（四级偏移）
						th_addr.Format(L"[[[[[%llX]+%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric, m_offset4_numeric);
					}
				}
				else {
					// 拼接地址（三级偏移）
					th_addr.Format(L"[[[[%llX]+%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric, m_offset3_numeric);
				}
			}
			else {
				// 拼接地址(二级偏移)
				th_addr.Format(L"[[[%llX]+%llX]+%llX]", m_base_address_numeric, m_offset1_numeric, m_offset2_numeric);
			}
		}
		else {
			// 拼接地址(一级偏移)
			th_addr.Format(L"[[%llX]+%llX]", m_base_address_numeric, m_offset1_numeric);
		}
	}
	else {
		// 拼接地址
		th_addr.Format(L"[%llX]", m_base_address_numeric);
	}

	// 当前地址指针的字符串
	CString pointer_str;
	pointer_str.Format(L"%llX", tmp_pointer);

	// 获取整数
	int tmp_int = readInt(handle, cur_address);
	CString int_str;
	int_str.Format(L"%d", tmp_int);

	// 获取长整数
	CString long_str;
	long_str.Format(L"%lld", tmp_pointer);

	// 获取小数
	float tmp_float = readFloat(handle, cur_address);
	CString float_str;
	float_str.Format(L"%G", tmp_float);

	// 获取双精度浮点
	double tmp_double = readDouble(handle, cur_address);
	CString double_str;
	double_str.Format(L"%G", tmp_double);

	// 获取字符串
	CString tmp_str = readCString(handle, tmp_pointer, 50);

	// 解密整型
	int tmp_res = readInt(handle, tmp_pointer);
	CString res;
	res.Format(L"%d", tmp_res);

	insertRowData(row, th_addr, pointer_str, int_str, long_str, float_str, double_str, tmp_str, res);
}

bool CMemToolDlg::initBaseAndOffset()
{
	CString base_address_str;
	m_base_addr.GetWindowText(base_address_str);
	if (base_address_str.IsEmpty()) {
		MessageBox(L"基址不能为空");
		return false;
	}

	// 初始化基址
	__int64 tmp_num = wcstoull(base_address_str, NULL, 16);
	m_base_address_numeric = wcstoull(base_address_str, NULL, 16);
	if (m_base_address_numeric <= 0) {
		MessageBox(L"基址不能为0");
		return false;
	}

	// 初始化一级偏移
	CString offset1_str;
	m_offset1.GetWindowText(offset1_str);
	if (!offset1_str.IsEmpty()) {
		m_offset1_numeric = wcstoull(offset1_str, NULL, 16);
	}

	// 初始化二级偏移
	CString offset2_str;
	m_offset2.GetWindowText(offset2_str);
	if (!offset2_str.IsEmpty()) {
		m_offset2_numeric = wcstoull(offset2_str, NULL, 16);
	}

	// 初始化三级偏移
	CString offset3_str;
	m_offset3.GetWindowText(offset3_str);
	if (!offset3_str.IsEmpty()) {
		m_offset3_numeric = wcstoull(offset3_str, NULL, 16);
	}

	// 初始化四级偏移
	CString offset4_str;
	m_offset4.GetWindowText(offset4_str);
	if (!offset4_str.IsEmpty()) {
		m_offset4_numeric = wcstoull(offset4_str, NULL, 16);
	}

	// 初始化五级偏移
	CString offset5_str;
	m_offset5.GetWindowText(offset5_str);
	if (!offset5_str.IsEmpty()) {
		m_offset5_numeric = wcstoull(offset5_str, NULL, 16);
	}

	// 初始化六级偏移
	CString offset6_str;
	m_offset6.GetWindowText(offset6_str);
	if (!offset6_str.IsEmpty()) {
		m_offset6_numeric = wcstoull(offset6_str, NULL, 16);
	}

	// 初始化七级偏移
	CString offset7_str;
	m_offset7.GetWindowText(offset7_str);
	if (!offset7_str.IsEmpty()) {
		m_offset7_numeric = wcstoull(offset7_str, NULL, 16);
	}

	// 初始化八级偏移
	CString offset8_str;
	m_offset8.GetWindowText(offset8_str);
	if (!offset8_str.IsEmpty()) {
		m_offset8_numeric = wcstoull(offset8_str, NULL, 16);
	}

	// 初始化九级偏移
	CString offset9_str;
	m_offset9.GetWindowText(offset9_str);
	if (!offset9_str.IsEmpty()) {
		m_offset9_numeric = wcstoull(offset9_str, NULL, 16);
	}

	// 初始化十级偏移
	CString offset10_str;
	m_offset10.GetWindowText(offset10_str);
	if (!offset10_str.IsEmpty()) {
		m_offset10_numeric = wcstoull(offset10_str, NULL, 16);
	}
	return true;
}

void CMemToolDlg::initLoopCheckbox()
{
	m_loop1_checked = m_checkbox1.GetCheck();
	m_loop2_checked = m_checkbox2.GetCheck();
	m_loop3_checked = m_checkbox3.GetCheck();
	m_loop4_checked = m_checkbox4.GetCheck();
	m_loop5_checked = m_checkbox5.GetCheck();
}

bool CMemToolDlg::initLoopAndInc()
{
	// 一层遍历检查
	if (m_loop1_checked) {
		if (!verifyLoop1()) {
			return false;
		}
		// 二层遍历检查
		if (m_loop2_checked) {
			if (!verifyLoop2()) {
				return false;
			}
			// 三层遍历检查
			if (m_loop3_checked) {
				if (!verifyLoop3()) {
					return false;
				}
				// 四层遍历检查
				if (m_loop4_checked) {
					if (!verifyLoop4()) {
						return false;
					}
					// 五层遍历检查
					if (m_loop5_checked) {
						if (!verifyLoop5()) {
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}

bool CMemToolDlg::verifyLoop1()
{
	// 获取循环次数，递增数值
	CString loop1_str, inc1_str;
	m_loop1.GetWindowText(loop1_str);
	m_inc1.GetWindowText(inc1_str);
	if (loop1_str.IsEmpty()) {
		MessageBox(L"一级遍历循环次数未填写");
		return false;
	}
	if (inc1_str.IsEmpty()) {
		MessageBox(L"一级遍历递增数值未填写");
		return false;
	}

	int loop1_num = _wtoi(loop1_str);
	int inc1_num = _wtoi(inc1_str);

	if (loop1_num <= 0) {
		MessageBox(L"一级遍历循环次数必须大于0");
		return false;
	}
	if (inc1_num <= 0) {
		MessageBox(L"一级遍历递增数值必须大于0");
		return false;
	}

	// 获取递增选项
	int sel1_num = m_combo1.GetCurSel();
	// 所有偏移都需要检查一遍
	if (!checkIncSel(sel1_num)) {
		MessageBox(L"偏移数值或基址未填写");
		return false;
	}

	// 获取一层遍历递增项
	m_loop1_inc_item = getIncByIndex(sel1_num);

	// 获取一层遍历次数
	m_loop1_num = loop1_num;

	// 获取一层递增数值
	m_inc1_num = inc1_num;

	return true;
}

bool CMemToolDlg::verifyLoop2()
{
	// 获取循环次数，递增数值
	CString loop2_str, inc2_str;
	m_loop2.GetWindowText(loop2_str);
	m_inc2.GetWindowText(inc2_str);
	if (loop2_str.IsEmpty()) {
		MessageBox(L"二级遍历循环次数未填写");
		return false;
	}
	if (inc2_str.IsEmpty()) {
		MessageBox(L"二级遍历递增数值未填写");
		return false;
	}

	int loop2_num = _wtoi(loop2_str);
	int inc2_num = _wtoi(inc2_str);

	if (loop2_num <= 0) {
		MessageBox(L"二级遍历循环次数必须大于0");
		return false;
	}
	if (inc2_num <= 0) {
		MessageBox(L"二级遍历递增数值必须大于0");
		return false;
	}

	// 获取递增选项
	int sel2_num = m_combo2.GetCurSel();
	// 所有偏移都需要检查一遍
	if (!checkIncSel(sel2_num)) {
		MessageBox(L"偏移数值或基址未填写");
		return false;
	}
	// 获取二层遍历递增项
	m_loop2_inc_item = getIncByIndex(sel2_num);

	// 获取二层遍历次数
	m_loop2_num = loop2_num;

	// 获取一层递增数值
	m_inc2_num = inc2_num;

	return true;
}

bool CMemToolDlg::verifyLoop3()
{
	// 获取循环次数，递增数值
	CString loop3_str, inc3_str;
	m_loop3.GetWindowText(loop3_str);
	m_inc3.GetWindowText(inc3_str);
	if (loop3_str.IsEmpty()) {
		MessageBox(L"三级遍历循环次数未填写");
		return false;
	}
	if (inc3_str.IsEmpty()) {
		MessageBox(L"三级遍历递增数值未填写");
		return false;
	}

	int loop3_num = _wtoi(loop3_str);
	int inc3_num = _wtoi(inc3_str);

	if (loop3_num <= 0) {
		MessageBox(L"三级遍历循环次数必须大于0");
		return false;
	}
	if (inc3_num <= 0) {
		MessageBox(L"三级遍历递增数值必须大于0");
		return false;
	}

	// 获取递增选项
	int sel3_num = m_combo3.GetCurSel();
	// 所有偏移都需要检查一遍
	if (!checkIncSel(sel3_num)) {
		MessageBox(L"偏移数值或基址未填写");
		return false;
	}

	// 获取三层遍历递增项
	m_loop3_inc_item = getIncByIndex(sel3_num);

	// 获取三层遍历次数
	m_loop3_num = loop3_num;

	// 获取三层递增数值
	m_inc3_num = inc3_num;

	return true;
}

bool CMemToolDlg::verifyLoop4()
{
	// 获取循环次数，递增数值
	CString loop4_str, inc4_str;
	m_loop4.GetWindowText(loop4_str);
	m_inc4.GetWindowText(inc4_str);
	if (loop4_str.IsEmpty()) {
		MessageBox(L"四级遍历循环次数未填写");
		return false;
	}
	if (inc4_str.IsEmpty()) {
		MessageBox(L"四级遍历递增数值未填写");
		return false;
	}

	int loop4_num = _wtoi(loop4_str);
	int inc4_num = _wtoi(inc4_str);

	if (loop4_num <= 0) {
		MessageBox(L"四级遍历循环次数必须大于0");
		return false;
	}
	if (inc4_num <= 0) {
		MessageBox(L"四级遍历递增数值必须大于0");
		return false;
	}

	// 获取递增选项
	int sel4_num = m_combo4.GetCurSel();
	// 所有偏移都需要检查一遍
	if (!checkIncSel(sel4_num)) {
		MessageBox(L"偏移数值或基址未填写");
		return false;
	}

	// 获取四层遍历递增项
	m_loop4_inc_item = getIncByIndex(sel4_num);

	// 获取四层遍历次数
	m_loop4_num = loop4_num;

	// 获取四层递增数值
	m_inc4_num = inc4_num;

	return true;
}

bool CMemToolDlg::verifyLoop5()
{
	// 获取循环次数，递增数值
	CString loop5_str, inc5_str;
	m_loop5.GetWindowText(loop5_str);
	m_inc5.GetWindowText(inc5_str);
	if (loop5_str.IsEmpty()) {
		MessageBox(L"五级遍历循环次数未填写");
		return false;
	}
	if (inc5_str.IsEmpty()) {
		MessageBox(L"五级遍历递增数值未填写");
		return false;
	}

	int loop5_num = _wtoi(loop5_str);
	int inc5_num = _wtoi(inc5_str);

	if (loop5_num <= 0) {
		MessageBox(L"五级遍历循环次数必须大于0");
		return false;
	}
	if (inc5_num <= 0) {
		MessageBox(L"五级遍历递增数值必须大于0");
		return false;
	}

	// 获取递增选项
	int sel5_num = m_combo5.GetCurSel();
	// 所有偏移都需要检查一遍
	if (!checkIncSel(sel5_num)) {
		MessageBox(L"偏移数值或基址未填写");
		return false;
	}

	// 获取五层遍历递增项
	m_loop5_inc_item = getIncByIndex(sel5_num);

	// 获取五层遍历次数
	m_loop5_num = loop5_num;

	// 获取五层递增数值
	m_inc5_num = inc5_num;

	return true;
}

void CMemToolDlg::OnCbnSelchangeCombo1()
{
	// 一级遍历，递增选项改变事件

	m_combo2.SetCurSel(0);
	m_combo3.SetCurSel(0);
	m_combo4.SetCurSel(0);
	m_combo5.SetCurSel(0);
}
