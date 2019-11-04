#pragma once


// CDlgEllip 对话框

class CDlgEllip : public CDialog
{
	DECLARE_DYNAMIC(CDlgEllip)

public:
	CRgn m_rgnWnd;
	CDlgEllip(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgEllip();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ELLIPSEWND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
