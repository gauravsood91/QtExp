#ifndef TEST1_H
#define TEST1_H

#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QWidget>

class test1 : public QWidget
{
    Q_OBJECT
private:
    QLabel *label;
    QPushButton *button;
public:
    test1()
    {
        label=new QLabel;
        button=new QPushButton("Print");
        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(label);
        layout->addWidget(button);
        setLayout(layout);
        connect(button,SIGNAL(clicked()),this,SLOT(labelText()));
        show();
    }

public slots:
        void labelText()
    {
            label->setText("Hello World");
    }
};

#endif // TEST1_H
