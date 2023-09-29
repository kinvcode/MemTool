
// MemToolDlg.h: 头文件
//

#pragma once
#include <unordered_map>
#include <vector>

using namespace std;

struct LISTROWDATA {
	CString addr_str;	// 地址表达式字符串
	CString pointer_str;// 指针字符串
	int int_num;		// 整数
	CString int_str;	// 整数字符串
	__int64 int64_num;	// 长整数
	CString int64_str;	// 长整数字符串
	float float_num;	// 浮点数
	CString float_str;	// 浮点数字符串
	double double_num;	// 双精度浮点数
	CString double_str;	// 双精度浮点数字符串
	CString text;		// 文本
	int decrypt_value;	// 解密值
	CString decrypt_value_str;	// 解密值字符串
};

// CMemToolDlg 对话框
class CMemToolDlg : public CDialogEx
{
	// 构造
public:
	CMemToolDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMTOOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 数据
public:
	// 基址与偏移数值
	__int64 m_base_address_numeric = -1;
	__int64 m_offset1_numeric = -1;
	__int64 m_offset2_numeric = -1;
	__int64 m_offset3_numeric = -1;
	__int64 m_offset4_numeric = -1;
	__int64 m_offset5_numeric = -1;
	__int64 m_offset6_numeric = -1;
	__int64 m_offset7_numeric = -1;
	__int64 m_offset8_numeric = -1;
	__int64 m_offset9_numeric = -1;
	__int64 m_offset10_numeric = -1;
	// 循环遍历勾选状态
	bool m_loop1_checked = false;
	bool m_loop2_checked = false;
	bool m_loop3_checked = false;
	bool m_loop4_checked = false;
	bool m_loop5_checked = false;
	// 循环遍历递增数值指针
	__int64* m_loop1_inc_item = nullptr;
	__int64* m_loop2_inc_item = nullptr;
	__int64* m_loop3_inc_item = nullptr;
	__int64* m_loop4_inc_item = nullptr;
	__int64* m_loop5_inc_item = nullptr;
	// 循环遍历次数
	int m_loop1_num = 0;
	int m_loop2_num = 0;
	int m_loop3_num = 0;
	int m_loop4_num = 0;
	int m_loop5_num = 0;
	// 循环遍历递增
	int m_inc1_num = 0;
	int m_inc2_num = 0;
	int m_inc3_num = 0;
	int m_inc4_num = 0;
	int m_inc5_num = 0;
	// 是否停止搜索
	bool m_need_stop_search = false;
	// 是否停止过滤
	bool m_need_stop_filter = false;
	// 64位数据映射
	unordered_map<__int64, __int64> m_bit64_map;
	// 行数据映射
	unordered_map<__int64, LISTROWDATA> m_data_map;
	// 列表数据容器
	vector<LISTROWDATA> m_list_data;

