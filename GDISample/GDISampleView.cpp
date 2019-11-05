
// GDISampleView.cpp: CGDISampleView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GDISample.h"
#endif

#include "GDISampleDoc.h"
#include "GDISampleView.h"
#include "DlgEllip.h"
#include <gdiplus.h>
using namespace Gdiplus;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDISampleView

IMPLEMENT_DYNCREATE(CGDISampleView, CView)

BEGIN_MESSAGE_MAP(CGDISampleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDD_MENU_BITMAP, &CGDISampleView::OnMenuBitmap)
	ON_COMMAND(ID_MENUITEM_REGION, &CGDISampleView::OnMenuitemRegion)
	ON_COMMAND(ID_MENUITEM_PEN, &CGDISampleView::OnMenuitemPen)
	ON_COMMAND(ID_MENUITEM_BRUSH, &CGDISampleView::OnMenuitemBrush)
	ON_COMMAND(ID_MENUITEM_BITMAPBRUSH, &CGDISampleView::OnMenuitemBitmapbrush)
	ON_COMMAND(ID_MENUITEM_SAVESCREENTOFILE, &CGDISampleView::OnMenuitemSavescreentofile)
END_MESSAGE_MAP()

// CGDISampleView 构造/析构

CGDISampleView::CGDISampleView() noexcept
{
	// TODO: 在此处添加构造代码

}

CGDISampleView::~CGDISampleView()
{
}

BOOL CGDISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGDISampleView 绘图

void CGDISampleView::OnDraw(CDC* /*pDC*/)
{
	CGDISampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGDISampleView 打印

BOOL CGDISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGDISampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGDISampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CGDISampleView 诊断

#ifdef _DEBUG
void CGDISampleView::AssertValid() const
{
	CView::AssertValid();
}

void CGDISampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDISampleDoc* CGDISampleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDISampleDoc)));
	return (CGDISampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDISampleView 消息处理程序


void CGDISampleView::OnMenuBitmap()
{
	// TODO: 在此添加命令处理程序代码
	CBitmap bitmap;
	CDC *pDC = GetDC();
	bitmap.LoadBitmap(IDB_BITMAP1);
	CDC memDC;	//获取内存上下文
	memDC.CreateCompatibleDC(pDC);	//创建与pDC兼容的内存设备上下文
	memDC.SelectObject(&bitmap);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CRect rect;
	GetClientRect(&rect);
	//在设备上下文绘制位图
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
	memDC.DeleteDC();	//删除设备上下文
	::DeleteObject(&bitmap);	//删除位图对象
}


void CGDISampleView::OnMenuitemRegion()
{
	// TODO: 在此添加命令处理程序代码
	CDlgEllip dlg;
	dlg.DoModal();
}


void CGDISampleView::OnMenuitemPen()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC = GetDC();
	CPen newPen;
	if (newPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0)))
	{
		CPen* pOldPen = pDC->SelectObject(&newPen);
		RECT rect;
		GetClientRect(&rect);
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.right, rect.top);
		pDC->LineTo(rect.left, rect.bottom);
		pDC->LineTo(rect.right, rect.bottom);
		pDC->LineTo(rect.left, rect.top);
		pDC->SelectObject(pOldPen);
	}
	else
		MessageBox(L"创建画笔失败");
}


void CGDISampleView::OnMenuitemBrush()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CBrush newBrush;
	if (newBrush.CreateSolidBrush(RGB(100, 250, 255)))
	{
		RECT rect;
		GetClientRect(&rect);
		CRgn rgn;
		rgn.CreateEllipticRgn(rect.left + 10, rect.top, rect.right - 10, rect.bottom);
		pDC->FillRgn(&rgn, &newBrush);
	}
	else
		MessageBox(L"创建画刷失败！");
}


void CGDISampleView::OnMenuitemBitmapbrush()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	rect.top = rect.Height() / 4;
	rect.bottom = rect.top * 3;
	rect.left = rect.Width() / 4;
	rect.right = rect.left * 3;
	CBitmap bitmap;
	if (!bitmap.LoadBitmap(IDB_BITMAP2))
		return;
	CBrush newBrush;
	if (newBrush.CreatePatternBrush(&bitmap))
		pDC->FillRect(&rect, &newBrush);
	else
		MessageBox(L"创建位图画刷失败！");
}


int   GetEncoderClsid(const   WCHAR*   format, CLSID*   pClsid)
{
	UINT num = 0;
	UINT size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (size == 0)   return   -1;
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)   return -1;
	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return   j;
		}
	}
	free(pImageCodecInfo);
	return   -1;
}

void CGDISampleView::OnMenuitemSavescreentofile()
{
	// TODO: 在此添加命令处理程序代码
	int cx = GetSystemMetrics(SM_CXSCREEN);		//获取屏幕分辨率
	int cy = GetSystemMetrics(SM_CYSCREEN);
	//创建显示屏上下文
	HDC hScrDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
	Graphics graphics1(hScrDC);
	Bitmap bitmap(cx, cy, &graphics1);
	Graphics graphics2(&bitmap);
	HDC dc1 = graphics1.GetHDC();
	HDC dc2 = graphics2.GetHDC();	//获取设备上下文
	BitBlt(dc2, 0, 0, cx, cy, dc1, 0, 0, 13369376);	//获取位图
	graphics1.ReleaseHDC(dc1);
	graphics2.ReleaseHDC(dc2);	//释放设备上下文句柄
	CLSID clsid;
	char propertyValue[] = "屏幕截图";
	PropertyItem* propertyItem = new PropertyItem;	//创建属性页
	//将抓到的图像保存到jpg文件
	GetEncoderClsid(L"image/jpeg", &clsid);
	propertyItem->id = PropertyTagImageTitle;
	propertyItem->length = 16;
	propertyItem->type = PropertyTagTypeASCII;
	propertyItem->value = propertyValue;
	bitmap.SetPropertyItem(propertyItem);
	bitmap.Save(L"screen1.jpg", &clsid, NULL);
	CDC* pDC = GetDC();
	pDC->TextOutW(10,10,L"保存屏幕抓图到screen1.jpg");
}
