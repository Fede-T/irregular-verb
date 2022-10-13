/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label;
    QLineEdit *inf_verb;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *ps_verb;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *pp_verb;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QLabel *ps_correct;
    QSpacerItem *horizontalSpacer_12;
    QLabel *pp_correct;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *boton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *puntos;
    QLabel *label_8;
    QLabel *puntos_totales;
    QLabel *label_9;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 375);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget{/*\n"
"image: url(:/Guia de ventana nueva.png);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(27, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        inf_verb = new QLineEdit(centralwidget);
        inf_verb->setObjectName(QString::fromUtf8("inf_verb"));
        inf_verb->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inf_verb->sizePolicy().hasHeightForWidth());
        inf_verb->setSizePolicy(sizePolicy1);
        inf_verb->setFont(font);
        inf_verb->setAlignment(Qt::AlignCenter);
        inf_verb->setReadOnly(true);

        horizontalLayout->addWidget(inf_verb);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(29, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 4);
        horizontalLayout_2->setStretch(3, 2);
        horizontalLayout_2->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_8 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        ps_verb = new QLineEdit(centralwidget);
        ps_verb->setObjectName(QString::fromUtf8("ps_verb"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ps_verb->sizePolicy().hasHeightForWidth());
        ps_verb->setSizePolicy(sizePolicy2);
        ps_verb->setFont(font);
        ps_verb->setAlignment(Qt::AlignCenter);
        ps_verb->setReadOnly(false);

        horizontalLayout_3->addWidget(ps_verb);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pp_verb = new QLineEdit(centralwidget);
        pp_verb->setObjectName(QString::fromUtf8("pp_verb"));
        sizePolicy2.setHeightForWidth(pp_verb->sizePolicy().hasHeightForWidth());
        pp_verb->setSizePolicy(sizePolicy2);
        pp_verb->setFont(font);
        pp_verb->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(pp_verb);

        horizontalSpacer_9 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_3->setStretch(1, 10);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 10);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        ps_correct = new QLabel(centralwidget);
        ps_correct->setObjectName(QString::fromUtf8("ps_correct"));
        QFont font1;
        font1.setPointSize(9);
        ps_correct->setFont(font1);
        ps_correct->setStyleSheet(QString::fromUtf8(""));
        ps_correct->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(ps_correct);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);

        pp_correct = new QLabel(centralwidget);
        pp_correct->setObjectName(QString::fromUtf8("pp_correct"));
        pp_correct->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(pp_correct);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        horizontalLayout_8->setStretch(0, 4);
        horizontalLayout_8->setStretch(1, 4);
        horizontalLayout_8->setStretch(2, 8);
        horizontalLayout_8->setStretch(3, 4);
        horizontalLayout_8->setStretch(4, 4);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        boton = new QPushButton(centralwidget);
        boton->setObjectName(QString::fromUtf8("boton"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(boton->sizePolicy().hasHeightForWidth());
        boton->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(boton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        horizontalLayout_7->setStretch(0, 5);
        horizontalLayout_7->setStretch(1, 3);
        horizontalLayout_7->setStretch(2, 5);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setPointSize(8);
        font2.setItalic(true);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(label_5);

        puntos = new QLabel(centralwidget);
        puntos->setObjectName(QString::fromUtf8("puntos"));
        sizePolicy.setHeightForWidth(puntos->sizePolicy().hasHeightForWidth());
        puntos->setSizePolicy(sizePolicy);
        puntos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(puntos);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_8);

        puntos_totales = new QLabel(centralwidget);
        puntos_totales->setObjectName(QString::fromUtf8("puntos_totales"));
        sizePolicy.setHeightForWidth(puntos_totales->sizePolicy().hasHeightForWidth());
        puntos_totales->setSizePolicy(sizePolicy);
        puntos_totales->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(puntos_totales);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_9);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout_4->addWidget(label_3);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 5);
        horizontalLayout_4->setStretch(3, 5);
        horizontalLayout_4->setStretch(4, 5);
        horizontalLayout_4->setStretch(5, 5);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(2, 5);
        verticalLayout->setStretch(3, 6);
        verticalLayout->setStretch(4, 4);
        verticalLayout->setStretch(5, 4);
        verticalLayout->setStretch(6, 5);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        boton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Irregular verbs", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Infinitive:", nullptr));
        inf_verb->setText(QCoreApplication::translate("MainWindow", "verb", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "  past simple  ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "past participle", nullptr));
        pp_verb->setText(QString());
        ps_correct->setText(QString());
        pp_correct->setText(QString());
        boton->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ver. 1.0", nullptr));
        puntos->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", " / ", nullptr));
        puntos_totales->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "puntos", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Created by Troncoso Federico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
