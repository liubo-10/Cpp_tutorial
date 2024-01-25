
// 窗口求根View.cpp : C窗口求根View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "窗口求根.h"
#endif

#include "窗口求根Doc.h"
#include "窗口求根View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C窗口求根View

IMPLEMENT_DYNCREATE(C窗口求根View, CView)

BEGIN_MESSAGE_MAP(C窗口求根View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C窗口求根View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C窗口求根View 构造/析构

C窗口求根View::C窗口求根View()
{
	// TODO: 在此处添加构造代码

}

C窗口求根View::~C窗口求根View()
{
}

BOOL C窗口求根View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C窗口求根View 绘制

void C窗口求根View::OnDraw(CDC* /*pDC*/)
{
	C窗口求根Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C窗口求根View 打印


void C窗口求根View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C窗口求根View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C窗口求根View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C窗口求根View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C窗口求根View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C窗口求根View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C窗口求根View 诊断

#ifdef _DEBUG
void C窗口求根View::AssertValid() const
{
	CView::AssertValid();
}

void C窗口求根View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C窗口求根Doc* C窗口求根View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C窗口求根Doc)));
	return (C窗口求根Doc*)m_pDocument;
}
#endif //_DEBUG


// C窗口求根View 消息处理程序
