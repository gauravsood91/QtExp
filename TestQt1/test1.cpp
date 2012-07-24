#include "test1.h"

test1::test1(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout=new QHBoxLayout;
    QSlider *slider=new QSlider(Qt::Horizontal);
    QSpinBox *spin=new QSpinBox;
    setLayout(layout);
    layout->addWidget(spin);
    layout->addWidget(slider);
    show();
    connect(slider,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
}
