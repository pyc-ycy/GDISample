
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
#include <gdiplusheaders.h>
#include <gdiplusbase.h>
#include <gdipluscolor.h>
#include <gdiplustypes.h>
#include <math.h>
#pragma comment(lib, "gdiplus.lib")
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
	ON_COMMAND(ID_MENUITEM_MEMDC, &CGDISampleView::OnMenuitemMemdc)
	ON_COMMAND(ID_MENUITEM_GEOMETRICPEN, &CGDISampleView::OnMenuitemGeometricpen)
	ON_COMMAND(ID_MENUITEM_CROSSLINE, &CGDISampleView::OnMenuitemCrossline)
	ON_COMMAND(ID_MENUITEM_FUNDRAW, &CGDISampleView::OnMenuitemFundraw)
	ON_COMMAND(ID_MENUITEM_MULTIBRUSH, &CGDISampleView::OnMenuitemMultibrush)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEM_CLOCK, &CGDISampleView::OnMenuitemClock)
	ON_COMMAND(ID_MENUITEM_FILLRECT, &CGDISampleView::OnMenuitemFillrect)
	ON_COMMAND(ID_MENUITEM_COLORCHANGE, &CGDISampleView::OnMenuitemColorchange)
	ON_COMMAND(ID_MENUITEM_DRAW_COLORCHANGE, &CGDISampleView::OnMenuitemDrawColorchange)
	ON_COMMAND(ID_MENUITEM_SAVEMETAFILE, &CGDISampleView::OnMenuitemSavemetafile)
	ON_COMMAND(ID_MENUITEM_SHOWPICCENTER, &CGDISampleView::OnMenuitemShowpiccenter)
	ON_COMMAND(ID_MENUITEM_PICTURECOMB, &CGDISampleView::OnMenuitemPicturecomb)
	ON_COMMAND(ID_MENUITEM_SAVEDC, &CGDISampleView::OnMenuitemSavedc)
	ON_COMMAND(ID_MENUITEM_WONIULINE, &CGDISampleView::OnMenuitemWoniuline)
	ON_COMMAND(ID_MENUITEM_DRAWBEZIER, &CGDISampleView::OnMenuitemDrawbezier)
	ON_COMMAND(ID_MENUITEM_SINLINE, &CGDISampleView::OnMenuitemSinline)
	ON_COMMAND(ID_MENUITEM_RUIHUA, &CGDISampleView::OnMenuitemRuihua)
	ON_COMMAND(ID_MENUITEM_ROUHUA, &CGDISampleView::OnMenuitemRouhua)
	ON_COMMAND(ID_MENUITEM_FANSE, &CGDISampleView::OnMenuitemFanse)
	ON_COMMAND(ID_MENUITEM_HUIDU, &CGDISampleView::OnMenuitemHuidu)
	ON_COMMAND(ID_MENUITEM_FUDIAO, &CGDISampleView::OnMenuitemFudiao)
	ON_COMMAND(ID_MENUITEM_RESERVE, &CGDISampleView::OnMenuitemReserve)
	ON_COMMAND(ID_MENUITEM_RESIZE, &CGDISampleView::OnMenuitemResize)
	ON_COMMAND(ID_MENUITEM_CUT, &CGDISampleView::OnMenuitemCut)
	ON_COMMAND(ID_MENUITEM_MASAIKE, &CGDISampleView::OnMenuitemMasaike)
	ON_COMMAND(ID_MENUITEM_HBAIYE, &CGDISampleView::OnMenuitemHbaiye)
	ON_COMMAND(ID_MENUITEM_VBAIYE, &CGDISampleView::OnMenuitemVbaiye)
	ON_COMMAND(ID_MENUITEM_DRAWLINE_ON_IMAGE, &CGDISampleView::OnMenuitemDrawlineOnImage)
	ON_COMMAND(ID_MENUITEM_DRAWNETLINEONTIMG, &CGDISampleView::OnMenuitemDrawnetlineontimg)
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


void CGDISampleView::OnMenuitemMemdc()
{
	// TODO: 在此添加命令处理程序代码
	Bitmap bmp(300, 300);
	Graphics g(&bmp);
	Rect rect(0, 0, 300, 300);
	LinearGradientBrush brush(rect, Color::Green, Color::Blue, LinearGradientModeHorizontal);
	// 循环输出矩形
	for (int j = 0; j < 60; j++)
	{
		for (int i = 0; i < 60; i++)
		{
			g.FillEllipse(&brush, i * 5, j * 5, 5, 5);
		}
	}
	Graphics graphics(m_hWnd);
	graphics.DrawImage(&bmp, 0, 0);
}


