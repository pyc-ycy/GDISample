// DlgEllip.cpp: 实现文件
//

#include "stdafx.h"
#include "GDISample.h"
#include "DlgEllip.h"
#include "afxdialogex.h"


// CDlgEllip 对话框

IMPLEMENT_DYNAMIC(CDlgEllip, CDialog)

CDlgEllip::CDlgEllip(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_ELLIPSEWND, pParent)
{

}

CDlgEllip::~CDlgEllip()
{
}

void CDlgEllip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgEllip, CDialog)
END_MESSAGE_MAP()


// CDlgEllip 消息处理程序
BOOL CDlgEllip::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(_T("椭圆对话框测试"));
	CWnd *hParent = this->GetParent();
	CenterWindow(hParent);
	CRect rect;
	this->GetClientRect(&rect);
	int nEllipseWidth = rect.Width();
	int nEllipseHeight = rect.Height();
	m_rgnWnd.CreateEllipticRgn(0, 0, nEllipseWidth, nEllipseHeight);
	SetWindowRgn((HRGN)m_rgnWnd, true);
	return true;
}