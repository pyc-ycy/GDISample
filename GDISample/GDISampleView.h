
// GDISampleView.h: CGDISampleView 类的接口
//

#pragma once

class CGDISampleView : public CView
{
protected: // 仅从序列化创建
	CGDISampleView() noexcept;
	DECLARE_DYNCREATE(CGDISampleView)

// 特性
public:
	CGDISampleDoc* GetDocument() const;

// 操作
public:
	CPoint beginPoint;
	CPoint endPoint;
	int OperType;//1--保留椭圆中内容
	CRect rect;
	CPoint forePoint;
	BOOL bSelectedImage;
	HANDLE hThread;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CGDISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnMenuBitmap();
	afx_msg void OnMenuitemRegion();
	afx_msg void OnMenuitemPen();
	afx_msg void OnMenuitemBrush();
	afx_msg void OnMenuitemBitmapbrush();
	afx_msg void OnMenuitemSavescreentofile();
	afx_msg void OnMenuitemMemdc();
	afx_msg void OnMenuitemGeometricpen();
	afx_msg void OnMenuitemCrossline();
	afx_msg void OnMenuitemFundraw();
	afx_msg void OnMenuitemMultibrush();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMenuitemClock();
	afx_msg void OnMenuitemFillrect();
	afx_msg void OnMenuitemColorchange();
	afx_msg void OnMenuitemDrawColorchange();
	afx_msg void OnMenuitemSavemetafile();
	afx_msg void OnMenuitemShowpiccenter();
	afx_msg void OnMenuitemPicturecomb();
	afx_msg void OnMenuitemSavedc();
	afx_msg void OnMenuitemWoniuline();
	afx_msg void OnMenuitemDrawbezier();
	afx_msg void OnMenuitemSinline();
	afx_msg void OnMenuitemRuihua();
	afx_msg void OnMenuitemRouhua();
	afx_msg void OnMenuitemFanse();
	afx_msg void OnMenuitemHuidu();
	afx_msg void OnMenuitemFudiao();
	afx_msg void OnMenuitemReserve();
	afx_msg void OnMenuitemResize();
	afx_msg void OnMenuitemCut();
	afx_msg void OnMenuitemMasaike();
	afx_msg void OnMenuitemHbaiye();
	afx_msg void OnMenuitemVbaiye();
	afx_msg void OnMenuitemDrawlineOnImage();
	afx_msg void OnMenuitemDrawnetlineontimg();
	afx_msg void OnMenuitemOpenhighimg();
	//鼠标事件
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMenuitemDrag();
	afx_msg void OnMenuitemScreencut();
	afx_msg void OnMenuitemGetrgb();
	afx_msg void OnMenuitemShimage();
	afx_msg void OnMenuitemSaveellipsepcontent();
	afx_msg void OnMenuitemCutellipcontent();
};

#ifndef _DEBUG  // GDISampleView.cpp 中的调试版本
inline CGDISampleDoc* CGDISampleView::GetDocument() const
   { return reinterpret_cast<CGDISampleDoc*>(m_pDocument); }
#endif