void CGDISampleView::OnMenuitemGeometricpen()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 0, 255);
	lb.lbHatch = HS_CROSS;
	// 创建几何画笔
	HPEN hPen = ExtCreatePen(PS_GEOMETRIC | PS_ENDCAP_SQUARE | PS_JOIN_ROUND, 10, &lb, 0, NULL);
	if (hPen == NULL)
	{
		MessageBox(L"提示", L"创建几何画笔失败");
		return;
	}
	CPen newPen;
	if (newPen.Attach(hPen))
	{
		CPen* pOldPen = pDC->SelectObject(&newPen);
		CRect rect;
		GetClientRect(&rect);
		rect.top = rect.Height() / 4;
		rect.bottom = rect.top * 3;
		rect.left = rect.Width() / 4;
		rect.right = rect.left * 3;
		pDC->Rectangle(&rect);
	}
	else
	{
		MessageBox(L"提示", L"创建几何画笔失败");
		return;
	}
}


void CGDISampleView::OnMenuitemCrossline()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CPen newPen;
	if (newPen.CreatePen(PS_SOLID, 2, RGB(125, 125, 125)))
	{
		const int HC = 9;
		const int VC = 9;
		CPen* pOldPen = pDC->SelectObject(&newPen);
		CRect rect;
		GetClientRect(&rect);
		int dx = rect.Width() / (HC - 1);
		int dy = rect.Height() / (VC - 1);
		CPoint(*Point)[VC] = new CPoint[HC][VC];
		for (int i = 0; i < HC; i++)
		{
			for (int j = 0; j < VC; j++)
			{
				Point[i][j].x = i*dx;
				Point[i][j].y = j*dy;
			}
		}
		for(int i=0;i<HC;i++)   
		{   
			pDC->MoveTo(Point[i][0]);   
			pDC->LineTo(Point[i][VC-1]);   
		}   
		for(int j=0;j<VC;j++)   
		{   
			pDC->MoveTo(Point[0][j]);   
			pDC->LineTo(Point[HC-1][j]);   
		} 	
		pDC->SelectObject(pOldPen);
	}
	else
	{
		MessageBox(L"网格绘制失败",L"提示");
	}
}


void CGDISampleView::OnMenuitemFundraw()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CPen newPen;
	if (newPen.CreatePen(PS_SOLID, 2, RGB(125, 125, 125)))
	{
		const int HC = 9;
		const int VC = 9;
		CPen* pOldPen = pDC->SelectObject(&newPen);
		CRect rect;
		GetClientRect(&rect);
		int dx = rect.Width() / (HC - 1);
		int dy = rect.Height() / (VC - 1);
		CPoint(*Point)[VC] = new CPoint[HC][VC];
		for (int i = 0; i < HC; i++)
		{
			for (int j = 0; j < VC; j++)
			{
				Point[i][j].x = i * dx;
				Point[i][j].y = j * dy;
			}
		}
		pDC->MoveTo(rect.left, rect.bottom);
		for (int i = 0; i < HC; i++)
		{
			for (int j = 0; j < VC; j++)
			{
				pDC->LineTo(Point[i][j].x, Point[i][j].y);
				pDC->MoveTo(Point[i][j].x, Point[i][j].y);
			}
		}
		pDC->SelectObject(pOldPen);
	}
	else
	{
		MessageBox(L"网格绘制失败", L"提示");
	}
}


void CGDISampleView::OnMenuitemMultibrush()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(255, 255, 0));
	CRect rect;
	GetClientRect(&rect);
	int width = rect.Width()/4;	//将客户区域分为四部分
	rect.right = width;
	pDC->FillRect(&rect, &newBrush);
	::DeleteObject((HGDIOBJ)newBrush);
	CBrush newBrush1;
	newBrush1.CreateHatchBrush(HS_CROSS, RGB(0, 255, 255));
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush1);
	::DeleteObject((HGDIOBJ)newBrush1);
	LOGBRUSH logBrush;
	logBrush.lbColor = RGB(255, 0, 255);
	logBrush.lbHatch = HS_HORIZONTAL;
	logBrush.lbStyle = BS_HATCHED;

	CBrush newBrush2;
	newBrush2.CreateBrushIndirect(&logBrush);
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush2);
	::DeleteObject((HGDIOBJ)newBrush2);

	CBrush newBrush3;
	newBrush3.CreateSysColorBrush(HS_VERTICAL);
	rect.left += width;
	rect.right += width;
	pDC->FillRect(&rect, &newBrush3);
	::DeleteObject((HGDIOBJ)newBrush3);
}

