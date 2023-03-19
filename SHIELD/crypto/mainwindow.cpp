#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Language.h"
#include "formencrypt.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    encrypt = new Encryption();
    decrypt = new Decryption();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    QString FileName = QFileDialog::getOpenFileName( this, "Choose File", QDir::currentPath(), tr( "JSON (*.json);;All files (*)" ) );
    QFile file( FileName );
    if ( file.open( QIODevice::ReadOnly ) )
    {
        ui->textEdit->setText( file.readAll() );
    }
    else
    {
        return;
    }
    file.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString FileName = QFileDialog::getOpenFileName( this, "Choose File", QDir::currentPath(), tr( "JSON (*.json);;All files (*)" ) );
    QFile file( FileName );
    if ( file.open( QIODevice::ReadOnly ) )
    {
        ui->textEdit_2->setText( file.readAll() );
    }
    else
    {
        return;
    }
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->textEdit->toPlainText();
    encrypt->EncryptText( str );
    //ui->textEdit_3->insertPlainText(  );
    ui->textEdit_2->setText( str );
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->textEdit_2->toPlainText();
    FormEncrypt* form = new FormEncrypt();
    form->setText( str );
    form->showMaximized();
}
