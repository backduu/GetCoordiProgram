
// ProjectGetCoordiView.cpp: CProjectGetCoordiView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ProjectGetCoordi.h"
#endif

#include "ProjectGetCoordiDoc.h"
#include "ProjectGetCoordiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjectGetCoordiView

IMPLEMENT_DYNCREATE(CProjectGetCoordiView, CView)

BEGIN_MESSAGE_MAP(CProjectGetCoordiView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProjectGetCoordiView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
//	ON_WM_MOUSEHWHEEL()
ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CProjectGetCoordiView 생성/소멸

CProjectGetCoordiView::CProjectGetCoordiView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CProjectGetCoordiView::~CProjectGetCoordiView()
{
}

BOOL CProjectGetCoordiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CProjectGetCoordiView 그리기

void CProjectGetCoordiView::OnDraw(CDC* /*pDC*/)
{
	CProjectGetCoordiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CClientDC dc(this);
	CClientDC dc2(this);

	CString strPoint;
	CString strText;
	strPoint.Format(_T("(%4d, %4d)"), m_pos.x, m_pos.y);
	strText.Format(_T("마우스 휠을 움직여보세요."));
	dc2.TextOutW(50, 50, strText);
	dc.TextOutW(m_pos.x, m_pos.y, strPoint);
}


// CProjectGetCoordiView 인쇄


void CProjectGetCoordiView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjectGetCoordiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CProjectGetCoordiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CProjectGetCoordiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CProjectGetCoordiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProjectGetCoordiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProjectGetCoordiView 진단

#ifdef _DEBUG
void CProjectGetCoordiView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectGetCoordiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectGetCoordiDoc* CProjectGetCoordiView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectGetCoordiDoc)));
	return (CProjectGetCoordiDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectGetCoordiView 메시지 처리기


void CProjectGetCoordiView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pos = point;
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


//void CProjectGetCoordiView::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
//{
//	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
//	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CView::OnMouseHWheel(nFlags, zDelta, pt);
//	CString strWheel = _T("mouse wheel has moved");
//	MessageBox(_T("mouse wheel has moved"), _T("INFO"), MB_OK);
//}


BOOL CProjectGetCoordiView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CView::OnMouseHWheel(nFlags, zDelta, pt);
	CString strWheel = _T("mouse wheel has moved");
	MessageBox(_T("mouse wheel has moved"), _T("INFO"), MB_OK);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
