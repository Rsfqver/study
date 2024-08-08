#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVector>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void setNum();
    void setOp();
    void clear();
    void calculate();  // calculate 메서드 선언

private:
    QLabel *m_label;
    QVector<QPushButton*> m_buttons;
    QString m_num1;
    QString m_op;
    bool m_isFisrt;
};

#endif // WIDGET_H