	// 用户函数
public:
	void initListCtr();
	void initCheckBoxs();
	void initComboxs();
	// 插入一行数据
	void insertRowData(int row, CString addr, CString pointer, CString int_str, CString long_str, CString float_str, CString double_str, CString str, CString res);
	// 检查递增选项是否合法
	bool checkIncSel(int cur);
	// 根据递增索引获取数值
	__int64* getIncByIndex(int index);
	// 处理当前行的数据
	void rowData(HANDLE handle, int row);
	// 初始化基址与偏移数值
	bool initBaseAndOffset();
	// 初始化循环遍历勾选状态
	void initLoopCheckbox();
	// 初始化循环与递增
	bool initLoopAndInc();
	// 检测一层遍历
	bool verifyLoop1();
	// 检测二层遍历
	bool verifyLoop2();
	// 检测三层遍历
	bool verifyLoop3();
	// 检测四层遍历
	bool verifyLoop4();
	// 检测五层遍历
	bool verifyLoop5();
	// 从缓存中读取地址
	__int64 readLongByMap(HANDLE handle, __int64 address);
	// 从缓存中读取一行数据
	LISTROWDATA readRowDataByMap(HANDLE handle, __int64 address, __int64 tmp_pointer, CString th_addr);
	// 更新当前搜索进度
	void updateSearchPos(int index, int count);
	// 初始化过滤器
	void initFilter();
	// 整数相等
	vector<LISTROWDATA> intEqual();
	// 整数大于
	vector<LISTROWDATA> intGreaterThan();
	// 整数小于
	vector<LISTROWDATA> intLessThan();
	// 整数不等于
	vector<LISTROWDATA> intnotEqual();
	// 整数两者之间
	vector<LISTROWDATA> intBetween();
	// 长整数相等
	vector<LISTROWDATA> int64Equal();
	// 长整数大于
	vector<LISTROWDATA> int64GreaterThan();
	// 长整数小于
	vector<LISTROWDATA> int64LessThan();
	// 长整数不等于
	vector<LISTROWDATA> int64notEqual();
	// 长整数两者之间
	vector<LISTROWDATA> int64Between();
	// 浮点数相等
	vector<LISTROWDATA> floatEqual();
	// 浮点数大于
	vector<LISTROWDATA> floatGreaterThan();
	// 浮点数小于
	vector<LISTROWDATA> floatLessThan();
	// 浮点数不等于
	vector<LISTROWDATA> floatnotEqual();
	// 浮点数两者之间
	vector<LISTROWDATA> floatBetween();
	// 双精度相等
	vector<LISTROWDATA> doubleEqual();
	// 双精度大于
	vector<LISTROWDATA> doubleGreaterThan();
	// 双精度小于
	vector<LISTROWDATA> doubleLessThan();
	// 双精度不等于
	vector<LISTROWDATA> doublenotEqual();
	// 双精度两者之间
	vector<LISTROWDATA> doubleBetween();
	// 解密值相等
	vector<LISTROWDATA> decryptEqual();
	// 解密值大于
	vector<LISTROWDATA> decryptGreaterThan();
	// 解密值小于
	vector<LISTROWDATA> decryptLessThan();
	// 解密值不等于
	vector<LISTROWDATA> decryptnotEqual();
	// 解密值两者之间
	vector<LISTROWDATA> decryptBetween();
	// 文本相等
	vector<LISTROWDATA> textEqual();
	// 文本包含
	vector<LISTROWDATA> textContain();
	// 显示区间编辑框
	void showBetweenValue(bool show);
	// 更新过滤结果数量
	void updateFilterCount(int count);
	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CButton m_checkbox1;
	CButton m_checkbox2;
	CButton m_checkbox3;
	CButton m_checkbox4;
	CButton m_checkbox5;
	CComboBox m_combo1;
	CComboBox m_combo2;
	CComboBox m_combo3;
	CComboBox m_combo4;
	CComboBox m_combo5;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedButton1();
	CEdit m_base_addr;
	CEdit m_offset1;
	CEdit m_offset2;
	CEdit m_offset3;
	CEdit m_offset4;
	CEdit m_offset5;
	CEdit m_offset6;
	CEdit m_offset7;
	CEdit m_offset8;
	CEdit m_offset9;
	CEdit m_offset10;
	CEdit m_loop1;
	CEdit m_loop2;
	CEdit m_loop3;
	CEdit m_loop4;
	CEdit m_loop5;
	CEdit m_inc1;
	CEdit m_inc2;
	CEdit m_inc3;
	CEdit m_inc4;
	CEdit m_inc5;
	CEdit m_pid;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnBnClickedButton2();
	CButton m_stop_search;
	CStatic m_search_pos;
	CButton m_filter_type;
	int m_filter_type_value;
	afx_msg void OnBnClickedRadio1();
	CComboBox m_filter_condition;
	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CButton m_filter_btn;
	CButton m_stop_filter_btn;
	CStatic m_filter_result;
	CEdit m_compare_value;
	CEdit m_compare_min_value;
	CEdit m_compare_max_value;
};