void CGDISampleView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 200)
	{
		//绘制钟表盘
		Graphics graphics(m_hWnd);
		int width = 300;
		int height = 300;
		Rect outRect(0, 0, width, height);
		Rect midRect(6, 6, 288, 288);
		Rect inRect(9, 9, 282, 282);

		LinearGradientBrush outBrush(outRect, Color(0, 125, 0), Color(0, 255, 0), LinearGradientModeBackwardDiagonal);
		LinearGradientBrush midBrush(midRect, Color(0, 255, 0), Color(0, 125, 0), LinearGradientModeBackwardDiagonal);
		LinearGradientBrush inBrush(inRect, Color(0, 125, 0), Color(0, 255, 0), LinearGradientModeBackwardDiagonal);

		graphics.FillEllipse(&outBrush, outRect);
		graphics.FillEllipse(&midBrush, midRect);
		graphics.FillEllipse(&inBrush, inRect);

		//绘制刻度	
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 20, FontStyleBold);
		SolidBrush whiteBrush(Color(255, 255, 255, 255));
		graphics.DrawString(L"12", -1, &font, PointF(130, 10), &whiteBrush);
		graphics.DrawString(L"6", -1, &font, PointF(140, 265), &whiteBrush);
		graphics.DrawString(L"3", -1, &font, PointF(270, 140), &whiteBrush);
		graphics.DrawString(L"9", -1, &font, PointF(10, 140), &whiteBrush);
		graphics.DrawString(L"1", -1, &font, PointF(200, 30), &whiteBrush);
		graphics.DrawString(L"2", -1, &font, PointF(250, 80), &whiteBrush);
		graphics.DrawString(L"5", -1, &font, PointF(205, 245), &whiteBrush);
		graphics.DrawString(L"4", -1, &font, PointF(250, 200), &whiteBrush);
		graphics.DrawString(L"11", -1, &font, PointF(65, 30), &whiteBrush);
		graphics.DrawString(L"10", -1, &font, PointF(20, 80), &whiteBrush);
		graphics.DrawString(L"7", -1, &font, PointF(65, 245), &whiteBrush);
		graphics.DrawString(L"8", -1, &font, PointF(25, 200), &whiteBrush);

		//绘制指针 
		graphics.TranslateTransform(150, 150, MatrixOrderAppend);
		Pen hourPen(Color(255, 0, 255, 0), 7); //时针
		hourPen.SetLineCap(LineCapRoundAnchor, LineCapArrowAnchor, DashCapFlat);
		Pen minutePen(Color(255, 0, 0, 255), 4); //分针
		minutePen.SetLineCap(LineCapRoundAnchor, LineCapArrowAnchor, DashCapFlat);
		Pen secondPen(Color(255, 255, 0, 0), 2); //秒针

		CTime time = CTime::GetCurrentTime();
		int sec = time.GetSecond();
		int min = time.GetMinute();
		int hour = time.GetHour();

		const double pi = 3.1415926;
		double secondAngle = 2.0 * pi * sec / 60.0;
		double minuteAngle = 2.0 * pi * (min + sec / 60.0) / 60.0;
		double hourAngle = 2.0 * pi * (hour + min / 60.0) / 12.0;

		Point centre(0, 0);

		Point hourHand((int)(40 * sin(hourAngle)), (int)(-40 * cos(hourAngle)));
		graphics.DrawLine(&hourPen, centre, hourHand);

		Point minHand((int)(80 * sin(minuteAngle)), (int)(-80 * cos(minuteAngle)));
		graphics.DrawLine(&minutePen, centre, minHand);

		Point secHand((int)(80 * sin(secondAngle)), (int)(-80 * cos(secondAngle)));
		graphics.DrawLine(&secondPen, centre, secHand);
	}
	CView::OnTimer(nIDEvent);
}

void CGDISampleView::OnMenuitemClock()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(200, 1000, NULL);
}


