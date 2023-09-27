
// MemToolDlg.h: 头文件
//

#pragma once


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

// 用户函数
protected:
	void initListCtr();
	void initCheckBoxs();
	void initComboxs();
	void insertRowData(int row, CString addr, CString pointer, CString int_str, CString long_str, CString float_str, CString double_str, CString str, CString res);
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
};
