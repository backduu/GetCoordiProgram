
// ProjectGetCoordiView.h: CProjectGetCoordiView 클래스의 인터페이스
//

#pragma once


class CProjectGetCoordiView : public CView
{
protected: // serialization에서만 만들어집니다.
	CProjectGetCoordiView() noexcept;
	DECLARE_DYNCREATE(CProjectGetCoordiView)

// 특성입니다.
public:
	CProjectGetCoordiDoc* GetDocument() const;

// 작업입니다.
public:
	CPoint m_pos;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CProjectGetCoordiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // ProjectGetCoordiView.cpp의 디버그 버전
inline CProjectGetCoordiDoc* CProjectGetCoordiView::GetDocument() const
   { return reinterpret_cast<CProjectGetCoordiDoc*>(m_pDocument); }
#endif

