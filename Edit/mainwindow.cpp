#include<mainwindow.h>
#include <QTextEdit>
#include <QMenuBar>
#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QStatusBar>
#include <QKeySequence>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QDebug>

QtEditor::QtEditor(QWidget *parent) : QMainWindow(parent)
{
    // MDI 위젯 설정
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);

    // 텍스트 편집기 초기화
    textEdit = new QTextEdit(this);
    mdiArea->addSubWindow(textEdit);
    textEdit->show();

    // 메뉴바 설정
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File 메뉴
    QMenu *fileMenu = menubar->addMenu("&File");
    QAction *newAct = new QAction(QIcon(":/images/new.png"), "&New", this);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip(tr("Make new file"));
    connect(newAct, &QAction::triggered, this, &QtEditor::newFile);

    QAction *openAct = new QAction(QIcon(":/images/open.png"), "&Open", this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Open file"));
    connect(openAct, &QAction::triggered, this, &QtEditor::newOpen);

    QAction *saveAct = new QAction(QIcon(":/images/save.png"), "&Save", this);
    saveAct->setShortcut(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save file"));
    connect(saveAct, &QAction::triggered, this, &QtEditor::newSave);

    QAction *saveasAct = new QAction(QIcon(":/images/saveas.png"), "&Save As", this);
    saveasAct->setShortcut(QKeySequence::SaveAs);
    saveasAct->setStatusTip(tr("Save file as"));
    connect(saveasAct, &QAction::triggered, this, &QtEditor::newSaveas);

    QAction *printAct = new QAction(QIcon(":/images/print.png"), "&Print", this);
    printAct->setShortcut(QKeySequence::Print);
    printAct->setStatusTip(tr("Print file"));
    connect(printAct, &QAction::triggered, this, &QtEditor::newPrint);

    QAction *quitAct = new QAction(QIcon(":/images/quit.png"), "&Quit", this);
    quitAct->setShortcut(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit application"));
    connect(quitAct, &QAction::triggered, this, &QtEditor::newQuit);

    // File 메뉴에 액션 추가
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // 툴바 구현
    QToolBar *fileToolBar = addToolBar("&File");
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveasAct);
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    // 상태바 추가
    QStatusBar *statusbar = statusBar();
    QLabel *statusLabel = new QLabel(tr("Qt Editor"), this);
    statusLabel->setObjectName("StatusLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("Started", 15000);



    // 툴바 폰트 구현
    QFontComboBox *fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, &QFontComboBox::currentFontChanged, this, &QtEditor::setTextFont);

    QDoubleSpinBox *sizeSpinBox = new QDoubleSpinBox(this);
    sizeSpinBox->setRange(1, 100);
    connect(sizeSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &QtEditor::setTextFontSize);

    QToolBar *formatToolbar = addToolBar("&Format");
    formatToolbar->addSeparator();
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);

    // Edit 메뉴 구현
    QMenu *editMenu = menubar->addMenu("&Edit");

    QAction *undoAct = new QAction(QIcon(":/images/undo.png"), "Undo", this);
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo last action"));
    connect(undoAct, &QAction::triggered, textEdit, &QTextEdit::undo);
    editMenu->addAction(undoAct); //Edit메뉴에 삽입

    QAction *redoAct = new QAction(QIcon(":/images/redo.png"), "Redo", this);
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo last undone action"));
    connect(redoAct, &QAction::triggered, textEdit, &QTextEdit::redo);
    editMenu->addAction(redoAct);//Edit메뉴에 삽입

    editMenu->addSeparator();

    QAction *cutAct = new QAction(QIcon(":/images/cut.png"), "Cut", this);
    cutAct->setShortcut(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut selected text"));
    connect(cutAct, &QAction::triggered, textEdit, &QTextEdit::cut);
    editMenu->addAction(cutAct);

    QAction *copyAct = new QAction(QIcon(":/images/copy.png"), "Copy", this);
    copyAct->setShortcut(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy selected text"));
    connect(copyAct, &QAction::triggered, textEdit, &QTextEdit::copy);
    editMenu->addAction(copyAct);

    QAction *pasteAct = new QAction(QIcon(":/images/paste.png"), "Paste", this);
    pasteAct->setShortcut(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste from clipboard"));
    connect(pasteAct, &QAction::triggered, textEdit, &QTextEdit::paste);
    editMenu->addAction(pasteAct);

    editMenu->addSeparator();

    QAction *zoomInAct = new QAction("Zoom In", this);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    connect(zoomInAct, &QAction::triggered, textEdit, &QTextEdit::zoomIn);
    editMenu->addAction(zoomInAct);

    QAction *zoomOutAct = new QAction("Zoom Out", this);
    zoomOutAct->setShortcut(QKeySequence::ZoomOut);
    connect(zoomOutAct, &QAction::triggered, textEdit, &QTextEdit::zoomOut);
    editMenu->addAction(zoomOutAct);

    // Format 메뉴 및 Align 메뉴 추가
    QMenu *formatMenu = menubar->addMenu("&Format");
    QMenu *alignMenu = new QMenu("&Align", this);
    formatMenu->addMenu(alignMenu);

    // Left  액션 추가
    QAction *leftAlignAct = new QAction(QIcon(":/images/left.png"),"&Left ", this);
    connect(leftAlignAct, &QAction::triggered, this, [&]() {
        textEdit->setAlignment(Qt::AlignLeft);
    });
    alignMenu->addAction(leftAlignAct);

    // Center  액션 추가
    QAction *centerAlignAct = new QAction(QIcon(":/images/center.png"),"&Center ", this);
    connect(centerAlignAct, &QAction::triggered, this, [&]() {
        textEdit->setAlignment(Qt::AlignCenter);
    });
    alignMenu->addAction(centerAlignAct);

    // Right  액션 추가
    QAction *rightAlignAct = new QAction(QIcon(":/images/right.png"),"&Right ", this);
    connect(rightAlignAct, &QAction::triggered, this, [&]() {
        textEdit->setAlignment(Qt::AlignRight);
    });
    alignMenu->addAction(rightAlignAct);

    // Justify  추가
    QAction *justifyAct = new QAction(QIcon(":/images/justify.png"),"&Justify ", this);;
    connect(justifyAct, &QAction::triggered, this, [&]() {
        textEdit->setAlignment(Qt::AlignJustify);
    });
    alignMenu->addAction(justifyAct);

    // Window 메뉴 구현
    QMenu *windowMenu = menubar->addMenu("&Window");
    QMenu *toolBarMenu = windowMenu->addMenu("&ToolBar");
    toolBarMenu->addAction(fileToolBar->toggleViewAction());

    // Edit 툴바 구현
    QToolBar *editToolBar = addToolBar("&Edit");
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoomInAct);
    editToolBar->addAction(zoomOutAct);

    // Dock Widget 설정
    QWidget *dockWidgetContent = new QWidget(this);
    QLabel *label = new QLabel("Doc Widget", dockWidgetContent);
    QDockWidget *dock = new QDockWidget("Dock Widget", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(dockWidgetContent);
    toolBarMenu->addAction(dock->toggleViewAction());

}

QtEditor::~QtEditor()
{
}

void QtEditor::newFile()
{
    QTextEdit *newTextEdit = new QTextEdit(this);
    mdiArea->addSubWindow(newTextEdit);
    newTextEdit->show();
}

void QtEditor::newOpen()
{
    qDebug() << "File Open";
}

void QtEditor::newSave()
{
    qDebug() << "File Save";
}

void QtEditor::newSaveas()
{
    qDebug() << "File Save As";
}

void QtEditor::newPrint()
{
    qDebug() << "File Print";
}

void QtEditor::newQuit()
{
    qDebug() << "File Quit";
    QApplication::quit(); // 애플리케이션 종료
}

void QtEditor::setTextFont(const QFont &font)
{
    textEdit->setCurrentFont(font);
}

void QtEditor::setTextFontSize(double size)
{
    textEdit->setFontPointSize(size);
}

