
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
};

#ifndef _DEBUG  // GDISampleView.cpp 中的调试版本
inline CGDISampleDoc* CGDISampleView::GetDocument() const
   { return reinterpret_cast<CGDISampleDoc*>(m_pDocument); }
#endif

