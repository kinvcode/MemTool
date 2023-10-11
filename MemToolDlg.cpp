
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
	, m_filter_type_value(0)
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
	DDX_Control(pDX, IDC_BUTTON2, m_stop_search);
	DDX_Control(pDX, IDC_STATIC36, m_search_pos);
	DDX_Control(pDX, IDC_RADIO1, m_filter_type);
	DDX_Radio(pDX, IDC_RADIO1, m_filter_type_value);
	DDX_Control(pDX, IDC_COMBO6, m_filter_condition);
	DDX_Control(pDX, IDC_BUTTON3, m_filter_btn);
	DDX_Control(pDX, IDC_BUTTON4, m_stop_filter_btn);
	DDX_Control(pDX, IDC_STATIC41, m_filter_result);
	DDX_Control(pDX, IDC_EDIT23, m_compare_value);
	DDX_Control(pDX, IDC_EDIT24, m_compare_min_value);
	DDX_Control(pDX, IDC_EDIT25, m_compare_max_value);
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
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMemToolDlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMemToolDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMemToolDlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CMemToolDlg::OnCbnSelchangeCombo5)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemToolDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CMemToolDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMemToolDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CMemToolDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CMemToolDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO5, &CMemToolDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO6, &CMemToolDlg::OnBnClickedRadio1)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CMemToolDlg::OnCbnSelchangeCombo6)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemToolDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemToolDlg::OnBnClickedButton4)
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
	// 初始化过滤
	initFilter();

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
	__int64 start_time = CTime::GetCurrentTime().GetTime();
	// 开始遍历
	int pid = getProcessPID(L"DFO.exe");
	if (pid == 0)
	{
		AfxMessageBox(L"DFO未启动");
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

	// 清空64位数据映射
	m_bit64_map.clear();

	// 显示停止搜索按钮
	m_stop_search.ShowWindow(true);

	// 禁用过滤按钮
	m_filter_btn.EnableWindow(false);

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
											// 更新搜索进度
											updateSearchPos(list_index, m_loop1_num * m_loop2_num * m_loop3_num * m_loop4_num * m_loop5_num);
											// 停止搜索
											if (m_need_stop_search) {
												goto search_end;
											}
											*m_loop5_inc_item += m_inc5_num;
											list_index++;
											handleEvents();
										}
									}
									else {
										// 计算当前循环索引
										rowData(handle, list_index);
										// 更新搜索进度
										updateSearchPos(list_index, m_loop1_num * m_loop2_num * m_loop3_num * m_loop4_num);
										// 停止搜索
										if (m_need_stop_search) {
											goto search_end;
										}
										handleEvents();
									}
									*m_loop4_inc_item += m_inc4_num;
									list_index++;

								}
							}
							else {
								// 计算当前循环索引
								rowData(handle, list_index);
								// 更新搜索进度
								updateSearchPos(list_index, m_loop1_num * m_loop2_num * m_loop3_num);
								// 停止搜索
								if (m_need_stop_search) {
									goto search_end;
								}
								handleEvents();
							}
							*m_loop3_inc_item += m_inc3_num;
							list_index++;

						}
					}
					else {
						// 计算当前循环索引
						rowData(handle, list_index);
						// 更新搜索进度
						updateSearchPos(list_index, m_loop1_num * m_loop2_num);
						// 停止搜索
						if (m_need_stop_search) {
							goto search_end;
						}
						handleEvents();
					}
					*m_loop2_inc_item += m_inc2_num;
					list_index++;
				}
			}
			else {
				// 读取一层循环的地址数据
				rowData(handle, list_index);
				// 更新搜索进度
				updateSearchPos(list_index, m_loop1_num);
				// 停止搜索
				if (m_need_stop_search) {
					goto search_end;
				}
				handleEvents();
			}
			// 一级遍历递增
			*m_loop1_inc_item += m_inc1_num;
			list_index++;
		}
	}
	else {
		// 没有循环，只读取一次地址
		rowData(handle, list_index);
		updateSearchPos(1, 1);
	}

