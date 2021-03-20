#ifndef FORMWORD_H
#define FORMWORD_H

#include <random>
#include <ctime>

#include <QMessageBox>
#include <QRegularExpression>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FormWord; }
QT_END_NAMESPACE

class FormWord : public QMainWindow
{
    Q_OBJECT

public:
    FormWord(QWidget *parent = nullptr);
    ~FormWord();

private slots:
    void on_Formation_clicked();

private:
    Ui::FormWord *ui;
    QString Word;
    int Capacity, randInt, key;
    QChar replacement;
};
#endif // FORMWORD_H