void CGDISampleView::OnMenuitemFillrect()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CBrush backBrush(RGB(255, 100, 50));
	CRect rect;
	GetClientRect(&rect);
	rect.top = rect.Height() / 4;
	rect.bottom = rect.top * 3;
	rect.left = rect.Width() / 4;
	rect.right = rect.left * 3;
	pDC->FillRect(&rect, &backBrush);
}


void CGDISampleView::OnMenuitemColorchange()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	int i = 0, j = 0;
	for(i=0;i<255;i++)
		for (j = 0; j < 255; j++)
		{
			DWORD dwColor = (unsigned long)(0x00000000 | 0 | j << 8 | i);
			pDC->SetPixel(i, j, dwColor);
		}
}


void CGDISampleView::OnMenuitemDrawColorchange()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	TRIVERTEX vert[2];
	GRADIENT_RECT gRect;
	vert[0].x = rect.left;
	vert[0].y = rect.top;
	vert[0].Red = 0xff00;
	vert[0].Green = 0x0000;
	vert[0].Blue = 0x0000;
	vert[0].Alpha = 0;
	vert[1].x = rect.right;
	vert[1].y = rect.bottom;
	vert[1].Red = 0x0000;
	vert[1].Green = 0xff00;
	vert[1].Blue = 0x0000;
	vert[1].Alpha = 0;
	gRect.UpperLeft = 0;
	gRect.LowerRight = 1;
	//绘制渐变矩形
	GradientFill(pDC->GetSafeHdc(), vert, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
}


void CGDISampleView::OnMenuitemSavemetafile()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	Status status = GenericError;
	Metafile metafile(L"MFSample.emf", pDC->m_hDC);		//定义图元文件变量
	{
		Graphics graphics(&metafile);
		status = graphics.GetLastStatus();	//获取装载状态
		if (status != Ok)
			return;
		Pen pen(Color(255, 0, 255, 0));
		status = pen.GetLastStatus();	// 获取创建状态
		if (status != Ok)
			return;
		SolidBrush solidBrush(Color(255, 0, 255, 255));
		status = solidBrush.GetLastStatus();
		if (status != Ok)
			return;
		CRect rect;
		GetClientRect(&rect);
		int nLeft = (rect.Width()) / 2;
		int nTop = (rect.Height()) / 2;
		Gdiplus::Rect rt(0, 0, nLeft, nTop);
		Gdiplus::Rect rt1(nLeft, nTop, nLeft / 2, nTop/2);
		graphics.DrawRectangle(&pen,rt);
		graphics.FillEllipse(&solidBrush, rt1);
		graphics.SetSmoothingMode(SmoothingModeHighQuality);
	}
	Graphics graphics(pDC->m_hDC);
	graphics.DrawImage(&metafile, 0, 0);
}


void CGDISampleView::OnMenuitemShowpiccenter()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"baby.JPG");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	CRect rect;
	GetClientRect(&rect);
	int nLeft = 10;
	int nTop = 20;
	graphics.DrawImage(&image, nLeft, nTop, rect.Width() - 2 * nLeft, rect.Height() - 2 * nTop);
}


void CGDISampleView::OnMenuitemPicturecomb()
{
	// TODO: 在此添加命令处理程序代码
	Graphics graphics(m_hWnd);
	Bitmap bg(L"girl1.jpg");
	int bgWidth = bg.GetWidth();
	int bgHeight = bg.GetHeight();
	graphics.DrawImage(&bg, 0, 0, bgWidth, bgHeight);
	Bitmap fg(L"girl2.jpg");
	int fgWidth = fg.GetWidth();
	int fgHeight = fg.GetHeight();
	Color color, colorTemp;
	// 使用 for 循环融合两幅图片的各个对应点的像素
	for (int iRow = 0; iRow < fgHeight; iRow++)
	{
		for (int iColumn = 0; iColumn < fgWidth; iColumn++)
		{
			fg.GetPixel(iColumn, iRow, &color);
			colorTemp.SetValue(color.MakeARGB(150, color.GetRed(), color.GetGreen(), color.GetBlue()));
			fg.SetPixel(iColumn, iRow, colorTemp);
		}
	}
	// 绘制融合后的图片
	graphics.DrawImage(&fg, 0, 0, fgWidth, fgHeight);
}


void CGDISampleView::OnMenuitemSavedc()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	CPen newPen;
	if (newPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 255)))
	{
		int saved = pDC->SaveDC();
		pDC->SelectObject(&newPen);
		CRect rect;
		GetClientRect(&rect);
		pDC->MoveTo(0, 0);
		pDC->LineTo(rect.Width(), rect.Height());
		pDC->RestoreDC(saved);
		pDC->MoveTo(rect.Width(), 0);
		pDC->LineTo(0, rect.Height());
	}
}