search_end:
	// 隐藏停止搜索按钮
	m_stop_search.ShowWindow(false);
	m_need_stop_search = false;

	// 显示过滤按钮
	m_filter_btn.EnableWindow(true);

	__int64 end_time = CTime::GetCurrentTime().GetTime();
	__int64 total_time = end_time - start_time;
	CString time_str;
	time_str.Format(L"当前搜索用时：%d秒", total_time);
	MessageBox(time_str);
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
	//tmp_pointer = readLong(handle, cur_address);
	tmp_pointer = readLongByMap(handle, cur_address);

	// 处理一级偏移
	if (m_offset1_numeric != -1) {
		cur_address = tmp_pointer + m_offset1_numeric;
		//tmp_pointer = readLong(handle, cur_address);
		tmp_pointer = readLongByMap(handle, cur_address);

		// 处理二级偏移
		if (m_offset2_numeric != -1) {
			cur_address = tmp_pointer + m_offset2_numeric;
			//tmp_pointer = readLong(handle, cur_address);
			tmp_pointer = readLongByMap(handle, cur_address);

			// 处理三级偏移
			if (m_offset3_numeric != -1) {
				cur_address = tmp_pointer + m_offset3_numeric;
				//tmp_pointer = readLong(handle, cur_address);
				tmp_pointer = readLongByMap(handle, cur_address);

				// 处理四级偏移
				if (m_offset4_numeric != -1) {
					cur_address = tmp_pointer + m_offset4_numeric;
					//tmp_pointer = readLong(handle, cur_address);
					tmp_pointer = readLongByMap(handle, cur_address);

					// 处理五级偏移
					if (m_offset5_numeric != -1) {
						cur_address = tmp_pointer + m_offset5_numeric;
						//tmp_pointer = readLong(handle, cur_address);
						tmp_pointer = readLongByMap(handle, cur_address);

						// 处理六级偏移
						if (m_offset6_numeric != -1) {
							cur_address = tmp_pointer + m_offset6_numeric;
							//tmp_pointer = readLong(handle, cur_address);
							tmp_pointer = readLongByMap(handle, cur_address);

							// 处理七级偏移
							if (m_offset7_numeric != -1) {
								cur_address = tmp_pointer + m_offset7_numeric;
								//tmp_pointer = readLong(handle, cur_address);
								tmp_pointer = readLongByMap(handle, cur_address);

								// 处理八级偏移
								if (m_offset8_numeric != -1) {
									cur_address = tmp_pointer + m_offset8_numeric;
									//tmp_pointer = readLong(handle, cur_address);
									tmp_pointer = readLongByMap(handle, cur_address);

									// 处理九级偏移
									if (m_offset9_numeric != -1) {
										cur_address = tmp_pointer + m_offset9_numeric;
										//tmp_pointer = readLong(handle, cur_address);
										tmp_pointer = readLongByMap(handle, cur_address);

										// 处理十级偏移
										if (m_offset10_numeric != -1) {
											cur_address = tmp_pointer + m_offset9_numeric;
											//tmp_pointer = readLong(handle, cur_address);
											tmp_pointer = readLongByMap(handle, cur_address);
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

	LISTROWDATA tmp_row_data = readRowDataByMap(handle, cur_address, tmp_pointer, th_addr);

	// 表数据保存（用于数据筛选）
	m_list_data.push_back(tmp_row_data);

	// 插入当前行数据
	insertRowData(
		row,
		th_addr,
		tmp_row_data.pointer_str,
		tmp_row_data.int_str,
		tmp_row_data.int64_str,
		tmp_row_data.float_str,
		tmp_row_data.double_str,
		tmp_row_data.text,
		tmp_row_data.decrypt_value_str
	);
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


void CMemToolDlg::OnCbnSelchangeCombo2()
{
	// 二级遍历，递增选项改变事件
	m_combo3.SetCurSel(0);
	m_combo4.SetCurSel(0);
	m_combo5.SetCurSel(0);

	// 检查合法数据
	int sel1 = m_combo1.GetCurSel();
	if (m_combo2.GetCurSel() <= sel1) {
		m_combo2.SetCurSel(0);
		MessageBox(L"二级遍历必须高于一级遍历");
	}
}


void CMemToolDlg::OnCbnSelchangeCombo3()
{
	// 三级遍历，递增选项改变事件
	m_combo4.SetCurSel(0);
	m_combo5.SetCurSel(0);

	// 检查合法数据
	int sel2 = m_combo2.GetCurSel();
	if (m_combo3.GetCurSel() <= sel2) {
		m_combo3.SetCurSel(0);
		MessageBox(L"三级遍历必须高于二级遍历");
	}
}


void CMemToolDlg::OnCbnSelchangeCombo4()
{
	// 四级遍历，递增选项改变事件
	m_combo5.SetCurSel(0);

	// 检查合法数据
	int sel3 = m_combo3.GetCurSel();
	if (m_combo4.GetCurSel() <= sel3) {
		m_combo4.SetCurSel(0);
		MessageBox(L"四级遍历必须高于三级遍历");
	}
}


void CMemToolDlg::OnCbnSelchangeCombo5()
{
	// 五级遍历，递增选项改变事件

	// 检查合法数据
	int sel4 = m_combo4.GetCurSel();
	if (m_combo5.GetCurSel() <= sel4) {
		m_combo5.SetCurSel(0);
		MessageBox(L"五级遍历必须高于四级遍历");
	}
}

__int64 CMemToolDlg::readLongByMap(HANDLE handle, __int64 address)
{
	if (m_bit64_map.count(address)) {
		return m_bit64_map[address];
	}
	else {
		__int64 bit64 = readLong(handle, address);
		m_bit64_map.insert({ address,bit64 });
		return bit64;
	}
}

LISTROWDATA CMemToolDlg::readRowDataByMap(HANDLE handle, __int64 address, __int64 tmp_pointer, CString th_addr)
{
	if (m_data_map.count(address)) {
		//if (false) {
		return m_data_map[address];
	}
	else {
		LISTROWDATA tmp_row_data;

		// 当前地址表达式
		tmp_row_data.addr_str = th_addr;

		// 当前地址指针的字符串
		CString pointer_str;
		pointer_str.Format(L"%llX", tmp_pointer);
		tmp_row_data.pointer_str = pointer_str;

		// 获取整数
		//int tmp_int = readInt(handle, cur_address);
		int tmp_int = (int)(tmp_pointer >> 32);
		CString int_str;
		int_str.Format(L"%d", tmp_int);
		tmp_row_data.int_num = tmp_int;
		tmp_row_data.int_str = int_str;

		// 获取长整数
		CString int64_str;
		int64_str.Format(L"%lld", tmp_pointer);
		tmp_row_data.int64_num = tmp_pointer;
		tmp_row_data.int64_str = int64_str;

		// 获取小数
		//float tmp_float = readFloat(handle, cur_address);
		float tmp_float = (float)tmp_int;
		CString float_str;
		float_str.Format(L"%G", tmp_float);
		tmp_row_data.float_num = tmp_float;
		tmp_row_data.float_str = float_str;

		// 获取双精度浮点
		//double tmp_double = readDouble(handle, cur_address);
		double tmp_double = (double)tmp_pointer;
		CString double_str;
		double_str.Format(L"%G", tmp_double);
		tmp_row_data.double_num = tmp_double;
		tmp_row_data.double_str = double_str;

		// 获取字符串
		CString tmp_str = readCString(handle, tmp_pointer, 50);
		tmp_row_data.text = tmp_str;

		// 解密整型
		int tmp_res = decrypt(handle, tmp_pointer);
		CString res;
		res.Format(L"%d", tmp_res);
		tmp_row_data.decrypt_value = tmp_res;
		tmp_row_data.decrypt_value_str = res;
		return tmp_row_data;
	}
}

void CMemToolDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_need_stop_search = true;
	m_stop_search.ShowWindow(false);
}

void CMemToolDlg::updateSearchPos(int index, int count)
{
	index += 1;
	CString pos_str;
	pos_str.Format(L"%d/%d", index, count);
	m_search_pos.SetWindowText(pos_str);
}

void CMemToolDlg::initFilter()
{
	//m_filter_type.SetCheck(true);
	m_filter_condition.ResetContent();
	m_filter_condition.InsertString(0, L"等于");
	m_filter_condition.InsertString(1, L"小于");
	m_filter_condition.InsertString(2, L"大于");
	m_filter_condition.InsertString(3, L"不等于");
	m_filter_condition.InsertString(4, L"两者之间");
	m_filter_condition.SetCurSel(0);
}


void CMemToolDlg::OnBnClickedRadio1()
{
	UpdateData(true);

	switch (m_filter_type_value) {
	case 0:
		// 整数
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"小于");
		m_filter_condition.InsertString(2, L"大于");
		m_filter_condition.InsertString(3, L"不等于");
		m_filter_condition.InsertString(4, L"两者之间");
		m_filter_condition.SetCurSel(0);
		break;
	case 1:
		// 长整数
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"小于");
		m_filter_condition.InsertString(2, L"大于");
		m_filter_condition.InsertString(3, L"不等于");
		m_filter_condition.InsertString(4, L"两者之间");
		m_filter_condition.SetCurSel(0);
		break;
	case 2:
		// 浮点
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"小于");
		m_filter_condition.InsertString(2, L"大于");
		m_filter_condition.InsertString(3, L"不等于");
		m_filter_condition.InsertString(4, L"两者之间");
		m_filter_condition.SetCurSel(0);
		break;
	case 3:
		// 双精度
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"小于");
		m_filter_condition.InsertString(2, L"大于");
		m_filter_condition.InsertString(3, L"不等于");
		m_filter_condition.InsertString(4, L"两者之间");
		m_filter_condition.SetCurSel(0);
		break;
	case 4:
		// 文本
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"包含");
		m_filter_condition.SetCurSel(0);
		break;
	case 5:
		// 解密
		m_filter_condition.ResetContent();
		m_filter_condition.InsertString(0, L"等于");
		m_filter_condition.InsertString(1, L"小于");
		m_filter_condition.InsertString(2, L"大于");
		m_filter_condition.InsertString(3, L"不等于");
		m_filter_condition.InsertString(4, L"两者之间");
		m_filter_condition.SetCurSel(0);
		break;
	default:
		MessageBox(L"无效的选项");
		break;
	}
}


void CMemToolDlg::OnCbnSelchangeCombo6()
{
	// 过滤条件发生改变
	int index = m_filter_condition.GetCurSel();

	// 如果是区间比较
	if (index == 4)
	{
		showBetweenValue(true);
	}
	else {
		showBetweenValue(false);
	}
}


void CMemToolDlg::OnBnClickedButton3()
{
	// 开始过滤
	if (m_list_data.size() < 1) {
		MessageBox(L"当前没有数据");
		return;
	}

	UpdateData();

	m_stop_filter_btn.ShowWindow(true);

	// 清空列表
	m_list.DeleteAllItems();

	// 当前过滤条件
	int tmp_filter_condition = m_filter_condition.GetCurSel();

	if (tmp_filter_condition == 4) {
		CString compare_min_value_str,compare_max_value_str;
		m_compare_min_value.GetWindowText(compare_min_value_str);
		m_compare_max_value.GetWindowText(compare_max_value_str);
		if (compare_min_value_str.IsEmpty() || compare_max_value_str.IsEmpty()) {
			MessageBox(L"请填写过滤值");
			return;
		}
	}
	else {
		CString compare_value_str;
		m_compare_value.GetWindowText(compare_value_str);
		if (compare_value_str.IsEmpty()) {
			MessageBox(L"请填写过滤值");
			return;
		}
	}

	// 创建一个临时的vector容器存放过滤结果
	vector<LISTROWDATA> tmp_list_data;

	// 当前过滤类型
	int type_value = m_filter_type_value;
	switch (type_value)
	{
		// 处理整数
	case 0:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = intEqual();
			break;
		case 1:
			tmp_list_data = intLessThan();
			break;
		case 2:
			tmp_list_data = intGreaterThan();
			break;
		case 3:
			tmp_list_data = intnotEqual();
			break;
		case 4:
			tmp_list_data = intBetween();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
		// 处理长整数
	case 1:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = int64Equal();
			break;
		case 1:
			tmp_list_data = int64LessThan();
			break;
		case 2:
			tmp_list_data = int64GreaterThan();
			break;
		case 3:
			tmp_list_data = int64notEqual();
			break;
		case 4:
			tmp_list_data = int64Between();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
		// 处理浮点数
	case 2:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = floatEqual();
			break;
		case 1:
			tmp_list_data = floatLessThan();
			break;
		case 2:
			tmp_list_data = floatGreaterThan();
			break;
		case 3:
			tmp_list_data = floatnotEqual();
			break;
		case 4:
			tmp_list_data = floatBetween();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
		// 处理双精度
	case 3:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = doubleEqual();
			break;
		case 1:
			tmp_list_data = doubleLessThan();
			break;
		case 2:
			tmp_list_data = doubleGreaterThan();
			break;
		case 3:
			tmp_list_data = doublenotEqual();
			break;
		case 4:
			tmp_list_data = doubleBetween();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
		// 处理解密值
	case 5:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = decryptEqual();
			break;
		case 1:
			tmp_list_data = decryptLessThan();
			break;
		case 2:
			tmp_list_data = decryptGreaterThan();
			break;
		case 3:
			tmp_list_data = decryptnotEqual();
			break;
		case 4:
			tmp_list_data = decryptBetween();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
		// 处理文本
	case 4:
		switch (tmp_filter_condition)
		{
		case 0:
			tmp_list_data = textEqual();
			break;
		case 1:
			tmp_list_data = textContain();
			break;
		default:
			MessageBox(L"错误的过滤条件");
			return;
			break;
		}
		break;
	default:
		MessageBox(L"错误的过滤类型");
		return;
		break;
	}

	// 将过滤结果全部转移给数据容器
	m_list_data = tmp_list_data;

	// 隐藏停止过滤按钮
	m_stop_filter_btn.ShowWindow(false);
	m_need_stop_filter = false;
}


void CMemToolDlg::OnBnClickedButton4()
{
	// 停止过滤
	m_need_stop_filter = true;

	// 隐藏按钮
	m_stop_filter_btn.ShowWindow(false);
	m_need_stop_filter = false;
}


// 整数相等
vector<LISTROWDATA> CMemToolDlg::intEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).int_num;
		if (num == target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 整数大于
vector<LISTROWDATA> CMemToolDlg::intGreaterThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).int_num;
		if (num > target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 整数小于
vector<LISTROWDATA> CMemToolDlg::intLessThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).int_num;
		if (num < target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 整数不等于
vector<LISTROWDATA> CMemToolDlg::intnotEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).int_num;
		if (num != target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 整数两者之间
vector<LISTROWDATA> CMemToolDlg::intBetween()
{
	CString target_min_str;
	m_compare_min_value.GetWindowText(target_min_str);
	int target_min_num = _wtoi(target_min_str);

	CString target_max_str;
	m_compare_max_value.GetWindowText(target_max_str);
	int target_max_num = _wtoi(target_max_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).int_num;
		if (num >= target_min_num && num <= target_max_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 长整数相等
vector<LISTROWDATA> CMemToolDlg::int64Equal()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	__int64 target_num = wcstoull(target_str, NULL, 10);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		__int64 num = (*item).int64_num;
		if (num == target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 长整数大于
vector<LISTROWDATA> CMemToolDlg::int64GreaterThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	__int64 target_num = wcstoull(target_str, NULL, 10);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		__int64 num = (*item).int64_num;
		if (num > target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 长整数小于
vector<LISTROWDATA> CMemToolDlg::int64LessThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	__int64 target_num = wcstoull(target_str, NULL, 10);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		__int64 num = (*item).int64_num;
		if (num < target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 长整数不等于
vector<LISTROWDATA> CMemToolDlg::int64notEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	__int64 target_num = wcstoull(target_str, NULL, 10);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		__int64 num = (*item).int64_num;
		if (num != target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 长整数两者之间
vector<LISTROWDATA> CMemToolDlg::int64Between()
{
	CString target_min_str;
	m_compare_min_value.GetWindowText(target_min_str);
	__int64 target_min_num = wcstoull(target_min_str, NULL, 10);

	CString target_max_str;
	m_compare_max_value.GetWindowText(target_max_str);
	__int64 target_max_num = wcstoull(target_max_str, NULL, 10);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		__int64 num = (*item).int64_num;
		if (num >= target_min_num && num <= target_max_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 浮点数相等
vector<LISTROWDATA> CMemToolDlg::floatEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	float target_num = wcstof(target_str, NULL);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		float num = (*item).float_num;
		if (num == target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 浮点数大于
vector<LISTROWDATA> CMemToolDlg::floatGreaterThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	float target_num = wcstof(target_str, NULL);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		float num = (*item).float_num;
		if (num > target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 浮点数小于
vector<LISTROWDATA> CMemToolDlg::floatLessThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	float target_num = wcstof(target_str, NULL);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		float num = (*item).float_num;
		if (num < target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 浮点数不等于
vector<LISTROWDATA> CMemToolDlg::floatnotEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	float target_num = wcstof(target_str, NULL);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		float num = (*item).float_num;
		if (num != target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 浮点数两者之间
vector<LISTROWDATA> CMemToolDlg::floatBetween()
{
	CString target_min_str;
	m_compare_min_value.GetWindowText(target_min_str);
	float target_min_num = wcstof(target_min_str, NULL);

	CString target_max_str;
	m_compare_max_value.GetWindowText(target_max_str);
	float target_max_num = wcstof(target_max_str, NULL);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		float num = (*item).float_num;
		if (num >= target_min_num && num <= target_max_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 双精度相等
vector<LISTROWDATA> CMemToolDlg::doubleEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	double target_num = _wtof(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		double num = (*item).double_num;
		if (num == target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 双精度大于
vector<LISTROWDATA> CMemToolDlg::doubleGreaterThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	double target_num = _wtof(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		double num = (*item).double_num;
		if (num > target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 双精度小于
vector<LISTROWDATA> CMemToolDlg::doubleLessThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	double target_num = _wtof(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		double num = (*item).double_num;
		if (num < target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 双精度不等于
vector<LISTROWDATA> CMemToolDlg::doublenotEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	double target_num = _wtof(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		double num = (*item).double_num;
		if (num != target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}
// 双精度两者之间
vector<LISTROWDATA> CMemToolDlg::doubleBetween()
{
	CString target_min_str;
	m_compare_min_value.GetWindowText(target_min_str);
	double target_min_num = _wtof(target_min_str);

	CString target_max_str;
	m_compare_max_value.GetWindowText(target_max_str);
	double target_max_num = _wtof(target_max_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		double num = (*item).double_num;
		if (num >= target_min_num && num <= target_max_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 文本相等
vector<LISTROWDATA> CMemToolDlg::textEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		CString text = (*item).text;
		if (text == target_str)
		{
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 文本包含
vector<LISTROWDATA> CMemToolDlg::textContain()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		CString text = (*item).text;
		if (text.Find(target_str, 0) != -1)
		{
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 解密值相等
vector<LISTROWDATA> CMemToolDlg::decryptEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).decrypt_value;
		if (num == target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 解密值大于
vector<LISTROWDATA> CMemToolDlg::decryptGreaterThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).decrypt_value;
		if (num > target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 解密值小于
vector<LISTROWDATA> CMemToolDlg::decryptLessThan()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).decrypt_value;
		if (num < target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 解密值不等于
vector<LISTROWDATA> CMemToolDlg::decryptnotEqual()
{
	CString target_str;
	m_compare_value.GetWindowText(target_str);
	int target_num = _wtoi(target_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).decrypt_value;
		if (num != target_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

// 解密值两者之间
vector<LISTROWDATA> CMemToolDlg::decryptBetween()
{
	CString target_min_str;
	m_compare_min_value.GetWindowText(target_min_str);
	int target_min_num = _wtoi(target_min_str);

	CString target_max_str;
	m_compare_max_value.GetWindowText(target_max_str);
	int target_max_num = _wtoi(target_max_str);

	int row = 0;

	vector<LISTROWDATA> tmp_list_data;
	for (auto item = m_list_data.cbegin(); item != m_list_data.cend(); item++) {
		int num = (*item).decrypt_value;
		if (num >= target_min_num && num <= target_max_num) {
			tmp_list_data.push_back(*item);
			// 插入当前行数据
			insertRowData(
				row,
				(*item).addr_str,
				(*item).pointer_str,
				(*item).int_str,
				(*item).int64_str,
				(*item).float_str,
				(*item).double_str,
				(*item).text,
				(*item).decrypt_value_str
			);
			updateFilterCount(row + 1);
			row++;
		}
		if (m_need_stop_filter) {
			break;
		}
		handleEvents();
	}

	return tmp_list_data;
}

void CMemToolDlg::showBetweenValue(bool show)
{
	if (show) {
		m_compare_value.ShowWindow(false);
		m_compare_min_value.ShowWindow(true);
		m_compare_max_value.ShowWindow(true);
	}
	else {
		m_compare_value.ShowWindow(true);
		m_compare_min_value.ShowWindow(false);
		m_compare_max_value.ShowWindow(false);
	}
}

void CMemToolDlg::updateFilterCount(int count)
{
	CString str;
	str.Format(L"%d条", count);
	m_filter_result.SetWindowText(str);
}