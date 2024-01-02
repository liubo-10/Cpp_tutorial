
// FMC_experienceView.cpp : CFMC_experienceView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FMC_experience.h"
#endif

#include "FMC_experienceDoc.h"
#include "FMC_experienceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFMC_experienceView

IMPLEMENT_DYNCREATE(CFMC_experienceView, CView)

BEGIN_MESSAGE_MAP(CFMC_experienceView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFMC_experienceView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFMC_experienceView 构造/析构

CFMC_experienceView::CFMC_experienceView()
{
	// TODO: 在此处添加构造代码

}

CFMC_experienceView::~CFMC_experienceView()
{
}

BOOL CFMC_experienceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFMC_experienceView 绘制

void CFMC_experienceView::OnDraw(CDC* /*pDC*/)
{
	CFMC_experienceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFMC_experienceView 打印


void CFMC_experienceView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFMC_experienceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFMC_experienceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFMC_experienceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFMC_experienceView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFMC_experienceView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFMC_experienceView 诊断

#ifdef _DEBUG
void CFMC_experienceView::AssertValid() const
{
	CView::AssertValid();
}

void CFMC_experienceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFMC_experienceDoc* CFMC_experienceView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFMC_experienceDoc)));
	return (CFMC_experienceDoc*)m_pDocument;
}
#endif //_DEBUG


// CFMC_experienceView 消息处理程序