void CGDISampleView::OnMenuitemWoniuline()
{
	// TODO: 在此添加命令处理程序代码
	float pi = 3.1415926f;
	CRect rect;
	GetClientRect(&rect);
	UINT width = rect.Width();
	UINT height = rect.Height();
	CDC* pDC = GetDC();
	// 根据蜗牛线的算法绘制蜗牛曲线
	for (float x = 0; x < 10 * pi; x += pi / width)
	{
		if (x == 0) pDC->SetPixel(width / 2, 0, RGB(255, 0, 0));
		else pDC->SetPixel(width * sin(x) / x * cos(x) + width / 2, width*sin(x)/x*sin(x), RGB(255, 0, 0));
	}
}


void CGDISampleView::OnMenuitemDrawbezier()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();
	//定义贝塞尔曲线点集合
	CPoint pt[] = { CPoint(40,72),CPoint(107,302),
					CPoint(329, 292),CPoint(79, 148),
		CPoint(498, 29),CPoint(322, 201),CPoint(176, 137)
	};
	pDC->PolyBezier(pt, sizeof(pt) / sizeof(pt[0]));	//绘制贝塞尔曲线
}


void CGDISampleView::OnMenuitemSinline()
{
	// TODO: 在此添加命令处理程序代码
	float pi = 3.1415926f;
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	CRect rect;
	GetClientRect(&rect);
	UINT width = rect.Width();
	UINT height = rect.Height();
	Pen bluePen(Color(255, 0, 0, 255), 1);
	graphics.DrawLine(&bluePen, 0, height / 2, width, height / 2);
	Pen redPen(Color(255, 255, 0, 0), 2);
	float oldx = 0.0, oldy = (width/2);
	//绘制正弦曲线
	for (float x = 0; x < width; x++)
	{
		float radian = x / width * pi * 10;
		float y = sin(radian);
		y = (1 - y) * height / 2;
		graphics.DrawLine(&redPen, oldx, oldy, x, y);
		oldx = x;
		oldy = y;
	}
}


void CGDISampleView::OnMenuitemRuihua()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Bitmap oldBitmap(L"girl.jpg");
	status = oldBitmap.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;
	//绘制原图像
	graphics.DrawImage(&oldBitmap, 10, 0, width, height);
	// 拉普拉斯模板
	int Laplacian[] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
	// 使用锐化模板计算锐化后的图像
	for (int x = 1; x < width; x++)
	{
		for (int y = 1; y < height; y++)
		{
			int r = 0, g = 0, b = 0;
			int Index = 0;
			for(int col=-1;col<=1;col++)
				for (int row = -1; row <= 1; row++)
				{
					oldBitmap.GetPixel(x + row, y + col, &pixel);
					r += pixel.GetRed() * Laplacian[Index];
					g += pixel.GetGreen() * Laplacian[Index];
					b += pixel.GetBlue() * Laplacian[Index];
					Index++;
				}
			if (r > 255)
				r = 255;
			else if (r < 0)
				r = -r;
			if (g > 255)
				g = 255;
			else if (g < 0)
				g = -g;
			if (b > 255)
				b = 255;
			else if (b < 0)
				b = -b;
			pixel.SetFromCOLORREF(RGB(r, g, b));
			newBitmap.SetPixel(x - 1, y - 1, pixel);
		}
	}
	graphics.DrawImage(&newBitmap, width + 20, 0, width, height);
}


void CGDISampleView::OnMenuitemRouhua()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Bitmap oldBitmap(L"girl.jpg");
	if (status != Ok)
		return;
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;
	graphics.DrawImage(&oldBitmap, 10, 0, width, height);
	int smoothGauss[9] = { 1,2,1,2,4,2,1,2,1 };	// 高斯模板
	//使用高斯模板计算柔滑后的图像
	for (int x = 1; x < width; x++)
	{
		for (int y = 1; y < height; y++)
		{
			int r = 0, g = 0, b = 0;
			int Index = 0;
			for(int col=-1;col<=1;col++)
				for (int row = -1; row <= 1; row++)
				{
					oldBitmap.GetPixel(x + row, y + col, &pixel);
					r += pixel.GetRed() * smoothGauss[Index];
					g += pixel.GetGreen() * smoothGauss[Index];
					b += pixel.GetBlue() * smoothGauss[Index];
					Index++;
				}
			r = (r / 16);
			g = (g / 16);
			b = (b / 16);
			if (r > 255)
				r = 255;
			else if (r < 0)
				r = -r;
			if (g > 255)
				g = 255;
			else if (g < 0)
				g = -g;
			if (b > 255)
				b = 255;
			else if (b < 0)
				b = -b;
			pixel.SetFromCOLORREF(RGB(r, g, b));
			newBitmap.SetPixel(x - 1, y - 1, pixel);
		}
	}
	//绘制柔化后的图像
	graphics.DrawImage(&newBitmap, width + 20, 0, width, height);
}


