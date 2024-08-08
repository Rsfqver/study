#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMdiArea>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private slots:
    void newFile();
    void newOpen();
    void newSave();
    void newSaveas();
    void newPrint();
    void newQuit();
    void setTextFont(const QFont &font);
    void setTextFontSize(double size);

private:
    QMdiArea *mdiArea;   // MDI 영역
    QTextEdit *textEdit; // 현재 텍스트 편집기
};

#endif // QTEDITOR_H

