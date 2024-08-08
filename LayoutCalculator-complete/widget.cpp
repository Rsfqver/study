#include "widget.h"
#include "ui_widget.h"
#include<QLabel>
#include <QApplication>
#include<QPushButton>
#include<QVBoxLayout>
#include<QGridLayout>


Widget::Widget(QWidget *parent): QWidget(parent), m_isFisrt(true)
{
    m_label = new QLabel("0", this);  // Changed initial text to "0"
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    //m_label->setGeometry(10,5,230,40);
    m_label->setFrameShape(QFrame::Box);
    m_label->setMaximumHeight(30);

    const int WIDTH = 4;
    const char *ButtonChar[16] = {"7", "8", "9", "/",
                                  "4", "5", "6", "x",
                                  "1", "2", "3", "-",
                                  "0", "C", "=", "+"};

    const char *methods[16] = {SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
                               SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
                               SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
                               SLOT(setNum()), SLOT(clear()), SLOT(calculate()), SLOT(setOp())};
    QGridLayout *gridLayout=new QGridLayout();
    for(int y=0; y<WIDTH; ++y)
    {
        for(int x=0; x<WIDTH; ++x)
        {
            int n=x+y*WIDTH;
            m_buttons.append(new QPushButton(ButtonChar[n],this));
            gridLayout->addWidget(m_buttons.at(n),n/WIDTH,n%WIDTH);
            if(n !=13&&n!=14)connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]); //버튼 연결이였구나
        }
    }
    connect(m_buttons.at(14), SIGNAL(clicked()), SLOT(calculate()));
    setWindowTitle("Calculator");
    QVBoxLayout*vBoxLayout=new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(6,6,6,6);
    vBoxLayout->addWidget(m_label);
    vBoxLayout->addLayout(gridLayout);
    setLayout(vBoxLayout);
}

Widget::~Widget()
{
    delete m_label;
    m_buttons.clear();
}

void Widget::setNum()
{
    QPushButton *button = dynamic_cast<QPushButton *>(sender());
    QString bStr;
    if (button != nullptr) bStr = button->text();
    if (m_label != nullptr)
    {
        QString IStr = m_label->text();
        m_label->setText((IStr == "0" || m_isFisrt) ? bStr : IStr + bStr);
        m_isFisrt = false;
    }
}

void Widget::setOp()
{
    QPushButton *button = dynamic_cast<QPushButton *>(sender());
    if (button != nullptr) m_op = button->text();
    if (m_label != nullptr)
    {
        m_num1 = m_label->text();
        m_isFisrt = true;
    }
}

void Widget::clear()
{
    m_label->setText("0");
    m_isFisrt = true;
}

void Widget::calculate()
{
    qreal result = 0;
    m_isFisrt = true;
    if (m_op == "+")
        result = m_num1.toDouble() + m_label->text().toDouble();
    else if (m_op == "-")
        result = m_num1.toDouble() - m_label->text().toDouble();
    else if (m_op == "x")
        result = m_num1.toDouble() * m_label->text().toDouble();
    else if (m_op == "/")
    {
        if (m_label->text().toDouble() == 0) {
            m_label->setText("Error: Cannot Divide by Zero");
            return;
        }
        result = m_num1.toDouble() / m_label->text().toDouble();
    }
    m_label->setText(QString::number(result));
}