void CGDISampleView::OnMenuitemFanse()
{
	// TODO: 在此添加命令处理程序代码
	//反色矩阵
	ColorMatrix colorMatrix = {
		-1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,
		0.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,
		1.0f,1.0f,1.0f,1.0f,1.0f
	};
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"girl.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	ImageAttributes imageAttributes;
	Rect destRect1(width+ 20, 10, width, height);
	// 设置图像的反色矩阵
	imageAttributes.SetColorMatrix(&colorMatrix,
		ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);
	graphics.DrawImage(&image, 10, 10, width, height);
	graphics.DrawImage(&image, destRect1, 0, 0, width , height, UnitPixel, &imageAttributes);
}


void CGDISampleView::OnMenuitemHuidu()
{
	// TODO: 在此添加命令处理程序代码
	//灰度矩阵
	ColorMatrix colorMatrix = {
		0.299f,0.299f,0.299f,0.0f,0.0f,
		0.587f,0.587f,0.587f,0.0f,0.0f,
		0.114f,0.114f,0.114f,0.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"girl.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	ImageAttributes imageAttributes;
	Rect destRect1(width + 20, 10, width, height);
	//设置图像的反色矩阵
	imageAttributes.SetColorMatrix(&colorMatrix, ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);
	graphics.DrawImage(&image, 10, 10, width, height);
	// 绘制灰度图像
	graphics.DrawImage(&image, destRect1, 0, 0, width, height, UnitPixel, &imageAttributes);
}


void CGDISampleView::OnMenuitemFudiao()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Bitmap oldBitmap(L"girl.jpg");
	status = oldBitmap.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = oldBitmap.GetWidth();
	UINT height = oldBitmap.GetHeight();
	Bitmap newBitmap(width, height);
	Color pixel1, pixel2, pixel;
	graphics.DrawImage(&oldBitmap, 10, 0, width, height);
	for (int x = 0; x < width - 1; x++)
	{
		for (int y = 0; y < height - 1; y++)
		{
			int r = 0, g = 0, b = 0;
			oldBitmap.GetPixel(x, y, &pixel1);
			oldBitmap.GetPixel(x + 1, y + 1, &pixel2);
			r = abs(pixel1.GetRed() - pixel2.GetRed() + 128);
			g = abs(pixel1.GetGreen() - pixel2.GetGreen() + 128);
			b = abs(pixel1.GetBlue() - pixel2.GetBlue() + 128);
			if (r > 255)
				r = 255;
			if (r < 0)
				r = 0;
			if (g > 255)
				g = 255;
			if (g < 0)
				g = 0;
			if (b > 255)
				b = 255;
			if (b < 0)
				b = 0;
			pixel.SetFromCOLORREF(RGB(r, g, b));
			newBitmap.SetPixel(x, y, pixel);
		}
	}
	// 绘制经过浮雕效果转换的位图
	graphics.DrawImage(&newBitmap, width + 20, 0, width, height);
}


void CGDISampleView::OnMenuitemReserve()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"girl.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	graphics.DrawImage(&image, 10, 0, width, height);
	image.RotateFlip(Rotate180FlipX);
	width = image.GetWidth();
	height = image.GetHeight();
	// 绘制翻转后的图像
	graphics.DrawImage(&image, 20 + width, 0, width, height);
}


void CGDISampleView::OnMenuitemResize()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"girl.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	graphics.DrawImage(&image, 10, 0, width, height);
	// 缩放 4 倍
	graphics.DrawImage(&image, width + 20, 0, width * 2, height * 2);
}


void CGDISampleView::OnMenuitemCut()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	Image image(L"yn.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	Rect destRect1(width + 20, 20, 150, 150);	//小范围
	Rect destRect2(width + 20, 200, 320, 320);	//大范围
	graphics.DrawImage(&image, 0, 0, width, height);	//原始图像
	graphics.DrawImage(&image, destRect1, 240, 475, 135, 135, UnitPixel);	//绘制缩小剪切
	graphics.DrawImage(&image, destRect2, 240, 475, 135, 135, UnitPixel);	//绘制放大剪切
}


void CGDISampleView::OnMenuitemMasaike()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	graphics.Clear(Color::White);
	Image image(L"wyn.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int dw = width / 50;
	int dh = height / 50;
	int points[2500] = { 0 };
	int ncount = 0;
	// 使用 while 循环输出马赛克效果
	while (ncount < 80)
	{
		int index = rand() % 2500;
		if (points[index] == 0)
		{
			ncount++;
			points[index] = 1;
			int m = index / 50;
			int n = index % 50;
			Rect destRect(dw * m, dh * n, (m + 1) * dw, (n + 1) * dh);
			// 绘制马赛克图像块
			graphics.DrawImage(&image, destRect, dw * m, dh * n, (m + 1) * dw, (n + 1) * dh, UnitPixel);
		}
		Sleep(10);
	}
}


void CGDISampleView::OnMenuitemHbaiye()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	graphics.Clear(Color::White);
	Image image(L"雅男.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int nPixes = 30;
	int nNum = width / nPixes;
	for (int i = 0; i < nPixes; i++)
	{
		for (int j = 0; j < nNum; j++)
		{
			// 分别扫描条
			Rect destRect1(j * nPixes + i, 0, 1, height);
			// 绘制每条百叶条的图像
			graphics.DrawImage(&image, destRect1, j * nPixes + i, 0, 1, height, UnitPixel);
		}
		Sleep(10);
	}
}


void CGDISampleView::OnMenuitemVbaiye()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	graphics.Clear(Color::White);
	Image image(L"雅男.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	int nPixes = 15;
	int nNum = height / nPixes;		// 计算垂直百叶窗的个数
	for (int i = 0; i < nPixes; i++)
	{
		for (int j = 0; j < nNum; j++)
		{
			Rect destRect(0, j * nPixes + i, width, 1);
			// 绘制每条百叶窗的图像
			graphics.DrawImage(&image, destRect, 0, j * nPixes + i, width, 1, UnitPixel);
		}
		Sleep(50);
	}
}


void CGDISampleView::OnMenuitemDrawlineOnImage()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	graphics.Clear(Color::White);
	Image image(L"baby1.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	// 计算线条区域
	Rect destRect(width + 20, 10, width, height);
	graphics.DrawImage(&image, 10, 10, width, height);
	//绘制目标区域
	graphics.DrawImage(&image, destRect, 0, 0, width, height, UnitPixel);
	Pen pen(Color(255, 255, 0, 0), 3);
	int nLineCount = 18;
	int h = height / (nLineCount - 1);	//计算画笔宽度
	//绘制线条
	for (int i = 0; i < nLineCount; i++)
		graphics.DrawLine(&pen, width + 20, h * i + 10, width * 2 + 20, h * i + 10);
}


void CGDISampleView::OnMenuitemDrawnetlineontimg()
{
	// TODO: 在此添加命令处理程序代码
	Status status = GenericError;
	Graphics graphics(m_hWnd);
	status = graphics.GetLastStatus();
	if (status != Ok)
		return;
	graphics.Clear(Color::White);
	Image image(L"baby1.jpg");
	status = image.GetLastStatus();
	if (status != Ok)
		return;
	UINT width = image.GetWidth();
	UINT height = image.GetHeight();
	// 计算线条区域
	Rect destRect(width + 20, 10, width, height);
	graphics.DrawImage(&image, 10, 10, width, height);
	//绘制目标区域
	graphics.DrawImage(&image, destRect, 0, 0, width, height, UnitPixel);
	Pen pen(Color(255, 255, 0, 0), 3);
	int nXCount = 18;
	int nYCount = 18;
	//绘制横线
	int h = height / (nYCount - 1);
	for(int i=1;i<nXCount;i++)
		graphics.DrawLine(&pen, width + 20, h * i + 10, width * 2 + 20, h * i + 10);
	//绘制纵线
	int w = width / (nYCount - 1);
	for (int i = 0; i < nYCount; i++)
		graphics.DrawLine(&pen, w * i + 20 + width, 10, w * i + 20 + width, 10 + height);
}
